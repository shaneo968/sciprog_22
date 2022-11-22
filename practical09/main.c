#include<stdio.h>
#include<stdlib.h>
#include "magicsquare.h"
#define MAX_FILE_NAME 100

//Read in file function to calculate the number of lines
int get_num_line(char filename[MAX_FILE_NAME]){

    FILE *fp;
    //Opens file
    fp = fopen(filename, "r");
    int ch_read;
    int count=0;
    while ((ch_read = fgetc(fp)) != EOF){
        if (ch_read == '\n'){
            count++;
        }
    }
    printf("Number of lines is %d\n", count);
    //Close file after oping it
    fclose(fp);
    return count;
}


int main(void){
//open file by user inputing the file name
    FILE *f;
    char filename[MAX_FILE_NAME];
    printf("Enter file name please: ");
    scanf("%s", filename);

    //Get number of lines
    int n=get_num_line(filename);
    //open file to compile the matrix
    f = fopen(filename, "r");

    //Make a 2 D array to store info
    int i;
    int **magicsquare = malloc(n * sizeof(int*));
    for (i=0; i < n; i ++){
        magicsquare[i] = malloc(n * sizeof(int));
    }

    int j;
    for (i=0; i<n; i++){
        for (j=0; j<n; j++){
            //fscanf to read from the file
            fscanf(f, "%d", &magicsquare[i][j]);
        }
    }
    //Read in function to determine is the square magic or not.
    int flag = isMagicSquare(magicsquare, n);
    if (flag ==1){
        printf("This square is magic!\n");
    }
    else{
        printf("this square is not magic!\n");
    }
    for (i=0; i<n; i++){
        free(magicsquare[i]);
    }
    free(magicsquare);
    fclose(f);
    return 0;
}
