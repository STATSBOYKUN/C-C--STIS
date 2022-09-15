#include<stdio.h>
#include<stdbool.h>
#include<conio.h>

#define CLEAR system("cls")
#define TRUE 1
#define FALSE 0
//calculator

struct calculator{
   float *a;
   float *b;
   float *hasil;
};

struct calculator *kalkulatorSederhana;
int main(){
   char operator, opsi;
   bool ulang = true;

   while(ulang == TRUE){
      CLEAR;
      printf("Kalkulator Sederhana\n");
      printf("Masukkan angka pertama : ");
      scanf("%.2f", &kalkulatorSederhana->a);
      printf("Masukkan angka kedua : ");
      scanf("%.2f", &kalkulatorSederhana->b);
      printf("Masukkan operator (+, -, *, /) : ");
      scanf("%s", &operator);

      switch(operator){
         case '+':
            *kalkulatorSederhana->hasil = kalkulatorSederhana->a + kalkulatorSederhana->b;
            break;
         case '-':
            kalkulatorSederhana->hasil = kalkulatorSederhana->a - kalkulatorSederhana->b;
            break;
         case '*':
            kalkulatorSederhana->hasil = kalkulatorSederhana->a * kalkulatorSederhana->b;
            break;
         case '/':
            kalkulatorSederhana->hasil = kalkulatorSederhana->a / kalkulatorSederhana->b;
            break;
         default:
            printf("Operator tidak ditemukan");
            break;
      }

      printf("Hasil : %.2f", kalkulatorSederhana->hasil);
      printf("Apakah anda ingin mengulang? (y/n) : ");
      scanf("%s", &opsi);
      if(opsi == 'y'){
         ulang = TRUE;
      }else{
         ulang = FALSE;
      }
   }

   return 0;
}
