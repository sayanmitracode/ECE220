; ADD subroutine – pop two numbers from stack, 
; perform ‘+’ operation and then push result back to the stack
ADD_OP
		;save regs
                ST R7, ADD_SAVER7
                ST R0, ADD_SAVER0
                ST R1, ADD_SAVER1
                ST R6, ADD_SAVER6
		;load stack top pointer
                LD R6, STACK_TOP

		;first POP
                JSR POP
                ADD R5, R5, #0          ; check if pop is successful
                BRp EXIT
                ADD R1, R0, #0          ; save value in R1

		;second POP
                JSR POP
                ADD R5, R5, #0          ; check if pop is successful
                BRp RESTORE_1           ; restore first value to stack

		;add two numbers
                ADD R0, R0, R1          ; perform ‘+’ operation: R0 <- R0 + R1
                JSR CHECK_RANGE
                ADD R5, R5, #0
                BRp RESTORE_2           ; range check fail, restore both values to stack
                JSR PUSH
                BRnzp EXIT

RESTORE_1	;put back first number
                LD R6, STACK_TOP
                ADD R6, R6, #-1
                BRnzp EXIT


RESTORE_2	;put back both numbers
                LD R6, STACK_TOP
                ADD R6, R6, #-2
                BRnzp EXIT

EXIT		;prepare to return out
		;update stack top pointer
                ST R6, STACK_TOP
		;restore regs
                LD R7, ADD_SAVER7
                LD R0, ADD_SAVER0
                LD R1, ADD_SAVER1
                LD R6, ADD_SAVER6
                RET

