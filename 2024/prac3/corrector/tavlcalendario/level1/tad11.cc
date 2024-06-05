// --------------------------------
// correctores: www.auladoce.com
// autor: jose manuel baldo pujante
// email: jmbp10m@msn.com
// corrector level1/tad11.cc
// --------------------------------

#include <iostream>
#include "tcalendario.h"
#include "tavlcalendario.h"
using namespace std;

int main()
{
	TCalendario 	c1(1, 1, 2010, NULL), 
			c2(1, 1, 2020, NULL), 
			c3(1, 1, 2030, NULL), 
			c4(1, 1, 2040, NULL), 
			c5(1, 1, 2050, NULL);
	TAVLCalendario a;
	TCalendario cx(1, 1, 2012, NULL);


	a.Insertar(c4);
	a.Insertar(c5);   
	a.Insertar(c2);
	a.Insertar(c1);
	a.Insertar(c3);
  
	TAVLCalendario b;
	b = a;
  
	cout << "a.Inorden(): " << a.Inorden() << endl << "a.Preorden(): " << a.Preorden() << endl;
	cout << "b.Inorden(): " << b.Inorden() << endl << "b.Preorden(): " << b.Preorden() << endl;

	if(a == b)
		cout << "a y b son iguales" << endl;
	else
		cout << "no rula el = o el ==" << endl;
	
	TAVLCalendario c, d;
	d = c;
	cout << "c.Inorden(): " << c.Inorden() << endl << "c.Preorden(): " << c.Preorden() << endl;
	cout << "d.Inorden(): " << d.Inorden() << endl << "d.Preorden(): " << d.Preorden() << endl;
  
	if(c == d)
		cout << "c y d son iguales" << endl;
	else
		cout << "no rula el = o el == con dos vacios" << endl;
	
	c.Insertar(cx);
	if(c != d)
		cout << "c y d son distintos ahora" << endl;
	else
		cout << "no rula el = o el !=" << endl;
  
  return 0;
}
