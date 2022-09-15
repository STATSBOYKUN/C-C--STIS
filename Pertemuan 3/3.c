#include<stdio.h>
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

   while(tebakAngka->tebakan != tebakAngka->angka){
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
   }

   printf("Anda telah menebak angka dalam %d kali", i);
   getch();
   return 0;
}