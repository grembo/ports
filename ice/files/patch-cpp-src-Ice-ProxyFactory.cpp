--- cpp.orig/src/Ice/ProxyFactory.cpp	2011-06-15 21:43:59.000000000 +0200
+++ cpp/src/Ice/ProxyFactory.cpp	2012-03-04 20:14:53.000000000 +0100
@@ -229,6 +229,7 @@
     } 
     else if(cnt > static_cast<int>(_retryIntervals.size()))
     {
+        interval = 0; // apeace compiler
         if(traceLevels->retry >= 1)
         {
             Trace out(logger, traceLevels->retryCat);
