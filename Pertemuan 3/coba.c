#include <stdio.h>
typedef struct lahir
{
    int tanggal;
    int bulan;
    int tahun;
} tanggallahir;

typedef struct datamahasiswa
{
    char Nama[30];
    char NIM[9];
    char Kelas[4];
    tanggallahir ultah;
} data;

int main()
{
    int jumlah;
    data biodata[jumlah];

    printf("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n");
    printf("     PROGRAM INPUT DATA MAHASISWA    \n");
    printf("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n\n");

    printf("Masukkan jumlah data mahasiswa : ");
    scanf("%d", &jumlah);
    printf("\n");

    for(int i=1; i<=jumlah; i++)
    {
        printf("# Input Data Mahasiswa Ke-%d\n", i);
        printf("  Nama        : "); scanf(" %[^\n]", biodata[i].Nama);
        printf("  NIM         : "); scanf(" %s", biodata[i].NIM);
        printf("  Kelas       : "); scanf(" %s", biodata[i].Kelas);
        printf("  Ulang Tahun (Masukkan dalam angka) \n");
        printf("   - Tanggal  : "); scanf(" %d", &biodata[i].ultah.tanggal);
        printf("   - Bulan    : "); scanf(" %d", &biodata[i].ultah.bulan);
        printf("   - Tahun    : "); scanf(" %d", &biodata[i].ultah.tahun);
        printf("\n");

    }

    printf("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n");
    printf("      D A T A   M A H A S I S W A    \n");
    printf("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n");

    for(int i=1; i<=jumlah; i++)
    {
        printf("\n# Data Mahasiswa Ke-%d\n", i);
        printf("  Nama          : %s \n", biodata[i].Nama );
        printf("  NIM           : %s \n", biodata[i].NIM );
        printf("  Kelas         : %s \n", biodata[i].Kelas);

        printf("  Tanggal Lahir : %d - %d - %d \n", biodata[i].ultah.tanggal, biodata[i].ultah.bulan, biodata[i].ultah.tahun);
    }

    printf("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n");
    printf("   T E R I M A    K A S I H    \n");
    printf("~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n\n");

    return 0;
}
