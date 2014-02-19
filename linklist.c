//This program creates a linklist of size 6
//makes user enter the data field of each link
//Traverses through the list
//Deletes link[3]
// Incase you want to give any other link to delete,say a, modify delete(head,a )

#include<stdio.h>
#include<stdlib.h>
#include "structlinklist.h"


//reversing link list is defined in reverse_ll.c
struct ll *reverse_ll(struct ll *head);

//reversing a link list using iteration is defined in reverse_ll.c
struct ll *reverse_ll_iter(struct ll *head);

//reversing linklist pair-wise
void reverse_ll_pair(struct ll *head);

void traverse(struct ll *link)
{	
	while (link->next != NULL)
	{
		printf("%d\n", link->i);
		link = link->next;
	}
	printf("%d\n",link->i);
}

struct ll* insert(struct ll *head, int n)
{
	int i;
	struct ll *new, *link;
	link = head;
	i = 0;
	if (head == NULL)
	{
		head = (struct ll*)malloc(sizeof(struct ll));
		printf("\nwhat do u want to add in head : ");
		scanf ("%d", &i);
		head->i= i;
		head->next = NULL;
	}
	link=head;
	if (link->next == NULL)
	{
		i = 1;
	}
	else
	{
		while(link->next!=NULL)
		{
			link = link->next;	
			++i;
		}
	}	
	if (n >i)
	{	printf("\n%d is beyond range. hence inserting link at %d ", n, i);
		n = i;
	}	
	new = (struct ll*)malloc(sizeof(struct ll));
	link = head;
	for(i=0;i<n;i++)
	{
		link = link->next;	
	}	
	new->next  = link->next;
	printf("\nwhat do u want to add : ");
	scanf ("%d", &i);
	new->i= i;
	link->next = new;

	return head;
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
	printf("\n1. Inserting 6 links ");
	head = insert(head, 0);
	head = insert(head, 1);
	head = insert(head, 2);
	head = insert(head, 3);	
	head = insert(head, 4);
	printf("\n2. Traversing\n");
	traverse(head);
	delete(head,3);
	printf("\n3. Reversing linklist by recursion\n");
	head = reverse_ll(head);
	printf("\nResult after reversing\n");
	traverse(head);
	printf("\n 4. Reversing linklist by iteration\n");
	head = reverse_ll_iter(head);
	printf("\nResult after reversing\n");
	traverse(head);

	printf("5. Reversing linklist pairwise");
	reverse_ll_pair(head);
	printf("\nResult after reversing\n");
	traverse(head);

	return 0;

}
