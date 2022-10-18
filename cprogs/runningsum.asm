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

        ;Caller stack Built-up - push RUNNING's arg to the stack
        
        ;Pass control to callee - invoke RUNNING subroutine
        
        ;Caller stack Tear-down for RUNNING
        

        HALT
NUMBER  .FILL   x0005
RSTACK  .FILL   x4000


;;RUNNING Subroutine
RUNNING
;callee set-up of Running Sum’s activation record
;push return value

;push return address & old frame pointer

;;push local variables & update frame pointer

;function logic
;;base case (n==1)

ADD 
;call Running(n-1)

;caller tear-down for Running(n-1)
;pop Running(n-1)’s return value to R0

;pop running(n-1)’s argument

;calculate n + running(n-1)

;store result in fn

;ready to return
BRnzp RETURN

BASE_CASE
;set fn = 1


RETURN
;set return value

;callee tear-down of Factorial(n)’s activation record
;pop local variables

;restore caller’s frame pointer and return address

;return to caller

.END