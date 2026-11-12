
#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* izquierda;
    Nodo* derecha;
};

// Crear un nuevo nodo
Nodo* crearNodo(int valor) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->izquierda = NULL;
    nuevo->derecha = NULL;

    return nuevo;
}

// Insertar datos en el arbol
Nodo* insertar(Nodo* raiz, int valor) {
    if (raiz == NULL) {
        return crearNodo(valor);
    }

    if (valor < raiz->dato) {
        raiz->izquierda = insertar(raiz->izquierda, valor);
    }
    else {
        raiz->derecha = insertar(raiz->derecha, valor);
    }

    return raiz;
}

// RECORRIDO INORDEN
void inorden(Nodo* raiz) {
    if (raiz != NULL) {
        inorden(raiz->izquierda);
        cout << raiz->dato << " ";
        inorden(raiz->derecha);
    }
}

// RECORRIDO PREORDEN
void preorden(Nodo* raiz) {
    if (raiz != NULL) {
        cout << raiz->dato << " ";
        preorden(raiz->izquierda);
        preorden(raiz->derecha);
    }
}

// RECORRIDO POSORDEN
void posorden(Nodo* raiz) {
    if (raiz != NULL) {
        posorden(raiz->izquierda);
        posorden(raiz->derecha);
        cout << raiz->dato << " ";
    }
}

int main() {
    Nodo* raiz = NULL;
    int valor;

    cout << "Ingrese 5 numeros:\n";

    for (int i = 0; i < 5; i++) {
        cout << "Numero " << i + 1 << ": ";
        cin >> valor;

        raiz = insertar(raiz, valor);
    }

    cout << "\nRECORRIDOS DEL ARBOL\n";

    cout << "\nInorden: ";
    inorden(raiz);

    cout << "\nPreorden: ";
    preorden(raiz);

    cout << "\nPosorden: ";
    posorden(raiz);

    cout << endl;

    return 0;
}
