
// modoJuego1.h
// Autores: Kislev Aleman, Josua Esquivel y Néstor Leiva
// Descripción: Definicion de la clase modo juego 1 para jugador vs jugador


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

		jugador1Gano = false;
		jugador2Gano = false;
		realizoJugada = false;
		inicializarMatrizJuegoVacia();
	}


	~modoJuego1() { limpiarMatrizJuego(); }



	bool verificarPosibleJugada(unsigned int nBoton, unsigned int nJugador, char letraAAgregar);
	bool verificaGanadorJugador1();
	bool verificaGanadorJugador2();


	//void SetRealizoJugada( bool realizoJugad) { realizoJugada = realizoJugad; }
	bool GetRealizoJugada() { return realizoJugada; }
	bool GetJugador1Gana() { return jugador1Gano; }
	bool GetJugador2Gana() { return jugador2Gano; }

	void mostrarValoresEnMatriz(char matrizJuego[TAM_FILA][TAM_COLUMNA]);

	vector<char> vectorGuardaMatriz();


private:

	char matrizJuego[TAM_FILA][TAM_COLUMNA];

	void inicializarMatrizJuegoVacia();
	void limpiarMatrizJuego();


	bool asignarValorEnBotonMatriz(unsigned int nBoton, char letraAAgregar);
	bool verificarJugadorGanador();
	bool verificacionMovimientoDiagonalDerecha();
	bool verificacionMovimientoDiagonalIzquierda();
	bool verificacionMovimientoHorizontal();
	bool verificacionMovimientoVertical();

	bool jugador1Gano;
	bool jugador2Gano;
	bool realizoJugada;

	void resetGame();


};



#endif // !MODOJUEGO1_H

