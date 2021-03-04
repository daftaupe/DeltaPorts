--- src/core/lib/iomgr/port.h.orig	2018-04-13 18:08:11 UTC
+++ src/core/lib/iomgr/port.h
@@ -112,6 +112,16 @@
 #define GRPC_POSIX_SOCKET 1
 #define GRPC_POSIX_SOCKETUTILS 1
 #define GRPC_POSIX_WAKEUP_FD 1
+#elif defined(GPR_DRAGONFLY)
+#define GRPC_HAVE_IFADDRS 1
+#define GRPC_HAVE_IPV6_RECVPKTINFO 1
+#define GRPC_HAVE_SO_NOSIGPIPE 1
+#define GRPC_HAVE_UNIX_SOCKET 1
+#define GRPC_POSIX_FORK 1
+#define GRPC_POSIX_NO_SPECIAL_WAKEUP_FD 1
+#define GRPC_POSIX_SOCKET 1
+#define GRPC_POSIX_SOCKETUTILS 1
+#define GRPC_POSIX_WAKEUP_FD 1
 #elif defined(GPR_OPENBSD)
 #define GRPC_HAVE_IFADDRS 1
 #define GRPC_HAVE_IPV6_RECVPKTINFO 1