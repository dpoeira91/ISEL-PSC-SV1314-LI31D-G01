/*
the shift amount is given first, and the value to shift is given second.

The shift amount is given either as an immediate or in the singlebyte register element %cl. 
(These instructions are unusual in only allowing this specific register as operand.)

unsigned reverse ( unsigned val ){
	unsigned aux = 0;
	int i;
	for( i=31 ; val!=0 ; val>>=1, --i)
	    aux = aux | ((val&1)<<i);
	return aux;
}
*/
    .globl  reverse
.text
reverse:
	pushl %ebp
	movl %esp,%ebp
	push %ebx
	push %edx
	push %ecx

	
.L1:
	movl 8(%ebp), %edx  #edx = val
	movl $0, %eax #eax = result	
	movl $31, %ecx #ecx = i	
	
//aux = aux | ((val&1)<<i);
.CICLE:
	or %edx, %edx #verify if val = 0
	jz .OVER 
	movl %edx, %esi # esi is an auxiliar reg	
	and $1, %esi     # esi =val&1
	sal %cl, %esi
	orl %esi , %eax

	#setup for next iteration
	dec %ecx
	shr $1, %edx    # shift val, 1 time (val >>=1)	

	jmp .CICLE

.OVER:
	popl %ecx
	popl %edx
	popl %ebx
	popl %ebp
	ret



