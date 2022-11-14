#include<stdio.h>
#include<math.h>

//Functions defined before the main
float deg_to_rad(float degang);
float trap_rule(int N, float Tan_arr[N+1]);

int main() {

  int N=12, i;
  float Tan_arr[N+1] , deg, rad;

  for (i=0; i<=N; i++) {
    deg= i * 5.0;
//Calling a function outside the main
    rad = deg_to_rad(deg);
    Tan_arr[i] = tan(rad);
//Print all the area values for the points
    printf("Tan Array[%d]=%f (f(x) at x=%d)\n", i, Tan_arr[i],i);		
}

float area = trap_rule(N, Tan_arr);

printf("\nTrapezoidal approximation is %f\n", area);
printf("Real area is: %f\n", logf(2.0));

return 0;

}
//Define the functions that are outside the main block
float deg_to_rad(float degang){
   return((M_PI * degang)/180.0);
}

float trap_rule(int N, float Tan_arr[N+1]){
   float area;
   int i;
//find the area at the two end points   
   area=Tan_arr[0] + Tan_arr[N];
//Find the area at all other points twice as per the formula
   for (i=1; i<N; i++) {
    area = area + 2.0*Tan_arr[i];
}

float mult_rad = deg_to_rad((60.0-0.0)/(2.0*N));
area = mult_rad * area;

return area;

}


