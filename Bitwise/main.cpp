#include <iostream>
#include <chrono> // geçen süreyi hesaplamak için gerekli kütüphane

using namespace std;
using namespace std::chrono; // chrono isim uzayını kullan

int mult_by_pow(int number , int power) // power kadar biti sola kaydırarak number sayısını 2^power ile çarp
{
	return number<<power;
}

int divide_by_pow(int number , int power) // power kadar biti sağa kaydırarak number sayısını 2^power ile böl
{
	return number>>power;
}

int main()
{
	auto sayi1 = 1600000;
	auto sayi2 = 1600000;
	const int size = 1000;

	high_resolution_clock::time_point t1 = high_resolution_clock::now(); // saymaya başla t1 = başlangıç zamanı

	for(int i=0 ; i<size ; i++)
	{
		cout<<mult_by_pow(sayi1 , 1);
	}
	
	cout<<endl;
	high_resolution_clock::time_point t2 = high_resolution_clock::now(); // saymayı bitir t2 = bitiş zamanı
	duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
	cout<<"Total Time : "<<time_span.count()<<" seconds"<<endl<<endl;

	
	high_resolution_clock::time_point t3 = high_resolution_clock::now();// saymaya başla t3 = başlangıç zamanı
	
	for(int i=0 ; i<size ; i++)
	{
		cout<<sayi2*2;
	}
	
	cout<<endl;
	high_resolution_clock::time_point t4 = high_resolution_clock::now();// saymayı bitir t4 = bitiş zamanı
	duration<double> time_span1 = duration_cast<duration<double>>(t4 - t3);
	cout<<"Total Time : "<<time_span1.count()<<" seconds"<<endl<<endl;

	if(time_span1.count() > time_span.count())
		cout<<"sola kaydirarak carpma daha hizli : "<<time_span.count()<<endl<<endl;
	else
		cout<<"x2 ile carpma daha hizli : "<<time_span1.count()<<endl<<endl;

	cout<<"bitwise mult : "<<time_span.count()<<endl;
	cout<<"normal mult : "<<time_span1.count()<<endl;

	system("pause");
	return 0;
}