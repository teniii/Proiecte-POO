#include "Tranzactii.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <cstring>

Tranzactii::Tranzactii(int valoare,Lista_cumparaturi l): nr(valoare),depozit(l){}

Tranzactii:: ~Tranzactii(){}

void Tranzactii:: citire(ifstream& inventar)
{
    int nr_clienti;
    cout<<"Introduceti numarul de clienti: ";
    cin>>nr_clienti;
    nr=nr_clienti;

    string auxi, auxi2;
    std::getline(inventar,auxi);
    vector <Produs*> vec;
    int n,nr_cp=0;
    inventar>>n;

    char s[60], *ptr;

    for(int i =0 ; i<=n; i++)
    {
        std::getline(inventar,auxi);
        auxi2 = auxi;
        strcpy(s,auxi.c_str());
        ptr=strtok(s," ");

        nr_cp=0;
        while(ptr != NULL)
        {
            nr_cp++;
            ptr=strtok(NULL," ");  //vedem ce tip de data avem:
        }

        if(nr_cp == 6)
        {
            Produs* p =new Produs(0,0,0,"","","");
            p->citire(auxi2);
            vec.push_back(dynamic_cast <Produs*> (p));
        }

        if(nr_cp == 7)
        {
            Produs* pb =new ProdusCuBrand(0,0,0,"","","","");
            pb->citire(auxi2);
            vec.push_back(dynamic_cast <ProdusCuBrand*> (pb));
        }
        if(nr_cp == 9)
        {
            Produs* vin =new VinDeSoi(0,0,0,"","","","","",0);
            vin->citire(auxi2);
            vec.push_back(dynamic_cast <VinDeSoi*> (vin));
        }

    }

    inventar.close();
    char ch = '!';
    for(int k = 0; k<nr_clienti; k++)
    {

        Lista_cumparaturi inv(n,vec); //inv reprezinta intregul inventar

        ifstream client ("ListaCumpClient.in");
        try
        {
            if(client.is_open()==0)
                throw ch;
        }
        catch(char ch)
        {
            cout<<"Eroare la deschiderea Listei de cumparaturi\n";
            throw ch;
            //return -1;
        }

        client>>n;
        vec.clear();

        Lista_cumparaturi listaCli(n,vec);
        Lista_cumparaturi listaMediatoare(n,vec);

        listaCli = listaCli.citire_client(client);

        listaMediatoare = listaCli.imbinare(inv);

        for(int i=0; i<listaCli.get_n(); i++)
        {
            for(int j=0; j<inv.get_n(); i++)
            {
                if(listaCli.elem_is_equal(i,inv,j))
                    listaMediatoare.push_back(inv.get_elem(j));
            }
        }
        medieri.push_back(listaMediatoare);
        clienti.push_back(listaCli);
        client.close();
        vec.clear();
    }
}

void Tranzactii:: afisare(ofstream& inchidere)
{
    string auxi;
    for(int i= 0;i<medieri.size();i++){
    cout<<"Am ales pentru dvstra produsele de cea mai buna calitate de la noi din stoc";
    cout<<"si care se potrivesc cu cerintele din lista dvstra de cumparaturi";
    cout<<"\nPretul final este de: ";
    cout<<medieri[i].get_total();

    cout<<"Introduceti DA daca sunteti de acord cu pretul, altfel NU\n";
    cin>>auxi;
    if(auxi == "DA" )
    {
        int profit = 0;
        for(int i = 0;i<medieri[i].get_n();i++)
            {
            depozit = depozit - medieri[i].get_elem(i); //scoatem din inventar produsele cumparate de client
            profit+= (medieri[i].get_elem(i)->get_pret() - medieri[i].get_elem(i)->get_pret());
            inchidere<<medieri[i]<<endl;
            }

        inchidere<<profit<<endl; //afisam profitul
    }
    }
}

Tranzactii* Tranzactii :: get_element()
{
    if(elementul != NULL)
        return elementul;
//    elementul = new Tranzactii;
    return elementul;
}


