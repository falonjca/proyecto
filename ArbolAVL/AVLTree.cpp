#include "AVLTree.h"
#include <algorithm>  // Para std::max

using namespace std;

AVLTree::AVLTree() : raiz(nullptr) {}

int AVLTree::altura(NodoAVL* nodo) {
    return nodo ? nodo->altura : 0;
}

int AVLTree::obtenerBalance(NodoAVL* nodo) {
    return nodo ? altura(nodo->izquierda) - altura(nodo->derecha) : 0;
}

NodoAVL* AVLTree::rotacionDerecha(NodoAVL* y) {
    NodoAVL* x = y->izquierda;
    NodoAVL* T2 = x->derecha;

    x->derecha = y;
    y->izquierda = T2;

    y->altura = max(altura(y->izquierda), altura(y->derecha)) + 1;
    x->altura = max(altura(x->izquierda), altura(x->derecha)) + 1;

    return x;
}

NodoAVL* AVLTree::rotacionIzquierda(NodoAVL* x) {
    NodoAVL* y = x->derecha;
    NodoAVL* T2 = y->izquierda;

    y->izquierda = x;
    x->derecha = T2;

    x->altura = max(altura(x->izquierda), altura(x->derecha)) + 1;
    y->altura = max(altura(y->izquierda), altura(y->derecha)) + 1;

    return y;
}

NodoAVL* AVLTree::insertar(NodoAVL* nodo, Artista* artista) {
    if (!nodo)
        return new NodoAVL(artista);

    if (artista->cedula < nodo->artista->cedula)
        nodo->izquierda = insertar(nodo->izquierda, artista);
    else if (artista->cedula > nodo->artista->cedula)
        nodo->derecha = insertar(nodo->derecha, artista);
    else
        return nodo; // No se permiten duplicados

    nodo->altura = max(altura(nodo->izquierda), altura(nodo->derecha)) + 1;

    int balance = obtenerBalance(nodo);

    // Caso rotaciones
    if (balance > 1 && artista->cedula < nodo->izquierda->artista->cedula)
        return rotacionDerecha(nodo);

    if (balance < -1 && artista->cedula > nodo->derecha->artista->cedula)
        return rotacionIzquierda(nodo);

    if (balance > 1 && artista->cedula > nodo->izquierda->artista->cedula) {
        nodo->izquierda = rotacionIzquierda(nodo->izquierda);
        return rotacionDerecha(nodo);
    }

    if (balance < -1 && artista->cedula < nodo->derecha->artista->cedula) {
        nodo->derecha = rotacionDerecha(nodo->derecha);
        return rotacionIzquierda(nodo);
    }

    return nodo;
}

NodoAVL* AVLTree::nodoMinimo(NodoAVL* nodo) {
    NodoAVL* actual = nodo;
    while (actual->izquierda)
        actual = actual->izquierda;
    return actual;
}

NodoAVL* AVLTree::eliminar(NodoAVL* raiz, string cedula) {
    if (!raiz)
        return raiz;

    if (cedula < raiz->artista->cedula)
        raiz->izquierda = eliminar(raiz->izquierda, cedula);
    else if (cedula > raiz->artista->cedula)
        raiz->derecha = eliminar(raiz->derecha, cedula);
    else {
        if (!raiz->izquierda || !raiz->derecha) {
            NodoAVL* temp = raiz->izquierda ? raiz->izquierda : raiz->derecha;

            if (!temp) {
                temp = raiz;
                raiz = nullptr;
            }
            else
                *raiz = *temp;

            delete temp;
        }
        else {
            NodoAVL* temp = nodoMinimo(raiz->derecha);
            raiz->artista = temp->artista;
            raiz->derecha = eliminar(raiz->derecha, temp->artista->cedula);
        }
    }

    if (!raiz)
        return raiz;

    raiz->altura = max(altura(raiz->izquierda), altura(raiz->derecha)) + 1;

    int balance = obtenerBalance(raiz);

    if (balance > 1 && obtenerBalance(raiz->izquierda) >= 0)
        return rotacionDerecha(raiz);

    if (balance > 1 && obtenerBalance(raiz->izquierda) < 0) {
        raiz->izquierda = rotacionIzquierda(raiz->izquierda);
        return rotacionDerecha(raiz);
    }

    if (balance < -1 && obtenerBalance(raiz->derecha) <= 0)
        return rotacionIzquierda(raiz);

    if (balance < -1 && obtenerBalance(raiz->derecha) > 0) {
        raiz->derecha = rotacionDerecha(raiz->derecha);
        return rotacionIzquierda(raiz);
    }

    return raiz;
}

void AVLTree::desplegarAscendente(NodoAVL* nodo) {
    if (nodo) {
        desplegarAscendente(nodo->izquierda);
        nodo->artista->mostrarArtista();
        desplegarAscendente(nodo->derecha);
    }
}

void AVLTree::desplegarDescendente(NodoAVL* nodo) {
    if (nodo) {
        desplegarDescendente(nodo->derecha);
        nodo->artista->mostrarArtista();
        desplegarDescendente(nodo->izquierda);
    }
}

NodoAVL* AVLTree::buscar(NodoAVL* nodo, string cedula) {
    if (!nodo || nodo->artista->cedula == cedula)
        return nodo;
    if (cedula < nodo->artista->cedula)
        return buscar(nodo->izquierda, cedula);
    return buscar(nodo->derecha, cedula);
}

void AVLTree::agregarArtista(Artista* artista) {
    raiz = insertar(raiz, artista);
}

void AVLTree::eliminarArtista(string cedula) {
    raiz = eliminar(raiz, cedula);
}

void AVLTree::desplegarArtistasAscendente() {
    desplegarAscendente(raiz);
}

void AVLTree::desplegarArtistasDescendente() {
    desplegarDescendente(raiz);
}

void AVLTree::consultarArtista(string cedula) {
    NodoAVL* nodo = buscar(raiz, cedula);
    if (nodo) {
        nodo->artista->mostrarArtista();
    }
    else {
        cout << "Artista con cédula " << cedula << " no encontrado." << endl;
    }
}
