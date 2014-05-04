    .globl  select
    .text
	/*
	ctx is at 28(%ebp)					+28	|		ctx			|
	result is at 24(%ebp)				+24	|		result		|
	check is at 20(%ebp)				+20	|		check		|
	num is at 16(%ebp)					+16	|		num			|
	dim is at 12(%ebp)					+12	|		dim			|
	items is at 8(%ebp)					+8	|		items		|
	counter is held in %ebx				+4	|	return addr		|-4
	check_result is held in %esi	->%ebp	|		old %ebp	|-8
	i is held in %edi					-4	|		%ebx		|-12
										-8	|		%esi		|-16 <-%original %esp
										-12	|		i			|-20 
										-16	|					|-24
										-20	|	call param 2	|-28
										-24	|	call param 1	|-32 <-%esp prepared for calling functions = %esp-12
	*/

select:
#prepare stack for the execution of the	function
	pushl	%ebp			#%esp = -8
	movl	%esp, %ebp		#%ebp = %esp
	pushl	%ebx			#%esp = -12
	pushl	%edi			#%esp = -16
	subl	$16, %esp		#%esp = -32
#prepare variables for the function
	movl	$0, %ebx		#counter = 0 = %ebx
	movl	$0, %eax		#i = 0 = %eax
	movl	%eax,-12(%ebp)	#-12(%ebp) = i;
loop:
#this loop occurs while i < num , meaning there are still elements in items to check , i = %eax
	cmpl	16(%ebp), %eax	#compares i to num
	jge		end_of_function	#jumps if i>= num
	imull	12(%ebp), %eax	#%eax = i*dim
	addl	8(%ebp), %eax	#%eax = items + (dim * i)
	movl	%eax,(%esp)		#(%esp) = items + (dim * i) = call param 1
	movl	28(%ebp), %eax	#%eax = ctx
	movl	%eax, 4(%esp)	#4(%esp) = ctx = call param 2
	call	*20(%ebp)		#call check
	orl		$0,%eax			#0 | check result affecting flags
	jz		end_of_loop		#jumps to the end of the loop if the check result is 0
#if check result is not zero then we store the item in result[]
	movl	%ebx,%ecx		#%ecx = counter
	imull	12(%ebp),%ecx	#%ecx = counter * dim
	addl	24(%ebp),%ecx	#%ecx = result + (counter * dim)
	movl	-12(%ebp), %eax	#%eax = i
	imull	12(%ebp), %eax	#%eax = i*dim
	addl	8(%ebp), %eax	#%eax = items + (dim * i)
	movl	%eax, (%ecx)	#MEM[result + (counter * dim)] = %eax
	inc		%ebx			#++counter
end_of_loop:
#here a new iteration of the loop is prepared
	movl	-12(%ebp), %eax	#%eax = i
	inc		%eax			#++i
	movl	%eax ,-12(%ebp)	#-12(%ebp) = new i
	jmp		loop			#jumps to the beggining of the loop to check for more items
end_of_function:
#here the function gets ready to return
	movl	%ebx , %eax		#%eax = counter
	addl	$16, %esp		#%esp = -16
	popl	%edi			#%esp = -12
	popl	%ebx			#%esp = -8
	popl	%ebp			#%esp = -4
	ret

