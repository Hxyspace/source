	.file	"main.cpp"
	.text
	.section .rdata,"dr"
_ZStL19piecewise_construct:
	.space 1
.lcomm _ZStL8__ioinit,1,1
	.text
	.align 2
	.globl	_ZN8RationalC2Eii
	.def	_ZN8RationalC2Eii;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN8RationalC2Eii
_ZN8RationalC2Eii:
.LFB1574:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	%r8d, 32(%rbp)
	movq	16(%rbp), %rax
	movl	24(%rbp), %edx
	movl	%edx, (%rax)
	movq	16(%rbp), %rax
	movl	32(%rbp), %edx
	movl	%edx, 4(%rax)
	movq	16(%rbp), %rcx
	call	_ZN8Rational9normalizeEv
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	_ZN8RationalC1Eii
	.def	_ZN8RationalC1Eii;	.scl	2;	.type	32;	.endef
	.set	_ZN8RationalC1Eii,_ZN8RationalC2Eii
	.align 2
	.globl	_ZN8Rational9normalizeEv
	.def	_ZN8Rational9normalizeEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN8Rational9normalizeEv
_ZN8Rational9normalizeEv:
.LFB1576:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movl	4(%rax), %eax
	testl	%eax, %eax
	jns	.L3
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	negl	%eax
	movl	%eax, %edx
	movq	16(%rbp), %rax
	movl	%edx, (%rax)
	movq	16(%rbp), %rax
	movl	4(%rax), %eax
	negl	%eax
	movl	%eax, %edx
	movq	16(%rbp), %rax
	movl	%edx, 4(%rax)
.L3:
	movq	16(%rbp), %rax
	movl	(%rax), %edx
	movl	%edx, %eax
	sarl	$31, %eax
	xorl	%eax, %edx
	movl	%edx, -4(%rbp)
	subl	%eax, -4(%rbp)
	movq	16(%rbp), %rax
	movl	4(%rax), %edx
	movl	%edx, %eax
	sarl	$31, %eax
	xorl	%eax, %edx
	movl	%edx, -8(%rbp)
	subl	%eax, -8(%rbp)
.L5:
	cmpl	$0, -8(%rbp)
	jle	.L4
	movl	-4(%rbp), %eax
	cltd
	idivl	-8(%rbp)
	movl	%edx, -12(%rbp)
	movl	-8(%rbp), %eax
	movl	%eax, -4(%rbp)
	movl	-12(%rbp), %eax
	movl	%eax, -8(%rbp)
	jmp	.L5
.L4:
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	cltd
	idivl	-4(%rbp)
	movl	%eax, %edx
	movq	16(%rbp), %rax
	movl	%edx, (%rax)
	movq	16(%rbp), %rax
	movl	4(%rax), %eax
	cltd
	idivl	-4(%rbp)
	movl	%eax, %edx
	movq	16(%rbp), %rax
	movl	%edx, 4(%rax)
	nop
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN8RationalplES_
	.def	_ZN8RationalplES_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN8RationalplES_
_ZN8RationalplES_:
.LFB1577:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
	movq	16(%rbp), %rax
	movl	4(%rax), %eax
	movl	%eax, -8(%rbp)
	movl	24(%rbp), %eax
	movl	%eax, -12(%rbp)
	movl	28(%rbp), %eax
	movl	%eax, -16(%rbp)
	movl	-4(%rbp), %eax
	imull	-8(%rbp), %eax
	movl	%eax, %edx
	movl	-12(%rbp), %eax
	imull	-16(%rbp), %eax
	addl	%edx, %eax
	movl	%eax, -20(%rbp)
	movl	-8(%rbp), %eax
	imull	-16(%rbp), %eax
	movl	%eax, -24(%rbp)
	movl	-24(%rbp), %ecx
	movl	-20(%rbp), %edx
	leaq	-32(%rbp), %rax
	movl	%ecx, %r8d
	movq	%rax, %rcx
	call	_ZN8RationalC1Eii
	movq	-32(%rbp), %rax
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN8RationalmiES_
	.def	_ZN8RationalmiES_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN8RationalmiES_
_ZN8RationalmiES_:
.LFB1578:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movl	24(%rbp), %eax
	negl	%eax
	movl	%eax, 24(%rbp)
	movq	24(%rbp), %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	_ZN8RationalplES_
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN8RationalmlES_
	.def	_ZN8RationalmlES_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN8RationalmlES_
_ZN8RationalmlES_:
.LFB1579:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
	movq	16(%rbp), %rax
	movl	4(%rax), %eax
	movl	%eax, -8(%rbp)
	movl	24(%rbp), %eax
	movl	%eax, -12(%rbp)
	movl	28(%rbp), %eax
	movl	%eax, -16(%rbp)
	movl	-4(%rbp), %eax
	imull	-12(%rbp), %eax
	movl	%eax, -20(%rbp)
	movl	-8(%rbp), %eax
	imull	-16(%rbp), %eax
	movl	%eax, -24(%rbp)
	movl	-24(%rbp), %ecx
	movl	-20(%rbp), %edx
	leaq	-32(%rbp), %rax
	movl	%ecx, %r8d
	movq	%rax, %rcx
	call	_ZN8RationalC1Eii
	movq	-32(%rbp), %rax
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.align 2
	.globl	_ZN8RationaldvES_
	.def	_ZN8RationaldvES_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN8RationaldvES_
_ZN8RationaldvES_:
.LFB1580:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movl	24(%rbp), %eax
	movl	%eax, -4(%rbp)
	movl	28(%rbp), %eax
	movl	%eax, 24(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, 28(%rbp)
	movq	24(%rbp), %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	_ZN8RationalmlES_
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC0:
	.ascii "/\0"
	.text
	.align 2
	.globl	_ZN8Rational5printEv
	.def	_ZN8Rational5printEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN8Rational5printEv
_ZN8Rational5printEv:
.LFB1581:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	movq	16(%rbp), %rdx
	movl	4(%rdx), %ecx
	cltd
	idivl	%ecx
	movl	%edx, %eax
	testl	%eax, %eax
	jne	.L15
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	movq	16(%rbp), %rdx
	movl	4(%rdx), %ecx
	cltd
	idivl	%ecx
	movl	%eax, %edx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZNSolsEi
	jmp	.L17
.L15:
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %edx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZNSolsEi
	leaq	.LC0(%rip), %rdx
	movq	%rax, %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rcx
	movq	16(%rbp), %rax
	movl	4(%rax), %eax
	movl	%eax, %edx
	call	_ZNSolsEi
.L17:
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC1:
	.ascii " + \0"
.LC2:
	.ascii " = \0"
.LC3:
	.ascii "\12\0"
.LC4:
	.ascii " - \0"
.LC5:
	.ascii " * \0"
.LC6:
	.ascii " / \0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB1582:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$64, %rsp
	.seh_stackalloc	64
	.seh_endprologue
	call	__main
	leaq	-8(%rbp), %rax
	movl	$16, %r8d
	movl	$2, %edx
	movq	%rax, %rcx
	call	_ZN8RationalC1Eii
	leaq	-16(%rbp), %rax
	movl	$8, %r8d
	movl	$7, %edx
	movq	%rax, %rcx
	call	_ZN8RationalC1Eii
	movq	-16(%rbp), %rdx
	leaq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN8RationalplES_
	movq	%rax, -24(%rbp)
	leaq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN8Rational5printEv
	leaq	.LC1(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leaq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN8Rational5printEv
	leaq	.LC2(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leaq	-24(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN8Rational5printEv
	leaq	.LC3(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	-16(%rbp), %rdx
	leaq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN8RationalmiES_
	movq	%rax, -24(%rbp)
	leaq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN8Rational5printEv
	leaq	.LC4(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leaq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN8Rational5printEv
	leaq	.LC2(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leaq	-24(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN8Rational5printEv
	leaq	.LC3(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	-16(%rbp), %rdx
	leaq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN8RationalmlES_
	movq	%rax, -24(%rbp)
	leaq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN8Rational5printEv
	leaq	.LC5(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leaq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN8Rational5printEv
	leaq	.LC2(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leaq	-24(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN8Rational5printEv
	leaq	.LC3(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	-16(%rbp), %rdx
	leaq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN8RationaldvES_
	movq	%rax, -24(%rbp)
	leaq	-8(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN8Rational5printEv
	leaq	.LC6(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leaq	-16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN8Rational5printEv
	leaq	.LC2(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leaq	-24(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN8Rational5printEv
	leaq	.LC3(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$0, %eax
	addq	$64, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__tcf_0;	.scl	3;	.type	32;	.endef
	.seh_proc	__tcf_0
__tcf_0:
.LFB2067:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitD1Ev
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	_Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
	.seh_proc	_Z41__static_initialization_and_destruction_0ii
_Z41__static_initialization_and_destruction_0ii:
.LFB2066:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	cmpl	$1, 16(%rbp)
	jne	.L23
	cmpl	$65535, 24(%rbp)
	jne	.L23
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitC1Ev
	leaq	__tcf_0(%rip), %rcx
	call	atexit
.L23:
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	_GLOBAL__sub_I__ZN8RationalC2Eii;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I__ZN8RationalC2Eii
_GLOBAL__sub_I__ZN8RationalC2Eii:
.LFB2068:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	$65535, %edx
	movl	$1, %ecx
	call	_Z41__static_initialization_and_destruction_0ii
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I__ZN8RationalC2Eii
	.ident	"GCC: (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0"
	.def	_ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	atexit;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
