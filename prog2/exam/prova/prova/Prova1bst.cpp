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
    public:
    BST(){
        radice=NULL;
        dim=0;
    }
    void inserisci(T valore,nodo*& ptr){
        if(ptr==NULL){
            ptr=new nodo(valore);
        }else{
            if(ptr->val->getTitolo()<valore->getTitolo()){
                return inserisci(valore,ptr->right);
            }else{
                return inserisci(valore,ptr->left);
            }
        }
    }
    void stampan(nodo* ptr ){
        if(ptr!=NULL){
            stampan(ptr->left);
            cout<<ptr->val->getTitolo()<<" e stato fatto da "<<ptr->val->getAutore()<<"nell "<<ptr->val->getAnno()<<endl;
            stampan(ptr->right);
        }

    }
    T cercan(string s,nodo*& ptr){
        if(ptr==NULL){
            return NULL;
        }else{
            if(s==ptr->val->getTitolo()){
                return ptr->val;
            }else{
                if(s<ptr->val->getTitolo()){
                    return cercan(s,ptr->left);
                }else{
                    return cercan(s,ptr->right);

                }
            }

        }
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
    void deleteNodo(string s){
        deleteN(radice,s);
         
    }
    nodo* deleteN(nodo* ptr,string s){
        if(ptr==NULL)
            return NULL;

        if(ptr->val->getTitolo()>s)
            ptr->left= deleteN(ptr->left,s);
        else if(ptr->val->getTitolo()<s)
            ptr->right= deleteN(ptr->right,s);
            else    
                ptr=deleteRoot(ptr);

        return ptr;
        
    }
    nodo* deleteRoot(nodo* ptr){
        if(ptr==NULL)
            return NULL;

        if(ptr->right!=NULL && ptr->left!=NULL){
            nodo* min=deleteMin(ptr,ptr->right);
            ptr->val=min->val;
            free(min);
            return ptr;
        }

        nodo* newn;
        if(ptr->left==NULL)
            newn=ptr->right;
        else 
            newn=ptr->left;  

        free(ptr);
        return newn; 

    }
    nodo* deleteMin(nodo* P,nodo* ptr){
        if(P==NULL || ptr==NULL)
            return NULL;

        if(ptr->left!=NULL)
            return deleteMin(ptr,ptr->left);

        if(ptr== P->left)
            P->left=ptr->right;
        else
            P->right=ptr->right;
        
        return ptr;
    }

};
int main(){
    BST<Libro*> radice;
    radice.insert(new Romanzo("Il mondo nuovo","aldos huxley",1932));
    radice.insert(new Romanzo("Il nome della rosa","Umberto Eco",1980));
    radice.insert(new Saggio("Breve storia del tempo","stephen hawking",1988));
    radice.insert(new Romanzo("Orgoglio e pregiudizio","jane austen",1813));
    radice.stampa();
    radice.cerca("Orgoglio e pregiudizio");
    radice.deleteNodo("Orgoglio e pregiudizio");
      
    cout<<endl<<endl<<"      --------------"<<endl<<endl;
    radice.stampa();
    
    

}