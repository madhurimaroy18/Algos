
#include<stdio.h>
#include<stdlib.h>
#include "structlinklist.h"
#include<string.h>

void func_print(int i[20]){
    int j;
    int *p;
    printf("\n sizeof int  i[20] = %d", sizeof(i));
     printf("\n sizeof int = %d, int *p = %d", sizeof(int), sizeof(p));
    for(j = 0; j <20; j++){
	printf("\n i [%d] = %d", j, i[j]);
    }
}

int main()
{


    int i[10];
    int j;
    char *c;
    char a[] = "ch";
    char b[] = "this is a ch finding 2 ch string";
    for(j = 0; j <10; j++){
	i[j] = j;
    }
    func_print(i);
    c=b;
#if 0 
    while (*c != '\0'){
	c =strstr(c, a);
	if (c)	printf("\n match to ch in string b!");
	c++;
    }
#endif
    while (1) {
	c = strstr(c,a);
	if(c !=NULL){
	    printf("\n match!");
	    c++;
	    continue;
	}
	else
	    break;

    }
    return 0;
}
