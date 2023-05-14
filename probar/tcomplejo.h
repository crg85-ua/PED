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
        
        TComplejo();

        TComplejo(double re);

        TComplejo(double re, double im);

        TComplejo(const TComplejo&);

        TComplejo& operator=(const TComplejo&);

        TComplejo operator+ (const TComplejo&) const;
        TComplejo operator- (const TComplejo&) const;
        TComplejo operator* (const TComplejo&) const;
        TComplejo operator+ (double) const;
        TComplejo operator- (double) const;
        TComplejo operator* (double) const;

        bool operator== (const TComplejo&) const;
        bool operator!= (const TComplejo&) const;

        double Re() const;
        double Im() const;

        void Re(double);
        void Im(double);

        double Arg(void);
        double Mod(void);

        friend ostream& operator<<(ostream&, const TComplejo&);

        friend TComplejo operator+ (double, const TComplejo&);
        friend TComplejo operator- (double, const TComplejo&);
        friend TComplejo operator* (double, const TComplejo&);



};

#endif