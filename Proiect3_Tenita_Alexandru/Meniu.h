#ifndef MENIU_H_INCLUDED
#define MENIU_H_INCLUDED

#include "Ingredient.h"

template <class T>
class Meniu
{
private:

    vector <T>* m;
    unordered_map <T,int> nr_vanzari;
    static std::unordered_map <std::string, std::vector <Ingredient>> decod ;

public:

    Meniu();



};

#endif // MENIU_H_INCLUDED
