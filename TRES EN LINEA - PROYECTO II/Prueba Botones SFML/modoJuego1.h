
// modoJuego1.h
// Autores: Kislev Aleman, Josua Esquivel y N�stor Leiva
// Descripci�n: Definicion de la clase modo juego 1 para jugador vs jugador


#ifndef MODOJUEGO1_H
#define MODOJUEGO1_H


#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::cout;
using std::endl;
using std::vector;


#define TAM_FILA 3
#define TAM_COLUMNA 3


class modoJuego1 {


public:

	modoJuego1() {
		jugador1Gano = false; jugador2Gano = false; realizoJugada = false;
		inicializarMatrizJuegoVacia();
	}
	~modoJuego1() { limpiarMatrizJuego(); }

	bool GetRealizoJugada() { return realizoJugada; }
	bool GetJugador1Gana() { return jugador1Gano; }
	bool GetJugador2Gana() { return jugador2Gano; }

	bool verificarPosibleJugada(unsigned int nBoton, unsigned int nJugador, char letraAAgregar),
		verificaGanadorJugador1(), verificaGanadorJugador2();

	vector<char> vectorGuardaMatriz();
	void mostrarValoresEnMatriz(char matrizJuego[TAM_FILA][TAM_COLUMNA]);

private:

	char matrizJuego[TAM_FILA][TAM_COLUMNA];
	bool jugador1Gano, jugador2Gano, realizoJugada;
	bool asignarValorEnBotonMatriz(unsigned int nBoton, char letraAAgregar),
		verificarJugadorGanador(),
		verificacionMovimientoDiagonalDerecha(),
		verificacionMovimientoDiagonalIzquierda(),
		verificacionMovimientoHorizontal(),
		verificacionMovimientoVertical();

	void inicializarMatrizJuegoVacia(), limpiarMatrizJuego(), resetGame();
};
#endif // !MODOJUEGO1_H

