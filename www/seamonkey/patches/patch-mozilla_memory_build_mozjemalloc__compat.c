$NetBSD: patch-mozilla_memory_build_mozjemalloc__compat.c,v 1.2 2015/03/17 19:50:42 ryoon Exp $

--- mozilla/memory/build/mozjemalloc_compat.c.orig	2015-03-09 05:34:43.000000000 +0000
+++ mozilla/memory/build/mozjemalloc_compat.c
@@ -12,6 +12,8 @@
 #include "jemalloc_types.h"
 #include "mozilla/Types.h"
 
+#include <stdbool.h>
+
 #if defined(MOZ_NATIVE_JEMALLOC)
 
 MOZ_IMPORT_API int
@@ -47,6 +49,16 @@ je_(nallocm)(size_t *rsize, size_t size,
 	je_(mallctlbymib)(mib, miblen, &v, &sz, NULL, 0);		\
 } while (0)
 
+#define	CTL_IJ_GET(n, v, i, j) do {					\
+	size_t mib[6];							\
+	size_t miblen = sizeof(mib) / sizeof(mib[0]);			\
+	size_t sz = sizeof(v);						\
+	je_(mallctlnametomib)(n, mib, &miblen);				\
+	mib[2] = i;							\
+	mib[4] = j;							\
+	je_(mallctlbymib)(mib, miblen, &v, &sz, NULL, 0);			\
+} while (0)
+
 MOZ_MEMORY_API size_t
 malloc_good_size_impl(size_t size)
 {
@@ -61,6 +73,48 @@ malloc_good_size_impl(size_t size)
   return size;
 }
 
+static size_t
+compute_bin_unused(unsigned int narenas)
+{
+    size_t bin_unused = 0;
+
+    uint32_t nregs; // number of regions per run in the j-th bin
+    size_t reg_size; // size of regions served by the j-th bin
+    size_t curruns; // number of runs belonging to a bin
+    size_t curregs; // number of allocated regions in a bin
+
+    unsigned int nbins; // number of bins per arena
+    unsigned int i, j;
+
+    // curruns and curregs are not defined for uninitialized arenas,
+    // so we skip them when computing bin_unused. However, initialized
+    // arenas are not guaranteed to be sequential, so we must test each
+    // one when iterating below.
+    bool initialized[100]; // should be narenas, but MSVC doesn't have VLAs
+    size_t isz = sizeof(initialized) / sizeof(initialized[0]);
+
+    je_(mallctl)("arenas.initialized", initialized, &isz, NULL, 0);
+    CTL_GET("arenas.nbins", nbins);
+
+    for (j = 0; j < nbins; j++) {
+        CTL_I_GET("arenas.bin.0.nregs", nregs, j);
+        CTL_I_GET("arenas.bin.0.size", reg_size, j);
+
+        for (i = 0; i < narenas; i++) {
+            if (!initialized[i]) {
+                continue;
+            }
+
+            CTL_IJ_GET("stats.arenas.0.bins.0.curruns", curruns, i, j);
+            CTL_IJ_GET("stats.arenas.0.bins.0.curregs", curregs, i, j);
+
+            bin_unused += (nregs * curruns - curregs) * reg_size;
+        }
+    }
+
+    return bin_unused;
+}
+
 MOZ_JEMALLOC_API void
 jemalloc_stats_impl(jemalloc_stats_t *stats)
 {
@@ -93,7 +147,8 @@ jemalloc_stats_impl(jemalloc_stats_t *st
   // We could get this value out of base.c::base_pages, but that really should
   // be an upstream change, so don't worry about it for now.
   stats->bookkeeping = 0;
-  stats->bin_unused = 0;
+
+  stats->bin_unused = compute_bin_unused(narenas);
 }
 
 MOZ_JEMALLOC_API void
