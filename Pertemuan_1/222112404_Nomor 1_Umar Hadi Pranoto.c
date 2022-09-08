#include<stdio.h>

int main(){
  char NIM[15], nama[30];
  int nilaiKuis, nilaiUTS, nilaiUAS;
  float nilaiAkhir;

  printf("[Program Nilai Mahasiswa]\n\n");
  printf("NIM \t: "); scanf("%s", &NIM);
  printf("Nama \t: "); scanf("%s", &nama);
  printf("Masukkan nilai kuis \t: "); scanf("%d", &nilaiKuis);
  printf("Masukkan nilai UTS \t: "); scanf("%d", &nilaiUTS);
  printf("Masukkan nilai UAS \t: "); scanf("%d", &nilaiUAS);

  nilaiAkhir = (nilaiKuis*0.2)+(nilaiUTS*0.3)+(nilaiUAS*0.5);
  printf("Nilai akhir anda adalah %.2f\n", nilaiAkhir);
  return 0;
   
  /*
  Dibuat oleh :
    Nama    : Umar Hadi Pranoto
    NIM     : 222112404
    Sekolah : Politeknik Statistika STIS
  */
}