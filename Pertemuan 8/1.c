#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define CLEAR system("cls")
struct node {
   char nama_mhs[30];
   struct node *left;
   struct node *right;
};

struct node *newNode(char data[30]) {
   struct node *node = (struct node *)malloc(sizeof(struct node));

   strcpy(node->nama_mhs, data);
   node->left = NULL;
   node->right = NULL;

   return node;
}

struct node *insert(struct node *root, char newData[30]) {
   if (root == NULL) {
      root = newNode(newData);
   } else {
      int is_left = 0;
      struct node *cursor = root;
      struct node *prev = NULL;
      while (cursor != NULL) {
         prev = cursor;
         if (newData < cursor->nama_mhs) {
            is_left = 1;
            cursor = cursor->left;
         } else if (newData > cursor->nama_mhs) {
            is_left = 0;
            cursor = cursor->right;
         }
      }

      if (is_left == 1){
         prev->left = newNode(newData);
      } else {
         prev->right = newNode(newData);
      }
   }

   return root;
}

void search_node(struct node *root, char data[30]) {
   struct node *cursor = root;

   while (cursor->nama_mhs != data) {
      if (cursor != NULL) {
         if (data > cursor->nama_mhs) {
            cursor = cursor->right;
         } else {
            cursor = cursor->left;
         }

         if (cursor == NULL) {
            printf("\nNode %s tidak ditemukan", data);
            return;
         }
      }
   }

   printf("\nNode %s ditemukan", data);
   return;
}

struct node *delete_node(struct node *root, char deletedData[30]) {
   if (root == NULL)
      return NULL;

   struct node *cursor;
   if (deletedData > root->nama_mhs)
      root->right = delete_node(root -> right, deletedData);
   else if (deletedData < root->nama_mhs)
      root->left = delete_node(root->left, deletedData);
   else {
      // 1 CHILD

      if (root->left == NULL) {
         cursor = root->right;
         free(root);
         root = cursor;
      } else if (root->right == NULL) {
         cursor = root->left;
         free(root);
         root = cursor;
      } else {
         // 2 CHILDS NODE
         cursor = root->right;
         while (cursor->left != NULL){
            cursor = cursor->left;
         }

         strcpy(root -> nama_mhs, cursor -> nama_mhs);
         root->right = delete_node(root->right, cursor->nama_mhs);
      }
   }

   return root;
}

void displayPreorder(struct node *node) {
   if (node == NULL)
      return;

   printf("%s ", node->nama_mhs);    // root
   displayPreorder(node->left);  // subtree kiri
   displayPreorder(node->right); // subtree kanan
}

void displayInorder(struct node *node) {
   if (node == NULL)
      return;

   displayInorder(node->left);  // subtree kiri
   printf("%s ", node->nama_mhs);   // root
   displayInorder(node->right); // subtree kanan
}

void displayPostorder(struct node *node) {
   if (node == NULL)
      return;

   displayPostorder(node->left);  // subtree kiri
   displayPostorder(node->right); // subtree kanan
   printf("%s ", node->nama_mhs);     // root
}

int main() {
   struct node *root = NULL;
   char temp[30];
   int i, n, opsi;

   while (opsi != 7) {
      CLEAR;
      printf("[PROGRAM NAMA MAHASISWA]\n");
      printf("========================\n");
      printf("1. Insert\n");
      printf("2. Delete\n");
      printf("3. Search\n");
      printf("4. Display Preorder\n");
      printf("5. Display Inorder\n");
      printf("6. Display Postorder\n");
      printf("7. Exit\n");
      printf("========================\n");
      printf("Pilihan(1-7): "); scanf("%d", &opsi);

      CLEAR;
      switch (opsi) {
         case 1:
            printf("Masukkan jumlah mahasiswa: "); scanf("%d", &n);
            for (i = 0; i < n; i++) {
               printf("Masukkan nama mahasiswa ke-%d: ", i+1); scanf("%s", &temp);
               root = insert(root, temp);
            }
            break;
         case 2:
            printf("Masukkan nama mahasiswa yang akan dihapus: "); scanf("%s", &temp);
            root = delete_node(root, temp);
            break;
         case 3:
            printf("Masukkan nama mahasiswa yang akan dicari: "); scanf("%s", &temp);
            search_node(root, temp);
            break;
         case 4:
            printf("Display Preorder: ");
            displayPreorder(root);
            printf("\n");
            break;
         case 5:
            printf("Display Inorder: ");
            displayInorder(root);
            printf("\n");
            break;
         case 6:
            printf("Display Postorder: ");
            displayPostorder(root);
            printf("\n");
            break;
         case 7:
            exit(0);
            break;
         default:
            printf("Pilihan tidak tersedia\n");
            break;
      }

      getch();
   }
   
   return 0;
}