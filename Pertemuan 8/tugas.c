#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>

#define CLEAR system("cls")

struct node
{
   int data;
   struct node *left;
   struct node *right;
};

int M[100][100];
int globalCol;
int globalRow;
int max(int num1, int num2);
int height(struct node *root);
int getcol(int h);

struct node *newNode(int newData);
struct node *insert(struct node *root, int newData);
struct node *delete_node(struct node *root, int deletedData);

void search_node(struct node *root, int data);
void printTree(int M[100][100], struct node *root, int col, int row, int height);
void TreePrinter(struct node *root);
void displayPreorder(struct node *node);
void displayInorder(struct node *node);
void displayPostorder(struct node *node);

int main()
{
   struct node *root = NULL;
   int temp;
   int i, n, opsi;

   while (opsi != 7)
   {
      CLEAR;
      printf("[PROGRAM BINARY SEARCH TREE]\n");
      printf("========================\n");
      printf("1. Insert\n");
      printf("2. Delete\n");
      printf("3. Search\n");
      printf("4. Display Preorder\n");
      printf("5. Display Inorder\n");
      printf("6. Display Postorder\n");
      printf("7. Exit\n");
      printf("========================\n");
      printf("Pilihan(1-7): ");
      scanf("%d", &opsi);

      CLEAR;
      switch (opsi)
      {
      case 1:
         printf("Masukkan jumlah data: ");
         scanf("%d", &n);
         for (i = 0; i < n; i++)
         {
            printf("Masukkan data ke-%d: ", i + 1);
            scanf("%d", &temp);
            root = insert(root, temp);
         }
         break;
      case 2:
         printf("Masukkan nama mahasiswa yang akan dihapus: ");
         scanf("%d", &temp);
         root = delete_node(root, temp);
         break;
      case 3:
         printf("Masukkan nama mahasiswa yang akan dicari: ");
         scanf("%d", &temp);
         search_node(root, temp);
         break;
      case 4:
         TreePrinter(root);
         printf("\n");
         printf("Display Preorder: ");
         displayPreorder(root);
         printf("\n");
         break;
      case 5:
         TreePrinter(root);
         printf("\n");
         printf("Display Inorder: ");
         displayInorder(root);
         printf("\n");
         break;
      case 6:
         TreePrinter(root);
         printf("\n");
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

struct node *newNode(int newData)
{
   struct node *node = (struct node *)malloc(sizeof(struct node));

   node->data = newData;
   node->left = NULL;
   node->right = NULL;

   return node;
}

struct node *insert(struct node *root, int newData)
{
   if (root == NULL)
   {
      root = newNode(newData);
   }
   else
   {
      int is_left = 0;
      struct node *cursor = root;
      struct node *prev = NULL;
      while (cursor != NULL)
      {
         prev = cursor;
         if (newData < cursor->data)
         {
            is_left = 1;
            cursor = cursor->left;
         }
         else if (newData > cursor->data)
         {
            is_left = 0;
            cursor = cursor->right;
         }
      }

      if (is_left == 1)
      {
         prev->left = newNode(newData);
      }
      else
      {
         prev->right = newNode(newData);
      }
   }

   return root;
}

void search_node(struct node *root, int data)
{
   struct node *cursor = root;

   while (cursor->data != data)
   {
      if (cursor != NULL)
      {
         if (data > cursor->data)
         {
            cursor = cursor->right;
         }
         else
         {
            cursor = cursor->left;
         }

         if (cursor == NULL)
         {
            printf("\nNode %d tidak ditemukan", data);
            return;
         }
      }
   }

   printf("\nNode %d ditemukan", data);
   return;
}

struct node *delete_node(struct node *root, int deletedData)
{
   if (root == NULL)
      return NULL;

   struct node *cursor;
   if (deletedData > root->data)
      root->right = delete_node(root->right, deletedData);
   else if (deletedData < root->data)
      root->left = delete_node(root->left, deletedData);
   else
   {
      if (root->left == NULL)
      {
         cursor = root->right;
         free(root);
         root = cursor;
      }
      else if (root->right == NULL)
      {
         cursor = root->left;
         free(root);
         root = cursor;
      }
      else
      {
         cursor = root->right;
         while (cursor->left != NULL)
         {
            cursor = cursor->left;
         }

         root->data = cursor->data;
         root->right = delete_node(root->right, cursor->data);
      }
   }

   return cursor;
}

int max(int num1, int num2)
{
   return (num1 > num2 ) ? num1 : num2;
}

int height(struct node *root){
   if (root == NULL)
   {
      return 0;
   }
   else
   {
      return max(height(root->left), height(root->right)) + 1;
   }
}

int getcol(int h){
   if (h == 1)
      return 1;
   return getcol(h-1) + getcol(h-1) + 1;
}

void printTree(int M[100][100], struct node *root, int col, int row, int height){
   if (root == NULL)
   {
      return;
   }
   
   M[row*2][col+1] = root->data;
   globalCol = col+1;
   globalRow = row*2;

   printTree(M, root->left, col-pow(2, height-2), row+1, height-1);
   printTree(M, root->right, col+pow(2, height-2), row+1, height-1);
}

void TreePrinter(struct node *root){
   int i = 0, j = 0;
   int h = height(root);
   int col = getcol(h);

   printTree(M, root, floor(col/2), 0, h);

   for (i = 0; i <= globalRow; i++)
   {
      for (j = 0; j <= globalCol; j++)
      {
         M[i][j] = 0;
      }
   }
   printTree(M, root, floor(col/2), 0, h);

   // int rootColumn = 0;
   // for (i = 0; i <= globalRow; i++)
   // {
   //    for (j = 0; j <= globalCol; j++)
   //    {
   //       roo
   //       if (i > 1){
   //          if ((M[i][j] != 0) && (possibleTwoNodes == 0)){
   //             // M[i-1][j+2] = 2;
   //             M[i-1][j+2] = 100001;
   //             // M[i+1][j+2] = 2;
   //             possibleTwoNodes = 1;
   //          } else if ((M[i][j] != 0) && (possibleTwoNodes == 1)){
   //             // M[i-1][j-2] = 3;
   //             M[i-1][j+2] = 111110;
   //             // M[i+1][j-2] = 3;
   //          }
   //       }
   //    }
   //    possibleTwoNodes = 0;
   // }
   
   for (i = 0; i <= globalRow; i++)
   {
      for (j = 0; j <= globalCol; j++){
         if (M[i][j] == 0){
            printf(" ");
         }
         else if (M[i][j] == 100001){
            printf("/");
         }
         else if (M[i][j] == 111110){
            printf("\\");
         }
         else
         {
           printf("%d ", M[i][j]);
         }
      }
      
      printf("\n");
   }
}

void displayPreorder(struct node *node)
{
   if (node == NULL)
      return;

   printf("%d ", node->data);    // root
   displayPreorder(node->left);  // subtree kiri
   displayPreorder(node->right); // subtree kanan
}

void displayInorder(struct node *node)
{
   if (node == NULL)
      return;

   displayInorder(node->left);  // subtree kiri
   printf("%d ", node->data);   // root
   displayInorder(node->right); // subtree kanan
}

void displayPostorder(struct node *node)
{
   if (node == NULL)
      return;

   displayPostorder(node->left);  // subtree kiri
   displayPostorder(node->right); // subtree kanan
   printf("%d ", node->data);     // root
}