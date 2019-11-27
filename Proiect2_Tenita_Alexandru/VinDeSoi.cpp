#include "Produs.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

VinDeSoi:: VinDeSoi(int pret = 0, int cost = 0, int cantitate = 1, const string& um = "buc", const string& denumire = "Vin", const string& tip = "rosu_Sec", const string& soi = "Merlot", const string& tara = "Romania", int an = 2019):
    //pret(pret),cost(cost),cantitate(cantitate), um(um), denumire(denumire), tip(tip)
    Produs(pret, cost, cantitate, um, denumire, tip)
    {
        this->soi = soi;
        this->an = an;
        this->tara = tara;
    }

VinDeSoi:: VinDeSoi(const VinDeSoi& a):
    //pret(pret),cost(a.cost),cantitate(a.cantitate), um(a.um), denumire(a.denumire), tip(a.tip)
    Produs(a.pret,a.cost, a.cantitate, a.um, a.denumire, a.tip)
    {
        this->soi = soi;
        this->an = an;
        this->tara = tara;
    }

VinDeSoi:: ~VinDeSoi(){}

VinDeSoi VinDeSoi:: operator + (const VinDeSoi& a)
{
    VinDeSoi rez(*this);
    rez.cost += a.cost; //cand facem totalul si adunam toate VinDeSoiele ne
    rez.pret += a.cost; //intereseaza doar costul si pretul
    return rez;
}

VinDeSoi VinDeSoi:: operator = (const VinDeSoi& a)
{
    pret = a.pret;
    cost = a.cost;
    cantitate = a.cantitate;
    um = a.um;
    denumire = a.denumire;
    tip = a.tip;
    an = a.an;
    soi = a.soi;
    tara = a.tara;
    return *this;
}

bool VinDeSoi:: operator == (const VinDeSoi& a)
{
    if(denumire == a.denumire && tip == a.tip && soi == a.soi)
        return 1;
    return 0;
}

void VinDeSoi:: citire(string ajutor)
{
    char* s;
    strcpy(s,ajutor.c_str());
    char* cuv=strtok(s," ");

        denumire = cuv;
        cuv = strtok (NULL, " ");
        tip = cuv;
        cuv = strtok (NULL, " ");
        soi = cuv;
        cuv = strtok(NULL, " ");
        soi.append(cuv);
        cuv = strtok(NULL, " ");
        an = atoi(cuv);
        cuv = strtok(NULL, " ");
        cantitate = atoi(cuv);
        cuv=strtok (NULL," ");
        um=cuv;
        cuv = strtok (NULL, " ");
        cost = atoi(cuv);
        cuv = strtok (NULL, " ");
        pret = atoi (cuv);
}

ifstream& operator >> (ifstream& fin, VinDeSoi*& a)
{
    string aux;
    fin>>a->denumire;
    fin>>a->tip;
    fin>>a->soi;
    a->soi+=" ";
    fin>>aux;
    a->soi+=aux;
    fin>>a->an;
    fin>>a->cantitate;
    fin>>a->um;
    fin>>a->cost;
    fin>>a->pret;
    return fin;
}

ostream& operator << (ostream& out, VinDeSoi*& a)
{
    out<<a->denumire<<" "<<a->tip<<" "<<a->soi<<" "<<a->an<<" "<<a->cantitate<<" "<<a->um<<endl;
    return out;
}

ofstream& operator << (ofstream& fout, VinDeSoi*& a)
{
    fout<<a->denumire<<" "<<a->tip<<" "<<a->soi<<" "<<a->an<<" "<<a->cantitate<<" "<<a->um<<endl;
    return fout;
}
