//program sorting in c
#include <stdio.h>
#include <stdlib.h>

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