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
#include "Queue.hpp"

Node* Queue::previousMaxNode()const{
	Node *prev=NULL;
	Node *tmp=front;
	int max=front->item;
	while(tmp->next!=NULL)
	{
		if(tmp->next->item < max){
			max=tmp->next->item;
			prev=tmp;
		}
		tmp=tmp->next;
	}
	return prev;
			
}


Queue::Queue(){
	front=back=NULL;
	length=0;
}

int Queue::count()const{
	return length;
}

bool Queue::isEmpty()const{
	return length==0;
}

void Queue::clear(){
	while(!isEmpty()) dequeue();
}

int Queue::peek()const{
	if(isEmpty()) throw "hata";
	return front->item;
}

int Queue::peekMax()const{
	if(isEmpty()) throw "hata";
	Node *prev=previousMaxNode();
	if(prev==NULL) return peek();
	return prev->next->item;
}

void Queue::enqueue(const int item){
	Node *last=new Node(item,NULL);
	if(isEmpty()){ front=back=last; }//ilk defa eleman ekleniyorsa
	else
	{
		back->next=last;
		back=last;
	}
	length++;
}
int* Queue::oncelikliSiraDizisi(int d[])
{
	int i=0;
	while(!isEmpty())
	{
	  d[i]=peekMax();
	  dequeueMax();
	  i++;
	}
	return d;
}
void Queue::dequeue(){
	if(isEmpty()) throw "hata";
	Node *del=front;
	front=front->next;
	delete del;
	length--;
}

void Queue::dequeueMax(){
	if(isEmpty()) throw "hata";
	Node *prev=previousMaxNode();
	Node *tmp;
	if(prev==NULL)
	dequeue();
	else{
		if(prev->next==back) back=prev;
		tmp=prev->next;
		prev->next=tmp->next;
		delete tmp;
		length--;
	}
			
}

ostream &operator<<(ostream &screen,  Queue  &right ){
	screen<<right.satir<<".satirdaki dogrularin toplam mesafesi"<<": "<<right.toplamUzunluk<<endl;
	return screen;
}


Queue::~Queue(){
	clear();
}
		


