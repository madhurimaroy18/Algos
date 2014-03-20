// Program for insertion, deletion, traversal(inorder, postorder, pre-order) of BST
// Finding the least common parent

#include<stdio.h>
#include<stdlib.h>
int flag = 0;

struct node
{
    struct node * left;
    int data;
    struct node * right;
};

struct node * root = NULL;

//Insertion in BST
struct node * insert(struct node * head, int i)
{
    struct node * new = NULL;

    new = (struct node *)malloc(sizeof(struct node));
    new->data = i;
    new->left = new->right = NULL;

    if (head == NULL)
    {
	printf("\nthere is no BST. New BST being created\n");
	return new;
    }

    if(i > head->data) {
	if (head->right == NULL) {
	    head->right = new;
	    return head->right;
	} else {
	    return insert(head->right, i);
	}
    }

    if(i < head->data) {
	if (head->left == NULL)
	{
	    head->left = new;
	    return head->left;
	} else {
	    return insert(head->left, i);
	}
    }

    if (i == head->data) {
	free(new);
	new = NULL;
	return head;
    }
}

//Get predecessor of i by inorder traversal
struct node * get_predecessor( struct node *head, struct node *pred,  int i)
{
    if (head == NULL)
    {
	printf("\n No BST");
	return; 
    }
    if (head->left != NULL)
    { 
	if (flag!=1)
	{
	    //printf("\ngoing left");
	    pred = get_predecessor(head->left, pred, i);
	    //printf("\nget_predecessor(head->left %d , pred %d, i %d)",head->left->data, pred->data, i);
	}
    }
    //printf(" \n printing current head %d ", head->data);

    if (head->data == i)
    {
	flag = 1;
	//printf("\n changing flag to 1. returning pred as %d",pred->data);  
	return pred;
    }

    if (flag!=1)
    {
	pred = head;
    }
    if (head->right != NULL)
    {
	if(flag!=1)
	{
	    //printf("going right");
	    pred = get_predecessor(head->right, pred, i);
	    // printf("\nget_predecessor(head->right %d , pred %d, i %d)",head->right->data, pred->data, i);
	}

    }
    //printf("\nreturning pred %d ", pred->data);
    return pred;
}


//Deletion of a specific node given data
void delete( struct node * head, struct node * parent, int i)
{
    struct node * pred = NULL;  
    int tmp = 0;
    
    if (head == NULL)
    {
	printf("\nthere is no BST. Noting to delete\n");
	return;
    }
    
    if (head->data < i && head->right!=NULL)
    {
	delete(head->right,head, i);
    }

    if (head->data > i && head->left != NULL)
    {
	delete(head->left, head, i);
    }

    if (head->data == i)
    {
	//case where there is no child
	if(head->left == NULL && head->right == NULL)
	{
	    if(parent->left == head) //if head is left child
	    {
		parent->left = NULL;
		free(head);
		return;
	    }
	    
	    if(parent->right == head) //if head is right child
	    {
		parent->right = NULL;
		free(head);
		return;
	    }
	}

	//case with only left child
	if(head->right == NULL && head->left != NULL)
	{
	    head->data = head->left->data;
	    free(head->left); // or just call delete
	    head->left = NULL;
	}
	//case with only right child
	if(head->left == NULL && head->right != NULL)
	{
	    head->data = head->right->data;
	    free(head->right);
	    head->right = NULL;
	}
	//case when node has both left and right children
	if (head->left != NULL && head->right != NULL)
	{
	    pred = get_predecessor(root, NULL, head->data);
	    printf("pred = %d, head = %d", pred->data, head->data);
	    // tmp = pred->data;
	    // delete(root, NULL, pred->data);
	    // head->data = tmp;

#if 0
	    if (parent->right == pred) //if predecessor is right child
	    {
		free(pred);
		parent->right == NULL;
		return;
	    }
	    if (parent->left == pred) //if predecessor  is right child
	    {
		free(pred);
		parent->left == NULL;
		return;
	    }
#endif
	}
    }
}

//Deleting of subtree from given node
void delete_sub(struct node *node){
    //Deleting left child
    if (node->left!=NULL){

	if(node->left->left != NULL){
	    delete_sub(node->left);
	}
	if (node->left->right != NULL){
	    delete_sub(node->left);
	}
	printf("\n Deleting node %d", node->left->data);
	free(node->left);
	node->left = NULL;
    }
    //Deleting right child
    if (node->right!=NULL){
	if(node->right->left != NULL){
	    delete_sub(node->right);
	}
	if (node->right->right != NULL){
	    delete_sub(node->right);
	}   
	printf("\n Deleting node %d", node->right->data);
	free(node->right);
	node->right = NULL;
    }
}

//Inorder traversal 
void in_traverse( struct node *head)
{
    if (head == NULL)
    {
	printf("\n No BST");
    	return; 
    }
    if (head->left != NULL)
    { 
	in_traverse(head->left);
    }

    printf(" %d ", head->data);

    if (head->right != NULL)
    {
    	in_traverse(head->right);
	
    }
    return;
}

//Post order traversal

void post_traverse( struct node *node)
{
    if (node == NULL)
    {
	return;
    }
    if (node->left != NULL )
    {
	post_traverse(node->left);
    }
    if (node->right != NULL);
    {
	post_traverse(node->right);
    }
    printf(" % d ", node->data);
    return;
}
/*
//Pre order traversal
void pre_traversal( struct node *root)
{
}
*/

//Least Common Ancestor
void lca(struct node * head, int p, int q)
{
    if(p < head->data && q < head->data && head->left != NULL)
    {
	lca(head->left,p,q);
    }
    
    if(p > head->data && q > head->data && head->right != NULL)
    {
	lca(head->right,p,q);
    }
    if ((p > head->data && q < head->data) || (p < head->data && q > head->data))
    {
	printf("\n Least common ancestor of %d and %d is %d", p, q, head->data);
	return;
    }
}


void main()
{
    struct node * head = NULL, * temp = NULL;
    int i = 0;
    head = insert(head, 60); //in_traverse(head); printf("\n");
    temp = insert(head, 41); //in_traverse(head); printf("\n");
    temp = insert(head, 16); //in_traverse(head); printf("\n");
    temp = insert(head, 53); //in_traverse(head); printf("\n");
    temp = insert(head, 25); //in_traverse(head); printf("\n");
    temp = insert(head, 46); //in_traverse(head); printf("\n");
    temp = insert(head, 42); //in_traverse(head); printf("\n");
    temp = insert(head, 55); //in_traverse(head); printf("\n");
    temp = insert(head, 74); //in_traverse(head); printf("\n");
    temp = insert(head, 65); //in_traverse(head); printf("\n");
    temp = insert(head, 63); //in_traverse(head); printf("\n");
    temp = insert(head, 70); //in_traverse(head); printf("\n");
    temp = insert(head, 62); //in_traverse(head); printf("\n");
    temp = insert(head, 64); //in_traverse(head); printf("\n");

    in_traverse(head); printf("\n");

    i = 60;
    root = head;
    temp = get_predecessor(head, NULL ,i);
    printf("\n1. Predecessor of %d is %d", i, temp->data);
    printf("\n2. Post traversal");
    post_traverse(head);
    printf("\n3. Least Common ancestor");
    lca(head, 62, 70);
    i = 65;
    printf("\n\n4. delete left and right subtrees of head\n");
    delete_sub(head->left);
    delete_sub(head->right);

    //printf("\n2. Deleting %d", i);
    //delete(head,NULL, i); printf("\n");
    // printf("After deletion of %d", i);
    printf("\n");
    in_traverse(head); printf("\n");
   

}
