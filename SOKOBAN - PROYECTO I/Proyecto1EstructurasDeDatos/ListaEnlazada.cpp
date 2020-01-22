
//	ListaEnlazada.cpp
// Autores: Kislev Aleman, Josua Esquivel y Néstor Leiva
// Implementacion  de la clase ListaEnlazada


#include "ListaEnlazada.h"
#include<iostream>
#include<string>



// Metodo que realiza la insercion en la una lista enlasada de cuator enlaces.

void ListaEnlazada::insertar(NodoLista*& inicio, char letra, int linea) {
	int contLinea = 0;
	nuevo = new NodoLista;
	nuevo->caracter = letra;
	nuevo->aux = ' ';
	nuevo->abajo = nullptr;
	nuevo->arriba = nullptr;
	nuevo->derecho = nullptr;
	nuevo->izquierdo = nullptr;
	if (inicio == nullptr) {
		//std::cout << nuevo->caracter;
		inicio = nuevo;
	}
	else {
		NodoLista* tmp1 = inicio;
		NodoLista* tmp2 = inicio;
		NodoLista* tmp3 = nullptr;
		if (linea == 0) {

			while (tmp1->derecho != nullptr) {
				tmp1 = tmp1->derecho;
			}
			//std::cout << nuevo->caracter;
			tmp1->derecho = nuevo;
			nuevo->izquierdo = tmp1;

		}
		else {

			//std::cout << linea - 1;
			while (contLinea != linea - 1 && tmp1->abajo != nullptr) {
				tmp1 = tmp1->abajo;
				contLinea++;
			}
			if (tmp1->abajo == nullptr) {
				tmp1->abajo = nuevo;
			}
			else {
				tmp2 = tmp1;
				tmp1 = tmp1->abajo;
				while (tmp1->derecho != nullptr) {
					tmp1 = tmp1->derecho;
					tmp2 = tmp2->derecho;
				}
				tmp2 = tmp2->derecho;

				tmp1->derecho = nuevo;
				nuevo->arriba = tmp2;
				tmp2->abajo = nuevo;
				nuevo->izquierdo = tmp1;
			}
		}

	}
	//std::cout << nuevo->caracter << std::endl;
}




// Metodo que elimina de la lista enlazada.
void ListaEnlazada::BorrarLista(NodoLista*& inicio) {
	NodoLista* tmp1 = inicio;
	NodoLista* tmp;

	while (tmp1->abajo != nullptr) {
		inicio = inicio->derecho;
		NodoLista* tmp2;
		while (inicio != nullptr) {
			tmp = inicio;
			inicio = inicio->derecho;
			delete tmp;
		}
		tmp2 = tmp1;
		tmp1 = tmp1->abajo;
		inicio = tmp1;
		delete tmp2;
	}

}





//	Metodo que se encarga de cargar los objetos del nivel

void ListaEnlazada::verificarNivel(int nivel) {
	if (nivel == 1) {
		filaMapa = NUM_NIVEL1;
		columnaMapa = NUM_NIVEL1;

	}
	else if (nivel == 2) {
		filaMapa = NUM_NIVEL1;
		columnaMapa = NUM_NIVEL1;

	}
	else if (nivel == 3) {
		filaMapa = NUM_NIVEL1;
		columnaMapa = NUM_NIVEL1;
	}
}


// Metodo que se encarga de cargar los objetos del nivel.
void ListaEnlazada::cargarTexturasNivel(std::string matriz, int nivel) {

	char caracter = ' ';
	int nuemerocontador = matriz.length();
	verificarNivel(nivel);

	for (int i = 0; i < nuemerocontador; i++) {

		/* Llena el vector del area de juego con los datos
		 contenidos en el string que conteniene la informacion de la lista enlazada.
		 */
		areaJuego.push_back(matriz[i]); 

		// Se imprime por consola
		std::cout << areaJuego[i];
	}
}



//	Recorre la lista enlazada mostrando el contenido de cada uno de los elementos.
void ListaEnlazada::mostrarLista(NodoLista*& n) {
	NodoLista* ax = n;
	if (listaVacia(ax)) {
		std::cout << std::endl << std::endl << "La lista no tiene elementos..." << std::endl;
	}
	else
	{
		int i = 1;
		NodoLista* tmp;
		tmp = n;
		while (tmp != nullptr) {
			std::cout << "Elemento #" << i++ << " " << tmp->caracter << std::endl;
			tmp = tmp->next;
		}
	}
}





// Metodo que verifica que la lista se encuntra vacia y retorna un valor verdadero
//o falso segun el caso.

bool ListaEnlazada::listaVacia(NodoLista*& nood) {
	if (nood == nullptr) {
		return true;

	}
	return false;
}












NodoLista* ListaEnlazada::posicionJugador(NodoLista*& inicio) {
	NodoLista* jugador = inicio;
	NodoLista* tmp = inicio;
	NodoLista* tmp2 = nullptr;


	while (tmp->abajo != nullptr) {
		while (jugador->derecho != nullptr && jugador->caracter != '@') {
			jugador = jugador->derecho;

		}
		if (jugador->caracter == '@') {
			tmp2 = jugador;
			break;
		}
		else {
			jugador = tmp->abajo;
			tmp = tmp->abajo;

		}
	}
	tmp = nullptr;

	return tmp2;
}


void ListaEnlazada::movimientoJugadorArriba(NodoLista*& jugador) {
	NodoLista* posicionMover;
	NodoLista* tmp;
	if (jugador->caracter == '@' && jugador->arriba != nullptr) {
		posicionMover = jugador->arriba;
		if (posicionMover->caracter == '$') {
			tmp = posicionMover->arriba;
			if (tmp->caracter == ' ') {
				tmp->caracter = posicionMover->caracter;
				posicionMover->caracter = jugador->caracter;
				if (jugador->aux == '.') {
					jugador->caracter = jugador->aux;
				}
				else {
					jugador->caracter = ' ';
				}



			}
			else if (tmp->caracter == '#') {


			}
			else if (tmp->caracter == '.') {
				tmp->caracter = '!';
				posicionMover->caracter = jugador->caracter;
				if (jugador->aux == '.') {
					jugador->caracter = jugador->aux;
				}
				else {
					jugador->caracter = ' ';
				}

			}

		}
		else if (posicionMover->caracter == ' ') {
			posicionMover->caracter = jugador->caracter;
			if (jugador->aux == '.') {
				jugador->caracter = jugador->aux;
			}
			else {
				jugador->caracter = ' ';
			}
		}
		else if (posicionMover->caracter == '#') {


		}
		else if (posicionMover->caracter == '.') {
			posicionMover->aux = posicionMover->caracter;
			posicionMover->caracter = jugador->caracter;
			if (jugador->aux == '.') {
				jugador->caracter = jugador->aux;
			}
			else {
				jugador->caracter = ' ';
			}
		}
		else if (posicionMover->caracter = '!') {
			NodoLista* tmp2 = posicionMover->arriba;
			if (tmp2->caracter == '.') {
				tmp2->caracter = '!';
				posicionMover->aux = '.';
				posicionMover->caracter = jugador->caracter;
				if (jugador->aux == '.') {
					jugador->caracter = jugador->aux;
				}
				else {
					jugador->caracter = ' ';
				}
			}
		}


	}
}

void ListaEnlazada::movimientoJugadorAbajo(NodoLista*& jugador) {
	NodoLista* posicionMover;
	NodoLista* tmp;
	if (jugador->caracter == '@' && jugador->abajo != nullptr) {
		posicionMover = jugador->abajo;
		if (posicionMover->caracter == '$') {
			tmp = posicionMover->abajo;
			if (tmp->caracter == ' ') {
				tmp->caracter = posicionMover->caracter;
				posicionMover->caracter = jugador->caracter;
				if (jugador->aux == '.') {
					jugador->caracter = jugador->aux;
				}
				else {
					jugador->caracter = ' ';
				}



			}
			else if (tmp->caracter == '#') {


			}
			else if (tmp->caracter == '.') {
				tmp->caracter = '!';
				posicionMover->caracter = jugador->caracter;
				if (jugador->aux == '.') {
					jugador->caracter = jugador->aux;
				}
				else {
					jugador->caracter = ' ';
				}

			}
		}
		else if (posicionMover->caracter == ' ') {
			posicionMover->caracter = jugador->caracter;
			if (jugador->aux == '.') {
				jugador->caracter = jugador->aux;
			}
			else {
				jugador->caracter = ' ';
			}
		}
		else if (posicionMover->caracter == '#') {


		}
		else if (posicionMover->caracter == '.') {
			posicionMover->aux = posicionMover->caracter;
			posicionMover->caracter = jugador->caracter;
			if (jugador->aux == '.') {
				jugador->caracter = jugador->aux;
			}
			else {
				jugador->caracter = ' ';
			}
		}
		else if (posicionMover->caracter = '!') {
			NodoLista* tmp2 = posicionMover->abajo;
			if (tmp2->caracter == '.') {
				tmp2->caracter = '!';
				posicionMover->aux = '.';
				posicionMover->caracter = jugador->caracter;
				if (jugador->aux == '.') {
					jugador->caracter = jugador->aux;
				}
				else {
					jugador->caracter = ' ';
				}
			}
		}
	}


}

void ListaEnlazada::movimientoJugadorIzquierda(NodoLista*& jugador) {
	NodoLista* posicionMover;
	NodoLista* tmp;
	if (jugador->caracter == '@' && jugador->izquierdo != nullptr) {
		posicionMover = jugador->izquierdo;
		if (posicionMover->caracter == '$') {
			tmp = posicionMover->izquierdo;
			if (tmp->caracter == ' ') {
				tmp->caracter = posicionMover->caracter;
				posicionMover->caracter = jugador->caracter;
				if (jugador->aux == '.') {
					jugador->caracter = jugador->aux;
				}
				else {
					jugador->caracter = ' ';
				}



			}
			else if (tmp->caracter == '#') {


			}
			else if (tmp->caracter == '.') {
				tmp->caracter = '!';
				posicionMover->caracter = jugador->caracter;
				if (jugador->aux == '.') {
					jugador->caracter = jugador->aux;
				}
				else {
					jugador->caracter = ' ';
				}
			}


		}
		else if (posicionMover->caracter == ' ') {
			posicionMover->caracter = jugador->caracter;
			if (jugador->aux == '.') {
				jugador->caracter = jugador->aux;
			}
			else {
				jugador->caracter = ' ';
			}
		}
		else if (posicionMover->caracter == '#') {


		}
		else if (posicionMover->caracter == '.') {
			posicionMover->aux = posicionMover->caracter;
			posicionMover->caracter = jugador->caracter;
			if (jugador->aux == '.') {
				jugador->caracter = jugador->aux;
			}
			else {
				jugador->caracter = ' ';
			}
		}
		else if (posicionMover->caracter = '!') {
			NodoLista* tmp2 = posicionMover->izquierdo;
			if (tmp2->caracter == '.') {
				tmp2->caracter = '!';
				posicionMover->aux = '.';
				posicionMover->caracter = jugador->caracter;
				if (jugador->aux == '.') {
					jugador->caracter = jugador->aux;
				}
				else {
					jugador->caracter = ' ';
				}
			}
		}
	}


}

void ListaEnlazada::movimientoJugadorDerecha(NodoLista*& jugador) {
	NodoLista* posicionMover;
	NodoLista* tmp;
	if (jugador->caracter == '@' && jugador->derecho != nullptr) {
		posicionMover = jugador->derecho;
		if (posicionMover->caracter == '$') {
			tmp = posicionMover->derecho;
			if (tmp->caracter == ' ') {
				tmp->caracter = posicionMover->caracter;
				posicionMover->caracter = jugador->caracter;
				if (jugador->aux == '.') {
					jugador->caracter = jugador->aux;
				}
				else {
					jugador->caracter = ' ';
				}



			}
			else if (tmp->caracter == '#') {


			}
			else if (tmp->caracter == '.') {
				tmp->caracter = '!';
				posicionMover->caracter = jugador->caracter;
				if (jugador->aux == '.') {
					jugador->caracter = jugador->aux;
				}
				else {
					jugador->caracter = ' ';
				}
			}
		}
		else if (posicionMover->caracter == ' ') {
			posicionMover->caracter = jugador->caracter;
			if (jugador->aux == '.') {
				jugador->caracter = jugador->aux;
			}
			else {
				jugador->caracter = ' ';
			}
		}
		else if (posicionMover->caracter == '#') {


		}
		else if (posicionMover->caracter == '.') {
			posicionMover->aux = posicionMover->caracter;
			posicionMover->caracter = jugador->caracter;
			if (jugador->aux == '.') {
				jugador->caracter = jugador->aux;
			}
			else {
				jugador->caracter = ' ';
			}
		}
		else if (posicionMover->caracter = '!') {
			NodoLista* tmp2 = posicionMover->derecho;
			if (tmp2->caracter == '.') {
				tmp2->caracter = '!';
				posicionMover->aux = '.';
				posicionMover->caracter = jugador->caracter;
				if (jugador->aux == '.') {
					jugador->caracter = jugador->aux;
				}
				else {
					jugador->caracter = ' ';
				}
			}
		}


	}
}


















std::string ListaEnlazada::leerMatris(NodoLista*& inicio) {

	std::string matriz = "";
	NodoLista* tmp1 = inicio;
	NodoLista* tmp2;

	while (tmp1 != nullptr) {
		tmp2 = tmp1;
		while (tmp2 != nullptr)
		{
			matriz += tmp2->caracter;
			tmp2 = tmp2->derecho;
		}
		matriz += "\n";
		tmp1 = tmp1->abajo;
	}
	return matriz;
}








