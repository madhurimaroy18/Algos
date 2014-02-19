/* To find if 2 binary trees are same.
   This uses functions of BST.c
*/

#include<stdio.h>
#include<stdlib.h>

struct bst* insert(struct bst *head, int n);
struct bst;

int compare(struct bst *head1, struct bst *head2)
{
    if(head1 == NULL || head2 == NULL)
    {
	printf("\nBST is NULL\n");
	return 1;
    }
    if (head1->left == head2->left == NULL || head1->right == head2->right ==NULL)
    	return 0;
    if (head1->left == NULL || head2->left == NULL || head1->right == NULL || head2->right ==NULL)
    	return 1;
    if (head1->i == head2->i) 
	return (compare(head1->left, head2->left) && compare(head1->right, head2->right));
    else return 1;

    return 0;
}
/*
int post_order_compare(struct bst *head1, struct bst *head2)
{
    if(head1 == NULL || head2 == NULL)
    {
	printf("\nBST is NULL\n");
	return 1;
    }
    if (head1->i == head2->i)
	return (compare(head1->left, head2->left) && compare(head1->right, head2->right));
    else return 1;

    return 0;
}
*/
int main()
{
    struct bst *node1, *node2, *head;
    node1 = (struct *bst)malloc(sizeof(struct bst));
    node1->i=10;
    node1->left = node1->right = NULL;
    node2 = (struct *bst)malloc(sizeof(struct bst));
    node2->i=10;
    node2->left = node2->right = NULL;
    printf("\nInserting nodes in BST 1\n");
    head = insert(node1, 2);
    head = insert(node1, 5);
    head = insert(node1, 9);
    head = insert(node1, 1);
    head = insert(node1, 3);
    head = insert(node1, 4);
    head = insert(node1, 6);
    head = insert(node1, 8);
    printf("Inserting nodes in BST 2\n");
    head = insert(node2, 2);
    head = insert(node2, 5);
    head = insert(node2, 9);
    head = insert(node2, 1);
    head = insert(node2, 3);
    head = insert(node2, 4);
    head = insert(node2, 6);
    head = insert(node2, 8);
    if (compare(node1, node2))
	printf("BSTs are same\n");
    else printf("BSTs are different\n");
    return 0;
}



