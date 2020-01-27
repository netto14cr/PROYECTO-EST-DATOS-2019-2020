// modoJuego1.cpp
// Autores: Kislev Aleman, Josua Esquivel y Néstor Leiva
// Descripcion: Implementacion de la clase modoJeugo1 y sus metodos necesarios para la 
// realizacion de la validacion del nivel jugador vs jugador, realizacion de jugadas y
// la validacion de jugadas correctas y el deterninar asi en el transcurso del juego
// si hay una ganador o el juego termina en empate.

#include "modoJuego1.h"

bool modoJuego1::verificarPosibleJugada(unsigned int nBoton, unsigned int nJugador, char letraAAgregar) {
	cout << "\nletra a agrgar:: " << letraAAgregar << endl;
	// Asigna un valor de ser posible en la matriz de juego y actualiza el estado de realizo jugada
	// ademas se verifica la posibilidad de que el jugador haya ganado con ese movimiento
	if (asignarValorEnBotonMatriz(nBoton, letraAAgregar)) {
		// Se realiza el cambio del estado de realizo movimiento en la jugada a verdadero
		realizoJugada = true;
		// llamado al metodo que muestra los valores de la matriz por consola
		mostrarValoresEnMatriz(matrizJuego);
	}
	// Falso si no se puede asignar un valor a la matriz se actualiza su estado a falso
	else if (!asignarValorEnBotonMatriz(nBoton, letraAAgregar)) {
		// Se realiza el cambio del estado de realizo movimiento en la jugada a falso
		realizoJugada = false;
	}

	return realizoJugada;
}

// Metodo para imprimir la matriz mostrada por consola
void modoJuego1::mostrarValoresEnMatriz(char matrizJuego[TAM_FILA][TAM_COLUMNA]) {
	system("cls");
	cout << " \n :::::::::::::::::		MATRIZ MODO JUGADOR VS JUGADOR		::::::::::::::::\n\n";
	for (unsigned int i = 0; i < TAM_FILA; i++) {
		for (unsigned int k = 0; k < TAM_COLUMNA; k++) {
			cout << "[	" << matrizJuego[i][k] << "	]	";

		}
		cout << "\n";
	}
}

// Metodo booleano que devuele la verificasion de verdadero o falso si el juegador 1
// ha realizado movimientos para declararlo ganador del juego o no.
bool modoJuego1::verificaGanadorJugador1() {
	// Siempre y cuando los movimientos correctos por el jugador 1 podra ganar
	if (verificarJugadorGanador()) {
		jugador1Gano = true;
	}
	else {
		jugador1Gano = false;
	}

	return jugador1Gano;
}

// Metodo booleano que devuele la verificasion de verdadero o falso si el juegador 2
// ha realizado movimientos para declararlo ganador del juego o no.
bool modoJuego1::verificaGanadorJugador2() {
	// Siempre y cuando los movimientos correctos por el jugador  2 podra ganar
	if (verificarJugadorGanador()) {
		jugador2Gano = true;
	}
	else {
		jugador2Gano = false;
	}
	return jugador2Gano;
}

// Metodo que verifica si la seleccion de boton del jugador se puede escoger y 
// cambia el estado de la variable realizoJugada a verdadero. 
bool modoJuego1::verificarJugadorGanador() {
	bool jugadorGano;
	jugadorGano = false;

	// Si se puede realizar un movimiento en la diagonal izquierda
	if (verificacionMovimientoDiagonalIzquierda()) {
		jugadorGano = true;
	}

	// Falso Si se puede realizar un movimiento en la diagonal Derecha
	else if (verificacionMovimientoDiagonalDerecha()) {
		jugadorGano = true;
	}
	// Falso si se puede realizar un movimiento horizontal
	else if (verificacionMovimientoHorizontal()) {
		jugadorGano = true;
	}
	// Falso si se puede realizar un movimiento en vertical
	else if (verificacionMovimientoVertical()) {
		jugadorGano = true;
	}
	realizoJugada = jugadorGano;
	return realizoJugada;
}

// Metodo tipo booleano que devuele verdaro o falso dependiendo si encuentra o no
// una jugada ganadora realizada por los juegadores en la diagonal izquierda.
bool modoJuego1::verificacionMovimientoDiagonalIzquierda() {
	bool auxGanaDiagonalIz;
	auxGanaDiagonalIz = false;


	// Verifical la diagonal izuquierda de X
	if (matrizJuego[0][0] == 'X' && matrizJuego[0][4] == 'X' && matrizJuego[0][8] == 'X') {
		auxGanaDiagonalIz = true;
	}
	// Verifical la diagonal izuquierda de O
	else if (matrizJuego[0][0] == 'O' && matrizJuego[0][4] == 'O' && matrizJuego[0][8] == 'O') {
		auxGanaDiagonalIz = true;
	}
	// Falso no hay coincidencias de gane en diagonal izquierda
	else {
		auxGanaDiagonalIz = false;
	}
	return auxGanaDiagonalIz;
}

// Metodo tipo booleano que devuele verdaro o falso dependiendo si encuentra o no
// una jugada ganadora realizada por los juegadores en la diagonal derecha.
bool modoJuego1::verificacionMovimientoDiagonalDerecha() {
	bool auxGanaDiagonalDer;
	auxGanaDiagonalDer = false;

	// Verifical la diagonal derecha de X
	if (matrizJuego[0][2] == 'X' && matrizJuego[0][4] == 'X' && matrizJuego[0][6] == 'X') {
		auxGanaDiagonalDer = true;
	}

	// Verifical la diagonal derecha de O
	else if (matrizJuego[0][2] == 'O' && matrizJuego[0][4] == 'O' && matrizJuego[0][6] == 'O') {
		auxGanaDiagonalDer = true;
	}
	// Falso no hay coincidencias de gane en diagonal derecha
	else {
		auxGanaDiagonalDer = false;
	}
	return auxGanaDiagonalDer;
}

// Metodo tipo booleano que devuele verdaro o falso dependiendo si encuentra o no
// una jugada ganadora realizada por los juegadores en las posicion vectical.
bool modoJuego1::verificacionMovimientoVertical() {
	bool auxGanaVertical;
	auxGanaVertical = false;

	// Verifica la primera columna vertical de X
	if (matrizJuego[0][0] == 'X' && matrizJuego[0][3] == 'X' && matrizJuego[0][6] == 'X') {
		auxGanaVertical = true;
	}
	// Verifica la primera columna vertical de O
	else if (matrizJuego[0][0] == 'O' && matrizJuego[0][3] == 'O' && matrizJuego[0][6] == 'O') {
		auxGanaVertical = true;
	}
	// Verifica la segunda columna vertical de X
	else if (matrizJuego[0][1] == 'X' && matrizJuego[0][4] == 'X' && matrizJuego[0][7] == 'X') {
		auxGanaVertical = true;
	}
	// Verifica la segunda columna vertical de O
	else if (matrizJuego[0][1] == 'O' && matrizJuego[0][4] == 'O' && matrizJuego[0][7] == 'O') {
		auxGanaVertical = true;
	}

	// Verifica la tercera columna vertical de X
	else if (matrizJuego[0][2] == 'X' && matrizJuego[0][5] == 'X' && matrizJuego[0][8] == 'X') {
		auxGanaVertical = true;
	}
	// Verifica la tercera columna vertical de O
	else if (matrizJuego[0][2] == 'O' && matrizJuego[0][5] == 'O' && matrizJuego[0][8] == 'O') {
		auxGanaVertical = true;
	}
	// Falso no existen concidencias de jugada ganadora en vetical
	else {
		auxGanaVertical = false;
	}
	return auxGanaVertical;
}

// Metodo tipo booleano que devuele verdaro o falso dependiendo si encuentra o no
// una jugada ganadora realizada por los juegadores en las posicion horizontal.
bool modoJuego1::verificacionMovimientoHorizontal() {
	bool auxGanaHorizontal;
	auxGanaHorizontal = false;

	// Verifica la primera linea horizontal de X
	if (matrizJuego[0][0] == 'X' && matrizJuego[0][1] == 'X' && matrizJuego[0][2] == 'X') {
		auxGanaHorizontal = true;
	}
	// Verifica la primera linea horizontalde O
	else if (matrizJuego[0][0] == 'O' && matrizJuego[0][1] == 'O' && matrizJuego[0][2] == 'O') {
		auxGanaHorizontal = true;
	}
	// Verifica la segunda linea horizontal de X
	else if (matrizJuego[0][3] == 'X' && matrizJuego[0][4] == 'X' && matrizJuego[0][5] == 'X') {
		auxGanaHorizontal = true;
	}
	// Verifica la segunda linea horizontal de O
	else if (matrizJuego[0][3] == 'O' && matrizJuego[0][4] == 'O' && matrizJuego[0][5] == 'O') {
		auxGanaHorizontal = true;
	}

	// Verifica la tercera linea horizontal de X
	else if (matrizJuego[0][6] == 'X' && matrizJuego[0][7] == 'X' && matrizJuego[0][8] == 'X') {
		auxGanaHorizontal = true;
	}
	// Verifica la tercera linea horizontal de O
	else if (matrizJuego[0][6] == 'O' && matrizJuego[0][7] == 'O' && matrizJuego[0][8] == 'O') {
		auxGanaHorizontal = true;
	}

	// Falso no existen concidencias de jugada ganadora en horizontal
	else {
		auxGanaHorizontal = false;
	}
	return auxGanaHorizontal;
}

// Vector guarda matrizJuego para pasar a la clase gato para usarla 
// para imprimir contenido de botones del juego
vector<char> modoJuego1::vectorGuardaMatriz()
{
	vector<char> vectorAux;
	for (unsigned int i = 0; i < TAM_FILA; i++) {
		for (unsigned int k = 0; k < TAM_FILA; k++) {

			vectorAux.push_back(matrizJuego[i][k]);
		}
	}
	return vectorAux;
}

// Metodo que vuelve a colocar los valores de las variables modificados 
// a su valor original para comenzar un nuevo juego.
void modoJuego1::resetGame()
{
	jugador1Gano = false;
	jugador2Gano = false;
	realizoJugada = false;
	inicializarMatrizJuegoVacia();
}

// Verifica que se pueda agrgar un nuevo valor a la matriz de juego
bool modoJuego1::asignarValorEnBotonMatriz(unsigned int nBoton, char letraAAgregar) {
	cout << "BOTON # " << nBoton << endl;
	bool auxAsignaValor = false;
	for (unsigned int i = 0; i < TAM_FILA; i++) {
		for (unsigned int k = 0; k < TAM_COLUMNA; k++) {

			if (matrizJuego[0][nBoton] == '-') {
				matrizJuego[0][nBoton] = letraAAgregar;
				auxAsignaValor = true;
			}
		}
	}

	return auxAsignaValor;
}

// Metodo que se encarga de asignar un valor de vacia a toda la matriz de juego
void modoJuego1::inicializarMatrizJuegoVacia() {
	for (unsigned int i = 0; i < TAM_FILA; i++) {
		for (unsigned int k = 0; k < TAM_COLUMNA; k++) {
			matrizJuego[i][k] = '-';
		}
	}
}

// Metodo que se encargar de reseter los valores por defecto de la matriz de juego
void modoJuego1::limpiarMatrizJuego() {
	for (unsigned int i = 0; i < TAM_FILA; i++) {
		for (unsigned int k = 0; k < TAM_COLUMNA; k++) {

			matrizJuego[i][k] = ' ';
		}
	}
}


