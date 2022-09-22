#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//linked list

struct node{
   int nim;
   char nama[50];
   struct node *next;
};

struct node *head = NULL;

void insertFirst(int data, char nama[]);
void printList();

int main(){
   int n, nim;
   char nama[50];

   printf("Linked List\n");
   printf("Banyak data : "); scanf("%d", &n);

   for(int i=0; i<n; i++){
      int data;
      printf("Data ke-%d : ", i+1);
      printf("NIM : "); scanf("%d", &nim);
      printf("Nama : "); scanf("%s", &nama);

      insertFirst(nim, nama);
   }
   
   printList();
}

void insertFirst(int data, char nama[]){
   struct node *temp = (struct node*) malloc(sizeof(struct node));
   temp->nim = data;
   strcpy(temp->nama, nama);
   
   temp->next = head;
   head = temp;
}

void printList(){
   struct node *ptr = head;

   printf("Isi list: ");
   while(ptr != NULL){
      printf("NIM : %d ",ptr->nim);
      printf("Nama : %s ",ptr->nama);
      ptr = ptr->next;
   }
}