#include <stdio.h>
#include <stdlib.h>

#define CLEAR system("cls")

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

void decimalToBinary(int n) {
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
   }

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

void decimalToOctal(int n){
   if (n == 0) {
      printf(" Oktal \t\t: 0");
   } else if(n == -1){
      printf(" Oktal \t\t: 377");
   } else {
      if (n < 0) {
         printf(" Oktal \t\t: 37");
      } else {
         printf(" Oktal \t\t: 00");
      }
   }

   int sisa_bagi;
   if (n > 0) {
      for (int i = n; i > 0; i /= 8) {
         sisa_bagi = i%8;
         push(sisa_bagi);
      }
   }else{
      for (int i = n+1; i < 0; i /= 8) {
         sisa_bagi = i%8;
         if(sisa_bagi == 0){
            push(7);
         } else{
            push(8-sisa_bagi);
         }
      }
   }

   while(tumpukan != NULL) {
      printf("%d", pop());
   }
}

int main() {
   int n;
   int ulang = 1;

   while (ulang == 1) {
      CLEAR;
      printf("[PROGRAM KONVERSI DESIMAL KE BINER]\n");
      printf("==================================\n");

      printf(" Desimal \t: ");
      scanf("%d", &n);
      decimalToBinary(n);

      printf("\n");
      decimalToOctal(n);

      printf("\n\n");
      printf("Ulangi program? (YA = 1, TIDAK = 0) : "); scanf("%d", &ulang);
   }
   
   return 0;
}

/*
Dibuat oleh :
  Nama    : Umar Hadi Pranoto
  NIM     : 222112404
  Sekolah : Politeknik Statistika STIS
*/