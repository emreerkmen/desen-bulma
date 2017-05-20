#include <stdio.h>
#include <stdlib.h>
#define RESIM_SATIR 25
#define RESIM_SUTUN 80

int matriste_matris(char ana[][RESIM_SUTUN],char baba[][20],int *str,int *stn,int x,int y,int z,int t);//Fonksiyon prototipi.

int main()
{
    int i,j,desen_say,w,desen_no,desen_satiri,desen_sutunu,str,stn,bulundu;
    char matris_resim[RESIM_SATIR][RESIM_SUTUN],karakter,matris_desen[15][20];//Matrislerin tanýmlanmasi.
    FILE *resim,*desenler;

    resim=fopen("resim.txt","r");//resim.txt dosyasi okunmak icin aciliyor...
    for(i=0;i<RESIM_SATIR;i++){
        for(j=0;j<=RESIM_SUTUN;j++){
            if(j==RESIM_SUTUN){
                fscanf(resim,"%c",&karakter);//Satir sonu karakterleri aliniyor.
            }else{
                fscanf(resim,"%c",&matris_resim[i][j]);//Dosyadaki karakterler matrisin icine aktariliyor...
                }
        }
    }
    fclose(resim);//resim.txt dosyasi kapatiliyor.

    desenler=fopen("desenler.txt","r");//desenler.txt dosyasi okunmak icin aciliyor...
    fscanf(desenler,"%d",&desen_say);

    printf("Kod Koordinatlar\n");
    printf("--- ------------\n");

    for(w=0;w<desen_say;w++){
        fscanf(desenler,"%d",&desen_no);
        fscanf(desenler,"%d",&desen_satiri);
        fscanf(desenler,"%d",&desen_sutunu);
        fscanf(desenler,"%c",&karakter);//Dosyadaki karakterler okunmadan onceki satir sonu karakterleri aliniyor.

        for(i=0;i<desen_satiri;i++){
            for(j=0;j<=desen_sutunu;j++){
                if(j==desen_sutunu){
                    fscanf(desenler,"%c",&karakter);//Satir sonu karakterleri aliniyor.
                }else{
                    fscanf(desenler,"%c",&matris_desen[i][j]);//Dosyadaki karakterler matrisin icine aliniyor...
                }
            }
        }
        bulundu=matriste_matris(matris_resim,matris_desen,&str,&stn,RESIM_SATIR,RESIM_SUTUN,desen_satiri,desen_sutunu);//Fonksiyon cagriliyor.
        if(bulundu==1){//Sonuclar yazdiriliyor...
            printf("%3d",desen_no); printf("%3s","("); printf("%d,%d)\n",str,stn);
        }else{
            printf("%d  bulunamadi\n",desen_no);
        }
    }
    fclose(desenler);//desenler.txt dosyasi kapatiliyor.

    return 0;
}

int matriste_matris(char ana[][RESIM_SUTUN],char baba[][20],int *str,int *stn,int x,int y,int z,int t)
{
    int i,j,k,l,bulundu;

    for(i=0;i<=x-z;i++){
        for(j=0;j<=y-t;j++){
            bulundu=1;
            for(k=0;k<z;k++){
                for(l=0;l<t;l++){
                    if(baba[k][l]!=ana[i+k][j+l] && baba[k][l]!=' '){
                        bulundu=0;
                        break;
                    }
                }if(bulundu==0) break;
            }if(bulundu==1) break;
        }if(bulundu==1) break;
    }if(bulundu==1){
        *str=i+1;
        *stn=j+1;
    }
    return bulundu;
}


