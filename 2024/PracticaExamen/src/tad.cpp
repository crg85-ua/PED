#include <iostream>

using namespace std;

#include "tcalendario.h"
#include "tlistacalendario.h"
#include "tavlcalendario.h"

int
main(void)
{
  //tavl
  TCalendario a(06,10,2006, (char*) "mensaje");
  TCalendario b(03,10,2006, (char*) "mensaje");
  TCalendario c(8,10,2006, (char*) "mensaje");
  TCalendario d(01,10,2006, (char*) "mensaje");
  TCalendario e(05,10,2006, (char*) "mensaje");
  TCalendario f(07,10,2006, (char*) "mensaje");
  TCalendario g(10,10,2006, (char*) "mensaje");

//lista
  TCalendario h(01,10,2006, (char*) "mensaje");
  TCalendario i(06,10,2006, (char*) "mensaje");
  TCalendario j(8,10,2006, (char*) "mensaje");
  TCalendario k(25,10,2006, (char*) "mensaje");
  // TCalendario l(21,10,2006, (char*) "mensaje 12");


  TListaCalendario lista;
  lista.Insertar(h);
  lista.Insertar(i);
  lista.Insertar(j);
  lista.Insertar(k);

  TAVLCalendario cal;
  cal.Insertar(a);
  cal.Insertar(b);
  cal.Insertar(c);
  cal.Insertar(d);
  cal.Insertar(e);
  cal.Insertar(f);
  cal.Insertar(g);

  int* pru = cal.BuscaAVL(lista);
  for (int i = 0; i < sizeof(pru); i++)
  {
    cout << pru[i] << endl;
  }
  return 0;
}
