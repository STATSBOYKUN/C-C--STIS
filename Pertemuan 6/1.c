#include<stdio.h>

typedef struct {
   int item[50]; 
   int jml_item;
} stack;

void initializestack(stack *s) {
   s->jml_item = 0;
}

int isEmpty(stack *s) {
   return (s->jml_item == 0);
}

int isFull(stack *s) {
   return (s->jml_item == 50);
}

void push(int x, stack *s) {
   if(isFull(s))
      printf("Bilangan terlalu besar !\n");
   else {
      s->item[s->jml_item]=x; ++(s->jml_item);
   }
}

int pop(stack *s) {
   if(isEmpty(s)) return (0);
   else {
      --(s->jml_item);
      return (s->item[s->jml_item]);
   }
}

void convert(int x, stack *s) {
   int i, n, sisa_bagi;
   for(n = x; n > 0; n = n / 2){
      sisa_bagi = n % 2;
      push(sisa_bagi, s);
   }

   printf("Hasil konversi ke biner = ");
   for(i=s->jml_item;i>0;i--){
      printf("%d", pop(s));
   }
}

int main() {
   stack tumpukan;
   int bil_desimal;

   printf("Program konversi Desimal ke Biner\n\n");
   initializestack(&tumpukan);

   printf("Masukkan bilangan desimal = ");
   scanf("%d", &bil_desimal);

   if (bil_desimal==0) {
      printf("Hasil konversi ke biner =0");
   }else{
      convert(bil_desimal, &tumpukan);
   }
}