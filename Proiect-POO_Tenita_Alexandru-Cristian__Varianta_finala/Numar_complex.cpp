#include "Numar_complex.h"
#include <iostream>

using namespace std;

numar_complex::numar_complex(double a, double b)
{
    real=a;
    imag=b;
}

numar_complex::numar_complex(const numar_complex& nr)
{
    real=nr.real;
    imag=nr.imag;
}

numar_complex::~numar_complex() {}

void numar_complex:: afisare()
{
    if(imag==0 && real==0)
        cout<<0;
    else
    {
        if(imag==0)
            cout<<real;
        else
        {
            if(real==0)
            {
                if(imag<0)
                    cout<<"-i*"<<(-1)*imag;
                else
                    cout<<"i*"<<imag;
            }
            else
            {
                if(imag<0)
                    cout<<real<<"-i*"<<(-1)*imag;
                else
                    cout<<real<<"+i*"<<imag;
            }
        }
    }
}

ostream& operator<<(ostream& out, numar_complex& nr)
{
    nr.afisare();
    return out;
}

istream& operator>>(istream& in, numar_complex& nr)
{
    double a,b;
    cout<<"Introduceti partea reala si cea imaginara: ";
    in>>a>>b;
    //cout<<endl<<"Introduceti partea imaginara: ";
    //in>>b;
    cout<<endl;

    nr.real=a;
    nr.imag=b;

    return in;
}

numar_complex& numar_complex::operator =(const numar_complex& nr)
{
    this->real=nr.real;
    imag=nr.imag;
    return *this;
}

numar_complex numar_complex::operator+(const numar_complex& el)
{
    numar_complex rez;
    rez.real=this->real+el.real;
    rez.imag=imag+el.imag;
    return rez;
}

numar_complex numar_complex::operator*(const numar_complex& el)
{
    //double re=real;
    numar_complex rez;
    rez.real=real*el.real-imag*el.imag; //din produsul partilor reale se scade produsul partilor imaginare
    rez.imag=real*el.imag+imag*el.real;//partea reala a unui se inmulteste cu cea imaginara a celuilalt si apoi se aduna cu produsul anterior, facut invers
    return rez;
}

