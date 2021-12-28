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

#include <iostream>
#include <string>
#include <fstream>
#include <sstream> 
#include "Reader.hpp"

using namespace std;

Reader::Reader()
{
	ifstream dosyaOku("./doc/sayilar.txt");
	kuyruksayisi=0;
	satir =0;
	if (dosyaOku) {
		Split *split = new Split;
		while (getline(dosyaOku, line)) {
			if(line!="")
				satir++;
		}
		kuyruksayisi=satir;
		dosyaOku.clear();
		dosyaOku.seekg(0, dosyaOku.beg);
		AvlTree* tree=new AvlTree();
		Queue **list = new Queue*[satir];
		satir =0;
		while (getline(dosyaOku, line)) {
			if(line=="")
				continue;
			list[satir] = new Queue();
			split->addToQueueList(line,list[satir],satir);
			
			satir++;
		}
		split->addToAvlTreeFromQueueList(kuyruksayisi,list,tree);
			delete []list;
			delete tree;
			delete split;
		}
		dosyaOku.close();
}
	
