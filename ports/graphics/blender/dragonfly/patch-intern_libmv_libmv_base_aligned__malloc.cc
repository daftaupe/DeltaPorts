--- intern/libmv/libmv/base/aligned_malloc.cc.orig	2020-02-06 15:52:00 UTC
+++ intern/libmv/libmv/base/aligned_malloc.cc
@@ -21,7 +21,7 @@
 #include "libmv/base/aligned_malloc.h"
 #include "libmv/logging/logging.h"
 
-#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__NetBSD__)
+#if !defined(__APPLE__) && !defined(__FreeBSD__) && !defined(__NetBSD__) && !defined(__DragonFly__)
 // Needed for memalign on Linux and _aligned_alloc on Windows.
 #  ifdef FREE_WINDOWS
 /* make sure _aligned_malloc is included */
@@ -44,7 +44,8 @@ namespace libmv {
 void *aligned_malloc(int size, int alignment) {
 #ifdef _WIN32
   return _aligned_malloc(size, alignment);
-#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__APPLE__)
+#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__APPLE__) || \
+  defined(__DragonFly__)
   void *result;
 
   if (posix_memalign(&result, alignment, size)) {
