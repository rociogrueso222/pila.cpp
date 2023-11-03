#include <iostream>
#include <windows.h>
#include <MMSystem.h> 
using namespace std;

struct Nodo {
    int id;
    string numero;
    string nombre;
    Nodo* sig;
};

Nodo* cab = NULL;

void push() {
    Nodo* nuevoNodo = new Nodo();
    cout << "\a"; 
    nuevoNodo->id = (cab == NULL) ? 1 : cab->id + 1;
    cout << "Ingrese el nu
	mero de telefono: ";
    cin >> nuevoNodo->numero;
    cout << "Ingrese el nombre del contacto: ";
    cin >> nuevoNodo->nombre;

    if (cab == NULL) {
        nuevoNodo->sig = NULL;
    } else {
        nuevoNodo->sig = cab;
    }
    cab = nuevoNodo;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    cout << "Llamada registrada correctamente." << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void viewer() {
    if (cab == NULL) {
        cout << "\a"; 
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        cout << "La lista de llamadas está vacía." << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        return;
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    cout << "\nLista de llamadas realizadas:\n";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    
    Nodo* temp = cab;
    while (temp != NULL) {
        cout << "ID: " << temp->id << ", Nombre: " << temp->nombre << ", NUmero: " << temp->numero << endl;
        temp = temp->sig;
    }
}

void pop() {
    if (cab == NULL) {
        cout << "\a"; 
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        cout << "La lista de llamadas esta vacia." << endl;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        return;
    }

    Nodo* temp = cab;
    cab = cab->sig;
    delete temp;

    cout << "\a";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
    cout << "La ultima llamada realizada ha sido eliminada." << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

int main() {
    int opcion = 0;
    do {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        cout << "\nMenu Pila:\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout << "1. Registrar Llamada\n";
        cout << "2. Mostrar Llamadas\n";
        cout << "3. Eliminar Ultima Llamada\n";
        cout << "4. Salir\n";
        cin >> opcion;

        switch (opcion) {
            case 1:
                push();
                break;
            case 2:
                viewer();
                break;
            case 3:
                pop();
                break;
            case 4:
                while (cab != NULL) {
                    Nodo* temp = cab;
                    cab = cab->sig;
                    delete temp;
                }
                break;
            default:
                cout << "\a"; 
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                cout << "Opción invalida. Por favor, seleccione una opcion valida." << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        }
    } while (opcion != 4);

    return 0;
}
