//This program finds the maximum area accross bar chart
//Bar chart has bars of width 1 and heights given in an array
//For e.g A[]={2,4,1} has the 1st bar height of 2, 2nd bar height of 4 and 3rd of 1. Each have width 1.
// Max_area in this case will be 2 * 2 = 4 which is also equal to 4*1

#include<stdio.h>
#include<stdlib.h>

int max_area (int A[], int n)
{
    int i,j, k=0;
    int width = 1;
    int min_elem = 0;
    int maxarea = 0, curarea = 0;
    //check for pairs then triplets .. till n 
    for (i= 1; i<=n; i++) //keeps track of checking pairs or triplets or 4 together..till n 
    {
	for (j = 0; j < n-i+1; j++)
	{
	    min_elem = A[j];
	    for(k = j; k < (i+j); k++) {
		printf(" \n i = %d; j = %d ; k = %d ", i,j,k);
		if (A[k] < min_elem) { 
		    min_elem = A[k];
	//	    printf(" minelement is %d ", min_elem);
		}
		//else continue;
	    }
	    printf("\n min element = %d", min_elem);
	    curarea = min_elem * i;
	    //printf(" \n current area = min_element %d * i %d is %d ; maxarea = %d ",min_elem, i,curarea,maxarea);
	    if(curarea > maxarea)
		maxarea = curarea;
	    //else continue;
	}
    }
    printf ("\n Maxarea is %d", maxarea);
    return maxarea;
}

void main()
{
    int A[]={7,10,3,6,4,5};
    int i, maxarea=0;
    int size= sizeof(A)/4;
    printf("\n size is %d ", size);
    maxarea = max_area(A, size);
    printf("\nMax Area of ");
    for (i = 0; i<size; i++)
    {
	printf(" %d ", A[i]);
    }
    printf(" is %d.\n", maxarea);
    return;
}

