#include "Date.h"
#include <iostream>
#include "TimeStamp.h"

using namespace std;

int main() 
{
	CDate* d1 = new CDate(10, 2, 1900);
	CDate* d2 = new  CDate(20, 10, 1945);
	CDate* d3 = new CDate(15, 4, 1960);
	CDate* d4 = new  CDate(15, 4, 2018);
	CDate* d5 = new CDate(10, 2, 1900);

	cout << (*d1 == *d5) << endl;
	cout << (*d4 == *d5) << endl;
	cout << (*d2 == *d5) << endl<<endl;

	d1->vPrintDate();
	d2->vPrintDate();
	d3->vPrintDate();
	d4->vPrintDate();

	cout<<endl <<"PRZERWA"<< endl<<endl;

	*d1+365;
	d1->vPrintDate();
	cout << "ROZNICA DAT: "<<endl;
	cout << (*d5 - *d1) << endl;
	cout << (*d1 - *d5) << endl;
	*d1 + 365;
	d1->vPrintDate();
	*d1 + 365;
	d1->vPrintDate();
	*d1 + 365;
	d1->vPrintDate();
	*d1 + 365;
	d1->vPrintDate();
	*d1 + 365;
	//d1->vAddDays(365);
	d1->vPrintDate();
	cout << (*d1 - *d5)/5 << endl;
	*d1 - 365;
	d1->vPrintDate();
	cout << (*d1 - *d5)/4 << endl;



	cout<<endl << (*d1 > *d5)<<endl;


	cout << endl << "TIMESTAMPS" << endl;
	
	CTimeStamp* cts1 = new CTimeStamp(1, 1, 1900, 0, 0);
	CTimeStamp* cts2 = new CTimeStamp(1, 1, 1900, 10, 0);
	cts1->vPrintTimeStamp();
	cts1->vPrintDate();

	cts2->vPrintTimeStamp();
	cts2->vPrintDate();
	cout << (*cts2 - *cts1) << endl;

	CTimeStamp* cts3 = new CTimeStamp(15, 7, 1945, 13, 46);
	cts3->vPrintTimeStamp();
	cts3->vPrintDate();


	cout << "TESTTSETSETESTSET" << endl << endl << endl;
	CTimeStamp* ts= new CTimeStamp(1, 1, 1900, 0, 0);
	CTimeStamp* ts2 = new CTimeStamp(1, 1, 1900, 10, 0);
	CDate * dx=&(*ts);
	CDate * dx2 = &(*ts2);

	cout<<"DATE" << (*dx == (*dx2))<<endl;
	cout<<"TIMESTAMP" << (*ts == (*ts2))<<endl;

	system("pause");

	delete d1;
	delete d2;
	delete d3;
	delete d4;
	delete d5;
	delete cts1;
	delete cts2;
	delete cts3;
	return 0;
}//int main() 