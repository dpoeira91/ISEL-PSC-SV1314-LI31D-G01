#Minimo
	.data 

a: .long 7
b: .long 4

res: .long 0

	.text
	
	.global main
main:
	movl a , %ecx
	movl b , %edx
	sub %ecx, %edx
	jc storeB
	jmp storeA

storeA:
	movl res, %ecx
	ret
	
storeB:
	movl b, %ecx
	movl res, %ecx
	ret
