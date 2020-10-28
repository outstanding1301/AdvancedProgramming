TARGET = main_so main_a
WDIR = .
CC = gcc

CFLAGS = -Wall -O3 -D_REENTRANT
CFLAGS += -I${WDIR}/include

LDIR = -L./lib
LIBS = $(LDIR) -lmylib

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

all: ${TARGET} clean

main_so: $(SRCS)
	$(CC) $(CFLAGS) -o $@ $? $(LIBS)

main_a: $(SRCS)
	$(CC) $(CFLAGS) -o $@ $? ./lib/libmylib.a
# $(CC) $(CFLAGS) -static  -o $@ $? $(LIBS)

test:
	cd $(OPENCV_HOME)
	ls
	cd $(OPENCV_HOME) ; ls
	cd $(OPENCV_HOME) && ls
	echo 에러 테스트
	cd $(OPENCV_HOME)/123 ; echo "이건 실행됨!"
	-cd $(OPENCV_HOME)/123 ; echo "이건 실행됨 + 오류무시!"
	cd $(OPENCV_HOME)/123 && echo "이건 실행안됨!"

clean:
	rm -f core *.o a.out