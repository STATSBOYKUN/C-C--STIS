#include<stdio.h>

void yxa(int x, int y){
   int tmp;
   tmp = x;
   x = y;
   y = tmp;
}

void yxb(int *x, int *y){
   int tmp;
   tmp = *x;
   *x = *y;
   *y = tmp;
}

void yxc(int x, int *y){
   int tmp;
   tmp = x;
   x = *y;
   *y = tmp;
}

int main() {
   int a = 10, b = 90;
   int n1, n2;
   
   yxa(a, b);
   n1 = a; n2 = b;
   printf("YXA : n1 = %d, n2 = %d\n", n1, n2);

   yxb(&a, &b);
   n1 = a; n2 = b;
   printf("YXB : n1 = %d, n2 = %d\n", n1, n2);

   yxc(a, &b);
   n1 = a; n2 = b;
   printf("YXC : n1 = %d, n2 = %d\n", n1, n2);
   return 0;
}
