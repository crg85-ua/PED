#ifndef _TCOMPLEJO
#define _TCOMPLEJO
#include<iostream>

using namespace std;

class TComplejo
{
private:
    double re;
    double im;
public:
    TComplejo();

    ~TComplejo();

    TComplejo(double);

    TComplejo(double , double);

    TComplejo(TComplejo&);

    TComplejo& operator=(const TComplejo&);
};

#endif;