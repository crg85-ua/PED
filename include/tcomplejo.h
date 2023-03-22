#ifndef _TCOMPLEJO
#define _TCOMPLEJO
#include <iostream>

using namespace std;

class TComplejo
{
    private:
        double re;
        double im;
    public:
        ~TComplejo();

        TComplejo(double = 0.0 , double = 0.0);

        TComplejo(TComplejo&);

        TComplejo& operator=(TComplejo&);

        TComplejo operator+ (TComplejo&);
        TComplejo operator- (TComplejo&);
        TComplejo operator* (TComplejo&);
        TComplejo operator+ (double);
        TComplejo operator- (double);
        TComplejo operator* (double);

        bool operator== (TComplejo&);
        bool operator!= (TComplejo&);

        double Re();
        double Im();

        void Re(double);
        void Im(double);

        double Arg(void);
        double Mod(void);

        friend ostream& operator<<(ostream&, TComplejo&);

        friend TComplejo operator+ (double, TComplejo&);
        friend TComplejo operator- (double, TComplejo&);
        friend TComplejo operator* (double, TComplejo&);



};

#endif