
// sokoban.h
// Autores: Kislev Aleman, Josua Esquivel y Néstor Leiva
// Definicion de la clase ventana.h

#ifndef VENTANA_H
#define VENTANA_H

// Declacion de clases implementadas
#include <SFML/Graphics.hpp> // Inclusion para uso de la libreria graphica SFML 
#include <SFML/Audio.hpp>
#include"ListaEnlazada.h"
#include"Archivo.h"
#include "menu.h"
#include "sokoban.h"
#include <iostream>
#include<string>
#include<iostream>
#include <sstream>


// Declaracion de funciones de la libreria STD empleadas en la clase
using std::stringstream;
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::string;




class ventana {

public:
	ventana(); // Contructor de la clase
	~ventana(); // Destructor de la clase


	
	// Metodo que maneja el juego en la parte inicial del programa.
	void playGame();


private:

	// Declaracion de variables necesarias de la clase
	bool estaJugando = false;
	bool menuEstaActivo = true;
	bool realizoUnMovimiento = false;
	int	tamAncho = 0;
	int	tamAlto = 0;
	bool comenzoJuego = false;
	NodoLista* tmp = nullptr;
	sf::Time tiempo = sf::seconds(0.5f);
	void manejoEventosTeclado(sf::RenderWindow& window);
	void inicializarJuego(int nivel);
	void movimientoPersonaje(int dir);
	void teclado(sf::RenderWindow& window, NodoLista*& tx);
	int nivelSeleccionado=1;
	void determinarMedidasPantalla(sf::RenderWindow& window);
	


};




#endif // !VENTANA_H
