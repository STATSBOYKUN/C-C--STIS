#include<stdio.h>
#include<stdlib.h>
 
struct node{
   int value;
   struct node *next;
   struct node *prev;
};
 
typedef struct node *ptrnode;
ptrnode head, tail;
 
ptrnode createNode(int nilai);
void insert_head(int nilai);
void insert_tail(int nilai);
void insert_after(int nilai, int nilai_dicari);
void insert_before(int nilai, int nilai_dicari);
void remove_first();
void remove_last();
void remove_middle(int nilai);
void printList(ptrnode temp);
 
int main(){
   int n, temp;
   head = NULL;
   tail = NULL;
    
   head = (ptrnode)malloc(sizeof(struct node));
   tail = (ptrnode)malloc(sizeof(struct node));
    
   tail = head;
   printf("Banyak data : "); scanf("%d", &n);
   for(int i = 0;i < n;i++){
      printf("Input data ke - %d : ", i+1);
      if (i == 0){
         scanf("%d", &temp);
         head = createNode(temp);
      }else{
         scanf("%d", &temp);
         insert_tail(temp);
      }
   }
   
   printf("\n");
   printf("List sebelum remove_last: \n");
   printList(head);

   remove_last();

   printf("\n");
   printf("List setelah remove_last: \n");
   printList(head);
}
 
ptrnode createNode(int nilai){
   ptrnode temp;
   temp = (ptrnode)malloc(sizeof(struct node));
   temp->value = nilai;
   temp->next = NULL;
   temp->prev = NULL;
    
   return(temp);
}

void insert_head(int nilai){
   ptrnode new_node = createNode(nilai);

   new_node->next = head;
   head->prev = new_node;
   head = new_node;
}

void insert_tail(int nilai){
   ptrnode new_node = createNode(nilai);

   tail = head;
   while(tail->next != NULL){
      tail = tail->next;
   }

   tail->next = new_node;
   new_node->prev = tail;
   tail = new_node;  
}

void insert_after(int nilai, int nilai_dicari){
   ptrnode cursor = head;
   while(cursor->value != nilai_dicari){
      cursor = cursor->next; 
   }

   ptrnode new_node = createNode(nilai);
   new_node->next = cursor->next;
   cursor->next->prev = new_node;
   new_node->prev = cursor;
   cursor->next = new_node;
}

void insert_before(int nilai, int nilai_dicari){ 
   if (head->value == nilai_dicari){
      insert_head(nilai);
   }else{
      ptrnode cursor = head;
      while(cursor->value != nilai_dicari){
         cursor = cursor->next;
      }
     
      ptrnode new_node = createNode(nilai);
      new_node->prev = cursor->prev;
      cursor->prev->next = new_node;
      new_node->next = cursor;
      cursor->prev = new_node;   
   }
}

void remove_first(){
   if(head == NULL){
      return(0);
   }

   ptrnode first = head;
   head = head->next;
   head->prev = NULL;
   first->next = NULL;

   free(first);

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

void remove_middle(int nilai){
   ptrnode cursor = head;
   while(cursor != NULL){
      if(cursor->next->value == nilai){
         break;
      }
      cursor = cursor->next; 
   }

   if(cursor != NULL){
      ptrnode tmp = cursor->next;
      cursor->next = tmp->next;
      tmp->next->prev = cursor;
      tmp->next = NULL;
      tmp->prev = NULL;
      free(tmp);
   }
}

void printList(ptrnode temp){
   while(temp != NULL){
      printf("Nilai : %d ;",temp->value);
      printf("Alamat : %d\n", &temp->value);
      temp = temp->next;
   }
}