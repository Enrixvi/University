#include <iostream>
#include <cstring>
using namespace std;

class Frutto{
    private:
    string nome,colore,stagione,descrizione_sapore;
    public:
    Frutto(string nome,string colore,string stagione,string descrizione_sapore):nome(nome),
                    colore(colore),stagione(stagione),descrizione_sapore(descrizione_sapore){}
    string getNome(){return nome;};
    string getColore(){return colore;};
    string getStagione(){return stagione;};
    string getSapore(){return descrizione_sapore;};
    void stampaFrutto();
    virtual string sapore() = 0; 
    virtual int id() = 0;
};

void Frutto::stampaFrutto(){
    cout << "Nome:" << getNome() << "\tColore:" << getColore() << "\tStagione:" 
            << getStagione() << "Sapore:" << getSapore() <<endl;
}

class Mela : public Frutto{
    public:
    Mela(string nome,string colore,string stagione,string descrizione_sapore):Frutto(nome,colore,stagione,descrizione_sapore){}
    string sapore(){return "Frutto mela e so di"+getSapore(); };
    int id(){return 1;};
};

class Arancia : public Frutto{
    public:
    Arancia(string nome,string colore,string stagione,string descrizione_sapore):Frutto(nome,colore,stagione,descrizione_sapore){}
    string sapore(){return "Frutto arancia e so di"+getSapore(); };
    int id(){return 2;};
};

template <class T>
class Nodo{
   public:
   T* dato;
   Nodo<T>* next;

};


template <class T>
class Coda{
    private:
    Nodo<T>* head;
    Nodo<T>* tail;
    int size;
    public:
    Coda():head(nullptr),tail(nullptr),size(0){}
    ~Coda();
    bool isEmpty(){return (head==nullptr);};
    void Enqueue(T* elem);
    T* Dequeue();
    T* front();
    void stampaCoda();
    int getDim(){return this->size;};
};

template <class T>
void Coda<T> :: Enqueue(T* elem){
    Nodo<T>* nodo = new Nodo<T>;
    nodo->dato = elem;
    nodo->next = nullptr; 
    if(isEmpty()){
        head=tail=nodo;
        return;
    }
    else{
        tail->next=nodo;
        tail=nodo;
    }
    size++;
}
template <class T>
T* Coda<T> :: Dequeue(){
    Nodo<T>* tmp = head;
    T* elem = tmp->dato;
    if(isEmpty()){
        cout << "La Queue e' vuota" <<endl;
        return nullptr;
    }
    if(head == tail)
    {
        head = tail = nullptr;
    }
    else
    {
    head = head->next;
    }
    delete tmp;
    size--;
    return elem;
}
template <class T>
T* Coda<T> ::front(){
    if(isEmpty())
        return nullptr;
    return this->head->dato;
}

template <class T>
void Coda<T>::stampaCoda(){
    Nodo<T>*tmp = head;
//if(isEmpty())
  //      return nullptr;
    T* elem;
    while(tmp!=nullptr){
        elem=tmp->dato;
        cout << elem->sapore() <<""<<endl;
        tmp=tmp->next;
    }
}
template <class T>
Coda<T>::~Coda(){
    Nodo<T>* tmp = head;
    Nodo<T>* tmp_succ;
    
    while(tmp!=nullptr){
        tmp_succ = tmp->next;
        delete tmp;
        tmp=tmp_succ; 
    }    
}
//immaginare che elemento rimosso se uguale si lascia cosi senno va reinserito con una enqueue per metterlo in coda
/*int rimuovi_tipo(Coda<Frutto> &c,int tipo){
    int count = c.getDim();
    while(count>0){
        if(tipo == 1){
            while(c.)

    }  
    }
    
}*/

int main(){
    Mela frutto1("Granny Smith", "Verde", "Autunno", "sapore Aspro");
    Arancia frutto2("Tarocco", "Arancione", "Inverno", "sapore Dolce");
    Mela frutto3("Golden Delicious", "Giallo", "Autunno", "sapore Dolce");
    Arancia frutto4("Navel", "Arancione", "Inverno", "sapore Dolce-Acido");
    Mela frutto5("Fuji", "Rosso", "Autunno", "sapore Dolce");
    Arancia frutto6("Valencia", "Arancione", "Estate", "sapore Acido");

    Coda<Frutto> c;
    c.Enqueue(&frutto1);
    c.Enqueue(&frutto2);
    c.Enqueue(&frutto3);
    c.Enqueue(&frutto4);
    c.Enqueue(&frutto5);
    c.Enqueue(&frutto6);

    c.stampaCoda();
    /*string d;
    cout << "Digitare tipo di frutti da rimuovere"<<endl;
    cin << d;*/

}