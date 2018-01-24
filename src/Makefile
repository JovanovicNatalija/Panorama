PROGRAM = main
CC      = gcc
CFLAGS  = -Wall
LDLIBS  = -lm -lglut -lGL -lGLU

$(PROGRAM): panorama.o worker.o light.o main.o
	$(CC) -o $(PROGRAM) panorama.o worker.o light.o main.o $(CFLAGS) $(LDLIBS)

.PHONY: clean

clean:
	-rm *.o $(PROGRAM)