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
        void stampaLibro(){       
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
    public:
    struct nodo{
        T val;
        nodo* right;
        nodo* left;

        nodo(T v):val(v),right(nullptr),left(nullptr){

        }
    };
    BST(){
        dim=0;
        radice=NULL;
    }
    void insertn(T v,nodo*& ptr){
        
        
        if(ptr==NULL){      
            dim++;
            ptr=new nodo(v);
            
        }else{
            if(ptr->val->getTitolo()>v->getTitolo())
                insertn(v,ptr->left);
            else
                insertn(v,ptr->right);
        }
    }
    void stampan(nodo* ptr){
        if(ptr!=NULL){
            stampan(ptr->right);
            ptr->val->stampaLibro();
            stampan(ptr->left);
        }
    }
    T cercan(string s,nodo*& ptr){
        if(ptr==NULL){
            cout<<"nonce";
            return NULL;
        }else{
            if(s==ptr->val->getTitolo()){
                cout<<"CE";
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

    nodo* rimuoviNodo(string s,nodo* ptr){
        if(ptr==NULL)
            return NULL;

        if(ptr->val->getTitolo()<s)
            ptr->right= rimuoviNodo(s,ptr->right);
        else{
            if(ptr->val->getTitolo()>s)
                ptr->left= rimuoviNodo(s,ptr->left);
            else
                ptr=rimuoviRoot(ptr);
        }
        return ptr;


    }
    nodo* rimuoviRoot(nodo* ptr){
        if(ptr==NULL)
            return NULL;
        if(ptr->left!=NULL && ptr->right!=NULL){
            nodo* min=Min(ptr,ptr->right);
            ptr->val=min->val;
            delete min;
            return ptr;
        }
        nodo* tmp;
        if(ptr->left==NULL)
            tmp=ptr->right;
        else
            tmp=ptr->left;

        delete ptr;
        return tmp;
    }
    nodo* Min(nodo* ptr,nodo* ptright){
        if(ptr==NULL || ptright==NULL)
            return NULL;
        
        if(ptright->left!=NULL)
            return Min(ptright,ptright->left);

        if(ptr->left==ptright)
            ptr->left=ptright->right;
        else  
            ptr->right=ptright->right;

        return ptright;
    }
    
    void insert(T v){
        insertn(v,radice);
    }
    void stampa(){
        stampan(radice);
    }
    void cerca(string s){
        cercan(s,radice);
    }
    void deleteNodo(string s){
        rimuoviNodo(s,radice);
    }
    private:
    int dim;
    nodo* radice;
};
int main(){
    BST<Libro*> albero;

    albero.insert(new Saggio("Breve storia del figlio","stephen hawking",1988));
    albero.insert(new Romanzo("Breve storia del tempo","stephen hawking",1988));
    albero.insert(new Saggio("Breve storia del padre","stephen hawking",1988));
    albero.stampa();
    albero.cerca("Breve storia del padre");
    albero.deleteNodo("Breve storia del padre");
    albero.stampa();
}
/*nodo* deleteN(nodo* ptr,string s){
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
            nodo* min=Min(ptr,ptr->right);
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
    nodo* Min(nodo* P,nodo* ptrR){
        if(P==NULL || ptrR==NULL)
            return NULL;

        if(ptrR->left!=NULL)
            return Min(ptr,ptrR->left);

        if(ptrR== P->left)
            P->left=ptrR->right;
        else
            P->right=ptrR->right;
        
        return ptrR;
    }*/