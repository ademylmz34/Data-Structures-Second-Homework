/**
* @file VeriYapılarıOdev2
* @description MinGW C++ ile yazılacak program, açıldığı gibi sayilar.txt dosyasını okuyacaktır. Bu dosyada her satırda 
	3 ün katı olacak şekilde sayi adedi vardir. Bu sayilar aytrıştırılıp her noktanın orjine olan uzaklığı öncelikli kuyruk listesine eklenecek.
	Sonrasında ise her satırda oluşan doğruların toplam uzunlukları avl ağacına eklenecektir. Avl ağacında ise bu toplam uzunluklarla
	bağlantılı olan doğruların orjine olan yakınlıkları göz önüne alınarak ağaç postorder olarak dolaşılacaktır.
* @course 2. Öğretim B Grubu
* @assignment 2
* @date 24.12.2021
* @author Adem Yılmaz adem.yilmaz10@ogr.sakarya.edu.tr
*/
#include "AvlTree.hpp"


Dugum* AvlTree::AraveEkle(Dugum *alt_Dugum,const int yeni,int dizi[],int elemansayisi){
	if(alt_Dugum==NULL) alt_Dugum=new Dugum(yeni,elemansayisi,NULL,NULL,dizi);
	else if(yeni<alt_Dugum->veri||(yeni==alt_Dugum->veri && Yukseklik()==0)){
		alt_Dugum->sol=AraveEkle(alt_Dugum->sol,yeni,dizi,elemansayisi);
				
		if(Yukseklik(alt_Dugum->sol)-Yukseklik(alt_Dugum->sag)==2){ // sol tarafa gittiğimiz için sol tarafta denge bozulma durumuna bakacağız.
			if(yeni<alt_Dugum->sol->veri || yeni==alt_Dugum->sol->veri) // solun soluna gitmiştir.
				alt_Dugum=SolCocukIleDegistir(alt_Dugum);
			else{// solun sağına gitmiştir
				alt_Dugum->sol=SagCocukIleDegistir(alt_Dugum->sol);
				alt_Dugum=SolCocukIleDegistir(alt_Dugum);
			}
		}
	}
				
	 else if(yeni>alt_Dugum->veri|| (Ara(yeni)&&Yukseklik()!=0)){ //Sag tarafta denge bozulma durumu
		alt_Dugum->sag=AraveEkle(alt_Dugum->sag,yeni,dizi,elemansayisi);
			if(Yukseklik(alt_Dugum->sag)-Yukseklik(alt_Dugum->sol)==2)
			{
				if(yeni>alt_Dugum->sag->veri || yeni==alt_Dugum->sag->veri) // sağın sağına gitmiştir.
					alt_Dugum=SagCocukIleDegistir(alt_Dugum); // alt düğümü sağ çocuk ile değiştiriyor.
				else{
					alt_Dugum->sag=SolCocukIleDegistir(alt_Dugum->sag);
					alt_Dugum=SagCocukIleDegistir(alt_Dugum);
				}
			}
		
				
	}
	alt_Dugum->yukseklik=Yukseklik(alt_Dugum);
	return alt_Dugum;
			 // aynı eleman varsa eklemiyoruz.
	} //*& yapmamızın referanslı çağırmamızın sebebi alt dugumu atadığımız alt dugumu yukarıda ki kok e bağlar ve o kok uzerinden işlem yapar. yeni bir parametre oluşturulmaz.
		
Dugum* AvlTree::SolCocukIleDegistir(Dugum *alt_Dugum){
	Dugum *tmp=alt_Dugum->sol;
	alt_Dugum->sol=tmp->sag;
	tmp->sag=alt_Dugum;
			
	alt_Dugum->yukseklik=Yukseklik(alt_Dugum);
	tmp->yukseklik=max(Yukseklik(tmp->sol),alt_Dugum->yukseklik);
	return tmp;
}
		
Dugum* AvlTree::SagCocukIleDegistir(Dugum *alt_Dugum){
	Dugum *tmp=alt_Dugum->sag;
	alt_Dugum->sag=tmp->sol;
	tmp->sol=alt_Dugum;
			
	alt_Dugum->yukseklik=Yukseklik(alt_Dugum);
	tmp->yukseklik=max(Yukseklik(tmp->sag),alt_Dugum->yukseklik);
	return tmp;
}
		
bool AvlTree::Ara(Dugum *&alt_Dugum,const int veri){
	if(alt_Dugum==NULL) return false;
	if(alt_Dugum->veri==veri) return true;
	else if(veri<alt_Dugum->veri) return Ara(alt_Dugum->sol,veri);
	else return Ara(alt_Dugum->sag,veri);
}
		
void AvlTree::postorder(Dugum *alt_Dugum){
	if(alt_Dugum!=NULL){
		postorder(alt_Dugum->sol);
		postorder(alt_Dugum->sag);
		for(int i=0;i<alt_Dugum->diziElemanSayisi;i++)
		{
			cout<<alt_Dugum->dizi[i]<<" "; 
		}
		
		cout<<endl;
	}
}
int AvlTree::Yukseklik(Dugum *alt_Dugum){
	if(alt_Dugum==NULL) return -1;
	return 1+max(Yukseklik(alt_Dugum->sol),Yukseklik(alt_Dugum->sag));
}

bool AvlTree::DugumSil(Dugum *&alt_Dugum){
	Dugum *silinecekDugum=alt_Dugum;
			
	if(alt_Dugum->sag==NULL) alt_Dugum=alt_Dugum->sol; //referanslı çağırma yaptığımıız için kök dügüm değişecektir.
	else if(alt_Dugum->sol==NULL) alt_Dugum=alt_Dugum->sag;
	else{// silinen düğümün iki çocuğu var
		silinecekDugum=alt_Dugum->sol; //sol tarafın en büyüğünü alacağız.
		Dugum *ebevynDugum=alt_Dugum;
		while(silinecekDugum->sag!=NULL){
			ebevynDugum=silinecekDugum;
			silinecekDugum=silinecekDugum->sag;
		}
		alt_Dugum->veri=silinecekDugum->veri;
		if(ebevynDugum==alt_Dugum) // solun hiç sağ çocuğu yok.
					alt_Dugum->sol=silinecekDugum->sol; // null a atacağız.
		else ebevynDugum->sag=silinecekDugum->sol; // silinecek dugumun sagını silecegiz. dolayısıyla solunu da null da olsa deger de olsa ebevynDugum un sagına atamalıyız ki kaybetmeyelim o dugumu.
	}
	delete silinecekDugum;
	return true;
}


		
AvlTree::AvlTree(){
	kok=NULL;
}
bool AvlTree::Bosmu()const{
	return kok==NULL;
}
void AvlTree::Ekle(const int yeni,int dizi[],int elemansayisi){
	kok=AraveEkle(kok,yeni,dizi,elemansayisi);
}
bool AvlTree::Ara(const int veri){
	return Ara(kok,veri);
}
void AvlTree::postorder(){
	postorder(kok);
}

int AvlTree::Yukseklik(){
	return Yukseklik(kok);
}
void AvlTree::Temizle(){
	while(!Bosmu())
		DugumSil(kok);
}


ostream &operator<<(ostream &screen,  AvlTree  &right ){

	screen<<"Avl Tree PostOrder"<<": "<<endl;
	right.postorder();
	return screen;
}


AvlTree::~AvlTree(){
	Temizle();
}



