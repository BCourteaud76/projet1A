CFLAGS = -g -Wall -Wextra -Iinclude/ -Isrc/
LDFLAGS = -lm -lSDL -lSDLmain -lSDL_draw
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
