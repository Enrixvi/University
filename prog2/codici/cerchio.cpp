

#include <iostream>
using namespace std;

class Cerchio{
protected:
    double raggio;
public:
    Cerchio():raggio(1){ cout << "def. constructor" << endl;}
    Cerchio(double _r): raggio(_r) { cout << "costr. #2 " << endl;}

    double circonferenza() const { return 2*raggio*3.14;}
    double getRaggio() const { return raggio;}
};
/* // se non metto 'const' in circonferenza() qualcuno potrebbe fare...
class CerchioCattivo: public Cerchio{
public:
    double circonferenza() { raggio = -10; return 100;}
};*/


// top-level functions per calcolare l'area
double areaCerchio(Cerchio c){
    return c.getRaggio()*c.getRaggio()*3.14;
}

double areaC(Cerchio& c){
    cout << "versione senza const\t";
    return c.getRaggio()*c.getRaggio()*3.14;
}

double areaC(const Cerchio& c){
    cout << "versione con il const\t";
    return c.getRaggio()*c.getRaggio()*3.14;
}

int main(){

    cout << "1) ";
    Cerchio c1;
    cout << "raggio di c1:\t" << c1.getRaggio() << endl;
    cout << "2) ";
    Cerchio c2(10.0); // funcional form (puo' essere pericolosa, mettere lo spazio)
    cout << "3) ";
    Cerchio c3{30.0};
    cout << "4) ";
    Cerchio c4 = {40.0};
    cout << "5) ";
    Cerchio c5 = 20.0;


    cout << "Area:\t" << areaCerchio(2.3) << endl;
    cout << "Area:\t" << areaCerchio(3.2f) << endl;
    cout << "Area:\t" << areaCerchio(3) << endl;

    cout << endl;
    Cerchio cc (2.3);
    cout << "Area:\t" << areaC(cc) << endl;
    cout << "Area:\t" << areaC(3.2) << endl;

    //NB: aggiungere 'explicit' al secondo costruttore ..
    return 0;
}