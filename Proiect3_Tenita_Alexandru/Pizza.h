#ifndef PIZZA_H_INCLUDED
#define PIZZA_H_INCLUDED

#include <unordered_map>
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include "Ingredient.h"

class Contabilitate{

public:
    virtual float calcul_pret() = 0;
};

class Pizza: public Contabilitate{

protected:
    std::string nume;
    int nr_ingr;
    //std::vector <Ingredient> v;
    const float pret_manopera= 30;
    //static std::unordered_map <std::string, std::vector <Ingredient>> decod ;
public:

    Pizza();
    ~Pizza();

    Pizza& operator = (const Pizza&);
    //Pizza& operator = (const PizzaOnline&);


    const float get_manopera();
    virtual float calcul_pret();
    virtual void afisare();

    friend istream& operator >> (istream&, Pizza);
    friend class PizzaOnline;
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

    friend istream& operator >> (istream&, PizzaOnline);
};


#endif // PIZZA_H_INCLUDED
