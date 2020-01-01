#ifndef MENIU_H_INCLUDED
#define MENIU_H_INCLUDED

#include "Pizza.h"
#include <vector>
#include <unordered_map>
#include <fstream>

template <class T = Pizza>
class Meniu
{
private:

    std::vector <T*> lista; //lista de pizze comercializate
    std::unordered_map <const T*,int> nr_vanzari; //nr de vanzari pentru fiecare tip de pizza din meniu
    //static std::unordered_map <T*, std::vector <Ingredient>> lista ;

public:

    Meniu<T>();
    ~Meniu<T>();

    Meniu<T>& operator += (const T*); //pentru a incrementa nr de vanzari

    friend ifstream& operator >> (ifstream&, Meniu<T>&); //am avut erori cu asta
    void citire(ifstream&); //asa ca am facut metode de citire

    inline std::unordered_map <const T*,int> get_nr_vanz(); //getter pentru nr_vanzari

};


template <class T = Pizza> float venit_veget(Meniu<T> m) //specializarea pentru pizze vegetariene
{
    std::unordered_map <const T*,int> aux = m.get_nr_vanz();
    typename std::unordered_map <const T*,int>::iterator i;
    float suma = 0;
    PizzaOnline veggie; //variabila in care se va memora valoarea iteratorului
    for ( i = aux.begin(); i != aux.end(); i++)
    {
        if(dynamic_cast<PizzaOnline> (i->first)) // daca se poate converti la pizza online, memoram in variabila
        {
            veggie = dynamic_cast<PizzaOnline> (i->first); //memoram
            if(veggie.get_nume().find("veget") != std::string::npos) // daca pizza este si online, si vegetariana, atunci adaugam la suma totala
                suma += i->second * veggie.calcul_pret(); // suma este suma anterioara la care se adauga produsul dintre nr de pizze si pretul ei
        }
    }
    ofstream out ("docContabilitate.out");
    out<<suma;
    out.close();

    return suma;
}

#endif // MENIU_H_INCLUDED
