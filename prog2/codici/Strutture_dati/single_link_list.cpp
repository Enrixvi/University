#include <iostream>
using namespace std;

class Nodo{
    public:
    int val;
    Nodo* next;
};

class List{
    private:
    Nodo* head;
    public:
    List(){head=nullptr;}
    void insert(int val);
    void insert(Nodo* prev,int val);
    void insertTail(int vak);
    void remove(int val);
    friend ostream& operator<<(ostream& os,const List& ls);
   // ~List();   
};

void List::insert(int val){
    Nodo* newNode = new Nodo;
    newNode->val = val;
    if(head==nullptr){
        head = newNode;
        head->next = nullptr;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void List::insert(Nodo* prev,int val){
    Nodo* newNode = new Nodo;
    newNode->val = val;
    newNode->next = prev->next;
    prev->next = newNode;
}

void List::insertTail(int val){
    Nodo* newNode = new Nodo;
    Nodo* tmp=this->head;
    newNode->val = val;
    newNode->next = nullptr;
    while(tmp->next!=nullptr){
        tmp = tmp->next;
    }
    cout<<tmp->val<<"VAL TEMMP"<<endl;
    
   // newNode->next = tmp->next;
    tmp->next = newNode;
}

ostream& operator<<(ostream& os,const List& ls){
    Nodo* loop= ls.head;
    while(loop!=nullptr){
        os << loop->val << "-->";
        loop = loop->next;
    }
    os << "NULL";
    return os;
}

int main(){
    List lista;
    lista.insert(5);
    lista.insert(7);
    lista.insert(3);
    lista.insertTail(43);
    cout << lista;
}