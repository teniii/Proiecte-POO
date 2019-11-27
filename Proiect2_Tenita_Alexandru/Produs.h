#ifndef PRODUS_H_INCLUDED
#define PRODUS_H_INCLUDED

#include <fstream>
using namespace std;

class ProdusCuBrand;
class VinDeSoi;

class Produs
{
protected:
    int pret;
    int cost;
    int cantitate;
    string um;
    string denumire;
    string tip;
public:
    Produs(int, int, int, const string&, const string&, const string&);
    Produs(const Produs&);
    virtual ~Produs();

    Produs operator + (const Produs&);
    Produs operator + (const ProdusCuBrand&);
    Produs operator + (const VinDeSoi&);

    Produs operator = (const Produs&);
    bool operator == (const Produs*&);
    void citire (string);

    friend ostream& operator << (ostream&, Produs*&);
    friend ifstream& operator >> (ifstream&, Produs*&);
    friend ofstream& operator << (ofstream&, Produs*&);
    friend class Lista_cumparaturi;
    friend class ProdusCuBrand;

    string get_denum();
    string get_tip();
    int get_pret();
    int get_cost();
};


class ProdusCuBrand : public Produs
{
protected:
    string brand;
public:
    ProdusCuBrand(int, int, int, const string&, const string&, const string&,const string&);
    ProdusCuBrand(const ProdusCuBrand&);
    virtual ~ProdusCuBrand();

    Produs operator + (const ProdusCuBrand&);
    Produs operator + (const Produs&);
    Produs operator + (const VinDeSoi&);

    bool operator == (const ProdusCuBrand&);
    ProdusCuBrand operator = (const ProdusCuBrand&);
    void citire(string);

    friend ostream& operator << (ostream&, ProdusCuBrand*&);
    friend ifstream& operator >> (ifstream&, ProdusCuBrand*&);
    friend ofstream& operator << (ofstream&, ProdusCuBrand*&);
    friend class Lista_cumparaturi;

};



class VinDeSoi : public Produs
{
private:
    int an;
    string soi;
    string tara;
public:
    VinDeSoi(int, int, int, const string&, const string&, const string&, const string&, const string&, int);
    VinDeSoi(const VinDeSoi&);
    virtual ~VinDeSoi();

    VinDeSoi operator + (const VinDeSoi&);
    VinDeSoi operator = (const VinDeSoi&);
    bool operator == (const VinDeSoi&);

    void citire(string);


    friend ostream& operator << (ostream&, VinDeSoi*&);
    friend ifstream& operator >> (ifstream&, VinDeSoi*&);
    friend ofstream& operator << (ofstream&, VinDeSoi*&);
    friend class Lista_cumparaturi;


};


#endif // PRODUS_H_INCLUDED
