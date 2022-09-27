#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Creating a node
struct Mhs
{
    int NIM;
    char nama[50];
    struct Mhs *next;
};

typedef struct Mhs* Mahasiswa;

//Menampilkan nilai linked list
Mahasiswa printdaftarmhs(Mahasiswa p)
{
    int i = 0;
    printf("\nDAFTAR MAHASISWA \n");
    while (p != NULL)
    {
        i = i+1;
        printf("Mahasiswa ke-%d\n", i);
        printf("Nama    : %s\n", p->nama);
        printf("NIM     : %d\n", p->NIM);
        p = p->next;
    }
}

//Memasukkan atau menginput node
Mahasiswa createNode(Mahasiswa *head, char *nama_mhs, int NIM_mhs)
{
    Mahasiswa p;
    p = (Mahasiswa)malloc(sizeof(struct Mhs));
    p->NIM = NIM_mhs;
    strcpy(p->nama, nama_mhs);
    p->next = NULL;

    if(*head == NULL)
       *head = p;
    else
    {
        Mahasiswa tail = *head;
        while (tail->next != NULL)
            tail = tail->next;
        tail->next=p;
    }
}

int main()
{
    int n=0;
    int NIM;
    char nama[50];
    Mahasiswa datamahasiswa = NULL;

    printf("Masukkan Jumlah Data Mahasiswa= ");
    scanf("%d", &n);

    for (int i=1; i<=n; i++)
    {
        printf("Mahasiswa ke-%d", i);
        printf("\nNama    : ");
        scanf("%[^\n]", &nama);
        printf("\nNIM     : ");
        scanf("%d", &NIM);
        createNode(&datamahasiswa, nama, NIM);
    }
    printdaftarmhs(datamahasiswa);
}

