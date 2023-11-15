#include <iostream>
using namespace std;

class Nodo{
    public:
    int val;
    Nodo* succ;
};

class Lista{
    private:
    Nodo* testa;
    public:
    Lista(){testa=nullptr;}
    void insert(int val);
    void inverti();
    void stampa();
};

void Lista::insert(int val){
    Nodo* elem = new Nodo;
    elem->val = val;
    //elem->succ = nullptr;
   // if(testa==nullptr){ 
        //testa->succ = nullptr;
     //   testa = elem;
    //}
    elem->succ = this->testa;
    this->testa = elem;
}
void Lista::inverti(){
    Nodo* prev=nullptr;
    Nodo* current=testa;
    Nodo* next;
    while(current!=nullptr){
        next=current->succ;
        current->succ=prev;
        prev=current;
        current=next;
    }
    testa=prev;
}

void Lista::stampa(){
    Nodo* tmp=testa;
    while(tmp!=nullptr){
        cout<<tmp->val<<endl;
        tmp=tmp->succ;
    }
}

int main(){
    Lista l;
    l.insert(5);
    l.insert(7);
    l.insert(4);
    l.insert(9);
    l.stampa();
    l.inverti();
    l.stampa();
    return 0;
}