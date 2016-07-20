--- cpp/src/Glacier2/CryptPermissionsVerifierI.cpp.orig	2016-07-20 13:40:49.368571222 +0000
+++ cpp/src/Glacier2/CryptPermissionsVerifierI.cpp	2016-07-20 13:58:05.421569273 +0000
@@ -8,6 +8,7 @@
 // **********************************************************************
 
 #include <Glacier2/CryptPermissionsVerifierI.h>
+#include <openssl/opensslv.h>
 #include <openssl/des.h>
 
 using namespace std;
