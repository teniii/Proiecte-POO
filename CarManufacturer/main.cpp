#include <iostream>
#include <fstream>

#include <bits/stdc++.h>

#include "Masini.h"

using namespace std;
///Tenita Alexandru-Cristian 251 compilator: c++14 CodeBlocks 17.12



class manager_singleton
{
private:
    static manager_singleton* instance;
    manager_singleton(){}
    vector<Tranzactie> tranzactii;

public:
    ~manager_singleton();
    static manager_singleton* get_instance()
    {
        if(instance == 0)
            instance = new manager_singleton();
        return instance;
    }

    void citire()
    {
        int n;
        cin>>n; //nr de tranzactii
        Tranzactie aux;
        for(int i = 0;i<n;++i)
        {
            cin>>aux;
            instance->tranzactii.push_back(aux);
        }
    }

    void afisare()
    {
        vector<Tranzactie>::iterator it;
        //for(int i = 0;i<instance->tranzactii.size();++i)
        for(it = instance->tranzactii.begin();it!=instance->tranzactii.end();it++)
        {
            cout<<*it;
        }
    }

};

manager_singleton* manager_singleton:: instance = 0;

manager_singleton::~manager_singleton()
{
    delete(instance);
}

int main()
{
    manager_singleton* seful = manager_singleton::get_instance();

    seful->citire();

    seful->afisare();

    MasinaCombustie m1(2020,"Astra",240,2240,true,56);
    MasinaCombustie m2 = m1;
    cout<<m1;
    cout<<endl<<m2;


    return 0;
}
