#include<stdio.h>
#include<stdlib.h>

struct stack{
   int item;
   struct stack *prev;
};

typedef struct stack *ptrstack;
ptrstack tumpukan = NULL;

void push(int x, ptrstack s) {
   ptrstack new_node;
   new_node = (ptrstack)malloc(sizeof(struct stack));
   new_node->item = x;
   new_node->prev = s;
   s = new_node;
}

int pop(ptrstack s) {
   ptrstack temp = s;
   int x = temp->item;
   s = s->prev;
   free(temp);

   return(x);
}

void convert(int x, ptrstack s) {
   int i, temp;
   for(i = x; i > 0; i = i / 2){
      temp = i % 2;
      push(temp, s);
   }
   
   while (s != NULL){
      printf("%d", pop(s));
   }
}

int main() {
   int bil_desimal;

   printf("[PROGRAM KONVERSI DESIMAL KE BINER]\n");

   printf("Bilangan desimal : ");
   scanf("%d", &bil_desimal);

   if (bil_desimal==0) {
      printf("Biner \t: 0");
   }else{
      convert(bil_desimal, tumpukan);
   }
}