
	.text
	
	.global printout

printout:
	pushl %ebp
	movl %esp, %ebp
	pushl %ebx
	
	movl 8(%ebp), %eax									#eax = tst_str
	pushl %eax
	call strlen
	addl $4, %esp
	movl %eax, %edx
	movl $1, %ebx
	movl 8(%ebp), %ecx
	movl $4 , %eax
	int $0x80
	
	popl %ebx
	popl %ebp
	ret

#printout(tst_str);
#ssize_t write(int fd, const void *buf, size_t count); 
