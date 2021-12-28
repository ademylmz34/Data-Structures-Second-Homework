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
#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iostream>
#include <cmath>
#include "Node.hpp"
using namespace std;
class Queue{
	private:
		Node *front;
		Node *back;
		int length;
		Node * previousMaxNode()const;
		
	public:
		Queue();
		int satir;
		int *dizi;
		int toplamUzunluk;
		int count()const;
		bool isEmpty()const;
		void clear();
		int peek()const;
		int peekMax()const;
		void enqueue(const int);
		void dequeue();
		void dequeueMax();
		int *oncelikliSiraDizisi(int[]);
		
		friend ostream &operator<<( ostream &,  Queue &);
		~Queue();
		
};

#endif