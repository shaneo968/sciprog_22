#include<stdio.h>
#include<math.h>

int main(void){

  int N=12, i;
  float a=0.0, b_deg=60.0;
  float b_rad, area, mult_rad;

  /*Convert B__deg=pi/3 to radians */
  b_rad=(M_PI * b_deg)/180.0;
  printf("pi/3 in radians = %f\n", b_rad);

  /*Calculate intial area value Sum tan (a) +tan (b) in radians */
  area=tan(a)+tan(b_rad);

  /*Calculate the area with the bounds using loops,convert to radians*/
  for(i=5; i<60; i=i+5){
     area=area+2*tan((M_PI*i)/180.0);
  }
 
  /*Multiply the partial area by the (pi/3)/(2N) in radians first*/
  /* Required to have ((B_deg/2*N))) to ensure precidence*/
  mult_rad=(M_PI*((b_deg)/(2*N)))/180.0;
  area=mult_rad*area;

  printf("Approximated=%f, Exact=%f\n", area, logf(2.0));


   return 0;
}
