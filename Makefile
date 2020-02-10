CC=g++
CFLAGS=-std=c++11 -O3  -Wall -pthread -I./ -DTCD
LIBDIR=/home/suser/threadcached
#LIBDIR=/u/ckjellqv/libmemcached/libmemcached/.libs
LDFLAGS= -lpthread -levent $(LIBDIR)/obj/libthreadcached.so $(LIBDIR)/ralloc/test/libralloc.a
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

test:
	gcc -std=c17 -g -O0 -Wall -pthread -I./ $(LDFLAGS) -I/u/ckjellqv/libmemcached/ test.c -o test
yest:
	g++ -std=c++17 -g -O0 -Wall -pthread -I./ $(LDFLAGS) -I/u/ckjellqv/threadcached/include/ yest.c /u/ckjellqv/threadcached/obj/libthreadcached.so /u/ckjellqv/threadcached/ralloc/test/libralloc.a -o yest

.PHONY: $(SUBDIRS) $(EXEC) test
