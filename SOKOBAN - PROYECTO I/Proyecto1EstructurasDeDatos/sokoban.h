

// sokoban.h
// Autores: Kislev Aleman, Josua Esquivel y Néstor Leiva
// Definicion de la clase sokoban.h


#ifndef SOKOBAN_H
#define SOKOBAN_H

#include <SFML/Graphics.hpp> // Inclusion para uso de la libreria graphica SFML 
#include <SFML/Audio.hpp> // Inclusion de la llibreria de sonido SFML.

#include "ventana.h"


// Definicion de la direcciones de las imagenes

#define DIR_PARED "../img/wall.png"
#define DIR_CAMINO "../img/white.png"
#define DIR_JUGADOR "../img/player.gif"
#define DIR_CAJA "../img/box.png" 
#define DIR_DOT "../img/dot.png"
#define DIR_OBJETIVO "../img/ground.gif"
#define DIR_PAUSA "../sonido/EndofLine.wav"
#define DIR_MUSICA_TECLAS "../sonido/confirm.wav"
#define DIR_MUSICA_FONDO "../sonido/juego.wav"

class sokoban {


public:

	sokoban(); // Costructor por defecto
	~sokoban(); // Destrutor de la clase


	void dibCambioMovSokoban(sf::RenderWindow& window, NodoLista*& inicio);
	void dibujarMapa(sf::RenderWindow& window);
	void actualizarDatosMatriz(NodoLista*& inicio);
	void cargaDeTexturasJuego();
	void cargarSonidos();
	void reproducirSonido(int numeroSonido);
	void detenerSonido();

private:

	// Declaracion del uso de funciones de la libreria SFML
	sf::Texture pared;
	sf::Texture camino;
	sf::Texture caja;
	sf::Texture lugarCaja;
	sf::Texture personaje;
	sf::Texture target;
	sf::Event event;
	sf::Sprite obj;
	
	sf::SoundBuffer musicaPausa;
	sf::SoundBuffer musicaTeclas;
	sf::SoundBuffer musicaFondo;

	sf::Sound sonido;
	sf::Music musica;
	vector<char>areaJuego;
	void eliminarContenidoVector();
	string matriz;
	string paredDir;
	string cajaDir;
	string objetivoDir;
	string lugarDir;
	string jugadorDir;
	string caminoDir;
	char caracter;
	unsigned int posicionActX;
	unsigned int posicionActY;
	ListaEnlazada lE;
	


};

#endif // !SOKOBAN_H

