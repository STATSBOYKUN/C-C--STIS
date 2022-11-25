#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CLEAR system ("cls");

struct mhs{
    int NIM;
    char nama[30];
}; 

struct mhs arrMhs[100];

// void inputData(int n){
//     int i;
//     for (i = 0; i<n; i++){
//         printf("Data mahasiswa ke-%d\n",i+1);
//         printf("NIM  : ");
//         scanf("%d",&arrMhs[i].NIM);
//         printf("Nama : ");
//         scanf("%s",&arrMhs[i].nama);
//     }
// }

void inputDataWithFile(int n)
{
   FILE *file;
   file = fopen("dataMahasiswa.txt", "r");

   for (int i = 0; i < n; i++)
   {
      fscanf(file, "%d %[^\n]s", &arrMhs[i].NIM, &arrMhs[i].nama);
   }

   fclose(file);
}

void displayData(int n){
    for (int i=0; i<n; i++){
        printf("Data mahasiswa ke-%d\n",i+1);
        printf("NIM  : %d\n",arrMhs[i].NIM);
        printf("Nama : %s\n",arrMhs[i].nama);
    }
}

void cariDataNIM(int noInduk, int n){
    int i=1;
    while (i<n && arrMhs[i].NIM != noInduk){
        i=i+1;
    }

    if (arrMhs[i].NIM != noInduk){
        printf("Data tidak ditemukan!");
        printf("NIM %d tidak terdapat dalam database", noInduk);
    } else {
        printf("Data ditemukan!\n");
        printf("NIM %d terdapat pada mahasiswa dengan no. urut %d\n",noInduk,i+1);
        printf("NIM  : %d\n",arrMhs[i].NIM);
        printf("Nama : %s\n",arrMhs[i].nama);
    }
}

int cariDataNama(char name[], int n){
    for (int i = 0; i<n; i++){
        if (strcmp(arrMhs[i].nama,name)==0)
            return i;
    }
    return -1;
}

int main(){
    CLEAR;
    int pilihan,c,nMhs,cariNIM, temp;
    char cariNama[30];
    while (c!=0){
        CLEAR;
        printf("Program Data Mahasiswa\n");
        printf("======================\n");
        printf("1. INPUT DATA WITH FILE\n");
        printf("2. DISPLAY DATA\n");
        printf("3. SEARCH DATA NIM\n");
        printf("4. SEARCH DATA NAME\n");
        printf("5. EXIT\n");
        printf("======================\n");
        printf("Pilihan Anda [1-4]: ");
        scanf("%d",&pilihan);

        switch (pilihan){
            case 1: 
                printf("Masukkan banyaknya mahasiswa: ");
                scanf("%d",&nMhs);
                inputDataWithFile(nMhs);
                break;
            case 2:
                displayData(nMhs);
                break;
            case 3:
                printf("Masukkan NIM mahasiswa yang akan dicari: ");
                scanf("%d", &cariNIM);
                cariDataNIM(cariNIM,nMhs);
                break;
            case 4:
                printf("Masukkan nama mahasiswa yang akan dicari: ");
                // getch();
                scanf("%[^\n]s", cariNama);
                // gets(cariNama);
                temp = cariDataNama(cariNama,nMhs);
                if (temp == -1){
                    printf("Data tidak ditemukan!\n");
                }else {
                    printf("Data ditemukan!\n");
                    printf("Nama %s terdapat pada mahasiswa dengan no. urut %d\n",cariNama,temp);
                    printf("NIM  : %d\n",arrMhs[temp].NIM);
                    printf("Nama : %s\n",arrMhs[temp].nama);
                }
                
                break;
            case 5:
                exit(0);
            default:
                printf("Pilihan Anda tidak tercantum dalam menu");
                break;
        }

        printf("\nDo you want to continue-:(press 1 for yes)\t");
        scanf("%d", &c);
        getchar();
    } 
    return 0;
}