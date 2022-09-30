#include <stdio.h>
#include <stdlib.h>

struct node {
    int s;
    struct node *prev;
};

typedef struct node *ptrNode;
ptrNode tail = NULL;

void push(int n) {
    ptrNode new;
    new = malloc(sizeof(struct node));
    new->s = n;
    new->prev = tail;
    tail = new;
}

int pop() {
    ptrNode curr = tail;
    int n = curr->s;
    tail = tail->prev;
    free(curr);
    return n;
}

void convert(int n) {
    int reminder;
    if (n>0){
        for (int i = n; i > 0; i /= 2) {
            reminder = i%2;
            push(reminder);
    }
    else
        for (int i = n+1; i < 0; i /= 2) {
            reminder = i%2;
            if(reminder == 0) push(1);
            else push(0);
    }
    while(tail != NULL) {
        printf("%d", pop());
    }
}

int main() {
    int n;
    printf("==Program Konversi Bilangan Desimal ke Biner==\n");
    printf("Masukkan Bilangan Desimal = ");
    scanf("%d", &n);
    if (n == 0) printf("Hasil Konversi ke biner = 0");
    else if (n < 0){
        if (n == -1)
        printf ("Hasil Konversi ke biner = 11")
    else {
        printf("Hasil Konversi ke biner = ");
        convert(n);
    }
    return 0;
}
