#include <iostream>
#include <fstream>
#include <vector>
#include "Produs.h"
#include "Lista_produse.h"
#include "Tranzactii.h"
#include <string>
#include <cstring>
#include <typeinfo>

using namespace std;

/*class Management
{
private:
    Management(){}
    static Management* elementul;
public:
    static Management* get_element()
    {
        if(elementul != NULL)
            return elementul;
        elementul = new Management;
        return elementul;
    }

};

Management* Management:: elementul = NULL;

*/

// tipuri : varza- alba rosie; bere- blonda bruna
//          vinuri- varsat de soi; cartofi- albi rosii

//jucariile fiind unicat, intra la produse si in denumire
//se va introduce ce jucarie este


int main()
{
    ifstream inventar ("Inventar.in");

//    Tranzactii* Tranzactii:: elementul = NULL;
    //Tranzactii* t = Tranzactii::get_element();
    int valoare =0;
    vector <Produs*> vect;
    Lista_cumparaturi l(valoare,vect);
    Tranzactii t(valoare,l);

    char c = '!';
    try{
        if(inventar.is_open()==0) throw c;
    }
    catch(char c){
        cout<<"Eroare la deschiderea Inventarului!"<<endl;
        return -1;
    }
    try{
    t.citire(inventar);
    }
    catch(char c){
        return -1;
    }

    ofstream inchidere ("InchidereaZilei.out");
    try{
        if(inchidere.is_open()==0)
            throw c;
    }
    catch(char c){
        cout<<"Eroare la deschiderea fisierului InchidereaZilei.out\n";
        return -1;
    }

    t.afisare(inchidere);

    return 0;
}
