
	.text
	
	.global xstrlcat
xstrlcat:
	pushl %ebp
	movl  %esp, %ebp
	pushl %esi
	pushl %edi
	pushl %ebx
	
1:	movl 8(%ebp) , %edx							#edx == dst
	pushl %edx
	call strlen									#Calcular o comprimento já preenchido de dst
	addl $4, %esp
	movl %eax, %esi								#Guarda-lo em %esi
	movl %esi, %ebx

2:	movl 12(%ebp) , %edx						#edx == src
	pushl %edx
	call strlen									#Calcular o comprimento já preenchido de src
	addl $4, %esp
	movl %eax, %edi								#Guarda-lo em %edi
	addl %edi, %ebx								#ebx == Tamanho total da string
	
3:	movl 12(%ebp) , %eax						#eax == src
	movl 8(%ebp) , %edx							#edx == dst
	addl %esi, %edx
	
4:	testl %edi, %edi
	jz 5f
	movl (%eax) , %ecx
	movb %cl , (%edx) 
	incl %eax
	incl %edx
	decl %edi
	jmp 4b
	
5: 	movl %ebx, %eax
	popl %ebx
	popl %edi
	popl %esi
	popl %ebp
	ret
