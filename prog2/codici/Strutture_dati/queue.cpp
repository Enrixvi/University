#include <iostream>
using namespace std;

class Nodo{
    public:
    int val;
    Nodo *next;
};
class Queue{
    private:
    Nodo* head;
    Nodo* tail;
    public:
    Queue(){head=tail=nullptr;}
    void Enqueue(int val);
    void Dequeue();
    bool isEmpty();
    void stampa();
};

bool Queue::isEmpty(){
    return(head==nullptr && tail==nullptr);
}
void Queue::Enqueue(int val){
    Nodo *ins=new Nodo;
    ins->val=val;
    //ins->next=nullptr;
    if(isEmpty()){
        head=tail=ins;
        return;
    }
    tail->next=ins;
    tail=ins;
}

void Queue::Dequeue(){
    
}

void Queue::stampa(){
    Nodo* tmp=head;
    while(tmp!=nullptr){
        cout<< tmp->val<<"";
        tmp=tmp->next;
    }
}
int main(){
    Queue q;
    q.Enqueue(4);
    q.Enqueue(7);
    q.Enqueue(1);
    q.Enqueue(2);
    q.stampa();

    return 0;
}