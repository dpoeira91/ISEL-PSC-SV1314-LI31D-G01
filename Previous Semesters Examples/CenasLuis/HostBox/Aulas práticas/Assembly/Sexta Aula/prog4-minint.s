
	.text
	
	.global min_Int
	
min_Int:
	movl 4(%esp), %eax
	movl 8(%esp), %ecx
	cmp %eax, %ecx
	jg 1f
	movl %ecx, %eax

1:	ret
