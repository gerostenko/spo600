BINARIES=hello-nasm hello-gas

all:	${BINARIES}
AS_ARGS=-g

hello-nasm:	hello-nasm.s
		nasm 	-g 	-o hello-nasm.o	-f elf64 	hello-nasm.s
		ld 	 	-o hello-nasm	 		hello-nasm.o

hello-gas:	hello-gas.s
		as	${AS_ARGS}	-o hello-gas.o		hello-gas.s
		ld			-o hello-gas		hello-gas.o

clean:	
		rm ${BINARIES} *.o || true



