BINARIES=hello
AS=as
LD=ld

all:	${BINARIES}

hello:		hello.s
		${AS}	-g	-o hello.o	hello.s
		${LD}		-o hello	hello.o

clean:	
		rm ${BINARIES} *.o || true



