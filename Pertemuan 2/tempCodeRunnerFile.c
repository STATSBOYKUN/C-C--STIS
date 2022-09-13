#include<stdio.h>

int main(){
   int matriks[3][4];

   //matrix 3x4
   for (int i = 0; i <= 2; i++){
      for (int j = 0; j <= 3; j++){
         printf("Masukkan nilai matriks [%d][%d]: ", i, j);
         scanf("%d", &matriks[i][j]);
      }
   }

   //output
   printf("\n");
   printf("Matriks 3x4 : \n");
   for (int i = 0; i <= 2; i++){
      for (int j = 0; j <= 3; j++){
         printf("%d\t", matriks[i][j]);
      }
      printf("\n");
   }
   
   return 0;
}