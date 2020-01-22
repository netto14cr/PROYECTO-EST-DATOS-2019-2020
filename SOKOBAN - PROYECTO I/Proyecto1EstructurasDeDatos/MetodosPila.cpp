
// MetodosPila.cpp
// Autores: Kislev Aleman, Josua Esquivel y Néstor Leiva
// Implementacion de la clase MetodosPila
#include"PilaCaja.h"


// Metodo de insertar dentro de la pila
std::stack<char> Pila::insertar(char caja) {
	std::stack<char> pilaCajas;


	if (pilaCajas.empty()) {


		pilaCajas.push(caja);
	}
	else {

		pilaCajas.push(caja);
	}

	return pilaCajas;
}



/*quita la ultima caja ingresada a la  pila*/
void Pila::quitarCajaDeLaPila(std::stack<char>& pilaCaja) {
	char aux;

	aux = pilaCaja.top();
	pilaCaja.pop();

}

/*borra la pila*/

void Pila::borrarPila(std::stack<char>& pilaCaja) {

	while (!pilaCaja.empty()) {

		pilaCaja.pop();
	}
}

