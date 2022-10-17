#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// Himawan
 
// Node
typedef struct node
{
    char nama[20];
    int alpro;
    int kalkulus;
    struct node *next;
} mhs;
 
int count = 0;
 
// Function to Create A New Node
mhs *newmhs(char a[], int alp, int kal)
{
    mhs *temp = (mhs *)malloc(sizeof(mhs));
    strcpy(temp->nama, a);
    temp->alpro = alp;
    temp->kalkulus = kal;
    temp->next = NULL;
 
    return temp;
}
 
// menghapus pendaftar
void dequeue(mhs **head)
{
    if ((*head) != NULL)
    {
        mhs *temp = *head;
        (*head) = (*head)->next;
        free(temp);
    }
}
 
// Function to push according to priority
void enqueue(mhs **head, char n[], int alp, int kal)
{
    mhs *temp = newmhs(n, alp, kal);
 
    // jika head kosong maka temp menjadi head
    if ((*head) == NULL)
    {
        (*head) = temp;
    }
    // jika nilai input alpro lebih kecil
    // maka nilai input alpro dijadikan head
    else if ((*head)->alpro > alp)
    {
        temp->next = *head;
        (*head) = temp;
    }
    // jika nilai alpro sama maka akan menaruh nilai berdasarkan nilai
    // kalkulus dengan kalkulus yang kecil berada di posisi lebih atas
    else if ((*head)->alpro == alp)
    {
        mhs *start = (*head);
        // Untuk menukar nilai head apabila nilai alpro sama dan nilai
        // kalkulus lebih besar sama dengan dari nilai sebelumnya
        if (start->kalkulus >= kal)
        {
            temp->next = start;
            *head = temp;
        }
        else
        {
            // menambahkan syarat while jika nilai alpro selanjutnya sama, jika tidak
            // ditambahkan maka item akan dimasukkan tanpa melihat nilai alpro
            while (start->next != NULL && start->next->kalkulus < kal && start->next->alpro == alp)
            {
                start = start->next;
            }
            temp->next = start->next;
            start->next = temp;
        }
    }
    // jika nilai alpro yang dimasukkan lebih besar maka akan melooping untuk mencari
    // nilai alpro yang lebih besar untuk diselipkan didepannya
    else
    {
        mhs *start = (*head);
        while (start->next != NULL && start->next->alpro < alp)
        {
            start = start->next;
        }
        // memberi if supaya data terakhir yang yang next nya bernilai null
        // tidak terpakai dalam start->next->alpro
        if (start->next != NULL)
            if (start->next->alpro == alp)
                // menambahkan syarat while jika nilai alpro selanjutnya sama, jika tidak
                // ditambahkan maka item akan dimasukkan tanpa melihat nilai alpro
                while (start->next != NULL && start->next->kalkulus < kal && start->next->alpro == alp)
                    start = start->next;
        temp->next = start->next;
        start->next = temp;
    }
    count++;
}
 
void display(mhs *head)
{
    if (head == NULL)
    {
        printf("Belum ada yang daftar\n");
    }
    else
    {
        printf("Nama: %s \tAlpro: %d \tKalkulus: %d\n", head->nama, head->alpro, head->kalkulus);
        if (head->next != NULL)
            display(head->next);
    }
}
 
int main()
{
    // mendeklarasikan pointer mhs wakil sebagai NULL karena belum diisi
    mhs *wakil = NULL;
    enqueue(&wakil, "Eko", 50, 20);
    enqueue(&wakil, "Budi", 50, 20);
    enqueue(&wakil, "bambang", 60, 20);
    enqueue(&wakil, "Eka", 60, 20);
    enqueue(&wakil, "wawo", 60, 20);
    enqueue(&wakil, "Ame", 60, 30);
 
    display(wakil);
    getchar();
    getchar();
    return 0;
}
