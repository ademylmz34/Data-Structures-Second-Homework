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
#ifndef SPLIT_HPP
#define SPLIT_HPP


#include <iostream>
#include <string>
#include <sstream> 
#include <math.h>
#include "Queue.hpp"
#include "AvlTree.hpp"
using namespace std;

class Split 
{ 
private: 
	int *newDizi; 
	int elemansayisi;
	int toplamDogruUzunlugu;
	int adet;
	int sayi;
	int x,y,z;
	int sumOfPoints;
public: 
	void addToQueueList(string,Queue *&,int); 
	void addToAvlTreeFromQueueList(int,Queue **&,AvlTree *&);
};
#endif