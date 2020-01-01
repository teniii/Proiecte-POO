#include <iostream>
#include "Pizza.h"
#include <fstream>
#include "Meniu.cpp"

using namespace std;



int main()
{
    char c = '!';
    ifstream fin ("ListaDePizza.in");
    ifstream comenzi ("Comenzi");
    try
    {
        if(fin.is_open() == 0)
            throw c;
    }
    catch (char c)
    {
        cout<<"Eroare la deschiderea Listei de pizza!\n";
        return -1;
    }

    try
    {
        if(comenzi.is_open() == 0)
            throw c;
    }
    catch (char c)
    {
        cout<<"Eroare la deschiderea Comenzilor!\n";
        return -1;
    }

    Meniu<Pizza> m;
    m.citire(fin);
    //m.afisare();

    unsigned int nrComenzi;
    comenzi>>nrComenzi;
    string optiune;
    for(size_t i = 0; i < nrComenzi ; ++i)
    {
        std::getline(comenzi,optiune);
        if (optiune == "aici")
        {
            Pizza* aux = new Pizza();
            comenzi>>*aux;
            m += aux;
            //aux->afisare();
        }
        else
        {
            PizzaOnline* aux = new PizzaOnline();
            comenzi>>*aux;
            m += aux;
            //aux->afisare();
        }
    }

    venit_veget<>(m); //aici primesc eroarea legata de get_nume si calcul_pret

    return 0;
}
