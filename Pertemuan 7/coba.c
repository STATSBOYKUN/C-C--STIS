#include <stdio.h>
#include <stdlib.h>

struct abc {
   int a;
   int b;
   int c;
};

void nilai(struct abc *a){
   a->a = 1;
   a->b = 2;
   a->c = 3;
}

void display(struct abc *a){
   printf("%d %d %d", a->a, a->b, a->c);
}

int main(){
   struct abc coba;

   nilai(&coba);
   display(&coba);
   return 0;
}