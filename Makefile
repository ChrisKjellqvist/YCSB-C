CC=g++
CFLAGS=-std=c++11 -g -Wall -pthread -I./ -DMCD
LIBDIR=/u/ckjellqv/threadcached/lib
#LIBDIR=/u/ckjellqv/libmemcached/libmemcached/.libs
LDFLAGS= -lpthread -ltbb -levent $(LIBDIR)/libthreadcached.so $(LIBDIR)/librpmalloc.a
#LDFLAGS= -lpthread -ltbb -levent $(LIBDIR)/libmemcached.so 
SUBDIRS=core db
SUBSRCS=$(wildcard core/*.cc) $(wildcard db/*.cc)
OBJECTS=$(SUBSRCS:.cc=.o)
EXEC=ycsbc

all: $(SUBDIRS) $(EXEC)

$(SUBDIRS):
	$(MAKE) -C $@

$(EXEC): $(wildcard *.cc) $(OBJECTS)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir $@; \
	done
	$(RM) $(EXEC)

.PHONY: $(SUBDIRS) $(EXEC)

