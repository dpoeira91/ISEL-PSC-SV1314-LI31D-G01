
    .globl  reverse
	.text

# return the argument
/**												|		val			|+8
val is at 8(%ebp) and held in %ebx,				|	return address	|+4
saved %ebx is at -4(%ebp),						|	Saved %ebp		|<-%ebp
saved %edx is at -8(%ebp),iaux is held at %edx	|	Saved %ebx		|-4
saved %ecx is at -12(%ebp),i is held at %ecx	|	Saved %edx		|-8
												|	Saved %ecx		|-12 <-%esp
*/
reverse:
	#push used registers into the stack so that information is not lost
	pushl	%ebp	#saved %ebp , %esp - 4
	movl	%esp,%ebp	# %ebp = %esp
	pushl	%ebx	#saved %ebx , %esp - 4
	pushl	%edx	#saved %edx , %esp - 4
	pushl	%ecx	#saved %ecx , %esp - 4
	/**
	%esp == -12(%ebp)
	load registers %ebx, %edx and %ecx
	*/
	movl	8(%ebp), %ebx	# %ebx = val 
	movl	$0, %eax	# result = %eax = 0
	movl	$31, %ecx	# i = %ecx = 31
	movl	$31, %edx	# iaux = 31;
Loop:
	#Verifies if we should go into the loop again
	testl	%ecx, %ecx	# i & i affects the flags with the result
	js		prologue	#if i<0 jumps to prologue
	#Isolates a bit and puts it in it's reversed position on the result
	sarl	%cl, %ebx		# %ebx = val>>i
	andl	$1 , %ebx		# %ebx = %ebx & 1 = (val>>i)&1
	movl	%ecx, %edx		# %edx = i
	subl	$32, %ecx		# %ecx = i - 32bits
	xorl	$-1,%ecx		# %ecx = 31 - i
	sall	%cl, %ebx	# %ebx = %ebx<<31-i = ((val>>i) & 1)<<(31-i)
	orl		%ebx, %eax		# %eax = (%eax | %ebx) = (result | %ebx)
	#Prepares the cicle for it's next iteration
	decl	%edx		# --iaux
	movl	%edx, %ecx	# i = iaux
	movl	8(%ebp), %ebx	# %ebx = val 	
	jmp Loop
prologue:
	#returns the machine to it's original state and returns
	popl	%ecx	#gets old %ecx from the stack and places it in %ecx, %esp + 4
	popl	%edx	#gets old %edx from the stack and places it in %edx, %esp + 4
	popl	%ebx	#gets old %ebx from the stack and places it in %ebx, %esp + 4
	popl	%ebp	#gets old %ebp from the stack and places it in %ebp, %esp + 4
    ret		#returns the result through %eax
