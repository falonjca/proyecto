#include "Artista.h"  
#include "AVLTree.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void mostrarMenu() {
    cout << "\n--- Bienvenido CenfoEstudiante, elija opcion ---\n";
    cout << "1. Agregar artista\n";
    cout << "2. Eliminar artista\n";
    cout << "3. Desplegar artistas  ascendente\n";
    cout << "4. Desplegar artistas en forma descendente\n";
    cout << "5. Consultar datos de un artista\n";
    cout << "6. Leer artistas de archivo\n";
    cout << "0. Salir\n";
    cout << "Seleccione una opcion: ";
}

void leerArchivo(AVLTree& arbol, string nombreArchivo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "Error abriendo el archivo." << endl;
        return;
    }

    string cedula, apellido, nombre, telefono, email, provincia, canton, barrio;
    while (archivo >> cedula >> apellido >> nombre >> telefono >> email >> provincia >> canton >> barrio) {
        Artista* nuevoArtista = new Artista(cedula, apellido, nombre, telefono, email, provincia, canton, barrio);
        arbol.agregarArtista(nuevoArtista);
    }

    archivo.close();
    cout << "Artistas cargados desde el archivo con éxito.\n";
}

int main() {
    AVLTree arbolArtistas;
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
        case 1: {
            string cedula, apellido, nombre, telefono, email, provincia, canton, barrio;
            cout << "Ingrese los datos del artista:\n";
            cout << "Cedula: "; cin >> cedula;
            cout << "Apellido: "; cin >> apellido;
            cout << "Nombre: "; cin >> nombre;
            cout << "Telefono: "; cin >> telefono;
            cout << "Email: "; cin >> email;
            cout << "Provincia: "; cin >> provincia;
            cout << "Canton: "; cin >> canton;
            cout << "Barrio: "; cin >> barrio;

            Artista* nuevoArtista = new Artista(cedula, apellido, nombre, telefono, email, provincia, canton, barrio);
            arbolArtistas.agregarArtista(nuevoArtista);
            cout << "Artista agregado con exito.\n";
            break;
        }

        case 2: {
            string cedula;
            cout << "Ingrese la cedula del artista que desea eliminar: ";
            cin >> cedula;
            arbolArtistas.eliminarArtista(cedula);
            cout << "Artista eliminado (si existia).\n";
            break;
        }

        case 3: {
            cout << "Lista de artistas en forma ascendente:\n";
            arbolArtistas.desplegarArtistasAscendente();
            break;
        }

        case 4: {
            cout << "Lista de artistas en forma descendente:\n";
            arbolArtistas.desplegarArtistasDescendente();
            break;
        }

        case 5: {
            string cedula;
            cout << "Ingrese la cedula del artista que desea consultar: ";
            cin >> cedula;
            arbolArtistas.consultarArtista(cedula);
            break;
        }

        case 6: {
            string nombreArchivo = "artistas.txt"; // Asegúrate de que el archivo esté en el directorio correcto
            leerArchivo(arbolArtistas, nombreArchivo);
            break;
        }

        case 0: {
            cout << "Saliendo del programa.\n";
            break;
        }

        default:
            cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != 0);

    return 0;
}
