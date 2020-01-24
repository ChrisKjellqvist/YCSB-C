CC=g++
#MEMCACHED=-DTCD
MEMCACHED=-DMCD
CFLAGS=-std=c++11 -c -g -Wall -fgnu-tm $(MEMCACHED)
INCLUDES=-I../ -I/u/ckjellqv/threadcached/include/ -I/u/ckjellqv/lmcd
SOURCES=$(wildcard *.cc)
OBJECTS=$(SOURCES:.cc=.o)

all: $(SOURCES) $(OBJECTS)

.cc.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	$(RM) $(OBJECTS)

