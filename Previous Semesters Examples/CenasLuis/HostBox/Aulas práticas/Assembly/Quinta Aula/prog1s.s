	
	.data 

a: .long 3
b: .long 7

res: .long 0

	.text
	
	.global main
main:
	movl a , %eax
	movl b , %ecx
	addl %eax, %ecx
	movl %ecx, res 
	ret
