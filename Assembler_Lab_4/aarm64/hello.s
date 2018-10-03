.text
.globl _start

start = 0
max = 30

_start:

	mov x19, start
loop:
	mov 	x20, 0 /*first digit */
	mov 	x21, x19 /*second digit */
	mov		x22, 10
	cmp		x19, 10
	b.lt	skip
	
	udiv 	x20, x19, x22
	msub 	x21, x20, x22, x21
	add		x20, x20, 48
	adr		x1, msg
	strb	w20, [x1, 6]
		

skip:
	add		x21, x21, 48
	mov     x0, 1           /* file descriptor: 1 is stdout */
	adr     x1, msg   	/* message location (memory address) */
	strb	w21, [x1, 7]
	mov     x2, len   	/* message length (bytes) */

	mov     x8, 64     	/* write is syscall #64 */
	svc     0          	/* invoke syscall */
 
	add	x19, x19, 1
	cmp	x19, max
	b.lt	loop

	mov     x0, 0     	/* status -> 0 */
	mov     x8, 93    	/* exit is syscall #93 */
	svc     0          	/* invoke syscall */
 

.data
msg: 	.ascii      "loop:   \n"
len= 	. - msg

