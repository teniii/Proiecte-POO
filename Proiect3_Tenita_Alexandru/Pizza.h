#ifndef PIZZA_H_INCLUDED
#define PIZZA_H_INCLUDED

#include <unordered_map>
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include <fstream>
#include "Ingredient.h"

//clasa de baza cu metoda pur virtuala calcul_pret
class Contabilitate{

public:
    virtual float calcul_pret() = 0;
};

class Pizza: public Contabilitate{

protected:
    std::string nume;
    int nr_ingr;
    std::vector <Ingredient> ingr;
    const float pret_manopera= 30;

public:

    Pizza();
    ~Pizza();

    Pizza& operator = (const Pizza&);
    //Pizza& operator = (const PizzaOnline&);

    const float get_manopera();
    inline string get_nume();
    inline vector <Ingredient> get_ingr();

    virtual float calcul_pret();
    virtual void afisare();

    friend ifstream& operator >> (ifstream&, Pizza&);
    friend istream& operator >> (istream&, Pizza&);
};

class PizzaOnline: public Pizza{

protected:
    int nr_km;
public:
    PizzaOnline(){}
    ~PizzaOnline(){}

    PizzaOnline& operator = (PizzaOnline);
    PizzaOnline& operator = (Pizza);

    virtual float calcul_pret();
    virtual void afisare();

    friend ifstream& operator >> (ifstream&, PizzaOnline);
    friend istream& operator >> (istream&, PizzaOnline);


};




#endif // PIZZA_H_INCLUDED
