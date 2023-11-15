//Scrivere un programma in C++ per eseguire le seguenti operazioni in
//un lista:
// 1. Inserisci in testa
// 2. Inserisci in coda
// 3. Inserisci ordinatamente
// 4. Estrai dalla testa
// 5. Estrai uno specifico elemento
// 6. Stampa la lista
// 7. Conta le occorrenze di uno specifico elemento
// 8. Ordina la lista crescente con quicksort e stampa
// 9. Esci
#include <iostream>
using namespace std;

struct nodo{
    int dato;
    nodo *next;
};
class Nodo{
    private:
        nodo *head;
        nodo *tail;
    public:
        Nodo (){
            head = NULL;
        }

        void push(int data){
            /*if(head == NULL){
                nodo *newN = new nodo;
                newN->next = head;
                head = newN;
            }*/
            nodo *newN = new nodo;
            newN->dato = data;
            newN->next = head;
            head = newN;
        }

        void insOrd(int data){
            while((nodo->dato)>data){
                nodo->next = 
            }
        }

}
int main(){
    
}