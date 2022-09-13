#include<stdio.h>

int main(){
   {
      int x = 10, y = 20;
      //scope 1
      {
         printf("x = %d, y = %d\n", x, y);
         {
            int y = 40;
            //scope 2
            x++;
            y++;
            printf("x = %d, y = %d\n", x, y);
         }
         printf("x = %d, y = %d\n", x, y);
      }
   }
   return 0;
}
