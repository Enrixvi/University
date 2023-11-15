#include <iostream>
using namespace std;
int main(){

    int x = 10;
    int y = 50;
    int* px = &x;

    const int * cis = &x;
    cis = &y;   // OK
//    *cis = 100; // no OK: cis e' un puntatore ad un const int

    int * const ics = &x;
    *ics = 100;  // OK
    //ics = &y;    // no OK: ics e' un puntatore costante


    const int * const cisc = &x;
    *cisc = 100; // no OK
    cisc  = &y;  // no OK
    return 0;
}
