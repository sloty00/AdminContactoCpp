// AdminCcontactosCpp.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <vector>
#include <string>

struct Contacto {
    std::string nombre;
    std::string telefono;
};

// Declaración de funciones
void agregarContacto(std::vector<Contacto>& contactos);
void mostrarContactos(const std::vector<Contacto>& contactos);
void eliminarContacto(std::vector<Contacto>& contactos);
void salir();

// Tipo de puntero a función
typedef void(*MenuOption)(std::vector<Contacto>&, const std::vector<Contacto>&);

int main() {
    std::vector<Contacto> contactos;
    MenuOption opciones[] = {
        [](std::vector<Contacto>& c, const std::vector<Contacto>&) { agregarContacto(c); },
        [](std::vector<Contacto>& c, const std::vector<Contacto>&) { mostrarContactos(c); },
        [](std::vector<Contacto>& c, const std::vector<Contacto>&) { eliminarContacto(c); },
        [](std::vector<Contacto>&, const std::vector<Contacto>&) { salir(); }
    };

    int eleccion;
    bool salirDelPrograma = false;

    while (!salirDelPrograma) {
        std::cout << "Menu:\n";
        std::cout << "1. Agregar Contacto\n";
        std::cout << "2. Mostrar Contactos\n";
        std::cout << "3. Eliminar Contacto\n";
        std::cout << "4. Salir\n";
        std::cout << "Ingrese su opcion: ";
        std::cin >> eleccion;
        std::cin.ignore(); // Limpiar el buffer de entrada

        if (eleccion >= 1 && eleccion <= 4) {
            // Llamar a la función correspondiente usando el puntero
            opciones[eleccion - 1](contactos, contactos);
            if (eleccion == 4) {
                salirDelPrograma = true;
            }
        }
        else {
            std::cout << "Opción no válida. Intente de nuevo.\n";
        }
    }

    return 0;
}

void agregarContacto(std::vector<Contacto>& contactos) {
    Contacto nuevoContacto;
    std::cout << "Ingrese el nombre del contacto: ";
    std::getline(std::cin, nuevoContacto.nombre);
    std::cout << "Ingrese el teléfono del contacto: ";
    std::getline(std::cin, nuevoContacto.telefono);
    contactos.push_back(nuevoContacto);
    std::cout << "Contacto agregado exitosamente.\n";
}

void mostrarContactos(const std::vector<Contacto>& contactos) {
    if (contactos.empty()) {
        std::cout << "No hay contactos para mostrar.\n";
        return;
    }

    std::cout << "Lista de Contactos:\n";
    for (const auto& contacto : contactos) {
        std::cout << "Nombre: " << contacto.nombre << ", Teléfono: " << contacto.telefono << "\n";
    }
}

void eliminarContacto(std::vector<Contacto>& contactos) {
    std::string nombre;
    std::cout << "Ingrese el nombre del contacto a eliminar: ";
    std::getline(std::cin, nombre);

    auto it = std::remove_if(contactos.begin(), contactos.end(), [&nombre](const Contacto& c) {
        return c.nombre == nombre;
        });

    if (it != contactos.end()) {
        contactos.erase(it, contactos.end());
        std::cout << "Contacto eliminado exitosamente.\n";
    }
    else {
        std::cout << "Contacto no encontrado.\n";
    }
}

void salir() {
    std::cout << "Saliendo del programa...\n";
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
