#include <iostream>
using namespace std;

class Nodo{
    public:
    int val;
    Nodo *next;
};

class Lista{
    private:
    Nodo *head;
    public:
    Lista(){testa=nullptr;}
    ~Lista()
    void Inserisci(int val);
    void InserisciCoda(int);
    void rimuovi(int);
    
    
};

Lista::~Lista(){
    Nodo *elim=this->head;
    while(elim!=nullptr){
        Nodo *temp=elim->next;
        delete elim;
        elim=temp;
    }
}

void Lista::Inserisci(int val){
    Nodo *nuovo=new Nodo;
    nuovo->val=val;
    nuovo->next=this->head;
    this->head=nuovo;
}

void Lista::InserisciCoda(int val1){
    Nodo *nuovoC=new Nodo;
    Nodo *scorri=this->testa;
    nuovoC->val=val1;
    if(head==nullptr){
        this->head=nuovoC;
        nuovoC->next=nullptr;}
    else{
        while(scorri->next!=nullptr){
            scorri=scorri->next;
        }
        scorri->next=nuovoC;
        
    }
}

void Lista::rimuovi(int valr){
    Nodo *prev;
    Nodo *curr;
    if(this->head==nullptr)
        cout<<"Lista vuota!"<<endl;
    else if(this->head->val==valr){
        prev=this->head;
        this->head=this->head->next;
        delete prev;
    }
    else{
        prev=this->head;
        curr=this->head->next;
        while(curr!=nullptr && curr->val!=valr){
            prev=prev->next;
            curr=curr->next;
        }
        if(curr!=nullptr){
        prev->next=curr->next;
        delete curr;
        }
        else
            cout<<"no element found!"<<endl;
    }
}