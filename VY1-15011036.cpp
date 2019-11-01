#include<stdio.h>
#include<stdlib.h>

typedef struct Linked_List{							//Struct olu�turuyor
    int data;
    struct Linked_List *next;						//Linked list olu�turuyor
}NODE;

void yazdir(NODE *head){							//Yazd�r fonksiyonu ile linked listleri ekrana yazd�ran fonksiyon
	while(head!= NULL){								//Linked list de son elemana ula��nyaca kadar d�nmeye devam ediyor
		printf("%d ",head->data);					//Linked listin datas�n� ekrana yazd�r�yor
		head = head ->next;							//Bir sonraki elemana ge�iyor
	}
}

 void ekle(NODE*head, int data){					//Linked liste yeni eleman ekleme fonksiyonu
 	
 	if(head->data == NULL){							//Linked listin ilk degeri a��lm�� m� bo� mu onu kontrol ediyor
 		head->next = (NODE*)malloc(sizeof(NODE));	//Dinamic Memory Allocation ile head->next e yer a��l�yor
 		head->next = NULL;							//A��lan yeri Null yap�yor
 		head -> data=data;							//Atmak istedi�imiz veriyi linked listin ba��na at�yor
	 }else{
 	while (head->next != NULL)						//Linked listte en sona var�ncaya kadar ilerliyor
 	 head=head->next;
 	 
	 head -> next = (NODE*)malloc(sizeof(NODE));	//Dinamic Memory Allocation ile head->next e yer a��l�yor
	 head -> next -> next =NULL;					//Bir sonraki eleman� NULL yap�yor
	 head -> next -> data= data;					//Atmak istedi�imiz veriyi linked liste at�yor
	}
}
 NODE* kesisme(NODE *root1, NODE *root2, NODE* tmp){	//Verilen 2 dizinin kesi�im k�mesini bulan fonksiyon

	NODE* start=root2;									//Root2 en ba�a geri d�nebilsin diye start ad�nda NODE tan�ml�yoruz
 	while(root1 != NULL){								//Root1 sonuna gelinceye kadar d�n�yor
		while(root2 != NULL){							//Root2 sonuna gelinceye kadar d�n�yor
			if(root1->data == root2->data)				//Root1 verisi Root2 verisine e�it mi kontrol ediyor
			ekle(tmp,(root1->data));					//E�er e�itse tmp adl� linked liste at�yor
			root2=root2->next;							//Root2 linked listinde 1 sonraki elemana ge�i� yap�yor
		}
		root2=start;									//Root2 linked listini en ba�a sar�yor
		root1=root1->next;								//Root1 linked listinde 1 sonraki elemana ge�i� yap�yor
	}
		return tmp;										//tmp adl� linked listi geri d�nd�r�yor
 }
 NODE* birlestir(NODE *root1,NODE *root2, NODE* root3){	//Verilen 2 dizinin birle�im k�mesini bulan fonksiyon
 	
 	while(root1 != NULL && root2 != NULL){				//root1 ve root2 null g�stermedi�i s�rece d�ng� d�n�yor
 		if(root1->data > root2->data){					//Bu algoritma da e�er root1 in datas� root2 nin datas�nda daha b�y�kse
 			ekle(root3,root2->data);					//�nce root2nin datas�n� root3 e at�yoruz ve root2 yi bi sonraki elemana
 			root2=root2->next;							//ge�iriyoruz. Tekrar kontrol ile root1 in datas� daha m� k���k kontrol
		 }else if(root1->data < root2->data){			//e�er root1 k���kse onu root3 e at�yoruz.E�er 2 eleman e�itse 1 tane 
		 	ekle(root3,root1->data);					//eleman� root3 at�yor, root1 ve root2yi bi sonraki elemana ge�iriyor
		 	root1=root1->next;
		 }else{
		 	ekle(root3,root1->data);
		 	root1=root1->next;
		 	root2=root2->next;
		 }
	 }
	 if(root1 == NULL){									//E�er root1 sonuna eri�ildi�i i�in d�ng�den ��k�ld�ysa root2nin verilerini
	 	while(root2 != NULL){							//root3e at�yor
	 		ekle(root3,root2->data);
	 		root2=root2->next;
		 }
	 }
	 if(root2 == NULL){									//E�er root2 sonuna eri�ildi�i i�in d�ng�den ��k�ld�ysa root1in verilini
	 	while(root1 != NULL){							//root3e at�yor
	 		ekle(root3,root1->data);
	 		root1=root1->next;
		 }
	 }
	 return root3;										//Root3 � ana fonksiyona geri d�nd�r�yor
 }
int main(){											
	 int diziA[4]={2,5,9,11};							//Verilen slayttaki �rnek verileri
	 int diziB[4]={1,2,7,9};
	 NODE*kesisim,*birlesim,*root1,*root2;				//Gerekli verileri tan�ml�yoruz
	 int komut,i,j,boyut1,boyut2,eleman;
	 
 	 kesisim = (NODE*)malloc(sizeof(NODE));				//B�t�n linked listlere dinamic memory ile yer a��p
 	 kesisim -> data = NULL;							//A��lan haf�zada data verilerini NULL yap�yor
 	 birlesim = (NODE*)malloc(sizeof(NODE));			
 	 birlesim -> data = NULL;
	 root1 = (NODE*)malloc(sizeof(NODE));
	 root1 -> data = NULL;
	 root2 = (NODE*)malloc(sizeof(NODE));
	 root2 -> data = NULL;
	 printf("Verilen ornekteki diziyi kullanmak icin 1'e kendiniz dizi girmek icin 2'ye basiniz=");
	 scanf("%d",&komut);								//Girilen de�eri komuta at�yor
	 switch(komut){										
	 case 1:											//Slayttaki �rne�i root1 ve root2ye at�yor

	 for (i=0;i<4;i++){									//Slayttaki �rne�i for d�ng�s� ile root1e at�yor
	 	ekle(root1,diziA[i]);
	 }
	printf("diziA\n");									
	yazdir(root1);										//Ekrana root1 linked listini yazd�r�yor
	
	for (i=0;i<4;i++){									//Slayttaki �rne�i for d�ng�s� ile root2ye at�ypor
		ekle(root2,diziB[i]);
	}
	printf("\ndiziB\n");
	yazdir(root2);										//Ekrana root2 linked listini yazd�r�yor
	break;
	case 2:												//Case 2 kullan�c�n�n girdi�i diziyi linked liste at�yor
		printf("\n1. dizinin boyutunu giriniz");		//Kullan�c�dan 1. dizinin boyutunu girmesini istiyor
		scanf("%d",&boyut1);							//Girilen de�eri boyut1 at�yor
		printf("\n2. dizinin boyutunu giriniz");		//Kullan�c�dan 2. dizinin boyutunu girmesini istiyor
		scanf("%d",&boyut2);							//Girilen de�eri boyut2 at�yor	
	for(i=0;i<boyut1;i++){								
		printf("1. dizinin %d. elemanini giriniz",i+1);	//Her bir eleman� kullan�c�dan teker teker al�p
		scanf("%d",&eleman);							//eleman de�i�kenine at�p ard�ndan root1 linked listine
		ekle(root1,eleman);								//at�yor
	}
	for(i=0;i<boyut2;i++){								//Her bir eleman� kullan�c�dan teker teker al�p
		printf("2. dizinin %d. elemanini giriniz",i+1);	//eleman de�i�kenine at�p ard�ndan root2 linked listine
		scanf("%d",&eleman);							//at�yor		
		ekle(root2,eleman);
	}
	printf("\n 1. dizinin elemanlari: \n");				//Root1 linked listini ekrana yazd�r�yor
	yazdir(root1);
	printf("\n 2. dizinin elemanlari:\n");				//Root2 linked listini ekrana yazd�r�yor
	yazdir(root2);
	}
	kesisim=kesisme(root1,root2,kesisim);				//Kesisim fonksiyonu ile rootlar�n kesisim k�mesini 
														//kesisim linked listine at�yor
	printf("\n");
	printf("Kesisim kumesi\n");							//Kesisim linked listini ekrana yazd�r fonksiyonu ile yazd�r�yor
	yazdir(kesisim);						
	
	birlesim=birlestir(root1,root2,birlesim);			//Birle�im fonksiyonu ile rootlar�n birle�im k�mesini
	printf("\nBirlesim kumesi\n");						//birlesim linked listine at�yor
	yazdir(birlesim);									//Birlesim linked listini ekrana yazd�r fonksiyonu ile yazd�r�yor
	
	return 0;
}

