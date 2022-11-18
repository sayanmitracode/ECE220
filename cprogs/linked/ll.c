#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentStruct student;

struct studentStruct{
	int UIN;
	float GPA;
	char name[10];
	student * next;
};

void print(student * head);
void add(student ** head, int uin, float gpa, char name[10]);
void addEnd(student ** head, int uin, float gpa, char name[10]);

student * find(student * head, int uin);

int main(){
	student * head;
	head = (student *) malloc(sizeof(student));
	head->UIN = 1234;
	head->GPA = -1.0;
	head->next = NULL;
	strcpy(head->name,"Teresa");

	head->next = (student *) malloc(sizeof(student));
	head->next->UIN = 2344;
	head->next->GPA = -1.0;
	head->next->next = NULL;
	strcpy(head->next->name,"Boris");

	add(&head, 3345, -1.0, "Liz");
	addEnd(&head, 4345, -1.0, "Rishi");
	addEnd(&head, 5345, -1.0, "Piers");

	print(head);
	if (find(head,4345)==NULL)
		printf("\n UIN %d not found", 4345);
	if (find(head,4445)==NULL)
		printf("\n UIN %d not found", 4445);
	
	/* 
	add(list,1345);
	add(list,2234);
	print(list);
	*/
	return 0;
}

void add(student ** head, int uin, float gpa, char name[10])
{
	// add node at the head of the list
	student * new;
	new = (student *) malloc(sizeof(student));
	new->UIN = uin;
	new->GPA = gpa;
	new->next = *head;
	strcpy(new->name,name);
	*head = new;
	return;
}

void addEnd(student ** head, int uin, float gpa, char name[10]){
	// add node at the end
	student * new;
	student * current;
	new = (student *) malloc(sizeof(student));
	new->UIN = uin;
	new->GPA = gpa;
	strcpy(new->name,name);
	if (*head == NULL)
	{
		*head = new;
		return;
	}
	else
	{
		current = *head;
		while (current->next != NULL)
		{
			current=current->next;
		}
		current->next = new;
	}
	return;

}


student * find(student * head, int uin)
{
	// find a node with the UIN, return pointer to node if found
	// else return NULL
	student * current = head;
	int i = 1;
	while(current != NULL)
	{
		if (current->UIN == uin){
			printf("\n Node found at %d name %s UIN %d", i, current->name, current->UIN);
			return current;
		}
		current = current->next;
		i++;
	}
	return NULL;
}

void print(student * head)
{
	student * current = head;
	int i;
	while(current != NULL)
	{
		printf("\n %d. %s UIN %d GPA %f", i, current->name, current->UIN, current->GPA);
		current = current->next;
		i++;
	}
	return;
}
