#include "Lista_produse.h"
#include <vector>
#include <fstream>
#include <cstring>


Lista_cumparaturi::Lista_cumparaturi(int n, vector <Produs*> v)
//n(n), v(v)
{
    this->n = n;
    this->v = v;
}

Lista_cumparaturi::Lista_cumparaturi(const Lista_cumparaturi& a):
    n(a.n), v(a.v) {}

Lista_cumparaturi::~Lista_cumparaturi()
{
    for(int i =0;i<v.size();i++)
        delete(v[i]);
}

Lista_cumparaturi Lista_cumparaturi::operator - (const Produs* a)
{
    Lista_cumparaturi aux(*this);
    for(int i = 0; i < this->n; i++)
    {
        if( this->v[i]->denumire == a->denumire && this->v[i]->tip == a->tip)
        {
            aux.v[i]->cantitate = this->v[i]->cantitate - a->cantitate;
            break;
        }
    }
    return aux;
}

Lista_cumparaturi Lista_cumparaturi::operator - (const ProdusCuBrand*& a)
{
    Lista_cumparaturi aux(*this);
    for(int i = 0; i < this->n; i++)
    {
        if( this->v[i]->denumire == a->denumire && this->v[i]->tip == a->tip)// && this->v[i].brand == a.brand)
        {
            aux.v[i]->cantitate = this->v[i]->cantitate - a->cantitate;
            break;
        }
    }
    return aux;
}

Lista_cumparaturi Lista_cumparaturi::operator - (const VinDeSoi*& a)
{
    Lista_cumparaturi aux(*this);
    for(int i = 0; i < this->n; i++)
    {
        if( this->v[i]->denumire == a->denumire && this->v[i]->tip == a->tip)// && this->v[i].brand == a.brand)
        {
            aux.v[i]->cantitate = this->v[i]->cantitate - a->cantitate;
            break;
        }
    }
    return aux;
}

Lista_cumparaturi Lista_cumparaturi:: operator = (const Lista_cumparaturi& a)
{
    n = a.n;
    v = a.v;
    return *this;
}

ostream& operator << (ostream& out, Lista_cumparaturi & l)
{
    for(int i = 0; i < l.n; i++)
    {
        out<<l.v[i]<<endl;
    }

    out<<l.get_total();
    return out;
}

ifstream& operator >> (ifstream& fin, Lista_cumparaturi& l)
{
    fin>>l.n;
    Produs* aux = new Produs(0,0,1,"buc","produs","Standard");
    for(int i = 0; i < l.n; i++)
    {
        fin>>aux;
        l.v.push_back(aux);
    }
    //fin>>l.v[i];
    return fin;
}

ofstream& operator << (ofstream& fout, Lista_cumparaturi & l)
{
    for(int i = 0; i < l.n; i++)
    {
        fout<<l.v[i]<<endl;
    }

    fout<<l.get_total();
    return fout;
}

int Lista_cumparaturi:: get_total()
{
    Produs* aux = v[0];
    for(int i=1; i<v.size(); i++)
        *aux = *aux + *this->v[i];

    return aux->pret;

}

int Lista_cumparaturi:: get_n()
{
    return n;
}

bool Lista_cumparaturi:: elem_is_equal(int i, Lista_cumparaturi a,int j)
{
    if(v[i]->get_denum() == a.v[j]->get_denum() && v[i]->get_tip() == a.v[j]->get_tip())
        return 1;
    return 0;
}

void Lista_cumparaturi:: push_back(Produs* p)
{
    v.push_back(p);
}

Produs* Lista_cumparaturi:: get_elem(int i)
{
    return v[i];
}

Lista_cumparaturi Lista_cumparaturi::imbinare(Lista_cumparaturi& inv)
{
    Lista_cumparaturi imb(n,v);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<inv.get_n(); i++)
        {
            //if(this->elem_is_equal(i,inv,j));
            if(v[i]->get_denum() == inv.v[j]->get_denum() && v[i]->get_tip() == inv.v[j]->get_tip())
                imb.push_back(inv.get_elem(j));
        }
    }
    imb.n = imb.v.size();
    return imb;

}

Lista_cumparaturi Lista_cumparaturi:: citire_client(ifstream& client)
{
    string auxi;
    int nr_cp=0;
    char* s,*ptr;

    for(int i =0 ; i<=n; i++)
    {
        std::getline(client,auxi);

        while(auxi.find("din")!= string::npos) //eliminam cuv "din" din lista clientului
            auxi.erase(auxi.find("din"),4);

        strcpy(s,auxi.c_str());
        ptr=strtok(s," ");

        nr_cp=0;
        while(ptr != NULL)
        {
            nr_cp++;
            ptr=strtok(NULL," ");  //impartim linia in cuvinte
        }
            //in functie de numarul de campuri ne putem da seama de ce tip de produs este vorba
        if(nr_cp == 1)
        {
            Produs* p =new Produs(0,0,0,"","","");
            p->denumire = ptr;
            v.push_back(dynamic_cast <Produs*> (p));
        }

        if(nr_cp == 2)
        {
            Produs* p =new Produs(0,0,0,"","","");
            p->denumire = ptr;
            ptr = strtok(NULL," ");
            p->tip = ptr;
            v.push_back(dynamic_cast <Produs*> (p));
        }

        if(nr_cp == 3)
        {
            ProdusCuBrand* pb =new ProdusCuBrand(0,0,0,"","","","");
            pb->denumire = ptr;
            ptr = strtok(NULL," ");
            pb->tip = ptr;
            ptr = strtok(NULL," ");
            pb->brand = ptr;
            v.push_back(dynamic_cast <Produs*> (pb));
        }

        if(nr_cp == 4)
        {
            VinDeSoi* vin =new VinDeSoi(0,0,0,"","","","","",0);
            vin->denumire = ptr;
            ptr = strtok(NULL," ");
            vin->tip = ptr;
            ptr = strtok(NULL," ");
            vin->soi = ptr;
            ptr = strtok(NULL," ");
            vin->tara = ptr;
            v.push_back(dynamic_cast <Produs*> (vin));
        }

        if(nr_cp == 5)
        {
            VinDeSoi* vin =new VinDeSoi(0,0,0,"","","","","",0);
            vin->denumire = ptr;
            ptr = strtok(NULL," ");
            vin->tip = ptr;
            ptr = strtok(NULL," ");
            vin->tip.append(ptr);
            ptr = strtok(NULL," ");
            vin->soi = ptr;
            ptr = strtok(NULL," ");
            vin->tara = ptr;
            v.push_back(dynamic_cast <Produs*> (vin));
        }


    }

    return *this;
}
