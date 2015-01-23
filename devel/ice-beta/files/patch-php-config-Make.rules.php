--- php.orig/config/Make.rules.php	2015-01-23 12:48:40.000000000 +0000
+++ php/config/Make.rules.php	2015-01-23 12:52:06.000996033 +0000
@@ -100,8 +100,8 @@
 endif
 
 libdir			= $(top_srcdir)/lib
 ifneq ($(prefix), /usr)
-install_phpdir      = $(prefix)/php
-install_libdir      = $(prefix)/php
+install_phpdir		= $(prefix)/share/pear
+install_libdir		= $(prefix)/lib/php/$(PHP_EXT_DIR)
 else

@@ -169,7 +169,8 @@
 endif
 
 ifeq ($(installphplib),)
-	installphplib	= $(INSTALL) $(1) $(2); \
+	installphplib	= mkdir -p $(2) ; \
+			  $(INSTALL) $(1) $(2); \
 			  chmod a+rx $(2)/$(notdir $(1))
 endif
 
