
#include <iostream>
using namespace std;

class Nodo{
public: 
	int val;
	Nodo* succ;
};

class ListaSemplice {
	private:
		Nodo* testa;
	public:
		ListaSemplice() {testa=nullptr;}
		~ListaSemplice();
		Nodo* getTesta(){return testa;}
		
		// Inserisce in testa
		void inserisci(int);
		// Inserisce in un posto determinato (dal precedente)
		void inserisci(Nodo*, int);
		void inserisciInCoda(int);
		Nodo* ricerca(int);
		void rimuovi(int);
		
		friend
		ostream& operator<<(ostream& os, const ListaSemplice& ls);
};

	ListaSemplice::~ListaSemplice() {
		Nodo* iter = this->testa;
		while(iter!=nullptr){
			Nodo* tmp = iter->succ;
			delete iter;
			iter = tmp;
		}
	}	

ostream& operator<<(ostream& os, const ListaSemplice& ls){
		Nodo* iter = ls.testa;
		while(iter!=nullptr){
			os << "[" << iter->val << "] --> ";
			iter = iter->succ;
		}
		cout << "NULL" << endl;
		return os;
}

// Inserimento in testa
void ListaSemplice::inserisci(int val){
	Nodo* nuovo = new Nodo;
	nuovo->val = val;
	nuovo->succ = this->testa;
	this->testa = nuovo;
}

// Inserisce in un posto determinato (dal precedente)
void ListaSemplice::inserisci(Nodo* prec, int val){
	Nodo* nuovo = new Nodo;
	nuovo->val = val;
	nuovo->succ = prec->succ;
	prec->succ = nuovo;
}
	
void ListaSemplice::inserisciInCoda(int val){
	Nodo* nuovo = new Nodo;
	Nodo* iter = this->testa;
	nuovo->val = val;
	nuovo->succ = nullptr;
	
	if(this->testa == nullptr){
		this->testa = nuovo;
	}
	else{
		while(iter->succ!=nullptr)
			iter=iter->succ;		
		iter->succ = nuovo;
	}
}

Nodo* ListaSemplice::ricerca(int val){
	Nodo* iter;
	for(iter=this->testa;iter!=nullptr;iter=iter->succ)
		if(iter->val == val)
			return iter;
		
	return nullptr;
}


void ListaSemplice::rimuovi(int val){
	
	Nodo* prec;
	Nodo* curr;
	
	if(this->testa == nullptr)
		cout << "Lista vuota: impossibile rimuovere elementi" << endl;
	else if (this->testa->val == val) {
		prec = this->testa;
		this->testa = this->testa->succ;
		delete prec;
	}
	else{ // caso generico
	
		prec = this->testa;
		curr = this->testa->succ;
	
		while((curr!=nullptr) && (curr->val != val)){
			prec = prec->succ;
			curr = curr->succ;
		}
		
		if(curr!=nullptr){
			prec->succ = curr->succ;
			delete curr;
		}
		else
			cout << "Elemento non presente nella lista!" << endl;
	}
}


int main(){
	
	ListaSemplice lista;
	lista.inserisci(20);
	lista.inserisci(2);
	lista.inserisci(10);
	lista.inserisci(5);
		
	cout << lista;
	
	int pre, in;
	Nodo* p = nullptr;
	do{
		cout << "Scegli un elemento dalla lista: ";
		cin >> pre;
		p = lista.ricerca(pre);
	}while(p==nullptr);
	
	cout << "Quale elemento vuoi inserire dopo " << pre << "? ";
	cin >> in;
	lista.inserisci(p, in);
	
	cout << lista;
	
	for(int i=0;i<3;i++)
		lista.inserisciInCoda(i*i+ 10);
	
	cout << lista;
	
	p= nullptr;
	do{
		cout << "Scegli un elemento da eliminare dalla lista: ";
		cin >> in;
		p = lista.ricerca(in);
	}while(p==nullptr);
	
	lista.rimuovi(in);
	cout << lista;
	
	return 0;	
	
}
