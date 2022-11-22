#include<stdio.h>
#include<stdlib.h>

void hanoi(int n, int source, int destination, int inter){
    //Base cases
    //If we have only 1 disc move from source to destination
    if (n==1){
        printf("Move disc from %d to %d \n", source, destination);
    }
    //Recursion part
    else{
        hanoi(n-1, source, inter, destination);
        printf("Move disc from %d to %d\n", source, destination);
        hanoi(n-1, inter, destination, source);
        
    }
}


int main (void){
    int h;
    //User input for h
    printf("Give a number of discs required\n");
    scanf("%d", &h);
    //Print Solution for the moves
    printf("Solution for disc %d discs\n", h);
    hanoi(h,1,3,2);
    return 0;
}