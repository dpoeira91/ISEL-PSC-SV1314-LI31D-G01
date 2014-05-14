	.text

	.global println
println:
	pushl %ebx
	movl 8(%esp), %ebx
	jmp 2f
	
1:	pushl %eax
	call putchar
	addl $4, %esp
	incl %ebx
	
2:	movzbl (%ebx), %eax
	test %al, %al
	jnz 1b
	pushl $10
	call putchar
	addl $4, %esp
	popl %ebx
	ret
