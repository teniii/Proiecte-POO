#ifndef NUMAR_COMPLEX_H_INCLUDED
#define NUMAR_COMPLEX_H_INCLUDED
#include <iostream>

using namespace std;

class numar_complex
{

private:
    double real, imag;

public:
    numar_complex(double a=0, double b=0);
    numar_complex(const numar_complex&);
    ~numar_complex();

    numar_complex operator +(const numar_complex&);
    numar_complex operator *(const numar_complex&);
    numar_complex& operator =(const numar_complex&);

    friend ostream& operator<<(ostream&, numar_complex&);
    friend istream& operator>>(istream&, numar_complex&);

    void afisare();
    void citire();

};


#endif // NUMAR_COMPLEX_H_INCLUDED
