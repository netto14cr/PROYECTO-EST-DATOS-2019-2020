// nivelDificil.h
// Autores: Kislev Aleman, Josua Esquivel y Néstor Leiva
// Descripción: Definición de metodos utilizados en la clase nivelDificil

#ifndef NIVELDIFICIL_H
#define NIVELDIFICIL_H

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


// Declaración de uso de libria STD
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::make_pair;
using std::max;
using std::min;
using std::begin;
using std::find;
using std::end;


// Definición del tamano de las fila y la columna para usar para la matriz
#define TAM_FILA 3
#define TAM_COLUMNA 3

// Definición de caracteres ingresados en la matriz de juego
#define LETRA_JUGADOR_X 'X'
#define LETRA_JUGADOR_O 'O'
#define CAMPO_EN_BLANCO '-'

#define GANADOR 1000
#define	VALOR_TEMPORAL 0
#define PERDEDOR -1000

#define ESTADO_INICIAL 0

//	C L A S E  N I V E L  D I F I C I L
class nivelDificil {


public:// Declaración de metodos publicos

	// Constructor de la clase
	nivelDificil() {
		// Inicialización de varibles
		jugador1Gano, jugador2Gano, realizoJugada = false;
		letraJugador1, letraMaquina = ' ';
		// Cuando arranca la clase se asigna automaticamente los valores iniciales a la matriz de juego
		inicializarMatrizJuegoVacia();
	}

	// Destructor de la clase
	~nivelDificil() {}


	// Declaración de metodo que retorna u verdadero o falso si el jugador 1 o jugador 2 (maquina) 
	// realizaron su movimento y controla otros metodos necesarios que son de tipo provado para
	// la validacion necesaria de la logica que implica ejecutar las acciones del nivel dificil.
	bool verificarPosibleJugada(unsigned int nBoton, unsigned int nJugador, char letraAAgregar);

	// Declaraión de retorno de las variables privadas de jugador1Gano y jugadorGano 2 para dar las
	// a conocer a la clase gato para que determine si realiza un cambio de estatus en la parte visual
	bool GetGanadorJ1() { return jugador1Gano; }
	bool GetGanadorJ2() { return jugador2Gano; }

	// Declaración de retorno de variable que devuelve un vector con la información real de los 
	// movimientos y jugadas realizadas en la matriz de juego de nivel dificil.
	vector<char> vectorGuardaMatrizDificil();

	bool verificaGanadorJugador11(),
		verificaGanadorJugador22();

private:// Declaración de metodos privados

	// Declaracion de variables
	char matrizJuego[TAM_FILA][TAM_COLUMNA];
	bool jugador1Gano, jugador2Gano, realizoJugada;

	// Declaracion de metodos que retornan un valor
	bool asignarValorEnBotonMatriz(unsigned int nBoton, char letraAAgregar, int numeroJugador);
	bool verificarPosicionMarcada(pair<int, int> posicion,
		char matrizJuego[TAM_FILA][TAM_COLUMNA]);

	vector<pair<int, int>> jugadasGanadores;
	vector<pair<int, int>> obtenerLugaresDisponibles(char matrizJuego[TAM_FILA][TAM_COLUMNA]);
	vector<pair<int, int>> obtenerLugaresOcupados(char letraAAgregar,
		char matrizJuego[TAM_FILA][TAM_COLUMNA]);

	pair<int, pair<int, int>> algoritmoMinimazaJuego(
		char matrizJuego[TAM_FILA][TAM_COLUMNA], char letraAAgregar,
		int auxEstadoInicial, int auxPerdedor, int auxGanador);

	bool verificarJugadorGanador(vector<pair<int, int>>  obtenerLugaresOcupados);
	bool matrizJuegoLlena(char matrizJuego[TAM_FILA][TAM_COLUMNA]);
	int obtenerEstadoMatrizJuego(char matrizJuego[TAM_FILA][TAM_COLUMNA], char letraAAgregar);

	char letraJugador1, letraMaquina;

	vector<vector<pair<int, int>>> declaraPosiblesJugadas;
	// Declaracion de metodos que no retornan ningun valor
	void inicializarMatrizJuegoVacia();
	void mostrarValoresEnMatriz(char matrizJuego[TAM_FILA][TAM_COLUMNA]);
	void verificaGanadorJugador1(char letraAAgregar, char matrizJuego[TAM_FILA][TAM_COLUMNA]),
		verificaGanadorJugador2(char letraAAgregar, char matrizJuego[TAM_FILA][TAM_COLUMNA]);

	bool verificarJugadorGanador1(),
		verificacionMovimientoDiagonalDerecha(),
		verificacionMovimientoDiagonalIzquierda(),
		verificacionMovimientoHorizontal(),
		verificacionMovimientoVertical();
	void determinaLetraJugadores(char letraJugador, unsigned int numeroJugador);

};
#endif NIVELDIFICIL_H