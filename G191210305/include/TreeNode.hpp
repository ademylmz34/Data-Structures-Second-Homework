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
#ifndef TREENODE_HPP
#define TREENODE_HPP

#include <iostream>
using namespace std;

class Dugum{
	public:
		int veri;
		int *dizi;
		int diziElemanSayisi;
		Dugum *sol;
		Dugum *sag;
		int yukseklik;
		Dugum(const int,int,Dugum *sl, Dugum *sg,int[]);
		
};
#endif