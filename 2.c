//Program to select max_element from int pointer  

#include<stdio.h>
#include<stdlib.h>

void max_element( int *arr, int n)
{
    int i, max = *arr;
    for (i = 1; i< n; i++)
    {
	if (max < arr[i])
	    max = arr[i];
    }
    printf("\n %d \n", max);    
}

void main()
{
    int i[]= {2,4,1,6,4,7};
    int *arr = i;
    //printf("\n%d",sizeof(i));

    max_element(arr, sizeof(i)/4);
    
}

