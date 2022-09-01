.ORIG x3000

;; Main program for computing 3x^3 - 6x^2 + 7x
;; Value of input stored at xvalue
;; Demonstrate use of two subroutines for multiplication and subtraction
	
LD R1, xvalue			;R1,R2 <- x
LD R2, xvalue
JSR MULT 
ADD R4, R0, #0 			;R4 <- x^2
ADD R1, R0, #0			;R1 <- x^2, R2 <- x
JSR MULT
ADD R5, R0, #0			;R5 <- x^3
ADD R1, R0, #0			;R1 <- X^3
AND R2, R2, #0
ADD R2, R2, #3			;R2 <- 3
JSR MULT
ADD R6, R0, #0			;R6 <- 3x^3
AND R2, R2, #0
ADD R2, R2, #6		 	;R2 <-6
ADD R1, R4, #0			;R1 <- x^2
JSR MULT
ADD R2, R0, #0			;R2 <- 6x^2
ADD R1, R6, #0			;R1 <- 3x^3
JSR SUBTR
ADD R6, R0, #0			;R6 <- 3x^3 - 6x^2
LD R1, xvalue
AND R2, R2, #0
ADD R2, R2, #7		 	;R2 <-7
JSR MULT			;R0 <- 7x
ADD R0, R6, R0			;R0 <- 3x^3 - 6x^2 + 7x
HALT
	
xvalue .FILL #4

;; Multiplication subroutine
;;; input: R1, R2
;;; output: R0 <- R1 X R2
MULT
	ST R2, MULT_SAVE_R2 	;save R2 in memory
	ST R1, MULT_SAVE_R1 	;save R1 in memory
	ST R7, MULT_SAVE_R7 	;save R7 in memory
	
	AND R0, R0, #0		;reset R0
MLOOP	ADD R0, R1, R0
	ADD R2, R2, #-1
	BRP MLOOP	

	LD R2, MULT_SAVE_R2 	;load R2 in memory
	LD R1, MULT_SAVE_R1 	;load R1 in memory
	LD R7, MULT_SAVE_R7 	;load R7 in memory

RET

MULT_SAVE_R1 .BLKW #1	;memory for saving R2
MULT_SAVE_R2 .BLKW #1	;memory for saving R1
MULT_SAVE_R7 .BLKW #1	;memory for saving R7


;;; Subtraction subroutine
;;; input: R1, R2
;;; output: R0 <- R1 - R2
;;; callee save
SUBTR
	ST R2, SUBT_SAVE_R2 	;save R2 in memory
	ST R1, SUBT_SAVE_R1 	;save R1 in memory
	ST R7, SUBT_SAVE_R7 	;save R7 in memory
	NOT R2, R2
	ADD R2, R2, #1		;
	ADD R0, R1, R2		; R0 <- R1 - R2

	LD R2, SUBT_SAVE_R2 	;load R2 in memory
	LD R1, SUBT_SAVE_R1 	;load R1 in memory
	LD R7, SUBT_SAVE_R7 	;load R7 in memory

RET

SUBT_SAVE_R1 .BLKW #1	;memory for saving R2
SUBT_SAVE_R2 .BLKW #1	;memory for saving R1
SUBT_SAVE_R7 .BLKW #1	;memory for saving R7
.END
