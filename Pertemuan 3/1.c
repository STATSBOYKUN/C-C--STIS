#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<conio.h>

#define CLEAR system("cls")
#define TRUE 1
#define FALSE 0
//program CRUD mahasiswa

struct mahasiswa{
   char nim[10];
   char nama[50];
   char kelas[50];
   char jurusan[50];
   char no_wa[50];
};

struct mahasiswa mhs[10];

void tambah(){
   CLEAR;
   int i;

   printf("Masukkan jumlah data yang akan diinput : ");
   scanf("%d", &i);
   
   for(int j=0; j<i; j++){
      CLEAR;
      printf("[Data ke-%d]\n", j+1);

      printf("Masukkan NIM \t: ");
      scanf("%s", &mhs[j].nim);
      printf("Masukkan Nama \t: ");
      scanf("%s", &mhs[j].nama);
      printf("Masukkan Kelas \t: ");
      scanf("%s", &mhs[j].kelas);
      printf("Masukkan Jurusan \t: ");
      scanf("%s", &mhs[j].jurusan);
      printf("Masukkan No. WA \t: ");
      scanf("%s", &mhs[j].no_wa);
      getch();
   }
}

void tampil(){
   CLEAR;
   int i;
   printf("Masukkan jumlah data yang akan ditampilkan : ");
   scanf("%d", &i);

   for(int j=0; j<i; j++){
      CLEAR;
      printf("[Data ke-%d]\n", j+1);

      printf("NIM \t: %s \n", mhs[j].nim);
      printf("Nama \t: %s \n", mhs[j].nama);
      printf("Kelas \t: %s \n", mhs[j].kelas);
      printf("Jurusan \t: %s \n", mhs[j].jurusan);
      printf("No. WA \t: %s \n", mhs[j].no_wa);
      getch();
   }
}

void ubah(){
   CLEAR;
   int i;
   char nim[10];
   bool ketemu = FALSE;

   printf("Masukkan NIM \t: ");
   scanf("%s", &nim);
   for(int k=0; k<10; k++){
      if(strcmp(nim, mhs[k].nim) == 0){
         printf("Masukkan Nama \t: ");
         scanf("%s", &mhs[k].nama);
         printf("Masukkan Kelas \t: ");
         scanf("%s", &mhs[k].kelas);
         printf("Masukkan Jurusan \t: ");
         scanf("%s", &mhs[k].jurusan);
         printf("Masukkan No. WA \t: ");
         scanf("%s", &mhs[k].no_wa);
         ketemu = TRUE;
      }
   }

   if (ketemu == FALSE){
      printf("Data tidak ditemukan");
   }

   getch();
}

void hapus(){
   CLEAR;
   int i;
   char cari[10];
   bool ketemu = FALSE;

   printf("Masukkan NIM yang akan dicari : ");
   scanf("%s", &cari);
   for(int j=0; j<i; j++){
      if(strcmp(cari, mhs[j].nim) == 0){
         strcpy(mhs[j].nim, "");
         strcpy(mhs[j].nama, "");
         strcpy(mhs[j].kelas, "");
         strcpy(mhs[j].jurusan, "");
         strcpy(mhs[j].no_wa, "");
         ketemu = TRUE;
      }
   }

   if (ketemu == FALSE){
      printf("Data tidak ditemukan");
   }

   getch();
}

char cari(){
   CLEAR;
   int i;
   char cari[10];
   bool ketemu = FALSE;

   printf("Masukkan NIM yang akan dicari : ");
   scanf("%s", &cari);
   for(int j=0; j<i; j++){
      if(strcmp(cari, mhs[j].nim) == 0){
         printf("NIM \t: %s \n", mhs[j].nim);
         printf("Nama \t: %s \n", mhs[j].nama);
         printf("Kelas \t: %s \n", mhs[j].kelas);
         printf("Jurusan \t: %s \n", mhs[j].jurusan);
         printf("No. WA \t: %s \n", mhs[j].no_wa);
         ketemu = TRUE;
      }
   }

   if (ketemu == FALSE){
      printf("Data tidak ditemukan");
   }

   getch();
}

int main(){
   CLEAR;
   int pilih;
   bool ADA_DATA = FALSE;

   while(pilih != 6){
      CLEAR;
      printf("[PROGRAM CRUD MAHASISWA]\n");
      printf("========================\n");
      printf("1. Tambah Data\n");
      printf("2. Lihat Data\n");
      printf("3. Ubah Data\n");
      printf("4. Hapus Data\n");
      printf("5. Cari Data\n");
      printf("6. Keluar\n");
      printf("========================\n");

      printf("Pilih menu: ");
      scanf("%d", &pilih);
      switch(pilih){
         case 1:
            ADA_DATA = TRUE;
            printf("[Tambah Data]\n");
            tambah();
            break;
         case 2:
            if (ADA_DATA == FALSE){
               printf("Data masih kosong");
               getch();
               break;
            }
            printf("[Lihat Data]\n");
            tampil();
            break;
         case 3:
            if (ADA_DATA == FALSE){
               printf("Data masih kosong");
               getch();
               break;
            }
            printf("[Ubah Data]\n");
            ubah();
            break;
         case 4:
            if (ADA_DATA == FALSE){
               printf("Data masih kosong");
               getch();
               break;
            }
            printf("[Hapus Data]\n");
            hapus();
            break;
         case 5:
            if (ADA_DATA == FALSE){
               printf("Data masih kosong");
               getch();
               break;
            }
            printf("[Cari Data]\n");
            cari();
            break;
         case 6:
            printf("[Keluar]\n");
            break;
         default:
            printf("[Menu tidak tersedia]\n");
      }
   }

   printf("Terima kasih telah menggunakan program ini :)\n");
   return 0;
}

/*
Dibuat oleh :
  Nama    : Umar Hadi Pranoto
  NIM     : 222112404
  Sekolah : Politeknik Statistika STIS
*/