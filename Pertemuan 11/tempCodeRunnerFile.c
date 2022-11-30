#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLEAR system("cls")

struct data {
   int nim;
   char nama[40];
   struct data *next;
};

typedef struct data *ptrdata;
ptrdata head = NULL;

void insert(int nim, char nama[40])
{
   ptrdata p, q;
   p = (ptrdata)malloc(sizeof(struct data));
   p->nim = nim;
   strcpy(p->nama, nama);
   p->next = NULL;

   if (head == NULL)
   {
      head = p;
      q = head;
   }
   else
   {
      q = head;
      while (q->next != NULL)
      {
         q = q->next;
      }
      q->next = p;
   }
}

void isi_data()
{
   int k, temp;
   char n[40];
   printf("Input jumlah data: ");
   scanf("%d", &k);

   printf(" [INPUT DATA]\n");
   printf("==============\n");
   for (int j = 1; j <= k; j++)
   {
      printf("Data ke-%d\n", j);
      printf("NIM\t: "); scanf("%d", &temp);
      printf("Nama\t: "); scanf("%s", &n);
      insert(temp, n);
   }
}

void search(int x)
{ // x adalah nilai yang dicari
   int j = 1, choice2;
   ptrdata tmp = head;

   printf("  [SEARCH DATA]\n");
   printf("=================\n");
   printf("1. Berdasarkan NIM\n");
   printf("2. Berdasarkan Nama\n");
   printf("=================\n");
   printf("Pilihan: "); scanf("%d", &choice2);

   switch(choice2)
   {
      case 1:
         while (tmp != NULL)
         {
            if (tmp->nim == x)
            {
               printf("Data ke-%d ditemukan!\n", j);
               printf("NIM\t: %d\n", tmp->nim);
               printf("Nama\t: %s\n", tmp->nama);
               break;
            }
            else
            {
               tmp = tmp->next;
               j++;
            }

            if (tmp == NULL)
            {
               printf("Data tidak ditemukan!\n");
            }
         }
         break;
      case 2:
         while (tmp != NULL)
         {
            if (strcmp(tmp->nama, x) == 0)
            {
               printf("Data ke-%d ditemukan!\n", j);
               printf("NIM\t: %d\n", tmp->nim);
               printf("Nama\t: %s\n", tmp->nama);
               break;
            }
            else
            {
               tmp = tmp->next;
               j++;
            }

            if (tmp == NULL)
            {
               printf("Data tidak ditemukan!\n");
            }
         }
         break;
      default:
         printf("Pilihan tidak tersedia!\n");
         break;
   }
}

void bersihkan_memori()
{
   ptrdata tmp = head;
   while (tmp != NULL)
   {
      tmp = tmp->next;
      free(head);
      head = tmp;
   }
}

void cetak_data()
{
   int j = 1;
   ptrdata tmp = head;

   printf("  [CETAK DATA]\n");
   printf("================\n");
   while (tmp != NULL)
   {
      printf("Data ke-%d\n", j);
      printf("NIM\t: %d\n", tmp->nim);
      printf("Nama\t: %s\n", tmp->nama);
      tmp = tmp->next;
      j++;
   }
}

void main()
{
   int x, choice;

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

            search(x);
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