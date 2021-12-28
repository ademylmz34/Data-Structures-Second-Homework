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

#ifndef AVLTREE_HPP
#define AVLTREE_HPP
#include "TreeNode.hpp"
#include <iostream>
using namespace std;


class AvlTree{
	private:
		Dugum *kok;
		
		
	public:
		Dugum *AraveEkle(Dugum*,const int,int[],int);
		
		Dugum *SolCocukIleDegistir(Dugum *);
		
		Dugum *SagCocukIleDegistir(Dugum *);
		
		bool DugumSil(Dugum *&);
		
		bool Ara(Dugum *&,const int);
		
		void postorder(Dugum *);
		int Yukseklik(Dugum *);
		
		AvlTree();
		bool Bosmu()const;
		void Ekle(const int,int[],int);
	
		bool Ara(const int);
		void postorder();
		int Yukseklik();
		void Temizle();
		friend ostream &operator<<(ostream &,  AvlTree &);
		~AvlTree();
};


#endif