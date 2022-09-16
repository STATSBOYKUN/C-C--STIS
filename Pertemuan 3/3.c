#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define CLEAR system("cls")
//tebak angka

struct tebakan{
   int angka;
   int tebakan;
};

struct tebakan *tebakAngka;

int main(){
   CLEAR;
   int i = 0;
   tebakAngka->angka = 17;

   do{
      CLEAR;
      printf("Tebak angka : ");
      scanf("%d", &tebakAngka->tebakan);

      if(tebakAngka->tebakan < tebakAngka->angka){
         printf("Angka terlalu kecil\n");
      }else if(tebakAngka->tebakan > tebakAngka->angka){
         printf("Angka terlalu besar\n");
      }else{
         printf("Selamat anda berhasil menebak angka\n");
      }
      i++;
   }while(tebakAngka->tebakan != tebakAngka->angka);

   printf("Anda telah menebak angka dalam %d kali", i);

   return 0;
}