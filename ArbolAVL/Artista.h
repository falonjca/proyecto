#ifndef ARTISTA_H
#define ARTISTA_H


#include <iostream>
#include <string>

using namespace std;

class Artista {

    public:
    string cedula;
    string apellido;
    string nombre;
    string telefono;
    string email;
    string provincia;
    string canton;
    string barrio;


    Artista(string ced, string ape, string nom, string tel, string mail, string prov, string cant, string bar);

    void mostrarArtista();

   
};


#endif // ARTISTA_H