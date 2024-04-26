prog:fonct.o main.o
	gcc fonct.o main.o -o prog -lSDL -g -lSDL_image -lSDL_mixer -lSDL_ttf 
main.o:main.c
	gcc -c main.c -g
fonct.o:fonct.c
	gcc -c fonct.c 


