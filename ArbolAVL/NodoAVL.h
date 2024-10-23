#include <iostream>
#include "Artista.h"

using namespace std;

class NodoAVL {

public:
    Artista* artista;
    NodoAVL* izquierda;
    NodoAVL* derecha;
    int altura;


    NodoAVL(Artista* art);
};


