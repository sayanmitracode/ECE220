
.ORIG x3000
	
;;; Main program
;;; Exercise with stack, push and pop

	AND R0,R0, #0
	ADD R0, R0, #5
	JSR PUSH
	ADD R0, R0, #5
	JSR PUSH
	JSR PUSH
	JSR POP
	JSR POP
	ADD R2, R0, #0
	JSR POP
	JSR POP
	ADD R2, R5, #0 		;What do you expect to see in R2? 
HALT
	


; PUSH subroutine
; IN: R0 (value)
; OUT: R5 (0 – success, 1 – fail)
; R3: STACK_END
; R6: STACK_TOP
PUSH
; save original values of R3 and R6, init R5
	ST R3, PUSH_SaveR3
	ST R6, PUSH_SaveR6
	LD R3, STACK_END
	LD R6, STACK_TOP
; Assume no overflow 
	AND R5, R5, #0 ; clear R5, indicates success
; Check for full stack, overflow
; Check stack_top = stack_end-1
	ADD R3, R3, #-1
	NOT R3, R3
	ADD R3, R3, #1
	ADD R3, R6, R3
	BRZ OVERFLOW
	STR R0, R6, #0		;push onto stack
	ADD R6, R6, #-1		;move top of stack up
	ST R6, STACK_TOP
	BRNZP DONEPUSH
OVERFLOW
	ADD R5, R5, #1
DONEPUSH
; load R3 with STACK_END, R6 with STACK_TOP
	LD R3, PUSH_SaveR3
	LD R6, PUSH_SaveR6
RET


; PUSH subroutine
; IN: None
; OUT: R0 (value), R5 (0 – success, 1 – fail)
; R3: STACK_START
; R6: STACK_TOP
POP
; save original values of R3 and R6, init R5
	ST R3, PUSH_SaveR3
	ST R6, PUSH_SaveR6
	LD R3, STACK_START
	LD R6, STACK_TOP
; Assume no underflow 
	AND R5, R5, #0 ; clear R5, indicates success
; Check for empty stack, underflow
; Check stack_top = stack_start
	NOT R3, R3
	ADD R3, R3, #1
	ADD R3, R6, R3
	BRZ UNDERFLOW
	LDR R0, R6, #0		;push onto stack
	ADD R6, R6, #1		;move top of stack up
	ST R6, STACK_TOP
	BRNZP DONEPOP
UNDERFLOW
	ADD R5, R5, #1
DONEPOP
; load R3 with STACK_END, R6 with STACK_TOP
	LD R3, PUSH_SaveR3
	LD R6, PUSH_SaveR6
RET

PUSH_SaveR3 .BLKW #1
PUSH_SaveR6 .BLKW #1

POP_SaveR3 .BLKW #1
POP_SaveR6 .BLKW #1

STACK_START .FILL x4000
STACK_END   .FILL x3FF0
STACK_TOP   .FILL x4000
	
.END
