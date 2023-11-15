#include <iostream>
using namespace std;

class Prodotto{
    int prod_id;
    double price;

    public:
    Prodotto(){prod_id=0,price=0};
    Prodotto(int id,double p):prod_id(id),price(p){};
    int get_id(){return prod_id;};
    double get_price(){return price;};
    void set_price(double p){price=p;};

};