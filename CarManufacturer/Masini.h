#ifndef MASINI_H_INCLUDED
#define MASINI_H_INCLUDED

#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

template <class A, class B, class C>
class triplet
{
private:
    A f;
    B s;
    C t;
public:
    inline A get_f()
    {
        return f;
    }
    inline B get_s()
    {
        return s;
    }
    inline C get_t()
    {
        return t;
    }
    void set_f(A a)
    {
        f = a;
    }
    void set_s(B b)
    {
        s = b;
    }
    void set_t(C c)
    {
        t = c;
    }

};

using date = triplet<int,int,int>;

class Masina
{
protected:
    int an;
    string model;
    int vmax;
    int greutate;
public:

    virtual int calcul_autonomie() = 0;

};

class MasinaCombustie:virtual public Masina
{
protected:
    bool combustibil; //0 benzina, 1 motorina
    int capRezervor;
public:

    MasinaCombustie(int an = 0, string model = "", int vmax = 0, int geutate = 0, bool combustibil = false, int capRezervor = 0)
    //an(an),model(model),vmax(vmax),greutate(greutate), combustibil(combustibil), capRezervor(capRezervor)
    //lista de initializare nu vrea sa mearga
    {
        an = an;
        model=model;
        vmax = vmax;
        greutate=greutate;
        combustibil=combustibil;
        capRezervor=capRezervor;
    }
    MasinaCombustie& operator = (const MasinaCombustie& a)
    {
        an = a.an;
        model=a.model;
        vmax = a.vmax;
        greutate=a.greutate;
        combustibil=a.combustibil;
        capRezervor=a.capRezervor;
    }

    friend ostream& operator << (ostream& out, const MasinaCombustie a)
    {
        out<<a.an<<" "<<a.model<<" "<<a.vmax<<" km/h "<<a.greutate<<" kg ";
        if(a.combustibil == false)
            out<<"benzina ";
        else out<<" motorina ";
        out<<a.capRezervor<<" L\n\n";
        return out;
    }

    friend istream& operator >> (istream& in, MasinaCombustie& a)
    {
        in>>a.an>>a.model>>a.vmax>>a.greutate>>a.combustibil>>a.capRezervor;
        return in;
    }

    virtual ~MasinaCombustie(){}

    virtual int calcul_autonomie()
    {
        return static_cast<int> (static_cast<double> (capRezervor)/sqrt(greutate));
    }

};

class MasinaElectrica:virtual public Masina
{
protected:
    int capBaterie;
public:


    friend ostream& operator << (ostream& out, const MasinaElectrica a)
    {
        out<<a.an<<" "<<a.model<<" "<<a.vmax<<" km/h "<<a.greutate<<" kg ";

        out<<a.capBaterie<<" kW\n\n";
        return out;
    }

    friend istream& operator >> (istream& in, MasinaElectrica& a)
    {
        in>>a.an>>a.model>>a.vmax>>a.greutate>>a.capBaterie;
        return in;
    }

    virtual ~MasinaElectrica(){}

    virtual int calcul_autonomie()
    {
        return static_cast<int> (capBaterie/(greutate*greutate));
    }
};



class MasinaHibrida: virtual public MasinaCombustie, virtual public MasinaElectrica
{
private:

public:

    friend ostream& operator << (ostream& out, const MasinaHibrida a)
    {
        out<<a.an<<" "<<a.model<<" "<<a.vmax<<" km/h "<<a.greutate<<" kg ";
        out<<"benzina "<<a.capRezervor<<" L si ";
        out<<a.capBaterie<<" kW\n\n";
        return out;
    }

    friend istream& operator >> (istream& in, MasinaHibrida& a)
    {
        in>>a.an>>a.model>>a.vmax>>a.greutate>>a.combustibil>>a.capRezervor>>a.capBaterie;
        return in;
    }
    virtual ~MasinaHibrida(){}
    virtual int calcul_autonomie()
    {
        return MasinaCombustie::calcul_autonomie() + MasinaElectrica::calcul_autonomie();
    }
};

class Tranzactie
{
private:
    string nume;
    int nr; //pentru citire folosesc si numarul de masini
    date data;
    vector<Masina*> masini;
public:
    ~Tranzactie()
    {
        vector<Masina*>::iterator it;
        for(it = masini.begin(); it!=masini.end(); it++)
            delete(*it);
    }

    friend istream& operator >> (istream& in, Tranzactie& a)
    {
        in>>a.nume;
        int z,l,an;
        in>>z>>l>>an;
        date aux;
        aux.set_f(z);
        aux.set_s(l);
        aux.set_t(an);
        a.data = aux;
        in>>a.nr;

        for(int i = 0;i<a.nr;i++)
        {
            //Masina* auxi = new Masina(),  in>>*auxi, a.masini.push_back(auxi);
            int choice;
            in>>choice; //1 combustie, 2 electrica, 3 hibrida
            switch (choice)
            {
            case 1:
                Masina* auxi = new MasinaCombustie();  in>>*dynamic_cast<MasinaCombustie*> (auxi); a.masini.push_back(auxi); break;
            //case 2://la fel si penntru celelalte cazuri
                /*
            case 3:
                */
            }
        }
    }

    friend ostream& operator << (ostream& out, const Tranzactie& a)
    {
        out<<a.nume<<" ";//<<a.data.get_f()<<" "<<a.data.get_s()<<" "<<a.data.get_t();
        for(int i = 0;i < a.nr;i++)
        {
            if( MasinaHibrida* aux = dynamic_cast<MasinaHibrida*> (a.masini[i]))
                {out<<*aux;continue;}
            //la fel pentru celelalte
        }
    }


};

#endif // MASINI_H_INCLUDED
