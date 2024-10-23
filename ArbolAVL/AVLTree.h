#include <iostream>
#include "NodoAVL.h"

using namespace std;

class AVLTree {

private:
  
    NodoAVL* raiz;
    // Métodos privados
    int altura(NodoAVL* nodo);
    int obtenerBalance(NodoAVL* nodo);
    NodoAVL* rotacionDerecha(NodoAVL* y);
    NodoAVL* rotacionIzquierda(NodoAVL* x);
    NodoAVL* insertar(NodoAVL* nodo, Artista* artista);
    NodoAVL* nodoMinimo(NodoAVL* nodo);
    NodoAVL* eliminar(NodoAVL* raiz, string cedula);
    void desplegarAscendente(NodoAVL* nodo);
    void desplegarDescendente(NodoAVL* nodo);
    NodoAVL* buscar(NodoAVL* nodo, string cedula);

public:

    AVLTree();

    // Métodos públicos
    void agregarArtista(Artista* artista);
    void eliminarArtista(string cedula);
    void desplegarArtistasAscendente();
    void desplegarArtistasDescendente();
    void consultarArtista(string cedula);
};
