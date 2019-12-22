#ifndef INGREDIENT_H_INCLUDED
#define INGREDIENT_H_INCLUDED

#include <string>
#include <iostream>

using namespace std;

class Ingredient{
private:
    std::string nume;
    float pret_unitar;
    int cantitate;

public:

    Ingredient();
    ~Ingredient();

    Ingredient& operator = (const Ingredient&);
    friend istream& operator >> (istream&, Ingredient&);
    void afisare();

    friend class Pizza;

};


#endif // INGREDIENT_H_INCLUDED
