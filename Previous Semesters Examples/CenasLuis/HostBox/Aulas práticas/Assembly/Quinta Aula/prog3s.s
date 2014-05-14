
	.data
	
str : .asciz "PSC-LI31D"
len : .long 0
	
	.text
	
	.global main

main:
	xorl %ecx , %ecx
	movl $str , %edx			#Acrescentando o dolar falamos de Endereços
	jmp 2f						# F significa forward, ou seja vai para a próxima label 2

1:
	inc %ecx
	
2:
	movb (%edx, %ecx), %al
	testb %al, %al			
	jnz 1b						# B significa back, ou seja vai para a última label 1

	movl %ecx, len
	ret
