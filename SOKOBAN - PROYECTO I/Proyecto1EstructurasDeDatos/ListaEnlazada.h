
#ifndef ListaEnlazada_H
#define ListaEnlazada_H


#include<vector>
#include <string>
#include <iostream>
using std::vector;
using std::string;

#define NUM_NIVEL1 8;
#define NUM_NIVEL2 8;
#define NUM_NIVEL3 8;

struct NodoLista {

	char caracter ;
	char aux;
	NodoLista* arriba;
	NodoLista* abajo;
	NodoLista* izquierdo;
	NodoLista* derecho;
	int valor;
	NodoLista* next;

};



class ListaEnlazada {
public:
	ListaEnlazada() {
		inicio = nullptr;
		//nuevo = nullptr;
	}
	~ListaEnlazada() {}
	//ListaEnlazada(&ListaEnlazada);

		//NUM_NIVEL1;

	void insertar(NodoLista*&, char, int);
	
	std::vector<char> areaJuego;
	//char areaJuego[99][99];

	string leerMatris(NodoLista*&);
	void mostrarLista(NodoLista*& n);

	void cargarTexturasNivel(std::string mat, int nivel);

	int columnaMapa;
	int filaMapa;
	int posicionActY;
	int posicionActX;





	NodoLista* posicionJugador(NodoLista*&);
	void movimientoJugadorArriba(NodoLista*&);
	void movimientoJugadorAbajo(NodoLista*&);
	void movimientoJugadorIzquierda(NodoLista*&);
	void movimientoJugadorDerecha(NodoLista*&);

private:
	NodoLista* inicio;
	NodoLista* nuevo;
	bool listaVacia(NodoLista* & inicio);
	void BorrarLista(NodoLista*&);
	//void movimientoJugador(NodoLista*&, int);

	void verificarNivel(int nivel);
	//vector<int> ListaEnlazada::sacarTamanio(NodoLista*&);
};

#endif // ListaEnlazada_H
