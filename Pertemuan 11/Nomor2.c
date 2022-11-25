#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLEAR system("cls")
#define MAX 100 // ukuran maksimum array

struct data
{
   int nim;
   char nama[40];
};

void fill_data(struct data *data, int *size)
{ // mengisi data
   printf("Input ukuran array (max 100): ");
   scanf("%d", size);

   printf(" [INPUT DATA]\n");
   printf("==============\n");
   for (int i = 0; i < *size; i++)
   {
      printf("Data ke-%d\n", i + 1);
      printf("NIM\t: "); scanf("%d", &data[i].nim);
      printf("Nama\t: "); scanf("%s", &data[i].nama);

      printf("\n");
   }
}

int seq_search(struct data *data, int size)
{
   int choice2, ketemu = 0;
   int i, temp;
   printf("  [SEARCH DATA]\n");
   printf("=================\n");
   printf("1. Berdasarkan NIM\n");
   printf("2. Berdasarkan Nama\n");
   printf("=================\n");
   printf("Pilihan : "); scanf("%d", &choice2);

   switch(choice2) {
      case 1:
         int x;
         printf("Masukkan NIM yang dicari: "); scanf("%d", &x);
         for (i = 0; i < size; i++)
         {
            if (data[i].nim == x){
               ketemu = 1;
               break;
            }
         }
         
         if (ketemu == 1) {
            printf("Data ditemukan\n");
            printf("NIM\t: %d\n", data[i].nim);
            printf("Nama\t: %s\n", data[i].nama);
         } else {
            printf("Data tidak ditemukan\n");
         }

         break;
      case 2:
         char temp[40];
         printf("Masukkan Nama yang dicari: "); scanf("%s", &temp);
         for (i = 0; i < size; i++)
         {
            if (strcmp(data[i].nama, temp) == 0){
               ketemu = 1;
               break;
            }
         }
         
         if (ketemu == 1) {
            printf("Data ditemukan\n");
            printf("NIM\t: %d\n", data[i].nim);
            printf("Nama\t: %s\n", data[i].nama);
         } else {
            printf("Data tidak ditemukan\n");
         }
         break;
      default:
         printf("Pilihan tidak tersedia");
   }
}

void printData(struct data *data, int size)
{
   printf(" [DATA]\n");
   printf("================\n");
   for (int i = 0; i < size; i++)
   {
      printf("Data ke-%d\n", i + 1);
      printf("NIM \t: %d\n", data[i].nim);
      printf("Nama \t: %s\n", data[i].nama);
      printf("\n");
   }
}

void main()
{
   int x, choice, size;
   struct data *data = (struct data*)malloc(sizeof(struct data) * MAX);

   while (choice != 4){
      CLEAR;
      printf(" [LINEAR SEARCH]\n");
      printf("=================\n");
      printf("1. Input Data\n");
      printf("2. Search\n");
      printf("3. Print Data\n");
      printf("4. Exit\n");
      printf("=================\n");
      printf("Pilihan : "); scanf("%d", &choice);

      switch (choice)
      {
         case 1:
            CLEAR;
            fill_data(data, &size);
            break;
         case 2:
            CLEAR;
            seq_search(data, size);
            break;
         case 3:
            CLEAR;
            printData(data, size);
            break;
         case 4:
            printf("Terima kasih");
            break;
         default:
            printf("Pilihan tidak tersedia");
            break;
      }

      printf("\n");
      printf("Press any key to continue...");
      getch();
   }
}