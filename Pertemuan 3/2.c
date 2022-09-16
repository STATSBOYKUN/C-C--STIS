#include<stdio.h>
#include<stdbool.h>
#include<conio.h>

#define CLEAR system("cls")
#define TRUE 1
#define FALSE 0
//calculator

struct calculator{
   float a;
   float b;
   float *hasil;
};

struct calculator kalkulatorSederhana;
int main(){
   char operator, opsi;
   bool ulang = true;
   float temp;

   while(ulang == TRUE){
      CLEAR;
      printf("[KALKULATOR SEDERHANA]\n");
      printf("======================\n");
      printf("Masukkan angka pertama \t: ");
      scanf("%f", &kalkulatorSederhana.a);
      printf("Masukkan angka kedua \t: ");
      scanf("%f", &kalkulatorSederhana.b);
      printf("Masukkan operator (+, -, *, /) : ");
      scanf("%s", &operator);

      switch(operator){
         case '+':
            temp = kalkulatorSederhana.a + kalkulatorSederhana.b;
            kalkulatorSederhana.hasil = &temp;
            break;
         case '-':
            temp = kalkulatorSederhana.a - kalkulatorSederhana.b;
            kalkulatorSederhana.hasil = &temp;
            break;
         case '*':
            temp = kalkulatorSederhana.a * kalkulatorSederhana.b;
            kalkulatorSederhana.hasil = &temp;
            break;
         case '/':
            temp = kalkulatorSederhana.a / kalkulatorSederhana.b;
            kalkulatorSederhana.hasil = &temp;
            break;
         default:
            printf("Operator tidak ditemukan");
            break;
      }

      printf("======================\n");
      printf("Hasil : %.2f\n\n", *kalkulatorSederhana.hasil);
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

/*
Dibuat oleh :
  Nama    : Umar Hadi Pranoto
  NIM     : 222112404
  Sekolah : Politeknik Statistika STIS
*/