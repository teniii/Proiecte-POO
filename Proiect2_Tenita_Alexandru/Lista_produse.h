#ifndef LISTA_PRODUSE_H_INCLUDED
#define LISTA_PRODUSE_H_INCLUDED

#include "Produs.h"
#include <vector>

using std::vector;

class Lista_cumparaturi
{
    vector <Produs*> v;
    int n;
    //int total;
public:
    Lista_cumparaturi(int, vector <Produs*>);
    Lista_cumparaturi(const Lista_cumparaturi&);
    ~Lista_cumparaturi();

    //Lista_cumparaturi operator + (const Lista_cumparaturi&);
    Lista_cumparaturi operator - (const Produs*);
    Lista_cumparaturi operator - (const ProdusCuBrand*&);
    Lista_cumparaturi operator - (const VinDeSoi*&);
    Lista_cumparaturi operator = (const Lista_cumparaturi&);

    friend ostream& operator << (ostream&, Lista_cumparaturi&);
    friend ofstream& operator << (ofstream&, Lista_cumparaturi&);
    friend ifstream& operator >> (ifstream&, Lista_cumparaturi&);

    int get_total();
    int get_n();
    bool elem_is_equal(int,Lista_cumparaturi,int);
    void push_back(Produs*);

    Produs* get_elem(int );
    Lista_cumparaturi imbinare(Lista_cumparaturi&);
    Lista_cumparaturi citire_client(ifstream&);
};


#endif // LISTA_PRODUSE_H_INCLUDED
