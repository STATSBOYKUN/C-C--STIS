#include<stdio.h>
#include<stdlib.h>
//linked list

struct node{
   int data;
   struct node *next;
};

struct node *head = NULL;

void insertFirst(int data);
void printList();

int main(){
   insertFirst(10);
   insertFirst(20);
   insertFirst(30);
   insertFirst(1);
   insertFirst(40);
   insertFirst(56);
   printList();
}

void insertFirst(int data){
   struct node *temp = (struct node*) malloc(sizeof(struct node));
   temp->data = data;
   temp->next = head;
   head = temp;
}

void printList(){
   int count = 0;
   struct node *ptr = head;
   printf("Isi list: ");
   while(ptr != NULL){
      printf("%d ",ptr->data);
      ptr = ptr->next;
      count++;
   }

   printf("Panjang list: %d", count);
}