CC=g++
MEMCACHED=-DTCD
#MEMCACHED=-DMCD
CFLAGS=-std=c++11 -c -Ofast -Wall -fgnu-tm $(MEMCACHED) 
INCLUDES=-I../ -I../../threadcached/include -I../../threadcached/hodor/include -I../../threadcached/hodor/libhodor
SOURCES=$(wildcard *.cc)
OBJECTS=$(SOURCES:.cc=.o)

all: $(SOURCES) $(OBJECTS)

.cc.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	$(RM) $(OBJECTS)

