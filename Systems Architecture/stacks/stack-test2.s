


   1              		.file	1 "stack-test2.c"
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
  46              		.align	2
  47              		.globl	test
  48              		.ent	test
  49              	test:
GAS LISTING /tmp/ccaW2kAe.s 			page 2


  50              		.frame	$fp,32,$31		# vars= 8, regs= 2/0, args= 16, extra= 0
  51              		.mask	0xc0000000,-4
  52              		.fmask	0x00000000,0
  53 00ac E0FFBD27 		subu	$sp,$sp,32
  54 00b0 1C00BFAF 		sw	$31,28($sp)
  55 00b4 1800BEAF 		sw	$fp,24($sp)
  56 00b8 21F0A003 		move	$fp,$sp
  57 00bc 2000C4AF 		sw	$4,32($fp)
  58 00c0 2000C48F 		lw	$4,32($fp)
  59 00c4 5B00000C 		jal	dummy
  59      00000000 
  60 00cc 2000C28F 		lw	$2,32($fp)
  60      00000000 
  61 00d4 1000C2AF 		sw	$2,16($fp)
  62 00d8 1000C227 		addu	$2,$fp,16
  63 00dc 21E8C003 		move	$sp,$fp
  64 00e0 1C00BF8F 		lw	$31,28($sp)
  65 00e4 1800BE8F 		lw	$fp,24($sp)
  66 00e8 0800E003 		addu	$sp,$sp,32
  67 00ec 2000BD27 		j	$31
  68              		.end	test
  69              		.align	2
  70              		.globl	foo
  71              		.ent	foo
  72              	foo:
  73              		.frame	$fp,40,$31		# vars= 16, regs= 2/0, args= 16, extra= 0
  74              		.mask	0xc0000000,-4
  75              		.fmask	0x00000000,0
  76 00f0 D8FFBD27 		subu	$sp,$sp,40
  77 00f4 2400BFAF 		sw	$31,36($sp)
  78 00f8 2000BEAF 		sw	$fp,32($sp)
  79 00fc 21F0A003 		move	$fp,$sp
  80 0100 2800C4AF 		sw	$4,40($fp)
  81 0104 41000224 		li	$2,65			# 0x41
  82 0108 1000C2AF 		sw	$2,16($fp)
  83 010c 42000224 		li	$2,66			# 0x42
  84 0110 1400C2AF 		sw	$2,20($fp)
  85 0114 1000C38F 		lw	$3,16($fp)
  86 0118 1400C28F 		lw	$2,20($fp)
  86      00000000 
  87 0120 21106200 		addu	$2,$3,$2
  88 0124 1800C2AF 		sw	$2,24($fp)
  89 0128 1800C48F 		lw	$4,24($fp)
  90 012c 5B00000C 		jal	dummy
  90      00000000 
  91 0134 1800C28F 		lw	$2,24($fp)
  92 0138 21E8C003 		move	$sp,$fp
  93 013c 2400BF8F 		lw	$31,36($sp)
  94 0140 2000BE8F 		lw	$fp,32($sp)
  95 0144 0800E003 		addu	$sp,$sp,40
  96 0148 2800BD27 		j	$31
  97              		.end	foo
  98              		.align	2
  99              		.globl	__main
 100              		.ent	__main
 101              	__main:
 102              		.frame	$fp,8,$31		# vars= 0, regs= 1/0, args= 0, extra= 0
GAS LISTING /tmp/ccaW2kAe.s 			page 3


 103              		.mask	0x40000000,-8
 104              		.fmask	0x00000000,0
 105 014c F8FFBD27 		subu	$sp,$sp,8
 106 0150 0000BEAF 		sw	$fp,0($sp)
 107 0154 21F0A003 		move	$fp,$sp
 108 0158 21100000 		move	$2,$0
 109 015c 21E8C003 		move	$sp,$fp
 110 0160 0000BE8F 		lw	$fp,0($sp)
 111 0164 0800E003 		addu	$sp,$sp,8
 112 0168 0800BD27 		j	$31
 113              		.end	__main
 114              		.align	2
 115              		.globl	dummy
 116              		.ent	dummy
 117              	dummy:
 118              		.frame	$fp,8,$31		# vars= 0, regs= 1/0, args= 0, extra= 0
 119              		.mask	0x40000000,-8
 120              		.fmask	0x00000000,0
 121 016c F8FFBD27 		subu	$sp,$sp,8
 122 0170 0000BEAF 		sw	$fp,0($sp)
 123 0174 21F0A003 		move	$fp,$sp
 124 0178 0800C4AF 		sw	$4,8($fp)
 125 017c 21100000 		move	$2,$0
 126 0180 21E8C003 		move	$sp,$fp
 127 0184 0000BE8F 		lw	$fp,0($sp)
 128 0188 0800E003 		addu	$sp,$sp,8
 129 018c 0800BD27 		j	$31
 130              		.end	dummy
