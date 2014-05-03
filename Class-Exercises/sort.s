.globl  sort
	.text

	/*base is at 8(%ebp)			|	...				|+12
	nmemb is at 12(%ebp)			|	1º arg			|+8%   16 ==0
	size is at 16(%ebp)			-4	|	return address	|+4
	p is held in %ebx			-8	|	old %ebp		|<- new %ebp
	q is held in %esi			-12	|	%ebx			|-4 a vantagem de usar estes 3 registos é a garantia que eles não se alteram mesmo chamando outras funções
	chosen is held in %edi		-18	|	%esi			|-8
								-20	|	%edi			|-12<-%esp
								-24	|	i				|-16
								-28	|	j				|-20
						%esp->	-32	|					|	
								-36	|					|
								-40	|	param chamada 3	|
								-44	|	param chamada 2	|
								-48	|	param chamada 1	|	
	*/ 

sort:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%esi
	pushl	%edi
	subl	$28, %esp
#	chosen = malloc(size)
	movl	16(%ebp),%eax
	movl	%eax, (%esp)
	call	malloc
	movl	%eax, %edi
	movl	$1, -16(%ebp)
	movl	8(%ebp), %ebx
	addl	16(%ebp), %ebx	#p = base +size
1:
	movl	-16(%ebp), %eax
	compl	12(%ebp), %eax # i < nmemb?
	jge		...
#memcpy(chosen,p,size)
	movl	16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%edi, (%esp)
	call	memcpy
#inner for
	movl	%ebx, %esi #q=p
	movl	-16(%ebp),%eax
	movl	%eax, -20(%ebp)
L0:
	cmpl	$0, -20(%ebp)
	jle		...
	movl	%edi, 4(%esp)
	movl	%esi, %eax
	subl	16(%ebp), %eax	# %eax = q-size
	movl	%eax, (%esp)
	call	*20(%esp)
	cmpl	$0, %eax
	jle		...
#memcpy(q,q-size,size)
	movl	16(%ebp), %ecx
	movl	%ecx, 8(%esp)
	movl	%esi, %eax
	subl	%eax,
	movl	