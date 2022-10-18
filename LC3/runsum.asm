.ORIG x3000

;;RTS Example: answer = Running(number);
;;main code
;;Main's activation record starting at x4000
;;Assume it only has local variables
;answer (x3FFF) <-R6
;number (x4000) <-R5
MAIN
        LD R5, RSTACK   ;set R5 to point to addr x4000
        LD R6, RSTACK   ;set R6 to point to addr x4000
        LD R0, NUMBER   ;set R0 to x0005 
        //
	STR R0, R6, #0		; number <- 5
	ADD R6, R6, #-1		; pushes answer
	
        ;Caller stack Built-up - push RUNNING's arg to the stack
        ADD R6, R6, #-1		;
	LDR R0, R5, #0		; R0 <- number (using the FP)
	STR R0, R6, #0		; pushed number (argument) on stack
        ;Pass control to callee - invoke RUNNING subroutine
        JSR Running
        ;Caller stack Tear-down for RUNNING
        

        HALT
NUMBER  .FILL   x0005
RSTACK  .FILL   x4000


;;RUNNING Subroutine
RUNNING
;callee set-up of Running Sum’s activation record
;push return value
ADD R6, R6, #-1		      ;
;push return address & old frame pointer
ADD R6, R6, #-1		 ;
STR R7, R6, #0
ADD R6, R6, #-1
STR R5, R6, #0		 ;
;;push local variables & update frame pointer
ADD R6, R6, #-1			;
ADD R5, R6, #0			;
				;function logic
;;base case (n==1)
LDR R1, R6, #4			;R1 <- n
ADD R2, R1, #-1			;
BRz BASE_CASE 			; n == 1
	
ADD R2, R1, #-1			;R2 <- n-1
;call Running(n-1)
ADD R6, R6, #-1			;
STR R2, R6, #0			;
JSR RUNNING			; recursive call;
	
;caller tear-down for Running(n-1)
;pop Running(n-1)’s return value to R0
	
LDR R0, R6, #0			; R0 <- return value
ADD R6, R6, #1			;
;pop running(n-1)’s argument
ADD R6, R6, #1			;
;calculate n + running(n-1)
LDR R1, R5, #4			; n<- R1
ADD R0, R1, R0			; R0 <- n + running(n-1)
;store result in fn
STR R0, R5, #0			;
;ready to return
BRnzp RETURN

BASE_CASE
;set fn = 1
AND R3, R3, #0			;
ADD R3, R3, #1			;
STR R3, R5, #0			;

RETURN
;set return value
LDR R2, R5, #0			; R2 <- fn
STR R2, R5, #3			; return val <- fn
;callee tear-down of Factorial(n)’s activation record
;pop local variables
ADD R6, R6, #1			;
	
;restore caller’s frame pointer and return address
LDR R5, R6, #0			;
ADD R6, R6, #1
LDR R7, R6, #0
ADD R6, R6, #1			;
;return to caller
RET
	
.END
