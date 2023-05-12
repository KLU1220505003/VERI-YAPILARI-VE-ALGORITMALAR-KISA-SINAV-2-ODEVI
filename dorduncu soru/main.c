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
	//listedeki her eklenecek eleman i�in yer ay�r�yor
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
		
		//son eleman�n nexti daima null oldugu i�in nexti null olan eleman� bulan dongu
		while(gecici->next!=NULL)
		{
			gecici= gecici->next;
		}
		//yenisay�y� ekler
		gecici->next=yeniDugum;
	}
	
}

//listeden d���m silen fonksiyon
void Silme(Bliste **head, int silineceksayi)
{
	Bliste *gecici = *head;
	
	//e�er listde hi� eleman yok ise
	if(gecici == NULL)
	{
		printf("Silinecek sayi bulunamadi.");
		return;
	}
	//queue de ilk giren ilk ��kt��� i�in ilk eleman silinir
	if(gecici !=NULL )
	{
		*head=(*head)->next;//ba� d���m ikinci d���me atan�r
		free(gecici);
		printf("ilk eleman silindi.");
		}
	
}


//listedeki t�m elemanlar� bast�ran fonksiyon
void Goruntuleme(Bliste *head)
{
	//e�er listede hi� eleman yok ise
	if(head == NULL)
	{
		printf("Liste bos.\n");
	}
	else
	{
		//listede gezinmek i�in ge�ici bir de�i�ken olu�turulur
		Bliste *gecici= head;
		while( gecici!=NULL)
		{
			printf("%d  ",gecici->sayi);
			gecici = gecici->next;
		}
		
	}
}


int main(int argc, char *argv[]) {
	
	int secim=0; //switch se�imi i�in
	int sayi=0; //kullan�c�dan al�nacak say�
	Bliste *head=NULL; //liste ba��ndaki d���m hi� eleman i�ermedi�inden NULL olarak atama yap�l�r
	
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
			case 4: //direkt programdan ��kar yap�lacak bir�ey yok
				break;
			default: //kullan�c�n�n ba�ka bir�ey girmesi sonucu
				printf("  Boyle bir secenek yoktur!!");
				break;
		}
	}while(secim!=4);
	
	
	return 0;
}
