#include <iostream>
#include "Informatii_complete.h"

using namespace std;

int main()
{
    info a(0);
    cin>>a;
    cout<<a;//in cadrul suprascrierii operatorului << pt clasa info am afisat operatia de inmultire si adunare
            //pentru toate matricele introduse. Pentru o rulare cat mai rapida si fara mesaje de eroare primite
            //in consola se recomanda introducerea unor matrice patratice de aceleasi dimensiuni.

            //Aplicatia ruleaza si in alte situatii, dar vor aparea mai multe mesaje care vor preciza incapacitatea
            //realizarii calculelor si se vor face doar calculele posibile.
            //Spre exemplu, daca se introduc 5 matrice, dar a 3 nu poate fi inmultita(/adunata) cu rezultatul dintre
            //primele doua, se va afisa un mesaj "Matricele nu se pot inmulti" si se va afisa inmultirea dintre matricele
            //1,2,4,5

            //Pentru metodele implementate la numere complexe am considerat ca inmultirea matricelor este suficienta,
            //acolo fiind nevoie de adunarea si inmultirea elementelor(numere complexe). Am incercat sa fac si o afisare
            //pentru suma si produsul tutoror elementelor matricelor, dar timpul si erorile nu au fost de partea mea

    return 0;
}
