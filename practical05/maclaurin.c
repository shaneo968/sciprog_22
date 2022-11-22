#include<stdio.h>
#include<math.h>

//Function declartion
double arctanh1(const double x, const double delta);

double arctanh2(const double x);

int main(){
  //User input for precision
  double delta, x;
  printf("Enter the precision for MacLaurin series\n");
  scanf("%lf", &delta);
  
  //Store the results in an array. 1 array to store arctanh1 and second for arctanh2
  int length=1000;
  double tan1[length]; 
  double tan2[length]; 

  int j=0; //array index, starts 0 to n-1
  x=-0.9; //initalise x
  while (x<=0.9 && j<length){
    tan1[j]=arctanh1(x,delta);
    tan2[j]=arctanh2(x);
    printf("The difference at x=%lf between them is %.10lf\n", x, fabs(tan1[j]-tan2[j]));
    //Updates array and array index
    j++;  
    x=x+0.01;
  }
  
  return 0;
}

//Defining MacLaurin series
double arctanh1(const double x, const double delta){
  double arcTan=0; // aproximated result
  double element, value; //value variable will replace 2n+1
  int n=0; //sum parameter

  do{
    value=(2*n)+1;
    element=pow(x,value)/value;
    arcTan +=element; //arcTan=arcTan+element
    n++;

  } while(fabs(element) >= delta);//stop series as it is infinite when the element is smaller than prescion 

  return arcTan;
}

//Defining the natural logarithms calculation
double arctanh2(const double x){

  return((log(1+x)-log(1-x))/2);


}