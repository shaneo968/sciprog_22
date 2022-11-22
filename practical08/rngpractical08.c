//Iterative and Recursive versions of Euclid's algorithm 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Function delaration for iterative and recursive
int iterativeGCD(int a, int b);
int recursiveGCD(int a, int b);

int main(){
    int a, b, ierror;
    clock_t start, end;

    //Generate two positive integers between 1 and 12
    srand(time(NULL));
    a=(rand()%12)+1;
    b=(rand()%12)+1;
    int x=(rand()/RAND_MAX);

    //Call the functions
    start=clock();
    printf("Iterative GCD(%d, %d)= %d\n", a, b, iterativeGCD(a,b));
    printf("Recursive GCD(%d, %d)= %d\n", a, b, recursiveGCD(a,b));
    end=clock();

    printf("Total time %.10f s\n", (double) (end-start)/CLOCKS_PER_SEC);

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