#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node
typedef struct node {
   char nama[20];
   int alpro;
   int kalkulus;
} mhs;

int front, rear;

// menghapus pendaftar
void dequeue(mhs* head) {
   if (rear == -1){
      printf("Data mahasiswa masih kosong.");
      return;
   }

   if (front == rear){
      front = rear = -1;
   } else {
      for (int i=0; i<rear; i++){
         head[i] = head[i+1];
      }
      rear--;
      front = 0;
   }
}

// Function to push according to priority
void enqueue(mhs** head,char n[], int alp, int kal) {
   
   if (front == -1){
      front = 0;
   }else if ((*head).alpro > alp) {
      head[rear+1] = head[rear];
   } else if ((*head).alpro == alp) { 
      int i = rear;
      while (head[rear].kalkulus < kal) {
         i--;
      }
      head[i+1] = head[i];
   } else {
      int i = rear;
      while (head[rear].alpro < alp) {
         i--;
      }
      if (head[i].alpro == alp){
         while (head[rear].kalkulus < kal) {
            i--;
         }
      }
      head[i+1] = head[i];

   }
   
   count++;
   if (count == 6){
      dequeue(head);
      count == 5;
   }
}

void display(mhs* head) {
   int noPendaftar = 1;
   if(head == NULL) {
      printf("Belum ada yang daftar\n");
   }else{
      mhs* temp = head;
      for (int i = count-1; i >= 0; i--){
         for (int j = 0; j < i; j++){
            temp = temp.next;
         }

         printf("[ PENDAFTAR KE-%d ]\n", noPendaftar);
         printf("Nama\t\t:%s \nAlpro\t\t: %d \nKalkulus\t: %d\n", temp.nama,temp.alpro,temp.kalkulus);
         
         noPendaftar++;
         temp = head;
      }
   }
}

int main() {
   front = rear = -1;
   mhs wakil[5];

   enqueue(&wakil, "Eko", 50, 20);
   enqueue(&wakil, "Budi", 50, 20);
   enqueue(&wakil, "bambang", 60, 20);
   enqueue(&wakil, "Eka", 60, 20);
   enqueue(&wakil, "wawo", 60, 20);
   enqueue(&wakil, "Ame", 60, 30);

   // reverse(&wakil);
   display(wakil);

   return 0;
}
