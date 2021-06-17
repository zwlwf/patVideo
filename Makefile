patVideo: patVideo.cpp main.cpp
	g++ main.cpp patVideo.cpp -o patVideo -std=c++11

a.exe : a.c
	gcc a.c -std=c99
