#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
};

void display(struct node* head);

int main()
{
    struct node *head=(struct node*)malloc(sizeof(struct node));
    head->data=10;
    head->link=head;

    struct node *current = (struct node*)malloc(sizeof(struct node));
    current->data=20;
    current->link=head;
    head->link=current;

    current=(struct node*)malloc(sizeof(struct node));
    current->data=30;
    current->link=head;
    head->link->link=current;
    printf("Cricular Linked List is created\n");
    display(head);
}

void display(struct node *head)
{
    if (head==NULL)
    {
        printf("List is empty.\n");
    }

    struct node *temp = head;
    if (head == NULL)
        printf("No nodes are attached\n");
    do
    {
        printf("%d->", temp->data);
        temp = temp->link;
    }
    while (temp != head);
    printf("%d //Circular linked list \n",head->data);
}
