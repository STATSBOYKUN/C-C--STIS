#include<stdio.h>
#include<stdlib.h>
 
struct node{
   int value;
   struct node *next;
   struct node *prev;
};
 
typedef struct node *ptrnode;
 
ptrnode createNode(int nilai);
ptrnode insert_head(ptrnode head, int nilai);
ptrnode insert_tail(ptrnode head, int nilai);
ptrnode insert_after(ptrnode head, int nilai, int nilai_dicari);
ptrnode insert_before(ptrnode head, int nilai, int nilai_dicari);
ptrnode remove_first(ptrnode head);
ptrnode remove_last(ptrnode head);
ptrnode remove_middle(ptrnode head, int nilai);
void printList(ptrnode temp);
 
int main(){
    int n, temp;
    ptrnode head = NULL;
    ptrnode tail = NULL;

    head = (ptrnode)malloc(sizeof(struct node));

    tail = head;
    printf("Input the number of nodes : "); scanf("%d", &n);
    for(int i = 0;i < n;i++){
        printf("Input data for node - %d : ", i+1);
        if (i == 0){
            scanf("%d", &temp);
            head = createNode(temp);
        }else{
            scanf("%d", &temp);
            head = insert_tail(head, temp);
        }
    }

    printf("\n");
    printf("Data entered in the list are : \n");
    printList(head);

    printf("Input data for the first node : "); scanf("%d", &temp);
    head = insert_head(head, temp);

    printf("\n");
    printf("After insertion the new list are : \n");
    printList(head);
}
 
ptrnode createNode(int nilai){
   ptrnode p;
   p = (ptrnode)malloc(sizeof(struct node));
   p->value = nilai;
   p->next = NULL;
   p->prev = NULL;
    
   return(p);
}
ptrnode insert_head(ptrnode head, int nilai){
   ptrnode new_node = createNode(nilai);

   new_node->next = head;
   head->prev = new_node;
   head = new_node;
    
   return(head);
}

ptrnode insert_tail(ptrnode head, int nilai){
   ptrnode tail = head;
   while(tail->next != NULL)
   tail = tail->next;

   ptrnode new_node = createNode(nilai);
   tail->next = new_node;

   return(head);
}

ptrnode insert_after(ptrnode head, int nilai, int nilai_dicari){
    ptrnode cursor = head;
    while(cursor->value != nilai_dicari){
        cursor = cursor->next; 
    }

    ptrnode new_node = createNode(nilai);
    new_node->next = cursor->next;
    cursor->next->prev = new_node;
    new_node->prev = cursor;
    cursor->next = new_node;

    return(head);
}

ptrnode insert_before(ptrnode head, int nilai, int nilai_dicari){ 
    if (head->value == nilai_dicari){
        head = insert_head(head, nilai);
    }else{
        ptrnode cursor = head;
        while(cursor->value != nilai_dicari){
            cursor = cursor->next;
        }
        
        ptrnode new_node = createNode(nilai);
        new_node->prev = cursor->prev;
        cursor->prev->next = new_node;
        new_node->next = cursor;
        cursor->prev = new_node;   
    }
    return(head);
}

ptrnode remove_first(ptrnode head){
    if(head == NULL){
        return(0);
    }

    ptrnode first = head;
    head = head->next;
    head->prev = NULL;
    first->next = NULL;

    free(first);

    return(head);
}

ptrnode remove_last(ptrnode head){
    if(head == NULL){
        return(0);
    }

    ptrnode tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }

    tail->prev = NULL;
    tail->prev->next = NULL;
    free(tail);
   return(head);
}

ptrnode remove_middle(ptrnode head, int nilai){
    ptrnode cursor = head;
    while(cursor != NULL){
        if(cursor->next->value == nilai){
            break;
        }
        cursor = cursor->next; 
    }

    if(cursor != NULL){
        ptrnode tmp = cursor->next;
        cursor->next = tmp->next;
        tmp->next->prev = cursor;
        tmp->next = NULL;
        tmp->prev = NULL;
        free(tmp);
    }

    return(head);
}
void printList(ptrnode temp){
    int count = 0;
    while(temp != NULL){
        printf("Node %d : %d ;", count+1, temp->value);
        printf("Address : %d\n", &temp->value);
        temp = temp->next;
        count++;
    }
}