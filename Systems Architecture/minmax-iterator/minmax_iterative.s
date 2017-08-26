GAS LISTING /tmp/cc3PQtnT.s 			page 1


   1              		.file	1 "G1.c"
   2              		.globl	A
   3              		.data
   4              		.align	2
   5              	A:
   6 ???? 0B000000 		.word	11
   7 ???? 02000000 		.word	2
   8 ???? 21000000 		.word	33
   9 ???? 04000000 		.word	4
  10 ???? 0F000000 		.word	15
  11 ???? 06000000 		.word	6
  12 ???? 07000000 		.word	7
  13 ???? 08000000 		.word	8
  14 ???? 09000000 		.word	9
  15 ???? 0A000000 		.word	10
  16              		.rdata
  17              		.align	2
  18              	$LC0:
  19 ???? 4D696E4D 		.ascii	"MinMaxIt = \000"
  19      61784974 
  19      203D2000 
  20              		.sdata
  21              		.align	2
  22              	$LC1:
  23 ???? 202000   		.ascii	"  \000"
  24              		.align	2
  25              	$LC2:
  26 ???? 0A00     		.ascii	"\n\000"
  27              		.text
  28              		.align	2
  29              		.globl	main
  30              		.ent	main
  31              	main:
  32              		.frame	$fp,32,$31		# vars= 8, regs= 2/0, args= 16, extra= 0
  33              		.mask	0xc0000000,-4
  34              		.fmask	0x00000000,0
  35 ???? E0FFBD27 		subu	$sp,$sp,32
  36 ???? 1C00BFAF 		sw	$31,28($sp)
  37 ???? 1800BEAF 		sw	$fp,24($sp)
  38 ???? 0000000C 		move	$fp,$sp
  39 ???? 21F0A003 		jal	__main
  40 ???? 1400C227 		addu	$2,$fp,20
  41 ???? 0000043C 		la	$4,A
  41      00008424 
  42 ???? 0A000524 		li	$5,10			# 0xa
  43 ???? 1000C627 		addu	$6,$fp,16
  44 ???? 0000000C 		move	$7,$2
  45 ???? 21384000 		jal	MinMaxIt
  46 ???? 0000043C 		la	$4,$LC0
  46      0000000C 
  47 ???? 00008424 		jal	print_str
  48 ???? 1000C48F 		lw	$4,16($fp)
  49 ???? 0000000C 		jal	print_int
  49      00000000 
  50 ???? 00008427 		la	$4,$LC1
  51 ???? 0000000C 		jal	print_str
  51      00000000 
GAS LISTING /tmp/cc3PQtnT.s 			page 2


  52 ???? 1400C48F 		lw	$4,20($fp)
  53 ???? 0000000C 		jal	print_int
  53      00000000 
  54 ???? 00008427 		la	$4,$LC2
  55 ???? 0000000C 		jal	print_str
  55      00000000 
  56 ???? 21100000 		move	$2,$0
  57 ???? 21E8C003 		move	$sp,$fp
  58 ???? 1C00BF8F 		lw	$31,28($sp)
  59 ???? 1800BE8F 		lw	$fp,24($sp)
  60 ???? 0800E003 		addu	$sp,$sp,32
  61 ???? 2000BD27 		j	$31
  62              		.end	main
  63              		.align	2
  64              		.globl	MinMaxIt
  65              		.ent	MinMaxIt
  66              	MinMaxIt:
  67              		.frame	$fp,16,$31		# vars= 0, regs= 4/0, args= 0, extra= 0
  68              		.mask	0x40e00000,-4
  69              		.fmask	0x00000000,0
  70 ???? F0FFBD27 		subu	$sp,$sp,16
  71 ???? 0C00BEAF 		sw	$fp,12($sp)
  72 ???? 0800B7AF 		sw	$23,8($sp)
  73 ???? 0400B6AF 		sw	$22,4($sp)
  74 ???? 0000B5AF 		sw	$21,0($sp)
  75 ???? 21F0A003 		move	$fp,$sp
  76 ???? 1000C4AF 		sw	$4,16($fp)
  77 ???? 1400C5AF 		sw	$5,20($fp)
  78 ???? 1800C6AF 		sw	$6,24($fp)
  79 ???? 1C00C7AF 		sw	$7,28($fp)
  80 ???? 1000C28F 		lw	$2,16($fp)
  80      00000000 
  81 ???? 0000558C 		lw	$21,0($2)
  82 ???? 1000C38F 		lw	$3,16($fp)
  82      00000000 
  83 ???? 0000768C 		lw	$22,0($3)
  84 ???? 1000C28F 		lw	$2,16($fp)
  84      00000000 
  85 ???? 04005724 		addu	$23,$2,4
  86              	$L3:
  87 ???? 1400C28F 		lw	$2,20($fp)
  87      00000000 
  88 ???? 80100200 		sll	$2,$2,2
  89 ???? 1000C38F 		lw	$3,16($fp)
  89      00000000 
  90 ???? 21106200 		addu	$2,$3,$2
  91 ???? 2B10E202 		sltu	$2,$23,$2
  92 ???? 00004014 		bne	$2,$0,$L6
  92      00000000 
  93 ???? 00000008 		j	$L4
  93      00000000 
  94              	$L6:
  95 ???? 0000E28E 		lw	$2,0($23)
  95      00000000 
  96 ???? 2A105500 		slt	$2,$2,$21
  97 ???? 00004010 		beq	$2,$0,$L7
  97      00000000 
GAS LISTING /tmp/cc3PQtnT.s 			page 3


  98 ???? 0000F58E 		lw	$21,0($23)
  99              	$L7:
 100 ???? 0000E28E 		lw	$2,0($23)
 100      00000000 
 101 ???? 2A10C202 		slt	$2,$22,$2
 102 ???? 00004010 		beq	$2,$0,$L5
 102      00000000 
 103 ???? 0000F68E 		lw	$22,0($23)
 104              	$L5:
 105 ???? 00000008 		addu	$23,$23,4
 106 ???? 0400F726 		j	$L3
 107              	$L4:
 108 ???? 1C00C28F 		lw	$2,28($fp)
 108      00000000 
 109 ???? 000056AC 		sw	$22,0($2)
 110 ???? 1800C38F 		lw	$3,24($fp)
 110      00000000 
 111 ???? 000075AC 		sw	$21,0($3)
 112 ???? 21100000 		move	$2,$0
 113 ???? 21E8C003 		move	$sp,$fp
 114 ???? 0C00BE8F 		lw	$fp,12($sp)
 115 ???? 0800B78F 		lw	$23,8($sp)
 116 ???? 0400B68F 		lw	$22,4($sp)
 117 ???? 0000B58F 		lw	$21,0($sp)
 118 ???? 0800E003 		addu	$sp,$sp,16
 119 ???? 1000BD27 		j	$31
 120              		.end	MinMaxIt
 121              		.align	2
 122              		.globl	__main
 123              		.ent	__main
 124              	__main:
 125              		.frame	$fp,8,$31		# vars= 0, regs= 1/0, args= 0, extra= 0
 126              		.mask	0x40000000,-8
 127              		.fmask	0x00000000,0
 128 ???? F8FFBD27 		subu	$sp,$sp,8
 129 ???? 0000BEAF 		sw	$fp,0($sp)
 130 ???? 21F0A003 		move	$fp,$sp
 131 ???? 21100000 		move	$2,$0
 132 ???? 21E8C003 		move	$sp,$fp
 133 ???? 0000BE8F 		lw	$fp,0($sp)
 134 ???? 0800E003 		addu	$sp,$sp,8
 135 ???? 0800BD27 		j	$31
 136              		.end	__main
 137              		.align	2
 138              		.globl	dummy
 139              		.ent	dummy
 140              	dummy:
 141              		.frame	$fp,8,$31		# vars= 0, regs= 1/0, args= 0, extra= 0
 142              		.mask	0x40000000,-8
 143              		.fmask	0x00000000,0
 144 ???? F8FFBD27 		subu	$sp,$sp,8
 145 ???? 0000BEAF 		sw	$fp,0($sp)
 146 ???? 21F0A003 		move	$fp,$sp
 147 ???? 0800C4AF 		sw	$4,8($fp)
 148 ???? 21100000 		move	$2,$0
 149 ???? 21E8C003 		move	$sp,$fp
 150 ???? 0000BE8F 		lw	$fp,0($sp)
GAS LISTING /tmp/cc3PQtnT.s 			page 4


 151 ???? 0800E003 		addu	$sp,$sp,8
 152 ???? 0800BD27 		j	$31
 153              		.end	dummy
 154              		.align	2
 155              		.globl	print_int
 156              		.ent	print_int
 157              	print_int:
 158              		.frame	$fp,16,$31		# vars= 8, regs= 1/0, args= 0, extra= 0
 159              		.mask	0x40000000,-8
 160              		.fmask	0x00000000,0
 161 ???? F0FFBD27 		subu	$sp,$sp,16
 162 ???? 0800BEAF 		sw	$fp,8($sp)
 163 ???? 21F0A003 		move	$fp,$sp
 164 ???? 1000C4AF 		sw	$4,16($fp)
 165 ???? 01000224 		li	$2,1			# 0x1
 166 ???? 0000C2AF 		sw	$2,0($fp)
 167 ???? 0000C38F 		lw	$3,0($fp)
 168 ???? 1000C28F 		lw	$2,16($fp)
 169              	 #APP
 170              		add $a0,$2,$zero
 171              		add $v0,$3,$zero
 172 ???? 0C000000 		syscall
 173              	 #NO_APP
 174 ???? 1000C28F 		lw	$2,16($fp)
 175 ???? 21E8C003 		move	$sp,$fp
 176 ???? 0800BE8F 		lw	$fp,8($sp)
 177 ???? 0800E003 		addu	$sp,$sp,16
 178 ???? 1000BD27 		j	$31
 179              		.end	print_int
 180              		.align	2
 181              		.globl	print_hex
 182              		.ent	print_hex
 183              	print_hex:
 184              		.frame	$fp,40,$31		# vars= 16, regs= 2/0, args= 16, extra= 0
 185              		.mask	0xc0000000,-4
 186              		.fmask	0x00000000,0
 187 ???? D8FFBD27 		subu	$sp,$sp,40
 188 ???? 2400BFAF 		sw	$31,36($sp)
 189 ???? 2000BEAF 		sw	$fp,32($sp)
 190 ???? 21F0A003 		move	$fp,$sp
 191 ???? 2800C4AF 		sw	$4,40($fp)
 192 ???? 2800C48F 		lw	$4,40($fp)
 193 ???? 0000000C 		addu	$5,$fp,16
 194 ???? 1000C527 		jal	itox
 195 ???? 0000000C 		addu	$4,$fp,16
 196 ???? 1000C427 		jal	print_str
 197 ???? 2800C28F 		lw	$2,40($fp)
 198 ???? 21E8C003 		move	$sp,$fp
 199 ???? 2400BF8F 		lw	$31,36($sp)
 200 ???? 2000BE8F 		lw	$fp,32($sp)
 201 ???? 0800E003 		addu	$sp,$sp,40
 202 ???? 2800BD27 		j	$31
 203              		.end	print_hex
 204              		.align	2
 205              		.globl	print_str
 206              		.ent	print_str
 207              	print_str:
GAS LISTING /tmp/cc3PQtnT.s 			page 5


 208              		.frame	$fp,16,$31		# vars= 8, regs= 1/0, args= 0, extra= 0
 209              		.mask	0x40000000,-8
 210              		.fmask	0x00000000,0
 211 ???? F0FFBD27 		subu	$sp,$sp,16
 212 ???? 0800BEAF 		sw	$fp,8($sp)
 213 ???? 21F0A003 		move	$fp,$sp
 214 ???? 1000C4AF 		sw	$4,16($fp)
 215 ???? 04000224 		li	$2,4			# 0x4
 216 ???? 0000C2AF 		sw	$2,0($fp)
 217 ???? 0000C38F 		lw	$3,0($fp)
 218 ???? 1000C28F 		lw	$2,16($fp)
 219              	 #APP
 220              		add $a0,$2,$zero
 221              		add $v0,$3,$zero
 222 ???? 0C000000 		syscall
 223              	 #NO_APP
 224 ???? 21100000 		move	$2,$0
 225 ???? 21E8C003 		move	$sp,$fp
 226 ???? 0800BE8F 		lw	$fp,8($sp)
 227 ???? 0800E003 		addu	$sp,$sp,16
 228 ???? 1000BD27 		j	$31
 229              		.end	print_str
 230              		.align	2
 231              		.globl	itox
 232              		.ent	itox
 233              	itox:
 234              		.frame	$fp,24,$31		# vars= 16, regs= 1/0, args= 0, extra= 0
 235              		.mask	0x40000000,-8
 236              		.fmask	0x00000000,0
 237 ???? E8FFBD27 		subu	$sp,$sp,24
 238 ???? 1000BEAF 		sw	$fp,16($sp)
 239 ???? 21F0A003 		move	$fp,$sp
 240 ???? 1800C4AF 		sw	$4,24($fp)
 241 ???? 1C00C5AF 		sw	$5,28($fp)
 242 ???? 07000224 		li	$2,7			# 0x7
 243 ???? 0400C2AF 		sw	$2,4($fp)
 244 ???? 0000C0AF 		sw	$0,0($fp)
 245              	$L15:
 246 ???? 0000C28F 		lw	$2,0($fp)
 246      00000000 
 247 ???? 08004228 		slt	$2,$2,8
 248 ???? 00004014 		bne	$2,$0,$L18
 248      00000000 
 249 ???? 00000008 		j	$L16
 249      00000000 
 250              	$L18:
 251 ???? 1800C28F 		lw	$2,24($fp)
 251      00000000 
 252 ???? 0F004230 		andi	$2,$2,0xf
 253 ???? 0800C2AF 		sw	$2,8($fp)
 254 ???? 0800C28F 		lw	$2,8($fp)
 254      00000000 
 255 ???? 0A004228 		slt	$2,$2,10
 256 ???? 00004010 		beq	$2,$0,$L19
 256      00000000 
 257 ???? 1C00C38F 		lw	$3,28($fp)
 258 ???? 0400C28F 		lw	$2,4($fp)
GAS LISTING /tmp/cc3PQtnT.s 			page 6


 258      00000000 
 259 ???? 21186200 		addu	$3,$3,$2
 260 ???? 0800C293 		lbu	$2,8($fp)
 260      00000000 
 261 ???? 30004224 		addu	$2,$2,48
 262 ???? 00000008 		sb	$2,0($3)
 263 ???? 000062A0 		j	$L20
 264              	$L19:
 265 ???? 1C00C38F 		lw	$3,28($fp)
 266 ???? 0400C28F 		lw	$2,4($fp)
 266      00000000 
 267 ???? 21186200 		addu	$3,$3,$2
 268 ???? 0800C293 		lbu	$2,8($fp)
 268      00000000 
 269 ???? 37004224 		addu	$2,$2,55
 270 ???? 000062A0 		sb	$2,0($3)
 271              	$L20:
 272 ???? 1800C28F 		lw	$2,24($fp)
 272      00000000 
 273 ???? 03110200 		sra	$2,$2,4
 274 ???? 1800C2AF 		sw	$2,24($fp)
 275 ???? 0400C28F 		lw	$2,4($fp)
 275      00000000 
 276 ???? FFFF4224 		addu	$2,$2,-1
 277 ???? 0400C2AF 		sw	$2,4($fp)
 278 ???? 0000C28F 		lw	$2,0($fp)
 278      00000000 
 279 ???? 01004224 		addu	$2,$2,1
 280 ???? 00000008 		sw	$2,0($fp)
 281 ???? 0000C2AF 		j	$L15
 282              	$L16:
 283 ???? 1C00C28F 		lw	$2,28($fp)
 283      00000000 
 284 ???? 08004224 		addu	$2,$2,8
 285 ???? 000040A0 		sb	$0,0($2)
 286 ???? 1800C28F 		lw	$2,24($fp)
 287 ???? 21E8C003 		move	$sp,$fp
 288 ???? 1000BE8F 		lw	$fp,16($sp)
 289 ???? 0800E003 		addu	$sp,$sp,24
 290 ???? 1800BD27 		j	$31
 291              		.end	itox
 292              		.align	2
 293              		.globl	print_stack
 294              		.ent	print_stack
 295              	print_stack:
 296              		.frame	$fp,40,$31		# vars= 16, regs= 2/0, args= 16, extra= 0
 297              		.mask	0xc0000000,-4
 298              		.fmask	0x00000000,0
 299 ???? D8FFBD27 		subu	$sp,$sp,40
 300 ???? 2400BFAF 		sw	$31,36($sp)
 301 ???? 2000BEAF 		sw	$fp,32($sp)
 302 ???? 21F0A003 		move	$fp,$sp
 303 ???? 2800C4AF 		sw	$4,40($fp)
 304 ???? 2A000224 		li	$2,42			# 0x2a
 305 ???? 1C00C2AF 		sw	$2,28($fp)
 306 ???? 2800C227 		addu	$2,$fp,40
 307 ???? 1000C2AF 		sw	$2,16($fp)
GAS LISTING /tmp/cc3PQtnT.s 			page 7


 308 ???? 1000C28F 		lw	$2,16($fp)
 308      00000000 
 309 ???? 1400C2AF 		sw	$2,20($fp)
 310 ???? 1400C48F 		lw	$4,20($fp)
 311 ???? 0000000C 		jal	print_hex
 311      00000000 
 312 ???? 00008427 		la	$4,$LC2
 313 ???? 0000000C 		jal	print_str
 313      00000000 
 314 ???? 1000C28F 		lw	$2,16($fp)
 314      00000000 
 315 ???? B0FF4224 		addu	$2,$2,-80
 316 ???? 1000C2AF 		sw	$2,16($fp)
 317 ???? 1800C0AF 		sw	$0,24($fp)
 318              	$L22:
 319 ???? 1800C28F 		lw	$2,24($fp)
 319      00000000 
 320 ???? 52004228 		slt	$2,$2,82
 321 ???? 00004014 		bne	$2,$0,$L25
 321      00000000 
 322 ???? 00000008 		j	$L23
 322      00000000 
 323              	$L25:
 324 ???? 1000C28F 		lw	$2,16($fp)
 324      00000000 
 325 ???? 1400C2AF 		sw	$2,20($fp)
 326 ???? 1400C48F 		lw	$4,20($fp)
 327 ???? 0000000C 		jal	print_hex
 327      00000000 
 328 ???? 00008427 		la	$4,$LC1
 329 ???? 0000000C 		jal	print_str
 329      00000000 
 330 ???? 1000C28F 		lw	$2,16($fp)
 330      00000000 
 331 ???? 0000428C 		lw	$2,0($2)
 331      00000000 
 332 ???? 1400C2AF 		sw	$2,20($fp)
 333 ???? 1400C48F 		lw	$4,20($fp)
 334 ???? 0000000C 		jal	print_hex
 334      00000000 
 335 ???? 00008427 		la	$4,$LC2
 336 ???? 0000000C 		jal	print_str
 336      00000000 
 337 ???? 1000C28F 		lw	$2,16($fp)
 337      00000000 
 338 ???? 04004224 		addu	$2,$2,4
 339 ???? 1000C2AF 		sw	$2,16($fp)
 340 ???? 1800C28F 		lw	$2,24($fp)
 340      00000000 
 341 ???? 01004224 		addu	$2,$2,1
 342 ???? 00000008 		sw	$2,24($fp)
 343 ???? 1800C2AF 		j	$L22
 344              	$L23:
 345 ???? 1C00C28F 		lw	$2,28($fp)
 346 ???? 21E8C003 		move	$sp,$fp
 347 ???? 2400BF8F 		lw	$31,36($sp)
 348 ???? 2000BE8F 		lw	$fp,32($sp)
GAS LISTING /tmp/cc3PQtnT.s 			page 8


 349 ???? 0800E003 		addu	$sp,$sp,40
 350 ???? 2800BD27 		j	$31
 351              		.end	print_stack
