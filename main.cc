#include <gst/gst.h>
#include <gst/rtsp-server/rtsp-server.h>
#include <iostream>
#include "Host.h"
using namespace std;

int main (int argc, char *argv[])
{
    
	gst_init (&argc, &argv);

	  if (argc < 2) {
	    g_message ("usage: %s <filename.mp4>", argv[0]);
	    return -1;
	  }
Host host1;        
host1.Start(argv[1]) ;  
   return 0;

}