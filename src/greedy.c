/*
 Proje odevi: greedy
*/

#include <stdio.h>
#include <stdlib.h>

#define k 50//arac en az k km kadar gider
#define f 100//arac bir depo benzin ile max f km kadar gidebiliyor
#define yol 200//menzile olan toplam yol
int main(void) {
	struct benzin{
		int m; //artan uzaklikta benzin istasyonu
		int p; //benzin istasyondaki bir depo benzinin ucrteti
	}istasyon[5];

    int istasyonSayisi = 5;
	int benzinAlindi = 0, globalFiyat = 0, localFiyat; //benzinAlindi: benzin Alinan istasyon
    //degerleri belirleme
	istasyon[0].m = 0;
	istasyon[0].p = 3;
    istasyon[1].m = 30;
   	istasyon[1].p = 5;
    istasyon[2].m = 70;
   	istasyon[2].p = 4;
    istasyon[3].m = 130;
    istasyon[3].p = 3;
    istasyon[4].m = 180;
   	istasyon[4].p = 6;
   	int j =0 , i = 0 ;
   int baslatma = 0, girdi = 0;
   		while(benzinAlindi + f > istasyon[i].m && i < istasyonSayisi){
   			if(benzinAlindi + k < istasyon[i].m){
   				if(baslatma == 0){
   					localFiyat = istasyon[i].p;
   				    baslatma = 1;
   				    j = i;
   				}
   				if(localFiyat > istasyon[i].p){
   					localFiyat = istasyon[i].p;
   					j = i;
   				}
   				i++;
   				girdi = 1;
   			}

   			else{
   				i++;
   			}
   			if(girdi == 1){ //eger benzin aldigi yeri degistiri;irse buraya girer
   	   			benzinAlindi = istasyon[j].m;//yeri
   	   	   		baslatma = 0;
   	   	        globalFiyat = globalFiyat + localFiyat;
   	   	   		girdi = 0;
   			}
   		}

   	 printf("gereken en az benzin ucreti: %d", globalFiyat);
   	return 0;
}
