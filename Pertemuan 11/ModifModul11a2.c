#include <stdio.h>
#include <stdlib.h>

#define CLEAR system("cls")

struct node
{
   int value;
   struct node *next;
};

typedef struct node *ptrnode;

ptrnode head = NULL;
int jumnode; // jumlah node

ptrnode insert(int nilai)
{
   ptrnode p, q;
   p = (ptrnode)malloc(sizeof(struct node));
   p->value = nilai;
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
   return (head);
}

void isi_data()
{
   int k;
   printf("Input jumlah data: ");
   scanf("%d", &jumnode);

   printf(" [INPUT DATA]\n");
   printf("==============\n");
   for (int j = 1; j <= jumnode; j++)
   {
      printf("Data ke-%d: ", j);
      scanf("%d", &k);
      head = insert(k);
   }
}

int search(int x)
{ // x adalah nilai yang dicari
   int j = 1, choice2;
   ptrnode tmp = head;
   
   printf("  [SEARCH DATA]\n");
   printf("====================\n");
   printf("1. Secara Ascending\n");
   printf("2. Secara Descending\n");
   printf("====================\n");
   printf("Pilihan : "); scanf("%d", &choice2);
   
   switch(choice2)
   {
      case 1:
         while (tmp != NULL)
         {
            if (tmp-> value > x)
            {
               return -1;
            }

            if (x == tmp->value)
            {
               return j;
            }
            else
            {
               tmp = tmp->next;
               j++;
            }
         }
         break;
      case 2:
         while (tmp != NULL)
         {
            if (tmp-> value < x)
            {
               return -1;
            }

            if (x == tmp->value)
            {
               return j;
            }
            else
            {
               tmp = tmp->next;
               j++;
            }
         }
         break;
      default:
         printf("Pilihan tidak tersedia!");
         break;
   }
}

void bersihkan_memori()
{
   while (head != NULL)
   {
      ptrnode tmp = head;
      head = head->next;
      tmp->next = NULL;
      free(tmp);
   }
}

void cetak_data()
{
   int j = 1;
   ptrnode tmp = head;
   printf(" [DATA YANG TERSIMPAN]\n");
   printf("=======================\n");
   while (tmp != NULL)
   {
      printf("Data ke-%d: %d \n", j, tmp->value);
      tmp = tmp->next;
      j++;
   }
}

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