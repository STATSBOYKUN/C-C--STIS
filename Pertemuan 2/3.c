#include<stdio.h>

int main(){
   //matrix
   
   for (int i = 0; i < 2; i++){
      for (int j = 0; j < 4; j++){
         printf("Masukkan nilai matriks [%d][%d]: ", i, j);
         scanf("%d", &matriks[i][j]);
      }
   }

   //output
   for (int i = 0; i < 2; i++){
      for (int j = 0; j < 4; j++){
         printf("%d ", matriks[i][j]);
      }
      printf("\n");
   }
   
   return 0;
}
