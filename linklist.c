//This program creates a linklist of size 6
//makes user enter the data field of each link
//Traverses through the list
//Deletes link[3]
// Incase you want to give any other link to delete,say a, modify delete(head,a )

#include<stdio.h>
#include<stdlib.h>

struct ll
{	
	int i;
	struct ll *next;
};

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
	printf("\nInserting 6 links ");
	head = insert(head, 0);
	head = insert(head, 1);
	head = insert(head, 2);
	head = insert(head, 3);
	head = insert(head, 4);
	printf("\nTraversing\n");
	traverse(head);
	delete(head,3);
	return 0;

}
