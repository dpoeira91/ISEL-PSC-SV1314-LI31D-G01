	.globl xstrpbrk
	.text

/**
ct is at 12(%ebp) and held in %ecx	|	+12
cs is at 8(%ebp) and held in %ebx	|	+8
return address						|	+4
saved %ebp							|	0
saved %ebx is at -4(%ebp)			|	-4
saved %edx is at -8(%ebp)			|	-8
saved %ecx is at -12(ebp)			|	-12
*/

xstrpbrk:
	#push registers into the stack
	pushl %ebp				# saved %ebp
	movl %esp, %ebp			# %ebp = %esp
	pushl %ebx				# saved %ebx
	pushl %ecx				# saved %ecx
	pushl %edx				# saved %edx
# %esp = -16(%ebp)
	movl 8(%ebp) , %ebx		# %ebx = cs
	movl 12(%ebp), %ecx		# %ecx = ct
	movl %ecx, %edx			# %edx = %ecx = aux

While:
	movb (%ebx), %al		# %al = %ebx 1st byte 
	orb %al, %al			# %al | %al
	jz Return				# (%ebx) == \0

For:
	movb (%ecx), %al		# %al = %ecx 1st byte
	orb %al, %al			# %al | %al
	jz L4					# (%ecx) == \0 
	cmpb %al, (%ebx)		# %ecx 1st byte == %ebx 1st byte ?
	je L5
	incl %ecx
	jmp For

L4:
	movl %edx, %ecx
	incl %ebx
	jmp While

L5:
	movl %ebx, %eax			# %eax = %ebx (%eax = *cs)
	jmp L6
	
Return:
	xorl %eax, %eax

L6:
	popl %edx
	popl %ecx
	popl %ebx
	popl %ebp
	ret
