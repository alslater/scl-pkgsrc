$NetBSD: patch-hw_block_fdc.c,v 1.1 2015/05/16 03:19:54 khorben Exp $

fdc: force the fifo access to be in bounds of the allocated buffer

During processing of certain commands such as FD_CMD_READ_ID and
FD_CMD_DRIVE_SPECIFICATION_COMMAND the fifo memory access could
get out of bounds leading to memory corruption with values coming
from the guest.

Fix this by making sure that the index is always bounded by the
allocated memory.

This is CVE-2015-3456.

--- hw/block/fdc.c.orig	2015-04-27 14:08:23.000000000 +0000
+++ hw/block/fdc.c
@@ -1512,7 +1512,7 @@ static uint32_t fdctrl_read_data(FDCtrl 
 {
     FDrive *cur_drv;
     uint32_t retval = 0;
-    int pos;
+    uint32_t pos;
 
     cur_drv = get_cur_drv(fdctrl);
     fdctrl->dsr &= ~FD_DSR_PWRDOWN;
@@ -1521,8 +1521,8 @@ static uint32_t fdctrl_read_data(FDCtrl 
         return 0;
     }
     pos = fdctrl->data_pos;
+    pos %= FD_SECTOR_LEN;
     if (fdctrl->msr & FD_MSR_NONDMA) {
-        pos %= FD_SECTOR_LEN;
         if (pos == 0) {
             if (fdctrl->data_pos != 0)
                 if (!fdctrl_seek_to_next_sect(fdctrl, cur_drv)) {
@@ -1867,10 +1867,13 @@ static void fdctrl_handle_option(FDCtrl 
 static void fdctrl_handle_drive_specification_command(FDCtrl *fdctrl, int direction)
 {
     FDrive *cur_drv = get_cur_drv(fdctrl);
+    uint32_t pos;
 
-    if (fdctrl->fifo[fdctrl->data_pos - 1] & 0x80) {
+    pos = fdctrl->data_pos - 1;
+    pos %= FD_SECTOR_LEN;
+    if (fdctrl->fifo[pos] & 0x80) {
         /* Command parameters done */
-        if (fdctrl->fifo[fdctrl->data_pos - 1] & 0x40) {
+        if (fdctrl->fifo[pos] & 0x40) {
             fdctrl->fifo[0] = fdctrl->fifo[1];
             fdctrl->fifo[2] = 0;
             fdctrl->fifo[3] = 0;
@@ -1970,7 +1973,7 @@ static uint8_t command_to_handler[256];
 static void fdctrl_write_data(FDCtrl *fdctrl, uint32_t value)
 {
     FDrive *cur_drv;
-    int pos;
+    uint32_t pos;
 
     /* Reset mode */
     if (!(fdctrl->dor & FD_DOR_nRESET)) {
@@ -2019,7 +2022,9 @@ static void fdctrl_write_data(FDCtrl *fd
     }
 
     FLOPPY_DPRINTF("%s: %02x\n", __func__, value);
-    fdctrl->fifo[fdctrl->data_pos++] = value;
+    pos = fdctrl->data_pos++;
+    pos %= FD_SECTOR_LEN;
+    fdctrl->fifo[pos] = value;
     if (fdctrl->data_pos == fdctrl->data_len) {
         /* We now have all parameters
          * and will be able to treat the command
