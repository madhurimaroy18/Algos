//This program creates a binary search tree
//inorder traversal of BST 
//ToDo: find nth node
//Todo: printthe tree in graphical form
//ToDo: Balancing a BST
#include<stdio.h>
#include<stdlib.h>

struct bst
{	
	struct bst *left;
	int i;
	struct bst *right;
};
//The search returns node if n is equal to any node
//also it return the closest node if n isnt in tree
struct bst *search(struct bst *node, int n)
{
	if (node == NULL)
	{
		return NULL;
	}
	if (node->i == n)
	{
		return node;
	}
	else if (node->i < n)
	{
		printf("\nm: going to right child from %d ", node->i);
		if (node->right == NULL) //if right child is NULL,i.e nothing matched till now, return the closest find
		{	return node;
		}
		else return search(node->right,n);
	}
	else if (node->i > n)
	{	
		printf("\nm: going to left child from %d ", node->i);
		if (node->left == NULL)  //if right child is NULL,i.e nothing matched till now, return the closest find

		{	return node;
		}
		else 	return search(node->left,n);
	}
	return node;
}	


void inorder_traverse(struct bst *node)
{	
	if (node == NULL)
	{
		printf("BS");
	}
	if (node->left != NULL)
	{
		inorder_traverse(node->left);
	}
 	printf("\n%d",node->i);
	if (node->right != NULL)
	{
		inorder_traverse(node->right);
	}	
	
}

struct bst* insert(struct bst *head, int n)
{
	struct bst * node,* temp;
	node = (struct bst*)malloc (sizeof (struct bst));
	node->i = n;
	node->left = node->right = NULL;
	temp = search(head, n);
	printf("\nm: search location %d", temp->i);
	if (temp->i < n)
	{
		temp->right = node;
	}
	if (temp->i > n)
	{
		temp->left = node;
	}	
	if (temp->i == n)
	{
		printf("\n The value is already in the tree");	
	}		
	return node;	
}


/*
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
}*/

int main()
{
	struct bst * node,* temp;
	node = (struct bst*)malloc (sizeof (struct bst));
	node->i = 10;
	node->left = node->right = NULL;
	printf("\nInserting 6 links ");
	temp = insert(node, 2);
	temp = insert(node, 5);
	temp = insert(node, 9);
	temp = insert(node, 1);
	temp = insert(node, 3);
	temp = insert(node, 4);
	temp = insert(node, 6);
	temp = insert(node, 8);
	printf("\nTraversing\n");
	inorder_traverse(node);
	//delete(head,3);
	return 0;

}
