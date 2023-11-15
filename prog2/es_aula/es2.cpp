/*Leggere un array di 10 interi e stampare solo i numeri che appaiono nell'array una volta soltanto.
Ad esempio se l'array contiene 1, 2, 3, 1, 2, 4 il programma stampera' 3 , 4*/
#include <iostream>
using namespace std;

int main(){
    int array[8];
    for(int i=0;i<8;i++){
        cin >> array[i];
    }
    int t=0;
    for(int i=0;i<8;i++){
        t=array[i+1];
        if(t!=array[i]){
            cout << array[i]; 
        }
    }
}