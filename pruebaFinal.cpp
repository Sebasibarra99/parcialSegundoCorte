#include <iostream>
#include <queue>
#include <stack>

using namespace std;


struct NodoArbol {
    char dato;
    NodoArbol* izquierda;
    NodoArbol* derecha;
};


struct NodoLista {
    char dato;
    NodoLista* anterior;
    NodoLista* siguiente;
};


NodoArbol* crearNodoArbol(char dato) {
    NodoArbol* nuevoNodo = new NodoArbol();
    nuevoNodo->dato = dato;
    nuevoNodo->izquierda = nullptr;
    nuevoNodo->derecha = nullptr;
    return nuevoNodo;
}


NodoLista* crearNodoLista(char dato) {
    NodoLista* nuevoNodo = new NodoLista();
    nuevoNodo->dato = dato;
    nuevoNodo->anterior = nullptr;
    nuevoNodo->siguiente = nullptr;
    return nuevoNodo;
}


void ingresarCola(queue<char>* cola) {
    char elemento;
    char opcion;
    do {
        cout << "Ingrese un elemento a la cola: ";
        cin >> elemento;
        cola->push(elemento);
        cout << "¿Desea ingresar otro elemento a la cola? (s/n): ";
        cin >> opcion;
    } while (opcion == 's' || opcion == 'S');
}


void ingresarPila(stack<char>* pila) {
    char elemento;
    char opcion;
    do {
        cout << "Ingrese un elemento a la pila: ";
        cin >> elemento;
        pila->push(elemento);
        cout << "¿Desea ingresar otro elemento a la pila? (s/n): ";
        cin >> opcion;
    } while (opcion == 's' || opcion == 'S');
}


void imprimirArbol(NodoArbol* nodo) {
    if (nodo != nullptr) {
        imprimirArbol(nodo->izquierda);
        cout << nodo->dato << " ";
        imprimirArbol(nodo->derecha);
    }
}


void imprimirListaAdelante(NodoLista* inicio) {
    cout << "Lista hacia adelante: ";
    while (inicio != nullptr) {
        cout << inicio->dato << " ";
        inicio = inicio->siguiente;
    }
    cout << endl;
}


void imprimirListaAtras(NodoLista* fin) {
    cout << "Lista hacia atrás: ";
    while (fin != nullptr) {
        cout << fin->dato << " ";
        fin = fin->anterior;
    }
    cout << endl;
}


void construirLista(queue<char>& cola, stack<char>& pila, NodoLista** inicio, NodoLista** fin) {
    *inicio = nullptr;
    *fin = nullptr;

    while (!cola.empty()) {
        char dato = cola.front();
        cola.pop();
        NodoLista* nuevoNodo = crearNodoLista(dato);
        if (*inicio == nullptr) {
            *inicio = nuevoNodo;
            *fin = nuevoNodo;
        } else {
            (*fin)->siguiente = nuevoNodo;
            nuevoNodo->anterior = *fin;
            *fin = nuevoNodo;
        }
    }

    while (!pila.empty()) {
        char dato = pila.top();
        pila.pop();
        NodoLista* nuevoNodo = crearNodoLista(dato);
        if (*inicio == nullptr) {
            *inicio = nuevoNodo;
            *fin = nuevoNodo;
        } else {
            (*fin)->siguiente = nuevoNodo;
            nuevoNodo->anterior = *fin;
            *fin = nuevoNodo;
        }
    }
}


int main() {
    queue<char> cola;
    stack<char> pila;

    char opcion;
    NodoArbol* raiz = nullptr;
    NodoLista* inicioLista = nullptr;
    NodoLista* finLista = nullptr;

    do {
        cout << "\nMENU:\n";
        cout << "1. Ingresar elementos a una cola\n";
        cout << "2. Ingresar elementos a una pila\n";
        cout << "3. Terminar ingreso y crear árbol y lista doblemente enlazada\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case '1':
                ingresarCola(&cola);
                break;
            case '2':
                ingresarPila(&pila);
                break;
            case '3':
                construirLista(cola, pila, &inicioLista, &finLista);
                break;
            default:
                cout << "Opción no válida. Por favor, seleccione nuevamente.\n";
                break;
        }
    } while (opcion != '3');

    cout << "\nLa lista creada es: ";
    imprimirListaAdelante(inicioLista);
    imprimirListaAtras(finLista);

    return 0;
}

