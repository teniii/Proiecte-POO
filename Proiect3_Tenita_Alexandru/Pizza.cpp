#include "Pizza.h"

Pizza::Pizza()
{

}

Pizza::~Pizza()
{

}

const float Pizza::get_manopera()
{
    return pret_manopera;
}

float Pizza::calcul_pret()
{
    float pret_pizza = 0;
//        for(auto i : decod[nume])
    //pret_pizza+=i.pret_unitar*i.cantitate;
    return pret_pizza + pret_manopera;
}

Pizza& Pizza:: operator = (const Pizza& a)
{
    nume = a.nume;
    nr_ingr = a.nr_ingr;
}


istream& operator >> (istream& in, Pizza a)
{
    cout<<"Numele pizzei: ";
    in>>a.nume;
    cout<<"Numarul de ingrediente: ";
    in>>a.nr_ingr;
    //for(int i = 0;i < n; i++)
    //in>>

}

void Pizza::afisare()
{
    cout<<nume;
}

PizzaOnline& PizzaOnline:: operator = (const Pizza a)
{
    nume = a.nume;
    nr_ingr = a.nr_ingr;

}

istream& operator >> (istream& in, PizzaOnline a)
{
    //folosind citirea de la Pizza??
    Pizza aux;
    in>>aux;
    a = aux;
    cout<<"Nr km: ";
    in>>a.nr_km;
    /*
    cout<<"Numele pizzei: ";
    in>>a.nume;
    cout<<"Numarul de ingrediente: ";
    in>>a.nr_ingr;
    cout<<"Nr km: ";
    in>>a.nr_km;*/

}

void PizzaOnline::afisare()
{
    cout<<nume;
}

float PizzaOnline::calcul_pret()
{
    float pret = Pizza::calcul_pret();
    if(nr_km >= 10)
        pret *= (1.0 + static_cast <float>(floor(nr_km/10)) * 0.05) ;
    return pret;
}
