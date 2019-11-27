#ifndef TRANZACTII_H_INCLUDED
#define TRANZACTII_H_INCLUDED

#include "Lista_produse.h"

class Tranzactii
{
private:
    int nr;
    Lista_cumparaturi depozit;
    vector <Lista_cumparaturi> clienti;
    vector <Lista_cumparaturi> medieri;
    static Tranzactii* elementul;



public:
    Tranzactii(int,Lista_cumparaturi);
    static Tranzactii* get_element();
    void citire(ifstream&);
    void afisare(ofstream&);
    ~Tranzactii();

};



#endif // TRANZACTII_H_INCLUDED
