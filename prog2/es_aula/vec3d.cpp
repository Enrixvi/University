/* 
Si vuole realizzare una classe vettore 3d che permetta di manipolare vettori di
tre coordinate x , y , z secondo le seguenti regole:

- ci sar� solo una funzione costruttore
- ci sar� una funzione chiamata "uguale" che permette di sapere se due vettori hanno le
coordinate uguali, con la funzione realizzata:
		- a. per trasmissione di valore ("uguale1"); 
		- b. per trasmissione di indirizzo ("uguale2"); 
		- c. per trasmissione di riferimento ("uguale3");
- ci sar� una funzione denominata norma che permetta di ottenere la norma del
vettore 3d (Nota: La norma di un vettore v = x,y,z � x*x+y*y+z*z ).

- Testare nel main le funzioni create
*/
#include <iostream>
using namespace std;

class Vettore3d
{
    int x,y,z;
    public:
        Vettore3d(int a,int b,int c):x(a),y(b),z(c){};
        bool uguale1(Vettore3d vec){return(x==vec.x && y==vec.y && z==vec.z);};
        bool uguale2(Vettore3d &vec){return(x==vec.x && y==vec.y && z==vec.z);};
        bool uguale3(Vettore3d *vec){return(x==vec->x && y==vec->y && z==vec->z);};
        int norma(){return x*x+y*y+z*z;};

};

int main(){
    Vettore3d v(3,2,1);
    Vettore3d m(3,2,0);
    cout << "Sono uguali?" << endl;
    if(v.uguale1(m))
        cout << "ca cettu "<< endl;
    v.uguale2(m);
    v.uguale3(&m);
}