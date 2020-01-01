#include "Pizza.h"
#include <fstream>

Pizza::Pizza()
{

}

Pizza::~Pizza() //totul e alocat static in pizza
{

}

const float Pizza::get_manopera()
{
    return pret_manopera;
}

string Pizza::get_nume()
{
    return nume;
}

vector<Ingredient> Pizza::get_ingr()
{
    return ingr;
}

float Pizza::calcul_pret()
{
    float pret_pizza = 0;
    std::vector<Ingredient>::iterator i;
    for(i = ingr.begin(); i != ingr.end(); i++)
        pret_pizza += i->pret_unitar * i->cantitate; //pretul pizzei este suma dintre toate ingr*cantitatea
    return pret_pizza + pret_manopera; //la pret se adauga si manopera
}

Pizza& Pizza:: operator = (const Pizza& a)
{
    nume = a.nume;
    nr_ingr = a.nr_ingr;
    ingr = a.ingr;
    return *this;
}


istream& operator >> (istream& in, Pizza& a)
{
    cout<<"Numele pizzei: ";
    in>>a.nume;
    cout<<"Numarul de ingrediente: ";
    in>>a.nr_ingr;
    Ingredient aux;
    for(int i = 0; i < a.nr_ingr; i++)
    {
        in>>aux;
        a.ingr.push_back(aux);
    }
}

ifstream& operator >> (ifstream& in, Pizza& a)
{
    in>>a.nume;
    in>>a.nr_ingr;
    Ingredient aux;
    for(int i = 0; i < a.nr_ingr; i++)
    {
        in>>aux;
        a.ingr.push_back(aux);
    }
}

void Pizza::afisare()
{
    cout<<nume<<":\n";
    std::vector<Ingredient>::iterator i;
    for(i = ingr.begin(); i != ingr.end(); i++)
        i->afisare();
        cout<<endl;

}

PizzaOnline& PizzaOnline:: operator = ( Pizza a)
{
    nume = a.get_nume();
    ingr = a.get_ingr();
    return *this;
}

istream& operator >> (istream& in, PizzaOnline a)
{
    cout<<"Nr km: \n";
    in>>a.nr_km;

    //folosind citirea de la Pizza
    Pizza aux;
    in>>aux;

    a = aux;

    return in;

}

ifstream& operator >> (ifstream& in, PizzaOnline a)
{
    in>>a.nr_km;

    //folosind citirea de la Pizza
    Pizza aux;
    in>>aux;

    a = aux;

    return in;

}

void PizzaOnline::afisare()
{
    cout<<nume<<" la distanta "<<nr_km<<":\n";
    std::vector<Ingredient>::iterator i;
    for(i = ingr.begin(); i != ingr.end(); i++)
        i->afisare();
        cout<<endl;
}

float PizzaOnline::calcul_pret()
{
    float pret = Pizza::calcul_pret(); //ne folosim de pretul pe loc
    if(nr_km >= 10)
        pret *= (1.0 + static_cast <float>(floor(nr_km/10)) * 0.05) ;
    //adaugam tariful pentru distanta
    return pret;
}
