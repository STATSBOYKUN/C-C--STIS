#include <stdio.h>
#define MAX 100 // ukuran maksimum array

void fill_data(int data[], int *size)
{ // mengisi data
   printf("Input ukuran array (max 100): ");
   scanf("%d", size);
   printf("Input data: ");
   for (int i = 0; i < *size; i++)
   {
      scanf("%d", &data[i]);
   }
}

void tampil_data(int data[], int size)
{
   for (int i = 0; i < size; i++)
      printf("%d ", data[i]);
   printf("\n");
}

void swap(int *a, int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
}

void bubbleSort(int arr[], int n)
{
   int i, j, choice;
   printf("[BUBBLE SORT]\n");
   printf("===============\n");
   printf("1. Ascending\n");
   printf("2. Descending\n");
   printf("===============\n");
   printf("Pilih: ");
   scanf("%d", &choice);

   switch(choice)
   {
      case 1:
         for (i = 0; i < n - 1; i++)
         {
            for (j = 0; j < n - i - 1; j++)
            {
               if (arr[j] > arr[j + 1])
                  swap(&arr[j], &arr[j + 1]);
            }
         }
         break;
      case 2:
         for (i = 0; i < n - 1; i++)
         {
            for (j = 0; j < n - i - 1; j++)
            {
               if (arr[j] < arr[j + 1])
                  swap(&arr[j], &arr[j + 1]);
            }
         }
         break;
      default:
         printf("Pilihan tidak tersedia!\n");
         break;
   }
}

void main()
{
   int data[MAX];
   int size; // ukuran array yang dipakai
   fill_data(data, &size);
   bubbleSort(data, size);
   printf("data setelah diurutkan:\n");
   tampil_data(data, size);
}