#include <stdio.h>
#include <stdlib.h>

// membersihkan layar
#define CLEAR system("cls")

// membuat node
struct stack {
   int s;
   struct stack *prev;
};

// membuat stack baru
typedef struct stack *ptrStack;
ptrStack tumpukan = NULL;

//prototype
void push(int n);
int pop();
void decimalToBinary(int n);
void decimalToOctal(int n);
void display();

int main() {
   int n, pilihan; // variabel untuk menyimpan nilai n dan pilihan
   int ulang = 1; // variabel untuk mengulang program

   while (ulang == 1) {
      CLEAR;
      printf("[PROGRAM KONVERSI DESIMAL]\n");
      printf("==================================\n");
      printf(" 1. Desimal ke Biner\n");
      printf(" 2. Desimal ke Oktal\n");
      printf("==================================\n");
      printf(" Pilih : "); scanf("%d", &pilihan);

      // memilah pilihan
      if (pilihan == 1 || pilihan == 2) {
         printf(" Desimal \t: ");
         scanf("%d", &n); // mengambil nilai n
      }

      // memilah pilihan
      switch(pilihan){
         case 1:
            decimalToBinary(n);
            break;
         case 2:
            decimalToOctal(n);
            break;
         default:
            printf("Pilihan tidak tersedia");
      }
      printf("\n\n");
      printf("Ulangi program? (YA = 1, TIDAK = 0) : "); scanf("%d", &ulang);
   }
   
   return 0;
}

// fungsi untuk memasukkan data ke stack
void push(int n) {
   ptrStack new; // membuat node baru
   new = malloc(sizeof(struct stack)); // alokasi memori
   new->s = n; // mengisi data
   new->prev = tumpukan; // menghubungkan node baru dengan node sebelumnya
   tumpukan = new; // mengubah node sebelumnya menjadi node baru
}

// fungsi untuk mengeluarkan data dari stack
int pop() {
   ptrStack temp = tumpukan; // membuat node baru untuk menampung node sebelumnya
   int n = temp->s; // mengambil data dari node sebelumnya
   tumpukan = tumpukan->prev; // mengubah node sebelumnya menjadi node baru
   free(temp); // menghapus node sebelumnya
   return n; // mengembalikan data
}

// fungsi untuk konervsi ke biner dan menampilkan isi stack
void decimalToBinary(int n) {
   // memilah nilai n
   if (n == 0) {
      printf(" Biner \t\t: 0");
   } else if(n == -1){
      printf(" Biner \t\t: 111");
   } else {
      if (n < 0) {

      } else {
         printf(" Biner \t\t: 00");
      }
   }

   int sisa_bagi; // variabel untuk menyimpan sisa bagi
   if (n > 0) {
      for (int i = n; i > 0; i /= 2) { // membagi n sampai n = 0
         sisa_bagi = i%2; // mengambil sisa bagi
         push(sisa_bagi); // memasukkan sisa bagi ke stack
      }

      display(); // menampilkan isi stack
   }else{
      printf ("Menggunakan 1's complement\n");
      printf(" Biner \t\t: ");
      n = n * -1;
      for (int i = n; i > 0; i /= 2) { // membagi n sampai n = 0
         sisa_bagi = i%2; // mengambil sisa bagi
         push(sisa_bagi); // memasukkan sisa bagi ke stack
      }
      
      if (tumpukan == NULL) {
         printf("stack kosong\n");
      } else {
         while (tumpukan != NULL) {
            // mengambil dan menampilkan kebalikan isi data dari stack 
            if (pop() == 1)
               printf("0");
            else
               printf("1");
         }
      }

      printf("\n");

      printf("Menggunakan 2's complement\n");
      printf(" Biner \t\t: 11");

      n = n * -1;
      for (int i = n+1; i < 0; i /= 2) { // membagi n sampai n = 0
         sisa_bagi = i%2; // mengambil sisa bagi
         if(sisa_bagi == 0){ // jika sisa bagi = 0
            push(1); // memasukkan 1 ke stack
         } else{
            push(0); // memasukkan 0 ke stack
         }
      }

      display(); // menampilkan isi stack
   }
}

// fungsi untuk konversi ke oktal dan menampilkan isi stack
void decimalToOctal(int n){
   // memilah nilai n
   if (n == 0) {
      printf(" Oktal \t\t: 0");
   } else if(n < 0){
      printf(" Tidak bisa mengkonversi ke oktal");
   } else {
      printf(" Oktal \t\t: ");
   }

   int sisa_bagi; // variabel untuk menyimpan sisa bagi
   for (int i = n; i > 0; i /= 8) { // membagi n sampai n = 0
      sisa_bagi = i%8; // mengambil sisa bagi
      push(sisa_bagi); // memasukkan sisa bagi ke stack
   }

   if (n > 0) {
      display(); // menampilkan isi stack
   }
}

// menampilkan isi stack
void display() {
   if (tumpukan == NULL) {
      printf("Stack kosong\n");
   } else {
      // menampilkan isi stack dengan memanggil nilai fungsi pop
      while(tumpukan != NULL) { 
      printf("%d", pop());
      }
   }
}