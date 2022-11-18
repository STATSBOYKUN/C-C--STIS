#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

struct kartu{
    char angka[3];
    char simbol[10];
    int power;
};
int topcard = 51;
int topbuang = -1;
int pilih = 0;
    struct kartu poker[52]; //kartu full
    struct kartu buang[52]; //kartu yang dibuang
    struct kartu mycard[52]; //kartu pengguna
    struct kartu lawan[52]; //kartu komputer

void inisialisasi(struct kartu *card){
int i,j;
        for (i=0;i<4;i++){
        for (j=0;j<13;j++){
            card[13*i+j].power = 0;
            strcpy(card[13*i+j].simbol,"Kosong");
            strcpy(card[13*i+j].angka,"\0");
        }
    }
}

void buatkartu(struct kartu *tumpukan){
//Angka
strcpy(tumpukan[0].angka,"AS");
strcpy(tumpukan[1].angka,"2");
strcpy(tumpukan[2].angka,"3");
strcpy(tumpukan[3].angka,"4");
strcpy(tumpukan[4].angka,"5");
strcpy(tumpukan[5].angka,"6");
strcpy(tumpukan[6].angka,"7");
strcpy(tumpukan[7].angka,"8");
strcpy(tumpukan[8].angka,"9");
strcpy(tumpukan[9].angka,"10");
strcpy(tumpukan[10].angka,"J");
strcpy(tumpukan[11].angka,"Q");
strcpy(tumpukan[12].angka,"K");
strcpy(tumpukan[13].angka,"AS");
strcpy(tumpukan[14].angka,"2");
strcpy(tumpukan[15].angka,"3");
strcpy(tumpukan[16].angka,"4");
strcpy(tumpukan[17].angka,"5");
strcpy(tumpukan[18].angka,"6");
strcpy(tumpukan[19].angka,"7");
strcpy(tumpukan[20].angka,"8");
strcpy(tumpukan[21].angka,"9");
strcpy(tumpukan[22].angka,"10");
strcpy(tumpukan[23].angka,"J");
strcpy(tumpukan[24].angka,"Q");
strcpy(tumpukan[25].angka,"K");
strcpy(tumpukan[26].angka,"AS");
strcpy(tumpukan[27].angka,"2");
strcpy(tumpukan[28].angka,"3");
strcpy(tumpukan[29].angka,"4");
strcpy(tumpukan[30].angka,"5");
strcpy(tumpukan[31].angka,"6");
strcpy(tumpukan[32].angka,"7");
strcpy(tumpukan[33].angka,"8");
strcpy(tumpukan[34].angka,"9");
strcpy(tumpukan[35].angka,"10");
strcpy(tumpukan[36].angka,"J");
strcpy(tumpukan[37].angka,"Q");
strcpy(tumpukan[38].angka,"K");
strcpy(tumpukan[39].angka,"AS");
strcpy(tumpukan[40].angka,"2");
strcpy(tumpukan[41].angka,"3");
strcpy(tumpukan[42].angka,"4");
strcpy(tumpukan[43].angka,"5");
strcpy(tumpukan[44].angka,"6");
strcpy(tumpukan[45].angka,"7");
strcpy(tumpukan[46].angka,"8");
strcpy(tumpukan[47].angka,"9");
strcpy(tumpukan[48].angka,"10");
strcpy(tumpukan[49].angka,"J");
strcpy(tumpukan[50].angka,"Q");
strcpy(tumpukan[51].angka,"K");

//Simbol
int i,j;
        for (i=0;i<4;i++){
            for (j=0;j<13;j++){
                switch (i){
                    case 0 :
                        strcpy(tumpukan[13*i+j].simbol,"Spades");
                        break;
                    case 1 :
                        strcpy(tumpukan[13*i+j].simbol,"Hearts");
                        break;
                    case 2 :
                        strcpy(tumpukan[13*i+j].simbol,"Clubs");
                        break;
                    case 3 :
                        strcpy(tumpukan[13*i+j].simbol,"Diamonds");
                        break;
                }
            }
        }

//Power
        for (int k=0;k<4;k++){
            for (int l=0;l<13;l++){
                if (l == 0)
                    tumpukan[13*k+l].power = 13;
                else
                    tumpukan[13*k+l].power = l;
            }
    }

}

void tukar(struct kartu *a,struct kartu *b){
    struct kartu c;
    c=*a;
    *a=*b;
    *b=c;
}

void randomisasi(struct kartu remi[]){
    int a,b;
    srand(time(0));
    for (int i=0;i<236;i++){
    a = rand()%52;
    b = rand()%52;
    tukar(&remi[a],&remi[b]);
    }

}

void displaycard(struct kartu remi[52]){
    int i,j;

    for (i=0;i<4;i++){
        for (j=0;j<13;j++){
            if (remi[13*i+j].power != 0 && remi[13*i+j].simbol != NULL){
                sleep(1/2);
                printf("(%d) %s of %s\n",13*i+j+1,remi[13*i+j].angka,remi[13*i+j].simbol,remi[13*i+j].power);
            }


        }
    }
}

//fungsi pindah()
void pindah(struct kartu *dari,struct kartu *ke,int mode){
    //Mode 1 dari tumpukan ke user/lawan
    if (mode == 1){
        int i = 0;
        while(ke[i].power != 0){
            i++;
        }
        ke[i]=dari[topcard];
        dari[topcard].power = 0;
        topcard--;
        if (topcard == -1){
            return;
        }
    }

    //mode 2 tumpukan poker ke tumpukan buang
    if (mode == 2){
        topbuang++;
        ke[topbuang]=dari[topcard];
        dari[topcard].power = 0;
        topcard--;
    }

    //mode 3 dari user/lawan ke tumpukan buang
    if (mode == 3){
        int i = 0;
        topbuang++;
        ke[topbuang]=dari[pilih-1];
        dari[pilih-1].power = 0;
        strcpy(dari[pilih-1].simbol,"Kosongs");
    }

    //dari buang ke user/awan
    if (mode == 4){
        int i = 0;
        while(ke[i].power != 0){
            i++;
        }
        ke[i] = dari[topbuang];
        topbuang--;
    }
    //
}


int getcount(struct kartu remi[]){
    int hitung = 0;
    int pilihan = 0;
    while (pilihan<52){
        if (remi[pilihan].power == 0){
            pilihan++;
        }
        else{
            hitung++;
            pilihan++;
        }
    }
    return hitung;
}

int cek(struct kartu *remi,struct kartu *buang){
    int i = 0;
    int hasil = 0 ;
    while(strcmp(remi[i].simbol,buang[topbuang].simbol) != 0 && i<52){
    i= i+1;
    }
    if (i < 52){
        hasil = 1;
    }
    return hasil;
}

//nilai max power dan simbol sama
int getmax(struct kartu remi[52], char simbol[10]){
    int max = 0;
    int count;
    for (int k=0;k<51;k++){
        if (strcasecmp(remi[k].simbol,simbol) == 0){
            count++;
            if (count >= 2 && remi[k].power>remi[max].power)
                max = k;
            else if (count == 1){
                max = k;
            }
        }


    }

    return max;
}

//nilai max power paling tinggi
int getmaxbebas(struct kartu remi[52]){
    int max = 0;

    for (int k=1;k<51;k++){
        if (remi[k].power > remi[max].power)
            max = k;
    }

    return max;
}

void mainkanmycard(int bebas){
    if(cek(&mycard,&buang) == 0 && bebas == 1){
        while (strcmp(poker[topcard].simbol,buang[topbuang].simbol) != 0 && topcard != -1){
            printf("\nKamu sedang mencangkul\n");
            sleep(1);
            pindah(&poker,&mycard,1);
        }
        if (topcard == -1){
            printf("\nKarena kartunya habis kamu ambil kartu yang dibuang yaitu %s of %s\n",buang[topbuang].angka,buang[topbuang].simbol);
            sleep(2);
            pindah(&buang,&mycard,4);
        }
        else{
        printf("\nSetelah sekian lama mencangkul akhirnya kamu membuang kartu juga yaitu %s of %s\n",poker[topcard].angka,poker[topcard].simbol);
        pindah(&poker,&buang,2);
        sleep(2);
        }
}
else
    {
        balik :
        printf("\n\nKartumu\n\n");
        displaycard(mycard);
        if (bebas == 1){
            printf("\n\nKamu mau buang kartu nomer berapa(must %s) : ",buang[topbuang].simbol);
            scanf("%d",&pilih);
            if (strcmp(mycard[pilih-1].simbol,buang[topbuang].simbol) != 0){
                printf("Pilihlah kartu dengan simbol %s",buang[topbuang].simbol);
                sleep(1);
                goto balik;
            }
        }
        else{
            printf("\n\nKamu mau buang kartu nomer berapa (Bebas) : ");
            scanf("%d",&pilih);
        }
        pindah(&mycard,&buang,3);
    }
}


void mainkanlawan(int bebas){
    if(cek(&lawan,&buang) == 0 && bebas == 0)
    {
        while (strcasecmp(poker[topcard].simbol,buang[topbuang].simbol) != 0 && topcard != -1)
            {
                printf("\nKomputer sedang mencangkul kartu");
                sleep(1);
                pindah(&poker,&lawan,1);
            }
        if (topcard == -1){
            printf("\nKarena kartunya habis, komputer ambil kartu yang dibuang %s of %s\n",buang[topbuang].angka,buang[topbuang].simbol);
            pindah(&buang,&lawan,4);
            sleep(2);
        }
        else{
        printf("\nSetelah mencangkul akhirnya komputer bisa membuang kartu ");
        sleep(1);
        printf("%s of %s",poker[topcard].angka,poker[topcard].simbol);
        sleep(2);
        pindah(&poker,&buang,2);
        }


    }
    else if (cek(&lawan,&buang) != 0 && bebas == 0)
    {
        printf("\n\nKomputer membuang kartu ");
        sleep(1);
        pilih = getmax(lawan,buang[topbuang].simbol)+1;
        printf("%s of %s",lawan[pilih-1].angka,lawan[pilih-1].simbol);
        sleep(2);
        pindah(&lawan,&buang,3);

    }
    else if(bebas == 1)
        {
        printf("\n\nKomputer membuang kartu secara BEBAS ");
        sleep(1);
        pilih = getmaxbebas(lawan)+1;
        printf("%s of %s",lawan[pilih-1].angka,lawan[pilih-1].simbol);
        pindah(&lawan,&buang,3);
        sleep(2);
        printf("\n====Kartu buang====\n");
        displaycard(buang);
    }
}

int main(){
    system("Color 74");
    inisialisasi(&mycard);
    inisialisasi(&lawan);
    int a=0;
    int siapamain;
    int bebas = 0;
    int bebasku = 1;
buatkartu(&poker);
printf("Siapa yang mau mulai dulu?\n");
sleep(1);
printf("(1) Komputer?\n");
sleep(1);
printf("(2) Kamu?\n");
sleep(1);
printf("Pilihanmu : ");
scanf("%d",&siapamain);
siapamain = siapamain-1;
system("cls");
printf("Kartu sedang dikocok\n\n");
randomisasi(&poker);
sleep(2);
system("cls");
for(int k=0;k<5;k++){
printf("\nKartu ke-%d kamu dibagikan",k+1);
pindah(&poker,&mycard,1);
sleep(1);
printf("\nKartu ke-%d komputer dibagikan",k+1);
pindah(&poker,&lawan,1);
sleep(1);
}
system("cls");

printf("\n\nmycard\n\n");
displaycard(mycard);
sleep(2);
//printf("\n\nlawan\n\n");
//displaycard(lawan);
system("cls");
//Ambil kartu pertama
pindah(&poker,&buang,2);
printf("\n\nKartu pertamanya adalah \n\n");
sleep(2);
displaycard(buang);
//bebasku = 0 adalah kebebasan mycard
//bebas = 1 adalah kebebasan komputer
//siapa main = 0 adalah komputer dulu yang bermain
//siapa main = 1 adalah mycard main
do{

//sistem permainan
if (siapamain == 0){
    printf("\nKomputer sedang bermain...");
    sleep(1);
    mainkanlawan(bebas);
    printf("\nSekarang kamu yang bermain...");
    sleep(1);
    mainkanmycard(bebasku);
    if (topcard == -1){
        goto komputermenang;
    }
    if(buang[topbuang].power>buang[topbuang-1].power){
        //jika komputer kalah
        siapamain = 1;
        bebas = 0;
        bebasku = bebas;
    }
    else{
        //jika komputer menang
        komputermenang :
        bebas = 1;
        siapamain = 0;
        bebasku = bebas;
    }
}
else {
    printf("\nKamu yang bermain...");
    sleep(1);
    mainkanmycard(bebasku);
    printf("\nSekarang Komputer sedang bermain...");
    sleep(1);
    mainkanlawan(bebas);
    if (topcard == -1){
        goto mycardmenang;
    }
    if(buang[topbuang].power>buang[topbuang-1].power){
        //jika mycard kalah
        siapamain = 0;
        bebas = 1;
        bebasku = bebas;
    }
    else{
        //jika my card menang
        mycardmenang :
        siapamain = 1;
        bebas = 0;
        bebasku = bebas;
    }
}

sleep(1);
printf("\n====Kartu buang====\n");
displaycard(buang);

printf("\nKartumu : %d\n",getcount(mycard));
printf("\nKartu Komputer : %d\n",getcount(lawan));
sleep(2);
system("cls");
}while(getcount(mycard) > 0 && getcount(lawan) > 0);
sleep(2);
if (getcount(mycard) == 0)
printf("Kamu memenangkan pertandingan!");
else
printf("Lawan memenangkan pertandingan!");
}
