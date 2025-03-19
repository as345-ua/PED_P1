//Abdallah Shaitani 2602245
//Complete
#include <iostream>
#include "./../include/tporo.h"
#include "./../include/tvectorporo.h"
#include <vector>
#include <cstring>

using namespace std;

// Constructor por defecto
TVectorPoro::TVectorPoro(){
    this->dimension = 0;
    this->datos = nullptr;
}
// Constructor a partir de una dimensión
TVectorPoro::TVectorPoro(int dim){
    if (dim <= 0){
        this->dimension = 0;
        this->datos = nullptr;
    }
    else {
        this->dimension = dim;
        this->datos = new TPoro[dim];
    }
}
 
// Constructor de copia
TVectorPoro::TVectorPoro(const TVectorPoro& other){
this->dimension = other.dimension;
if(this->dimension > 0){
    this->datos = new TPoro[this->dimension];
    for (int i = 0; i < this->dimension; i++){
        this->datos[i] = other.datos[i];
    }
}
else {
    this->datos = nullptr;
}
this->error = other.error;
}
// Destructor
TVectorPoro::~TVectorPoro(){
    delete[] datos;
    this->dimension = 0;
}
// Sobrecarga del operador asignación
TVectorPoro& TVectorPoro::operator=(const TVectorPoro & other){
if(this != &other){
    delete[] datos;
    this->dimension = other.dimension;
    if(this->dimension > 0){
        this->datos = new TPoro[this->dimension];
        for (int i = 0; i < this->dimension; i++){
            this->datos[i] = other.datos[i];
        }
    }
    else{
        this->datos = nullptr;
    }
    this->error = other.error;
}
return *this;
}

// Sobrecarga del operador igualdad
bool TVectorPoro::operator==(const TVectorPoro &other){
    bool temp;
    if (this->error == other.error)
    {
        return true;
    }else{
        return false;
    }
    
    if (this->dimension == other.dimension)
    {
        for(int i = 0;i < this->dimension;i++){
            if (this->datos[i] == other.datos[i])
            {
                temp = true;
            }else{
                return false;
            }
        }
        return temp;
    }
    return false;
}
// Sobrecarga del operador desigualdad
bool TVectorPoro::operator!=(const TVectorPoro &other){
    return !(*this == other);
}
// Sobrecarga del operador corchete (parte IZQUIERDA)
TPoro& TVectorPoro::operator[](const int pos){
    if(pos < 1 || pos > dimension)
        return error;
    return datos[pos - 1];
}
// Sobrecarga del operador corchete (parte DERECHA)
TPoro TVectorPoro::operator[](const int pos) const{
    if(pos < 1 || pos > dimension)
        return error;
    return datos[pos - 1];
}
// Devuelve la longitud (dimensión) del vector
int TVectorPoro::Longitud()const{
    return this->dimension;
}
// Devuelve la cantidad de posiciones ocupadas (no vacías) en el vector
int TVectorPoro::Cantidad()const{
    unsigned counter = 0;
    for(int i = 0;i < this->Longitud();i++){
        if (!this->datos[i].EsVacio())
        {
            counter++;
        }
    }
    return counter;
}
// REDIMENSIONAR el vector de TPoro
bool TVectorPoro::Redimensionar(int newDim){
    if(newDim <= 0 || newDim == dimension)
        return false;
    
    TPoro* NewData = new TPoro[newDim];

    int minDim = (newDim < dimension) ? newDim : dimension;

    for(int i = 0; i < minDim; i++){

        NewData[i] = datos[i];

    }
    // If newDim > dimension, new positions are left as default (empty) TPoro        
    delete[] datos;
    datos = NewData;
    dimension = newDim;
    return true;

}
ostream & operator<<(ostream & os, TVectorPoro & vector){
        os << "[";
    for(int i = 0; i < vector.Longitud(); i++){
        os << (i + 1) << " " << vector.datos[i];
        if(i < vector.dimension - 1)
            os << " ";
    }
    os << "]";
    return os;
}