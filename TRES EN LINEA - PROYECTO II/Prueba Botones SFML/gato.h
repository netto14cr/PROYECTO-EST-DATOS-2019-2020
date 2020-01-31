// gato.h
// Autores: Kislev Aleman, Josua Esquivel y Néstor Leiva
// Descripción: Definicion de la clase gato metodos y variables necesarias para la
// implementacion del juego.

#ifndef GATO_H
#define GATO_H

// Declaracion de uso inclusion de la libreria graphica SFML 
#include <SFML/Graphics.hpp> // Inclusion para 
// Declaracion de uso inclusion de la llibreria de sonido SFML.
#include <SFML/Audio.hpp> 
#include <iostream>
#include <vector>
#include <stack>

//  Declaracion del uso tipo variables de la libreria STD
using std::vector;
using std::string;
using std::stack;

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
#define DIR_MAQUINA "../img/maquina.png"

// Definicio de la direccion de los archivos de musica empleados en el juego
#define DIR_PAUSA "../sonido/EndofLine.wav"
#define DIR_MUSICA_TECLAS "../sonido/confirm.wav"
#define DIR_MUSICA_FONDO "../sonido/juego.wav"


#define DIR_CANCION1 "../sonido/im_sorry.wav"
#define DIR_CANCION2 "../sonido/lalala.wav"
#define DIR_CANCION3 "../sonido/slow_down.wav"
#define DIR_CANCION4 "../sonido/if_i_wouldnt_know.wav"







// Defino la cambiada de botones a desmarcar
#define CANT_BOTONES 9

//		C L A S E  G A T O
class gato {

	// Declaracion de metodos y variables  de tipo publico que otras clases 
	// pueden hacer uso para realizar cambios en la clase gato y en el juego.

public:

	// Costructor por defecto
	gato() {
		// Inicializacion de variables de la clase
		letraJugador1 = "";
		letraJugador2 = "";
		jugadaRealizada = false;
		contarMoviRealizados = 0;
		ganadorJugador1 = false;
		ganadorJugador2 = false;
		noGanadorFinal = false;
		cont=1;
		cargaDeTexturasJuego();
		obtenerTamanioImgBotones();
		cargarSonidos();
	}
	~gato() { resetGame(); } // Destrutor de la clase

	// Declaracion de variables que devuelven un valor

	// Declaracion de metodo que realiza la verificacion en modo de juego jugador Vs jugador
	bool verificarPosibleJugadaModo1(unsigned int nunerBoton, unsigned int numeroJugador,
		char letraJugador, sf::RenderWindow& window);
	// Declaracion de metodo que realiza la verificacion en el nivel Facil del juego Vs CPU
	bool verificarPosibleJugadaModoFacil(unsigned int numeroBoton, unsigned int numeroJugador,
		char letraJugador, sf::RenderWindow& window);
	// Declaracion de metodo que realiza la verificacion en el nivel normal del juego Vs CPU
	bool verificarPosibleJugadaModoMedio(unsigned int numeroBoton, unsigned int numeroJugador,
		char letraJugador, sf::RenderWindow& window);
	// Declaracion de metodo que realiza la verificacion en el nivel Dificil del juego Vs CPU
	bool verificarPosibleJugadaModoDificil(unsigned int numeroBoton, unsigned int numeroJugador,
		char letraJugador, sf::RenderWindow& window);

	int GetBotonPresionado() { return botonSeleccionado; }
	bool GetRealizoJugada() { return jugadaRealizada; }
	bool GetGanadorJ1() { return ganadorJugador1; }
	bool GetGanadorJ2() { return ganadorJugador2; }
	bool GetNoGanadorFinal() { return noGanadorFinal; }

	// Declaracion de metodos que no devuelven un valor
	void cargaDeTexturasJuego();
	void cargarSonidos();
	void detenerSonido();
	void reproducirSonido(int numeroSonido);
	void pintarColorBotonEncima(sf::RenderWindow& window);
	void accionSeleccionarBoton(sf::RenderWindow& window, unsigned int numeroJugador);
	void dibujarImagenEspecifica(sf::RenderWindow& window, int tipoImg);
	void actualizaMatrizMod1(sf::RenderWindow& window);
	void actualizaMatrizNivelFacil(sf::RenderWindow& window);
	void actualizaMatrizNivelMedio(sf::RenderWindow& window);
	void actualizaMatrizNivelDificil(sf::RenderWindow& window);

	// Metodo que realiza el cambio de variables modificadas de la clase gato a su estado inicial
	void resetGame();
	// Metodo que cambia las canciones y pone la siguiente
	void siguienteCancion();
	// Metodo que retrocede a la cancion anterior
	void anteriorCancion();

	// Metodo que reproduce musica
	void continuarMusica();

	// Declaracion de metodos y variables de tipo privadas de la clase
private:
	// ---------- Declaracion del uso de funciones de la libreria  S F M L	--------------

	// Declaracion de texturas para la carga de imagenes
	sf::Texture jugadorX, jugadorO, espacioVacio, salir, tituloJuego, turnoSeleccion1,
		turnoSeleccion2, jugadorGano1, jugadorGano2, empate, maquina, jugadorE1, jugadorE2, fondo,
		actualizaImagenAux, boton1, boton2, boton3, boton4, boton5, boton6, boton7,
		boton8, boton9;

	// Declaracion de Sprite's
	sf::Sprite fondoImage, obj, boton1Image, boton2Image, boton3Image, boton4Image,
		boton5Image, boton6Image, boton7Image, boton8Image, boton9Image, imgTitulo;

	// Declaracion de eventos con SFML
	sf::Event event;

	// Declaracion evento mause
	sf::Vector2i mousePos;

	// Declaracion de carga de Buffer de sonidos SFML
	sf::SoundBuffer musicaPausa, musicaTeclas, musicaFondo, cancion1, cancion2, cancion3, 
		cancion4, cancion5, cancion6;

	// Declaracion de sonido
	sf::Sound sonido;
	// Declaracion de musica
	sf::Music musica;

	// Declaracion de vectores
	vector<string>letrasBotones;
	vector <int>numeroDigitados;

	// Declaracion de variables que guardaran las dimesiones de ancho y alto de las imagenes 
	// usadas como simulacion de botones en el juego
	float boton1Width, boton2Width, boton3Width, boton4Width, boton5Width, boton6Width,
		boton7Width, boton8Width, boton9Width, boton1Height, boton2Height, boton3Height,
		boton4Height, boton5Height, boton6Height, boton7Height, boton8Height, boton9Height;

	// Declaracion de variables sin definir int 
	unsigned int botonSeleccionado, nivelSelecionado, contarMoviRealizados, cont;

	// Declaracion de varaibles tipo booleanas 
	bool jugadaRealizada, ganadorJugador1, ganadorJugador2, noGanadorFinal;

	// Delaracion de variables de tipo String
	string letraJugador1, letraJugador2;

	// Declaracion de metodo que obtiene segun la letra del jugador el obejto tipo de textura correcto
	sf::Texture determinarImagenTextura(char letraJuegador);

	// Declaracion de metodo que realiza el cambio de letra de jugadores segun si es jugador 1 u 2
	void cambioLetrasJugadores(char letraJugador, unsigned int numeroJugador);

	// Declaracion de metodo que actualiza la imagen del boton especifico y lo dibuja
	void actualizaImgBoton(unsigned int nBoton, sf::RenderWindow& window, sf::Texture imagenAux);

	// Declaracion de metodo que dibuja los botones de la matriz de juego
	void dibujarBotonesMatriz(vector<char> vectorAux, sf::RenderWindow& window);

	// Declaracion de metodo que des-selecciona el color de los botones diferentes al actual marcado
	// por el cursor del mause
	void desSeleccionaBotonesMatriz(unsigned int nBoton);

	// Declaracion de metodo que obtiene las medidas de las imagnes usadas para simular la matriz
	// de botones en pantalla.
	void obtenerTamanioImgBotones();

	//
	void verificarEstatusGanador(bool verificacionGanadorJugador1, bool verificacionGanadorJugador2,
		unsigned int numeroJugador, unsigned int movimientosRealizados);

	
	void reproduceLaCancionIndicada(unsigned int cont);

};

#endif // !GATO_H
