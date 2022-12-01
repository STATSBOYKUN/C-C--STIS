//program sorting in c
#include <stdio.h>
#include <stdlib.h>

#define CLEAR system("cls")

void insertData(int data[], int n){
   int i;
   for(i=0; i<n; i++){
      printf("Masukkan data ke-%d: ", i+1);
      scanf("%d", &data[i]);
   }
}

//swap
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//selection sort
void selection_sort(int arr[], int n)
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
               if (arr[j] < arr[min_idx])
                  min_idx = j;
            }
            swap(&arr[min_idx], &arr[i]);
         }
         break;
      case 2:
         for (i = 0; i < n - 1; i++)
         {
            min_idx = i;
            for (j = i + 1; j < n; j++)
            {
               if (arr[j] > arr[min_idx])
                  min_idx = j;
            }
            swap(&arr[min_idx], &arr[i]);
         }
         break;
      default:
         printf("Pilihan tidak tersedia!\n");
         break;
   }
}

//insertion sort
void insertionSort(int arr[], int n){
   int i, key, j, choice;

   printf("[INSERTION SORT]\n");
   printf("===============\n");
   printf("1. Ascending\n");
   printf("2. Descending\n");
   printf("===============\n");
   printf("Pilih: ");
   scanf("%d", &choice);

   switch(choice){
      case 1:
         for (i = 1; i < n; i++){
            key = arr[i];
            j = i - 1;
            while (j >= 0 && arr[j] > key){
               arr[j + 1] = arr[j];
               j = j - 1;
            }
            arr[j + 1] = key;
         }
         break;
      case 2:
         for (i = 1; i < n; i++){
            key = arr[i];
            j = i - 1;
            while (j >= 0 && arr[j] < key){
               arr[j + 1] = arr[j];
               j = j - 1;
            }
            arr[j + 1] = key;
         }
         break;
      default:
         printf("Pilihan tidak tersedia\n");
         break;
   }
}

//mergesort
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

//bubblesort
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

void display(int arr[], int n)
{
   int i;
   for (i = 0; i < n; i++)
      printf("%d ", arr[i]);
   printf("\n");
}

void main()
{
   int arr[] = {};
   int n, choice;

   while (choice != 5)
   {
      CLEAR;
      printf("[SORTING ALGORITHM]\n");
      printf("===================\n");
      printf("0. Insert Data\n");
      printf("1. Insertion Sort\n");
      printf("2. Merge Sort\n");
      printf("3. Bubble Sort\n");
      printf("4. Display\n");
      printf("5. Exit\n");
      printf("===================\n");
      printf("Pilih: ");
      scanf("%d", &choice);

      switch(choice)
      {
         case 0:
            CLEAR;
            printf("Masukkan banyak data: "); scanf("%d", &n);
            insertData(arr, n);
            break;
         case 1:
            CLEAR;
            insertionSort(arr, n);
            printf("Data berhasil diurutkan!\n");
            break;
         case 2:
            CLEAR;
            mergeSort(arr, 0, n - 1);
            printf("Data berhasil diurutkan!\n");
            break;
         case 3:
            CLEAR;
            bubbleSort(arr, n);
            printf("Data berhasil diurutkan!\n");
            break;
         case 4:
            CLEAR;
            display(arr, n);
            break;
         case 5:
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