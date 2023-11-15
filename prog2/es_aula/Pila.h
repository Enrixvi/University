template <typename T,int n=100> class Pila {
    T dati[n];
    int nElementi;
    public:
    Pila() : nElementi(0){}
    void Push(T elemento);
    T Pop();
    int Quanti();
    bool Vuota();
    bool Piena();
};