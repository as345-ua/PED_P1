//Abdallah Shaitani 2602245
#pragma once

#include "tporo.h"
#include <iostream>
#include "tvectorporo.h"

using namespace std;

// Forward declaration of classes
class TListaNodo;
class TListaPosicion;
class TListaPoro;

class TListaNodo {
    friend class TListaPoro;
    friend class TListaPosicion;

private:
    TPoro e;
    TListaNodo *anterior;
    TListaNodo *siguiente;
    friend ostream &operator<<(ostream &, const TListaPoro &);

public:
    // Canonical form
    TListaNodo();
    TListaNodo(const TListaNodo &);
    ~TListaNodo();
    TListaNodo &operator=(const TListaNodo &);
};
//__________________________________________________________________________________________
//__________________________________________________________________________________________
//__________________________________________________________________________________________
//__________________________________________________________________________________________
class TListaPosicion {
    friend class TListaPoro;
    friend class TListaNodo;

private:
    TListaNodo *pos;

public:
    // Canonical form
    TListaPosicion();
    TListaPosicion(const TListaPosicion &);
    ~TListaPosicion();
    TListaPosicion &operator=(const TListaPosicion &);

    // Methods
    // Sobrecarga del operador asignación
    bool operator==(const TListaPosicion &);
    TListaPosicion Anterior() const;
    TListaPosicion Siguiente() const;
    bool EsVacia() const;
};
//__________________________________________________________________________________________
//__________________________________________________________________________________________
//__________________________________________________________________________________________
//__________________________________________________________________________________________
class TListaPoro {
    friend class TListaPosicion;
    friend class TListaNodo;
    friend ostream &operator<<(ostream &, const TListaPoro &);

private:
    TListaNodo *primero;
    TListaNodo *ultimo;

public:
    // Canonical form
    TListaPoro();
    TListaPoro(const TListaPoro &);
    ~TListaPoro();
    TListaPoro & operator=(const TListaPoro &);

    // Methods
    bool operator==(const TListaPoro &);
    TListaPoro operator+(const TListaPoro &);
    TListaPoro operator-(const TListaPoro &);
    bool EsVacia() const;
    bool Insertar(const TPoro &);
    bool Borrar(const TPoro &);
    bool Borrar(TListaPosicion &);
    TPoro Obtener(const TListaPosicion &) const;
    bool Buscar(const TPoro &) const;
    int Longitud() const;
    TListaPosicion Primera() const;
    TListaPosicion Ultima() const;
    TListaPoro ExtraerRango(int n1, int n2);
};
