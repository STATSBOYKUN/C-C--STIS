#include <stdio.h>
#define MAX 100 //ukuran maksimum array

void fill_data(int data[], int *size){ //mengisi data
   printf("Input ukuran array (max 100): ");
   scanf("%d", size);
   printf("Input data: ");
   for(int i=0;i<*size;i++){
      
   }
}

void tampil_data(int data[], int size){
   for(int i=0;i<size;i++) printf("%d ",data[i]);
   printf("\n");
}

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

void main(){
   int data[MAX];
   int size; //ukuran array yang dipakai

   fill_data(data,&size);
   insertionSort(data,size);
   
   printf("data setelah diurutkan:\n");
   tampil_data(data,size);
}