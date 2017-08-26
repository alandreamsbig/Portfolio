

	.file	1 "stack-test2.c"
	.text
	.align	2
	.globl	main
	.ent	main
main:
		.frame	$fp,40,$31		# vars= 16, regs= 2/0, args= 16, extra= 0
		.mask	0xc0000000,-4
		.fmask	0x00000000,0
 		subu	$sp,$sp,40
 		sw	$31,36($sp)
 		sw	$fp,32($sp)
 		move	$fp,$sp
 		jal	__main
 		li	$2,61			# 0x3d
 		sw	$2,20($fp)
 		li	$2,62			# 0x3e
 		sw	$2,24($fp)
 		li	$2,63			# 0x3f
 		sw	$2,28($fp)
 		lw	$4,20($fp)
 		jal	test
 
 		sw	$2,16($fp)
 		lw	$2,16($fp)
 
 		lw	$2,0($2)
 
 		sw	$2,28($fp)
 		lw	$3,16($fp)
 		li	$2,70			# 0x46
 		sw	$2,0($3)
 		lw	$2,16($fp)
 
 		lw	$2,0($2)
 
 		sw	$2,28($fp)
 		lw	$4,20($fp)
 		jal	foo
 
 		sw	$2,24($fp)
 		lw	$2,16($fp)
 
 		lw	$2,0($2)
 
 		sw	$2,28($fp)
 		li	$2,2			# 0x2
 		move	$sp,$fp
 		lw	$31,36($sp)
 		lw	$fp,32($sp)
 		addu	$sp,$sp,40
 		j	$31
		.end	main
		.align	2
		.globl	test
		.ent	test
	test:


		.frame	$fp,32,$31		# vars= 8, regs= 2/0, args= 16, extra= 0
		.mask	0xc0000000,-4
		.fmask	0x00000000,0
 		subu	$sp,$sp,32
 		sw	$31,28($sp)
 		sw	$fp,24($sp)
 		move	$fp,$sp
 		sw	$4,32($fp)
 		lw	$4,32($fp)
 		jal	dummy
 
 		lw	$2,32($fp)
 
 		sw	$2,16($fp)
 		addu	$2,$fp,16
 		move	$sp,$fp
 		lw	$31,28($sp)
 		lw	$fp,24($sp)
 		addu	$sp,$sp,32
 		j	$31
		.end	test
		.align	2
		.globl	foo
		.ent	foo
	foo:
		.frame	$fp,40,$31		# vars= 16, regs= 2/0, args= 16, extra= 0
		.mask	0xc0000000,-4
		.fmask	0x00000000,0
 		subu	$sp,$sp,40
 		sw	$31,36($sp)
 		sw	$fp,32($sp)
 		move	$fp,$sp
 		sw	$4,40($fp)
 		li	$2,65			# 0x41
 		sw	$2,16($fp)
 		li	$2,66			# 0x42
 		sw	$2,20($fp)
 		lw	$3,16($fp)
 		lw	$2,20($fp)
 
 		addu	$2,$3,$2
 		sw	$2,24($fp)
 		lw	$4,24($fp)
 		jal	dummy
 
 		lw	$2,24($fp)
 		move	$sp,$fp
 		lw	$31,36($sp)
 		lw	$fp,32($sp)
 		addu	$sp,$sp,40
 		j	$31
 		.end	foo
 		.align	2
 		.globl	__main
 		.ent	__main
 	__main:
 		.frame	$fp,8,$31		# vars= 0, regs= 1/0, args= 0, extra= 0


 		.mask	0x40000000,-8
 		.fmask	0x00000000,0
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
