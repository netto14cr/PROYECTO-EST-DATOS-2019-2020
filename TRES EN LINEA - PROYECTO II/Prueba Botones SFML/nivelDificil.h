// nivelDificil.h
// Autores: Kislev Aleman, Josua Esquivel y Néstor Leiva
// Descripción: Definición de metodos utilizados en la clase nivelDificil

#ifndef NIVELDIFICIL_H
#define NIVELDIFICIL_H

#include <iostream>
#include <string>
#include <vector>


// Declaración de uso de libria STD
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::make_pair;
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

//	C L A S E  N I V E L  D I F I C I L
class nivelDificil {


public:// Declaración de metodos publicos

	// Constructor de la clase
	nivelDificil() {
		// Inicialización de varibles
		jugador1Gano, jugador2Gano, realizoJugada = false;
		inicializarMatrizJuegoVacia();
	}

	~nivelDificil() {} // Destructor de la clase

	bool verificarPosibleJugada(unsigned int nBoton, unsigned int nJugador, char letraAAgregar);
	bool GetGanadorJ1() { return jugador1Gano; }
	bool GetGanadorJ2() { return jugador2Gano; }


	vector<char> vectorGuardaMatrizDificil();

private:// Declaración de metodos privados

	// Declaracion de variables
	char matrizJuego[TAM_FILA][TAM_COLUMNA];
	bool jugador1Gano, jugador2Gano, realizoJugada;

	// Declaracion de metodos que retornan un valor
	bool asignarValorEnBotonMatriz(unsigned int nBoton, char letraAAgregar);
	bool verificarPosicionMarcada(pair<unsigned int, unsigned int> posicion,
		char matrizJuego[TAM_FILA][TAM_COLUMNA]);
	vector<pair<unsigned int, unsigned int>> llenarVectorPosiblesJugadas();
	vector<pair<unsigned int, unsigned int>> jugadasGanadores;
	vector<pair<unsigned int, unsigned int>> obtenerLugaresDisponibles(char matrizJuego[TAM_FILA][TAM_COLUMNA]);
	vector<pair<unsigned int, unsigned int>> obtenerLugaresOcupados(char letraAAgregar,
		char matrizJuego[TAM_FILA][TAM_COLUMNA]);

	bool verificarJugadorGanador(vector<pair<unsigned int, unsigned int>>  obtenerLugaresOcupados);

	// Declaracion de metodos que no retornan ningun valor
	void inicializarMatrizJuegoVacia();
	void mostrarValoresEnMatriz(char matrizJuego[TAM_FILA][TAM_COLUMNA]);
	void verificaGanadorJugador1(char letraAAgregar, char matrizJuego[TAM_FILA][TAM_COLUMNA]),
		verificaGanadorJugador2(char letraAAgregar, char matrizJuego[TAM_FILA][TAM_COLUMNA]);

};
#endif NIVELDIFICIL_H