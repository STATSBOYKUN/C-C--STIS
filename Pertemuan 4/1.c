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
   int n;

   printf("Linked List\n");
   printf("Banyak data : "); scanf("%d", &n);

   for(int i=0; i<n; i++){
      int data;
      printf("Data ke-%d : ", i+1); scanf("%d", &data);
      insertFirst(data);
   }
   
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