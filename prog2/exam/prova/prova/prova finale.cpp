#include <iostream>
#include <string>
using namespace std;
class Frutto{
    public:
    Frutto(){
    }
    Frutto(string no,string co,string st):n(no),c(co),s(st){}
    string getNome(){
        return n;
    }
    string getColore(){
        return c;
    }
    string getStagione(){
        return s;
    }
     void stampaFrutto(){
        cout<<"Frutto: "<<n<<"  colore: "<<c<<"  stagione: "<<s<<endl;
    }
    virtual void sapore()=0;

    
    private:
    string n;
    string c;
    string s;
};
class Mela : public Frutto{
    public:
    Mela(string n,string s,string m): Frutto(n,s,m){

    }
    void sapore(){
        cout<<"sapore dolce"<<endl;
    }
};
class Arancia : public Frutto{
    public:
    Arancia(string n,string s,string m): Frutto(n,s,m){

    }
    void sapore(){
        cout<<"sapore aspro"<<endl;
    }
};

template <typename T>
class Coda{
    public:
    struct nodo{
        T val;
        nodo* next;
        nodo(){
            val=NULL;
            next=NULL;
        }
        nodo(T p){
            val=p;
            next=NULL;
        }
    };

    Coda(){
        dim=0;
        testa=NULL;
        coda=NULL;
        
    }
    ~Coda(){

    }
    void enqueue(T inf){
        nodo* newn=new nodo(inf);
        dim++;
        if(testa==NULL){
            testa=coda=newn;        
        }else{          
                coda->next=newn;
                coda=coda->next;
        }


    }
    T dequeue(){
        dim--;
        if(testa==NULL){
            return NULL;
        }else{
           
            nodo* tmp=testa;
             T yu=tmp->val;
            testa=testa->next;
            delete tmp;
            return yu;  
              

        }
    }
    

    nodo* front(){
        if(testa==NULL){
            return NULL;
        }else{
            return testa;  
        }
    }
    void stampa(){
        
        nodo* tmp= testa;
        if(testa==NULL)
            cout<<"vuota";
        while(tmp!=NULL){
            tmp->val->stampaFrutto();
            tmp=tmp->next;
            
        }
    }
    int getDim(){
        return dim;
    }
    void rimuoviFrutti(string s){
    
    Coda<T> tmpco;
    if(s!="arancia" && s!="mela"){
        cout<<"frutto non esistente";
        return;
    }
    while(getDim()!=0){
        nodo* tmp=front();
        
        if(s=="mela" && dynamic_cast<Mela*>(tmp->val)){
                tmpco.enqueue(tmp->val);
                tmpco.stampa();
                
        }else{
            if(s=="arancia" && dynamic_cast<Arancia*>(tmp->val)){           
                    tmpco.enqueue(tmp->val);
                    tmpco.stampa();
                    
                
            }

        }
        dequeue();

    }
    cout<<getDim();
    while(tmpco.getDim()!=0){
        T tmp=tmpco.dequeue();
        enqueue(T);

    }
    cout<<tmpco.getDim();
    

    
    }
    
    private:
    int dim;
    nodo* testa;
    nodo* coda;

};

int main(){
    Coda<Frutto*> coda;
    coda.enqueue(new Arancia("Granny Smith", "Verde", "Autunno"));
    coda.enqueue(new Arancia("Tarocco", "Arancione", "Inverno"));
    coda.enqueue(new Mela("Golden Delicious", "Giallo", "Autunno"));
    coda.enqueue(new Arancia("Navel", "Arancione", "Inverno"));
    coda.stampa();
    cout<<endl;
    string s;
    cout<<"che tipo di frutto vuoi eliminare="<<endl;
    cin>>s;
    coda.rimuoviFrutti(s);
    
    
    
    
}