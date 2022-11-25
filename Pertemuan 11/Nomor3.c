#include <stdio.h>
#include <stdlib.h>

#define CLEAR system("cls")

struct data {
   int nim;
   char nama[40];
   struct data *next;
};


void main()
{
   int x, choice, temp;

   while(choice != 4)
   {
      CLEAR;
      printf("  [MENU]\n");
      printf("================\n");
      printf("1. Input Data\n");
      printf("2. Search Data\n");
      printf("3. Cetak Data\n");
      printf("4. Exit\n");
      printf("================\n");
      printf("Pilihan : "); scanf("%d", &choice);

      switch(choice)
      {
         case 1:
            CLEAR;
            isi_data();
            break;
         case 2:
            CLEAR;
            printf("Input data yang ingin dicari: "); scanf("%d", &x);

            temp = search(x);
            if (temp == -1)
            {
               printf("Data tidak ditemukan!");
            }
            else
            {
               printf("Data ditemukan pada data ke-%d", temp);
            }
            break;
         case 3:
            CLEAR;
            cetak_data();
            break;
         case 4:
            CLEAR;
            bersihkan_memori();
            break;
         default:
            printf("Pilihan tidak tersedia!");
            break;
      }

      printf("Press any key to continue...");
      getch();
   }
}