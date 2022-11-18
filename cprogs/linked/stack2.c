
typedef struct nodeStruct node;

struct nodeStruct{
	int data;
	node * next;
};

void push(node **top, int item);
int pop(node** top);
void print(node * top);

int main(){

	node * top;
	push(&top, 5);
	print(&top);
	push(&top, 6);
	push(&top, 10);
	push(&top, 25);
	pop(&top);
	pop(&top);
	return 0;
}


void push(node ** top, int item){
	node * temp = *top;
	node * new = (node *)malloc(sizeof(node));
	new->data = item;
	if (*top == NULL)
		new->next = NULL;
	else
	{
		new->next = *top;
	}
	*top = new;
	return ;
}

int pop(node** top){
	node * temp = *top;
	int val;
	if (*node == NULL){
		printf("\n Empty stack");
		return -1;
	}
	else
	{
		val = *top->data;
		*top= (*top)->next;
		free(temp);
		return val;
	}
}


void print(node * top){
	node * current = top;
	printf("\n Printing stack \n");
	while(current != NULL)
	{
		printf("\n %d", current->data);
		current = current->next;
	}
	return;
}



