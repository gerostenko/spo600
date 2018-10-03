# list all binaries in this next line
BINARIES = vol1 vol2 vol3 vol4
CCOPTS = -g -O3

all:	${BINARIES}

vol1:	vol1.c vol.h
	gcc ${CCOPTS} vol1.c -o vol1

vol2:	vol2.c vol.h
	gcc ${CCOPTS} vol2.c -o vol2

vol3:	vol3.c vol.h
	gcc ${CCOPTS} vol3.c -o vol3

vol4: vol4.c vol.h lookup.h
	gcc ${CCOPTS} vol4.c -o vol4

test1:	vol1
	bash -c "time ./vol1"

test2: vol2
	bash -c "time ./vol2"

test3: vol3
	bash -c "time ./vol3"

test4: vol4
	bash -c "time ./vol4"

# target to test all binaries
test:	test1 test2

gdb1:	vol1
	gdb vol1

clean:	
	rm ${BINARIES} || true


