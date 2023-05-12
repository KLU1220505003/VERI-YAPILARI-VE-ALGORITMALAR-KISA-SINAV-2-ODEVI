#include <stdio.h>
#include <stdlib.h>

int BinarySearch(int dizi[],int ilkIndex, int sonIndex, int istenenEleman)
{
	if(sonIndex>=ilkIndex)
	{
		int mid= ilkIndex + (sonIndex-ilkIndex)/2;
		if(dizi[mid]==istenenEleman)
		{
			return mid;
		}	
		if(dizi[mid]> istenenEleman)
		{
			BinarySearch(dizi,ilkIndex,mid-1,istenenEleman);
		}
		else
		{
			//geriye tek durum elemanýn midden büyük olmasý kalýyor. o zaman ortadaki elemanýn soluna bakýyoruz.
			BinarySearch(dizi,mid+1,sonIndex, istenenEleman);
		}
	}
	//elemanýn bulunamamasý sonucu
	else
	{
		return -1;
	}
	
}


int main(int argc, char *argv[]) {
	
	int dizi[]={4,8,3,84,47,76,9,24,68};
	int i,j,tut;
	int n=0; //eleman sayýsý
	
	n=sizeof(dizi)/sizeof(dizi[0]);
	
	//binary search için kucukten buyuðe dogru elemanlar sýralanýr
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(dizi[i]<dizi[j])
			{
				tut= dizi[i];
				dizi[i]=dizi[j];
				dizi[j]=tut;
			}
		}
	}
	
	int eleman; //aranacak olan eleman
	printf("Bulmak istediginiz elemani tam sayi seklinde giriniz: ");
	scanf("%d",&eleman);
	
	int index = BinarySearch(dizi,0,n-1,eleman);
	
	//binarysearch fonkisyonundan gelen degerlere gore sonuclarýn bastýrýlmasý
	if(index== -1)
	{
		printf("Eleman bulunamadi.");
	}
	else
	{
		printf("Eleman bulundu! Bulundugu indexi: %d",index);
	}
	
	return 0;
}
