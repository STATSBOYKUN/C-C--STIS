//selection sort
#include <stdio.h>
#define MAX 100 // ukuran maksimum dataay

void fill_data(int data[], int *size)
{ // mengisi data
   printf("Input ukuran dataay (max 100): ");
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

void selection_sort(int data[], int n)
{
   int i, j, min_idx, choice;
   printf("[SELECTION SORT]\n");
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
            min_idx = i;
            for (j = i + 1; j < n; j++)
            {
               if (data[j] < data[min_idx])
                  min_idx = j;
            }
            swap(&data[min_idx], &data[i]);
         }
         break;
      case 2:
         for (i = 0; i < n - 1; i++)
         {
            min_idx = i;
            for (j = i + 1; j < n; j++)
            {
               if (data[j] > data[min_idx])
                  min_idx = j;
            }
            swap(&data[min_idx], &data[i]);
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
   int size; // ukuran dataay yang dipakai
   fill_data(data, &size);
   selection_sort(data, size);
   printf("data setelah diurutkan:\n");
   tampil_data(data, size);
}