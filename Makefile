CFLAGS = -g -Wall -Wextra -Iinclude/ -Isrc/
LDFLAGS = -lm -lSDL -lSDLmain -lSDL_draw
CC = gcc

EXEC = main
SRC = $(wildcard src/*c)
OBJ = $(SRC:.c=.o)
TARGETDIR = bin/

all : $(EXEC)

main : $(OBJ)
	$(CC) -o $(TARGETDIR)$@ $^ $(LDFLAGS)

%.o : src/%.c
	$(CC) -c $< $(CFLAGS)

clean :
	-rm -rf src/*.o

mrproper : clean
	rm -rf bin/$(EXEC) $(EXEC)
