#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct nodeStruct node;
struct nodeStruct{       
        int data;
        node *next;
};

void push(node** top, int new_data); /* push a new node to stack */
int pop(node **top); /* return data of the node pop from stack */
void print(node *top); 

int main()
{
        node *top = NULL;
        pop(&top);
        push(&top,5); 
        push(&top,15); 
        push(&top,50); 
        push(&top,125); 

        print(top);
        pop(&top);
        pop(&top);
        pop(&top);
        print(top);
        
        /* init to NULL in main */

        return 0;

}

int pop(node ** top){
        int data;
        node * temp;
        if (*top == NULL){
                printf("\n Empty stack; nothing to pop. \n");
                return -1;
        }
        data = (*top)->data;
        temp = *top;
        *top = (*top)->next;
        free(temp);
        return data;
}

void push(node** top, int new_data) /* push a new node to stack */
{
        node * new = (node*)malloc(sizeof(node));
        new->data = new_data;
        new->next = *top;
        *top = new;
        return;
}

void print(node *top){
        printf("\n Printing stack: \n");
        node * current = top;
        while (current != NULL)
        {
                printf ("%d \n", current->data);
                current=current->next;
        }
        return;
}

