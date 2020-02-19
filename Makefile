CC=g++
CFLAGS=-std=c++11 -O3 -Wall -pthread -I./ -DTCD -g
LDFLAGS= -lpthread -levent ../threadcached/hodor/libhodor/libhodor.a \
	 ../threadcached/obj/libthreadcached.so ../threadcached/ralloc/test/libralloc.a -ldl
SUBDIRS=core db
SUBSRCS=$(wildcard core/*.cc) $(wildcard db/*.cc)
OBJECTS=$(SUBSRCS:.cc=.o)
EXEC=ycsbc

all: $(SUBDIRS) $(EXEC)

$(SUBDIRS):
	$(MAKE) -C $@

$(EXEC): $(wildcard *.cc) $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir $@; \
	done
	$(RM) $(EXEC)

.PHONY: $(SUBDIRS) $(EXEC) test
