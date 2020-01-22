
// ventana.h
// Autores: Kislev Aleman, Josua Esquivel y Néstor Leiva
// Definicion de la clase ventana.h

#ifndef VENTANA_H
#define VENTANA_H

// Declacion de clases implementadas
#include <SFML/Graphics.hpp> // Inclusion para uso de la libreria graphica SFML 
#include <SFML/Audio.hpp>
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

	// Contructor de la clase
	ventana() {


		menuEstaActivo = false;
		menuInicioActivo = true;
		menuSeleccionFiguraActivo = false;
		turnoJugador1 = true;
		turnoJugador2 = false;
		estaJugando = false;
		comenzoJuego = false;
		jugador1Eligio=false;
		jugador2Eligio=false;
		juegoEnPausa =true;
		juegoModo1Empezo = false;
		realizoCambioEnJuego = false;
		juegoFinalizo = false;

		nivelJuegoSeleccionado = 0;
		numeroJugador = 0;
		tipoJuego = "";
		letraSeleccionadaJugador1 = "";
		letraSeleccionadaJugador2 = "";

	}
		
	~ventana() {} // Destructor de la clase
	void iniciarPrograma();

private:

	// Declaracion de variables necesarias de la clase
	bool estaJugando;
	bool menuEstaActivo;
	bool comenzoJuego;
	bool juegoEnPausa;


	unsigned int numeroJugador;
	unsigned int nivelJuegoSeleccionado;
	bool menuInicioActivo;
	bool menuSeleccionFiguraActivo;
	bool turnoJugador1;
	bool turnoJugador2;

	bool jugador1Eligio;
	bool jugador2Eligio;
	bool realizoCambioEnJuego;
	bool juegoFinalizo;


	bool juegoModo1Empezo;
	string tipoJuego;
	string letraSeleccionadaJugador1;
	string letraSeleccionadaJugador2;

	void manejoEventosTeclado(sf::RenderWindow& window);
	void determinarTipoEvento(sf::RenderWindow& window);
	void opcionesMenuJuego(sf::RenderWindow& window);
	void opcionesBotonesJuegoModo1(sf::RenderWindow& window);
	//void opcionesBotonesJuegoModo2(sf::RenderWindow& window);
	void actualizaEstadoImgJugador();

};




#endif // !VENTANA_H


