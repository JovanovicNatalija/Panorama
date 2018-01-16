PROGRAM = main
CC      = gcc
CFLAGS  = -Wall
LDLIBS  = -lm -lglut -lGL -lGLU

$(PROGRAM): main.o panorama.o worker.o
	$(CC) -o $(PROGRAM) main.o panorama.o worker.o $(CFLAGS) $(LDLIBS)