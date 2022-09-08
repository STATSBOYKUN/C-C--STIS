#include<stdio.h>

int fungsi_luas(int a, int b);
int fungsi_keliling(int a, int b);

int main(){
   printf("[Program Persegi Panjang]\n\n");
   
   int panjang, lebar, luas, keliling;
   printf("Masukkan panjang \t: "); scanf("%d", &panjang);
   printf("Masukkan lebar \t\t: "); scanf("%d", &lebar);
   
   printf("Luas persegi panjang adalah %d\n", fungsi_luas(panjang, lebar));
   printf("Keliling persegi panjang adalah %d\n", fungsi_keliling(panjang, lebar));

   return 0;
}

int fungsi_luas(int a, int b){
   return a*b;
}

int fungsi_keliling(int a, int b){
   return (a+b)*2;
}

/*
Dibuat oleh :
  Nama    : Umar Hadi Pranoto
  NIM     : 222112404
  Sekolah : Politeknik Statistika STIS
*/