#include <stdio.h>
#include <stdlib.h>

typedef struct dugum
{
	int sayi;
	struct dugum *next;
}Bliste;

//listeye sayi ekleyecek fonksiyon
void Ekleme(Bliste **head, int ekleneceksayi)
{
	//listedeki her eklenecek eleman için yer ayýrýyor
	Bliste *yeniDugum= (Bliste*) malloc(sizeof(Bliste)); 
	
	//ilk eleman yok ise
	if(*head==NULL)
	{
		yeniDugum->sayi = ekleneceksayi;
		yeniDugum->next = NULL;
		*head=yeniDugum;
	}
	else
	{
		yeniDugum->sayi= ekleneceksayi;
		yeniDugum->next=NULL;
		Bliste *gecici= *head;
		
		//son elemanýn nexti daima null oldugu için nexti null olan elemaný bulan dongu
		while(gecici->next!=NULL)
		{
			gecici= gecici->next;
		}
		//yenisayýyý ekler
		gecici->next=yeniDugum;
	}
	
}

//listeden düðüm silen fonksiyon
void Silme(Bliste **head, int silineceksayi)
{
	Bliste *gecici = *head;
	
	//eðer listde hiç eleman yok ise
	if(gecici == NULL)
	{
		printf("Silinecek sayi bulunamadi.");
		return;
	}
	//queue de ilk giren ilk çýktýðý için ilk eleman silinir
	if(gecici !=NULL )
	{
		*head=(*head)->next;//baþ düðüm ikinci düðüme atanýr
		free(gecici);
		printf("ilk eleman silindi.");
		}
	
}


//listedeki tüm elemanlarý bastýran fonksiyon
void Goruntuleme(Bliste *head)
{
	//eðer listede hiç eleman yok ise
	if(head == NULL)
	{
		printf("Liste bos.\n");
	}
	else
	{
		//listede gezinmek için geçici bir deðiþken oluþturulur
		Bliste *gecici= head;
		while( gecici!=NULL)
		{
			printf("%d  ",gecici->sayi);
			gecici = gecici->next;
		}
		
	}
}


int main(int argc, char *argv[]) {
	
	int secim=0; //switch seçimi için
	int sayi=0; //kullanýcýdan alýnacak sayý
	Bliste *head=NULL; //liste baþýndaki düðüm hiç eleman içermediðinden NULL olarak atama yapýlýr
	
	do
	{
		printf("\n\nQueue icin lutfen asagidaki islemlerden birini seciniz\n");
		printf("\n1. Ekleme\n2. Silme\n3. Goruntuleme\n4. Cikis\n");
		scanf("%d",&secim);
	
		switch(secim)
		{
			case 1:
				printf("\nEklemek istediginiz tamsayiyi giriniz lutfen\n");
				scanf("%d",&sayi);
				Ekleme(&head,sayi);
				break;
			case 2:
				Silme(&head,sayi);
				break;
			case 3:
				printf("\nListe: \n");
				Goruntuleme(head);
				break;
			case 4: //direkt programdan çýkar yapýlacak birþey yok
				break;
			default: //kullanýcýnýn baþka birþey girmesi sonucu
				printf("  Boyle bir secenek yoktur!!");
				break;
		}
	}while(secim!=4);
	
	
	return 0;
}
