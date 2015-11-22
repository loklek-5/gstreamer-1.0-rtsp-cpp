g++ main.cc  -o program `pkg-config --cflags --libs gstreamermm-1.0 gtkmm-3.0 gstreamer-1.0 gstreamer-rtsp-server-1.0` 
#./program ~/Téléchargements/Adele.mp4 
#sudo mplayer -vo xv ffmpeg://rtsp://127.0.0.1:8554/test