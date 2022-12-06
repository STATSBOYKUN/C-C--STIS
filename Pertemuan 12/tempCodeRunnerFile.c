// merge sort
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

void mergeAscending(int arr[], int l, int m, int r)
{
   int i, j, k;
   int n1 = m - l + 1;
   int n2 = r - m;

   /* buat array sementara */
   int L[n1], R[n2];
   for (i = 0; i < n1; i++)
      L[i] = arr[l + i];
   for (j = 0; j < n2; j++)
      R[j] = arr[m + 1 + j];
   
   /* gabungkan array sementara kembali ke arr[l..r]*/
   i = 0; // index pertama array sementara L[]
   j = 0; // index pertama array sementara R[]
   k = l; // index awal gabungan array

   while (i < n1 && j < n2)
   {
      if (L[i] <= R[j])
      {
         arr[k] = L[i];
         i++;
      }
      else
      {
         arr[k] = R[j];
         j++;
      }
      k++;
   }

   /* copy elemen yang tersisa dari L[], jika ada */
   while (i < n1)
   {
      arr[k] = L[i];
      i++;
      k++;
   }
}

void mergeDescending(int arr[], int l, int m, int r)
{
   int i, j, k;
   int n1 = m - l + 1;
   int n2 = r - m;

   /* buat array sementara */
   int L[n1], R[n2];
   for (i = 0; i < n1; i++)
      L[i] = arr[l + i];
   for (j = 0; j < n2; j++)
      R[j] = arr[m + 1 + j];
   
   /* gabungkan array sementara kembali ke arr[l..r]*/
   i = 0; // index pertama array sementara L[]
   j = 0; // index pertama array sementara R[]
   k = l; // index awal gabungan array

   while (i < n1 && j < n2)
   {
      if (L[i] >= R[j])
      {
         arr[k] = L[i];
         i++;
      }
      else
      {
         arr[k] = R[j];
         j++;
      }
      k++;
   }

   /* copy elemen yang tersisa dari L[], jika ada */
   while (i < n1)
   {
      arr[k] = L[i];
      i++;
      k++;
   }
}

void mergeSort(int arr[], int l, int r)
{
   int choice;

   printf("[MERGE SORT]\n");
   printf("===============\n");
   printf("1. Ascending\n");
   printf("2. Descending\n");
   printf("===============\n");
   printf("Pilih: ");
   scanf("%d", &choice);

   switch(choice)
   {
      case 1:
         if (l < r)
         {
            int m = l + (r - l) / 2;
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            mergeAscending(arr, l, m, r);
         }
         break;
      case 2:
         if (l < r)
         {
            int m = l + (r - l) / 2;
            mergeSort(arr, l, m);
            mergeSort(arr, m + 1, r);
            mergeDescending(arr, l, m, r);
         } 
         break;
   }
}

void main()
{
   int data[MAX];
   int size; // ukuran array yang dipakai
   fill_data(data, &size);
   mergeSort(data, 0, size - 1);
   printf("data setelah diurutkan:\n");
   tampil_data(data, size);
}
