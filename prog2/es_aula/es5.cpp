#include <iostream>
#include <cstring>
using namespace std;

class MiaStringa
{
    public:
        MiaStringa(const char*Stringa="")
        {Lunghezza = strlen(Stringa) + 1;
        miaStringa = new char[Lunghezza];
        strncpy(miaStringa,Stringa,Lunghezza);
        miaStringa[Lunghezza-1] = '\0';
        }
        ~MiaStringa()
        {delete[] miaStringa;
         miaStringa=0;
        }
        char *RestituisciStringa(){return miaStringa;}
        int RestituisciLunghezza(){return Lunghezza;}
    private:
        char *miaStringa;
        int Lunghezza;
};

int main(){
    MiaStringa MioNome("Aldo");
        cout<<"Il mio nome e': "<<MioNome.RestituisciStringa()<<endl;
        return 0;
}