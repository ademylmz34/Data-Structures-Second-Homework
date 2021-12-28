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
#include "Split.hpp"
#include<stdio.h>

using namespace std;

void Split::addToQueueList(string str,Queue *&list,int satir)
{
	adet=0;	
	sayi=0;
	sumOfPoints=0;
	for(int i = 0; i <= str.length() ; i++) 
	{
		if(str[i] == ' '){
			adet++;
		}
	}
	adet++; // bir satırdaki sayıların adedi
	sumOfPoints=adet/3;
	int points[sumOfPoints][3];
	
	int sayilar[adet];
	adet=0;
	for(int i = 0; i < str.length() ; i++) 
	{
		char ch = str[i];
		if(ch != ' '){
			sayi = sayi*10 + ch - '0';
		}
		else{
			sayilar[adet] = sayi;
			sayi =0;
			adet++;
		}
	}
	sayilar[adet] = sayi;
	adet++;
	
	for(int a = 0; a < sumOfPoints ; a++){
		
		for(int b = 0 ; b < 3 ; b++){
			if(a==0)
				points[a][b]=sayilar[b];
			else
				points[a][b]=sayilar[b+(3*a)];
	
		}
	
	}
	
	for(int a = 0; a < sumOfPoints ; a++){	
		int orjineUzaklik= sqrt(pow(points[a][0],2)+pow(points[a][1],2)+pow(points[a][2],2));
		list->enqueue(orjineUzaklik);
	}
	toplamDogruUzunlugu=0;
	
	for(int a=0;a<sumOfPoints-1;a++)
	{
		
	
		if(a==0)
		{
			x=(points[a][0]-points[a+1][0]);
			y =(points[a][1]-points[a+1][1]);
			z= (points[a][2]-points[a+1][2]);
		}
		else
		{
			x=(points[a][0]-points[(1*a)+1][0]);
			y =(points[a][1]-points[(1*a)+1][1]);
			z= (points[a][2]-points[(1*a)+1][2]);
		}
		
		toplamDogruUzunlugu+= sqrt(pow(x,2)+ pow(y,2)+ pow(z,2));
			

	}
	list->toplamUzunluk=toplamDogruUzunlugu;
	list->satir=satir;
	cout<<*list;
	
	
	

	// list->toplamUzunluk=toplamDogruUzunlugu;
	// cout<<*list;
	
}
void Split::addToAvlTreeFromQueueList(int kuyrukSayisi,Queue **&list,AvlTree *& tree)
{
	for(int i=0;i<kuyrukSayisi;i++)
	{   
		elemansayisi=list[i]->count();
		newDizi=new int[elemansayisi];
		list[i]->oncelikliSiraDizisi(newDizi);
		tree->Ekle(list[i]->toplamUzunluk,newDizi,elemansayisi);
	}
	
	cout<<*tree;
	delete[] newDizi;
	
}