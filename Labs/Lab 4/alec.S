	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 3
	.globl	__Z5dummyii                     ; -- Begin function _Z5dummyii
	.p2align	2
__Z5dummyii:                            ; @_Z5dummyii
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #32
	.cfi_def_cfa_offset 32
	str	w0, [sp, #24]
	str	w1, [sp, #20]
	ldr	w8, [sp, #20]
	subs	w8, w8, #0
	cset	w8, ne
	tbnz	w8, #0, LBB0_2
	b	LBB0_1
LBB0_1:
	str	wzr, [sp, #28]
	b	LBB0_12
LBB0_2:
	ldr	w8, [sp, #20]
	subs	w8, w8, #0
	cset	w8, ge
	tbnz	w8, #0, LBB0_4
	b	LBB0_3
LBB0_3:
	ldr	w9, [sp, #24]
	mov	w8, #0
	subs	w9, w8, w9
	str	w9, [sp, #24]
	ldr	w9, [sp, #20]
	subs	w8, w8, w9
	str	w8, [sp, #20]
	b	LBB0_4
LBB0_4:
	b	LBB0_5
LBB0_5:
	ldr	w8, [sp, #24]
	str	w8, [sp, #16]
	mov	w8, #1
	str	w8, [sp, #12]
	b	LBB0_6
LBB0_6:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #12]
	ldr	w9, [sp, #20]
	subs	w8, w8, w9
	cset	w8, ge
	tbnz	w8, #0, LBB0_11
	b	LBB0_7
LBB0_7:                                 ;   in Loop: Header=BB0_6 Depth=1
	ldr	w9, [sp, #12]
	mov	w8, #2
	mul	w8, w8, w9
	ldr	w9, [sp, #20]
	subs	w8, w8, w9
	cset	w8, gt
	tbnz	w8, #0, LBB0_9
	b	LBB0_8
LBB0_8:                                 ;   in Loop: Header=BB0_6 Depth=1
	ldr	w8, [sp, #16]
	lsl	w8, w8, #1
	str	w8, [sp, #16]
	ldr	w8, [sp, #12]
	lsl	w8, w8, #1
	str	w8, [sp, #12]
	b	LBB0_10
LBB0_9:                                 ;   in Loop: Header=BB0_6 Depth=1
	ldr	w9, [sp, #24]
	ldr	w8, [sp, #16]
	add	w8, w8, w9
	str	w8, [sp, #16]
	ldr	w8, [sp, #12]
	add	w8, w8, #1
	str	w8, [sp, #12]
	b	LBB0_10
LBB0_10:                                ;   in Loop: Header=BB0_6 Depth=1
	b	LBB0_6
LBB0_11:
	ldr	w8, [sp, #16]
	str	w8, [sp, #28]
	b	LBB0_12
LBB0_12:
	ldr	w0, [sp, #28]
	add	sp, sp, #32
	ret
	.cfi_endproc
                                        ; -- End function
	.globl	_main                           ; -- Begin function main
	.p2align	2
_main:                                  ; @main
	.cfi_startproc
; %bb.0:
	stp	x29, x30, [sp, #-16]!           ; 16-byte Folded Spill
	.cfi_def_cfa_offset 16
	mov	x29, sp
	.cfi_def_cfa w29, 16
	.cfi_offset w30, -8
	.cfi_offset w29, -16
	mov	w0, #7
	mov	w1, #19
	bl	__Z5dummyii
	mov	x1, x0
	adrp	x0, __ZNSt3__14coutE@GOTPAGE
	ldr	x0, [x0, __ZNSt3__14coutE@GOTPAGEOFF]
	bl	__ZNSt3__113basic_ostreamIcNS_11char_traitsIcEEElsEi
	mov	w0, #0
	ldp	x29, x30, [sp], #16             ; 16-byte Folded Reload
	ret
	.cfi_endproc
                                        ; -- End function
.subsections_via_symbols
