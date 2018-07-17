
dominique1:
	cc -c *.c `libapril-config --cflags` -w
	cc *.o `libapril-config --libs ` -o dominique -w

wizard.o:
	cc -c wizard.c `libapril-config --libs --cflags` -w -o wizard.o
	
video.o:
	cc -c video.c `libapril-config --libs --cflags` -w -o video.o

main.o:
	cc -c main.c `libapril-config --libs --cflags` -w -o main.o
	#cc *.o `libapril-config --libs --cflags` -o dominique -w

install:
	cp dominique /usr/local/bin -v
	cp dominique.desktop /usr/share/applications -v
