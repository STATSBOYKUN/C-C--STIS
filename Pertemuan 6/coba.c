#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node *ndpointer;
ndpointer top;

void initialize()
{
    top = NULL;
}

void push(int value)
{
    ndpointer new_node;
    new_node = (ndpointer)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = top;
    top = new_node;
}

int pop()
{
    ndpointer tmp;
    tmp = top;
    int r = tmp->data;
    top = top->next;
    free(tmp);
    return r;
}

void convertbiner(int nilai)
{
    int mod;
    int n;
    for (n = nilai; n > 0; n = n / 2)
    {
        mod = n % 2;
        push(mod);
    }
}
void convertoktal(int nilai)
{
    int mod;

    int n;
    for (n = nilai; n > 0; n = n / 8)
    {
        mod = n % 8;
        push(mod);
    }
}
void display(ndpointer top)
{
    printf("Hasil konversi ke biner = ");
    if (top == NULL)
    {
        printf("Stack kosong\n");
    }
    else
    {
        while (top != NULL)
        {
            printf("%d", pop());
        }
    }
}
void displaycomplement()
{
    printf("Hasil konversi ke biner(komplemen-1) = ");

    if (top == NULL)
    {
        printf("stack kosong\n");
    }
    else
    {
        while (top != NULL)
        {
            if (pop() == 1)
                printf("0");
            else
                printf("1");
        }
    }
}

int main()
{
    initialize();
    int bil, pil;
    printf("Masukkan bilangan : ");
    scanf("%d", &bil);
    printf("Ingin anda rubah ke bilangan apa?\n 1. Biner\n 2. Biner Bertanda\n 3. Oktal\n Masukkan angka = ");
    scanf("%d", &pil);
    if (pil == 1)
    {
        convertbiner(bil);
        display(top);
    }
    else if (pil == 2)
    {
        bil = bil * -1;
        convertbiner(bil);
        displaycomplement();
    }
    else if (pil == 3)
    {
        convertoktal(bil);
        display(top);
    }
    return 0;
}
