--- common/terminal.c.orig	2021-02-01 14:44:48.596268000 +0100
+++ common/terminal.c	2021-02-01 14:50:44.317775000 +0100
@@ -21,6 +21,13 @@
 #define K_ENABLE  K_XLATE
 #define K_DISABLE K_RAW
 #define FRSIG	  SIGIO
+#elif defined(__DragonFly__)
+#include <sys/consio.h>
+#include <sys/kbio.h>
+#include <termios.h>
+#define K_ENABLE  K_XLATE
+#define K_DISABLE K_RAW
+#define FRSIG	  SIGIO
 #else
 #error Unsupported platform
 #endif
@@ -30,7 +37,7 @@
 
 #define TTYPATHLEN 16
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 static int get_tty_path(int tty, char path[static TTYPATHLEN]) {
 	assert(tty >= 0);
 
@@ -162,7 +169,7 @@
 		return -1;
 	}
 	return st.v_active;
-#elif defined(__FreeBSD__)
+#elif defined(__FreeBSD__) || defined(__DragonFly__)
 	int vt;
 	int res = ioctl(fd, VT_GETACTIVE, &vt);
 	close(fd);
@@ -234,7 +241,7 @@
 		log_errorf("could not set KD keyboard mode: %s", strerror(errno));
 		return -1;
 	}
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__DragonFly__)
 	struct termios tios;
 	if (tcgetattr(fd, &tios) == -1) {
 		log_errorf("could not set get terminal mode: %s", strerror(errno));
