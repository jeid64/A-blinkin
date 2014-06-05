CFLAGS=-Wall -g
LDFLAGS=-levent -lpthread -lprotobuf-c
LIBS=workqueue.o amessage.pb-c.o
HEADERS=workqueue.h amessage.pb-c.h
BINS=echoserver_threaded

all: ${BINS}

echoserver_threaded: echoserver_threaded.o ${LIBS} ${HEADERS}
	${CC} echoserver_threaded.o ${LIBS} ${LDFLAGS} -o $@

clean:
	/bin/rm -rf ${BINS} *.o core *.core
