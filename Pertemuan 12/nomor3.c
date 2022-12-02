//program sorting in c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLEAR system("cls")

struct data{
   int nim;
   char nama[50];
   int nilai;
};

void insertData(struct data *data, int n){
   int i;
   for (i = 0; i < n; i++)
   {
      printf("[Data ke-%d]", i+1);
      printf("NIM: ");
      scanf("%d", &data[i].nim);
      printf("Nama: ");
      scanf("%s", &data[i].nama);
      printf("Nilai: ");
      scanf("%d", &data[i].nilai);
   }
}

//swap
void swapInt(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapChar(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

//selection sort
void selectionSort(struct data *data, int n)
{
   int i, j, min_idx, choice, choice2;
   printf("[SELECTION SORT]\n");
   printf("===============\n");
   printf("1. Berdasarkan NIM\n");
   printf("2. Berdasarkan Nama\n");
   printf("3. Berdasarkan Nilai\n");
   printf("===============\n");
   printf("Pilih: ");
   scanf("%d", &choice);
   CLEAR;

   switch(choice){
      case 1 :
         printf("  [PENGURUTAN]\n");
         printf("===============\n");
         printf("1. Ascending\n");
         printf("2. Descending\n");
         printf("===============\n");
         printf("Pilih: ");
         scanf("%d", &choice2);

         switch(choice2){
            case 1 :
               for (i = 0; i < n - 1; i++)
               {
                  min_idx = i;
                  for (j = i + 1; j < n; j++)
                  {
                     if (data[j].nim < data[min_idx].nim)
                        min_idx = j;
                  }
                  swapInt(&data[min_idx].nim, &data[i].nim);
               }
               break;
            case 2 :
               for (i = 0; i < n - 1; i++)
               {
                  min_idx = i;
                  for (j = i + 1; j < n; j++)
                  {
                     if (data[j].nim > data[min_idx].nim)
                        min_idx = j;
                  }
                  swapInt(&data[min_idx].nim, &data[i].nim);
               }
               break;
            default :
               printf("Pilihan tidak tersedia!\n");
               break;
         }
         break;
      case 2 :
         printf("  [PENGURUTAN]\n");
         printf("===============\n");
         printf("1. Ascending\n");
         printf("2. Descending\n");
         printf("===============\n");
         printf("Pilih: ");
         scanf("%d", &choice2);

         switch(choice2){
            case 1 :
               for (i = 0; i < n - 1; i++)
               {
                  min_idx = i;
                  for (j = i + 1; j < n; j++)
                  {
                     if (strcmp(data[j].nama, data[min_idx].nama) < 0)
                        min_idx = j;
                  }
                  swapChar(&data[min_idx].nama, &data[i].nama);
               }
               break;
            case 2 :
               for (i = 0; i < n - 1; i++)
               {
                  min_idx = i;
                  for (j = i + 1; j < n; j++)
                  {
                     if (strcmp(data[j].nama, data[min_idx].nama) > 0)
                        min_idx = j;
                  }
                  swapChar(&data[min_idx].nama, &data[i].nama);
               }
               break;
            default :
               printf("Pilihan tidak tersedia!\n");
               break;
         }
         break;
      case 3 :
         printf("  [PENGURUTAN]\n");
         printf("===============\n");
         printf("1. Ascending\n");
         printf("2. Descending\n");
         printf("===============\n");
         printf("Pilih: ");
         scanf("%d", &choice2);

         switch(choice2){
            case 1 :
               for (i = 0; i < n - 1; i++)
               {
                  min_idx = i;
                  for (j = i + 1; j < n; j++)
                  {
                     if (data[j].nilai < data[min_idx].nilai)
                        min_idx = j;
                  }
                  swapInt(&data[min_idx].nilai, &data[i].nilai);
               }
               break;
            case 2 :
               for (i = 0; i < n - 1; i++)
               {
                  min_idx = i;
                  for (j = i + 1; j < n; j++)
                  {
                     if (data[j].nilai > data[min_idx].nilai)
                        min_idx = j;
                  }
                  swapInt(&data[min_idx].nilai, &data[i].nilai);
               }
               break;
            default :
               printf("Pilihan tidak tersedia!\n");
               break;
         }
         break;
      default :
         printf("Pilihan tidak tersedia!\n");
         break;
   }
}

void display(struct data *data, int n){
   int i;
   for (i = 0; i < n; i++)
   {
      printf("[DATA KE-%d]\n", i+1);
      printf("NIM\t: %d\n", data[i].nim);
      printf("Nama\t: %s\n", data[i].nama);
      printf("Nilai\t: %d\n", data[i].nilai);
   }
}

void main()
{
   struct data *arr = NULL;
   int n, choice;

   while (choice != 5)
   {
      CLEAR;
      printf("[SORTING ALGORITHM]\n");
      printf("===================\n");
      printf("1. Insert Data\n");
      printf("2. Sort Data\n");
      printf("3. Display\n");
      printf("4. Exit\n");
      printf("===================\n");
      printf("Pilih: ");
      scanf("%d", &choice);

      switch(choice)
      {
         case 1:
            CLEAR;
            printf("Masukkan banyak data: "); scanf("%d", &n);
            insertData(arr, n);
            break;
         case 2:
            CLEAR;
            selectionSort(arr, n);
            printf("Data berhasil diurutkan!\n");
            break;
         case 3:
            CLEAR;
            display(arr, n);
            break;
         case 4:
            CLEAR;
            exit(0);
            break;
         default:
            printf("Pilihan tidak tersedia!\n");
            break;
      }
   
      printf("Press any key to continue...");
      getch();
   }
}