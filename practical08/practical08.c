//Iterative and Recursive versions of Euclid's algorithm 
#include<stdio.h>

//Function delaration for iterative and recursive
int iterativeGCD(int a, int b);
int recursiveGCD(int a, int b);

int main(){
    int a, b, ierror;

    printf("Please input two positive values:\n");
    ierror=scanf("%d %d", &a, &b);
    if (ierror != 2){
        printf("Please enter two integers\n");
        return 1;
    }
    if (a<=0 || b<=0){
        printf("These numbers are not positive.\n");
        return 1;
    }

    //Call the functions
    printf("Iterative GCD(%d, %d)= %d\n", a, b, iterativeGCD(a,b));
    printf("Recursive GCD(%d, %d)= %d\n", a, b, recursiveGCD(a,b));

    return 0;
}

//Function definition
int iterativeGCD(int a, int b){
    int temp; //temporary variable
    while(b != 0){
        temp = b; //assogn b value to temp variable
        b=a%b; //assign remainder to b
        a=temp; 
    }
    return a;
}

int recursiveGCD(int a, int b){
    if (b==0){
        return a;
    }
    else{
        return(recursiveGCD(b, a%b));
    }
}