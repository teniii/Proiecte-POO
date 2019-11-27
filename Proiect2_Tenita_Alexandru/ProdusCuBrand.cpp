#include "Produs.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

ProdusCuBrand:: ProdusCuBrand(int pret = 0, int cost = 0, int cantitate = 1, const string& um = "buc", const string& denumire = "ProdusCuBrand", const string& tip = "standard", const string& brand = "Carlsber"):
    //pret(pret),cost(cost),cantitate(cantitate), um(um), denumire(denumire), tip(tip)
    Produs(pret, cost, cantitate, um, denumire, tip)
    {
        this->brand = brand;
    }

ProdusCuBrand:: ProdusCuBrand(const ProdusCuBrand& a):
    //pret(pret),cost(a.cost),cantitate(a.cantitate), um(a.um), denumire(a.denumire), tip(a.tip)
    Produs(a.pret,a.cost, a.cantitate, a.um, a.denumire, a.tip)
    {
        this->brand = a.brand;
    }

ProdusCuBrand:: ~ProdusCuBrand(){}

Produs ProdusCuBrand:: operator + (const ProdusCuBrand& a)
{
    Produs rez(*this);
    rez.cost += a.cost; //cand facem totalul si adunam toate ProdusCuBrandele ne
    rez.pret += a.pret; //intereseaza doar costul si pretul
    return rez;
}

Produs ProdusCuBrand:: operator + (const Produs& a)
{
    Produs rez(*this);
    rez.cost += a.cost; //cand facem totalul si adunam toate ProdusCuBrandele ne
    rez.pret += a.pret; //intereseaza doar costul si pretul
    return rez;
}

Produs ProdusCuBrand:: operator + (const VinDeSoi& a)
{
    Produs rez(*this);
    rez.cost += a.cost; //cand facem totalul si adunam toate ProdusCuBrandele ne
    rez.pret += a.pret; //intereseaza doar costul si pretul
    return rez;
}

ProdusCuBrand ProdusCuBrand:: operator = (const ProdusCuBrand& a)
{
    pret = a.pret;
    cost = a.cost;
    cantitate = a.cantitate;
    um = a.um;
    denumire = a.denumire;
    tip = a.tip;
    brand = a.brand;
    return *this;
}

bool ProdusCuBrand:: operator == (const ProdusCuBrand& a)
{
    if(denumire == a.denumire && tip == a.tip && brand == a.brand)
        return 1;
    return 0;
}

void ProdusCuBrand:: citire(const string ajutor)
{
    char* s;
    strcpy(s,ajutor.c_str());
    char* cuv=strtok(s," ");

        denumire = cuv;
        cuv = strtok (NULL, " ");
        tip = cuv;
        cuv = strtok (NULL, " ");
        brand = cuv;
        cuv = strtok(NULL, " ");
        cantitate = atoi(cuv);
        cuv=strtok (NULL," ");
        um=cuv;
        cuv = strtok (NULL, " ");
        cost = atoi(cuv);
        cuv = strtok (NULL, " ");
        pret = atoi (cuv);
}

ifstream& operator >> (ifstream& fin, ProdusCuBrand*& a)
{
    fin>>a->denumire;
    fin>>a->tip;
    fin>>a->brand;
    fin>>a->cantitate;
    fin>>a->um;
    fin>>a->cost;
    fin>>a->pret;
    return fin;
}

ostream& operator << (ostream& out, ProdusCuBrand*& a)
{
    out<<a->denumire<<" "<<a->tip<<" "<<a->brand<<" "<<a->cantitate<<" "<<a->um<<endl;
    return out;
}

ofstream& operator << (ofstream& fout, ProdusCuBrand*& a)
{
    fout<<a->denumire<<" "<<a->tip<<" "<<a->brand<<" "<<a->cantitate<<" "<<a->um<<endl;
    return fout;
}
