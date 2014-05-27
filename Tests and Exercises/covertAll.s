.globl convertAll
.text

/*
	ctx is at 32(%ebp)			 +32| ctx			|
	covertOne is at 28(%ebp)	 +28| covertOne		|
	odim is at 24(%ebp)			 +24| odim			|
	output is at 20(%ebp)		 +20| output		|
	len is at 16(%ebp)			 +16| len			|
	idim is at 12(%ebp)			 +12| idim			|
	input is at 8(%ebp)			  +8| input			|
								  +4| return addr	|-4
							  ->%ebp| old %ebp		|-8
	i is held in %esi			  -4| %esi			|-12<-original %esp
								  -8|				|-16
								 -12|				|-20
								 -16|call param3	|-24
								 -20|call param2	|-28
								 -24|call param1	|-32<-%esp prepared for call
*/

convertAll:
#prepare stack for the execution fo the function
	pushl	%ebp		#%esp = -8
	movl	%esp, %ebp  #%ebp = %esp
	pushl	%esi		#%esp = -12
	subl	$20, %esp	#%esp = -32
#prepare variables for the function
	movl	$0, %esi	#i = 0
loop:
#this loop occurs while i < len, meaning there are still elements in input to convert to the output
	cmpl	16(%ebp), %esi	#len - i -> updates flags
	je		prepare_ret		#if len -i ==0 jumps to the end of the function
	movl	32(%ebp),%eax	#eax = ctx
	movl	%eax, 8(%esp)	#ctx -> call param3
	movl	24(%ebp), %ecx	#%ecx = odim
	imull	%esi, %ecx		#%ecx = odim * i
	movl	20(%ebp),%eax	#%eax = output
	addl	%ecx, %eax		#%eax = output + (odim * i)
	movl	%eax,4(%esp)	#%eax -> call param2
	movl	12(%ebp), %ecx	#%ecx = idim
	imull	%esi, %ecx		#%ecx = %ecx * %esi = idim * i
	movl	8(%ebp),%eax	#%eax = input
	addl	%ecx, %eax		#%eax = input + (idim * i)
	movl	%eax, (%esp)	#%eax -> call param1
	call	*28(%ebp)		#call convertOne(call param 1, call param 2, call param 3)
	incl	%esi			#i++
	jmp		loop
prepare_ret:
	movl	24(%ebp), %ecx	#%ecx = odim
	imull	%esi, %ecx		#%ecx = odim * i
	movl	20(%ebp),%eax	#%eax = output
	addl	%ecx, %eax		#%eax = output + (odim * i)
#
	addl	$20, %esp		#%esp = -12
	popl	%esi			#%esi = old %esi	,%esp = -8
	popl	%ebp			#%ebp = old %ebp	,%esp = -4
	ret						#returns %eax		,%esp = 0