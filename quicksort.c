//Quicksort

#include<stdio.h>
#include<stdlib.h>

//swap without using extra memory
void swap(int *p, int *q)
{
    *p = *p + *q;
    *q = *p - *q;
    *p = *p - *q;
    printf("\n swaped %d %d",*p,*q);
}

void quicksort(int A[], int min, int max)
{
    int pivot_loc= (int) ((rand()%(max-min)) + min);
    int pivot = A[pivot_loc];
    int left = min;
    int right = max;


    printf("\nroy:1 %d %d %d %d %d", A[0], A[1], A[2], A[3], A[4]);
    printf("\nroy:2 pivot %d, min = %d, max = %d\n", pivot, A[min], A[max]);
	  
    //partitioning
    while(left<right)
    {
	while (left<right && A[left]<pivot)
	{ 
	   left ++;
	} 
	//printf("left set to %d\n", A[left]);
	while (left <right && A[right] > pivot)
	{
	    printf("\n left %d right %d A[right] %d, pivot %d", left, right, A[right], pivot);
	    right --;
	}
	//printf("right set to %d\n", A[right]);
	printf("\n left %d right %d\n",left, right);
	if (left<right)
	{
	    swap(&A[left], &A[right]);
	}
    }
    printf("\nroy:3 %d %d %d %d %d", A[0], A[1], A[2], A[3], A[4]);
    if (left>min && min>0)
    {
	quicksort(A, min,left-1);
    }
    if (left <max && left>=0)
    {
	quicksort(A, left +1, max);
    }
}

void main()
{
    int i, A[5]= {2,1,5,4,7};
    int m = 2;
    int n = 9;
    printf("\n Enter 5 elements in the array to be sorted\n");
    for (i = 0; i<5; i++)
    {
	printf(" %d ", A[i]);
	//scanf("%d", &A[i]);
    }
    //swap(&m, &n);
    quicksort(A, 0, 4);
    printf("\nThe sorted array is : ");
     for (i = 0; i<5; i++)
    {
	printf(" %d ", A[i]);
    }
    return;
}

