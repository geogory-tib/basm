	.file	"parse_tokens.c"
	.intel_syntax noprefix
	.text
	.globl	dir_table
	.section	.rodata
.LC0:
	.string	"byte"
.LC1:
	.string	"fill"
.LC2:
	.string	"org"
.LC3:
	.string	"word"
	.section	.data.rel.local,"aw"
	.align 32
	.type	dir_table, @object
	.size	dir_table, 64
dir_table:
	.quad	.LC0
	.long	-1
	.zero	4
	.quad	.LC1
	.long	2
	.zero	4
	.quad	.LC2
	.long	1
	.zero	4
	.quad	.LC3
	.long	-1
	.zero	4
	.globl	ins_table
	.section	.rodata
.LC4:
	.string	"adc"
.LC5:
	.string	"and"
.LC6:
	.string	"asl"
.LC7:
	.string	"bcc"
.LC8:
	.string	"bcs"
.LC9:
	.string	"beq"
.LC10:
	.string	"bmi"
.LC11:
	.string	"bne"
.LC12:
	.string	"bpl"
.LC13:
	.string	"bvc"
.LC14:
	.string	"bvs"
.LC15:
	.string	"brk"
.LC16:
	.string	"bit"
.LC17:
	.string	"clc"
.LC18:
	.string	"cld"
.LC19:
	.string	"cli"
.LC20:
	.string	"clv"
.LC21:
	.string	"cmp"
.LC22:
	.string	"cpx"
.LC23:
	.string	"cpy"
.LC24:
	.string	"dec"
.LC25:
	.string	"dex"
.LC26:
	.string	"dey"
.LC27:
	.string	"eor"
.LC28:
	.string	"inc"
.LC29:
	.string	"inx"
.LC30:
	.string	"iny"
.LC31:
	.string	"jmp"
.LC32:
	.string	"jsr"
.LC33:
	.string	"lda"
.LC34:
	.string	"ldx"
.LC35:
	.string	"ldy"
.LC36:
	.string	"lsr"
.LC37:
	.string	"nop"
.LC38:
	.string	"ora"
.LC39:
	.string	"pha"
.LC40:
	.string	"php"
.LC41:
	.string	"pla"
.LC42:
	.string	"plp"
.LC43:
	.string	"rol"
.LC44:
	.string	"ror"
.LC45:
	.string	"rti"
.LC46:
	.string	"rts"
.LC47:
	.string	"sbc"
.LC48:
	.string	"sec"
.LC49:
	.string	"sed"
.LC50:
	.string	"sei"
.LC51:
	.string	"sta"
.LC52:
	.string	"stx"
.LC53:
	.string	"sty"
.LC54:
	.string	"tax"
.LC55:
	.string	"tay"
.LC56:
	.string	"tsx"
.LC57:
	.string	"txa"
.LC58:
	.string	"txs"
.LC59:
	.string	"tya"
	.section	.data.rel.local
	.align 32
	.type	ins_table, @object
	.size	ins_table, 1792
ins_table:
	.quad	.LC4
	.string	""
	.string	""
	.string	"ieu"
	.string	""
	.string	"m}y"
	.ascii	"aq"
	.zero	3
	.long	0
	.zero	4
	.quad	.LC5
	.string	""
	.string	""
	.string	")%5"
	.string	""
	.string	"-=9"
	.ascii	"!1"
	.zero	3
	.long	0
	.zero	4
	.quad	.LC6
	.string	""
	.string	"\n"
	.string	"\006\026"
	.string	""
	.string	"\016\036"
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC7
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	"\220"
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC8
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	"\260"
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC9
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	"\360"
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC10
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	"0"
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC11
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	"\320"
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC12
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	"\020"
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC13
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	"P"
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC14
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	"p"
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC15
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC16
	.string	""
	.string	""
	.string	""
	.string	"$"
	.string	""
	.string	""
	.string	","
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC17
	.string	"\030"
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC18
	.string	"\330"
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC19
	.string	"X"
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC20
	.string	"\270"
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC21
	.string	""
	.string	""
	.string	"\311\305\325"
	.string	""
	.string	"\315\335\331"
	.ascii	"\301\321"
	.zero	3
	.long	0
	.zero	4
	.quad	.LC22
	.string	""
	.string	""
	.string	"\340\344"
	.string	""
	.string	""
	.string	"\354"
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC23
	.string	""
	.string	""
	.string	"\300\304"
	.string	""
	.string	""
	.string	"\314"
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC24
	.string	""
	.string	""
	.string	""
	.string	"\306\326"
	.string	""
	.string	"\316\336"
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC25
	.string	"\312"
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC26
	.string	"\210"
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC27
	.string	""
	.string	""
	.string	"IEU"
	.string	""
	.string	"M]Y"
	.ascii	"AQ"
	.zero	3
	.long	0
	.zero	4
	.quad	.LC28
	.string	""
	.string	""
	.string	""
	.string	"\346\366"
	.string	""
	.string	"\356\376"
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC29
	.string	"\350"
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC30
	.string	"\310"
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC31
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	"L"
	.string	""
	.string	"l"
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC32
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	" "
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC33
	.string	""
	.string	""
	.string	"\251\245\265"
	.string	""
	.string	"\255\275\271"
	.ascii	"\241\261"
	.zero	3
	.long	0
	.zero	4
	.quad	.LC34
	.string	""
	.string	""
	.string	"\242\246"
	.string	"\266"
	.string	"\256"
	.string	"\276"
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC35
	.string	""
	.string	""
	.string	"\240\244\264"
	.string	""
	.string	"\254\274"
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC36
	.string	""
	.string	"J"
	.string	"FV"
	.string	""
	.string	"N^"
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC37
	.string	"\352"
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC38
	.string	""
	.string	""
	.string	"\t\005\025"
	.string	""
	.string	"\r\035\031"
	.ascii	"\001\021"
	.zero	3
	.long	0
	.zero	4
	.quad	.LC39
	.string	"\b"
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC40
	.string	"H"
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC41
	.string	"h"
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC42
	.string	"("
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC43
	.string	""
	.string	"*"
	.string	"&6"
	.string	""
	.string	".>"
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC44
	.string	""
	.string	"j"
	.string	"fv"
	.string	""
	.string	"n~"
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC45
	.string	"@"
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC46
	.string	"`"
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC47
	.string	""
	.string	""
	.string	"\351\345\365"
	.string	""
	.string	"\355\375\371"
	.ascii	"\341\361"
	.zero	3
	.long	0
	.zero	4
	.quad	.LC48
	.string	"8"
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC49
	.string	"\370"
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC50
	.string	"x"
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC51
	.string	""
	.string	""
	.string	""
	.string	"\205\225"
	.string	""
	.string	"\215\235\231"
	.ascii	"\201\221"
	.zero	3
	.long	0
	.zero	4
	.quad	.LC52
	.string	""
	.string	""
	.string	""
	.string	"\206"
	.string	"\226"
	.string	"\216"
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC53
	.string	""
	.string	""
	.string	""
	.string	"\204\224"
	.string	""
	.string	"\214"
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC54
	.string	"\252"
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC55
	.string	"\250"
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC56
	.string	"\272"
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC57
	.string	"\212"
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC58
	.string	"\232"
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.quad	.LC59
	.string	"\230"
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.string	""
	.zero	3
	.long	0
	.zero	4
	.text
	.globl	append_label_slice
	.type	append_label_slice, @function
append_label_slice:
.LFB6:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 32
	mov	QWORD PTR -24[rbp], rdi
	mov	rax, QWORD PTR -24[rbp]
	mov	rdx, QWORD PTR 16[rax]
	mov	rax, QWORD PTR -24[rbp]
	mov	rax, QWORD PTR 8[rax]
	cmp	rdx, rax
	jne	.L2
	mov	rax, QWORD PTR -24[rbp]
	mov	rdx, QWORD PTR 8[rax]
	mov	rax, rdx
	add	rax, rax
	add	rax, rdx
	sal	rax, 3
	lea	rdx, 600[rax]
	mov	rax, QWORD PTR -24[rbp]
	mov	rax, QWORD PTR [rax]
	mov	rsi, rdx
	mov	rdi, rax
	call	realloc@PLT
	mov	QWORD PTR -8[rbp], rax
	cmp	QWORD PTR -8[rbp], 0
	jne	.L3
	mov	eax, -1
	jmp	.L4
.L3:
	mov	rax, QWORD PTR -24[rbp]
	mov	rdx, QWORD PTR -8[rbp]
	mov	QWORD PTR [rax], rdx
	mov	rax, QWORD PTR -24[rbp]
	mov	rax, QWORD PTR 8[rax]
	lea	rdx, 25[rax]
	mov	rax, QWORD PTR -24[rbp]
	mov	QWORD PTR 8[rax], rdx
.L2:
	mov	rax, QWORD PTR -24[rbp]
	mov	rcx, QWORD PTR [rax]
	mov	rax, QWORD PTR -24[rbp]
	mov	rdx, QWORD PTR 16[rax]
	mov	rax, rdx
	add	rax, rax
	add	rax, rdx
	sal	rax, 3
	add	rcx, rax
	mov	rax, QWORD PTR 16[rbp]
	mov	rdx, QWORD PTR 24[rbp]
	mov	QWORD PTR [rcx], rax
	mov	QWORD PTR 8[rcx], rdx
	mov	rax, QWORD PTR 32[rbp]
	mov	QWORD PTR 16[rcx], rax
	mov	rax, QWORD PTR -24[rbp]
	mov	rax, QWORD PTR 16[rax]
	lea	rdx, 1[rax]
	mov	rax, QWORD PTR -24[rbp]
	mov	QWORD PTR 16[rax], rdx
	mov	eax, 0
.L4:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	append_label_slice, .-append_label_slice
	.globl	init_parser
	.type	init_parser, @function
init_parser:
.LFB7:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	push	rbx
	sub	rsp, 120
	.cfi_offset 3, -24
	mov	QWORD PTR -120[rbp], rdi
	lea	rdx, -112[rbp]
	mov	eax, 0
	mov	ecx, 11
	mov	rdi, rdx
	rep stosq
	mov	QWORD PTR -40[rbp], 0
	mov	rax, QWORD PTR 16[rbp]
	mov	rdx, QWORD PTR 24[rbp]
	mov	QWORD PTR -112[rbp], rax
	mov	QWORD PTR -104[rbp], rdx
	mov	rax, QWORD PTR 32[rbp]
	mov	QWORD PTR -96[rbp], rax
	mov	esi, 1
	mov	edi, 1000
	call	calloc@PLT
	mov	QWORD PTR -64[rbp], rax
	mov	QWORD PTR -56[rbp], 1000
	mov	QWORD PTR -48[rbp], 0
	mov	esi, 24
	mov	edi, 10
	call	calloc@PLT
	mov	QWORD PTR -88[rbp], rax
	mov	QWORD PTR -80[rbp], 10
	mov	QWORD PTR -72[rbp], 0
	mov	rax, QWORD PTR -120[rbp]
	mov	rcx, QWORD PTR -112[rbp]
	mov	rbx, QWORD PTR -104[rbp]
	mov	QWORD PTR [rax], rcx
	mov	QWORD PTR 8[rax], rbx
	mov	rcx, QWORD PTR -96[rbp]
	mov	rbx, QWORD PTR -88[rbp]
	mov	QWORD PTR 16[rax], rcx
	mov	QWORD PTR 24[rax], rbx
	mov	rcx, QWORD PTR -80[rbp]
	mov	rbx, QWORD PTR -72[rbp]
	mov	QWORD PTR 32[rax], rcx
	mov	QWORD PTR 40[rax], rbx
	mov	rcx, QWORD PTR -64[rbp]
	mov	rbx, QWORD PTR -56[rbp]
	mov	QWORD PTR 48[rax], rcx
	mov	QWORD PTR 56[rax], rbx
	mov	rcx, QWORD PTR -48[rbp]
	mov	rbx, QWORD PTR -40[rbp]
	mov	QWORD PTR 64[rax], rcx
	mov	QWORD PTR 72[rax], rbx
	mov	rdx, QWORD PTR -32[rbp]
	mov	QWORD PTR 80[rax], rdx
	mov	rax, QWORD PTR -120[rbp]
	mov	rbx, QWORD PTR -8[rbp]
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE7:
	.size	init_parser, .-init_parser
	.globl	pull_token
	.type	pull_token, @function
pull_token:
.LFB8:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	QWORD PTR -40[rbp], rdi
	mov	QWORD PTR -48[rbp], rsi
	mov	rax, QWORD PTR -48[rbp]
	mov	rax, QWORD PTR 72[rax]
	lea	rdx, 1[rax]
	mov	rax, QWORD PTR -48[rbp]
	mov	rax, QWORD PTR 8[rax]
	cmp	rdx, rax
	jne	.L8
	mov	rax, QWORD PTR -40[rbp]
	mov	QWORD PTR [rax], 0
	mov	rax, QWORD PTR -40[rbp]
	mov	DWORD PTR 8[rax], 0
	mov	rax, QWORD PTR -40[rbp]
	mov	DWORD PTR 12[rax], 13
	mov	rax, QWORD PTR -40[rbp]
	mov	DWORD PTR 16[rax], 0
	jmp	.L7
.L8:
	mov	rax, QWORD PTR -48[rbp]
	mov	rax, QWORD PTR 72[rax]
	lea	rdx, 1[rax]
	mov	rax, QWORD PTR -48[rbp]
	mov	QWORD PTR 72[rax], rdx
	mov	rax, QWORD PTR -48[rbp]
	mov	rcx, QWORD PTR [rax]
	mov	rax, QWORD PTR -48[rbp]
	mov	rdx, QWORD PTR 72[rax]
	mov	rax, rdx
	add	rax, rax
	add	rax, rdx
	sal	rax, 3
	lea	rsi, [rcx+rax]
	mov	rcx, QWORD PTR -40[rbp]
	mov	rax, QWORD PTR [rsi]
	mov	rdx, QWORD PTR 8[rsi]
	mov	QWORD PTR [rcx], rax
	mov	QWORD PTR 8[rcx], rdx
	mov	rax, QWORD PTR 16[rsi]
	mov	QWORD PTR 16[rcx], rax
.L7:
	mov	rax, QWORD PTR -40[rbp]
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE8:
	.size	pull_token, .-pull_token
	.globl	peek_token
	.type	peek_token, @function
peek_token:
.LFB9:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	mov	QWORD PTR -40[rbp], rdi
	mov	rax, QWORD PTR 88[rbp]
	lea	rdx, 1[rax]
	mov	rax, QWORD PTR 24[rbp]
	cmp	rdx, rax
	jne	.L11
	mov	rax, QWORD PTR -40[rbp]
	mov	QWORD PTR [rax], 0
	mov	rax, QWORD PTR -40[rbp]
	mov	DWORD PTR 8[rax], 0
	mov	rax, QWORD PTR -40[rbp]
	mov	DWORD PTR 12[rax], 13
	mov	rax, QWORD PTR -40[rbp]
	mov	DWORD PTR 16[rax], 0
	jmp	.L10
.L11:
	mov	rcx, QWORD PTR 16[rbp]
	mov	rax, QWORD PTR 88[rbp]
	lea	rdx, 1[rax]
	mov	rax, rdx
	add	rax, rax
	add	rax, rdx
	sal	rax, 3
	lea	rsi, [rcx+rax]
	mov	rcx, QWORD PTR -40[rbp]
	mov	rax, QWORD PTR [rsi]
	mov	rdx, QWORD PTR 8[rsi]
	mov	QWORD PTR [rcx], rax
	mov	QWORD PTR 8[rcx], rdx
	mov	rax, QWORD PTR 16[rsi]
	mov	QWORD PTR 16[rcx], rax
.L10:
	mov	rax, QWORD PTR -40[rbp]
	pop	rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	peek_token, .-peek_token
	.globl	check_if_valid_instruction
	.type	check_if_valid_instruction, @function
check_if_valid_instruction:
.LFB10:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	DWORD PTR -4[rbp], 0
	jmp	.L14
.L17:
	mov	eax, DWORD PTR 24[rbp]
	movsx	rdx, eax
	mov	eax, DWORD PTR -4[rbp]
	cdqe
	sal	rax, 5
	mov	rcx, rax
	lea	rax, ins_table[rip]
	mov	rcx, QWORD PTR [rcx+rax]
	mov	rax, QWORD PTR 16[rbp]
	mov	rsi, rcx
	mov	rdi, rax
	call	strncasecmp@PLT
	test	eax, eax
	jne	.L15
	mov	eax, DWORD PTR -4[rbp]
	jmp	.L16
.L15:
	add	DWORD PTR -4[rbp], 1
.L14:
	cmp	DWORD PTR -4[rbp], 55
	jle	.L17
	mov	eax, -1
.L16:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE10:
	.size	check_if_valid_instruction, .-check_if_valid_instruction
	.globl	check_if_valid_directive
	.type	check_if_valid_directive, @function
check_if_valid_directive:
.LFB11:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	DWORD PTR -4[rbp], 0
	jmp	.L19
.L22:
	mov	eax, DWORD PTR 24[rbp]
	movsx	rdx, eax
	mov	eax, DWORD PTR -4[rbp]
	cdqe
	sal	rax, 4
	mov	rcx, rax
	lea	rax, dir_table[rip]
	mov	rcx, QWORD PTR [rcx+rax]
	mov	rax, QWORD PTR 16[rbp]
	mov	rsi, rcx
	mov	rdi, rax
	call	strncasecmp@PLT
	test	eax, eax
	jne	.L20
	mov	eax, DWORD PTR -4[rbp]
	jmp	.L21
.L20:
	add	DWORD PTR -4[rbp], 1
.L19:
	cmp	DWORD PTR -4[rbp], 3
	jle	.L22
	mov	eax, -1
.L21:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE11:
	.size	check_if_valid_directive, .-check_if_valid_directive
	.section	.rodata
.LC60:
	.string	"parse_tokens.c"
.LC61:
	.string	"Unimplemented"
	.align 8
.LC62:
	.string	"PANIC: %s in file:%s:%d in function %s \n"
	.text
	.globl	determine_directive_size
	.type	determine_directive_size, @function
determine_directive_size:
.LFB12:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR -8[rbp], rdi
	mov	DWORD PTR -12[rbp], esi
	mov	rax, QWORD PTR -8[rbp]
	mov	QWORD PTR 72[rax], -1
	mov	rax, QWORD PTR stderr[rip]
	lea	r9, __func__.0[rip]
	mov	r8d, 176
	lea	rdx, .LC60[rip]
	mov	rcx, rdx
	lea	rdx, .LC61[rip]
	lea	rsi, .LC62[rip]
	mov	rdi, rax
	mov	eax, 0
	call	fprintf@PLT
	call	abort@PLT
	.cfi_endproc
.LFE12:
	.size	determine_directive_size, .-determine_directive_size
	.section	.rodata
.LC63:
	.string	"Unsupported Addressing Mode"
.LC64:
	.string	"%s\n"
	.align 8
.LC65:
	.string	"Unexepected Identifer: Expected comma before second Identifer"
	.align 8
.LC66:
	.string	"Invaild Addressing mode: Hash provided within expression for ZeroPage addressing mode"
	.text
	.type	handle_zeropage_addressing, @function
handle_zeropage_addressing:
.LFB13:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	push	rbx
	sub	rsp, 88
	.cfi_offset 3, -24
	mov	QWORD PTR -56[rbp], rdi
	mov	rax, QWORD PTR fs:40
	mov	QWORD PTR -24[rbp], rax
	xor	eax, eax
	jmp	.L25
.L38:
	lea	rax, -48[rbp]
	mov	rdx, QWORD PTR -56[rbp]
	mov	rsi, rdx
	mov	rdi, rax
	call	pull_token
	mov	eax, DWORD PTR -36[rbp]
	cmp	eax, 13
	jne	.L26
	mov	eax, 3
	jmp	.L39
.L26:
	mov	eax, DWORD PTR -36[rbp]
	cmp	eax, 6
	jne	.L28
	lea	rax, -96[rbp]
	mov	rdx, QWORD PTR -56[rbp]
	mov	rsi, rdx
	mov	rdi, rax
	call	pull_token
	mov	rax, QWORD PTR -96[rbp]
	mov	rdx, QWORD PTR -88[rbp]
	mov	QWORD PTR -48[rbp], rax
	mov	QWORD PTR -40[rbp], rdx
	mov	rax, QWORD PTR -80[rbp]
	mov	QWORD PTR -32[rbp], rax
	mov	eax, DWORD PTR -36[rbp]
	cmp	eax, 2
	jne	.L29
	mov	rax, QWORD PTR 16[rbp]
	movzx	eax, BYTE PTR [rax]
	movsx	eax, al
	cmp	eax, 121
	je	.L30
	cmp	eax, 121
	jg	.L31
	cmp	eax, 120
	je	.L32
	cmp	eax, 120
	jg	.L31
	cmp	eax, 88
	je	.L33
	cmp	eax, 89
	jne	.L31
	mov	eax, 5
	jmp	.L39
.L30:
	mov	eax, 5
	jmp	.L39
.L33:
	mov	eax, 4
	jmp	.L39
.L32:
	mov	eax, 4
	jmp	.L39
.L31:
	mov	rax, QWORD PTR stderr[rip]
	lea	rdx, .LC63[rip]
	lea	rcx, .LC64[rip]
	mov	rsi, rcx
	mov	rdi, rax
	mov	eax, 0
	call	fprintf@PLT
	mov	edi, 1
	call	exit@PLT
.L29:
	mov	eax, DWORD PTR -36[rbp]
	cmp	eax, 2
	je	.L34
	cmp	eax, 5
	je	.L35
	jmp	.L28
.L34:
	mov	rax, QWORD PTR stderr[rip]
	lea	rdx, .LC65[rip]
	lea	rcx, .LC64[rip]
	mov	rsi, rcx
	mov	rdi, rax
	mov	eax, 0
	call	fprintf@PLT
	mov	edi, 1
	call	exit@PLT
.L35:
	mov	rax, QWORD PTR stderr[rip]
	lea	rdx, .LC66[rip]
	lea	rcx, .LC64[rip]
	mov	rsi, rcx
	mov	rdi, rax
	mov	eax, 0
	call	fprintf@PLT
	mov	edi, 1
	call	exit@PLT
.L28:
	lea	rsi, -96[rbp]
	sub	rsp, 8
	mov	rax, QWORD PTR -56[rbp]
	sub	rsp, 88
	mov	rdx, rsp
	mov	rcx, QWORD PTR [rax]
	mov	rbx, QWORD PTR 8[rax]
	mov	QWORD PTR [rdx], rcx
	mov	QWORD PTR 8[rdx], rbx
	mov	rcx, QWORD PTR 16[rax]
	mov	rbx, QWORD PTR 24[rax]
	mov	QWORD PTR 16[rdx], rcx
	mov	QWORD PTR 24[rdx], rbx
	mov	rcx, QWORD PTR 32[rax]
	mov	rbx, QWORD PTR 40[rax]
	mov	QWORD PTR 32[rdx], rcx
	mov	QWORD PTR 40[rdx], rbx
	mov	rcx, QWORD PTR 48[rax]
	mov	rbx, QWORD PTR 56[rax]
	mov	QWORD PTR 48[rdx], rcx
	mov	QWORD PTR 56[rdx], rbx
	mov	rcx, QWORD PTR 64[rax]
	mov	rbx, QWORD PTR 72[rax]
	mov	QWORD PTR 64[rdx], rcx
	mov	QWORD PTR 72[rdx], rbx
	mov	rax, QWORD PTR 80[rax]
	mov	QWORD PTR 80[rdx], rax
	mov	rdi, rsi
	call	peek_token
	add	rsp, 96
	mov	rax, QWORD PTR -96[rbp]
	mov	rdx, QWORD PTR -88[rbp]
	mov	QWORD PTR -48[rbp], rax
	mov	QWORD PTR -40[rbp], rdx
	mov	rax, QWORD PTR -80[rbp]
	mov	QWORD PTR -32[rbp], rax
.L25:
	mov	eax, DWORD PTR -36[rbp]
	test	eax, eax
	je	.L37
	mov	eax, DWORD PTR -36[rbp]
	cmp	eax, 1
	jne	.L38
.L37:
	mov	eax, 3
.L39:
	mov	rdx, QWORD PTR -24[rbp]
	sub	rdx, QWORD PTR fs:40
	je	.L40
	call	__stack_chk_fail@PLT
.L40:
	mov	rbx, QWORD PTR -8[rbp]
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE13:
	.size	handle_zeropage_addressing, .-handle_zeropage_addressing
	.section	.rodata
	.align 8
.LC67:
	.string	"Invaild Addressing mode: Hash provided within expression for Absolute addressing mode"
	.text
	.type	handle_absoulute_addressing, @function
handle_absoulute_addressing:
.LFB14:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	push	rbx
	sub	rsp, 88
	.cfi_offset 3, -24
	mov	QWORD PTR -56[rbp], rdi
	mov	rax, QWORD PTR fs:40
	mov	QWORD PTR -24[rbp], rax
	xor	eax, eax
	pxor	xmm0, xmm0
	movaps	XMMWORD PTR -48[rbp], xmm0
	movq	QWORD PTR -32[rbp], xmm0
	jmp	.L42
.L55:
	lea	rax, -48[rbp]
	mov	rdx, QWORD PTR -56[rbp]
	mov	rsi, rdx
	mov	rdi, rax
	call	pull_token
	mov	eax, DWORD PTR -36[rbp]
	cmp	eax, 13
	jne	.L43
	mov	eax, 7
	jmp	.L56
.L43:
	mov	eax, DWORD PTR -36[rbp]
	cmp	eax, 6
	jne	.L45
	lea	rax, -96[rbp]
	mov	rdx, QWORD PTR -56[rbp]
	mov	rsi, rdx
	mov	rdi, rax
	call	pull_token
	mov	rax, QWORD PTR -96[rbp]
	mov	rdx, QWORD PTR -88[rbp]
	mov	QWORD PTR -48[rbp], rax
	mov	QWORD PTR -40[rbp], rdx
	mov	rax, QWORD PTR -80[rbp]
	mov	QWORD PTR -32[rbp], rax
	mov	eax, DWORD PTR -36[rbp]
	cmp	eax, 2
	jne	.L46
	mov	rax, QWORD PTR 16[rbp]
	movzx	eax, BYTE PTR [rax]
	movsx	eax, al
	cmp	eax, 121
	je	.L47
	cmp	eax, 121
	jg	.L48
	cmp	eax, 120
	je	.L49
	cmp	eax, 120
	jg	.L48
	cmp	eax, 88
	je	.L50
	cmp	eax, 89
	jne	.L48
	mov	eax, 9
	jmp	.L56
.L47:
	mov	eax, 9
	jmp	.L56
.L50:
	mov	eax, 8
	jmp	.L56
.L49:
	mov	eax, 8
	jmp	.L56
.L48:
	mov	rax, QWORD PTR stderr[rip]
	lea	rdx, .LC63[rip]
	lea	rcx, .LC64[rip]
	mov	rsi, rcx
	mov	rdi, rax
	mov	eax, 0
	call	fprintf@PLT
	mov	edi, 1
	call	exit@PLT
.L46:
	mov	eax, DWORD PTR -36[rbp]
	cmp	eax, 2
	je	.L51
	cmp	eax, 5
	je	.L52
	jmp	.L45
.L51:
	mov	rax, QWORD PTR stderr[rip]
	lea	rdx, .LC65[rip]
	lea	rcx, .LC64[rip]
	mov	rsi, rcx
	mov	rdi, rax
	mov	eax, 0
	call	fprintf@PLT
	mov	edi, 1
	call	exit@PLT
.L52:
	mov	rax, QWORD PTR stderr[rip]
	lea	rdx, .LC67[rip]
	lea	rcx, .LC64[rip]
	mov	rsi, rcx
	mov	rdi, rax
	mov	eax, 0
	call	fprintf@PLT
	mov	edi, 1
	call	exit@PLT
.L45:
	lea	rsi, -96[rbp]
	sub	rsp, 8
	mov	rax, QWORD PTR -56[rbp]
	sub	rsp, 88
	mov	rdx, rsp
	mov	rcx, QWORD PTR [rax]
	mov	rbx, QWORD PTR 8[rax]
	mov	QWORD PTR [rdx], rcx
	mov	QWORD PTR 8[rdx], rbx
	mov	rcx, QWORD PTR 16[rax]
	mov	rbx, QWORD PTR 24[rax]
	mov	QWORD PTR 16[rdx], rcx
	mov	QWORD PTR 24[rdx], rbx
	mov	rcx, QWORD PTR 32[rax]
	mov	rbx, QWORD PTR 40[rax]
	mov	QWORD PTR 32[rdx], rcx
	mov	QWORD PTR 40[rdx], rbx
	mov	rcx, QWORD PTR 48[rax]
	mov	rbx, QWORD PTR 56[rax]
	mov	QWORD PTR 48[rdx], rcx
	mov	QWORD PTR 56[rdx], rbx
	mov	rcx, QWORD PTR 64[rax]
	mov	rbx, QWORD PTR 72[rax]
	mov	QWORD PTR 64[rdx], rcx
	mov	QWORD PTR 72[rdx], rbx
	mov	rax, QWORD PTR 80[rax]
	mov	QWORD PTR 80[rdx], rax
	mov	rdi, rsi
	call	peek_token
	add	rsp, 96
	mov	rax, QWORD PTR -96[rbp]
	mov	rdx, QWORD PTR -88[rbp]
	mov	QWORD PTR -48[rbp], rax
	mov	QWORD PTR -40[rbp], rdx
	mov	rax, QWORD PTR -80[rbp]
	mov	QWORD PTR -32[rbp], rax
.L42:
	mov	eax, DWORD PTR -36[rbp]
	test	eax, eax
	je	.L54
	mov	eax, DWORD PTR -36[rbp]
	cmp	eax, 1
	jne	.L55
.L54:
	mov	eax, 7
.L56:
	mov	rdx, QWORD PTR -24[rbp]
	sub	rdx, QWORD PTR fs:40
	je	.L57
	call	__stack_chk_fail@PLT
.L57:
	mov	rbx, QWORD PTR -8[rbp]
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE14:
	.size	handle_absoulute_addressing, .-handle_absoulute_addressing
	.section	.rodata
	.align 8
.LC68:
	.string	"Unexpeted mnemonic, expected closed paren"
	.align 8
.LC69:
	.string	"Invaild Addressing Mode: Expected Identifer 'X'"
	.align 8
.LC70:
	.string	"Invaild Addressing mode: Expected ')' after identifer 'X'"
	.align 8
.LC71:
	.string	"Expected new mnemonic after end of expression"
	.align 8
.LC72:
	.string	"Invaild Addressing mode: Expected ')' after identifer 'x'"
	.align 8
.LC73:
	.string	"Expected Mnemonic, Label or EOF after 'y'"
.LC74:
	.string	"Invaild Addressing mode"
	.align 8
.LC75:
	.string	"Expected Identifer after comma"
	.text
	.type	handle_indirect_addrmode, @function
handle_indirect_addrmode:
.LFB15:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	push	rbx
	sub	rsp, 88
	.cfi_offset 3, -24
	mov	QWORD PTR -56[rbp], rdi
	mov	rax, QWORD PTR fs:40
	mov	QWORD PTR -24[rbp], rax
	xor	eax, eax
	lea	rax, -48[rbp]
	mov	rdx, QWORD PTR -56[rbp]
	mov	rsi, rdx
	mov	rdi, rax
	call	pull_token
.L76:
	mov	eax, DWORD PTR -36[rbp]
	cmp	eax, 12
	je	.L86
	cmp	eax, 12
	ja	.L87
	cmp	eax, 6
	je	.L61
	cmp	eax, 6
	ja	.L87
	test	eax, eax
	je	.L62
	cmp	eax, 1
	je	.L63
	jmp	.L87
.L62:
	mov	rax, QWORD PTR stderr[rip]
	lea	rdx, .LC68[rip]
	lea	rcx, .LC64[rip]
	mov	rsi, rcx
	mov	rdi, rax
	mov	eax, 0
	call	fprintf@PLT
	mov	edi, 1
	call	exit@PLT
.L63:
	mov	rax, QWORD PTR stderr[rip]
	lea	rdx, .LC68[rip]
	lea	rcx, .LC64[rip]
	mov	rsi, rcx
	mov	rdi, rax
	mov	eax, 0
	call	fprintf@PLT
	mov	edi, 1
	call	exit@PLT
.L61:
	lea	rax, -96[rbp]
	mov	rdx, QWORD PTR -56[rbp]
	mov	rsi, rdx
	mov	rdi, rax
	call	pull_token
	mov	rax, QWORD PTR -96[rbp]
	mov	rdx, QWORD PTR -88[rbp]
	mov	QWORD PTR -48[rbp], rax
	mov	QWORD PTR -40[rbp], rdx
	mov	rax, QWORD PTR -80[rbp]
	mov	QWORD PTR -32[rbp], rax
	mov	eax, DWORD PTR -36[rbp]
	cmp	eax, 2
	je	.L64
	mov	rax, QWORD PTR stderr[rip]
	lea	rdx, .LC69[rip]
	lea	rcx, .LC64[rip]
	mov	rsi, rcx
	mov	rdi, rax
	mov	eax, 0
	call	fprintf@PLT
	mov	edi, 1
	call	exit@PLT
.L64:
	mov	rax, QWORD PTR -48[rbp]
	movzx	eax, BYTE PTR [rax]
	movsx	eax, al
	cmp	eax, 88
	je	.L65
	cmp	eax, 120
	je	.L66
	jmp	.L74
.L65:
	lea	rax, -96[rbp]
	mov	rdx, QWORD PTR -56[rbp]
	mov	rsi, rdx
	mov	rdi, rax
	call	pull_token
	mov	rax, QWORD PTR -96[rbp]
	mov	rdx, QWORD PTR -88[rbp]
	mov	QWORD PTR -48[rbp], rax
	mov	QWORD PTR -40[rbp], rdx
	mov	rax, QWORD PTR -80[rbp]
	mov	QWORD PTR -32[rbp], rax
	mov	eax, DWORD PTR -36[rbp]
	cmp	eax, 12
	je	.L68
	mov	rax, QWORD PTR stderr[rip]
	lea	rdx, .LC70[rip]
	lea	rcx, .LC64[rip]
	mov	rsi, rcx
	mov	rdi, rax
	mov	eax, 0
	call	fprintf@PLT
	mov	edi, 1
	call	exit@PLT
.L68:
	lea	rsi, -96[rbp]
	sub	rsp, 8
	mov	rax, QWORD PTR -56[rbp]
	sub	rsp, 88
	mov	rdx, rsp
	mov	rcx, QWORD PTR [rax]
	mov	rbx, QWORD PTR 8[rax]
	mov	QWORD PTR [rdx], rcx
	mov	QWORD PTR 8[rdx], rbx
	mov	rcx, QWORD PTR 16[rax]
	mov	rbx, QWORD PTR 24[rax]
	mov	QWORD PTR 16[rdx], rcx
	mov	QWORD PTR 24[rdx], rbx
	mov	rcx, QWORD PTR 32[rax]
	mov	rbx, QWORD PTR 40[rax]
	mov	QWORD PTR 32[rdx], rcx
	mov	QWORD PTR 40[rdx], rbx
	mov	rcx, QWORD PTR 48[rax]
	mov	rbx, QWORD PTR 56[rax]
	mov	QWORD PTR 48[rdx], rcx
	mov	QWORD PTR 56[rdx], rbx
	mov	rcx, QWORD PTR 64[rax]
	mov	rbx, QWORD PTR 72[rax]
	mov	QWORD PTR 64[rdx], rcx
	mov	QWORD PTR 72[rdx], rbx
	mov	rax, QWORD PTR 80[rax]
	mov	QWORD PTR 80[rdx], rax
	mov	rdi, rsi
	call	peek_token
	add	rsp, 96
	mov	rax, QWORD PTR -96[rbp]
	mov	rdx, QWORD PTR -88[rbp]
	mov	QWORD PTR -48[rbp], rax
	mov	QWORD PTR -40[rbp], rdx
	mov	rax, QWORD PTR -80[rbp]
	mov	QWORD PTR -32[rbp], rax
	mov	eax, DWORD PTR -36[rbp]
	cmp	eax, 1
	je	.L69
	mov	eax, DWORD PTR -36[rbp]
	test	eax, eax
	je	.L69
	mov	eax, DWORD PTR -36[rbp]
	cmp	eax, 13
	je	.L69
	mov	rax, QWORD PTR stderr[rip]
	lea	rdx, .LC71[rip]
	lea	rcx, .LC64[rip]
	mov	rsi, rcx
	mov	rdi, rax
	mov	eax, 0
	call	fprintf@PLT
	mov	edi, 1
	call	exit@PLT
.L69:
	mov	eax, 11
	jmp	.L58
.L66:
	mov	eax, DWORD PTR -36[rbp]
	cmp	eax, 12
	je	.L71
	mov	rax, QWORD PTR stderr[rip]
	lea	rdx, .LC72[rip]
	lea	rcx, .LC64[rip]
	mov	rsi, rcx
	mov	rdi, rax
	mov	eax, 0
	call	fprintf@PLT
	mov	edi, 1
	call	exit@PLT
.L71:
	lea	rsi, -96[rbp]
	sub	rsp, 8
	mov	rax, QWORD PTR -56[rbp]
	sub	rsp, 88
	mov	rdx, rsp
	mov	rcx, QWORD PTR [rax]
	mov	rbx, QWORD PTR 8[rax]
	mov	QWORD PTR [rdx], rcx
	mov	QWORD PTR 8[rdx], rbx
	mov	rcx, QWORD PTR 16[rax]
	mov	rbx, QWORD PTR 24[rax]
	mov	QWORD PTR 16[rdx], rcx
	mov	QWORD PTR 24[rdx], rbx
	mov	rcx, QWORD PTR 32[rax]
	mov	rbx, QWORD PTR 40[rax]
	mov	QWORD PTR 32[rdx], rcx
	mov	QWORD PTR 40[rdx], rbx
	mov	rcx, QWORD PTR 48[rax]
	mov	rbx, QWORD PTR 56[rax]
	mov	QWORD PTR 48[rdx], rcx
	mov	QWORD PTR 56[rdx], rbx
	mov	rcx, QWORD PTR 64[rax]
	mov	rbx, QWORD PTR 72[rax]
	mov	QWORD PTR 64[rdx], rcx
	mov	QWORD PTR 72[rdx], rbx
	mov	rax, QWORD PTR 80[rax]
	mov	QWORD PTR 80[rdx], rax
	mov	rdi, rsi
	call	peek_token
	add	rsp, 96
	mov	rax, QWORD PTR -96[rbp]
	mov	rdx, QWORD PTR -88[rbp]
	mov	QWORD PTR -48[rbp], rax
	mov	QWORD PTR -40[rbp], rdx
	mov	rax, QWORD PTR -80[rbp]
	mov	QWORD PTR -32[rbp], rax
	mov	eax, DWORD PTR -36[rbp]
	cmp	eax, 1
	jne	.L72
	mov	eax, DWORD PTR -36[rbp]
	test	eax, eax
	jne	.L72
	mov	eax, DWORD PTR -36[rbp]
	cmp	eax, 13
	je	.L73
.L72:
	mov	rax, QWORD PTR stderr[rip]
	lea	rdx, .LC71[rip]
	lea	rcx, .LC64[rip]
	mov	rsi, rcx
	mov	rdi, rax
	mov	eax, 0
	call	fprintf@PLT
	mov	edi, 1
	call	exit@PLT
.L73:
	mov	eax, 11
	jmp	.L58
.L87:
	nop
.L74:
	lea	rax, -96[rbp]
	mov	rdx, QWORD PTR -56[rbp]
	mov	rsi, rdx
	mov	rdi, rax
	call	pull_token
	mov	rax, QWORD PTR -96[rbp]
	mov	rdx, QWORD PTR -88[rbp]
	mov	QWORD PTR -48[rbp], rax
	mov	QWORD PTR -40[rbp], rdx
	mov	rax, QWORD PTR -80[rbp]
	mov	QWORD PTR -32[rbp], rax
	jmp	.L76
.L86:
	nop
.L75:
	lea	rsi, -96[rbp]
	sub	rsp, 8
	mov	rax, QWORD PTR -56[rbp]
	sub	rsp, 88
	mov	rdx, rsp
	mov	rcx, QWORD PTR [rax]
	mov	rbx, QWORD PTR 8[rax]
	mov	QWORD PTR [rdx], rcx
	mov	QWORD PTR 8[rdx], rbx
	mov	rcx, QWORD PTR 16[rax]
	mov	rbx, QWORD PTR 24[rax]
	mov	QWORD PTR 16[rdx], rcx
	mov	QWORD PTR 24[rdx], rbx
	mov	rcx, QWORD PTR 32[rax]
	mov	rbx, QWORD PTR 40[rax]
	mov	QWORD PTR 32[rdx], rcx
	mov	QWORD PTR 40[rdx], rbx
	mov	rcx, QWORD PTR 48[rax]
	mov	rbx, QWORD PTR 56[rax]
	mov	QWORD PTR 48[rdx], rcx
	mov	QWORD PTR 56[rdx], rbx
	mov	rcx, QWORD PTR 64[rax]
	mov	rbx, QWORD PTR 72[rax]
	mov	QWORD PTR 64[rdx], rcx
	mov	QWORD PTR 72[rdx], rbx
	mov	rax, QWORD PTR 80[rax]
	mov	QWORD PTR 80[rdx], rax
	mov	rdi, rsi
	call	peek_token
	add	rsp, 96
	mov	rax, QWORD PTR -96[rbp]
	mov	rdx, QWORD PTR -88[rbp]
	mov	QWORD PTR -48[rbp], rax
	mov	QWORD PTR -40[rbp], rdx
	mov	rax, QWORD PTR -80[rbp]
	mov	QWORD PTR -32[rbp], rax
	mov	eax, DWORD PTR -36[rbp]
	test	eax, eax
	je	.L77
	mov	eax, DWORD PTR -36[rbp]
	cmp	eax, 1
	jne	.L78
.L77:
	mov	eax, 10
	jmp	.L58
.L78:
	mov	eax, DWORD PTR 28[rbp]
	cmp	eax, 6
	jne	.L79
	mov	eax, DWORD PTR 28[rbp]
	cmp	eax, 2
	jne	.L80
	mov	eax, DWORD PTR -40[rbp]
	cmp	eax, 1
	jne	.L80
	mov	rax, QWORD PTR 16[rbp]
	movzx	eax, BYTE PTR [rax]
	movsx	eax, al
	cmp	eax, 89
	je	.L81
	cmp	eax, 121
	jne	.L82
.L81:
	lea	rsi, -96[rbp]
	sub	rsp, 8
	mov	rax, QWORD PTR -56[rbp]
	sub	rsp, 88
	mov	rdx, rsp
	mov	rcx, QWORD PTR [rax]
	mov	rbx, QWORD PTR 8[rax]
	mov	QWORD PTR [rdx], rcx
	mov	QWORD PTR 8[rdx], rbx
	mov	rcx, QWORD PTR 16[rax]
	mov	rbx, QWORD PTR 24[rax]
	mov	QWORD PTR 16[rdx], rcx
	mov	QWORD PTR 24[rdx], rbx
	mov	rcx, QWORD PTR 32[rax]
	mov	rbx, QWORD PTR 40[rax]
	mov	QWORD PTR 32[rdx], rcx
	mov	QWORD PTR 40[rdx], rbx
	mov	rcx, QWORD PTR 48[rax]
	mov	rbx, QWORD PTR 56[rax]
	mov	QWORD PTR 48[rdx], rcx
	mov	QWORD PTR 56[rdx], rbx
	mov	rcx, QWORD PTR 64[rax]
	mov	rbx, QWORD PTR 72[rax]
	mov	QWORD PTR 64[rdx], rcx
	mov	QWORD PTR 72[rdx], rbx
	mov	rax, QWORD PTR 80[rax]
	mov	QWORD PTR 80[rdx], rax
	mov	rdi, rsi
	call	peek_token
	add	rsp, 96
	mov	rax, QWORD PTR -96[rbp]
	mov	rdx, QWORD PTR -88[rbp]
	mov	QWORD PTR -48[rbp], rax
	mov	QWORD PTR -40[rbp], rdx
	mov	rax, QWORD PTR -80[rbp]
	mov	QWORD PTR -32[rbp], rax
	mov	eax, DWORD PTR -36[rbp]
	cmp	eax, 1
	je	.L83
	mov	eax, DWORD PTR -36[rbp]
	test	eax, eax
	je	.L83
	mov	eax, DWORD PTR -36[rbp]
	cmp	eax, 13
	je	.L83
	mov	rax, QWORD PTR stderr[rip]
	lea	rdx, .LC73[rip]
	lea	rcx, .LC64[rip]
	mov	rsi, rcx
	mov	rdi, rax
	mov	eax, 0
	call	fprintf@PLT
	mov	edi, 1
	call	exit@PLT
.L83:
	mov	eax, 12
	jmp	.L58
.L82:
	mov	rax, QWORD PTR stderr[rip]
	lea	rdx, .LC74[rip]
	lea	rcx, .LC64[rip]
	mov	rsi, rcx
	mov	rdi, rax
	mov	eax, 0
	call	fprintf@PLT
	mov	edi, 1
	call	exit@PLT
.L80:
	mov	rax, QWORD PTR stderr[rip]
	lea	rdx, .LC75[rip]
	lea	rcx, .LC64[rip]
	mov	rsi, rcx
	mov	rdi, rax
	mov	eax, 0
	call	fprintf@PLT
	mov	edi, 1
	call	exit@PLT
.L79:
.L58:
	mov	rdx, QWORD PTR -24[rbp]
	sub	rdx, QWORD PTR fs:40
	je	.L85
	call	__stack_chk_fail@PLT
.L85:
	mov	rbx, QWORD PTR -8[rbp]
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE15:
	.size	handle_indirect_addrmode, .-handle_indirect_addrmode
	.section	.rodata
.LC76:
	.string	"invaild addressing mode"
	.align 8
.LC77:
	.string	"Invaild Token after Acummlator Addressed instruction"
.LC78:
	.string	"Unexpected Token"
	.text
	.globl	determine_addressing
	.type	determine_addressing, @function
determine_addressing:
.LFB16:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	push	rbx
	sub	rsp, 88
	.cfi_offset 3, -24
	mov	QWORD PTR -56[rbp], rdi
	mov	DWORD PTR -60[rbp], esi
	mov	rax, QWORD PTR fs:40
	mov	QWORD PTR -24[rbp], rax
	xor	eax, eax
	cmp	DWORD PTR -60[rbp], 2
	jle	.L89
	cmp	DWORD PTR -60[rbp], 10
	jg	.L89
	lea	rax, -48[rbp]
	mov	rdx, QWORD PTR -56[rbp]
	mov	rsi, rdx
	mov	rdi, rax
	call	pull_token
	jmp	.L90
.L92:
	lea	rax, -96[rbp]
	mov	rdx, QWORD PTR -56[rbp]
	mov	rsi, rdx
	mov	rdi, rax
	call	pull_token
	mov	rax, QWORD PTR -96[rbp]
	mov	rdx, QWORD PTR -88[rbp]
	mov	QWORD PTR -48[rbp], rax
	mov	QWORD PTR -40[rbp], rdx
	mov	rax, QWORD PTR -80[rbp]
	mov	QWORD PTR -32[rbp], rax
.L90:
	mov	eax, DWORD PTR -36[rbp]
	test	eax, eax
	je	.L91
	mov	eax, DWORD PTR -36[rbp]
	cmp	eax, 13
	je	.L91
	mov	eax, DWORD PTR -36[rbp]
	cmp	eax, 1
	jne	.L92
.L91:
	mov	eax, 6
	jmp	.L93
.L89:
	mov	eax, DWORD PTR 28[rbp]
	cmp	eax, 11
	ja	.L94
	mov	eax, eax
	lea	rdx, 0[0+rax*4]
	lea	rax, .L96[rip]
	mov	eax, DWORD PTR [rdx+rax]
	cdqe
	lea	rdx, .L96[rip]
	add	rax, rdx
	jmp	rax
	.section	.rodata
	.align 4
	.align 4
.L96:
	.long	.L94-.L96
	.long	.L94-.L96
	.long	.L100-.L96
	.long	.L99-.L96
	.long	.L98-.L96
	.long	.L97-.L96
	.long	.L94-.L96
	.long	.L94-.L96
	.long	.L94-.L96
	.long	.L94-.L96
	.long	.L94-.L96
	.long	.L95-.L96
	.text
.L98:
	mov	eax, DWORD PTR 24[rbp]
	cmp	eax, 2
	jne	.L101
	mov	rsi, QWORD PTR -56[rbp]
	sub	rsp, 8
	sub	rsp, 24
	mov	rcx, rsp
	mov	rax, QWORD PTR 16[rbp]
	mov	rdx, QWORD PTR 24[rbp]
	mov	QWORD PTR [rcx], rax
	mov	QWORD PTR 8[rcx], rdx
	mov	rax, QWORD PTR 32[rbp]
	mov	QWORD PTR 16[rcx], rax
	mov	rdi, rsi
	call	handle_zeropage_addressing
	add	rsp, 32
	jmp	.L93
.L101:
	mov	rsi, QWORD PTR -56[rbp]
	sub	rsp, 8
	sub	rsp, 24
	mov	rcx, rsp
	mov	rax, QWORD PTR 16[rbp]
	mov	rdx, QWORD PTR 24[rbp]
	mov	QWORD PTR [rcx], rax
	mov	QWORD PTR 8[rcx], rdx
	mov	rax, QWORD PTR 32[rbp]
	mov	QWORD PTR 16[rcx], rax
	mov	rdi, rsi
	call	handle_absoulute_addressing
	add	rsp, 32
	jmp	.L93
.L99:
	mov	eax, DWORD PTR 32[rbp]
	cmp	eax, 255
	jg	.L102
	mov	rsi, QWORD PTR -56[rbp]
	sub	rsp, 8
	sub	rsp, 24
	mov	rcx, rsp
	mov	rax, QWORD PTR 16[rbp]
	mov	rdx, QWORD PTR 24[rbp]
	mov	QWORD PTR [rcx], rax
	mov	QWORD PTR 8[rcx], rdx
	mov	rax, QWORD PTR 32[rbp]
	mov	QWORD PTR 16[rcx], rax
	mov	rdi, rsi
	call	handle_zeropage_addressing
	add	rsp, 32
	jmp	.L93
.L102:
	mov	rsi, QWORD PTR -56[rbp]
	sub	rsp, 8
	sub	rsp, 24
	mov	rcx, rsp
	mov	rax, QWORD PTR 16[rbp]
	mov	rdx, QWORD PTR 24[rbp]
	mov	QWORD PTR [rcx], rax
	mov	QWORD PTR 8[rcx], rdx
	mov	rax, QWORD PTR 32[rbp]
	mov	QWORD PTR 16[rcx], rax
	mov	rdi, rsi
	call	handle_absoulute_addressing
	add	rsp, 32
	jmp	.L93
.L97:
	mov	QWORD PTR -48[rbp], 0
	mov	DWORD PTR -40[rbp], 0
	mov	DWORD PTR -36[rbp], 6
	mov	DWORD PTR -32[rbp], 0
	jmp	.L103
.L106:
	lea	rax, -48[rbp]
	mov	rdx, QWORD PTR -56[rbp]
	mov	rsi, rdx
	mov	rdi, rax
	call	pull_token
	mov	eax, DWORD PTR -36[rbp]
	cmp	eax, 6
	jne	.L114
	mov	rax, QWORD PTR stderr[rip]
	lea	rdx, .LC76[rip]
	lea	rcx, .LC64[rip]
	mov	rsi, rcx
	mov	rdi, rax
	mov	eax, 0
	call	fprintf@PLT
	mov	edi, 1
	call	exit@PLT
.L114:
	nop
	lea	rsi, -96[rbp]
	sub	rsp, 8
	mov	rax, QWORD PTR -56[rbp]
	sub	rsp, 88
	mov	rdx, rsp
	mov	rcx, QWORD PTR [rax]
	mov	rbx, QWORD PTR 8[rax]
	mov	QWORD PTR [rdx], rcx
	mov	QWORD PTR 8[rdx], rbx
	mov	rcx, QWORD PTR 16[rax]
	mov	rbx, QWORD PTR 24[rax]
	mov	QWORD PTR 16[rdx], rcx
	mov	QWORD PTR 24[rdx], rbx
	mov	rcx, QWORD PTR 32[rax]
	mov	rbx, QWORD PTR 40[rax]
	mov	QWORD PTR 32[rdx], rcx
	mov	QWORD PTR 40[rdx], rbx
	mov	rcx, QWORD PTR 48[rax]
	mov	rbx, QWORD PTR 56[rax]
	mov	QWORD PTR 48[rdx], rcx
	mov	QWORD PTR 56[rdx], rbx
	mov	rcx, QWORD PTR 64[rax]
	mov	rbx, QWORD PTR 72[rax]
	mov	QWORD PTR 64[rdx], rcx
	mov	QWORD PTR 72[rdx], rbx
	mov	rax, QWORD PTR 80[rax]
	mov	QWORD PTR 80[rdx], rax
	mov	rdi, rsi
	call	peek_token
	add	rsp, 96
	mov	rax, QWORD PTR -96[rbp]
	mov	rdx, QWORD PTR -88[rbp]
	mov	QWORD PTR -48[rbp], rax
	mov	QWORD PTR -40[rbp], rdx
	mov	rax, QWORD PTR -80[rbp]
	mov	QWORD PTR -32[rbp], rax
.L103:
	mov	eax, DWORD PTR -36[rbp]
	test	eax, eax
	je	.L105
	mov	eax, DWORD PTR -36[rbp]
	cmp	eax, 13
	je	.L105
	mov	eax, DWORD PTR -36[rbp]
	cmp	eax, 1
	jne	.L106
.L105:
	mov	eax, 2
	jmp	.L93
.L100:
	mov	rax, QWORD PTR 16[rbp]
	movzx	eax, BYTE PTR [rax]
	cmp	al, 65
	jne	.L107
	mov	eax, DWORD PTR 24[rbp]
	cmp	eax, 1
	je	.L108
.L107:
	mov	rax, QWORD PTR 16[rbp]
	movzx	eax, BYTE PTR [rax]
	cmp	al, 97
	jne	.L109
	mov	eax, DWORD PTR 24[rbp]
	cmp	eax, 1
	jne	.L109
.L108:
	lea	rsi, -48[rbp]
	sub	rsp, 8
	mov	rax, QWORD PTR -56[rbp]
	sub	rsp, 88
	mov	rdx, rsp
	mov	rcx, QWORD PTR [rax]
	mov	rbx, QWORD PTR 8[rax]
	mov	QWORD PTR [rdx], rcx
	mov	QWORD PTR 8[rdx], rbx
	mov	rcx, QWORD PTR 16[rax]
	mov	rbx, QWORD PTR 24[rax]
	mov	QWORD PTR 16[rdx], rcx
	mov	QWORD PTR 24[rdx], rbx
	mov	rcx, QWORD PTR 32[rax]
	mov	rbx, QWORD PTR 40[rax]
	mov	QWORD PTR 32[rdx], rcx
	mov	QWORD PTR 40[rdx], rbx
	mov	rcx, QWORD PTR 48[rax]
	mov	rbx, QWORD PTR 56[rax]
	mov	QWORD PTR 48[rdx], rcx
	mov	QWORD PTR 56[rdx], rbx
	mov	rcx, QWORD PTR 64[rax]
	mov	rbx, QWORD PTR 72[rax]
	mov	QWORD PTR 64[rdx], rcx
	mov	QWORD PTR 72[rdx], rbx
	mov	rax, QWORD PTR 80[rax]
	mov	QWORD PTR 80[rdx], rax
	mov	rdi, rsi
	call	peek_token
	add	rsp, 96
	mov	eax, DWORD PTR -36[rbp]
	cmp	eax, 13
	jne	.L110
	mov	eax, DWORD PTR -36[rbp]
	test	eax, eax
	jne	.L110
	mov	eax, DWORD PTR -36[rbp]
	cmp	eax, 1
	je	.L111
.L110:
	mov	rax, QWORD PTR stderr[rip]
	lea	rdx, .LC77[rip]
	lea	rcx, .LC64[rip]
	mov	rsi, rcx
	mov	rdi, rax
	mov	eax, 0
	call	fprintf@PLT
	mov	edi, 1
	call	exit@PLT
.L111:
	mov	eax, 1
	jmp	.L93
.L109:
	mov	rsi, QWORD PTR -56[rbp]
	sub	rsp, 8
	sub	rsp, 24
	mov	rcx, rsp
	mov	rax, QWORD PTR 16[rbp]
	mov	rdx, QWORD PTR 24[rbp]
	mov	QWORD PTR [rcx], rax
	mov	QWORD PTR 8[rcx], rdx
	mov	rax, QWORD PTR 32[rbp]
	mov	QWORD PTR 16[rcx], rax
	mov	rdi, rsi
	call	handle_absoulute_addressing
	add	rsp, 32
	jmp	.L93
.L95:
	mov	rsi, QWORD PTR -56[rbp]
	sub	rsp, 8
	sub	rsp, 24
	mov	rcx, rsp
	mov	rax, QWORD PTR 16[rbp]
	mov	rdx, QWORD PTR 24[rbp]
	mov	QWORD PTR [rcx], rax
	mov	QWORD PTR 8[rcx], rdx
	mov	rax, QWORD PTR 32[rbp]
	mov	QWORD PTR 16[rcx], rax
	mov	rdi, rsi
	call	handle_indirect_addrmode
	add	rsp, 32
	jmp	.L93
.L94:
	mov	rax, QWORD PTR stderr[rip]
	lea	rdx, .LC78[rip]
	lea	rcx, .LC64[rip]
	mov	rsi, rcx
	mov	rdi, rax
	mov	eax, 0
	call	fprintf@PLT
	mov	edi, 1
	call	exit@PLT
.L93:
	mov	rdx, QWORD PTR -24[rbp]
	sub	rdx, QWORD PTR fs:40
	je	.L112
	call	__stack_chk_fail@PLT
.L112:
	mov	rbx, QWORD PTR -8[rbp]
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE16:
	.size	determine_addressing, .-determine_addressing
	.section	.rodata
.LC79:
	.string	"Invaild mnemonic"
	.text
	.type	build_label_table, @function
build_label_table:
.LFB17:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 96
	mov	QWORD PTR -56[rbp], rdi
	mov	rax, QWORD PTR fs:40
	mov	QWORD PTR -8[rbp], rax
	xor	eax, eax
	mov	rax, QWORD PTR -56[rbp]
	mov	rcx, QWORD PTR [rax]
	mov	rax, QWORD PTR -56[rbp]
	mov	rdx, QWORD PTR 72[rax]
	mov	rax, rdx
	add	rax, rax
	add	rax, rdx
	sal	rax, 3
	add	rcx, rax
	mov	rax, QWORD PTR [rcx]
	mov	rdx, QWORD PTR 8[rcx]
	mov	QWORD PTR -32[rbp], rax
	mov	QWORD PTR -24[rbp], rdx
	mov	rax, QWORD PTR 16[rcx]
	mov	QWORD PTR -16[rbp], rax
.L119:
	sub	rsp, 8
	sub	rsp, 24
	mov	rcx, rsp
	mov	rax, QWORD PTR -32[rbp]
	mov	rdx, QWORD PTR -24[rbp]
	mov	QWORD PTR [rcx], rax
	mov	QWORD PTR 8[rcx], rdx
	mov	rax, QWORD PTR -16[rbp]
	mov	QWORD PTR 16[rcx], rax
	call	check_if_valid_instruction
	add	rsp, 32
	mov	DWORD PTR -36[rbp], eax
	cmp	DWORD PTR -36[rbp], 0
	js	.L116
	lea	rax, -32[rbp]
	mov	rdx, QWORD PTR -56[rbp]
	mov	rsi, rdx
	mov	rdi, rax
	call	pull_token
	mov	esi, DWORD PTR -36[rbp]
	mov	rdi, QWORD PTR -56[rbp]
	sub	rsp, 8
	sub	rsp, 24
	mov	rcx, rsp
	mov	rax, QWORD PTR -32[rbp]
	mov	rdx, QWORD PTR -24[rbp]
	mov	QWORD PTR [rcx], rax
	mov	QWORD PTR 8[rcx], rdx
	mov	rax, QWORD PTR -16[rbp]
	mov	QWORD PTR 16[rcx], rax
	call	determine_addressing
	add	rsp, 32
	jmp	.L117
.L116:
	cmp	DWORD PTR -36[rbp], 0
	js	.L118
	sub	rsp, 8
	sub	rsp, 24
	mov	rcx, rsp
	mov	rax, QWORD PTR -32[rbp]
	mov	rdx, QWORD PTR -24[rbp]
	mov	QWORD PTR [rcx], rax
	mov	QWORD PTR 8[rcx], rdx
	mov	rax, QWORD PTR -16[rbp]
	mov	QWORD PTR 16[rcx], rax
	call	check_if_valid_directive
	add	rsp, 32
	mov	DWORD PTR -36[rbp], eax
	mov	esi, DWORD PTR -36[rbp]
	mov	rdi, QWORD PTR -56[rbp]
	sub	rsp, 8
	sub	rsp, 24
	mov	rcx, rsp
	mov	rax, QWORD PTR -32[rbp]
	mov	rdx, QWORD PTR -24[rbp]
	mov	QWORD PTR [rcx], rax
	mov	QWORD PTR 8[rcx], rdx
	mov	rax, QWORD PTR -16[rbp]
	mov	QWORD PTR 16[rcx], rax
	call	determine_directive_size
	add	rsp, 32
	jmp	.L117
.L118:
	mov	rax, QWORD PTR stderr[rip]
	lea	rdx, .LC79[rip]
	lea	rcx, .LC64[rip]
	mov	rsi, rcx
	mov	rdi, rax
	mov	eax, 0
	call	fprintf@PLT
	mov	edi, 1
	call	exit@PLT
.L117:
	lea	rax, -96[rbp]
	mov	rdx, QWORD PTR -56[rbp]
	mov	rsi, rdx
	mov	rdi, rax
	call	pull_token
	mov	rax, QWORD PTR -96[rbp]
	mov	rdx, QWORD PTR -88[rbp]
	mov	QWORD PTR -32[rbp], rax
	mov	QWORD PTR -24[rbp], rdx
	mov	rax, QWORD PTR -80[rbp]
	mov	QWORD PTR -16[rbp], rax
	jmp	.L119
	.cfi_endproc
.LFE17:
	.size	build_label_table, .-build_label_table
	.globl	parse_tokens
	.type	parse_tokens, @function
parse_tokens:
.LFB18:
	.cfi_startproc
	push	rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp
	.cfi_def_cfa_register 6
	sub	rsp, 16
	mov	QWORD PTR -8[rbp], rdi
	mov	rax, QWORD PTR -8[rbp]
	mov	rdi, rax
	call	build_label_table
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE18:
	.size	parse_tokens, .-parse_tokens
	.section	.rodata
	.align 16
	.type	__func__.0, @object
	.size	__func__.0, 25
__func__.0:
	.string	"determine_directive_size"
	.ident	"GCC: (GNU) 14.2.1 20250405"
	.section	.note.GNU-stack,"",@progbits
