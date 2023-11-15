#include <iostream>
using namespace std;
/* definisco una classe che mantiene il # di istanze
e permette di clonare un oggetto */

class MyClass{

    int value;
    static int numObj; // # di istanze di questa classe

public:
    MyClass();
    MyClass(int);
    ~MyClass();

    int getVal(){return value;}
    void setVal(int _x) {value=_x;}

    static int getNumObj(){return numObj;}

    // clona l'istanza e restituisce il suo puntatore
    MyClass* clone();
    void copyIn(MyClass*);

};
// il membro statico deve essere inizializzato
int MyClass::numObj = 0;

MyClass::MyClass(int _x):value(_x){ numObj++;}
//MyClass::MyClass() { numObj++;}
// costruttore con delega
MyClass::MyClass(): MyClass(-10) {}
MyClass::~MyClass(){ cout << "distruggi!!" << endl; numObj--;}


MyClass * MyClass::clone(){
    MyClass * cp_p = new MyClass();
    cp_p->setVal(this->value);
    return cp_p;
}

void MyClass::copyIn(MyClass* dst){
    dst->setVal(this->value);
}

int main(){

    MyClass obj_1;
    obj_1.setVal(20);

    MyClass obj_2(10);
    MyClass obj_3;

    cout << "Numero di istanze:\t" << MyClass::getNumObj() << endl;
    cout << "Obj 1 value:\t" << obj_1.getVal() << endl;
    cout << "Obj 2 value:\t" << obj_2.getVal() << endl;
    cout << "Obj 3 value:\t" << obj_3.getVal() << endl;

    cout << endl;

    MyClass * cp_p_1 = obj_1.clone();
    MyClass * cp_p_2 = obj_2.clone();

    cout << "Numero di istanze:\t" << MyClass::getNumObj() << endl;
    cout << "Copia Obj 1 value:\t" << cp_p_1->getVal() << endl;
    cout << "Copia Obj 2 value:\t" << cp_p_2->getVal() << endl;

    delete cp_p_1;
    cout << "Numero di istanze:\t" << MyClass::getNumObj() << endl;

    {
        MyClass obj_4;
        cout << "Numero di istanze:\t" << MyClass::getNumObj() << endl;
    }
    cout << "Numero di istanze:\t" << MyClass::getNumObj() << endl;

    cout << endl;

    MyClass obj_5;
    obj_1.copyIn(&obj_5);
    cout << "Obj 5 value:\t" << obj_5.getVal() << endl;
    cout << "Numero di istanze:\t" << MyClass::getNumObj() << endl;

    cout << "elimino *cp_p_2" << endl;
    delete cp_p_2;
    return 0;
}
