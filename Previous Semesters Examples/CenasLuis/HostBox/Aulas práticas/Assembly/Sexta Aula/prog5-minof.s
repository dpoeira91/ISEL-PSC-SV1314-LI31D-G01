
	.text
	
	.global min_Of
min_Of:
	movl 4(%esp), %eax
	movl 8(%esp), %ecx
	movl (%eax),%edx
	pushl %ebx
	jmp 1f
	
1:	movl (%eax, %ecx),%ebx
	
