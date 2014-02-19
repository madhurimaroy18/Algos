//Using ITERATION
//This program creates a linklist of size 6
//makes user enter the data field of each link
//Traverses through the list
//Deletes link[3]
// Incase you want to give any other link to delete,say a, modify delete(head,a )

#include<stdio.h>
#include<stdlib.h>
#include "structlinklist.h"


//reversing a link list using iteration is defined in reverse_ll.c
struct ll *reverse_ll_iter(struct ll *head);

void traverse(struct ll *link)
{	
	while (link->next != NULL)
	{
		printf("%d\n", link->i);
		link = link->next;
	}
	printf("%d\n",link->i);
}


//Inserting a linklist
struct ll *insert(struct ll *head, int n)
{
    struct ll *new = NULL;
    struct ll *temp = head;
    new = (struct ll*) malloc(sizeof(struct ll));
    new->i = n;
    new->next = NULL;
    if (head == NULL)
    {
	return new;
    }
    else
    {
	while(temp->next!=NULL)
	{
	    temp = temp->next;
	}
	temp->next = new;
	return head;
    }
}

void delete(struct ll *head, int n)
{
	int i;
	struct ll *new, *link;
	link = head;
	i = 1;
	if (n == 1)
	{	link = head;
		head = head->next;	
		free(link);
	}
	else if (n ==4)
	{	while(link->next->next!=NULL)
		{
			link = link->next;	
		}
		free(link->next);
		link->next = NULL;
	}
	else 
	{
		while (i !=(n-1)) 	
		{	link = link->next;	
			i++;
		}

		new = link->next;
		link->next= new->next;
		free(new);
	}
	printf("\n Link [%d] deleted!! ", n);
	link = head;
	while (link != NULL)
	{
		printf("\n%d", link->i);
		link = link->next;
	}
}

int main()
{
    struct ll *head;

    head = NULL;
    head = insert(head, 5);
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);	
    head = insert(head, 4);
    head = insert(head, 0);
    traverse(head);

    printf("\n2. Traversing\n");
    traverse(head);
    delete(head,3);
    printf("\n 3. Reversing linklist by iteration\n");
    head = reverse_ll_iter(head);
    printf("\nResult after reversing\n");
    traverse(head);
    return 0;

}
