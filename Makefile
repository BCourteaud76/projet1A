DIRSDL=/users/prog1a/C/librairie/2011
CFLAGS = -g -Wall -Wextra -Iinclude/ -Isrc/ -I$(DIRSDL)/include -I$(DIRSDL)/include/SDL -I/usr/local/include -I/usr/local/include/SDL -I/usr/include/SDL
LDFLAGS = -lm -lSDL -lSDLmain -lSDL_draw -L$(DIRSDL)/lib -L/usr/local/lib  -lX11
CC = gcc

EXEC = main vGraphique
SRC = $(wildcard src/*c)
OBJ1 = src/Alist.o src/Astar.o src/fct.o src/listeArc.o src/main.o src/struct.o src/hach.o
OBJ2 = src/Alist.o src/Astar.o src/fct.o src/listeArc.o src/vGraphique.o src/struct.o src/graphic.o src/hach.o
TARGETDIR = bin/

all : $(EXEC)

main : $(OBJ1)
	$(CC) -o $(TARGETDIR)$@ $^ $(LDFLAGS)

vGraphique : $(OBJ2)
	$(CC) -o $(TARGETDIR)$@ $^ $(LDFLAGS)

%.o : src/%.c
	$(CC) -c $< $(CFLAGS)

clean :
	-rm -rf src/*.o

mrproper : clean
	rm -rf bin/$(EXEC) $(EXEC)
