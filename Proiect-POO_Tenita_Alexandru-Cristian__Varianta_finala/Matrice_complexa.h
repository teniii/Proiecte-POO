#ifndef MATRICE_COMPLEXA_H_INCLUDED
#define MATRICE_COMPLEXA_H_INCLUDED

#include "Numar_complex.h"
#include <iostream>

using namespace std;

class mat_com  //clasa mat_com reprezinta clasa matrice complexa
{

private:
    int nrl,nrc;
    numar_complex** matrice;

public:
    mat_com(int a=0, int b=0,int c=0);
    mat_com(const mat_com&);
    ~mat_com();

    friend ostream& operator<<(ostream&, mat_com&);
    friend istream& operator>>(istream&, mat_com&);
    //friend class numar_complex;

    mat_com operator +(const mat_com&);//mat_com suma(mat_com);
    mat_com operator *(const mat_com&);
    mat_com& operator =(const mat_com&);


};

#endif // MATRICE_COMPLEXA_H_INCLUDED
