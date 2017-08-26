Alan Tsai

.file	1 "G1.c"
.globl	A
.data
.align	2
A:
	.word	11              #initializing 1  array with 10 elements A[10]
		.word	2
		.word	33
		.word	4
		.word	15
		.word	6
		.word	7
		.word	8
		.word	9
		.word	10
	.rdata
	.align	2
$LC0:
		.ascii	"MinMaxIt = \000"


	.sdata
	.align	2
$LC1:
		.ascii	"  \000"      #refers to the C code print_str(" ")
	.align	2					  	
$LC2:
		.ascii	"\n\000"      #refers to the C code print_str("\n)
	.text
	.align	2
	.globl	main
	.ent	main
main:
	.frame	$fp,32,$31		# vars= 8, regs= 2/0, args= 16, extra= 0
	.mask	0xc0000000,-4
	.fmask	0x00000000,0
		subu	$sp,$sp,32      #adjust the stack to make room for 8 words
		sw	$31,28($sp)        #copy the argument in registers
		sw	$fp,24($sp)        #copy the argument to frame pointer
		move	$fp,$sp         #move the stack pointer to frame pointer
		jal	__main          #jump to the main program (main()in C) 
		addu	$2,$fp,20      #add constant 20 to frame pointer and store it in 
		la	$4,A                 #register $2

		li	$5,10			# 0xa
		addu	$6,$fp,16
		move	$7,$2i             
		jal	MinMaxIt       #jump to MinMaxIt function 
		la	$4,$LC0           #refers to MinMaxIt (A,10, &min, &max) in C

		jal	print_str      #jump to print_str(str) in C
		lw	$4,16($fp)
		jal	print_int      #jump to print_int(value) in C 

		la	$4,$LC1
		jal	print_str      #all these under main: in MIPS are jumping and
									#linking,adjusting stacks and pointers refering
									#calling functions in the C program.


		lw	$4,20($fp)
		jal	print_int

		la	$4,$LC2
		jal	print_str

		move	$2,$0
		move	$sp,$fp
		lw	$31,28($sp)
		lw	$fp,24($sp)
		addu	$sp,$sp,32
		j	$31
	.end	main
	.align	2
	.globl	MinMaxIt
	.ent	MinMaxIt
MinMaxIt:                   #The funtion MinMaxIt (A,n, _min, _max) in C
                            #starts here
	.frame	$fp,16,$31		# vars= 0, regs= 4/0, args= 0, extra= 0
	.mask	0x40e00000,-4
	.fmask	0x00000000,0
		subu	$sp,$sp,16     #adjusting the stack for 4 words
		sw	$fp,12($sp)      #copy the argument in frame pointer 
		sw	$23,8($sp)      #copy the argment in register $23 to stack and so on
		sw	$22,4($sp)
		sw	$21,0($sp)
		move	$fp,$sp      
		sw	$4,16($fp)
		sw	$5,20($fp)       #In the MinMaxIt function refing to the C program,
		sw	$6,24($fp)       #the elements of the array are being stored to
		sw	$7,28($fp)       #different registers, and by using pointers we can
		lw	$2,16($fp)       #find out the maximum an minimum number from the
		lw	$21,0($2)        #array recursivly
		lw	$3,16($fp)

		lw	$22,0($3)
 		lw	$2,16($fp)
 
 		addu	$23,$2,4
	$L3:
 		lw	$2,20($fp)
 
 		sll	$2,$2,2
 		lw	$3,16($fp)
 
 		addu	$2,$3,$2
 		sltu	$2,$23,$2
 		bne	$2,$0,$L6
 
 		j	$L4
 
	$L6:
 		lw	$2,0($23)
 
 		slt	$2,$2,$21
 		beq	$2,$0,$L7
 


 		lw	$21,0($23)
	$L7:
 		lw	$2,0($23)
 
 		slt	$2,$22,$2
 		beq	$2,$0,$L5
 
 		lw	$22,0($23)
	$L5:
 		addu	$23,$23,4
 		j	$L3
	$L4:
 		lw	$2,28($fp)
 
 		sw	$22,0($2)
 		lw	$3,24($fp)
 
 		sw	$21,0($3)
 		move	$2,$0
 		move	$sp,$fp
 		lw	$fp,12($sp)
 		lw	$23,8($sp)
 		lw	$22,4($sp)
 		lw	$21,0($sp)
 		addu	$sp,$sp,16
 		j	$31
		.end	MinMaxIt
		.align	2
		.globl	__main
		.ent	__main
	__main:
		.frame	$fp,8,$31		# vars= 0, regs= 1/0, args= 0, extra= 0
		.mask	0x40000000,-8
		.fmask	0x00000000,0   #refers to the __main() function in C
 		subu	$sp,$sp,8
 		sw	$fp,0($sp)
 		move	$fp,$sp
 		move	$2,$0
 		move	$sp,$fp
 		lw	$fp,0($sp)
 		addu	$sp,$sp,8
 		j	$31
		.end	__main
		.align	2
		.globl	dummy
		.ent	dummy
	dummy:
		.frame	$fp,8,$31		# vars= 0, regs= 1/0, args= 0, extra= 0
		.mask	0x40000000,-8
		.fmask	0x00000000,0
 		subu	$sp,$sp,8
 		sw	$fp,0($sp)
 		move	$fp,$sp
 		sw	$4,8($fp)
 		move	$2,$0
 		move	$sp,$fp
 		lw	$fp,0($sp)


 		addu	$sp,$sp,8
 		j	$31
		.end	dummy
		.align	2
		.globl	print_int
		.ent	print_int
	print_int:
		.frame	$fp,16,$31		# vars= 8, regs= 1/0, args= 0, extra= 0
		.mask	0x40000000,-8     #This refers to print_int function in C
		.fmask	0x00000000,0
 		subu	$sp,$sp,16        #adjust the stack for 4 words
 		sw	$fp,8($sp)
 		move	$fp,$sp
 		sw	$4,16($fp)
 		li	$2,1			# 0x1
 		sw	$2,0($fp)
 		lw	$3,0($fp)
 		lw	$2,16($fp)
	 #APP
		add $a0,$2,$zero
		add $v0,$3,$zero
 		syscall
	 #NO_APP
 		lw	$2,16($fp)
 		move	$sp,$fp
 		lw	$fp,8($sp)
 		addu	$sp,$sp,16
 		j	$31
		.end	print_int
		.align	2
		.globl	print_hex
		.ent	print_hex
	print_hex:
		.frame	$fp,40,$31		# vars= 16, regs= 2/0, args= 16, extra= 0
		.mask	0xc0000000,-4
		.fmask	0x00000000,0
 		subu	$sp,$sp,40
 		sw	$31,36($sp)
 		sw	$fp,32($sp)
 		move	$fp,$sp
 		sw	$4,40($fp)
 		lw	$4,40($fp)
 		addu	$5,$fp,16
 		jal	itox
 		addu	$4,$fp,16
 		jal	print_str
 		lw	$2,40($fp)
 		move	$sp,$fp
 		lw	$31,36($sp)
 		lw	$fp,32($sp)
 		addu	$sp,$sp,40
 		j	$31
		.end	print_hex
		.align	2
		.globl	print_str
		.ent	print_str
	print_str:


		.frame	$fp,16,$31		# vars= 8, regs= 1/0, args= 0, extra= 0
		.mask	0x40000000,-8
		.fmask	0x00000000,0
 		subu	$sp,$sp,16
 		sw	$fp,8($sp)
 		move	$fp,$sp
 		sw	$4,16($fp)
 		li	$2,4			# 0x4
 		sw	$2,0($fp)
 		lw	$3,0($fp)
 		lw	$2,16($fp)
	 #APP
		add $a0,$2,$zero
		add $v0,$3,$zero
 		syscall
	 #NO_APP
 		move	$2,$0
 		move	$sp,$fp
 		lw	$fp,8($sp)
 		addu	$sp,$sp,16
 		j	$31
		.end	print_str
		.align	2
		.globl	itox
		.ent	itox
	itox:
		.frame	$fp,24,$31		# vars= 16, regs= 1/0, args= 0, extra= 0
		.mask	0x40000000,-8
		.fmask	0x00000000,0
 		subu	$sp,$sp,24
 		sw	$fp,16($sp)
 		move	$fp,$sp
 		sw	$4,24($fp)
 		sw	$5,28($fp)
 		li	$2,7			# 0x7
 		sw	$2,4($fp)
 		sw	$0,0($fp)
	$L15:
 		lw	$2,0($fp)
 
 		slt	$2,$2,8
 		bne	$2,$0,$L18
 
 		j	$L16
 
	$L18:
 		lw	$2,24($fp)
 
 		andi	$2,$2,0xf
 		sw	$2,8($fp)
 		lw	$2,8($fp)
 
 		slt	$2,$2,10
 		beq	$2,$0,$L19
 
 		lw	$3,28($fp)
 		lw	$2,4($fp)


 
 		addu	$3,$3,$2
 		lbu	$2,8($fp)
 
 		addu	$2,$2,48
 		sb	$2,0($3)
 		j	$L20
	$L19:
 		lw	$3,28($fp)
 		lw	$2,4($fp)
 
 		addu	$3,$3,$2
 		lbu	$2,8($fp)
 
 		addu	$2,$2,55
 		sb	$2,0($3)
	$L20:
 		lw	$2,24($fp)
 
 		sra	$2,$2,4
 		sw	$2,24($fp)
 		lw	$2,4($fp)
 
 		addu	$2,$2,-1
 		sw	$2,4($fp)
 		lw	$2,0($fp)
 
 		addu	$2,$2,1
 		sw	$2,0($fp)
 		j	$L15
	$L16:
 		lw	$2,28($fp)
 
 		addu	$2,$2,8
 		sb	$0,0($2)
 		lw	$2,24($fp)
 		move	$sp,$fp
 		lw	$fp,16($sp)
 		addu	$sp,$sp,24
 		j	$31
		.end	itox
		.align	2
		.globl	print_stack
		.ent	print_stack
	print_stack:
		.frame	$fp,40,$31		# vars= 16, regs= 2/0, args= 16, extra= 0
		.mask	0xc0000000,-4
		.fmask	0x00000000,0 #refers to print_int(min); print_str("");print_int(max); in C
 		subu	$sp,$sp,40          #adjust the stack for 10 words
 		sw	$31,36($sp)
 		sw	$fp,32($sp)
 		move	$fp,$sp
 		sw	$4,40($fp)
 		li	$2,42			# 0x2a
 		sw	$2,28($fp)
 		addu	$2,$fp,40
 		sw	$2,16($fp)


 		lw	$2,16($fp)
 
 		sw	$2,20($fp)
 		lw	$4,20($fp)
 		jal	print_hex
 
 		la	$4,$LC2
 		jal	print_str
 
 		lw	$2,16($fp)
 
 		addu	$2,$2,-80
 		sw	$2,16($fp)
 		sw	$0,24($fp)
	$L22:
 		lw	$2,24($fp)
 
 		slt	$2,$2,82
 		bne	$2,$0,$L25
 
 		j	$L23
 
	$L25:
 		lw	$2,16($fp)
 
 		sw	$2,20($fp)
 		lw	$4,20($fp)
 		jal	print_hex
 
 		la	$4,$LC1
 		jal	print_str
 
 		lw	$2,16($fp)
 
 		lw	$2,0($2)
 
 		sw	$2,20($fp)
 		lw	$4,20($fp)
 		jal	print_hex
 
 		la	$4,$LC2
 		jal	print_str
 
 		lw	$2,16($fp)
 
 		addu	$2,$2,4
 		sw	$2,16($fp)
 		lw	$2,24($fp)
 
 		addu	$2,$2,1
 		sw	$2,24($fp)
 		j	$L22
	$L23:
 		lw	$2,28($fp)
 		move	$sp,$fp
 		lw	$31,36($sp)
 		lw	$fp,32($sp)


 		addu	$sp,$sp,40
 		j	$31
		.end	print_stack   #refers to print_str("\n") in C
