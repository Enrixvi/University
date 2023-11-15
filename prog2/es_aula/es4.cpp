#include <iostream>
using namespace std;
int somma(int formale[][5],int n,int m){
    int parziale=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        parziale+=formale[i][j];
        }
    }
    return parziale;
}
int main(){
    int attuale[3][5]={{0,2,4,6,8},{0,2,4,6,8},{0,2,4,6,8}};
    cout<<somma(attuale,1,5)<<'\n';
    cout<<somma(attuale,3,5)<<'\n';
    cout<<somma(attuale,3,2)<<'\n';
    
    return 0;
}