#include <stdio.h>
#define MAX 100 // ukuran maksimum array

void fill_data(int data[], int *size)
{ // mengisi data
    printf("Input ukuran array (max 100): ");
    scanf("%d", size);
    printf("Input data: ");
    for (int i = 0; i < *size; i++)
    {
        scanf("%d", &data[i]);
    }
}

int seq_search(int nim[],int size, int x)
{
    for (int i = 0; i < size; i++)
    {
        if (nim[i] == x)
            return i;
    }
    return -1;
}

void main()
{
    int data[MAX];
    int size;
    int x;

    fill_data(data, &size);
    printf("nilai yang mau dicari: ");
    scanf("%d", &x);

    if (seq_search(data,size, x) == -1) 
        printf("tidak ditemukan"); 
    else 
        printf("ditemukan pada indeks ke-%d",seq_search(data,size,x)); 
}