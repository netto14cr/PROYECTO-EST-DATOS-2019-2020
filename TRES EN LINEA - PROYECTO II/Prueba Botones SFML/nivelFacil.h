// Nivelfacil.h
// Autores: Kislev Aleman, Josua Esquivel y Néstor Leiva
// Descripción: Definicion de la clase nivel facil jugador vs la maquina

#pragma once
#ifndef NIVELFACIL_H
#define NIVELFACIL_H
#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using std::string;
using std::cout;
using std::endl;
using std::vector;


#define TAM_FILA 3
#define TAM_COLUMNA 3
#define CAP_BLAN '-'

class nivelFacil {
public:
	nivelFacil() {
		jugador1Gano = false; jugador2Gano = false; realizoJugada = false;
		botton = 0;
		inicializarMatrizJuegoVacia();
	}
	~nivelFacil() { limpiarMatrizJuego(); }

	bool GetRealizoJugada() { return realizoJugada; }
	bool GetJugador1Gana() { return jugador1Gano; }
	bool GetJugador2Gana() { return jugador2Gano; }

	bool verificarPosibleJugadaNF(unsigned int nBoton, unsigned int nJugador, char letraAAgregar);
	void verificaGanadorJugador1();
	void verificaGanadorJugador2();

	vector<char> vectorGuardaMatriz();
	void mostrarValoresEnMatriz(char matrizJuego[TAM_FILA][TAM_COLUMNA]);


	void resetGame();

private:

	char matrizJuego[TAM_FILA][TAM_COLUMNA];
	bool jugador1Gano, jugador2Gano, realizoJugada;
	int botton;
	int validarJugadaMaquina(unsigned int Jugador, char letraAAgregar);
	bool asignarValorEnBotonMatriz(unsigned int nBoton, char letraAAgregar),
		verificarJugadorGanador(),
		verificacionMovimientoDiagonalDerecha(),
		verificacionMovimientoDiagonalIzquierda(),
		verificacionMovimientoHorizontal(),
		verificacionMovimientoVertical();

	void inicializarMatrizJuegoVacia(), limpiarMatrizJuego();

};
#endif // !NIVELFACIL_H