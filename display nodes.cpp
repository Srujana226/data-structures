#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *link;
};

void traverse(struct node *head);
void display(struct node *head);
int main()
{
	struct node *head = (struct node*)malloc(sizeof(struct node));
	head->data = 10;
	head->link = NULL;
	struct node *current = (struct node*)malloc(sizeof(struct node));
	current->data = 20;
    current->link = NULL;
	head->link = current;
	current = (struct node*)malloc(sizeof(struct node));
	current->data = 30;
	current->link =NULL;
	head->link->link = current;
	current = (struct node*)malloc(sizeof(struct node));
	current->data = 40;
	current->link = NULL;
	head->link->link->link = current;
    traverse(head);
    display(head);
		
}
void traverse(struct node *head)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node *));
	temp->link = head;
	if(temp == NULL)
	{
	printf("linked list is empty");
	exit(0);
    }
	while(temp!=NULL)
	{
	//printf("%d->",temp->data);
	temp=temp->link;
    }
}
void display(struct node *head)
{
    struct node* temp = head;
    while (temp != NULL) 
        {
		printf("%d -> ", temp->data);
        temp = temp->link;
}
}
