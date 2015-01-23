--- cpp/include/Ice/FactoryTableInit.h.orig	2015-01-23 17:04:32.865689927 +0000
+++ cpp/include/Ice/FactoryTableInit.h	2015-01-23 17:06:20.823681212 +0000
@@ -47,7 +47,7 @@
 public:
     
     DefaultUserExceptionFactoryInit(const char* typeId) :
-        _typeId(typeId)
+        _typeId(typeId), _ftableInit(new IceInternal::FactoryTableInit)
     {
         factoryTable->addExceptionFactory(_typeId, new DefaultUserExceptionFactory<E>(_typeId));
     }
@@ -55,10 +55,12 @@
     ~DefaultUserExceptionFactoryInit()
     {
         factoryTable->removeExceptionFactory(_typeId);
+        delete _ftableInit;
     }
     
 private:
     const ::std::string _typeId;
+    IceInternal::FactoryTableInit* _ftableInit;
 };
 
 template<class O>
@@ -67,7 +69,7 @@
 public:
     
     DefaultObjectFactoryInit(const char* typeId) :
-        _typeId(typeId)
+        _typeId(typeId), _ftableInit(new IceInternal::FactoryTableInit)
     {
         factoryTable->addObjectFactory(_typeId, new DefaultObjectFactory<O>(_typeId));
     }
@@ -75,11 +77,12 @@
     ~DefaultObjectFactoryInit()
     {
         factoryTable->removeObjectFactory(_typeId);
+        delete _ftableInit;
     }
     
 private:
     const ::std::string _typeId;
- 
+    IceInternal::FactoryTableInit* _ftableInit;
 };
 
 }
