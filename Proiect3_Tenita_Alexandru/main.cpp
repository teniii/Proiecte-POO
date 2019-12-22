#include <iostream>
#include "Pizza.h"
//#include "Ingredient.h"

using namespace std;

int main()
{
    Pizza x ;
    cout << "Manopera impusa de producator este de "<< x.get_manopera() << " lei\n"<< endl;
    Ingredient i;
    PizzaOnline po;
    x = po;
    x.afisare();
    cin>>i;
    i.afisare();
    Ingredient j = i;
    j.afisare();
    return 0;
}
