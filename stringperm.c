#include<stdio.h>
#include<string.h>

int count = 0;
void stringperm(char *str, int index);

void main() {
    char str[100];
    int len;
    printf("\n****String Permutation****\nEnter the string: ");
    scanf("%s", str);
    len = strlen(str);
    printf("\nstring = %s; length = %d \n", str, len);
    stringperm(str, len-1);
    printf("No of permutations of %s is  %d. \n", str, count);
    return;
}

void stringperm(char *str, int index){
    int i=0, j=0;
    char last;
    for(j=0; j<=index; j++){
	//roation 
	last = str[index];
	for(i=index; i>0; i--){
	    str[i] = str[i-1];
	}
	str[0] = last;
	if(index == 1){
	    count++;
	    printf("Permutation %d = %s.\n", count, str);
	}
	stringperm(str, index-1);
    }
    return;
}



 

