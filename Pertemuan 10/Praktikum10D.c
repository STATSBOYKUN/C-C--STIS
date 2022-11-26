#include <stdio.h>
#include <stdlib.h>

#define CLEAR system("cls")
#define MAX 100

struct item
{
   int key;
   int value;
};

struct hashtable_item
{
   int flag;
   /*
    * flag = 0 : Tidak ada data
    * flag = 1 : Ada data
    * flag = 2 : Sebelumnya ada datanya
    * */
   struct item data;
};

struct hashtable_item array[MAX];
int max = 10;
int size = 0;

int size_of_hashtable();
int hashcode(int key);

void display();
void search(int key);
void remove_element(int key);
void insert(int key, int value);
void init_array();

int main()
{
   int i, choice, key, value;
   while (choice != 6)
   {
      CLEAR;
      printf("\n       [HASH TABLE OPERATIONS]");
      printf("\n =====================================");
      printf("\n 0. Initialize Array");
      printf("\n 1. Insert item in the Hash Table");
      printf("\n 2. Remove item from the Hash Table");
      printf("\n 3. Search item from the Hash Table");
      printf("\n 4. Display all elements of Hash Table");
      printf("\n 5. Size of Hash Table");
      printf("\n 6. Exit");
      printf("\n =====================================");
      printf("\n Enter your choice: ");
      scanf("%d", &choice);

      switch (choice)
      {
      case 0:
         init_array();
         printf("Jumlah data yang akan diinput : ");
         scanf("%d", &max);
         break;
      case 1:
         printf("Jumlah data yang akan diinput : ");
         scanf("%d", &max);
         for (i = 0; i < max; i++)
         {
            printf("\n Enter key -:\t");
            scanf("%d", &key);
            printf("\n Enter value -:\t");
            scanf("%d", &value);

            insert(key, value);
         }
         break;
      case 2:
         printf("\n Enter key -:\t");
         scanf("%d", &key);
         remove_element(key);
         break;
      case 3:
         printf("\n Enter key -:\t");
         scanf("%d", &key);
         search(key);
         break;
      case 4:
         display();
         break;
      case 5:
         printf("\n Size of Hash Table is -:%d \t", size_of_hashtable());
         break;
      case 6:
         exit(1);
         break;
      default:
         printf("\n Wrong choice, Please enter correct choice  ");
         break;
      }

      getch();
   }

   return 0;
}

void init_array()
{
   int i;
   for (i = 0; i < max; i++)
   {
      array[i].flag = 0;
   }
}

int hashcode(int key)
{
   return (key % max);
}

int size_of_hashtable()
{
   return size;
}

void insert(int key, int value)
{
   int index = hashcode(key);
   int i = index;
   int x = 1;

   struct item new_item;

   new_item.key = key;
   new_item.value = value;

   while (array[i].flag != 0)
   {
      if (array[i].flag == 2)
      {
         printf("Key sudah pernah diinput, namun telah dihapus");
         i = (index + (x * x)) % max;
      }

      if (array[i].data.key == key)
      {
         printf("\n Key already exists, hence updating its value \n");
         array[i].data.value = value;
         return;
      }

      i = (index + (x * x)) % max;
      x++;
      if (i == index)
      {
         printf("\n Hash table is full, cannot insert any more item \n");
         return;
      }
   }
   array[i].flag = 1;
   array[i].data = new_item;
   size++;
   printf("\n Key (%d) has been inserted \n", key);
}

void remove_element(int key)
{
   int index = hashcode(key);
   int i = index;
   int x = 1;

   while (array[i].flag != 0)
   {
      if (array[i].flag == 1 && array[i].data.key == key)
      {
         array[i].flag = 2;
         array[i].data.key = NULL;
         array[i].data.value = NULL;
         size--;
         printf("\n Key (%d) has been removed \n", key);
         return;
      }
      i = (index + (x * x)) % max;
      x++;
      if (i == index)
      {
         break;
      }
   }
   printf("\n This key does not exist \n");
}

void search(int key)
{
   int index = hashcode(key);
   int i = index;
   int x = 1;

   while (array[i].flag != 0)
   {
      if (array[i].flag == 1 && array[i].data.key == key)
      {
         printf("\n Key : %d, Value : %d \n", key, array[i].data.value);
         return;
      }

      i = (index + (x * x)) % max;
      x++;

      if (i == index)
      {
         break;
      }
   }
   printf("\n This key does not exist \n");
}

/* to display all the elements of hash table */
void display()
{
   int i;
   for (i = 0; i < max; i++)
   {
      if (array[i].data.key == NULL || array[i].data.value == NULL)
      {
         printf("\n Array[%d] has no elements \n", i);
      }
      else
      {
         printf("\n Array[%d] has elements -: \n %d(key) and %d(value) ", i, array[i].data.key, array[i].data.value);
      }
   }
}