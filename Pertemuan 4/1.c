#include<stdio.h>
#include<stdlib.h>
 
struct node{
   int value;
   struct node *next;
};
 
typedef struct node *ptrnode;
 
ptrnode createNode(int nilai);
void append(ptrnode head, int nilai);
void printList(ptrnode temp);
 
int main(){
   int n, temp;
   ptrnode head = NULL;
    
   head = (ptrnode)malloc(sizeof(struct node));

   printf("[PROGRAM LINKED LIST]\n");
   printf("Banyak data : "); scanf("%d", &n);
   for(int i = 0;i < n;i++){
      printf("Input data ke - %d : ", i+1);
      if (i == 0){
         scanf("%d", &temp);
         head = createNode(temp);
      }else{
         scanf("%d", &temp);
         append(head, temp);
      }
   }    
   printf("\n");
   printf("Data linked list : \n");
   printList(head);

   free(head);
}
 
ptrnode createNode(int nilai){
   ptrnode p;
   p = (ptrnode)malloc(sizeof(struct node));
   p->value = nilai;
   p->next = NULL;
    
   return(p);
}
 
void append(ptrnode head, int nilai){
   ptrnode tail = head;
    
   while(tail->next != NULL){
      tail = tail->next;
   }
    
   ptrnode new_node = createNode(nilai);
   tail->next = new_node;
   
}
 
void printList(ptrnode temp){
   int count = 0;
   while(temp != NULL){
      printf("Nilai data ke-%d : %d",count + 1, temp->value);
      printf("; Alamat : %d\n", &temp->value);
      temp = temp->next;
      count++;
   }

   printf("Panjang linked list : %d", count);
}