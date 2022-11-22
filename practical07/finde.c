/*
* Find e using taylor expansion series
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

//Fucntion to calculate factorial
int factorial(int n);

int main(void){
    int i, order;
    //Order will allow scanf
    double e, *terms;

    //Enter polynomial order
    printf("Please enter the required polynomial order\n");
    if(scanf("%d", &order) !=1){
        printf("Did not enter correct number");
        return 1;
    }

    //Allocate space for terms array..Dynamic Array
    terms=malloc(order*sizeof(double));
    for (i=0; i<order; i++){
        terms[i]=1.0/(double)factorial(i+1);
        printf("e term for order %d is %1.14lf\n", order, terms[i]);
    }
   //initialise e
    e=1.0;
    for(i=0; i<order; i++){
        e=e+terms[i];
    }
    
    //free dynamic array
    free(terms);

    printf("\n\ne is estimated as %.14lf, with difference %.14lf\n", e, fabs(e-exp(1.0)));

    return 0;
}

//Factorial Function
int factorial(int n){
    if (n<0){
        printf("Error: Entry should be a positive integer.");
        //If number added by user is negative, exit function
        return(-1);
    }
    else if(n==0){
        return 1;
        //If the entry is 0 then 0! = 1 so return 1
    }
    else{
        return(n*factorial(n-1));
        //Otherwise fulfill the function
    }
}
