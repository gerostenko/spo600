BINARIES = vol_simd backup
CCOPTS = -g -O3

all:	${BINARIES}

vol_simd:	vol_simd.c vol.h
		gcc ${CCOPTS} vol_simd.c -o vol_simd

backup: 	backup.c vol.h
		gcc ${CCOPTS} backup.c -o backup

test:		vol_simd
		bash -c "time ./vol_simd"

gdb:	vol_simd
	gdb vol_simd

clean:	
	rm ${BINARIES} || true


