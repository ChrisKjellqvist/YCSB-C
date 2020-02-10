CC=g++
MEMCACHED=-DTCD
#MEMCACHED=-DMCD
CFLAGS=-std=c++11 -c -Ofast -Wall -fgnu-tm $(MEMCACHED)
INCLUDES=-I../ -I/home/suser/threadcached/include/ -I/home/suser/libmemcached
SOURCES=$(wildcard *.cc)
OBJECTS=$(SOURCES:.cc=.o)

all: $(SOURCES) $(OBJECTS)

.cc.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	$(RM) $(OBJECTS)

