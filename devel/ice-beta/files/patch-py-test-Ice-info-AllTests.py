--- py.orig/test/Ice/info/AllTests.py.orig	2014-12-15 08:04:52.000000000 +0000
+++ py/test/Ice/info/AllTests.py	2015-01-23 13:15:31.163635817 +0000
@@ -7,12 +7,31 @@
 #
 # **********************************************************************
 
-import Ice, Test, sys, threading
+import Ice, Test, sys, threading, subprocess
 
 def test(b):
     if not b:
         raise RuntimeError('test assertion failed')
 
+def isFreeBSD():
+    return sys.platform.startswith("freebsd")
+
+def sysctl(key):
+    p = subprocess.Popen("sysctl "+key, shell=1, stdout=subprocess.PIPE)
+    try:
+        result = p.communicate()[0].strip().split()[1]
+    except IndexError:
+        return 0    
+    if sys.version_info >= (3,):
+        result = str(result, sys.stdout.encoding)
+    try:
+        return int(result)
+    except ValueError:
+        return result
+
+def isFreeBSDJail():
+    return isFreeBSD() and sysctl("security.jail.jailed")
+
 def allTests(communicator):
     sys.stdout.write("testing proxy endpoint information... ")
     sys.stdout.flush()
@@ -74,12 +93,12 @@
     ipEndpoint = endpoints[0].getInfo()
     test(ipEndpoint.type() == Ice.TCPEndpointType or ipEndpoint.type() == 2 or ipEndpoint.type() == 4 or
          ipEndpoint.type() == 5)
-    test(ipEndpoint.host == defaultHost)
+    test(ipEndpoint.host == defaultHost or isFreeBSDJail())
     test(ipEndpoint.port > 0)
     test(ipEndpoint.timeout == 15000)
 
     udpEndpoint = endpoints[1].getInfo()
-    test(udpEndpoint.host == defaultHost)
+    test(udpEndpoint.host == defaultHost or isFreeBSDJail())
     test(udpEndpoint.datagram())
     test(udpEndpoint.port > 0)
 
@@ -115,7 +134,7 @@
     ipinfo = base.ice_getConnection().getEndpoint().getInfo()
     test(ipinfo.port == 12010)
     test(not ipinfo.compress)
-    test(ipinfo.host == defaultHost)
+    test(ipinfo.host == defaultHost or isFreeBSDJail())
 
     ctx = testIntf.getEndpointInfoAsContext()
     test(ctx["host"] == ipinfo.host)
@@ -125,7 +144,7 @@
 
     udp = base.ice_datagram().ice_getConnection().getEndpoint().getInfo()
     test(udp.port == 12010)
-    test(udp.host == defaultHost)
+    test(udp.host == defaultHost or isFreeBSDJail())
 
     print("ok")
 
@@ -137,8 +156,8 @@
     test(len(info.adapterName) == 0)
     test(info.remotePort == 12010)
     if defaultHost == '127.0.0.1':
-        test(info.remoteAddress == defaultHost)
-        test(info.localAddress == defaultHost)
+        test(info.remoteAddress == defaultHost or isFreeBSDJail())
+        test(info.localAddress == defaultHost or isFreeBSDJail())
 
     ctx = testIntf.getConnectionInfoAsContext()
     test(ctx["incoming"] == "true")
