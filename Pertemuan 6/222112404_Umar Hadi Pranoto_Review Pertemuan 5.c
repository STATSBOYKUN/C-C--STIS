#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define CLEAR system("cls") // untuk membersihkan layar

// mendefinisikan struct
struct node{
   int value;
   struct node *next;
   struct node *prev;
};
 
typedef struct node *ptrnode; // mendefinisikan pointer node
ptrnode head, tail; // membuat variabel head dan tail
bool cek = false; // variabel cek untuk mengecek apakah list kosong atau tidak

// prototype fungsi
void menu();
ptrnode createNode(int nilai);
void createList(ptrnode *head, ptrnode *tail);
void insert_head(int nilai);
void insert_tail(int nilai);
void remove_last();
void printList(ptrnode temp);
void reverse(ptrnode *head);

int main(){
   head = NULL;
   tail = NULL;

   // alokasi memori untuk head dan tail
   head = (ptrnode)malloc(sizeof(struct node));
   tail = (ptrnode)malloc(sizeof(struct node));
    
   tail = head;

   // perulanagan menu
   menu();
}

// fungsi menu
void menu(){
   int pilihan, temp, temp2, ulang;
   CLEAR;

   printf("[PROGRAM DOUBLE LINKED LIST]\n");
   printf("====================================\n");
   printf("1. Create List\n");
   printf("2. Insert Tail\n");
   printf("3. Insert Head\n");
   printf("4. Remove Last\n");
   printf("5. Print List\n");
   printf("6. Reverse List\n");
   printf("7. Exit\n");
   printf("====================================\n");

   printf("Pilihan (1-7) :  "); scanf("%d", &pilihan);

   // switch case untuk memilih menu
   switch (pilihan) {
      case 1 :
         cek = true;
         createList(&head, &tail);
         break;
      case 2 :
         if(cek == true){
            printf("Masukkan nilai : "); scanf("%d", &temp);
            insert_tail(temp);
         }else{
            printf("List belum dibuat!\n");
         }
         break;
      case 3 :
         if(cek == true){
            printf("Masukkan nilai : "); scanf("%d", &temp);
            insert_head(temp);
         }else{
            printf("List belum dibuat!\n");
         }
         break;
      case 4 :
         if(cek == true){
            remove_last();
         }else{
            printf("List belum dibuat!\n");
         }
         break;
      case 5 :
         if(cek == true){
            printList(head);
         }else{
            printf("List belum dibuat!\n");
         }
         break;
      case 6 :
         if(cek == true){
            reverse(&head);
            printf("List berhasil dibalik!\n");
         }else{
            printf("List belum dibuat!\n");
         }
         break;
      case 7 :
         exit(0);
         break;
      default :
         printf("Pilihan tidak ada!\n");
         break;
   }

   getch();
   if (pilihan != 7){
      menu();
   }
}

// fungsi untuk membuat linked list
void createList(ptrnode *head, ptrnode *tail){
   int n, temp;

   printf("Banyak data : "); scanf("%d", &n); // input banyak data
   for(int i = 0;i < n;i++){
      printf("Input data ke - %d : ", i+1); // input data
      if (i == 0){
         scanf("%d", &temp);
         *head = createNode(temp); // membuat node head
      }else{
         scanf("%d", &temp);
         insert_tail(temp); // memasukkan data ke tail
      }
   }

}

// fungsi untuk membuat node
ptrnode createNode(int nilai){
   ptrnode temp; // membuat variabel temp
   temp = (ptrnode)malloc(sizeof(struct node)); // alokasi memori
   temp->value = nilai; // mengisi nilai
   temp->next = NULL; // mengisi next dengan NULL
   temp->prev = NULL; // mengisi prev dengan NULL
    
   return(temp); // mengembalikan nilai temp
}

// fungsi untuk memasukkan data di head
void insert_head(int nilai){
   ptrnode new_node = createNode(nilai); // membuat node baru

   new_node->next = head; // mengisi next dengan head
   head->prev = new_node; // mengisi prev dengan new_node
   head = new_node; // mengisi head dengan new_node
}

// fungsi untuk memasukkan data di tail
void insert_tail(int nilai){
   ptrnode new_node = createNode(nilai); // membuat node baru

   // mengecek apakah head kosong
   if (head == NULL){
      head = new_node;
   }

   tail = head; // mengisi tail dengan head
   while(tail->next != NULL){
      tail = tail->next; // mengarahkan tail ke node terakhir
   }

   tail->next = new_node; // mengisi next dengan new_node
   new_node->prev = tail; // mengisi prev dengan tail
   tail = new_node; // mengisi tail dengan new_node
}

// fungsi untuk menghapus data di tail
void remove_last(){

   // mengecek apakah head kosong
   if(head == NULL){
      return(0);
   }

   ptrnode last = tail; // membuat variabel last
   tail = tail->prev; // mengisi tail dengan prev
   tail->next = NULL; // mengisi next dengan NULL
   last->prev = NULL; // mengisi prev dengan NULL

   free(last); // menghapus last

}

// fungsi untuk membalik nilai linked list
void reverse(ptrnode *head){
   int i = 0; // membuat variabel i
   int temp_value[100]; // membuat array temp_value
   ptrnode temp = *head; // membuat variabel temp
    
   while (temp != NULL){
      temp_value[i] = temp->value; // mengisi array temp_value
      temp = temp->next; // mengarahkan temp ke node berikutnya
      i++; // increment i
   }
   
   temp = *head; // mengisi temp dengan head
    
   while (temp != NULL){
      temp->value = temp_value[i-1]; // mengisi value dengan array temp_value
      temp = temp->next; // mengarahkan temp ke node berikutnya
      i--; // decrement i
   }
}

// fungsi untuk menampilkan linked list
void printList(ptrnode temp){
   if (temp == NULL){
      printf("List kosong!\n"); // mengecek apakah head kosong
   }else{
      while(temp != NULL){
         printf("Nilai : %d ;",temp->value); // menampilkan nilai
         printf("Alamat : %d\n", &temp->value); // menampilkan alamat
         temp = temp->next; // mengarahkan temp ke node berikutnya
      }
   }
}

/*
Dibuat oleh :
  Nama    : Umar Hadi Pranoto
  NIM     : 222112404
  Sekolah : Politeknik Statistika STIS
*/