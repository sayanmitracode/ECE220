;;; Implementation of a stack ECE 220
	.ORIG x3000
;;; Main program
	AND R0, R0, #0
	ADD R0, R0, #5
	JSR PUSH
	ADD R0, R0, #5
	JSR PUSH
	ADD R0, R0, #5
	JSR PUSH
	JSR POP			;R0 <- 15
	JSR POP			;R0<- 10
	JSR POP			;R0 <- 5
	JSR POP			;Underflow R5 == 1
	HALT
	
;;; PUSH subroutine
;;; Input: RO value to be pushed
;;; Output: R5 (0--normal, 1---overflow)
;;; R6: Stack_top
;;; R3: stack_end
PUSH
	;; callee save R3, R6
	ST R3, PUSH_saveR3
	ST R6, PUSH_saveR6
	LD R6, STACK_TOP
	LD R3, STACK_END
	;;  initialize R5, assuming no overflow
	AND R5, R5, #0
	;; check for overflow stack_top = stack_end -1
	ADD R3, R3, #-1
	NOT R3, R3
	ADD R3, R3, #1
	ADD R3, R6, R3		; R3 = (stack_top - (stack_end -1))
	BRZ OVERFLOW
	STR R0, R6, #0		;Push
	ADD R6, R6, #-1		; mover stack_top
	ST R6, STACK_TOP
	BRNZP PUSH_DONE
OVERFLOW
	ADD R5, R5, #1
PUSH_DONE	
	;; callee restore
	LD R3, PUSH_saveR3
	LD R6, PUSH_saveR6
	RET

	PUSH_saveR3 .BLKW #1
	PUSH_saveR6 .BLKW #1


	
;;; POP subroutine
;;; Input: none
;;; Output: R0 popped value, R5 (0--normal, 1---underflow)
;;; R6: Stack_top
;;; R3: stack_start
POP
;;; Fill in
	RET
	
;;; STACK parameters
	STACK_START .FILL x4000
	STACK_END .FILL x3FF0
	STACK_TOP .FILL x4000	; R6
	
	.END
