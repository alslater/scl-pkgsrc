$NetBSD: patch-mozilla_dom_media_gmp_GMPParent.cpp,v 1.1 2015/03/17 19:50:42 ryoon Exp $

--- mozilla/dom/media/gmp/GMPParent.cpp.orig	2015-03-09 05:34:53.000000000 +0000
+++ mozilla/dom/media/gmp/GMPParent.cpp
@@ -96,23 +96,16 @@ GMPParent::Init(GeckoMediaPluginService 
   mService = aService;
   mDirectory = aPluginDir;
 
-  // aPluginDir is <profile-dir>/<gmp-plugin-id>/<version>
-  // where <gmp-plugin-id> should be gmp-gmpopenh264
-  nsCOMPtr<nsIFile> parent;
-  nsresult rv = aPluginDir->GetParent(getter_AddRefs(parent));
-  if (NS_FAILED(rv)) {
-    return rv;
-  }
-  nsAutoString parentLeafName;
-  rv = parent->GetLeafName(parentLeafName);
+  nsAutoString leafname;
+  nsresult rv = aPluginDir->GetLeafName(leafname);
   if (NS_FAILED(rv)) {
     return rv;
   }
   LOGD(("%s::%s: %p for %s", __CLASS__, __FUNCTION__, this,
-       NS_LossyConvertUTF16toASCII(parentLeafName).get()));
+       NS_LossyConvertUTF16toASCII(leafname).get()));
 
-  MOZ_ASSERT(parentLeafName.Length() > 4);
-  mName = Substring(parentLeafName, 4);
+  MOZ_ASSERT(leafname.Length() > 4);
+  mName = Substring(leafname, 4);
 
   return ReadGMPMetaData();
 }
