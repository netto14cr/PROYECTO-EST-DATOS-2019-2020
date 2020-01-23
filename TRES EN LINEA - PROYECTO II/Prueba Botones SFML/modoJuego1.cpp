

#include "modoJuego1.h"

bool modoJuego1::verificarPosibleJugada(unsigned int nBoton, unsigned int nJugador, string letraAAgregar) {
	cout << "\nletra a agrgar:: " << letraAAgregar << endl;
	// Asigna un valor de ser posible en la matriz de juego y actualiza el estado de realizo jugada
	// ademas se verifica la posibilidad de que el jugador haya ganado con ese movimiento
	if (asignarValorEnBotonMatriz(nBoton, letraAAgregar)) {
		realizoJugada = true;
		mostrarValoresEnMatriz(matrizJuego);
		cout << "\n Se pudo asignar un nuevo valor a la matriz :: " << realizoJugada << endl;
	}
	else if (!asignarValorEnBotonMatriz(nBoton, letraAAgregar)) {
		cout << "\n No ee pudo asignar un valor en la matriz\n";
		realizoJugada = false;
	}

	return realizoJugada;
}




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
	// Falso si no se puede realizar ningun tipo de movimiento entonces es falso

	realizoJugada = jugadorGano;
	return realizoJugada;
}


bool modoJuego1::verificacionMovimientoDiagonalIzquierda() {
	bool auxGanaDiagonalIz;
	auxGanaDiagonalIz = false;


	// Verifical la diagonal izuquierda de X
	if (this->matrizJuego[0][0] == "jugadorX" && this->matrizJuego[0][4] == "jugadorX" && this->matrizJuego[0][8] == "jugadorX") {
		auxGanaDiagonalIz = true;
	}

	// Verifical la diagonal izuquierda de O
	else if (matrizJuego[0][0] == "jugadorO" && this->matrizJuego[0][4] == "jugadorO" && this->matrizJuego[0][8] == "jugadorO") {
		auxGanaDiagonalIz = true;
	}

	// Falso no hay coincidencias de gane en diagonal izquierda
	else {
		auxGanaDiagonalIz = false;
	}
	return auxGanaDiagonalIz;
}

bool modoJuego1::verificacionMovimientoDiagonalDerecha() {
	bool auxGanaDiagonalDer;
	auxGanaDiagonalDer = false;

	// Verifical la diagonal derecha de X
	if (this->matrizJuego[0][2] == "jugadorX" && this->matrizJuego[0][4] == "jugadorX" && this->matrizJuego[0][6] == "jugadorX") {
		auxGanaDiagonalDer = true;
	}

	// Verifical la diagonal derecha de O
	else if (this->matrizJuego[0][2] == "jugadorO" && this->matrizJuego[0][4] == "jugadorO" && matrizJuego[0][6] == "jugadorO") {
		auxGanaDiagonalDer = true;
	}
	// Falso no hay coincidencias de gane en diagonal derecha
	else {
		auxGanaDiagonalDer = false;
	}
	return auxGanaDiagonalDer;
}




bool modoJuego1::verificacionMovimientoVertical() {
	bool auxGanaVertical;
	auxGanaVertical = false;

	// Verifica la primera columna vertical de X
	if (this->matrizJuego[0][0] == "jugadorX" && this->matrizJuego[0][3] == "jugadorX" && this->matrizJuego[0][6] == "jugadorX") {
		auxGanaVertical = true;
	}
	// Verifica la primera columna vertical de O
	else if (this->matrizJuego[0][0] == "jugadorO" && this->matrizJuego[0][3] == "jugadorO" && this->matrizJuego[0][6] == "jugadorO") {
		auxGanaVertical = true;
	}
	// Verifica la segunda columna vertical de X
	else if (this->matrizJuego[0][1] == "jugadorX" && this->matrizJuego[0][4] == "jugadorX" && this->matrizJuego[0][7] == "jugadorX") {
		auxGanaVertical = true;
	}
	// Verifica la segunda columna vertical de O
	else if (this->matrizJuego[0][1] == "jugadorO" && this->matrizJuego[0][4] == "jugadorO" && this->matrizJuego[0][7] == "jugadorO") {
		auxGanaVertical = true;
	}

	// Verifica la tercera columna vertical de X
	else if (this->matrizJuego[0][2] == "jugadorX" && this->matrizJuego[0][5] == "jugadorX" && this->matrizJuego[0][8] == "jugadorX") {
		auxGanaVertical = true;
	}
	// Verifica la tercera columna vertical de O
	else if (this->matrizJuego[0][2] == "jugadorO" && this->matrizJuego[0][5] == "jugadorO" && this->matrizJuego[0][8] == "jugadorO") {
		auxGanaVertical = true;
	}


	// Falso no existen concidencias de jugada ganadora en vetical
	else {
		auxGanaVertical = false;
	}
	return auxGanaVertical;
}



// Vector guarda matrizJuego para pasar a la clase gato para usarla 
// para imprimir contenido de botones del juego
vector<string> modoJuego1::vectorGuardaMatriz()

{
	vector<string> vectorAux;

	for (unsigned int i = 0; i < TAM_FILA; i++) {
		for (unsigned int k = 0; k < TAM_FILA; k++) {

			vectorAux.push_back(this->matrizJuego[i][k]);
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





bool modoJuego1::verificacionMovimientoHorizontal() {
	bool auxGanaHorizontal;
	auxGanaHorizontal = false;

	// Verifica la primera linea horizontal de X
	if (matrizJuego[0][0] == "jugadorX" && matrizJuego[0][1] == "jugadorX" && matrizJuego[0][2] == "jugadorX") {
		auxGanaHorizontal = true;
	}
	// Verifica la primera linea horizontalde O
	else if (matrizJuego[0][0] == "jugadorO" && matrizJuego[0][1] == "jugadorO" && matrizJuego[0][2] == "jugadorO") {
		auxGanaHorizontal = true;
	}
	// Verifica la segunda linea horizontal de X
	else if (matrizJuego[0][3] == "jugadorX" && this->matrizJuego[0][4] == "jugadorX" && this->matrizJuego[0][5] == "jugadorX") {
		auxGanaHorizontal = true;
	}
	// Verifica la segunda linea horizontal de O
	else if (matrizJuego[0][3] == "jugadorO" && matrizJuego[0][4] == "jugadorO" && matrizJuego[0][5] == "jugadorO") {
		auxGanaHorizontal = true;
	}

	// Verifica la tercera linea horizontal de X
	else if (matrizJuego[0][6] == "jugadorX" && matrizJuego[0][7] == "jugadorX" && matrizJuego[0][8] == "jugadorX") {
		auxGanaHorizontal = true;
	}
	// Verifica la tercera linea horizontal de O
	else if (matrizJuego[0][6] == "jugadorO" && matrizJuego[0][7] == "jugadorO" && matrizJuego[0][8] == "jugadorO") {
		auxGanaHorizontal = true;
	}

	// Falso no existen concidencias de jugada ganadora en horizontal
	else {
		auxGanaHorizontal = false;
	}
	return auxGanaHorizontal;
}


// Verifica que se pueda agrgar un nuevo valor a la matriz de juego
bool modoJuego1::asignarValorEnBotonMatriz(unsigned int nBoton, string letraAAgregar) {


	cout << "BOTON # " << nBoton << endl;
	bool auxAsignaValor = false;
	for (unsigned int i = 0; i < TAM_FILA; i++) {
		for (unsigned int k = 0; k < TAM_COLUMNA; k++) {

			if (matrizJuego[0][nBoton] == "espacioVacio") {
				matrizJuego[0][nBoton] = letraAAgregar;
				auxAsignaValor = true;
			}
		}
	}

	return auxAsignaValor;
}



// Metodo para imprimir la matriz por consola
void modoJuego1::mostrarValoresEnMatriz(string matrizJuego[TAM_FILA][TAM_COLUMNA]) {
	system("cls");
	cout << " \n MOSTRANDO MATRIZ EN CONSOLA MODO JUGADOR VS JUGADOR\n\n";
	for (unsigned int i = 0; i < TAM_FILA; i++) {
		for (unsigned int k = 0; k < TAM_COLUMNA; k++) {
			cout << "[ " << matrizJuego[i][k] << "] ";

		}
		cout << "\n";
	}
}




// Metodo que se encarga de asignar un valor de vacia a toda la matriz de juego
void modoJuego1::inicializarMatrizJuegoVacia() {
	for (unsigned int i = 0; i < TAM_FILA; i++) {
		for (unsigned int k = 0; k < TAM_COLUMNA; k++) {

			matrizJuego[i][k] = "espacioVacio";
		}
	}
}


// Metodo que se encargar de reseter los valores por defecto de la matriz de juego
void modoJuego1::limpiarMatrizJuego() {
	for (unsigned int i = 0; i < TAM_FILA; i++) {
		for (unsigned int k = 0; k < TAM_COLUMNA; k++) {

			matrizJuego[i][k] = " ";
		}
	}
}


