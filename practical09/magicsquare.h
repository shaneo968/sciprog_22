int isMagicSquare(int **square, const int n){
  //Error Checking
  if (n < 0){

     return 0;
  }
//intialise the varibles that we will be using for our arrays to calculate if a square is magic
  int magic_num=0;
  int off_diag_sum=0;
  int i,j;
  for (i = 0; i < n; i++){
//magic_num adds the diagonal values and off_diag_num for the off diagonal values
     magic_num += square[i][i];
     off_diag_sum += square[i][n - i - 1];
  }
  //Error checking if these are not the same, return 0, false
  if(off_diag_sum != magic_num){
    return 0;
  }
  //row sum and col sum are calculated using the variables below
  for (i=0; i < n; i++){
    int rowSum = 0;
    int colSum = 0;
    for (j=0; j < n; j++){
         rowSum += square[i][j];
         colSum += square[j][i];
        
    }
    //Error checking again tosay if rowsum doesnt equal magic num or if col sum doesnt equal magic num
    if (rowSum != magic_num || colSum != magic_num){

        return 0;
    }
   }
   return 1;
}