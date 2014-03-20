/* Problem: Given a number list
   	      and a number
	      Find in which iteration it will get deleted.
Deletion criterion is in 1st iteration every 2nd number is deleted. In 2nd iteration every 3rd number is deleted and so on. */

#include<stdio.h>

int list[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30};
int itr=2;

void main(){
    int num = 15;  //number whose deletion iteration is to be found
    int i = 0, j = 0;
    iteration(num);
    i = (sizeof(list)/4)/2;

    printf("\nIteration %d, size of list %d",itr, i);
    return;
}

int iteration(int num){
    int i;
    for(i=1; i<=((sizeof(list)/4)/itr); i+itr){
	printf("\n Setting %d to NULL", list[i]);
	list[i]= 0;
    }


}
