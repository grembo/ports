--- cpp/include/IceUtil/Config.h.orig	2013-10-04 15:48:14.000000000 +0000
+++ cpp/include/IceUtil/Config.h	2016-07-20 13:24:42.718563366 +0000
@@ -59,7 +59,7 @@
 #if (defined(__GNUC__) && (((__GNUC__* 100) + __GNUC_MINOR__) >= 405) && defined(__GXX_EXPERIMENTAL_CXX0X__)) || \
     (defined(__clang__) && \
       ((defined(__apple_build_version__) && (((__clang_major__ * 100) + __clang_minor__) >= 402)) || \
-       (!defined(__apple_build_version__) && (((__clang_major__ * 100) + __clang_minor__) >= 302))) && \
+       (!defined(__apple_build_version__) && (((__clang_major__ * 100) + __clang_minor__) >= 301))) && \
       __cplusplus >= 201103) || \
     (defined(_MSC_VER) && (_MSC_VER >= 1600))
 #   define ICE_CPP11
