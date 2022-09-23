#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct mahasiswa{
   int nim;
   char nama[50];
   struct mahasiswa *next;
   struct mahasiswa *prev;
};
 
typedef struct mahasiswa *mhs;
 
mhs createNode(int nilai, char nama[]);
void append(mhs head, int nilai, char nama[]);
void printList(mhs temp);
 
int main(){
   int n, nim_temp;
   char nama_temp[50];
   mhs head = NULL;
   
   head = (mhs)malloc(sizeof(struct mahasiswa));

   printf("[PROGRAM DATA MAHASISWA]\n");
   printf("Banyak mahasiswa : "); scanf("%d", &n);

   for(int i = 0;i < n;i++){
      printf("Input data ke - %d : \n", i+1);
      if (i == 0){
         printf("NIM \t: "); scanf("%d", &nim_temp);
         printf("Nama \t: "); scanf("%s", &nama_temp);
         head = createNode(nim_temp, nama_temp);
      }else{
         printf("NIM \t: "); scanf("%d", &nim_temp);
         printf("Nama \t: "); scanf("%s", &nama_temp);
         append(head, nim_temp, nama_temp);
      }
   }
   
   printf("\n");
   printf("Data mahasiswa : \n");
   printList(head);

   free(head);
}
 
mhs createNode(int nilai, char nama[]){
   mhs temp;
   temp = (mhs)malloc(sizeof(struct mahasiswa));
   temp->nim = nilai;
   strcpy(temp->nama, nama);

   temp->next = NULL;
   temp->prev = NULL;
    
   return(temp);
}
 
void append(mhs head, int nilai, char nama[]){
   mhs tail = head;
   
   while(tail->next != NULL){
      tail = tail->next;
   }
    
   mhs new_node = createNode(nilai, nama);
   tail->next = new_node;
}
 
void printList(mhs temp){
   int count = 0;
   while(temp != NULL){
      printf("Mahasiswa ke-%d : \n",count + 1);
      printf("NIM \t: %d \n", temp->nim);
      printf("Nama \t: %s \n", temp->nama);

      temp = temp->next;
      count++;
      printf("\n");
   }
}