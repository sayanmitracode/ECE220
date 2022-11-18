#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentStruct student;

struct studentStruct{
	int UIN;
	float GPA;
	char name[20];
	student * next;
};

void printll(student * head);

student* find(student * head, int uin);

void add(student ** head, int uin, char name[20]);

void addSorted(student ** head, int uin, char name[20]);

void delete(student * head);
void remove_node(student ** head, int uin);


int main(){
	student * head; 
	head = (student *)malloc(sizeof(student));
	head->UIN = 1234;
	head->GPA = -1.0;
	strcpy(head->name, "Teresa");
	head->next = (student *)malloc(sizeof(student));
	head->next->UIN = 2344;
	head->next->GPA = -1.0;
	strcpy(head->next->name, "Boris");
	head->next->next = NULL;

	addSorted(&head, 4578, "Rishi");
	printll(head);

	addSorted(&head, 3678, "Liz");
	printll(head);

	addSorted(&head, 578, "Joy");
	printll(head);

	// remove_node(&head, 578);
	// printll(head);

	// remove_node(&head, 2344);
	// printll(head);

	// remove_node(&head, 1234);
	// printll(head);



	return 0;
}


void remove_node(student ** head, int uin){
	student *current = *head;
	student *temp;
	// Case 1. remove the head node
	if (uin == (*head)->UIN){
		*temp = *head;
		*head = (*head)->next;
	}

	// Case 2. find node in the middle or at the end
	while(current->next != NULL)
	{
		if(current->next->UIN == uin)
			break;
		else if (current->next->UIN > uin){
			// we are past the range 
			printf("\n Record %d not found in the list", uin);
			return;
			}	
		current = current->next;
	}
	if (current->next == NULL)
	{
		// record not found after traversing the whole list
		printf("\n Record %d not found in the list", uin);
		return; 
	}
	else
	{
		// record found and pointers have to be moved
		temp = current->next;
		current->next = current->next->next;
	}

	free(temp);

}




void add(student ** head, int uin, char name[20]){
	student * new = (student *)malloc(sizeof(student));
	new->UIN = uin;
	new->GPA = -1.0;
	strcpy(new->name,name);
	new->next = *head;
	*head = new;
	return;

}


// void addSorted(student ** head, int uin, char name[20])
// {
// 	// setup pointers for traversal
// 	student * current = *head;
// 	student *prev = *head;
// 	// create the new node
// 	student *new = (student *)malloc(sizeof(student));
// 	new->UIN = uin;
// 	new->GPA = -1.0;
// 	strcpy(new->name,name);

// 	while(current!=NULL){
// 		if(uin < current->UIN)
// 		{
// 			new->next = current;
// 			if (current == *head)
// 			{
// 				// we want to insert the new node at the head
// 				*head = new;
// 			}
// 			else
// 			{
// 				// general case
// 				prev->next = new;
// 			}
// 			return; // exit function
// 		}
// 		// we have reached the last node and its UIN is smaller than the 
// 		// new node's UIN
// 		if(current->next == NULL)
// 		{
// 			current->next = new;
// 			new->next = NULL;
// 			return;
// 		}
// 		prev = current;
// 		current= current->next;
// 	}
// 	return;
// }




void printll(student * head){
	student * current = head;
	int i = 1;
	printf("\n Printing \n");
	while(current != NULL)
	{
		printf("\n %d. %s UIN = %d", i, current->name, current->UIN);
		current = current->next;
		i++;
	}
	return;

}

student* find(student * head, int uin){
	// returns pointer to the first node that has UIN = uin
	// if no such node exists in the LL then return NULL
	student * current = head;
	int i = 1;
	while(current != NULL)
	{
		if(current->UIN == uin)
		{
			printf("\n Found %d at %d", uin, i);
			return current;
		}
		i++;
		current = current->next;
	}
	return NULL;
}

void addSorted(student **head, int uin, char name[20])
{
	student *current = *head;
	student *prev = *head;

	// Create new node
	student *new = (student *)malloc(sizeof(student)); 
	new->UIN = uin; //initialize UIN for the new node
	strcpy(new->name, name);

	//keep traversing the list until we reach the end
	while(current != NULL)
	{
		//the first instance when new uin is smaller than current record's UIN
		//we want to insert new node in front of the current node
		if(uin < current->UIN) 
		{
			new->next = current;
			if(current == *head) //if the current node is the head, update head pointer
			  {	*head = new;}
			else //for everything else, update previous node's next pointer
			  {prev->next = new;}
			return; //exit function
		}

		// we've reach the last note and its UIN is still 
		// smaller than new node's UIN
		// new node will have to be inserted at the tail
		if(current->next == NULL) 
		{
			current->next = new;
			new->next = NULL;
		}

		prev = current;
		current = current ->next;
	}

}


void delete(student * head)
{
	if(head != NULL)
	{
		student * temp = head;
		delete(head->next);
		free(temp);
	}
	return;
}

void remove_node(student **head, int old_UIN){
	student *current = *head;
	student *temp;
	//case 1: remove head node, update list
	if((*head)->UIN == old_UIN){
		temp = *head;
		*head = (*head)->next;
	}
	else{
	//case 2: find node in the middle or at the end
	while(current->next != NULL){
		if(current->next->UIN == old_UIN)
			break;
		else if(current->next->UIN > old_UIN){ //past the range
			printf("\n Record %d not found.\n", old_UIN);
			return;
		}
		current = current->next;
	}

	//record not found after traversing the entire llist
	if(current->next == NULL){
		printf("\n Record %d not found.\n", old_UIN);
		return;
	}
	else{//record found - redirect pointers
		temp = current->next;
		current->next = current->next->next;
	}
	}
	free(temp);
}



