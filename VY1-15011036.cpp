#include<stdio.h>
#include<stdlib.h>

typedef struct Linked_List{							//Struct oluþturuyor
    int data;
    struct Linked_List *next;						//Linked list oluþturuyor
}NODE;

void yazdir(NODE *head){							//Yazdýr fonksiyonu ile linked listleri ekrana yazdýran fonksiyon
	while(head!= NULL){								//Linked list de son elemana ulaþýnyaca kadar dönmeye devam ediyor
		printf("%d ",head->data);					//Linked listin datasýný ekrana yazdýrýyor
		head = head ->next;							//Bir sonraki elemana geçiyor
	}
}

 void ekle(NODE*head, int data){					//Linked liste yeni eleman ekleme fonksiyonu
 	
 	if(head->data == NULL){							//Linked listin ilk degeri açýlmýþ mý boþ mu onu kontrol ediyor
 		head->next = (NODE*)malloc(sizeof(NODE));	//Dinamic Memory Allocation ile head->next e yer açýlýyor
 		head->next = NULL;							//Açýlan yeri Null yapýyor
 		head -> data=data;							//Atmak istediðimiz veriyi linked listin baþýna atýyor
	 }else{
 	while (head->next != NULL)						//Linked listte en sona varýncaya kadar ilerliyor
 	 head=head->next;
 	 
	 head -> next = (NODE*)malloc(sizeof(NODE));	//Dinamic Memory Allocation ile head->next e yer açýlýyor
	 head -> next -> next =NULL;					//Bir sonraki elemaný NULL yapýyor
	 head -> next -> data= data;					//Atmak istediðimiz veriyi linked liste atýyor
	}
}
 NODE* kesisme(NODE *root1, NODE *root2, NODE* tmp){	//Verilen 2 dizinin kesiþim kümesini bulan fonksiyon

	NODE* start=root2;									//Root2 en baþa geri dönebilsin diye start adýnda NODE tanýmlýyoruz
 	while(root1 != NULL){								//Root1 sonuna gelinceye kadar dönüyor
		while(root2 != NULL){							//Root2 sonuna gelinceye kadar dönüyor
			if(root1->data == root2->data)				//Root1 verisi Root2 verisine eþit mi kontrol ediyor
			ekle(tmp,(root1->data));					//Eðer eþitse tmp adlý linked liste atýyor
			root2=root2->next;							//Root2 linked listinde 1 sonraki elemana geçiþ yapýyor
		}
		root2=start;									//Root2 linked listini en baþa sarýyor
		root1=root1->next;								//Root1 linked listinde 1 sonraki elemana geçiþ yapýyor
	}
		return tmp;										//tmp adlý linked listi geri döndürüyor
 }
 NODE* birlestir(NODE *root1,NODE *root2, NODE* root3){	//Verilen 2 dizinin birleþim kümesini bulan fonksiyon
 	
 	while(root1 != NULL && root2 != NULL){				//root1 ve root2 null göstermediði sürece döngü dönüyor
 		if(root1->data > root2->data){					//Bu algoritma da eðer root1 in datasý root2 nin datasýnda daha büyükse
 			ekle(root3,root2->data);					//önce root2nin datasýný root3 e atýyoruz ve root2 yi bi sonraki elemana
 			root2=root2->next;							//geçiriyoruz. Tekrar kontrol ile root1 in datasý daha mý küçük kontrol
		 }else if(root1->data < root2->data){			//eðer root1 küçükse onu root3 e atýyoruz.Eðer 2 eleman eþitse 1 tane 
		 	ekle(root3,root1->data);					//elemaný root3 atýyor, root1 ve root2yi bi sonraki elemana geçiriyor
		 	root1=root1->next;
		 }else{
		 	ekle(root3,root1->data);
		 	root1=root1->next;
		 	root2=root2->next;
		 }
	 }
	 if(root1 == NULL){									//Eðer root1 sonuna eriþildiði için döngüden çýkýldýysa root2nin verilerini
	 	while(root2 != NULL){							//root3e atýyor
	 		ekle(root3,root2->data);
	 		root2=root2->next;
		 }
	 }
	 if(root2 == NULL){									//Eðer root2 sonuna eriþildiði için döngüden çýkýldýysa root1in verilini
	 	while(root1 != NULL){							//root3e atýyor
	 		ekle(root3,root1->data);
	 		root1=root1->next;
		 }
	 }
	 return root3;										//Root3 ü ana fonksiyona geri döndürüyor
 }
int main(){											
	 int diziA[4]={2,5,9,11};							//Verilen slayttaki örnek verileri
	 int diziB[4]={1,2,7,9};
	 NODE*kesisim,*birlesim,*root1,*root2;				//Gerekli verileri tanýmlýyoruz
	 int komut,i,j,boyut1,boyut2,eleman;
	 
 	 kesisim = (NODE*)malloc(sizeof(NODE));				//Bütün linked listlere dinamic memory ile yer açýp
 	 kesisim -> data = NULL;							//Açýlan hafýzada data verilerini NULL yapýyor
 	 birlesim = (NODE*)malloc(sizeof(NODE));			
 	 birlesim -> data = NULL;
	 root1 = (NODE*)malloc(sizeof(NODE));
	 root1 -> data = NULL;
	 root2 = (NODE*)malloc(sizeof(NODE));
	 root2 -> data = NULL;
	 printf("Verilen ornekteki diziyi kullanmak icin 1'e kendiniz dizi girmek icin 2'ye basiniz=");
	 scanf("%d",&komut);								//Girilen deðeri komuta atýyor
	 switch(komut){										
	 case 1:											//Slayttaki örneði root1 ve root2ye atýyor

	 for (i=0;i<4;i++){									//Slayttaki örneði for döngüsü ile root1e atýyor
	 	ekle(root1,diziA[i]);
	 }
	printf("diziA\n");									
	yazdir(root1);										//Ekrana root1 linked listini yazdýrýyor
	
	for (i=0;i<4;i++){									//Slayttaki örneði for döngüsü ile root2ye atýypor
		ekle(root2,diziB[i]);
	}
	printf("\ndiziB\n");
	yazdir(root2);										//Ekrana root2 linked listini yazdýrýyor
	break;
	case 2:												//Case 2 kullanýcýnýn girdiði diziyi linked liste atýyor
		printf("\n1. dizinin boyutunu giriniz");		//Kullanýcýdan 1. dizinin boyutunu girmesini istiyor
		scanf("%d",&boyut1);							//Girilen deðeri boyut1 atýyor
		printf("\n2. dizinin boyutunu giriniz");		//Kullanýcýdan 2. dizinin boyutunu girmesini istiyor
		scanf("%d",&boyut2);							//Girilen deðeri boyut2 atýyor	
	for(i=0;i<boyut1;i++){								
		printf("1. dizinin %d. elemanini giriniz",i+1);	//Her bir elemaný kullanýcýdan teker teker alýp
		scanf("%d",&eleman);							//eleman deðiþkenine atýp ardýndan root1 linked listine
		ekle(root1,eleman);								//atýyor
	}
	for(i=0;i<boyut2;i++){								//Her bir elemaný kullanýcýdan teker teker alýp
		printf("2. dizinin %d. elemanini giriniz",i+1);	//eleman deðiþkenine atýp ardýndan root2 linked listine
		scanf("%d",&eleman);							//atýyor		
		ekle(root2,eleman);
	}
	printf("\n 1. dizinin elemanlari: \n");				//Root1 linked listini ekrana yazdýrýyor
	yazdir(root1);
	printf("\n 2. dizinin elemanlari:\n");				//Root2 linked listini ekrana yazdýrýyor
	yazdir(root2);
	}
	kesisim=kesisme(root1,root2,kesisim);				//Kesisim fonksiyonu ile rootlarýn kesisim kümesini 
														//kesisim linked listine atýyor
	printf("\n");
	printf("Kesisim kumesi\n");							//Kesisim linked listini ekrana yazdýr fonksiyonu ile yazdýrýyor
	yazdir(kesisim);						
	
	birlesim=birlestir(root1,root2,birlesim);			//Birleþim fonksiyonu ile rootlarýn birleþim kümesini
	printf("\nBirlesim kumesi\n");						//birlesim linked listine atýyor
	yazdir(birlesim);									//Birlesim linked listini ekrana yazdýr fonksiyonu ile yazdýrýyor
	
	return 0;
}

