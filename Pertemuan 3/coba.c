#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
   for(int i = 0; i < 1000; i++){
      printf("%d ", 1 + rand() % 1000);
   }

   return 0;
}