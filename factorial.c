//Recursive way to find factorial


#include<stdio.h>

int fact(); //shows that C compiler doesnt take () as void. It takes undeclaration as indication that it can have innumerous arguments. In C++ fact() == fact(void)

void main(){
    int n = 4;
    printf("\n Factorial of %d is %d.\n", n, fact(n));
    return;
}

int fact(int n){
    if(n>1) return (n * fact(n-1));
    else return;
}


