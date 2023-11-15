#include <iostream>
using namespace std;
class Prodotto{
    public:
        Prodotto(){
            prod_id = 000;
            price = 0;
        }
        Prodotto(int n,double g){
            prod_id = n;
            price = g;
        }

        void setProdId(int n){
            prod_id = n;
        }
        int getProdId(){
            return prod_id;
        }

        void setPrice(double g){
            price = g;
        }
        double getPrice(){
            return price;
        }
    private:
        int prod_id;
        double price;
};

int main(){
    
}