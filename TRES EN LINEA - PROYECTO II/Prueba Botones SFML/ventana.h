
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

#include "gato.h"
#include "menu.h"


// Declaracion de funciones de la libreria STD empleadas en la clase
using std::stringstream;
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::string;



#define LETRA_JUGADOR_X 'X'
#define LETRA_JUGADOR_O 'O'


class ventana {

public:

	// Contructor de la clase
	ventana() {


		menuEstaActivo = false;
		menuInicioActivo = true;
		subMenuNivelActivo = false;
		menuSeleccionFiguraActivo = false;
		juegaMaquina = false;
		turnoJugador1 = true;
		turnoJugador2 = false;
		estaJugando = false;
		comenzoJuego = false;
		jugador1Eligio = false;
		jugador2Eligio = false;
		juegoEnPausa = true;
		juegoFinalizo = false;

		nivelJuegoSeleccionado = 0;
		numeroJugador = 0;
		tipoJuego = "";
		dificultad = "";
		letraSeleccionadaJugador1 = ' ';
		letraSeleccionadaJugador2 = ' ';

	}

	~ventana() {} // Destructor de la clase
	void iniciarPrograma();


private:

	// Declaracion de variables necesarias de la clase
	bool estaJugando;
	bool menuEstaActivo;
	bool subMenuNivelActivo;
	bool comenzoJuego;
	bool juegoEnPausa;


	unsigned int numeroJugador;
	unsigned int nivelJuegoSeleccionado;
	bool menuInicioActivo;
	bool menuSeleccionFiguraActivo;
	bool juegaMaquina;
	bool turnoJugador1;
	bool turnoJugador2;

	bool jugador1Eligio;
	bool jugador2Eligio;
	bool juegoFinalizo;


	string tipoJuego;
	string dificultad;
	char letraSeleccionadaJugador1, letraSeleccionadaJugador2;

	void manejoEventosJuego(sf::RenderWindow& window);
	void determinarTipoEvento(sf::RenderWindow& window);
	void opcionesMenuJuego(sf::RenderWindow& window);
	void opcionesBotonesJuegoModo1(sf::RenderWindow& window);
	void opcionesBotonesModoJuegoMaquina(sf::RenderWindow& window);

	void actualizaEstadoImgJugador();
	void verificacionJugadorLetra();
	void verificaEstatusDelJuego(sf::RenderWindow& window);

};




#endif // !VENTANA_H


