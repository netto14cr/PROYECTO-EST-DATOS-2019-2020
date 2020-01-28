// nivelDificicil.cpp
// Autores: Kislev Aleman, Josua Esquivel y Néstor Leiva
// Descripcion: Implementación de la clase nivelDificil y sus metodos necesarios para la 
// realización de la validación del nivel jugador vs CPU - Dificultad:: Dificil, y
// implementa metodos para validar y ejecutar movimientos inteligentes de la máquina, 
// según el jugador va realizando jugadas para intentar que el jugador pierda, empate y si 
// es posible que máquina gana la partida del juego. 

#include "nivelDificil.h"

// Metodo que determina si el juegador puede realizar una jugada y retorna un valor de 
// verdadero o falso ademas de asignar el movimiento solicitado por el usuario, llama al 
// metodo que muestra la matriz de juego por consola.
bool nivelDificil::verificarPosibleJugada(unsigned int nBoton, unsigned int numeroJugador,
	char letraAAgregar)
{
	// Si es el turno del jugador 1 y la posicion elegida para marcar en la matriz esta vacia
	// realiza la colocacion de la letra en la posicion indicada y actauluza el estado de jugada
	// realizada verdadero.
	if (asignarValorEnBotonMatriz(nBoton, letraAAgregar, numeroJugador) && numeroJugador == 1) {

		determinaLetraJugadores(letraAAgregar, numeroJugador);
		// Se hace el llamado del metodo que verifica si el juegador 1 con el movimiento 
		// realizada puede ganar y actualiza el estado de ganador de jugador 1, de ser verdad.
		//verificaGanadorJugador1(letraAAgregar, matrizJuego);

		// Llamado al metodo que muestra los valores de la matriz por consola
		mostrarValoresEnMatriz(matrizJuego);
		// Llama al metodo que calcula el estado de juego del jugador 1
		obtenerEstadoMatrizJuego(matrizJuego, letraJugador1);
		// Se realiza el cambio del estado de realizo movimiento en la jugada a verdadero
		realizoJugada = true;
	}
	// Falso Si es el turno del jugador 1 realiza la comprobacion asignada de jugada de la maquina
	else if (numeroJugador == 2) {
		// Aqui se debe llamar al metodo para que juegue y valide la maquina
		pair<int, pair<int, int>> movimientoMaquina = algoritmoMinimazaJuego(matrizJuego, LETRA_JUGADOR_O, ESTADO_INICIAL, PERDEDOR, GANADOR);
		matrizJuego[movimientoMaquina.second.first][movimientoMaquina.second.second] = letraAAgregar;
		//verificaGanadorJugador2(letraAAgregar, matrizJuego);
		// Llamado al metodo que muestra los valores de la matriz por consola
		mostrarValoresEnMatriz(matrizJuego);
		// Se realiza el cambio del estado de realizo movimiento en la jugada a verdadero
		realizoJugada = true;
	}

	// Falso si no se puede asignar un valor actualiza el estado de jugada realizada a falso
	else { realizoJugada = false; }
	return realizoJugada;
}

// Metodo en el cual se definen las jugadas donde los juegaodres o la maquina pueden ganar en el juego, 
// los posibles movimientos validados son todas la psociones existente de fila, columna y diagonal 
// izquierda y digalonal derecha.

vector<vector<pair<int, int>>> declaraPosiblesJugadas{

	// Validacion de jugada de gane de fila 0
	{ make_pair(0, 0), make_pair(0, 1), make_pair(0, 2) },
	// Validacion de jugada de gane de fila 1
	{ make_pair(1, 0), make_pair(1, 1), make_pair(1, 2) },
	// Validacion de jugada de gane de fila 2
	{ make_pair(2, 0), make_pair(2, 1), make_pair(2, 2) },
	// Validacion de jugada de gane de columana 0
	{ make_pair(0, 0), make_pair(1, 0), make_pair(2, 0) },
	// Validacion de jugada de gane de columana 1
	{ make_pair(0, 1), make_pair(1, 1), make_pair(2, 1) },
	// Validacion de jugada de gane de columana 2
	{ make_pair(0, 2), make_pair(1, 2), make_pair(2, 2) },
	// Validacion de jugada de gane de diagonal izquierda
	{ make_pair(0, 0), make_pair(1, 1), make_pair(2, 2) },
	// Validacion de jugada de gane de diagonal derecha
	{ make_pair(2, 0), make_pair(1, 1), make_pair(0, 2) }
};

// Vector guarda matrizJuego nivel Dificil para pasar a la clase gato para usarla 
// para imprimir contenido de botones del juego
vector<char> nivelDificil::vectorGuardaMatrizDificil()
{
	vector<char> vectorAux;
	for (int i = 0; i < TAM_FILA; i++) {
		for (int k = 0; k < TAM_COLUMNA; k++) {

			vectorAux.push_back(matrizJuego[i][k]);
		}
	}
	return vectorAux;
}

// Verifica que se pueda agrgar un nuevo valor a la matriz de juego
bool nivelDificil::asignarValorEnBotonMatriz(unsigned int nBoton, char letraAAgregar, int numeroJugador) {

	bool auxAsignaValor = false;
	for (int i = 0; i < TAM_FILA; i++) {
		for (int k = 0; k < TAM_COLUMNA; k++) {

			if (matrizJuego[0][nBoton] == CAMPO_EN_BLANCO) {
				matrizJuego[0][nBoton] = letraAAgregar;

				//pair<int, pair<int, int>> movimientoAuxMaquina = algoritmoMinimazaJuego(matrizJuego, numeroJugador,
					//letraAAgregar, ESTADO_INICIAL, PERDEDOR, GANADOR);
				auxAsignaValor = true;
			}
		}
	}
	return auxAsignaValor;
}

// Metodo de tipo booleano que retorna un verdadero o falso si en la verificación de la
// matriz y la posiscion a consultar encuentra un valor, si esto ocurre el valor sera
// verdadero pero sino hay nada devolvera un falso.
bool nivelDificil::verificarPosicionMarcada(pair<int, int> posicion,
	char matrizJuego[TAM_FILA][TAM_COLUMNA])
{
	// Se delacara una variable auxiliar booleana que se le asignara una valor de verdadero 
	// si en la verificacion de campo de la matriz se obtiene como resultado que esta ocpuado
	bool auxVerificaCampoOcupado;
	auxVerificaCampoOcupado = true;
	// Se declara a un vector auxiliar y se le pasan los valores del metodo lugaresDisponibles 
	// de la matriz de juego.
	vector<pair<int, int>> auxVectorCamposDisponibles = obtenerLugaresDisponibles(matrizJuego);

	// Ciclo for que recorre los valores que asignamos al vector auxiliar y verifica que 
	// en la direccion i, que valor tiene agregado.
	for (int i = 0; i < auxVectorCamposDisponibles.size(); i++)
	{
		// Si en la direccion de memoria i , el valor NO esta ocupado entonces se actualiza el 
		// valor de la variable auxiliar a falso.
		if (posicion.first == auxVectorCamposDisponibles[i].first &&
			posicion.second == auxVectorCamposDisponibles[i].second)
		{

			return auxVerificaCampoOcupado = false;

		}
	}
	return auxVerificaCampoOcupado;
}

int nivelDificil::obtenerEstadoMatrizJuego(char matrizJuego[TAM_FILA][TAM_COLUMNA], char letraAAgregar)
{
	// Se daclara un vector para recibir los campos ocupados por el jugador en espefico en la 
	// matriz de juego para comparar si exite un ganador o se perdio.
	vector<pair<int, int>>
		camposOcupadosAux = obtenerLugaresOcupados(letraAAgregar, matrizJuego);

	bool ganadorAux = verificarJugadorGanador(camposOcupadosAux);

	// Si el juegador verifica los campos ocupados y existe un ganador 
	if (ganadorAux) { return GANADOR; }

	// se pasan las posiciones ocupadas por de ljuegador en la matri de juego a la 
	// variable campos ocupados auxiliar
	camposOcupadosAux = obtenerLugaresOcupados(letraAAgregar, matrizJuego);
	bool perdedorAux = verificarJugadorGanador(camposOcupadosAux);

	// Se verifica si existe un estado de perdida y de ser verdad se retorna
	// el valor que se perdio.
	if (perdedorAux) { return PERDEDOR; }

	bool matrizJuegoLLena = matrizJuegoLlena(matrizJuego);
	if (matrizJuegoLLena)
	{
		return VALOR_TEMPORAL;
	}

	return VALOR_TEMPORAL;

}

// Metodo que se encarga de asignar un valor de vacia a toda la matriz de juego
void nivelDificil::inicializarMatrizJuegoVacia() {
	for (unsigned int i = 0; i < TAM_FILA; i++) {
		for (unsigned int k = 0; k < TAM_COLUMNA; k++) {
			matrizJuego[i][k] = '-';
		}
	}
}

// Metodo para imprimir la matriz mostrada por consola
void nivelDificil::mostrarValoresEnMatriz(char matrizJuego[TAM_FILA][TAM_COLUMNA]) {
	system("cls");
	cout << " \n ::::::		MATRIZ MODO JUGADOR VS CPU - Dificil [ M A Q U I N A ]		::::::::::::::::\n\n";
	for (unsigned int i = 0; i < TAM_FILA; i++) {
		for (unsigned int k = 0; k < TAM_COLUMNA; k++) {
			cout << "[	" << matrizJuego[i][k] << "	]	";
		}
		cout << "\n";
	}
}

// Metodo que retorna un vector con la información de todos los campos ocupados por cada 
// jugador obteniendo así el valor de la totalidad de ocupados existentes en la matriz 
// de juego ocupados por cada letra del jugador X y jugador O.
vector<pair<int, int>> nivelDificil::obtenerLugaresOcupados(char letraAAgregar,
	char matrizJuego[TAM_FILA][TAM_COLUMNA])
{
	// Se declara un vector auxiliar para llenarlo con los espacios ocupados por el jugador
	// se utiliza para retornar los valores que el juegador ha ocupado
	vector<pair<int, int>> auxVectorCamposOcupados;
	for (int i = 0; i < TAM_FILA; i++)
	{
		for (int j = 0; j < TAM_COLUMNA; j++)
		{
			if (letraAAgregar == matrizJuego[i][j])
			{
				auxVectorCamposOcupados.push_back(make_pair(i, j));

			}
		}
	}
	return auxVectorCamposOcupados;
}

// Metodo que actualiza el estado de la variable jugador 1 gano a verdadero o falso si el 
// juegador 2 (máquina) ha realizado movimientos para declararlo ganador del juego o no.
void nivelDificil::verificaGanadorJugador1(char letraAAgregar, char matrizJuego[TAM_FILA][TAM_COLUMNA]) {
	// Siempre y cuando los movimientos correctos por el jugador 1 podra ganar
	if (verificarJugadorGanador(obtenerLugaresOcupados(letraAAgregar, matrizJuego))) {
		jugador1Gano = true;
	}
	else { jugador1Gano = false; }
}

// Metodo que actualiza el estado de la variable jugador 2 gano a verdadero o falso si el juegador 2 
// (máquina) ha realizado movimientos para declararlo ganador del juego o no.
void nivelDificil::verificaGanadorJugador2(char letraAAgregar, char matrizJuego[TAM_FILA][TAM_COLUMNA]) {
	// Siempre y cuando los movimientos correctos por el jugador  2 podra ganar

	cout << "\n ENTRO Y VERIFICO !\n";
	if (verificarJugadorGanador(obtenerLugaresOcupados(letraAAgregar, matrizJuego))) {
		jugador2Gano = true;
		cout << "GANOOOO!";
	}
	else { jugador2Gano = false; }
}

// Metodo que verifica los lugares ocupados en el vector que contiene la información de los movimientos
// realizados en la matriz y verifica si los lugares ocupados son iguales a una posibilidad de gane ya
// definida previamente en vector de posibles jugadas.
bool nivelDificil::verificarJugadorGanador(vector<pair<int, int>>  obtenerLugaresOcupados)
{
	// Se declara una variable auxiliar booleanan para modificar si se encuntra que el jugador a
	// verificar tien una jugada ganadora
	bool auxliarJugadorGano;
	auxliarJugadorGano = false;
	for (int i = 0; i < declaraPosiblesJugadas.size(); i++)
	{
		auxliarJugadorGano = true;
		vector<pair<int, int>> auxliarPosicionGane = declaraPosiblesJugadas[i];
		for (int j = 0; j < 3; j++)
		{
			if (!(find(begin(obtenerLugaresOcupados), end(obtenerLugaresOcupados),
				auxliarPosicionGane[j]) != end(obtenerLugaresOcupados))) {
				auxliarJugadorGano = false; break;
			}
		}

		// Si se encontro que el juegador gano es verdadero detengase y salga de ciclo
		if (auxliarJugadorGano) { break; }
	}
	return auxliarJugadorGano;
}


// Vector que recorre la matriz de juego y verifica que cada posición no tenga una letra por algún
// jugador asignada y de ser asi gaurda los valores en un vector auxliar, el cual se utilizará
// para retornar sus valores de este metodo
vector<pair<int, int>>nivelDificil::obtenerLugaresDisponibles(char matrizJuego[TAM_FILA][TAM_COLUMNA])
{
	// Se declara un vector auxiliar para llenarlo con los espacios disponibles
	// para que se puedan realizar jugadas por los juegaodres
	vector<pair< int, int>> espaciosVaciosMatriz;
	for (int i = 0; i < TAM_FILA; i++)
	{
		for (int k = 0; k < TAM_COLUMNA; k++)
		{
			// Si el campo de la matriz de juego en la posicion i y k su valor es diferente a
			// la letra de jugador X o la letra del juegdor O, entonces se guardan sus valores
			// como espacios diponibles para realizar una jugada.
			if (matrizJuego[i][k] != LETRA_JUGADOR_X && matrizJuego[i][k] != LETRA_JUGADOR_O)
			{
				espaciosVaciosMatriz.push_back(make_pair(i, k));
			}
		}
	}
	return espaciosVaciosMatriz;
}

// Metodo que realiza el cambio de letras segun la eleccion de tipo y numero de jugador.
void nivelDificil::determinaLetraJugadores(char letraJugador, unsigned int numeroJugador) {
	// Actualiza con que letra esta realizando la jugada el jugador 
	// Si es jugador 1 actualiza la letra con la que juega
	if (numeroJugador == 1) {
		letraJugador1 = letraJugador;

	}
	// Falso Si es jugador 2 actualiza la letra con la que juega
	else if (numeroJugador == 2) { letraMaquina = letraJugador; }
}

// Metodo que realiza la validación de jugadas inteligentes por la máquina mediante
// el algoritmo de minimizar las opciones de juego implementado por la máquina
// donde se analizan las posibilidades que tiene el juegador dependiendo de la eleccion
// en la matriz de juego y determinando donde tiene que jugar la máquina para minimizar
// las opciones de gane del juegador 1 y por ende hacer que el juegador termine jugando 
// donde la máquina quiere y lograr el objetivo de empatar o el mejor resultado de ganar
// el juego.

pair<int, pair<int, int>>nivelDificil::algoritmoMinimazaJuego(
	char matrizJuego[TAM_FILA][TAM_COLUMNA], char letraAAgregar,
	int auxEstadoInicial, int auxPerdedor, int auxGanador)
{

	// Se asigna el movimiento correcto con valor de menos uno inicialmente
	pair<int, int> mejorMovimiento = make_pair(-1, -1);

	int mejorMarcador = (letraAAgregar == letraMaquina) ? PERDEDOR : GANADOR;

	// Verificacion si se llega a un estado terminal del nodo (hoja) se devuvle y retorna 
	 // la mejor puntuacion!
	if (matrizJuegoLlena(matrizJuego) ||
		VALOR_TEMPORAL != obtenerEstadoMatrizJuego(matrizJuego, letraMaquina))
	{
		mejorMarcador = obtenerEstadoMatrizJuego(matrizJuego, letraMaquina);
		return make_pair(mejorMarcador, mejorMovimiento);
	}


	vector<pair<int, int>> camposDisponibles = obtenerLugaresDisponibles(matrizJuego);

	for (int i = 0; i < camposDisponibles.size(); i++)
	{

		pair<int, int> movimentoAuxiliar = camposDisponibles[i];
		matrizJuego[movimentoAuxiliar.first][movimentoAuxiliar.second] = letraAAgregar;

		// Maquina minimiza las jugadas de jugador 1
		if (letraAAgregar == letraMaquina)
		{
			int puntajeJuego;
			puntajeJuego = 0;
			puntajeJuego = algoritmoMinimazaJuego(matrizJuego,
				letraJugador1, auxEstadoInicial + 1, auxPerdedor, auxGanador).first;

			// Si el puntaje es el mejor obtiene el movimiento lo elige y lo guarda 
			if (mejorMarcador < puntajeJuego)
			{
				mejorMarcador = puntajeJuego - auxEstadoInicial * 10;
				mejorMovimiento = movimentoAuxiliar;

				// Se comprueba si el mejor movimiento realizado en esta rama del arbol es mejor o
				// peor que la mejor opcion de una rama previa. 
				// si esta rama es peor la salta
				auxPerdedor = max(auxPerdedor, mejorMarcador);

				matrizJuego[movimentoAuxiliar.first][movimentoAuxiliar.second] = CAMPO_EN_BLANCO;
				if (auxGanador <= auxPerdedor)
				{
					break;
				}
			}

		}
		// Falso verifica el turno del jugador y analiza sus movimientos ------------
		else
		{
			int puntajeJuego;
			puntajeJuego = 0;
			puntajeJuego = algoritmoMinimazaJuego(matrizJuego,
				LETRA_JUGADOR_O, auxEstadoInicial + 1, auxPerdedor, auxGanador).first;

			if (mejorMarcador > puntajeJuego)
			{
				mejorMarcador = puntajeJuego + auxEstadoInicial * 10;
				mejorMovimiento = movimentoAuxiliar;

				// Se comprueba si el mejor movimiento realizado en esta rama del arbol es mejor o
				// peor que la mejor opcion de una rama previa. 
				// si esta rama es peor la salta
				auxGanador = min(auxGanador, mejorMarcador);
				matrizJuego[movimentoAuxiliar.first][movimentoAuxiliar.second] = CAMPO_EN_BLANCO;
				if (auxGanador <= auxPerdedor)
				{
					break;
				}
			}
		}
		matrizJuego[movimentoAuxiliar.first][movimentoAuxiliar.second] = CAMPO_EN_BLANCO;
	}
	return make_pair(mejorMarcador, mejorMovimiento);
}

// Metodo que retorna un booleano de verdadero o falso si la matriz de juego esta llena
bool nivelDificil::matrizJuegoLlena(char matrizJuego[TAM_FILA][TAM_COLUMNA])
{
	// mediante un vector se optienen la cantidad de lugares disponibles de la matriz de juego
	// y se verifica si es igual a cero retorna que la matriz esta llena.
	vector<pair<int, int>> camposDisponiblesAux = obtenerLugaresDisponibles(matrizJuego);
	if (0 == camposDisponiblesAux.size())
	{
		return true;
	}
	else { return false; }

}



// Metodo booleano que devuele la verificasion de verdadero o falso si el juegador 1
// ha realizado movimientos para declararlo ganador del juego o no.
bool nivelDificil::verificaGanadorJugador11() {
	// Siempre y cuando los movimientos correctos por el jugador 1 podra ganar
	if (verificarJugadorGanador1()) {
		jugador1Gano = true;
	}
	else {
		jugador1Gano = false;
	}

	return jugador1Gano;
}


// Metodo booleano que devuele la verificasion de verdadero o falso si el juegador 1
// ha realizado movimientos para declararlo ganador del juego o no.
bool nivelDificil::verificaGanadorJugador22() {
	// Siempre y cuando los movimientos correctos por el jugador 1 podra ganar
	if (verificarJugadorGanador1()) {
		jugador2Gano = true;
	}
	else {
		jugador2Gano = false;
	}

	return jugador2Gano;
}

// Metodo que verifica si la seleccion de boton del jugador se puede escoger y 
// cambia el estado de la variable realizoJugada a verdadero. 
bool nivelDificil::verificarJugadorGanador1() {
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
bool nivelDificil::verificacionMovimientoDiagonalIzquierda() {
	bool auxGanaDiagonalIz;
	auxGanaDiagonalIz = false;


	// Verifical la diagonal izuquierda de X
	if (matrizJuego[0][0] == LETRA_JUGADOR_X && matrizJuego[0][4] == LETRA_JUGADOR_X &&
		matrizJuego[0][8] == LETRA_JUGADOR_X) {
		auxGanaDiagonalIz = true;
	}
	// Verifical la diagonal izuquierda de O
	else if (matrizJuego[0][0] == LETRA_JUGADOR_O && matrizJuego[0][4] == LETRA_JUGADOR_O &&
		matrizJuego[0][8] == LETRA_JUGADOR_O) {
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
bool nivelDificil::verificacionMovimientoDiagonalDerecha() {
	bool auxGanaDiagonalDer;
	auxGanaDiagonalDer = false;

	// Verifical la diagonal derecha de X
	if (matrizJuego[0][2] == LETRA_JUGADOR_X && matrizJuego[0][4] == LETRA_JUGADOR_X &&
		matrizJuego[0][6] == LETRA_JUGADOR_X) {
		auxGanaDiagonalDer = true;
	}

	// Verifical la diagonal derecha de O
	else if (matrizJuego[0][2] == LETRA_JUGADOR_O && matrizJuego[0][4] == LETRA_JUGADOR_O &&
		matrizJuego[0][6] == LETRA_JUGADOR_O) {
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
bool nivelDificil::verificacionMovimientoVertical() {
	bool auxGanaVertical;
	auxGanaVertical = false;

	// Verifica la primera columna vertical de X
	if (matrizJuego[0][0] == LETRA_JUGADOR_X && matrizJuego[0][3] == LETRA_JUGADOR_X &&
		matrizJuego[0][6] == LETRA_JUGADOR_X) {
		auxGanaVertical = true;
	}
	// Verifica la primera columna vertical de O
	else if (matrizJuego[0][0] == LETRA_JUGADOR_O && matrizJuego[0][3] == LETRA_JUGADOR_O &&
		matrizJuego[0][6] == LETRA_JUGADOR_O) {
		auxGanaVertical = true;
	}
	// Verifica la segunda columna vertical de X
	else if (matrizJuego[0][1] == LETRA_JUGADOR_X && matrizJuego[0][4] == LETRA_JUGADOR_X &&
		matrizJuego[0][7] == LETRA_JUGADOR_X) {
		auxGanaVertical = true;
	}
	// Verifica la segunda columna vertical de O
	else if (matrizJuego[0][1] == LETRA_JUGADOR_O && matrizJuego[0][4] == LETRA_JUGADOR_O &&
		matrizJuego[0][7] == LETRA_JUGADOR_O) {
		auxGanaVertical = true;
	}

	// Verifica la tercera columna vertical de X
	else if (matrizJuego[0][2] == LETRA_JUGADOR_X && matrizJuego[0][5] == LETRA_JUGADOR_X &&
		matrizJuego[0][8] == LETRA_JUGADOR_X) {
		auxGanaVertical = true;
	}
	// Verifica la tercera columna vertical de O
	else if (matrizJuego[0][2] == LETRA_JUGADOR_O && matrizJuego[0][5] == LETRA_JUGADOR_O &&
		matrizJuego[0][8] == LETRA_JUGADOR_O) {
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
bool nivelDificil::verificacionMovimientoHorizontal() {
	bool auxGanaHorizontal;
	auxGanaHorizontal = false;

	// Verifica la primera linea horizontal de X
	if (matrizJuego[0][0] == LETRA_JUGADOR_X && matrizJuego[0][1] == LETRA_JUGADOR_X
		&& matrizJuego[0][2] == LETRA_JUGADOR_X) {
		auxGanaHorizontal = true;
	}
	// Verifica la primera linea horizontalde O
	else if (matrizJuego[0][0] == LETRA_JUGADOR_O && matrizJuego[0][1] == LETRA_JUGADOR_O &&
		matrizJuego[0][2] == LETRA_JUGADOR_O) {
		auxGanaHorizontal = true;
	}
	// Verifica la segunda linea horizontal de X
	else if (matrizJuego[0][3] == LETRA_JUGADOR_X && matrizJuego[0][4] == LETRA_JUGADOR_X &&
		matrizJuego[0][5] == LETRA_JUGADOR_X) {
		auxGanaHorizontal = true;
	}
	// Verifica la segunda linea horizontal de O
	else if (matrizJuego[0][3] == LETRA_JUGADOR_O && matrizJuego[0][4] == LETRA_JUGADOR_O &&
		matrizJuego[0][5] == LETRA_JUGADOR_O) {
		auxGanaHorizontal = true;
	}

	// Verifica la tercera linea horizontal de X
	else if (matrizJuego[0][6] == LETRA_JUGADOR_X && matrizJuego[0][7] == LETRA_JUGADOR_X &&
		matrizJuego[0][8] == LETRA_JUGADOR_X) {
		auxGanaHorizontal = true;
	}
	// Verifica la tercera linea horizontal de O
	else if (matrizJuego[0][6] == LETRA_JUGADOR_O && matrizJuego[0][7] == LETRA_JUGADOR_O &&
		matrizJuego[0][8] == LETRA_JUGADOR_O) {
		auxGanaHorizontal = true;
	}
	// Falso no existen concidencias de jugada ganadora en horizontal
	else { auxGanaHorizontal = false; }
	return auxGanaHorizontal;
}