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
		// Se realiza el cambio del estado de realizo movimiento en la jugada a verdadero
		realizoJugada = true;

		// Se hace el llamado del metodo que verifica si el juegador 1 con el movimiento 
		// realizada puede ganar y actualiza el estado de ganador de jugador 1, de ser verdad.
		//verificaGanadorJugador1(letraAAgregar, matrizJuego);

		// Llamado al metodo que muestra los valores de la matriz por consola
		mostrarValoresEnMatriz(matrizJuego);

	}
	// Falso Si es el turno del jugador 1 realiza la comprobacion asignada de jugada de la maquina
	else if (numeroJugador == 2) {
		cout << "\n BEBE :3 --TURNO ::" << numeroJugador << " JUEGA -- " << realizoJugada << "\n\n";
		cout << "\n N o  v a l i d a d o  a u n !!\n\n";
		//system("cls");

		// Aqui se debe llamar al metodo para que juegue y valide la maquina
		pair<unsigned int, pair<unsigned int, unsigned int>> movimientoMaquina = algoritmoMinimazaJuego(matrizJuego,
			numeroJugador, letraAAgregar, ESTADO_INICIAL, PERDEDOR, GANADOR);

		matrizJuego[movimientoMaquina.second.first][movimientoMaquina.second.second] = letraAAgregar;
		//verificaGanadorJugador2(letraAAgregar, matrizJuego);
		// Llamado al metodo que muestra los valores de la matriz por consola
		mostrarValoresEnMatriz(matrizJuego);
		//realizoJugada = true;
	}

	// Falso si no se puede asignar un valor actualiza el estado de jugada realizada a falso
	else { realizoJugada = false; }
	return realizoJugada;
}

// Metodo en el cual se definen las jugadas donde los juegaodres o la maquina pueden ganar en el juego, 
// los posibles movimientos validados son todas la psociones existente de fila, columna y diagonal 
// izquierda y digalonal derecha.

vector<vector<pair<unsigned int, unsigned int>>> declaraPosiblesJugadas{
	// Validacion de jugada de gane de fila 0
	{ std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(0, 2) },
	// Validacion de jugada de gane de fila 1
	{ std::make_pair(1, 0), std::make_pair(1, 1), std::make_pair(1, 2) },
	// Validacion de jugada de gane de fila 2
	{ std::make_pair(2, 0), std::make_pair(2, 1), std::make_pair(2, 2) },
	// Validacion de jugada de gane de columana 0
	{ std::make_pair(0, 0), std::make_pair(1, 0), std::make_pair(2, 0) },
	// Validacion de jugada de gane de columana 1
	{ std::make_pair(0, 1), std::make_pair(1, 1), std::make_pair(2, 1) },
	// Validacion de jugada de gane de columana 2
	{ std::make_pair(0, 2), std::make_pair(1, 2), std::make_pair(2, 2) },
	// Validacion de jugada de gane de diagonal izquierda
	{ std::make_pair(0, 0), std::make_pair(1, 1), std::make_pair(2, 2) },
	// Validacion de jugada de gane de diagonal derecha
	{ std::make_pair(2, 0), std::make_pair(1, 1), std::make_pair(0, 2) }
};


// Vector guarda matrizJuego nivel Dificil para pasar a la clase gato para usarla 
// para imprimir contenido de botones del juego
vector<char> nivelDificil::vectorGuardaMatrizDificil()
{
	vector<char> vectorAux;
	for (unsigned int i = 0; i < TAM_FILA; i++) {
		for (unsigned int k = 0; k < TAM_FILA; k++) {

			vectorAux.push_back(matrizJuego[i][k]);
		}
	}
	return vectorAux;
}

// Verifica que se pueda agrgar un nuevo valor a la matriz de juego
bool nivelDificil::asignarValorEnBotonMatriz(unsigned int nBoton, char letraAAgregar, unsigned int numeroJugador) {

	bool auxAsignaValor = false;
	for (unsigned int i = 0; i < TAM_FILA; i++) {
		for (unsigned int k = 0; k < TAM_COLUMNA; k++) {

			if (matrizJuego[0][nBoton] == '-') {
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
bool nivelDificil::verificarPosicionMarcada(pair<unsigned int, unsigned int> posicion,
	char matrizJuego[TAM_FILA][TAM_COLUMNA])
{
	// Se delacara una variable auxiliar booleana que se le asignara una valor de verdadero 
	// si en la verificacion de campo de la matriz se obtiene como resultado que esta ocpuado
	bool auxVerificaCampoOcupado;
	auxVerificaCampoOcupado = true;
	// Se declara a un vector auxiliar y se le pasan los valores del metodo lugaresDisponibles 
	// de la matriz de juego.
	vector<pair<unsigned int, unsigned int>> auxVectorCamposDisponibles = obtenerLugaresDisponibles(matrizJuego);

	// Ciclo for que recorre los valores que asignamos al vector auxiliar y verifica que 
	// en la direccion i, que valor tiene agregado.
	for (unsigned int i = 0; i < auxVectorCamposDisponibles.size(); i++)
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
	// Se daclara un vector para recibir los campos ocupados por el juegador en espefico en la 
	// matriz de juego para comparar si exite un ganador o se perdio.
	vector<pair< unsigned int, unsigned int>>
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
	//system("cls");
	//cout << " \n ::::::		MATRIZ MODO JUGADOR VS CPU - Dificil [ M A Q U I N A ]		::::::::::::::::\n\n";
	for (unsigned int i = 0; i < TAM_FILA; i++) {
		for (unsigned int k = 0; k < TAM_COLUMNA; k++) {
			//cout << "[	" << matrizJuego[i][k] << "	]	";
		}
		//cout << "\n";
	}
}

// Metodo que retorna un vector con la información de todos los campos ocupados por cada 
// jugador obteniendo así el valor de la totalidad de ocupados existentes en la matriz 
// de juego ocupados por cada letra del jugador X y jugador O.
vector<pair<unsigned int, unsigned int>> nivelDificil::obtenerLugaresOcupados(char letraAAgregar,
	char matrizJuego[TAM_FILA][TAM_COLUMNA])
{
	// Se declara un vector auxiliar para llenarlo con los espacios ocupados por el jugador
	// se utiliza para retornar los valores que el juegador ha ocupado
	vector<std::pair<unsigned int, unsigned int>> auxVectorCamposOcupados;
	//cout << "\n\n";
	for (int i = 0; i < TAM_FILA; i++)
	{
		for (int j = 0; j < TAM_COLUMNA; j++)
		{
			if (letraAAgregar == matrizJuego[i][j])
			{
				auxVectorCamposOcupados.push_back(make_pair(i, j));
				//cout<<matrizJuego[i][j]<<" - ";
			}
			//cout << "\n";
		}
		//system("cls");
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
	if (verificarJugadorGanador(obtenerLugaresOcupados(letraAAgregar, matrizJuego))) {
		jugador2Gano = true;
	}
	else { jugador2Gano = false; }
}

// Metodo que verifica los lugares ocupados en el vector que contiene la información de los movimientos
// realizados en la matriz y verifica si los lugares ocupados son iguales a una posibilidad de gane ya
// definida previamente en vector de posibles jugadas.
bool nivelDificil::verificarJugadorGanador(vector<pair<unsigned int, unsigned int>>  obtenerLugaresOcupados)
{
	// Se declara una variable auxiliar booleanan para modificar si se encuntra que el jugador a
	// verificar tien una jugada ganadora
	bool auxliarJugadorGano;
	auxliarJugadorGano = false;

	for (unsigned int i = 0; i < declaraPosiblesJugadas.size(); i++)
	{
		auxliarJugadorGano = true;
		vector<pair<unsigned int, unsigned int>> auxliarPosicionGane = declaraPosiblesJugadas[i];
		for (int j = 0; j < 3; j++)
		{
			if (!(find(begin(declaraPosiblesJugadas[i]), end(declaraPosiblesJugadas[i]),
				auxliarPosicionGane[j]) != end(declaraPosiblesJugadas[i]))) {
				auxliarJugadorGano = false; break;
			}
		}

		// Si se encontro que el juegador gano es verdadero detengase y salga de ciclo
		if (auxliarJugadorGano) { break; }
	}
	return auxliarJugadorGano;
}
//-------------------- R E V I S A R -----------------------------

// Vector que recorre la matriz de juego y verifica que cada posición no tenga una letra por algún
// jugador asignada y de ser asi gaurda los valores en un vector auxliar, el cual se utilizará
// para retornar sus valores de este metodo
vector<pair<unsigned int, unsigned int>>nivelDificil::obtenerLugaresDisponibles(char matrizJuego[TAM_FILA][TAM_COLUMNA])
{
	// Se declara un vector auxiliar para llenarlo con los espacios disponibles
	// para que se puedan realizar jugadas por los juegaodres
	vector<pair<unsigned int, unsigned int>> espaciosVaciosMatriz;
	for (unsigned int i = 0; i < TAM_FILA; i++)
	{
		for (unsigned int k = 0; k < TAM_COLUMNA; k++)
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

// Metodo que realiza la validación de jugadas inteligentes por la máquina mediante
// el algoritmo de minimizar las opciones de juego implementado por la máquina
// donde se analizan las posibilidades que tiene el juegador dependiendo de la eleccion
// en la matriz de juego y determinando donde tiene que jugar la máquina para minimizar
// las opciones de gane del juegador 1 y por ende hacer que el juegador termine jugando 
// donde la máquina quiere y lograr el objetivo de empatar o el mejor resultado de ganar
// el juego.

pair<int, pair<int, int>> nivelDificil::algoritmoMinimazaJuego(
	char matrizJuego[TAM_FILA][TAM_COLUMNA], int numeroJugador, char letraAAgregar,
	int auxEstadoInicial, int auxPerdedor, int auxGanador)
{

	// Se asigna el movimiento correcto con los agregados en menos -1 por defecto
	pair< int, int> movimientoCorrecto = make_pair(-1, -1);

	int mejorResultadoDeJuego = (numeroJugador == 2) ? auxPerdedor : auxGanador;

	// Verificacion si se llega a un estado terminal del nodo (hoja) se devuvle y retorna 
	 // la mejor puntuacion!
	if (matrizJuegoLlena(matrizJuego) ||
		VALOR_TEMPORAL != obtenerEstadoMatrizJuego(matrizJuego, letraAAgregar))
	{

		mejorResultadoDeJuego = obtenerEstadoMatrizJuego(matrizJuego, letraAAgregar);
		//cout << "\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
		return make_pair(mejorResultadoDeJuego, movimientoCorrecto);
	}

	// EL PROBLEMA ES QUE SE FALE ANTES DE AQUI.....................
	cout << "\n-----------\n";
	vector<pair<unsigned int, unsigned int>> camposDisponibles = obtenerLugaresDisponibles(matrizJuego);

	for (unsigned int i = 0; i < camposDisponibles.size(); i++)
	{

		cout << "[ " << camposDisponibles[i].second << " ";

		pair<unsigned int, unsigned int> movimentoAuxiliar = camposDisponibles[i];
		matrizJuego[movimentoAuxiliar.first][movimentoAuxiliar.second] = letraAAgregar;

		// Maquina minimiza las jugadas de jugador 1
		if (numeroJugador == 2)
		{
			int puntajeJuego = algoritmoMinimazaJuego(matrizJuego, numeroJugador,
				letraAAgregar, auxEstadoInicial + 1, auxPerdedor, auxGanador).first;

			// Si el puntaje es el mejor obtiene el movimiento lo elige y lo guarda 
			if (mejorResultadoDeJuego < puntajeJuego)
			{
				mejorResultadoDeJuego = puntajeJuego - auxEstadoInicial * 10;
				movimientoCorrecto = movimentoAuxiliar;

				// Se comprueba si el mejor movimiento realizado en esta rama del arbol es mejor o
				// peor que la mejor opcion de una rama previa. 
				// si esta rama es peor la salta
				auxPerdedor = max(auxPerdedor, mejorResultadoDeJuego);

				matrizJuego[movimentoAuxiliar.first][movimentoAuxiliar.second] = CAMPO_EN_BLANCO;
				if (auxGanador <= auxPerdedor)
				{
					break;
				}
			}

		}
		// <<<<<<<<<<<<<<<<	 SI EL TURNO ES DEL JUGADOR	>>>>>>>>>>>>>>>>
		else
		{
			int puntajeJuego = algoritmoMinimazaJuego(matrizJuego, numeroJugador,
				letraAAgregar, auxEstadoInicial + 1, auxPerdedor, auxGanador).first;

			if (mejorResultadoDeJuego > puntajeJuego)
			{
				mejorResultadoDeJuego = puntajeJuego + auxEstadoInicial * 10;
				movimientoCorrecto = movimentoAuxiliar;

				// Se comprueba si el mejor movimiento realizado en esta rama del arbol es mejor o
				// peor que la mejor opcion de una rama previa. 
				// si esta rama es peor la salta
				auxGanador = min(auxGanador, mejorResultadoDeJuego);
				matrizJuego[movimentoAuxiliar.first][movimentoAuxiliar.second] = CAMPO_EN_BLANCO;
				if (auxGanador <= auxPerdedor)
				{
					break;
				}
			}
		}

		matrizJuego[movimentoAuxiliar.first][movimentoAuxiliar.second] = CAMPO_EN_BLANCO;
	}
	cout << "\n\n";

	return make_pair(mejorResultadoDeJuego, movimientoCorrecto);
}

// Metodo que retorna un booleano de verdadero o falso si la matriz de juego esta llena
bool nivelDificil::matrizJuegoLlena(char matrizJuego[TAM_FILA][TAM_COLUMNA])
{
	bool matrizLLenaAux;
	matrizLLenaAux = false;
	// mediante un vector se optienen la cantidad de lugares disponibles de la matriz de juego
	// y se verifica si es igual a cero retorna que la matriz esta llena.
	vector<pair< unsigned int, unsigned int>> cmaposDisponiblesAux = obtenerLugaresDisponibles(matrizJuego);
	if (0 == cmaposDisponiblesAux.size())
	{
		matrizLLenaAux = true;
	}

	return matrizLLenaAux;
}







