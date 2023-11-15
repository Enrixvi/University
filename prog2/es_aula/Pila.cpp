#include "Pila.h"

template <typename T,int n> void Pila <T,n> ::Push(T elemento){
    dati[nElementi]=elemento;
    nElementi++;
}

template <typename T,int n> T Pila <T,n> ::Pop(){
    nElementi--;
    return dati[nElementi];
}

template <typename T,int n> int Pila <T,n> ::Quanti(){
    return nElementi;
}

template <typename T,int n> bool Pila <T,n> ::Vuota(){
    return (nElementi==0);
}

template <typename T,int n> bool Pila <T,n> ::Piena(){
    return (nElementi==n);
} 