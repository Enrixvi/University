/*Leggere un Array di interi di 10 posizioni e stampare 
il valore del massimo valore contenuto nell'array e
del secondo valore piu' grande.*/

#include <iostream>
using namespace std;

int main(){
    int Array[10];
    for(int i=0;i<10;i++){
        cin >> Array[i];
    }
    int max=0;
    int smax=0;
    for(int i=0;i<10;i++){
        if(Array[i]>max){
            max=Array[i];
        }
    }
    cout << "Il valore massimo e':"<<max <<endl;
}