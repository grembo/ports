--- cpp/src/IceGrid/RegistryI.cpp.orig	2016-07-20 14:05:45.755567630 +0000
+++ cpp/src/IceGrid/RegistryI.cpp	2016-07-20 14:06:07.402566459 +0000
@@ -40,6 +40,7 @@
 
 #include <fstream>
 
+#include <openssl/opensslv.h>
 #include <openssl/des.h> // For crypt() passwords
 
 #include <sys/types.h>
