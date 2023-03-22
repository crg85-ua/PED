#include "tcomplejo.h"
#include <iostream>

using namespace std;


int main(void)
{
  TComplejo a;
  TComplejo b(a);
  TComplejo c;
  c = a;
  
  if(a == b)
    cout << "SI" << endl;
  else
    cout << "NO" << endl;

  if(a == c)
    cout << "SI" << endl;
  else
    cout << "NO" << endl;


  return 0;
}
