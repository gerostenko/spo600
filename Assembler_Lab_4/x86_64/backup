/* 
   This is a 'hello world' program in x86_64 assembler using the 
   GNU assembler (gas) syntax. Note that this program runs in 64-bit
   mode.

   CTyler, Seneca College, 2014-01-20
   Licensed under GNU GPL v2+
*/

.text
.globl	_start

start = 0
max = 30

_start:
	movq	$start,%r15
loop:	
	movq $0,%rdx
	movq %r15,%rax
	movq $10,%r14
	div %r14 /*places quotient into rax and remainder into rdx*/
	cmp $10,%r15 /*see if we need to print the first digit*/
	jl skip /*if not skip*/
	/* first digit*/
	movq %rax,%r12
	add $48,%r12
	mov %r12b,msg+6
skip:
 /* second digit */
	movq %rdx,%r14
	add $48,%r14
	mov %r14b,msg+7	
	
	movq	$len,%rdx
	movq	$msg,%rsi
	movq	$1,%rdi
	movq	$1,%rax
	syscall
	inc	%r15
	cmp	$max,%r15
	jne	loop

	movq	$0,%rdi				/* exit status */
	movq	$60,%rax			/* syscall sys_exit */
	syscall

.section .data

msg:	.ascii      "loop:   \n"
	len = . - msg

//.set pos , msg + 6
//.set posB , msg + 7
