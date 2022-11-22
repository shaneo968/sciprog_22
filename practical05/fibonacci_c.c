#include<stdio.h>
#include<stdlib.h>

//Define function
//Function has two arguments n-1 and n-2 and output F(n) f(n-1)

void fibonacci(int *a, int *b);



int main(){
   int n, i;
   int f1=1, f0=0;
   
   printf("Enter a positive integer for n\n");
   scanf("%d", &n);
//Error checking
  if(n<1){
    printf("The number is not positive\n");
    exit(1);
  }

  printf("The fibonacci seequence is: \n"); 
  printf("%d, %d, ", f0, f1);
//Loop cycle to calculate values for the fibonacci sequence
  for(i=2; i<=n; i++){
     fibonacci(&f1, &f0);
     printf("%d, ", f1);
   

  if (((i+1)%10) == 0) printf("\n");

  }
  printf("\n");

  return 0;
}

//Declaration of the fibonnaci sequence function
void fibonacci(int *a, int *b){

   int next;
   //*a=f(n-1) *b=f(n-2) next will be f(n)
   next=*a+*b;
   //*a=f(n), *b=f(n-1)
   *b=*a;
   *a=next;

}

