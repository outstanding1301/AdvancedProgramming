TARGET = libmylib.a libmylib.so
CC = gcc

WDIR = ../..
LDIR = ${WDIR}/lib

SHARED = -shared -fPIC -undefined dynamic_lookup
CFLAGS = -Wall -O3 -D_REENTRANT
CFLAGS += -I./include -I${WDIR}/include

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all: ${TARGET} clean

libmylib.a: $(OBJS)
	ar rscv $@ $?
	mkdir -p ${LDIR}
	mv $@ ${LDIR}

libmylib.so: ${SRCS}
	$(CC) ${SHARED} $(CFLAGS) -o $@ $? $(LIBS)
	mkdir -p ${LDIR}
	mv $@ ${LDIR}

clean:
	rm -rf core *.o a.out