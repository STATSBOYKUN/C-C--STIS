#include<stdio.h>
#include<string.h>
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
   int i;
   printf("Masukkan jumlah data yang akan diinput : ");
   scanf("%d", &i);
   for(int j=0; j<i; j++){
      printf("Masukkan NIM : ");
      scanf("%s", &mhs[j].nim);
      printf("Masukkan Nama : ");
      scanf("%s", &mhs[j].nama);
      printf("Masukkan Kelas : ");
      scanf("%s", &mhs[j].kelas);
      printf("Masukkan Jurusan : ");
      scanf("%s", &mhs[j].jurusan);
      printf("Masukkan No. WA : ");
      scanf("%s", &mhs[j].no_wa);
   }
}

void tampil(){
   int i;
   printf("Masukkan jumlah data yang akan ditampilkan : ");
   scanf("%d", &i);
   for(int j=0; j<i; j++){
      printf("NIM : %s ", mhs[j].nim);
      printf("Nama : %s ", mhs[j].nama);
      printf("Kelas : %s ", mhs[j].kelas);
      printf("Jurusan : %s ", mhs[j].jurusan);
      printf("No. WA : %s ", mhs[j].no_wa);
   }
}

void ubah(){
   int i;
   char nim[10];
   printf("Masukkan jumlah data yang akan diubah : ");
   scanf("%d", &i);
   for(int j=0; j<i; j++){
      printf("Masukkan NIM : ");
      scanf("%s", &nim);
      for(int k=0; k<10; k++){
         if(nim == mhs[k].nim){
            printf("Masukkan Nama : ");
            scanf("%s", &mhs[k].nama);
            printf("Masukkan Kelas : ");
            scanf("%s", &mhs[k].kelas);
            printf("Masukkan Jurusan : ");
            scanf("%s", &mhs[k].jurusan);
            printf("Masukkan No. WA : ");
            scanf("%s", &mhs[k].no_wa);
         }
      }
   }
}

void hapus(){
   int i;
   char cari[10];
   printf("Masukkan NIM yang akan dicari : ");
   scanf("%s", &cari);
   for(int j=0; j<i; j++){
      if(mhs[j].nim == cari){
         strcpy(mhs[j].nim, "");
         strcpy(mhs[j].nama, "");
         strcpy(mhs[j].kelas, "");
         strcpy(mhs[j].jurusan, "");
         strcpy(mhs[j].no_wa, "");
      }
   }
}

char cari(){
   int i;
   char cari[10];
   printf("Masukkan NIM yang akan dicari : ");
   scanf("%s", &cari);
   for(int j=0; j<i; j++){
      if(mhs[j].nim == cari){
         printf("NIM : %s ", mhs[j].nim);
         printf("Nama : %s ", mhs[j].nama);
         printf("Kelas : %s ", mhs[j].kelas);
         printf("Jurusan : %s ", mhs[j].jurusan);
         printf("No. WA : %s ", mhs[j].no_wa);
      }
   }
}

int main(){
   int pilih;

   printf("[PROGRAM CRUD MAHASISWA]\n");
   printf("========================\n");
   printf("1. Tambah Data\n");
   printf("2. Lihat Data\n");
   printf("3. Ubah Data\n");
   printf("4. Hapus Data\n");
   printf("5. Cari Data\n");
   printf("6. Keluar\n");
   printf("========================\n");

   while(pilih != 6){
      printf("Pilih menu: ");
      scanf("%d", &pilih);
      switch(pilih){
         case 1:
            printf("[Tambah Data]\n");
            tambah();
         case 2:
            printf("[Lihat Data]\n");
            tampil();
         case 3:
            printf("[Ubah Data]\n");
            ubah();
         case 4:
            printf("[Hapus Data]\n");
            hapus();
         case 5:
            printf("[Cari Data]\n");
            cari();
         case 6:
            printf("[Keluar]\n");
         default:
            printf("[Menu tidak tersedia]\n");
      }
   }

   printf("Terima kasih telah menggunakan program ini\n");
   return 0;
}

/*
Dibuat oleh :
  Nama    : Umar Hadi Pranoto
  NIM     : 222112404
  Sekolah : Politeknik Statistika STIS
*/