#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <ctype.h>

#define CLEAR system("cls")
struct node
{
   char nama_mhs[30];
   int height;
   struct node *left;
   struct node *right;
};

int max(int a, int b);
int getHeight(struct node *N);
int getBalanceFactor(struct node *N);
int height(struct node *node);

struct node *newNode(char nama_mhs[30]);
struct node *rightRotate(struct node *T);
struct node *leftRotate(struct node *T);
struct node *insert(struct node *root, char nama_mhs[30]);
struct node *delete_node(struct node *root, char nama_mhs[30]);

void printGivenLevel(struct node *root, int level);
void printLevelOrder(struct node *root);
void displayPreorder(struct node *node);
void displayInorder(struct node *node);
void displayPostorder(struct node *node);

int main()
{
   struct node *root = NULL;

   int n, choice;
   char data[30];
   while (choice != 6)
   {
      CLEAR;
      printf("     [PROGRAM AVL TREE]\n");
      printf("============================\n");
      printf("1. Insert data\n");
      printf("2. Delete data\n");
      printf("3. Display Preorder\n");
      printf("4. Display Inorder\n");
      printf("5. Display Postorder\n");
      printf("6. Exit\n");
      printf("============================\n");
      printf("Enter your choice: ");
      scanf("%d", &choice);

      switch(choice){
         case 1:
            printf("Jumlah data yang akan dimasukkan : "); scanf("%d", &n);
            for (int i = 0; i < n; i++) {
               printf("Masukkan data ke-%d : ", i+1); scanf("%s", data);
               tolower(data);
               root = insert(root, data);
            }

            // root = insert(root, 9);
            // root = insert(root, 5);
            // root = insert(root, 10);

            // root = insert(root, 0);
            // root = insert(root, 6);
            // root = insert(root, 11);
            // root = insert(root, -1);
            // root = insert(root, 1);
            // root = insert(root, 2);
            break;
         case 2:
            printf("Enter data: ");
            scanf("%s", data);
            root = delete_node(root, data);
            // root = delete_node(root, 10);
            break;
         case 3:
            printLevelOrder(root);
            printf("\n");
            printf("Display Preorder: ");
            displayPreorder(root);
            break;
         case 4:
            printLevelOrder(root);
            printf("\n");
            printf("Display Inorder: ");
            displayInorder(root);
            break;
         case 5:
            printLevelOrder(root);
            printf("\n");
            printf("Display Postorder: ");
            displayPostorder(root);
            break;
         case 6:
            exit(0);
            break;
         default:
            printf("Invalid choice!");
            break;
      }

      getch();
   }
   return 0;
}

struct node *newNode(char nama_mhs[30])
{
   struct node *node = (struct node *)malloc(sizeof(struct node));

   strcpy(node->nama_mhs, nama_mhs);
   node->height = 1;
   node->left = NULL;
   node->right = NULL;
   return node;
}

int max(int a, int b)
{
   if (a > b)
      return a;
   else
      return b;
}

int getHeight(struct node *N)
{
   if (N == NULL)
      return 0;
   return N->height;
}

// Hitung Balance factor untuk node N
int getBalanceFactor(struct node *N)
{
   if (N == NULL)
      return 0;
   return getHeight(N->left) - getHeight(N->right);
}

struct node *rightRotate(struct node *T)
{
   struct node *new_root = T->left;
   struct node *orphan = new_root->right;

   // Lakukan rotasi
   new_root->right = T;
   T->left = orphan;

   // Update height
   T->height = max(getHeight(T->left), getHeight(T->right)) + 1;
   new_root->height = max(getHeight(new_root->left), getHeight(new_root->right)) + 1;

   // Return root baru
   return new_root;
}

struct node *leftRotate(struct node *T)
{
   struct node *new_root = T->right;
   struct node *orphan = new_root->left;

   // Lakukan rotasi
   new_root->left = T;
   T->right = orphan;

   // Update height
   T->height = max(getHeight(T->left), getHeight(T->right)) + 1;

   new_root->height = max(getHeight(new_root->left), getHeight(new_root->right)) + 1;

   // Return root baru
   return new_root;
}

struct node *insert(struct node *root, char nama_mhs[30])
{

   // 1. Lakukan BST insert biasa
   if (root == NULL)
      return (newNode(nama_mhs));
   // asumsi tidak boleh ada nilai yang sama dalam BST
   if (strcmp(nama_mhs, root->nama_mhs) < 0)
      root->left = insert(root->left, nama_mhs);
   else if (strcmp(nama_mhs, root->nama_mhs) > 0)
      root->right = insert(root->right, nama_mhs);

   // 2. Update height dari node baru sampai root
   root->height = 1 + max(getHeight(root->left), getHeight(root->right));
   // 3. Hitung balance factor untuk menentukan apakahnode unbalanced
   int balance = getBalanceFactor(root);

   // Jika tidak balanced, return hasil rotation
   // Kasus 1: Left Left
   if (balance > 1 && (strcmp(nama_mhs, root->left->nama_mhs) < 0))
      return rightRotate(root);
   // Kasus 2: Right Right
   if (balance < -1 && (strcmp(nama_mhs, root->right->nama_mhs) > 0))
      return leftRotate(root);

   // Kasus 3: Right Left
   if (balance < -1 && (strcmp(nama_mhs, root->right->nama_mhs) < 0))
   {
      root->right = rightRotate(root->right);
      return leftRotate(root);
   }

   // Kasus 4: Left Right
   if (balance > 1 && (strcmp(nama_mhs, root->left->nama_mhs) > 0))
   {
      root->left = leftRotate(root->left);
      return rightRotate(root);
   }

   // return node jika balanced
   return root;
}

struct node *delete_node(struct node *root, char nama_mhs[30])
{
   if (root == NULL)
      return NULL;

   struct node *cursor;
   if (strcmp(nama_mhs, root->nama_mhs) > 0)
      root->right = delete_node(root->right, nama_mhs);
   else if (strcmp(nama_mhs, root->nama_mhs) < 0)
      root->left = delete_node(root->left, nama_mhs);
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
         strcpy(root->nama_mhs, cursor->nama_mhs);
         root->right = delete_node(root->right, cursor->nama_mhs);
      }
   }
   
   // Jika setelah dilakukan delete, tree kosong maka return root
   if (root == NULL)
      return root;
   // 2. Update height dari node
   root->height = 1 + max(getHeight(root->left), getHeight(root->right));

   // 3. Hitung balance factor untuk menentukan apakah root unbalanced
   int balance = getBalanceFactor(root);

   // Jika tidak balanced, return hasil rotation

   // Kasus 1: Left Left
   if (balance > 1 && getBalanceFactor(root->left) >= 0)
      return rightRotate(root);

   // Kasus 2: Right Right
   if (balance < -1 && getBalanceFactor(root->right) <= 0)
      return leftRotate(root);

   // Kasus 3: Right Left
   if (balance < -1 && getBalanceFactor(root->right) > 0)
   {
      root->right = rightRotate(root->right);
      return leftRotate(root);
   }

   // Kasus 4: Left Right
   if (balance > 1 && getBalanceFactor(root->left) < 0)
   {
      root->left = leftRotate(root->left);
      return rightRotate(root);
   }
   
   return root;
}

void printGivenLevel(struct node *root, int level)
{
   if (root == NULL)
      return;
   if (level == 1)
      printf("%s ", root->nama_mhs);
   else if (level > 1)
   {
      printGivenLevel(root->left, level - 1);
      printGivenLevel(root->right, level - 1);
   }
}

void printLevelOrder(struct node *root)
{
   int h = height(root);
   int i;
   for (i = 1; i <= h; i++)
   {
      printf("Level-%d: ", i-1);
      printGivenLevel(root, i);
      printf("\n");
   }
}

/* Compute the "height" of a tree -- the number of
 nodes along the longest path from the root node
 down to the farthest leaf node.*/
int height(struct node *node)
{
   if (node == NULL)
      return 0;
   else
   {
      /* compute the height of each subtree */
      int lheight = height(node->left);
      int rheight = height(node->right);

      /* use the larger one */
      if (lheight > rheight)
      {
         return (lheight + 1);
      }
      else
      {
         return (rheight + 1);
      }
   }
}

void displayPreorder(struct node *node)
{
   if (node == NULL)
      return;

   printf("%s ", node->nama_mhs);    // root
   displayPreorder(node->left);  // subtree kiri
   displayPreorder(node->right); // subtree kanan
}

void displayInorder(struct node *node)
{
   if (node == NULL)
      return;

   displayInorder(node->left);  // subtree kiri
   printf("%s ", node->nama_mhs);   // root
   displayInorder(node->right); // subtree kanan
}

void displayPostorder(struct node *node)
{
   if (node == NULL)
      return;

   displayPostorder(node->left);  // subtree kiri
   displayPostorder(node->right); // subtree kanan
   printf("%s ", node->nama_mhs);     // root
}