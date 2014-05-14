	.text
	
	.global convertAll
convertAll:
	pushl %ebp
	movl %esp, %ebp
	pushl %esi
	pushl %edi
	pushl %ebx
	
	movl 16(%ebp) , %ebx							#ebx = len
	movl 20(%ebp) , %edi							#edi = output pointer
	movl 8(%ebp) , %esi								#esi = input pointer
	
1:	testl %ebx, %ebx
	jz 2f
	movl 32(%ebp) , %eax							#eax = ctx
	pushl %eax	
	pushl %edi
	pushl %esi
	call * 28(%ebp)
	addl $12, %esp
	movl 12(%ebp) , %edx							#edx = idim
	movl 24(%ebp) , %ecx							#ecx = odim
	addl %edx , %esi
	addl %ecx , %edi
	decl %ebx
	jmp 1b

2:	movl %edi, %eax

	popl %ebx
	popl %edi
	popl %esi
	popl %ebp
	ret
	
#void * convertAll( const void * input, size_t idim, size_t len, void * output, size_t odim, void (*convertOne)(const void * in, void * out, void * ctx), 
#void * ctx);

#input = ponteiro para array fonte
#idim = dimensão de cada byte do array input
#len = número de elementos do array apontado por input
#output = ponteiro para o array de destino dos valores convertidos
#odim = dimensão de cada byte do array de output
#convertOne = função conversora
#ctx = terceiro argumento de convertOne
