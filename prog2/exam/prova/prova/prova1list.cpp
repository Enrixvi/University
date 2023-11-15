#include <iostream>
#include <string>
using namespace std;
class Libro{
    string titolo;
    string autore;
    int anno;
    public:
        Libro(string t,string a,int an){
            titolo=t;
            autore=a;
            anno=an;
        }
        string getTitolo(){
            return titolo;
        }
        string getAutore(){
            return autore;
        }
        int getAnno(){
            return anno;
        }
        void stampa(){       
            cout<<titolo<<" e stato fatto da "<<autore<<"nell "<<anno<<endl;
        }
        virtual string get_genere()=0;
    
};
class Romanzo : public Libro{
    string get_genere(){
        return "Romanzo";
    }
    public:
    Romanzo(string t,string a,int an): Libro(t,a,an){
            
        }
};
class Saggio : public Libro{
    string get_genere(){
        return "Saggio";
    }
    public:
    Saggio(string t,string a,int an): Libro(t,a,an){
            
        }
};



template <typename T>
class list{
    struct nodo{
        public:
        T inf;
        nodo* next;
    };
    nodo* head;
    public:
    void insert(T val){
        nodo* newn= new nodo;
        newn->inf=val;
        newn->next=this->head;
        this->head=newn;
    }
    void insert(T val,nodo* prec){
        nodo* nuovo=new nodo;
        nuovo->inf=val;
        nuovo->next=prec->next;
        prec->next=nuovo;
    }
    nodo* ricerca(string val){
        nodo* control;
        for(control=this->head;control!=NULL;control=control->next)
            if(control->inf->getTitolo()==val)
                return control;
        
        return nullptr;
    }
    void rimuovi(string s){
        nodo* prec ,*curr;

        if (this->head==NULL)
            cout<<"lista vuota";
        else   {
            if(this->head->inf->getTitolo()==s){
                prec=this->head;
                this->head=this->head->next;
                delete prec;
            }else{
                prec=head;
                curr=head->next;
                while(curr!=NULL && curr->inf->getTitolo()!=s){
                    prec=prec->next;
                    curr=curr->next;
                }
                if(curr!=NULL){
                    prec->next=curr->next;
                    delete curr;
                }else
                    cout<<"non ce elemnto da elim";


            }
        }


    }
    void stampa(){
        nodo* cur=head;
        while(cur!=NULL){
            cout<<cur->inf->getTitolo()<<endl;
            cur=cur->next;
            if(cur!=NULL){
                cout<<"PEO";
            }
        }
    
    }
    



};
int main(){
    list<Libro*> lista;
    lista.insert(new Romanzo("Il mondo nuovo","aldos huxley",1932));
    lista.insert(new Romanzo("Il nome della rosa","Umberto Eco",1980));
    lista.insert(new Saggio("Breve storia del tempo","stephen hawking",1988));
    lista.insert(new Romanzo("Orgoglio e pregiudizio","jane austen",1813));
    lista.stampa();
    cout<<"           -----------------        "<<endl;
    //lista.rimuovi("Breve storia del tempo");
    //lista.stampa();

}