#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node
typedef struct node {
   char nama[20];
   int alpro;
   int kalkulus;
   struct node* next;
} mhs;

int count=0;

// Function to Create A New Node
mhs* newmhs(char a[], int alp, int kal) {
   mhs* temp = (mhs*)malloc(sizeof(mhs));
   strcpy(temp->nama, a);
   temp->alpro = alp;
   temp->kalkulus = kal;
   temp->next = NULL;
   return temp;
}

// menghapus pendaftar
void dequeue(mhs** head) {
   if ((*head)!=NULL){
      mhs* temp = *head;
      (*head) = (*head)->next;
      free(temp);
      count--;
   }
}

// Function to push according to priority
void enqueue(mhs** head,char n[], int alp, int kal) {
   mhs* temp = newmhs(n,alp,kal);

   if ((*head) == NULL) {  
      (*head) = temp;
   }else if ((*head)->alpro > alp) {
      temp->next = *head;
      (*head) = temp;
   } else if ((*head)->alpro == alp) { 
      mhs *start = (*head);

      while ((start != NULL) && (start->next->kalkulus < kal)) {
         start = start->next;
      }
      temp->next = start->next;
      start->next = temp;
   } else {

      mhs *start=(*head);
      while ((start != NULL) && (start->next->alpro < alp)) {
         start = start->next;
      }
      
      if (start->next->alpro == alp){
         while ((start != NULL) && (start->next->kalkulus <kal)) {
            start = start->next;
         }
      }

      temp->next = start->next;
      start->next = temp;
   }

   count++;
}

void display(mhs* head) {
   int noPendaftar = 1;
   if(head == NULL) {
      printf("Belum ada yang daftar\n");
   }else{
      while (count != 0) {
         printf("[ PENDAFTAR KE-%d ]\n", noPendaftar);
         printf("Nama\t\t:%s \nAlpro\t\t: %d \nKalkulus\t: %d\n", head->nama,head->alpro,head->kalkulus);
         head = head->next;
         count--;
         noPendaftar++;
      }
   }
}

int main() {
   mhs* wakil;

   enqueue(&wakil, "Eko", 50,20);
   enqueue(&wakil, "Budi", 50,20);
   enqueue(&wakil, "bambang", 60,20);
   enqueue(&wakil, "Eka", 60,20);
   enqueue(&wakil, "wawo", 60,20);
   enqueue(&wakil, "Ame", 60,30);

   display(wakil);

   return 0;
}
