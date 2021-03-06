#ifndef _Host_H
#define _Host_H
#include <string>

using namespace std;
class Host {

public:
     GMainLoop *loop;
     GstRTSPServer *server;
     GstRTSPMountPoints *mounts;
     GstRTSPMediaFactory *factory;
     gchar *str; 
int Start(char* filename)
{
      loop = g_main_loop_new (NULL, FALSE);
      /* create a server instance */   
      server = gst_rtsp_server_new ();
      /* get the mount points for this server, every server has a default object
   * that be used to map uri mount points to media factories */
      mounts = gst_rtsp_server_get_mount_points (server);

      str = g_strdup_printf ("( "
      "filesrc location=%s ! qtdemux name=d "
      "d. ! queue ! rtph264pay pt=96 name=pay0 "
      "d. ! queue ! rtpmp4apay pt=97 name=pay1 " ")", filename);

     /* make a media factory for a test stream. The default media factory can use
      * gst-launch syntax to create pipelines. 
      * any launch line works as long as it contains elements named pay%d. Each
      * element with pay%d names will be a stream */
     factory = gst_rtsp_media_factory_new ();
     gst_rtsp_media_factory_set_launch (factory, str);
     g_free (str);

     /* attach the test factory to the /test url */
     gst_rtsp_mount_points_add_factory (mounts, "/test", factory);

     /* don't need the ref to the mapper anymore */
     g_object_unref (mounts);

     /* attach the server to the default maincontext */
     gst_rtsp_server_attach (server, NULL);

     /* start serving */
     g_print ("stream ready at rtsp://127.0.0.1:8554/test\n");
     g_main_loop_run (loop);
         return 0;
 }
};

#endif /* _Host_H */
