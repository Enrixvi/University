#include <iostream>
#include <string>
using namespace std;

class Persona{
    string nome,cognome,eta;
    public:
    Persona(string nome,string cognome,int eta):nome(nome),cognome(cognome),eta(eta){}

};

class Studente : public Persona{
    Studente(string nome,string cognome,int eta):Persona(nome,cognome,eta){}
};

class Lavoratore : public Persona{
    Lavoratore(string nome,string cognome,int eta):Persona(nome,cognome,eta){}
};

class Pensionato : public Persona{
    Pensionato(string nome,string cognome,int eta):Persona(nome,cognome,eta){}
};

class Nodo{
    private:
    int key;
    Nodo* parent,left,right;
    public:
    Nodo(int key,):{}

    
};

class BST{
    private:
    Nodo* root;

    public:
    BST():root(nullptr){}
    void preOrder
};