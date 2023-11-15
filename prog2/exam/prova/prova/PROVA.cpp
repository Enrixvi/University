#include <iostream>
#include <string>
using namespace std;
class Persona{
    string nome;
    string cognome;
    int anno;
    public:
        Persona(string t,string a,int an){
            nome=t;
            cognome=a;
            anno=an;
        }
        string getCognome(){
            return cognome;
        }
        string getNome(){
            return nome;
        }
        int getAnno(){
            return anno;
        }
        void stampa(){       
            cout<<nome<<" e stato fatto da "<<cognome<<"nell "<<anno<<endl;
        }
        virtual string get_genere()=0;
    
};
class Pensionati : public Persona{
    string get_genere(){
        return "Pensionati";
    }
    public:
    Pensionati(string t,string a,int an): Persona(t,a,an){
            
        }
};
class Studenti : public Persona{
    string get_genere(){
        return "Studenti";
    }
    public:
    Studenti(string t,string a,int an): Persona(t,a,an){
            
        }
};
class Lavoratori : public Persona{
    string get_genere(){
        return "Lavoratori";
    }
    public:
    Lavoratori(string t,string a,int an): Persona(t,a,an){
            
        }
};
template <typename T>
class BST{
    struct nodo{
        T val;
        nodo* right;
        nodo* left;
        

        nodo(T n){
            val=n;
            right=NULL;
            left=NULL;
        }
    };
    nodo* radice;
    int dim;
    int contS,contP,contL,S,L,P;
    public:
    BST(){
        radice=NULL;
        dim=0;
        contS=contP=contL=S=L=P=0;
    }
    void inserisci(T valore,nodo*& ptr){
        if(ptr==NULL){
            ptr=new nodo(valore);
        }else{
            if(ptr->val->getAnno()<valore->getAnno()){
                return inserisci(valore,ptr->right);
            }else{
                return inserisci(valore,ptr->left);
            }
        }
    }
    void stampan(nodo* ptr ){
        if(ptr!=NULL){
            stampan(ptr->left);
            cout<<ptr->val->getNome()<<" e stato fatto da "<<ptr->val->getCognome()<<"nell "<<ptr->val->getAnno()<<endl;
            stampan(ptr->right);
        }

    }
    
    void Ricors(nodo* ptr){
        string s=ptr->val->get_genere();
        
            
            
                   
                if(s=="Studenti"){         
                    contS++;
                    S+=ptr->val->getAnno();
                    cout<<"S: "<<contS<<endl;
                }
                if(s=="Pensionati"){
                    contP++;
                    P+=ptr->val->getAnno();
                    cout<<"P: "<<contP<<endl;
                }
                if(s=="Lavoratori"){
                    contL++;
                    L+=ptr->val->getAnno();
                    cout<<"L: "<<contL<<endl;
                    
                }
                if(ptr->left!=NULL)
                    Ricors(ptr->left);
                if(ptr->right!=NULL)
                    Ricors(ptr->right);
        

    }
    void media(){
        Ricors(radice);
        cout<<L/contL<<endl;
        cout<<P/contP<<endl;
        cout<<S/contS<<endl;
        contS=contP=contL=S=L=P=0;

    }
    
    
    void stampa(){
        stampan(radice);
    }
    void insert(T val){
        inserisci(val,radice);
    }
    void cerca(string s){
        cercan(s,radice);
    }
    
    
};
int main(){
    BST<Persona*> radice;
    radice.insert(new Studenti("Il mondo nuovo","aldos huxley",50));
    radice.insert(new Pensionati("Il nome della rosa","Umberto Eco",50));
    radice.insert(new Lavoratori("Breve storia del tempo","stephen hawking",50));
    radice.insert(new Studenti("Orgoglio e pregiudizio","jane austen",50));
    radice.insert(new Pensionati("Il nome della rosa","Umberto Eco",100));
    radice.insert(new Lavoratori("Breve storia del tempo","stephen hawking",50));
    radice.stampa();
    radice.media();

    
    
 
    
    

}