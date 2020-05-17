#include <time.h>
#include <string.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define KAPASITE 20

typedef struct node{
	int siraNo;
	int islemSuresi;
	int islemBasla;
	char *islemTuru;
	int gelmeSuresi;
	int beklemeSuresi;
	int gitmeSuresi;
}node; 
typedef struct gise{
	int durum;
	int sure;
	int musteri;
	int toplamMusteri;
	int ortalamaCalismaSuresi;
}gise;
 int islem(int);
 void ilkDeger(node *,int*);
 void ilkDegerAtama(gise *);
 void enQueue(int * ,int *,node *,node);
 node deQueue(int *,int *,node ,node *);
 int maxKuyrukUzunlugu(int * ,int *);
 int giseyeGiris(gise *);
 void ilkDegerAtama(gise );
 int giseyeCekme(int *,int *,int *,int *,int *,node ,gise *,int *,node *,node *);
 void  musteriEkle(node * ,int *,int *,int *,int *,node *,int *,int *);
 void terkEtme(int *,gise *,int *,node *,int *);
 int islemBaslatma(node *,int *,int *,int *,int *,int *,int*,int *,gise *,int *);
int main(){

int static musteriSayaci=0;
 
 	node musteri;
 	gise gise[3];
 	node kuyruk[KAPASITE];
 	node kuyAlinanMus[3];
 	int front=-1,rear=-1;
	int temp[20],islemSecim,cekirdek,toplamMusteri,toplamSure,a,sure,saat=7,dakika=00,gelmeSuresi2,gelmeSuresi,maxUzunluk=0,bekleme,toplamBekleme,maxBekleme=-9999,sayac,sayac2=10,i,no,basladi[3],bosaldi[3],sira=-1;
	printf("Simulasyon suresini giriniz  :");
	scanf("%d",&sure);
	printf("Cekirdek Degerini Giriniz");
	scanf("%d",&cekirdek);
	srand(cekirdek);
	printf("Simulasyon basliyor.. ");
	ilkDegerAtama(gise);
	ilkDeger(kuyAlinanMus,&sayac);
		gelmeSuresi=rand()&6;
		gelmeSuresi2=gelmeSuresi+rand()%6;
					for( sayac=gelmeSuresi; sayac<=sure; sayac++)
					{ 
					if(musteriSayaci==0)
					{ 
						musteriSayaci++;
						musteriEkle(&musteri,&gelmeSuresi,&sayac,&front,&rear,kuyruk,&islemSecim,&musteriSayaci);
													
					}										
					while(sayac==gelmeSuresi2){
						musteriSayaci++;
						musteriEkle(&musteri,&gelmeSuresi2,&sayac,&front,&rear,kuyruk,&islemSecim,&musteriSayaci);
						
					}
					maxUzunluk=maxKuyrukUzunlugu(&front,&rear);
					
				/*	if(front!=-1){
						no=giseyeGiris(gise);
						if(no!=-1){									
						giseyeCekme(&no,basladi,&front,&rear,&musteri,gise,&gelmeSuresi,kuyAlinanMus,kuyruk);
									
						}}
						*/							

						for(i=0; i<3; i++)
						{
								if(front!=-1)
								{
								
								no=giseyeGiris(gise);
										
									if(no!=-1)
									{
									giseyeCekme(&sayac,&no,basladi,&front,&rear,musteri,gise,&gelmeSuresi,kuyAlinanMus,kuyruk);
									if(kuyAlinanMus[no].siraNo!=0 || kuyAlinanMus[no].siraNo!=musteriSayaci ){
									if(kuyAlinanMus[no].siraNo!=-1)
									gise[no].durum=1;
									}
									}
								}
							terkEtme(&no,gise,basladi,kuyAlinanMus,&sayac);
													
							islemBaslatma(kuyAlinanMus,&no,basladi,&sayac,temp,&toplamBekleme,&bekleme,&maxBekleme,gise,&musteriSayaci);	
							}
								
						}
						
					
						while(front!=-1){
							
							for(i=0; i<3; i++)
							{if(front!=-1)
								{
								
								no=giseyeGiris(gise);
										
									if(no!=-1)
									{
									giseyeCekme(&sayac,&no,basladi,&front,&rear,musteri,gise,&gelmeSuresi,kuyAlinanMus,kuyruk);
									if(kuyAlinanMus[no].siraNo!=0){
									gise[no].durum=1;
									}
									}
								}
								
							terkEtme(&no,gise,basladi,kuyAlinanMus,&sayac);
							
							
							islemBaslatma(kuyAlinanMus,&no,basladi,&sayac,temp,&toplamBekleme,&bekleme,&maxBekleme,gise,&musteriSayaci);	
							
								
						}
						sayac++;	
							
						}
						for(i=0; i<3; i++)					
						{
						toplamMusteri=toplamMusteri+gise[i].toplamMusteri;
						toplamSure=toplamSure+gise[i].sure;
						}
						printf("\nSONUCLAR \n");
						printf("Gecen Sure Boyunca Kuyruktaki En Fazla Bekleme Suresi: %d\n",maxBekleme);
						printf("Gecen Sure Boyunca Kuyruktaki Max Kuyruk Sayisi : %d\n",maxUzunluk);
						printf("Gecen Sure Boyunca Kuyruktaki Ortalama Bekleme Suresi :%.2f\n\n",((float)toplamBekleme/(float)musteriSayaci));
						printf("Gise No 	Toplam Musteri Sayisi 	Ortalama Hizmet Verme Suresi\n");
						printf("******       *******************    	*************************\n");
						for(i=0; i<3; i++)
						printf("Gise-%d 		%-20d			%.2f\n",(i+1),gise[i].toplamMusteri,(float)gise[i].sure/(float)gise[i].toplamMusteri);
						return 0;
}
 
 int islem(int secim){
 	int sure;
 	switch (secim){
 		case 0 :   sure=rand()%7+3;  return sure;
 		break;
 		case 1 :   sure=rand()%10+10; return sure;
 		break;
 		case 2 :	 sure=rand()%10+2; return sure;
 		break;
 		case 3 :   sure=rand()%6+1; return sure;
 		break;
	 }
	 
 }
 void ilkDeger(node kuyAlinanMus[],int *no){
		kuyAlinanMus[*no].siraNo=-1;
		kuyAlinanMus[*no].gelmeSuresi=-1;
		kuyAlinanMus[*no].islemBasla=-1;
		kuyAlinanMus[*no].islemSuresi=-1;
		kuyAlinanMus[*no].beklemeSuresi=-1;
		kuyAlinanMus[*no].gitmeSuresi=-1;}


void enQueue(int *front ,int *rear,node *kuyruk,node yeniMusteri){
		if((*rear+1)==KAPASITE && front==0)
		{
		//	printf("\nKuyruk Dolu");
		}
		else
		{
			if((*rear+1)==KAPASITE)
			*rear=0;
			if(*front==-1)
			*front= 0;
				
			*rear = *rear+1;
			kuyruk[*rear]=yeniMusteri;			
		}
	}
node deQueue(int *front,int *rear,node kuyruk[],node *kuyAlinanMus){
		if(*front == -1 || *front>*rear)
		{
		//	printf("\nKuyruk bos");
			*front= -1;
			*rear=-1;
		}
		else
		{
			node temp=kuyruk[*front];
			if (*front==KAPASITE-1)
			front=0;
			else
			*front=*front+1;
			return temp;
		}
	}
int maxKuyrukUzunlugu(int *front ,int *rear){
		int uzunluk,maxUzunluk;
			uzunluk=(*rear-*front+1+KAPASITE)%KAPASITE;
			if(uzunluk>maxUzunluk)
			maxUzunluk=uzunluk;	
			return maxUzunluk;
			}
 int giseyeGiris(gise *gise)
 {
 	int giseNo=-1;
 	if(gise[0].durum==0)
 	return giseNo=0;
 	if(gise[1].durum==0)
 	return giseNo=1;
 	if(gise[2].durum==0)
 	return giseNo=2;
 	return giseNo;
 }
 void ilkDegerAtama(gise gise[]){
	for(int i=0; i<3; i++)
	{
		gise[i].durum=0;
		gise[i].toplamMusteri=0;
		gise[i].sure=0;
}
}

int giseyeCekme(int *sayac,int *no,int *basladi,int *front,int *rear,node musteri,gise *gise,int *gelmeSuresi,node *kuyAlinanMus,node *kuyruk){


		if(*front!=-1){
		//	printf("*no*->%d",*no);
			if(*no!=-1){
			musteri=deQueue(front,rear,kuyruk,kuyAlinanMus);
			if(*front==-1)
			{
				ilkDeger(kuyAlinanMus,no); 
				return 1 ;
			}
			
			basladi[*no]=0;						
 			kuyAlinanMus[*no].siraNo=musteri.siraNo;
			kuyAlinanMus[*no].gelmeSuresi=musteri.gelmeSuresi;
			kuyAlinanMus[*no].islemBasla=*gelmeSuresi;
			kuyAlinanMus[*no].islemSuresi=musteri.islemSuresi;
			kuyAlinanMus[*no].beklemeSuresi=0;
			kuyAlinanMus[*no].gitmeSuresi=kuyAlinanMus[*no].gelmeSuresi+kuyAlinanMus[*no].islemSuresi;
		//	printf("\ngelme Suresi->%d sayac-> %d\n",kuyAlinanMus[*no].gelmeSuresi,*sayac);

			}
		}
	}
void  musteriEkle(node * musteri,int *gelmeSuresi2,int *sayac,int *front,int *rear,node *kuyruk,int *islemSecim,int *musteriSayaci){
					char *islemTuru;
					*islemSecim=rand()%4; 
					switch (*islemSecim){
					case 0 :   islemTuru="EFT" ;
 					break;
 					case 1 :   islemTuru="Kredi Cekme";
 					break;
 					case 2 :	 islemTuru="Fatura Odeme";
 					break;
 					case 3 :   islemTuru="Para Cekme";
 					break;}
					musteri->islemTuru=islemTuru;
					musteri->siraNo=*musteriSayaci;
					musteri->gelmeSuresi=*gelmeSuresi2;
					musteri->islemBasla=*sayac;
					musteri->islemSuresi=islem(*islemSecim);
					enQueue(front,rear,kuyruk,*musteri);
					printf("\n %d. dakikada Musteri#%d geldi %s Isleminin  Uzunlugu %d\ dakika.\n",*sayac,*musteriSayaci,musteri->islemTuru,musteri->islemSuresi);
					*gelmeSuresi2=musteri->gelmeSuresi+rand()%6;
					
					
}
void terkEtme(int *no,gise *gise,int *basladi,node *kuyAlinanMus,int *sayac){


	for(int a=0;a<3;a++){
								
								if(gise[a].durum!=0)
								{
								if(basladi[a]!=0)
								if((kuyAlinanMus[a].islemBasla+kuyAlinanMus[a].islemSuresi)==*sayac)
								{
								printf(" \n%d. dakikada Musteri#%d gise#%d kullanarak islemini bitirdi. \n",*sayac,kuyAlinanMus[a].siraNo,a+1);
								basladi[a]=0;
								gise[a].durum=0;
							
								}
								}}	
}
int islemBaslatma(node *kuyAlinanMus,int *no,int *basladi,int *sayac,int temp[],int *toplamBekleme,int*bekleme,int *maxBekleme,gise * gise,int *musteriSayaci){												
								if(*no!=-1 && basladi[*no]!=1 ) 
								{for(int i=kuyAlinanMus[*no].siraNo;i<0;i--)
									{ if(temp[kuyAlinanMus[*no].siraNo]==kuyAlinanMus[*no].siraNo)
									ilkDeger(kuyAlinanMus,no);
									gise[*no].durum=0;	return 0;	}																					
							//	printf("\nsayac--> %d musteriSayaci-->%dNo->%d kuyAlinanMus siraNo-->%d temp->%d<--\n",*sayac,*musteriSayaci,*no,kuyAlinanMus[*no].siraNo,temp[kuyAlinanMus[*no].siraNo]);
								printf(" \n%d. dakikada Musteri#%d gise#%d ile islemini gerceklestirmeye basladi.\n",*sayac,kuyAlinanMus[*no].siraNo,*no+1);
								kuyAlinanMus[*no].islemBasla=*sayac;
								*bekleme=kuyAlinanMus[*no].islemBasla-kuyAlinanMus[*no].gelmeSuresi;
								*toplamBekleme+=*bekleme;
								basladi[*no]=1;
								if(*bekleme>*maxBekleme)
								*maxBekleme=*bekleme;
								gise[*no].toplamMusteri=gise[*no].toplamMusteri+1;
								gise[*no].sure=gise[*no].sure+kuyAlinanMus[*no].islemSuresi;
								temp[kuyAlinanMus[*no].siraNo]=kuyAlinanMus[*no].siraNo;
								
					  
								
							}	
}							

					
					
						
		
	
			
	
							


	
	
 	
