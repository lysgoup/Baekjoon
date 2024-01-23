#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int *square_num;
int c;
int *matrix;

void find_min_add(int num){
  if(square_num[c-1] == num){
    matrix[num] = 1;
    return;
  }

  for(int i=1;i<num+1;i++){
    int min = 1000;
    for(int j=0;j<c;j++){
      if(square_num[j] > i) break;
      if(matrix[i-square_num[j]] < min){
        min = matrix[i-square_num[j]];
      }
    }
    matrix[i] = min+1;
  }
}

int main(int argc, char *argv[]){
  int n;
  scanf("%d",&n);
  c = (int)sqrt((float)n);

  square_num = (int *)malloc(sizeof(int)*c);
  for(int i=0;i<c;i++){
    square_num[i] = (i+1)*(i+1);
  }
  matrix = (int *)malloc(sizeof(int)*n+1);
  
  find_min_add(n);
  printf("%d",matrix[n]);
}