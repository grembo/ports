--- scripts.old/TestUtil.py	2015-01-23 16:48:48.000000000 +0000
+++ scripts/TestUtil.py	2015-01-23 16:49:07.385754019 +0000
@@ -84,6 +84,25 @@
 def isLinux():
     return sys.platform.startswith("linux")
 
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
 def getCppCompiler():
     compiler = ""
     if os.environ.get("CPP_COMPILER", "") != "":
@@ -321,7 +321,7 @@
     if(p.wait() != 0):
         print("uname failed:\n" + p.stdout.read().strip())
         sys.exit(1)
-    if p.stdout.readline().decode('UTF-8').strip() == "x86_64" and os.environ.get("LP64", "") != "no":
+    if p.stdout.readline().decode('UTF-8').strip() in ["x86_64", "amd64"] and os.environ.get("LP64", "") != "no":
         x64 = True
 
 #
@@ -1826,7 +1826,7 @@
     #
     if isWin32():
         addLdPath(getCppLibDir(lang), env)
-    elif lang in ["py", "rb", "php", "js"]:
+    elif lang in ["cpp", "py", "rb", "php", "js"]:
         addLdPath(getCppLibDir(lang), env)
 
     if lang == "javae":
@@ -1846,6 +1865,14 @@
                 print("%s*** test not supported under Darwin%s" % (prefix, suffix))
                 continue
 
+            if isFreeBSD() and "nofreebsd" in config:
+                print("%s*** test not supported under FreeBSD%s" % (prefix, suffix))
+                continue
+
+            if isFreeBSDJail() and "nofreebsdjail" in config:
+                print("%s*** test not supported within a FreeBSD Jail%s" % (prefix, suffix))
+                continue
+
             if not isWin32() and "win32only" in config:
                 print("%s*** test only supported under Win32%s" % (prefix, suffix))
                 continue
