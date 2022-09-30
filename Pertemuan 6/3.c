#include <stdio.h>
#include <stdlib.h>

struct stack {
   int s;
   struct stack *prev;
};

typedef struct stack *ptrStack;
ptrStack tumpukan = NULL;

void push(int n) {
   ptrStack new;
   new = malloc(sizeof(struct stack));
   new->s = n;
   new->prev = tumpukan;
   tumpukan = new;
}

int pop() {
   ptrStack temp = tumpukan;
   int n = temp->s;
   tumpukan = tumpukan->prev;
   free(temp);
   return n;
}

void convert(int n) {
   int sisa_bagi;
   if (n > 0) {
      for (int i = n; i > 0; i /= 2) {
         sisa_bagi = i%2;
         push(sisa_bagi);
      }
   }else{
      for (int i = n+1; i < 0; i /= 2) {
         sisa_bagi = i%2;
         if(sisa_bagi == 0){
            push(1);
         } else{
            push(0);
         }
      }
   }

   while(tumpukan != NULL) {
      printf("%d", pop());
   }
}

int main() {
   int n;
   printf("[PROGRAM KONVERSI DESIMAL KE BINER]\n");
   printf("==================================\n");

   printf(" Desimal \t: ");
   scanf("%d", &n);
   if (n == 0) {
      printf(" Biner \t\t: 0");
   } else if(n == -1){
      printf(" Biner \t\t: 111");
   } else {
      if (n < 0) {
         printf(" Biner \t\t: 11");
      } else {
         printf(" Biner \t\t: 00");
      }
      convert(n);
   }
   return 0;
}

/*
Dibuat oleh :
  Nama    : Umar Hadi Pranoto
  NIM     : 222112404
  Sekolah : Politeknik Statistika STIS
*/