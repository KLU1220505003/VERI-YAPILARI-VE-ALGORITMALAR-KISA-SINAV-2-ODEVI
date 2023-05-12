#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



int main(int argc, char *argv[]) {
	
	float n=0.0; //dizi eleman sayýsý
	int i; //sayac
	int max=100; // max dizi eleman sayýsý
	
	do
	{
		printf("Lutfen dizinin boyutu icin pozitif tam sayi giriniz:(max 100) ");
		scanf("%f",&n);
		
	}while( (int)n != n || n<=0 || n>100 );
	
	max=n;
	float dizi[max];
	
	//dizi elemanlarýnýn girilmesi
	printf("\nDizi elamanlarini giriniz:\n");
	for(i=0;i<n;i++)
	{
		printf("%d. eleman ",i+1);
		scanf("%f",&dizi[i]);
	}
	
	float aranacak_eleman;
	
	printf("Aranacak elemani giriniz.\n ");
	scanf("%f",&aranacak_eleman);
	
	//Linear search ile elemanýn bulunmasý
	for(i=0;i<n;i++)
	{
		if(aranacak_eleman == dizi[i])
		{
			printf("Eleman bulundu! bulundugu sira: %d",i+1);
			break;
		}
	}
	
	return 0;
}
