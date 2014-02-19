//This program reverses a link list using 1. recursion 2. iterative
//The function reverse_ll is called by linklist.c
//Reversing pairwise like 1->2->3->4 should become 2->1->4->3


#include<stdio.h>
#include<stdlib.h>
#include "structlinklist.h"

//Reversing using recursion
struct ll *reverse_ll(struct ll *head)
{
    struct ll *rest=NULL;
    if( head==NULL || head->next == NULL)
	return head;
    rest = reverse_ll(head->next);
    head->next->next = head;
    head->next = NULL;
    head = rest;
    return head;

}
#if 1
//Reversing using iteration
struct ll *reverse_ll_iter(struct ll *head)
{
    struct ll *prev = NULL;
    struct ll *curr = head;
    struct ll *next = NULL;
    while(curr != NULL)
    {
	next = curr->next;
	curr->next = prev;
	prev = curr;
	curr = next;
    }
    //head = prev; 
    //return head;
    return prev;
}
#endif

//Reversing in pairs
void reverse_ll_pair(struct ll *head)
{
    int data;
    if (!head || !head->next)
	return;
    data = head->i;
    head->i = head->next->i;
    head->next->i = data;
    if (!head->next->next)
	return;
    reverse_ll_pair(head->next->next);
    return;
}
