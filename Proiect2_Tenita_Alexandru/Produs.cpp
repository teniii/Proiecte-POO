#include "Produs.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

Produs:: Produs(int pret = 0, int cost = 0, int cantitate = 1, const string& um = "buc", const string& denumire = "produs", const string& tip = "standard"):
    pret(pret),cost(cost),cantitate(cantitate), um(um), denumire(denumire), tip(tip){}

Produs:: Produs(const Produs& a):
    pret(a.pret),cost(a.cost),cantitate(a.cantitate), um(a.um), denumire(a.denumire), tip(a.tip){}

Produs:: ~Produs(){}

Produs Produs:: operator + (const Produs& a)
{
    Produs rez(*this);
    rez.cost += a.cost; //cand facem totalul si adunam toate produsele ne
    rez.pret += a.pret; //intereseaza doar costul si pretul
    return rez;
}

Produs Produs:: operator + (const ProdusCuBrand& a)
{
    Produs rez(*this);
    rez.cost += a.cost; //cand facem totalul si adunam toate produsele ne
    rez.pret += a.pret; //intereseaza doar costul si pretul
    return rez;
}

Produs Produs:: operator + (const VinDeSoi& a)
{
    Produs rez(*this);
    rez.cost += a.cost; //cand facem totalul si adunam toate produsele ne
    rez.pret += a.pret; //intereseaza doar costul si pretul
    return rez;
}

Produs Produs:: operator = (const Produs& a)
{
    pret = a.pret;
    cost = a.cost;
    cantitate = a.cantitate;
    um = a.um;
    denumire = a.denumire;
    tip = a.tip;
    return *this;
}

bool Produs:: operator == (const Produs*& a)
{
    if(denumire == a->denumire && tip == a->tip)
        return 1;
    return 0;
}

void Produs:: citire(string ajutor)
{
    char* s;
    strcpy(s,ajutor.c_str());
    char* cuv=strtok(s," ");

        denumire = cuv;
        cuv = strtok (NULL, " ");
        tip = cuv;
        cuv = strtok (NULL, " ");
        cantitate = atoi(cuv);
        cuv=strtok (NULL," ");
        um=cuv;
        cuv = strtok (NULL, " ");
        cost = atoi(cuv);
        cuv = strtok (NULL, " ");
        pret = atoi (cuv);
}

ifstream& operator >> (ifstream& fin, Produs*& a)
{
    fin>>a->denumire;
    fin>>a->tip;
    fin>>a->cantitate;
    fin>>a->um;
    fin>>a->cost;
    fin>>a->pret;
    return fin;
}

ostream& operator << (ostream& out, Produs*& a)
{
    out<<a->denumire<<" "<<a->tip<<" "<<a->cantitate<<" "<<a->um<<endl;
    return out;
}

ofstream& operator << (ofstream& fout, Produs*& a)
{
    fout<<a->denumire<<" "<<a->tip<<" "<<a->cantitate<<" "<<a->um<<endl;

    return fout;
}

string Produs:: get_denum()
{
    return this->denumire;
}

string Produs:: get_tip()
{
    return this->tip;
}

int Produs:: get_pret()
{
    return this->pret;
}

int Produs:: get_cost()
{
    return this->cost;
}
