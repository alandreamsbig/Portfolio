


   1              		.file	1 "stack-test3.c"
   2              		.text
   3              		.align	2
   4              		.globl	main
   5              		.ent	main
   6              	main:
   7              		.frame	$fp,40,$31		# vars= 16, regs= 2/0, args= 16, extra= 0
   8              		.mask	0xc0000000,-4
   9              		.fmask	0x00000000,0
  10 0000 D8FFBD27 		subu	$sp,$sp,40
  11 0004 2400BFAF 		sw	$31,36($sp)
  12 0008 2000BEAF 		sw	$fp,32($sp)
  13 000c 5300000C 		move	$fp,$sp
  14 0010 21F0A003 		jal	__main
  15 0014 3D000224 		li	$2,61			# 0x3d
  16 0018 1400C2AF 		sw	$2,20($fp)
  17 001c 3E000224 		li	$2,62			# 0x3e
  18 0020 1800C2AF 		sw	$2,24($fp)
  19 0024 3F000224 		li	$2,63			# 0x3f
  20 0028 1C00C2AF 		sw	$2,28($fp)
  21 002c 1400C48F 		lw	$4,20($fp)
  22 0030 2B00000C 		jal	test
  22      00000000 
  23 0038 1000C2AF 		sw	$2,16($fp)
  24 003c 1000C28F 		lw	$2,16($fp)
  24      00000000 
  25 0044 0000428C 		lw	$2,0($2)
  25      00000000 
  26 004c 1C00C2AF 		sw	$2,28($fp)
  27 0050 1000C38F 		lw	$3,16($fp)
  28 0054 46000224 		li	$2,70			# 0x46
  29 0058 000062AC 		sw	$2,0($3)
  30 005c 1000C28F 		lw	$2,16($fp)
  30      00000000 
  31 0064 0000428C 		lw	$2,0($2)
  31      00000000 
  32 006c 1C00C2AF 		sw	$2,28($fp)
  33 0070 1400C48F 		lw	$4,20($fp)
  34 0074 3C00000C 		jal	foo
  34      00000000 
  35 007c 1800C2AF 		sw	$2,24($fp)
  36 0080 1000C28F 		lw	$2,16($fp)
  36      00000000 
  37 0088 0000428C 		lw	$2,0($2)
  37      00000000 
  38 0090 1C00C2AF 		sw	$2,28($fp)
  39 0094 02000224 		li	$2,2			# 0x2
  40 0098 21E8C003 		move	$sp,$fp
  41 009c 2400BF8F 		lw	$31,36($sp)
  42 00a0 2000BE8F 		lw	$fp,32($sp)
  43 00a4 0800E003 		addu	$sp,$sp,40
  44 00a8 2800BD27 		j	$31
  45              		.end	main
  46              	
  47              		.lcomm	c.0,4
  48              		.align	2
  49              		.globl	test
GAS LISTING /tmp/ccTIRmrP.s 			page 2


  50              		.ent	test
  51              	test:
  52              		.frame	$fp,24,$31		# vars= 0, regs= 2/0, args= 16, extra= 0
  53              		.mask	0xc0000000,-4
  54              		.fmask	0x00000000,0
  55 00ac E8FFBD27 		subu	$sp,$sp,24
  56 00b0 1400BFAF 		sw	$31,20($sp)
  57 00b4 1000BEAF 		sw	$fp,16($sp)
  58 00b8 21F0A003 		move	$fp,$sp
  59 00bc 1800C4AF 		sw	$4,24($fp)
  60 00c0 1800C48F 		lw	$4,24($fp)
  61 00c4 5B00000C 		jal	dummy
  61      00000000 
  62 00cc 1800C28F 		lw	$2,24($fp)
  62      00000000 
  63 00d4 00C082AF 		sw	$2,c.0
  64 00d8 00C08227 		la	$2,c.0
  65 00dc 21E8C003 		move	$sp,$fp
  66 00e0 1400BF8F 		lw	$31,20($sp)
  67 00e4 1000BE8F 		lw	$fp,16($sp)
  68 00e8 0800E003 		addu	$sp,$sp,24
  69 00ec 1800BD27 		j	$31
  70              		.end	test
  71              		.align	2
  72              		.globl	foo
  73              		.ent	foo
  74              	foo:
  75              		.frame	$fp,40,$31		# vars= 16, regs= 2/0, args= 16, extra= 0
  76              		.mask	0xc0000000,-4
  77              		.fmask	0x00000000,0
  78 00f0 D8FFBD27 		subu	$sp,$sp,40
  79 00f4 2400BFAF 		sw	$31,36($sp)
  80 00f8 2000BEAF 		sw	$fp,32($sp)
  81 00fc 21F0A003 		move	$fp,$sp
  82 0100 2800C4AF 		sw	$4,40($fp)
  83 0104 41000224 		li	$2,65			# 0x41
  84 0108 1000C2AF 		sw	$2,16($fp)
  85 010c 42000224 		li	$2,66			# 0x42
  86 0110 1400C2AF 		sw	$2,20($fp)
  87 0114 1000C38F 		lw	$3,16($fp)
  88 0118 1400C28F 		lw	$2,20($fp)
  88      00000000 
  89 0120 21106200 		addu	$2,$3,$2
  90 0124 1800C2AF 		sw	$2,24($fp)
  91 0128 1800C48F 		lw	$4,24($fp)
  92 012c 5B00000C 		jal	dummy
  92      00000000 
  93 0134 1800C28F 		lw	$2,24($fp)
  94 0138 21E8C003 		move	$sp,$fp
  95 013c 2400BF8F 		lw	$31,36($sp)
  96 0140 2000BE8F 		lw	$fp,32($sp)
  97 0144 0800E003 		addu	$sp,$sp,40
  98 0148 2800BD27 		j	$31
  99              		.end	foo
 100              		.align	2
 101              		.globl	__main
 102              		.ent	__main
GAS LISTING /tmp/ccTIRmrP.s 			page 3


 103              	__main:
 104              		.frame	$fp,8,$31		# vars= 0, regs= 1/0, args= 0, extra= 0
 105              		.mask	0x40000000,-8
 106              		.fmask	0x00000000,0
 107 014c F8FFBD27 		subu	$sp,$sp,8
 108 0150 0000BEAF 		sw	$fp,0($sp)
 109 0154 21F0A003 		move	$fp,$sp
 110 0158 21100000 		move	$2,$0
 111 015c 21E8C003 		move	$sp,$fp
 112 0160 0000BE8F 		lw	$fp,0($sp)
 113 0164 0800E003 		addu	$sp,$sp,8
 114 0168 0800BD27 		j	$31
 115              		.end	__main
 116              		.align	2
 117              		.globl	dummy
 118              		.ent	dummy
 119              	dummy:
 120              		.frame	$fp,8,$31		# vars= 0, regs= 1/0, args= 0, extra= 0
 121              		.mask	0x40000000,-8
 122              		.fmask	0x00000000,0
 123 016c F8FFBD27 		subu	$sp,$sp,8
 124 0170 0000BEAF 		sw	$fp,0($sp)
 125 0174 21F0A003 		move	$fp,$sp
 126 0178 0800C4AF 		sw	$4,8($fp)
 127 017c 21100000 		move	$2,$0
 128 0180 21E8C003 		move	$sp,$fp
 129 0184 0000BE8F 		lw	$fp,0($sp)
 130 0188 0800E003 		addu	$sp,$sp,8
 131 018c 0800BD27 		j	$31
 132              		.end	dummy
