#include "Informatii_complete.h"

using namespace std;

info::info(int a) //aceasta este o clasa pentru citirea, memorarea si afisarea matricelor. N repr nr de elemente, iar v este vectorul de obiecte
{
    n=a;
    v=new mat_com[n];
}

info::~info()
{
    delete[] v;
}

ostream& operator <<(ostream& out, info& a)
{
    out<<"Informatii initiale:\n";
    for(int i=0;i<a.n;i++)
        out<<a.v[i]<<endl;


    if(a.n>1)
    {
        mat_com copie_s(a.v[0]),copie_p(a.v[0]);
        out<<"Acum se va face suma si produsul tuturor matricelor,daca este posibil\n\n";
        for(int i=1;i<a.n;i++)
        {
            copie_s=copie_s+a.v[i];
            copie_p=copie_p*a.v[i];
        }

        out<<"\nSuma matricelor este:\n"<<copie_s;
        out<<"Produsul matricelor este:\n"<<copie_p;
    }
    return out;
}

istream& operator >>(istream& in, info& a)
{

    cout<<"Introduceti numarul de elemente:";
    int x;
    in>>x;
    if(x<0)
    {
        cout<<"\nINTRODUCETI NUMERE POZITIVE!!\n"<<endl;
        return in;
    }

    delete[] a.v;

    a.v=new mat_com[x];
    a.n=x;

    for(int i=0;i<a.n;i++)
    {
        in>>a.v[i];
    }
    return in;
}
