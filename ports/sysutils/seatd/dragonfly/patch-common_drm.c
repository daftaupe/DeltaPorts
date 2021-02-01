--- common/drm.c.orig	2021-02-01 14:37:48.623960000 +0100
+++ common/drm.c	2021-02-01 14:41:32.615064000 +0100
@@ -40,6 +40,12 @@
 	static const int prefixlen = STRLEN(prefix);
 	return strncmp(prefix, path, prefixlen) == 0;
 }
+#elif defined(__DragonFly__)
+int path_is_drm(const char *path) {
+	static const char prefix[] = "/dev/drm/";
+	static const int prefixlen = STRLEN(prefix);
+	return strncmp(prefix, path, prefixlen) == 0;
+}
 #else
 #error Unsupported platform
 #endif
