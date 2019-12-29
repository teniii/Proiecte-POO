#include "Ingredient.h"
#include <iostream>
#include <fstream>

Ingredient :: Ingredient() {}

Ingredient :: ~Ingredient() {}

Ingredient& Ingredient:: operator = (const Ingredient& a)
{
    nume = a.nume;
    pret_unitar = a.pret_unitar;
    cantitate = a.cantitate;
}

ifstream& operator >> (ifstream & in, Ingredient& a)
{
    std::getline(in, a.nume);
    cout<<"\nIntroduceti numele ingredientului: ";
    std::getline(in, a.nume);

    cout<<"\nPretul unitar: ";
    in>>a.pret_unitar;

    cout<<"\nCantitatea: ";
    in>>a.cantitate;
    cout<<endl;

    return in;
}

void Ingredient::afisare()
{
    cout<<nume<<" cu pretul "<<pret_unitar<<" si in cantitate de "<<cantitate<<endl;

}
