#include <iostream>
#include <string>
using namespace std;




template <typename T>
class BST{
    public:
    struct nodoB{
    T val;
    nodoB* left;
    nodoB* right;

    nodoB(T b): val(b),left(NULL),right(NULL){
        
    }
    };
    BST(){
        dim=0;
        radice=NULL;
    }
    void inserisci(T p,nodoB*& ptr){
        nodoB* tmp=new nodoB(p);
        if(ptr==NULL)
            ptr=tmp;
        else{
            if(p<ptr->val)
                insert(p,ptr->left);
            else
                insert(p,ptr->right);

        }
    };
    void  stampa(nodoB* ptr){
        if(ptr!=NULL){
            stampa(ptr->left);
            cout<<ptr->val;
            stampa(ptr->right);
        }
    }
    void cerca(T p,nodoB*& ptr){

        if(ptr!=NULL){
            if(p==ptr->val)
                cout<<"trovato";
            else
                if(p<ptr->val)
                    cerca(p,ptr->left);
                else
                    cerca(p,ptr->right);
        }else
            cout<<"NON TROVATO";
    };
    nodoB* rimuovi(T p,nodoB* ptr){
        if(ptr!=NULL){
            if(p==ptr->val)
                ptr=rimuoviNodo(ptr);
            else
                if(p<ptr->val)
                    ptr->left=rimuovi(p,ptr->left);
                else
                    ptr->right=rimuovi(p,ptr->right);
        }
        return ptr;
    }
    nodoB* rimuoviNodo(nodoB* ptr){
        if(ptr->left!=NULL && ptr->right != NULL){
            nodoB* tmp=min(ptr,ptr->right);
            ptr->val=tmp->val;
            delete tmp;
            return ptr;
        }
        nodoB* tmp;
        if(ptr->left!=NULL)
            tmp=ptr->left;
        else
            tmp=ptr->right;

        delete ptr;
        return tmp;

    }
    nodoB* Min(nodoB* ptr,nodoB* destro){
        if(destro->left!=NULL)
            return min(destro,destro->left);

        if(ptr== destro->left)
            destro->left=ptr->right;
        else
            destro->right=ptr->right;
        
        return ptr;
    }

    private:
    int dim;
    nodoB* radice;
};
template <typename T>
class coda{

};
template <typename T>
class lista{

};
using namespace std;

int main(){

}