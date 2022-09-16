#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

#define CLEAR system("cls")
//tebak angka

struct tebak2an{
   int angka;
   int tebakan;
};

int main(){
   CLEAR;
   struct tebak2an *tebakAngka = (struct tebak2an*)malloc(sizeof(struct tebak2an));
   int i = 0;
   
   tebakAngka->angka = 1 + rand() % 1000;

   do{
      CLEAR;
      printf("Tebak angka(1-1000) : ");
      scanf("%d", &tebakAngka->tebakan);

      if(tebakAngka->tebakan < tebakAngka->angka){
         printf("Angka terlalu kecil\n");
      }else if(tebakAngka->tebakan > tebakAngka->angka){
         printf("Angka terlalu besar\n");
      }else{
         printf("Selamat anda berhasil menebak angka\n");
      }
      getch();
      i++;
   }while(tebakAngka->tebakan != tebakAngka->angka);

   printf("Anda telah menebak angka dalam %d kali", i);

   return 0;
}

/*
Dibuat oleh :
  Nama    : Umar Hadi Pranoto
  NIM     : 222112404
  Sekolah : Politeknik Statistika STIS
*/