#include "Matrice_complexa.h"
#include "Numar_complex.h"

using namespace std;

mat_com::mat_com(int x, int l, int c)
{
    nrl=l;
    nrc=c;
    matrice=new numar_complex*[nrl];
    for(int i=0; i<nrl; i++)
        matrice[i]=new numar_complex[nrc];

    for(int i=0; i<nrl; i++)
        for(int j=0; j<nrc; j++)
            matrice[i][j]=x;
}

mat_com::mat_com(const mat_com& m)
{
    if(m.matrice!=matrice)
    {
        nrl=m.nrl;
        nrc=m.nrc;
        matrice=new numar_complex*[nrl];
        for(int i=0; i<nrl; i++)
            matrice[i]=new numar_complex[nrc];

        for(int i=0; i<nrl; i++)
            for(int j=0; j<nrc; j++)
                matrice[i][j]=m.matrice[i][j];
    }
}

mat_com::~mat_com()
{
    for(int i=0; i<nrl; i++)
        delete [] matrice[i];
    delete [] matrice;
}

ostream& operator<<(ostream& out, mat_com& m)
{
    for(int i=0; i<m.nrl; i++)
    {
        for(int j=0; j<m.nrc; j++)
            out<<m.matrice[i][j]<<" ";
        out<<endl<<endl;
    }
    return out;
}

istream& operator>>(istream& in, mat_com& m)
{
    /*for(int i=0; i<m.nrl; i++)
        delete [] m.matrice[i];
    delete [] m.matrice;
    */
eticheta:
    cout<<"Introduceti numarul de linii, apoi numarul de coloane: ";
    in>>m.nrl>>m.nrc;

    if(m.nrl<1 || m.nrc<1)
    {
        cout<<endl<<"INTRODUCETI VALORI CEL PUTIN EGALE CU 1!!!"<<endl;
        goto eticheta;
    }

    m.matrice=new numar_complex*[m.nrl];
    for(int i=0; i<m.nrl; i++)
        m.matrice[i]=new numar_complex[m.nrc];

    for(int i=0; i<m.nrl; i++)
        for(int j=0; j<m.nrc; j++)
            in>>m.matrice[i][j];

    return in;
}

mat_com& mat_com::operator =(const mat_com& rez)
{
    if(this==&rez)
        return *this;

    for(int i=0; i<nrl; i++)
        delete [] matrice[i];
    delete [] matrice;

    this->nrl=rez.nrl;
    this->nrc=rez.nrc;

    matrice=new numar_complex*[nrl];
    for(int i=0; i<nrl; i++)
        matrice[i]=new numar_complex[nrc];


    for(int i=0; i<nrl; i++)
        for(int j=0; j<nrc; j++)
            matrice[i][j]=rez.matrice[i][j];
    return *this;
}

mat_com& mat_com::operator+(const mat_com& m2)
{
    if(nrl!=m2.nrl || nrc!=m2.nrc)
    {
        cout<<"Matricele nu pot fi adunate!";
        cout<<"\nIgnorati matricea ce va fi afisata la suma!!\n";
        return *this;
    }

    for(int i=0; i<nrl; i++)
        for(int j=0; j<nrc; j++)
            matrice[i][j]=matrice[i][j]+m2.matrice[i][j];
    return *this;


}

mat_com& mat_com::operator*(const mat_com& m2)
{
    if(nrc!=m2.nrl) //nrl!=m2.nrc ||
    {
        cout<<"Cele doua matrice nu se pot inmulti!\n";
        cout<<"Ganditi-va la o alta matrice care sa fie inmultita cu:\n";
        cout<<*this<<"\nIgnorati matricea ce va fi afisata la produs!!\n";

        return *this;
    }
//1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
//2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2
//3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3
    mat_com rez(0,nrl,m2.nrc),that(*this);

    const numar_complex aux(0,0);
    int i,j,k;
    for( i=0; i<nrl; i++)
    {
        for( j=0; j<m2.nrc; j++)
        {
            rez.matrice[i][j]=aux;
            that=*this;
            for( k=0; k<m2.nrl; k++)
            {
                rez.matrice[i][j]= rez.matrice[i][j] + that.matrice[i][k]*m2.matrice[k][j];
            }
        }
    }

    *this=rez;
    return *this;
}
