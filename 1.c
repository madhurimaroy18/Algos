// Write an O(log2(N)) algorithm to find X^N
#include <stdio.h>
#include <stdlib.h>

int power(x,n)
{
    if (n<1)
    { 	
	return x;
    }

    if (n == 1)
    {
	return x;
    }
    if (n%2==0)
    {
	return power(x,n/2)* power(x,n/2);
    }
    else
    {
	return power(x,n/2)* power(x,n/2)*x;
    }
}

void main()
{
    int x, n, ans;
    printf("\nTo compute x^n \n Enter value x and n :");
    scanf("%d%d",&x,&n);
    ans = power(x,n);
    printf("\n %d^%d = %d \n", x,n,ans);
}
