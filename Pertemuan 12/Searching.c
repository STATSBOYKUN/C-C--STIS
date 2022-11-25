// jump search in c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define CLEAR system("cls")

struct data
{
   int NIM;
   char name[20];
};

int min(int a, int b)
{
   if (a < b)
      return a;
   else
      return b;
}

int jumpSearch(struct data *arr, int n, int NIM)
{
   int step = sqrt(n);
   int prev = 0;

   while (arr[min(step, n) - 1].NIM < NIM)
   {
      prev = step;
      step += sqrt(n);

      if (prev >= n)
         return -1;
   }

   while (arr[prev].NIM < NIM)
   {
      prev++;
      if (prev == min(step, n))
         return -1;
   }

   if (arr[prev].NIM == NIM)
      return prev;
   
   return -1;
}

void insertData(struct data *arr, int n)
{
   int i;
   for (i = 0; i < n; i++)
   {
      printf("[Data ke-%d] \n", i + 1);

      printf("Masukkan NIM \t: ");
      scanf("%d", &arr[i].NIM);
      printf("Masukkan Nama \t: ");
      scanf("%s", &arr[i].name);

      printf("\n");
   }
}

void printData(struct data *arr, int n)
{
   int i;
   for (i = 0; i < n; i++)
   {
      printf("[Data ke-%d] \n", i + 1);
      printf("NIM \t: %d\n", arr[i].NIM);
      printf("Nama \t: %s\n", arr[i].name);

      printf("\n");
   }
}

int main()
{
   int n, NIM, index, choice;

   while (choice != 4)
   {
      CLEAR;
      printf("      [PROGRAM DATA MAHASISWA] \n");
      printf("====================================\n");
      printf("1. Insert Data\n");
      printf("2. Print Data\n");
      printf("3. Searching Data\n");
      printf("4. Exit\n");
      printf("====================================\n");
      printf("Pilih Menu : ");
      scanf("%d", &choice);

      switch (choice)
      {
         case 1:
            printf("Masukkan jumlah data : ");
            scanf("%d", &n);
            struct data *arr = (struct data *)malloc(n * sizeof(struct data));

            CLEAR;
            insertData(arr, n);
            break;
         case 2:
            printData(arr, n);
            break;
         case 3:
            printf("Masukkan NIM yang dicari : ");
            scanf("%d", &NIM);
            
            index = jumpSearch(arr, n, NIM);
            if (index == -1)
               printf("Data tidak ditemukan");
            else
               CLEAR;
               printf("Data ditemukan pada index ke-%d\n", index);

               printf("\n");
               printf("NIM \t: %d\n", arr[index].NIM);
               printf("Nama \t: %s\n", arr[index].name);
            break;
         case 4:
            printf("Terima Kasih");
            break;
         default:
            printf("Pilihan tidak tersedia"); 
      }
      getch();
   }

   return 0;
}