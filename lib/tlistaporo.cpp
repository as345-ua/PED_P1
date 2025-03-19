//Abdallah Shaitani 2602245
#include "./../include/tlistaporo.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

TListaNodo::TListaNodo (){
    TPoro eTemp;
    e = eTemp;

    this->anterior = nullptr;
    this->siguiente = nullptr;

}
// Constructor de copia         
TListaNodo::TListaNodo(const TListaNodo& other) {
    // Defensive copy for e (assuming e is a pointer to TPoro)
    this->e = other.e;  // Deep copy of the TPoro object

    // Defensive copy for anterior and siguiente (assuming these are pointers)
    if (other.anterior != nullptr) {
        this->anterior = new TListaNodo(*other.anterior);  // Deep copy of the previous node
    } else {
        this->anterior = nullptr;  // If there's no previous node, set it to nullptr
    }

    if (other.siguiente != nullptr) {
        this->siguiente = new TListaNodo(*other.siguiente);  // Deep copy of the next node
    } else {
        this->siguiente = nullptr;  // If there's no next node, set it to nullptr
    }
}

TListaNodo::~TListaNodo() {
    // Recursively delete the 'anterior' and 'siguiente' nodes
    delete anterior;  // Deleting the previous node (if it exists)
    delete siguiente; // Deleting the next node (if it exists)
}

// Sobrecarga del operador asignación
TListaNodo & TListaNodo::operator=(const TListaNodo & other){

    if (this != &other)
    {
        if(this->anterior != nullptr){
            delete this->anterior;
        }
        if(this->siguiente != nullptr){
            delete this->siguiente;
        }
        this->e = other.e;
    }
    if (other.anterior != nullptr)
    {
        this->anterior = new TListaNodo(*other.anterior);
    }else{
        this->anterior = nullptr;
    }
    if (other.siguiente != nullptr)
    {
        this->siguiente = new TListaNodo(*other.siguiente);
    }else{
        this->siguiente = nullptr;
    }
        return *this;
}
//__________________________________________________________________________________________
//__________________________________________________________________________________________
//__________________________________________________________________________________________
//__________________________________________________________________________________________
TListaPosicion::TListaPosicion (){

    this->pos = nullptr;
}
    // Constructor de copia
TListaPosicion::TListaPosicion (const TListaPosicion& other){
    this->pos = other.pos;
}
    // Destructor
TListaPosicion::~TListaPosicion (){

    delete this->pos;
}
    // Sobrecarga del operador asignación
TListaPosicion& TListaPosicion::operator=(const TListaPosicion &other) {
        if (this != &other) {  // Avoid self-assignment
            this->pos = other.pos;  // Copy the pointer (shallow copy)
        }
        return *this;
}
    
// MÉTODOS
// Sobrecarga del operador igualdad
bool TListaPosicion::operator==(const TListaPosicion &other) {
    if (this->pos == nullptr && other.pos == nullptr) {
        return true;
    }
    if (this->pos == nullptr || other.pos == nullptr) {
        return false;
    }
    return this->pos->e == other.pos->e;  // Compare TPoro objects
}


// Devuelve la posición anterior
TListaPosicion TListaPosicion::Anterior() const {
    TListaPosicion anteriorPos;
    anteriorPos.pos = this->pos ? this->pos->anterior : nullptr;
    return anteriorPos;
}

// Devuelve la posición siguiente
TListaPosicion TListaPosicion::Siguiente() const {
    TListaPosicion siguientePos;
    siguientePos.pos = this->pos ? this->pos->siguiente : nullptr;
    return siguientePos;
}

    // Devuelve TRUE si la posición no apunta a una lista, FALSE en caso contrario
bool TListaPosicion::EsVacia() const{
    if (this->pos == nullptr){
        return true;
    }else{
        return false;
    }
}
//__________________________________________________________________________________________
//__________________________________________________________________________________________
//__________________________________________________________________________________________
//__________________________________________________________________________________________
TListaPoro::TListaPoro(){
    this->primero = nullptr;
    this->ultimo = nullptr;
}

TListaPoro::TListaPoro(const TListaPoro & other){
    this->primero = other.primero;
    this->ultimo = other.ultimo;
}

TListaPoro::~TListaPoro(){
    this->primero = nullptr;
    this->ultimo = nullptr;
}

TListaPoro& TListaPoro::operator=(const TListaPoro &other) {
    if (this != &other) {
        // Eliminar la lista actual manualmente
        TListaNodo *aux = this->primero;
        while (aux) {
            TListaNodo *temp = aux;
            aux = aux->siguiente;
            delete temp;
        }

        this->primero = nullptr;
        this->ultimo = nullptr;

        // Copiar cada nodo de 'other'
        aux = other.primero;
        while (aux) {
            this->Insertar(aux->e);
            aux = aux->siguiente;
        }
    }
    return *this;
}

bool TListaPoro::operator==(const TListaPoro &other) {
    TListaNodo *aux1 = this->primero;
    TListaNodo *aux2 = other.primero;

    while (aux1 && aux2) {
        if (!(aux1->e == aux2->e)) {
            return false;
        }
        aux1 = aux1->siguiente;
        aux2 = aux2->siguiente;
    }

    return aux1 == nullptr && aux2 == nullptr;  // Both lists should end at the same time
}



TListaPoro TListaPoro::operator+(const TListaPoro &lista){
    TListaPoro resultado;
    TListaPosicion pos1 = this->Primera();
    TListaPosicion pos2 = lista.Primera();

    while (!pos1.EsVacia() || !pos2.EsVacia()) {
        if (pos1.EsVacia()) {
            resultado.Insertar(lista.Obtener(pos2));
            pos2 = pos2.Siguiente();
        } else if (pos2.EsVacia()) {
            resultado.Insertar(this->Obtener(pos1));
            pos1 = pos1.Siguiente();
        } else {
            TPoro p1 = this->Obtener(pos1);
            TPoro p2 = lista.Obtener(pos2);

            if (p1.Volumen() < p2.Volumen()) {
                resultado.Insertar(p1);
                pos1 = pos1.Siguiente();
            } else if (p2.Volumen() < p1.Volumen()) {
                resultado.Insertar(p2);
                pos2 = pos2.Siguiente();
            } else { // Equal volume, insert one and move both
                resultado.Insertar(p1);
                pos1 = pos1.Siguiente();
                pos2 = pos2.Siguiente();
            }
        }
    }
    return resultado;
}

TListaPoro TListaPoro::operator-(const TListaPoro &lista){
    TListaPoro resultado;
    TListaPosicion pos = this->Primera();

    while (!pos.EsVacia()) {
        TPoro p = this->Obtener(pos);
        if (!lista.Buscar(p)) { // Insert only if not found in lista
            resultado.Insertar(p);
        }
        pos = pos.Siguiente();
    }
    return resultado;
}


bool TListaPoro::EsVacia() const{
    if (this->primero == nullptr && this->ultimo == nullptr)
    {
        return true;
    }else{
        return false;
    }
}

bool TListaPoro::Insertar(const TPoro &poro) {
    TListaNodo *nuevo = new TListaNodo();
    nuevo->e = poro;
    if (this->primero == nullptr) {
        this->primero = nuevo;
        this->ultimo = nuevo;
    } else {
        this->ultimo->siguiente = nuevo;
        nuevo->anterior = this->ultimo;
        this->ultimo = nuevo;
    }
    return true;
}
bool TListaPoro::Borrar(const TPoro &poro) {
    TListaNodo *aux = this->primero;
    while (aux != nullptr) {
        if (aux->e == poro) {
            if (aux->anterior != nullptr) {
                aux->anterior->siguiente = aux->siguiente;
            } else {
                this->primero = aux->siguiente;
            }
            if (aux->siguiente != nullptr) {
                aux->siguiente->anterior = aux->anterior;
            } else {
                this->ultimo = aux->anterior;
            }
            delete aux;
            return true;
        }
        aux = aux->siguiente;
    }
    return false;
}


bool TListaPoro::Borrar(TListaPosicion &pos) {
    if (pos.pos == nullptr) {  // Check if pos is nullptr
        return false;
    }
    if (pos.pos->anterior != nullptr) {
        pos.pos->anterior->siguiente = pos.pos->siguiente;
    } else {
        this->primero = pos.pos->siguiente;
    }
    if (pos.pos->siguiente != nullptr) {
        pos.pos->siguiente->anterior = pos.pos->anterior;
    } else {
        this->ultimo = pos.pos->anterior;
    }
    delete pos.pos;  // Delete the node at pos
    return true;
}

TPoro TListaPoro::Obtener(const TListaPosicion &pos) const {
    return pos.pos->e;
}


bool TListaPoro::Buscar(const TPoro &poro) const {
    TListaNodo *aux = this->primero;
    while (aux != nullptr) {
        if (aux->e == poro) {
            return true;  // Found the matching TPoro
        }
        aux = aux->siguiente;  // Move to the next node
    }
    return false;  // If we reach here, the poro wasn't found
}

int TListaPoro::Longitud() const{
    int cont = 0;
    TListaNodo *aux = this->primero;
    while (aux != nullptr)
    {
        cont++;
        aux = aux->siguiente;
    }
    return cont;
}

TListaPosicion TListaPoro::Primera() const{
    TListaPosicion pos;
    pos.pos = this->primero;
    return pos;
}

TListaPosicion TListaPoro::Ultima() const{
    TListaPosicion pos;
    pos.pos = this->ultimo;
    return pos;
}

TListaPoro TListaPoro::ExtraerRango(int n1, int n2){
    TListaPoro lista;
    TListaNodo *aux = this->primero;
    int cont = 1;
    while (aux != nullptr)
    {
        if (cont >= n1 && cont <= n2)
        {
            lista.Insertar(aux->e);
        }
        cont++;
        aux = aux->siguiente;
    }
    return lista;
}

ostream& operator<<(ostream &os, const TListaPoro &lista) {
    if(lista.primero == nullptr){
        os << "()";
        return os;
    }

    TListaNodo *aux = lista.primero;

    os << "(" << aux->e << "," << aux->e.PosicionX() << "," << aux->e.PosicionY() << "," << aux->e.Volumen() << ")";

    while (aux != nullptr){
        if(lista.primero == nullptr){
            os << "()";
            return os;
        }
    
        TListaNodo *aux = lista.primero;
    
        os << "(" << aux->e << "," << aux->e.PosicionX() << "," << aux->e.PosicionY() << "," << aux->e.Volumen() << ")";
    
        while (aux != nullptr)
        {
            aux = aux->siguiente;
            os << ",(" << aux->e << "," << aux->e.PosicionX() << "," << aux->e.PosicionY() << "," << aux->e.Volumen() << ")";
        }
        os << ")";
        return os;
    }
    {
        aux = aux->siguiente;
        os << ",(" << aux->e << "," << aux->e.PosicionX() << "," << aux->e.PosicionY() << "," << aux->e.Volumen() << ")";
    }
    os << ")";
    return os;
}