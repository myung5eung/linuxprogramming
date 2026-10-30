// 문제2
CC = gcc
CFLAGS = -g -Wall
OBJS = main.o mylib.o
TARGET = maxp
$(TARGET) : $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)
main.o : main.c mylib.h
	$(CC) $(CFLAGS) -c main.c
mylib.o : mylib.c mylib.h
	$(CC) $(CFLAGS) -c mylib.c
.PHONY: clean
clean :
	rm $(TARGET) $(OBJS)
// 문제3
CX = g++
CXFLAGS = -g -Wall
OBJS = main.o mylib.o
TARGET = maxp

$(TARGET) : $(OBJS)
	$(CX) -o $(TARGET) $(OBJS)
main.o : main.cpp mylib.hpp
	$(CX) $(CXFLAGS) -c main.cpp
mylib.o : mylib.cpp mylib.hpp
	$(CX) $(CXFLAGS) -c mylib.cpp

.PHONY: clean
clean :
	rm $(TARGET) $(OBJS)
