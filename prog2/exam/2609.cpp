#include <iostream>
using namespace std;

class Matrice
{
    private:
    int i,j;
    
    public:
    Matrice(int i,int j):i(i),j(j){}
    Matrice(int** matrix,int i,int j):i(i),j(j){
        allocM();
        
    }
    int** matrix;
    void allocM();
    void acquisisci();
    void StampaMatrix();
    friend ostream& operator<<(ostream& out,Matrice& mtx);
    Matrice& operator+(const Matrice& mtx);
    Matrice& operator*(const Matrice& mtx);
    Matrice& operator=(const Matrice& mtx);
};

void Matrice::allocM()
{
    matrix = new int*[i];
    for(int i=0;i<this->i;i++){
        for(int j=0;j<this->j;j++){
            matrix[i]= new int[j];
        }
    }
}

void Matrice::acquisisci()
{   
    static int mc = 1;
    cout << "Matrice " << mc <<endl;
    allocM();
    for(int row=0;row<i;row++){
        for(int col=0;col<j;col++){
            cin>>matrix[row][col];
        }
    }
    mc++;
}

void Matrice::StampaMatrix()
{
     for(int row=0;row<i;row++){
        for(int col=0;col<j;col++){
            cout<<matrix[row][col]<<" ";
        }
    }cout << endl;
}

ostream& operator<<(ostream& out,Matrice& mtx)
{
    for(int row=0;row<mtx.i;row++){
        for(int col=0;col<mtx.j;col++){
            out<<mtx.matrix[row][col]<<" ";
        }
    }out << endl;

    return out;
}

Matrice& Matrice:: operator+(const Matrice& mtx)
{   
    for(int row=0;row<i;row++){
        for(int col=0;col<j;col++){
            this->matrix[row][col]+=mtx.matrix[row][col];
        }
    }
    return *this;
}

Matrice& Matrice:: operator*(const Matrice& mtx)
{
    
    for(int row=0;row<i;row++){
        for(int col=0;col<j;col++){
            this->matrix[row][col]*=mtx.matrix[row][col];
        }
    }
    return *this;
}

Matrice& Matrice:: operator=(const Matrice& mtx){
    matrix=mtx.matrix;
    return *this;
}
int main()
{
    int i=2;
    int j=3;
    Matrice m1(i,j);
    Matrice m2(i,j);
    Matrice sum(i,j);
   
    m1.acquisisci();
    m2.acquisisci();
    Matrice m3(i,j);
    m3 = m1+m2;
    //cout << m3;
    m1.StampaMatrix();
    m2.StampaMatrix();
    m3.StampaMatrix();
    sum = m1+m2;
    sum.StampaMatrix();
    sum = m1*m2;
    cout << "operator *"<<endl;
    sum.StampaMatrix();
    m1 = m2;
    cout << "operator ="<<endl;
    m1.StampaMatrix();

}
