//Linklist creation, traversal and deletion

#include<stdio.h>
#include<stdlib.h>

struct ll {
    int data;
    struct ll *next;
};

//Inserting a link in the end
void insert(struct ll *head, int data) {
    struct ll * new = NULL;
    new = (struct ll *)malloc(sizeof(struct ll));
    new->data = data;
    new->next = NULL;
    while (head->next != NULL){
	head = head->next;
    }
    printf("\nInserted %d", data);
    head->next = new;
}

//Recursive traverse
void traverse(struct ll *head){
    if (head == NULL){
	return;
    }
    printf("%d\n", head->data);
    traverse(head->next);
    return;
}

//Iterative traverse
void itr_traverse(struct ll **headp){
    
    printf("%d\n", (*headp)->data);
    while( (*headp)->next != NULL){
	*headp = (*headp)->next;
	printf("%d\n", (*headp)->data);
    }
    //printf("%d\n", (*headp)->data);
}

//Iterative delete
void itr_delete(struct ll **headp, int data){
    struct ll *temp = *headp;
    struct ll *this = *headp;
    while ((*headp) !=NULL){
	if ((*head)->data == data){
	    this = *headp;
	    *headp = (*headp)->next;
	    free(this);
	}
	else **headp = (*headp)->next;
    }
    *headp = temp;
}



	

//returns head after deletion
/*struct ll * delete(struct ll *head, int data){
    struct ll *temp1;
    struct ll *temp2;
    temp1 = head;
    if (head == NULL){
	return;
    }

#ifdef DEL
    if (temp1->data == data) {			//head to be deleted
	head = temp1->next;
	free(temp1);					//deletes
	return head;
    }
#endif

    while(temp1->next!=NULL || temp1->next->data != data){
	temp1 = temp1->next;
    }
    if (temp1->next == NULL || temp1->data != data){
	printf("\nNode %d doesnt exists in the list", data);
    }

#ifdef DEL
    if (temp1->next->data == data){
	temp2 = temp1->next;
	temp1->next = temp1->next->next;
	free(temp2); 					  //deletes
	return head;
    }
#endif

    return head;
}
*/
	

void main(){
    struct ll *head = NULL;
    head = (struct ll*)malloc(sizeof(struct ll));
    head->data = 5;
    head->next = NULL;
    insert(head, 6);
    insert(head, 7);  
    insert(head, 8);
    insert(head, 9);
    insert(head, 10);  
    insert(head, 11);
    traverse(head);
    printf("traverse 1 ok\n");
  //  temp = delete(head, 9);
    //itr_traverse(&temp);
   // printf("traverse 2 ok\n");
    itr_delete(&head, 5);
    printf("Delete okay\n");
    itr_traverse(&head);
    printf("traverse 3 ok");
    return;
}






