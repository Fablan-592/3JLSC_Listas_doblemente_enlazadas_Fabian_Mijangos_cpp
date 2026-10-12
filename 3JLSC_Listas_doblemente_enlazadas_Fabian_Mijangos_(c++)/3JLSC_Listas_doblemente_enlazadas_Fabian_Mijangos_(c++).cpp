#include <iostream>
using namespace std;
struct nodo {
	int dato;
	nodo* siguiente;
	nodo* anterior;
};

void imprimirlista(nodo* cabeza) {
	nodo* actual = cabeza;
	while (actual != nullptr) {
		cout << "Dato: " << actual->dato
			<< "| Direccion: " << actual
			<< "| Anterior: " << actual->anterior
			<< "| Siguiente: " << actual->siguiente << endl;
		actual = actual->siguiente;
	}
	cout << endl;
}

void imprimirlistarever(nodo* cola) {
	nodo* actual = cola;
	while (actual != nullptr) {
		cout << "Dato: " << actual->dato
			<< "| Direccion: " << actual
			<< "| Anterior: " << actual->anterior
			<< "| Siguiente: " << actual->siguiente << endl;
		actual = actual->anterior;
	}
	cout << endl;
}

void borrarlista(nodo*& cabeza, nodo*& cola) {
	int contador = 0;
	while (cabeza != nullptr) {
		nodo* siguiente = cabeza->siguiente;
		contador++;
		cout << "Elemento borrado " << contador
			<< "| Dato: " << cabeza->dato
			<< "| Direccion: " << cabeza << endl;
		delete cabeza;
		cabeza = siguiente;
	}
	cout << "Total de elementos borrados: " << contador << endl;
	cola = nullptr;
}

void agregarnodo(nodo*& cabeza, nodo*& cola, int valor) {
	nodo* nuevonodo = new nodo;
	nuevonodo->dato = valor;
	nuevonodo->siguiente = nullptr;
	nuevonodo->anterior = nullptr;

	if (cabeza == nullptr) {
		cabeza = nuevonodo;
		cola = nuevonodo;
	}
	else {
		cola->siguiente = nuevonodo;
		nuevonodo->anterior = cola;
		cola = nuevonodo;
	}
}

int main() {
	cout << "Actividad 08 - Lista doblemente enlazada\n";
	nodo* cabeza = nullptr;
	nodo* cola = nullptr;
	int tamanolista;

	cout << "Ingrese la cantidad de elementos de la lista enlazada: ";
	cin >> tamanolista;
	if (tamanolista <= 0) {
		cout << "Cantidad de elementos no valida" << endl;
		return 1;
	}
	for (int i = 0; i < tamanolista; i++) {
		int valor;
		cout << "Ingrese el dato " << i + 1 << ": ";
		cin >> valor;
		agregarnodo(cabeza, cola, valor);
	}
	cout << "\n imprimiendo lista (de inicio a fin): " << endl;
	imprimirlista(cabeza);

	cout << "Imprimiendo lista (de fin a inicio): " << endl;
	imprimirlistarever(cola);

	cout << "\n borrando lista de numeros" << endl;
	borrarlista(cabeza, cola);

	return 0;
}