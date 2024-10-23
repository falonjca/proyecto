#include "NodoAVL.h"

using namespace std;

NodoAVL::NodoAVL(Artista* art)
    : artista(art), izquierda(nullptr), derecha(nullptr), altura(1) {
}
 