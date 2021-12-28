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
#include "TreeNode.hpp"


Dugum::Dugum(const int vr,int count,Dugum *sl=NULL, Dugum *sg=NULL,int dz[]=NULL){
	veri=vr;
	sol=sl;
	sag=sg;
	dizi=dz;
	diziElemanSayisi=count;
	yukseklik=0;
}