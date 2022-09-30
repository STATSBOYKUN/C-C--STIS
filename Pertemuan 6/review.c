#include<stdio.h>
#include<stdlib.h>

#define CLEAR system("cls")
struct node{
   int value;
   struct node *next;
   struct node *prev;
};
 
typedef struct node *ptrnode;
ptrnode head, tail;

int menu();
ptrnode createNode(int nilai);
void createList(ptrnode *head, ptrnode *tail);
void insert_tail(int nilai);
void remove_last();
void printList(ptrnode temp);
void reverse(ptrnode *head);

int main(){
   head = NULL;
   tail = NULL;

   head = (ptrnode)malloc(sizeof(struct node));
   tail = (ptrnode)malloc(sizeof(struct node));
    
   tail = head;

   while (menu() == 1){
      menu();
   }
}

int menu(){
   int pilihan, temp, temp2, ulang;
   CLEAR;

   printf("[PROGRAM DOUBLE LINKED LIST]\n");
   printf("====================================\n");
   printf("1. Create List\n");
   printf("2. Insert Tail\n");
   printf("3. Remove Last\n");
   printf("4. Print List\n");
   printf("5. Reverse List\n");
   printf("6. Exit\n");
   printf("====================================\n");

   printf("Pilihan (1-6) :  "); scanf("%d", &pilihan);

   switch(pilihan){
      case 1:
         createList(&head, &tail);
         break;
      case 2:
         printf("Masukkan nilai yang akan dimasukkan : "); scanf("%d", &temp);
         insert_tail(temp);
         break;
      case 3:
         remove_last();
         break;
      case 4:
         printList(head);
         break;
      case 5:
         reverse(&head);
         break;
      case 6:
         return 0;
         break;
      default:
         printf("Pilihan tidak ada!\n");
         break;
   }
   
   printf("\n");
   printf("Ulang program? (YES =1, NO = 0) : "); scanf("%d", &ulang);
   if (ulang == 1){
      return 1;
   }else{
      return 0;
   }
}

void createList(ptrnode *head, ptrnode *tail){
   int n, temp;

   printf("Banyak data : "); scanf("%d", &n);
   for(int i = 0;i < n;i++){
      printf("Input data ke - %d : ", i+1);
      if (i == 0){
         scanf("%d", &temp);
         *head = createNode(temp);
      }else{
         scanf("%d", &temp);
         insert_tail(temp);
      }
   }

}

ptrnode createNode(int nilai){
   ptrnode temp;
   temp = (ptrnode)malloc(sizeof(struct node));
   temp->value = nilai;
   temp->next = NULL;
   temp->prev = NULL;
    
   return(temp);
}

void insert_tail(int nilai){
   ptrnode new_node = createNode(nilai);

   if (head == NULL){
      head = new_node;
   }

   tail = head;
   while(tail->next != NULL){
      tail = tail->next;
   }

   tail->next = new_node;
   new_node->prev = tail;
   tail = new_node;  
}

void remove_last(){
   if(head == NULL){
      return(0);
   }

   ptrnode last = tail;
   tail = tail->prev;
   tail->next = NULL;
   last->prev = NULL;

   free(last);

}

void reverse(ptrnode *head){
   int i = 0;
   int temp_value[100];
   ptrnode temp = *head;
    
   while (temp != NULL){
      temp_value[i] = temp->value;
      temp = temp->next;
      i++;
   }
    
   if (temp != NULL){
      *head = temp->prev;
   }
   temp = *head;
    
   while (temp != NULL){
      temp->value = temp_value[i-1];
      temp = temp->next;
      i--;
   }
}

void printList(ptrnode temp){
   if (temp == NULL){
      printf("List kosong!\n");
   }else{
      while(temp != NULL){
         printf("Nilai : %d ;",temp->value);
         printf("Alamat : %d\n", &temp->value);
         temp = temp->next;
      }
   }
}