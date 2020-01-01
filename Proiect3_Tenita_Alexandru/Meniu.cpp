#include "Meniu.h"
#include <iostream>
#include"Pizza.h"

template <class T>
Meniu<T>::Meniu()
{

}

template <class T>
Meniu<T>::~Meniu()
{
    //stergem pointerii memorati in vectorul lista
    //fiind aceeasi pointeri cu cei din unordered_map,
    //nu e nevoie sa o parcurgem si pe aceea
    typename vector<T*>::iterator it = lista.begin();
    for(it = lista.begin(); it != lista.end();++it)
        delete *it;
}

template <class T>
Meniu<T>& Meniu<T>::operator += (const T* a) //incrementam nr de vanzari
{
    nr_vanzari[a] = nr_vanzari[a] + 1;
    return *this;

}

template <class T>
void Meniu<T>:: citire(ifstream& in)
{
    int n;
    in>>n;
    //in meniu se vor memora doar tipurile de pizza comercializate
    for(size_t i=0; i < n; i++)
    {
        Pizza* aux = new Pizza();
        in>>*aux;
        aux->afisare();
        lista.push_back(aux);
        nr_vanzari.insert(std::make_pair<const T*, int> (aux,0)); // nr_vanzari[aux] = 0;
    }
}

//o varianta anterioara de citire cu care am avut probleme si la care am renuntat

/*
template <class T = Pizza>
ifstream& operator >> (ifstream& in, Meniu<T>& a)
{
    int n;
    std::string optiune;
    in>>n;
    for(size_t i=0;i<n;i++)
    {
        std::getline(in,optiune);
        if (optiune == "aici")
        {
            Pizza* aux = new Pizza();
            in>>*aux;
            a.nr_vanzari[aux->get_nume()]++;
            a.lista[aux] = aux->get_ingr();
        }
        else
        {
            PizzaOnline* aux = new PizzaOnline();
            in>>*aux;
            a.nr_vanzari[aux->get_nume()]++;
            a.lista[dynamic_cast<Pizza*>(aux)] = aux->get_ingr();
        }
    }
    return in;
}

*/

template <class T>
std::unordered_map <const T*,int> Meniu<T>::get_nr_vanz()
{
    return nr_vanzari;
}
