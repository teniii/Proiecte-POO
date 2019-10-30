#ifndef INFORMATII_COMPLETE_H_INCLUDED
#define INFORMATII_COMPLETE_H_INCLUDED

#include "Matrice_complexa.h"
#include <iostream>

using namespace std;

class info
{

private:
    int n;
    mat_com* v;

public:
    info(int a=0);
    ~info();

    friend ostream& operator <<(ostream&,info&);
    friend istream& operator >>(istream&,info&);

};

#endif // INFORMATII_COMPLETE_H_INCLUDED
