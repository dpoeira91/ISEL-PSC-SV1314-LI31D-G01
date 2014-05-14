	.text
	
	.global find_in
find_in:
	pushl %ebp
	movl  %esp, %ebp  
	pushl %ebx
	pushl %esi
	pushl %edi
	
	movl 8(%ebp), %ebx
	movl 12(%ebp), %esi
	
	movl -4 ( %ebx , %esi , 4 ) , %edi		# res = values [len-1]
	
1: 	decl %esi								# --len
	jmp 2f
	
	pushl %edi								# passar argumento: old
	pushl -4(%ebx,%esi,4)					# passar argumento: new
	call *16(%ebp)							# chamar o is_better(old, new)

	addl $8, %esp
	testb %al, %al							#testl equivale a um AND
	jz 1b
	movl -4 ( %ebx , %esi , 4 ) , %edi
	jmp 1b
	
2:	movl %edi, %eax

	popl %edi
	popl %esi
	popl %ebx
	popl %ebp
	ret 
