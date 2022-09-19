#include <stdio.h>
#include <stdlib.h>
 
// A linked list node
struct Node {
   int nim;
   char nama[50];
   struct Node* next;
   struct Node* prev;
};
 
void push(struct Node** head_ref, int new_data) {
   struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
   new_node->data = new_data;
   new_node->next = (*head_ref);
   new_node->prev = NULL;

   if ((*head_ref) != NULL){
      (*head_ref)->prev = new_node;
   }

   (*head_ref) = new_node;
}

void reverse(struct Node** head_ref) {
   struct Node* temp = NULL;
   struct Node* current = *head_ref;

   while (current != NULL) {
      temp = current->prev;
      current->prev = current->next;
      current->next = temp;
      current = current->prev;
   }

   if (temp != NULL) {
      *head_ref = temp->prev;
   }
}

void printList(struct Node* node) {
   struct Node* last;
   printf("\nIsi list :  \n");
   while (node != NULL) {
      printf(" %d ", node->data);
      last = node;
      node = node->next;
   }

}
 
// Driver code
int main() {
   struct Node* head = NULL;

   push(&head, 7);
   push(&head, 1);
 
   printf("Created DLL is: ");
   printList(head);

   reverse(&head);
   printList(head);
 
   getchar();
   return 0;
}