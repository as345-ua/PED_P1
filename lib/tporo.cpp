//Abdallah Shaitani 2602245
//Complete
#include <iostream>
#include <string.h>
#include "./../include/tporo.h"
#include <cstring>

TPoro::TPoro() {
    x = 0;
    y = 0;
    volumen = 0;
    this->color = NULL;
};

TPoro::TPoro(int posx,int posy,double vol){

    this->x = posx;
    this->y = posy;
    this->volumen = vol;
    this->color = NULL;

};
//Copia defensiva porque cuando se copia el objeto y leugo se borra hace un core dump y eso pasa porque hay un double delete
TPoro::TPoro(int posx, int posy, double vol,const char * col) {
    this->x = posx;
    this->y = posy;
    this->volumen = vol;
    if (col != nullptr) {
        this->color = new char[strlen(col) + 1];
        strcpy(this->color, col);
    } else {
        this->color = nullptr;
    }
}
//igual q arriba
TPoro::TPoro(const TPoro &tp) {
    this->x = tp.x;
    this->y = tp.y;
    this->volumen = tp.volumen;
    if(tp.color != nullptr) {
        this->color = new char[strlen(tp.color) + 1];
        strcpy(this->color, tp.color);
    } else {
        this->color = nullptr;
    }
}

TPoro::~TPoro() {
    delete[] color;
    color = nullptr;
    x = 0;
    y = 0;
    volumen = 0;
}

TPoro& TPoro::operator =(const TPoro& TP2) {
    if (this != &TP2) {  

        if(TP2.color !=NULL){
            
            delete[] color;
        
        }

        x = TP2.x;

        y = TP2.y;

        volumen = TP2.volumen;
    }
    if (TP2.color != NULL) {
            color = new char[strlen(TP2.color) + 1];
            strcpy(color, TP2.color);
        } else {
            color = NULL;
        }
        return *this;
};

bool TPoro::operator==(const TPoro &OP2){
    bool temp;

    (this->color != nullptr && OP2.color != nullptr && strcmp(this->color, OP2.color) == 0) ? true : false;


    return temp;
};

bool TPoro::operator!=(const TPoro &x){

    return !(*this == x);

};

void TPoro::Posicion(int x,int y){

    this->x = x;
    this->y = y;
};

void TPoro::Volumen(double vol){
    if(vol < 0){
        return;
    }
    this->volumen = vol;
};
//igual q arriba
void TPoro::Color(const char * col) {
    
    delete[] this->color;
    if (col != nullptr) {
        this->color = new char[strlen(col) + 1];
        strcpy(this->color, col);
    } else {
        this->color = nullptr;
    }
}

int TPoro::PosicionX() const {
    return this->x;
};

int TPoro::PosicionY() const {
    return this->y;
};

double TPoro::Volumen() const {
    return this->volumen;
};

char *TPoro::Color() const {
    return this->color;
};

bool TPoro::EsVacio() const{
    if (x == 0 && y == 0 && color == nullptr && volumen == 0)
    {
        return true;
    }else{
        return false;
    } 
};

ostream & operator<<(ostream &os,const TPoro &poro){
    if(!poro.EsVacio()){
        os.setf(ios::fixed);
        os.precision( 2 );
        os<<"("<<poro.x<<", "<<poro.y<<") "<<poro.volumen<<" ";
    if(poro.color!=NULL)
        os<<poro.color;
    else
        os<<"-";
    }
    else
        os << "()";
    return os;
}