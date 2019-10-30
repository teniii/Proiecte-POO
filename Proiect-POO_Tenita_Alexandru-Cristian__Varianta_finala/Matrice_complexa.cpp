#include "Matrice_complexa.h"
#include "Numar_complex.h"

using namespace std;

mat_com::mat_com(int x, int l, int c) //constructorul de initializare a matricei
{
    nrl=l;
    nrc=c;
    matrice=new numar_complex*[nrl];
    for(int i=0; i<nrl; i++)
        matrice[i]=new numar_complex[nrc]; //alocam dinamic matricea

    for(int i=0; i<nrl; i++)
        for(int j=0; j<nrc; j++)
            matrice[i][j]=x; //initializam toate elementele cu valoarea x
}

mat_com::mat_com(const mat_com& m)
{
    if(m.matrice!=matrice)
    {
        nrl=m.nrl;
        nrc=m.nrc;
        matrice=new numar_complex*[nrl];
        for(int i=0; i<nrl; i++)
            matrice[i]=new numar_complex[nrc]; //alocam memoria si apoi copiem pe rand fiecare element dintr o matrice in cealalta

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

eticheta:
    cout<<"Introduceti numarul de linii, apoi numarul de coloane: ";
    in>>m.nrl>>m.nrc;

    if(m.nrl<1 || m.nrc<1)
    {
        cout<<endl<<"INTRODUCETI VALORI CEL PUTIN EGALE CU 1!!!"<<endl; //Daca utilizatorul introduce valori negatiive pentru
        goto eticheta;          //nr de linii sau coloane, il punem sa reintroduca valorile. Cea mai eleganta solutie mi s-a
    }                           //parut goto. Astept solutii noi pentru a rezolva altfel probleme de genul

    m.matrice=new numar_complex*[m.nrl];
    for(int i=0; i<m.nrl; i++)
        m.matrice[i]=new numar_complex[m.nrc];

    for(int i=0; i<m.nrl; i++)
        for(int j=0; j<m.nrc; j++)
            in>>m.matrice[i][j]; //memorarea elementelor matricei

    return in;
}

mat_com& mat_com::operator =(const mat_com& rez)
{
    if(this==&rez)
        return *this;

    for(int i=0; i<nrl; i++)
        delete [] matrice[i];
    delete [] matrice; //stergem pentru a  realoca memoria

    this->nrl=rez.nrl;
    this->nrc=rez.nrc; //introducem aceleasi valori pentru campurile de numar linii si numar coloane

    matrice=new numar_complex*[nrl];
    for(int i=0; i<nrl; i++)
        matrice[i]=new numar_complex[nrc]; //realocare de memorie


    for(int i=0; i<nrl; i++)
        for(int j=0; j<nrc; j++)
            matrice[i][j]=rez.matrice[i][j]; //copierea valorilor
    return *this;
}

mat_com mat_com::operator+(const mat_com& m2)
{
    if(nrl!=m2.nrl || nrc!=m2.nrc) //Aceasta este conditia de incompatibilitate si se afiseaza mesajul corespunzator
    {
        cout<<"Matricele nu pot fi adunate!";
        cout<<"\nIgnorati matricea ce va fi afisata la suma!!\n";
        return *this;
    }
    mat_com rez(*this);
    for(int i=0; i<nrl; i++)
        for(int j=0; j<nrc; j++)
            rez.matrice[i][j]=matrice[i][j]+m2.matrice[i][j]; //adaugarea sumei dintre 2 elemente de pe aceleasi pozitii pe aceeasi pozitie
    return rez;                                               //din matricea complexa rez


}

mat_com mat_com::operator*(const mat_com& m2)
{
    if(nrc!=m2.nrl) //Aceasta este conditia de incompatibilitate si se afiseaza mesajul corespunzator
    {
        cout<<"Cele doua matrice nu se pot inmulti!\n";
        cout<<"Ganditi-va la o alta matrice care sa fie inmultita cu:\n";
        cout<<*this<<"\nIgnorati matricea ce va fi afisata la produs!!\n";

        return *this;
    }
//1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 //acestea sunt niste valori pentru teste, pe care le iau cu copy paste
//2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2 2
//3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3 3
    mat_com rez(0,nrl,m2.nrc),that(*this);

    const numar_complex aux(0,0);
    int i,j,k;
    for( i=0; i<nrl; i++)
    {
        for( j=0; j<m2.nrc; j++)
        {
            rez.matrice[i][j]=aux; //se initializeaza cu 0 fiecare pozitie din rez (a doua oara pentru a fi siguri)
            that=*this;
            for( k=0; k<m2.nrl; k++)
            {
                rez.matrice[i][j]= rez.matrice[i][j] + that.matrice[i][k]*m2.matrice[k][j]; //aici se face suma dintre produse pentru a completa
            }                                                                               //in matricea rez
        }
    }

    return rez;
}
