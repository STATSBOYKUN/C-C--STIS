#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int nilai;
    char nim[50], nama[50];
    struct node *nextptr;
}*stnode;

void buatdaftarnode(int n); // function to create the list
void tampilan();         // function to display the list

int main()
{
    int n;
		printf("\n\n NODE :\n");
		printf("--------------------\n");

    printf("Jumlah node yang diinput : ");
    scanf("%d \n", &n);

    buatdaftarnode(n);
    printf("\n ====TAMPILAN NODE==== \n");
    tampilan();
    return 0;
}
void buatdaftarnode(int n)
{
    struct node *fnNode, *tmp;
    int nilai ,i;

    stnode = (struct node *)malloc(sizeof(struct node));

    if(stnode == NULL) //check whether the fnnode is NULL and if so no memory allocation
    {
        printf(" Memory can not be allocated.");
    }else
    {
// Creating n nodes and adding to linked list
        for(i=1; i<=n; i++)
        {
                printf("Nilai node : ", i);
                scanf(" %d", &nilai);

                printf("Nama Lengkap : ");


                printf("\n");

                strcpy(fnNode->nim, nim);      // links the num field of fnNode with num
                strcpy(fnNode->nama , nama);
                fnNode->nextptr = NULL; // links the address field of fnNode with NULL

                tmp->nextptr = fnNode; // links previous node i.e. tmp to the fnNode
                tmp = tmp->nextptr;
            }
        }
    }
}
void tampilan()
{
    struct node *tmp;
    if(stnode == NULL)
    {
        printf(" List is empty.");
    }
    else
    {
        tmp = stnode;
        int i=1;
        while(tmp != NULL)
        {
            printf("Data Mahasiswa ke-%d\n",i);
            printf(" NIM = %d\n", tmp->nim);       // prints the data of current node
            printf(" Nama = %s\n", tmp->nama);
            printf("\n");
            i++;
            tmp = tmp->nextptr;                     // advances the position of current node
        }
    }
}
