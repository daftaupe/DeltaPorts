--- common/evdev.c.orig	2021-02-01 14:39:35.604484000 +0100
+++ common/evdev.c	2021-02-01 14:39:53.394805000 +0100
@@ -9,6 +9,8 @@
 #include <sys/sysmacros.h>
 #elif defined(__FreeBSD__)
 #include <dev/evdev/input.h>
+#elif defined(__DragonFly__)
+#include <dev/misc/evdev/input.h>
 #else
 #error Unsupported platform
 #endif
