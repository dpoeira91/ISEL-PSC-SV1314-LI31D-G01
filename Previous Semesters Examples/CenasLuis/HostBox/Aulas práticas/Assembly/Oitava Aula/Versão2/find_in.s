	.text

	.global find_in
find_in:
	pushl %ebp
	movl %esp, %ebp
	pushl %esi
	pushl %edi
	pushl %ebx
	
	subl $8, %esp
	
	movl 8(%ebp) , %edi
	movl %edi, %ebx
	movl 12(%ebp), %esi
	jmp 2f
	
1:	addl 16(%ebp), %ebx
	
	movl %ebx, 0(%esp)
	movl %edi, 4(%esp)
	call *20(%esp)
	
	testb %al, %al
	jz 2f
	movl %ebx , %edi
	
2:	decl %esi
	jnz 1b
	
3:	movl %edi, %eax
	
	addl $8, %esp
	popl %ebx
	popl %edi
	popl %esi
	popl %ebp
	ret
