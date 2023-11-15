#include <iostream>
using namespace std;

class ClasseA{
public:
    ClasseA(){}
    virtual void dinamica(){ cout << "Dinamica in Classe A" << endl;}
    void statica(){ cout << "Statica in Classe A" << endl;}
};
class ClasseB: public ClasseA{
public:
    ClasseB(){}
    void dinamica(){ cout << "Dinamica in Classe B" << endl;}
    void statica(){ cout << "Statica in Classe B" << endl;}
};


// Esempio analogo

class Animale{
public:
    int zampe;
    virtual void faiVerso(){ cout << "non so che verso fare" << endl;}
    void getSpecie(){ cout << "non so di che specie sono" << endl;}
    ~Animale(){ cout << "Elimino Animale\t" << this << endl;}
};
class Cane: public Animale{
public:
    Cane(){ zampe = 4;}
    void faiVerso() { cout << "bau bau" << endl;}
    void getSpecie() { cout << "canide" << endl;}
    ~Cane(){ cout << "Elimino Cane\t" << this << endl;}
};
class Uccellino: public Animale{
public:
    Uccellino(){zampe=2;}
    void faiVerso() { cout << "cip cip" << endl;}
    void getSpecie() { cout << "volatile" << endl;}
    ~Uccellino(){ cout << "Elimino Uccellino\t" << this << endl;}
};

int main(){
    ClasseA *a = new ClasseA();
    ClasseB *b = new ClasseB();

    cout << "Richiamo i metodi di a della classe A:" << endl;
    a->dinamica();
    a->statica();
    cout << endl;

    cout << "Richiamo i metodi di b della classe B:" << endl;
    b->dinamica();
    b->statica();
    cout << endl;

    a = b;
    cout << "Richiamo i metodi di a della classe A (dopo avergli assegnato b):" << endl;
    a->dinamica();
    a->statica();

    cout << "Esempi con gerarchia di Animali:" << endl;
    
    Cane c;
    Uccellino u;
    c.faiVerso();
    u.faiVerso();

    // puntatore ad animale
    Animale * pA = new Animale();
    pA = &c;
    pA->faiVerso();
    pA = &u;
    pA->faiVerso();
    pA->getSpecie();

    /*
    In tutti questi esempi il virtual forza il compilatore ad usare
    l'implementazione del metodo che si trova nella classe derivata.
    */
    Animale& rA = c;
    rA.faiVerso();

    return 0;
}