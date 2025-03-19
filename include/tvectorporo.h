//Abdallah Shaitani 2602245
//Complete
#pragma once

#include <iostream>
#include "./../include/tporo.h"
#include <vector>

using namespace std;

class TVectorPoro
{
    friend ostream & operator<<(ostream &, TVectorPoro &);
private:
    
    int dimension;
    TPoro *datos;
    TPoro error;
public:
    // Constructor por defecto
    TVectorPoro();
    // Constructor a partir de una dimensión
    TVectorPoro(int);
    // Constructor de copia
    TVectorPoro(const TVectorPoro &);
    // Destructor
    ~TVectorPoro();
    // Sobrecarga del operador asignación
    TVectorPoro & operator=(const TVectorPoro &);
    // Sobrecarga del operador igualdad
    bool operator==(const TVectorPoro &);
    // Sobrecarga del operador desigualdad
    bool operator!=(const TVectorPoro &);
    // Sobrecarga del operador corchete (parte IZQUIERDA)
    TPoro& operator[](const int);
    // Sobrecarga del operador corchete (parte DERECHA)
    TPoro operator[](int) const;
    // Devuelve la longitud (dimensión) del vector
    int Longitud() const;
    // Devuelve la cantidad de posiciones ocupadas (no vacías) en el vector
    int Cantidad() const;
    // REDIMENSIONAR el vector de TPoro
    bool Redimensionar(int);

};