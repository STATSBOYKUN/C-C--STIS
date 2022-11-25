#include <stdio.h>
#include <stdlib.h>

#define CLEAR system("cls")
#define MAX 100 // ukuran maksimum array

void fill_data(int data[], int *size)
{ // mengisi data
   printf("Input ukuran array (max 100): ");
   scanf("%d", size);

   printf(" [INPUT DATA]\n");
   printf("==============\n");
   for (int i = 0; i < *size; i++)
   {
      printf("Data ke-%d: ", i + 1);
      scanf("%d", &data[i]);
   }
}

int seq_search(int nim[], int size, int x)
{
   int choice2;
   printf("  [SEARCH DATA]\n");
   printf("=================\n");
   printf("1. Secara Ascending\n");
   printf("2. Secara Descending\n");
   printf("=================\n");
   printf("Pilihan : "); scanf("%d", &choice2);

   switch (choice2)
   {
      case 1:
         for (int i = 0; i < size; i++)
         {
            if (nim[i] > x){
               return -1;
            }

            if (nim[i] == x)
               return i;
         }
         
         return -1;
         break;
      case 2:
         for (int i = 0; i < size; i++)
         {
            if (nim[i] < x){
               return -1;
            }

            if (nim[i] == x)
               return i;
         }

         return -1;
         break;
      default:
         printf("Pilihan tidak tersedia");
         break;
   }
}

void printData(int data[], int size)
{
   printf(" [DATA]\n");
   printf("========\n");
   for (int i = 0; i < size; i++)
   {
      printf("Data ke-%d: %d\n", i + 1, data[i]);
   }
}

void main()
{
   int data[MAX];
   int x, choice, size, temp;

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
            printf("nilai yang mau dicari: ");
            scanf("%d", &x);

            temp = seq_search(data, size, x);
            if (temp == -1)
               printf("Data %d tidak ditemukan", x);
            else
               printf("Data %d ditemukan pada indeks ke-%d", x, temp);
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