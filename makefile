CVLIBS = -lopencv_core -lopencv_highgui

SRC_PATH = .
OBJ_PATH = ./obj


INCLUDES = -I include
MAINFILE = threadlisttest.c

CC = gcc
CFLAGS = -Wall

mthread:	*.o
	$(CC) $(MAINFILE) $(OBJ_PATH)/*.o $(CFLAGS) -o mthread.out
debug:
	$(CC) -g $(MAINFILE) $(SRC_PATH)/*.cpp $(CFLAGS) -o debug.out
threadlist:
	$(CC) $(SRC_PATH)/threadlist.c -c -o $(OBJ_PATH)/threadlist.o $(CFLAGS)
thread:
	$(CC) $(SRC_PATH)/thread.c -c -o $(OBJ_PATH)/thread.o $(CFLAGS)
clean:
	rm -f *.o *.out make
