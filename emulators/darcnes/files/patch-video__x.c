
$FreeBSD: head/emulators/darcnes/files/patch-video__x.c 340725 2014-01-22 17:40:44Z mat $

--- video_x.c.orig	Tue Aug 24 10:46:40 2004
+++ video_x.c	Tue Aug 24 10:46:55 2004
@@ -365,7 +365,7 @@
 	    ui_joypad->data &= ~ui_joypad->button_template->buttons[0];
 	}
 	
-    default:
+    default: break;
     }
 }
 
