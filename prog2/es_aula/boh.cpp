/*Scrivere un programma che ricevuto in ingresso un file chiamato "testo.txt"
e due caratteri digitati da tastiera crei un fle "testo_sostituito.txt" con il testo di 
"testo.txt" sostituendo il secondo carattere al primo per tutte le volte che compare il primo carattere.

Creare un file testo.txt con la seguente frase:"per superare programmazione 2 è necessario studiare."

testo.txt="Per superare programmazione 2 è necessario studiare."
inserisco s ed X
testo_sostituito.txt="Per Xuperare programmazione 2 è neceXXario Xtudiare"*/
#include <iostream>
using namespace std;

int main(){
    ifstream  myfile ("testo.txt");
    myfile <<"Per superare programmazione 2 e' necessario studiare"<<end
}