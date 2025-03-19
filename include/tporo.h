//Abdallah Shaitani 2602245
//Complete
#pragma once
#include <iostream>

using namespace std;

class TPoro{
    friend ostream & operator<<(ostream &,const TPoro &);
    
private:
    int x;
    int y;
    double volumen;
    char* color;
public:
    TPoro();
    TPoro(int x,int y,double vol);
    TPoro(int x,int y,double vol,const char* color);
    TPoro(const TPoro &);
    ~TPoro();
    TPoro& operator=(const TPoro &);
    bool operator==(const TPoro &);
    bool operator!=(const TPoro&);
    void Posicion(int,int);
    void Volumen(double);
    void Color(const char *);
    int PosicionX() const;
    int PosicionY() const;
    double Volumen() const;
    char * Color() const;
    bool EsVacio() const;
};
