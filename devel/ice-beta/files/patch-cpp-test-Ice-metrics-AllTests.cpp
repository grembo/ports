--- cpp.orig/test/Ice/metrics/AllTests.cpp	2015-01-23 12:43:43.000000000 +0000
+++ cpp/test/Ice/metrics/AllTests.cpp	2015-01-23 12:47:42.796752254 +0000
@@ -639,9 +639,12 @@
         testAttribute(clientMetrics, clientProps, update, "Connection", "incoming", "false");
         testAttribute(clientMetrics, clientProps, update, "Connection", "adapterName", "");
         testAttribute(clientMetrics, clientProps, update, "Connection", "connectionId", "Con1");
-        testAttribute(clientMetrics, clientProps, update, "Connection", "localHost", "127.0.0.1");
+        if (!inFreeBSDJail())
+        {
+            testAttribute(clientMetrics, clientProps, update, "Connection", "localHost", "127.0.0.1");
+            testAttribute(clientMetrics, clientProps, update, "Connection", "remoteHost", "127.0.0.1");
+        }
         //testAttribute(clientMetrics, clientProps, update, "Connection", "localPort", "");
-        testAttribute(clientMetrics, clientProps, update, "Connection", "remoteHost", "127.0.0.1");
         testAttribute(clientMetrics, clientProps, update, "Connection", "remotePort", "12010");
         testAttribute(clientMetrics, clientProps, update, "Connection", "mcastHost", "");
         testAttribute(clientMetrics, clientProps, update, "Connection", "mcastPort", "");
@@ -871,9 +874,12 @@
         testAttribute(serverMetrics, serverProps, update, "Dispatch", "incoming", "true", op);
         testAttribute(serverMetrics, serverProps, update, "Dispatch", "adapterName", "TestAdapter", op);
         testAttribute(serverMetrics, serverProps, update, "Dispatch", "connectionId", "", op);
-        testAttribute(serverMetrics, serverProps, update, "Dispatch", "localHost", "127.0.0.1", op);
+        if (!inFreeBSDJail())
+        {
+            testAttribute(serverMetrics, serverProps, update, "Dispatch", "localHost", "127.0.0.1", op);
+            testAttribute(serverMetrics, serverProps, update, "Dispatch", "remoteHost", "127.0.0.1", op);
+        }
         testAttribute(serverMetrics, serverProps, update, "Dispatch", "localPort", "12010", op);
-        testAttribute(serverMetrics, serverProps, update, "Dispatch", "remoteHost", "127.0.0.1", op);
         //testAttribute(serverMetrics, serverProps, update, "Dispatch", "remotePort", "12010", op);
         testAttribute(serverMetrics, serverProps, update, "Dispatch", "mcastHost", "", op);
         testAttribute(serverMetrics, serverProps, update, "Dispatch", "mcastPort", "", op);
