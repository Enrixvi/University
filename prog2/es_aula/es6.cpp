/*
Progettare una classe vettore3d che permetta di manipolare vettori 3D 
(di tipo float) e che contenga una funzione costruttore predefinita ed
una con valori per default (0)
Deve contenere:
- La funzione visualizza
- La funzione prodotto scalare che restituisce il prodotto scalare(float)
- La funzione somma ad un altro vettore che modifica il vettore stesso.
Testare il tutto sul main.
*/
#include <iostream>

class vettore3d{
    public:
    vettore3d();
    vettore3d(0,0,0);
    protected:
    float x,y,z;

};