// heaps in c
#include <stdio.h>
#include <stdlib.h>

#define CLEAR system("cls")
#define MAX 100

// return parent index
int parent(int i)
{
   return (i) / 2;
}

// return left child index
int left(int i)
{
   return (2 * i);
}

// return right child index
int right(int i)
{
   return (2 * i + 1);
}

// swap elements
void swap(int *p, int *q)
{
   int temp = *p;
   *p = *q;
   *q = temp;
}

/**
 * function to heapify the tree
 * 
 * @param a heap array
 * @param heapsize size of heap
 * @param data data to be inserted
 */
void insert(int a[], int heapsize, int data)
{
   int i;
   if (heapsize == MAX)
   {
      printf("Heap is full");
      return;
   }

   heapsize++;
   i = heapsize;
   a[i] = data;

   while (i != 1 && a[parent(i)] < a[i])
   {
      swap(&a[i], &a[parent(i)]);
      i = parent(i);
   }
   
}

/**
 * function to delete element from heap
 * 
 * @param a heap array
 * @param heapsize size of heap
*/
void delete(int a[], int heapsize)
{
   int max = a[1];
   swap(&a[1], &a[heapsize]);
   heapsize--;

   int i = 1;
   int maxIndex;
   
   while (i <= heapsize)
   {
      if (left(i) <= heapsize && right(i) <= heapsize)
      {
         if (a[left(i)] > a[right(i)])
         {
            maxIndex = left(i);
         }
         else
         {
            maxIndex = right(i);
         }
      }
      else if (left(i) <= heapsize)
      {
         maxIndex = left(i);
      }
      else if (right(i) <= heapsize)
      {
         maxIndex = right(i);
      }
      else
      {
         break;
      }

      if (a[i] < a[maxIndex])
      {
         swap(&a[i], &a[maxIndex]);
         i = maxIndex;
      }
      else
      {
         break;
      }
   }

   printf("Deleted element is %d", max);
}

/**
 * function to display heap 
 * 
 * @param a heap array
 * @param heapsize size of heap
 */
void display(int a[], int heapsize)
{
   int i;

   for (i = 1; i <= heapsize; i++)
   {
      printf("%d ", a[i]);
   }

   printf("\n");
}

int main()
{
   int heapsize = 0;
   int temp[MAX];
   int choice, data;

   while (choice != 4)
   {
      CLEAR;
      printf("\n       [HEAP OPERATIONS]");
      printf("\n =====================================");
      printf("\n 1. Insert item in the Heap");
      printf("\n 2. Delete item from the Heap");
      printf("\n 3. Display all elements of Heap");
      printf("\n 4. Exit");
      printf("\n =====================================");
      printf("\n Enter your choice: ");
      scanf("%d", &choice);

      switch (choice)
      {
      case 1:
         printf(" Input data : ");
         scanf("%d", &data);
         insert(temp, heapsize, data);
         heapsize++;
         break;
      case 2:
         if (heapsize == 0)
         {
            printf(" Heap is empty");
            break;
         }

         delete(temp, heapsize);
         heapsize--;
         break;
      case 3:
         if (heapsize == 0)
         {
            printf(" Heap is empty");
            break;
         }

         printf(" Heap : ");
         display(temp, heapsize);
         break;
      case 4:
         exit(0);
         break;
      default:
         printf(" Wrong choice");
      }
      
      printf("\nPress any key to continue...");
      getch();
   }
   return 0;
}