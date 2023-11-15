#include <iostream>

void scambia(int &x,int &y){
    int t=x;
    x=y;
    y=t;
}

void scambia(float &x,float &y){
    float t=x;
    x=y;
    y=t;
}

void scambia(char &x,char &y){
    float t=x;
    x=y;
    y=t;
}

void scambia(Razionale &x,Razionale &y){
    Razionale t=x;
    x=y;
    y=t;
}

template <typename T> void scambia(T &x,T &y){
    T t=x;
    x=y;
    y=t;
}

class Razionale{

}