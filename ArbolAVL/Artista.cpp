#include "Artista.h"
#include <iostream>

using namespace std;

Artista::Artista(string ced, string ape, string nom, string tel, string mail, string prov, string cant, string bar)
    : cedula(ced), apellido(ape), nombre(nom), telefono(tel), email(mail), provincia(prov), canton(cant), barrio(bar) {}

void Artista::mostrarArtista() {
    cout << "Cedula: " << cedula << ", Apellido: " << apellido << ", Nombre: " << nombre
        << ", Telefono: " << telefono << ", Email: " << email
        << ", Provincia: " << provincia << ", Canton: " << canton
        << ", Barrio: " << barrio << endl;
}
