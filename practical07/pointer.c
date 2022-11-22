#include<stdio.h>
#include<stdlib.h>

//Write function allocate array, takes int as argument
int *allocatearray(int n){
    int *p;
    p=(int *) malloc((n)*sizeof(int));
    if(p==NULL){printf("Error in alloacating memory\n");}
    return p; //Returns pointer
}

//Write function to fillwithones
void fillwithones(int *array, int n){
    int i; //Loop index
    for (i=0; i<n; i++){
        array[i]=1;
    }
}

//Print array fucntion
void printarray(int *array, int n){
    int i;
    for (i=0; i<n; i++){
        printf("a[%d]=%d\n", i, array[i]);
    }
}

//Deallocate the array
void freearray(int *array){
    free(array);
}

int main(){
    int length, *a;

    printf("Please enter size of the array\n");
    scanf("%d", &length);

    a=allocatearray(length);
    fillwithones(a, length);
    printarray(a, length);
    freearray(a);
    a=NULL;

    return 0;
}