

// gato.h
// Autores: Kislev Aleman, Josua Esquivel y Néstor Leiva
// Descripción: Definicion de la clase gato.h


#ifndef GATO_H
#define GATO_H

#include <SFML/Graphics.hpp> // Inclusion para uso de la libreria graphica SFML 
#include <SFML/Audio.hpp> // Inclusion de la llibreria de sonido SFML.


#include <iostream>
#include <vector>
#include <stack>
using std::vector;
using std::string;
using std::stack;


//#include "ventana.h"


// Definicion de la direcciones de las imagenes


#define DIR_ESPACIOVACIO "../img/white.png"
#define DIR_JUGADORX "../img/letraX.png"
#define DIR_JUGADORO "../img/letraO.png"
#define DIR_SALIR "../img/exit.png"
#define DIR_TITULO "../img/tres.png"
#define DIR_TURNOSELECCION1 "../img/ts1.png"
#define DIR_TURNOSELECCION2 "../img/ts2.png"

#define DIR_TURNOJ1 "../img/juga1.png"
#define DIR_TURNOJ2 "../img/juga2.png"

#define DIR_GANO1 "../img/ganoj1.png"
#define DIR_GANO2 "../img/ganoj2.png"
#define DIR_EMPATE "../img/empate.png"


#define DIR_PAUSA "../sonido/EndofLine.wav"
#define DIR_MUSICA_TECLAS "../sonido/confirm.wav"
#define DIR_MUSICA_FONDO "../sonido/juego.wav"



// Definicion del tamaño de la matriz del juego gato.
#define TAM_FILA 3
#define TAM_COLUMNA 3





class gato {


public:
	// Costructor por defecto
	gato() {
		letraJugador1 = "";
		letraJugador2 = "";
		jugadaRealizada = false;
		contarMoviRealizados = 0;
		ganadorJugador1 = false;
		ganadorJugador2 = false;
		noGanadorFinal = false;


		cargaDeTexturasJuego();
		obtenerTamanioImgBotones();
	}
	~gato() {} // Destrutor de la clase


	void cargaDeTexturasJuego();


	// Delcaracion de los 9 botones en blanco pantalla
	void dibujarBotonesGato(sf::RenderWindow& window);



	void cargarSonidos();
	void detenerSonido();
	void reproducirSonido(int numeroSonido);

	void pintarColorBotonEncima(sf::RenderWindow& window);
	void accionSeleccionarBoton(sf::RenderWindow& window, unsigned int numeroJugador);

	void dibujarImagenEspecifica(sf::RenderWindow& window, int tipoImg);

	int GetBotonPresionado() { return botonSeleccionado; }
	bool GetRealizoJugada() { return jugadaRealizada; }
	bool GetGanadorJ1() { return ganadorJugador1; }
	bool GetGanadorJ2() { return ganadorJugador2; }
	bool GetNoGanadorFinal() { return noGanadorFinal; }

	string GetMatrizModoJuego1() {}
	string matrizJuegoAux;


	bool verificarPosibleJugadaModo1(unsigned int nunerBoton, unsigned int numeroJugador, string letraJugador, sf::RenderWindow& window);

private:

	// Declaracion del uso de funciones de la libreria SFML
	sf::Texture jugadorX;
	sf::Texture jugadorO;
	sf::Texture espacioVacio;
	sf::Texture salir;
	sf::Texture tituloJuego;
	sf::Texture	turnoSeleccion1;
	sf::Texture	turnoSeleccion2;


	sf::Texture jugadorGano1;
	sf::Texture	jugadorGano2;
	sf::Texture	empate;

	sf::Texture jugadorE1;
	sf::Texture jugadorE2;

	sf::Texture actualizaImagenAux;

	sf::Event event;
	sf::Sprite obj;
	vector<string>letrasBotones;
	vector <int>numeroDigitados;
	sf::Texture fondo;
	sf::Sprite fondoImage;


	sf::Vector2i mousePos;



	// Delcaracion de sonidos juego
	sf::SoundBuffer musicaPausa;
	sf::SoundBuffer musicaTeclas;
	sf::SoundBuffer musicaFondo;

	sf::Sound sonido;
	sf::Music musica;




	// Delcaracion de botones del gato

	// Boton 1
	sf::Texture boton1, boton2, boton3, boton4, boton5, boton6, boton7, boton8, boton9;
	sf::Sprite boton1Image, boton2Image, boton3Image, boton4Image, boton5Image, boton6Image,
		boton7Image, boton8Image, boton9Image, imgTitulo;


	float boton1Width, boton2Width, boton3Width, boton4Width, boton5Width, boton6Width,
		boton7Width, boton8Width, boton9Width;
	float boton1Height, boton2Height, boton3Height, boton4Height, boton5Height, boton6Height,
		boton7Height, boton8Height, boton9Height;


	unsigned int botonSeleccionado;
	unsigned int nivelSelecionado;
	bool jugadaRealizada;

	unsigned int contarMoviRealizados;


	string letraJugador1;
	string letraJugador2;
	string matrizJuegoModo1[TAM_FILA][TAM_COLUMNA];

	bool ganadorJugador1;
	bool ganadorJugador2;
	bool noGanadorFinal;

	void obtenerTamanioImgBotones();
	sf::Texture determinarImagenTextura(string letraJuegador);
	void cambioLetrasJugadores(string letraJugador, unsigned int numeroJugador);



	void actualizaImgBoton(unsigned int nBoton, sf::RenderWindow& window, sf::Texture imagenAux);

	void dibujarBotonesMatriz(vector<string> vectorAux, sf::RenderWindow& window);

};

#endif // !GATO_H
