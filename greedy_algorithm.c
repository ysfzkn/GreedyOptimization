/*
 * Yusuf Özkan
 * 
 * Greedy (Açgözlü)(Hırslı) Yöntemle 
 * Memnuniyet Optimizasyonu Hesaplayan Program
 * 
 */



#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

struct series //diziler strcut yapısında düzenli bi şekilde saklandı
{	
	char *name;
	float time;
	float pleasure;
	
};


struct series array[10]; // diziyi tutmak için bir struct tipinde değişken tanımlandı.

int main()
{
	array[0].name="PRISON BREAK"; // dizi isimleri arrayde tutuldu.
	array[1].name="THE WALKING DEAD";
	array[2].name="11.22.63";
	array[3].name="LA CASA DE PAPEL";
	array[4].name="SUPERNATURAL";
	array[5].name="STRANGER THINGS";
	array[6].name="EZEL";
	array[7].name="KUZEY GUNEY";
	array[8].name="BEHZAT C";
	array[9].name="7 GUZEL ADAM";
	
	float value[10];  //dizinin memnuniyet/uzunlugu bir degerde tutuldu.
	float value2[10]; //geçici dizi
	
	srand(time(0)); //random sayıların aynı kalmaması için srand çağırıldı.
	
	printf("-------Dizi Memnuniyet Listesi-------\n\n\n");
	
	
	for(int i=0;i<10;i++)
	{
		array[i].time=rand()%40+20; // 0-60 arası ürettiği 
		array[i].pleasure=rand()%10+1;  // 1-10 arası memnuniyet değerine sayı atanır.
		printf("Dizi Ismi: %s \nUzunlugu: %.2f dk  \nMemnuniyet Puani: %.2f\n",array[i].name, array[i].time,array[i].pleasure);
		value[i]=(float)array[i].pleasure/array[i].time;  // memnuniyet bölü zaman tek tek değere atandı
		printf("Deger :%.2f \n----------------------------------------------------\n",value[i]);
	}
		
	for(int i=0;i<10;i++)
	{
		value2[i]=value[i]; // kopyalama yapıldı
	}
	
	float temp;
	
	int size= sizeof(value)/sizeof(float); // boyut hesabı
	
	for(int i=size-1;i>=0;i--)   //değerleri büyükten küçüğe sıralama yapar
	{							// bubble sorting
		for(int j=i-1;j>=0;j--)
		{
			if(value[i]>value[j])
			{
			       temp  = value[i] ;
				value[i] = value[j] ;
				value[j] = temp     ;
			}
		}
	}
	
	printf("\n\nListe:\n");
	
	float sum=0; //toplam hesabı için değişken
	int index;
	
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			if(value[i]==value2[j])
			{
				index=j; // kopyalanmış dizi ile sıralanmış dizilerden eşleşen indis bulunur.
			}
		}
		
		sum+=array[index].time; //toplam zaman hesaplanacaktır
		 
		if(sum>180)    // eğer toplam 180'i geçerse döngüden çıkacaktır
		{
			break;
		}
		else            // geçmezse tek tek listeleme yapacaktır
		printf("Dizi Ismi: %s -Uzunlugu: %.2f dk - Memnuniyet Puani: %.2f\n",array[index].name, array[index].time,array[index].pleasure);
	}
	
	printf("\nToplam izlenecek sure %.2f dk'dir.",sum-array[index].time);
	
	return 0;
}
