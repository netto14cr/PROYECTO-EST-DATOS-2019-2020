// nivelDificicil.cpp
// Autores: Kislev Aleman, Josua Esquivel y Néstor Leiva
// Descripcion: Implementación de la clase nivelDificil y sus metodos necesarios para la 
// realizacion de la validacion del nivel jugador vs CPU - Dificultadad:: Dificil, y
// implementa metodos para validar y ejecutar movimientos inteligentes de la máquina, 
// según el jugador va realizando jugadas para intentar que el jugador pierda, empate y si 
// es posible que máquina gana la partida del juego. 

#include "nivelDificil.h"

// Metodo que determina si el juegador puede realizar una jugada y retorna un valor de 
// verdadero o falso ademas de asignar el movimiento solicitado por el usuario, llama al 
// metodo que muestra la matriz de juego por consola.
bool nivelDificil::verificarPosibleJugada(unsigned int nBoton, unsigned int numeroJugador, char letraAAgregar)
{
	// Si es el turno del jugador 1 y la posicion elegida para marcar en la matriz esta vacia
	// realiza la colocacion de la letra en la posicion indicada y actauluza el estado de jugada
	// realizada verdadero.
	if (asignarValorEnBotonMatriz(nBoton, letraAAgregar) && numeroJugador == 1) {
		// Se realiza el cambio del estado de realizo movimiento en la jugada a verdadero
		realizoJugada = true;

		// Se hace el llamado del metodo que verifica si el juegador 1 con el movimiento 
		// realizada puede ganar y actualiza el estado de ganador de jugador 1, de ser verdad.
		verificaGanadorJugador1(letraAAgregar, matrizJuego);

		// Llamado al metodo que muestra los valores de la matriz por consola
		mostrarValoresEnMatriz(matrizJuego);

	}
	// Falso Si es el turno del jugador 1 realiza la comprobacion asignada de jugada de la maquina
	else if (numeroJugador == 2) {
		cout << "\n N o  v a l i d a d o  a u n !!\n\n";
		system("cls");


		// Aqui se debe llamar al metodo para que juegue y valide la maquina
		//verificaGanadorJugador2(letraAAgregar, matrizJuego);

		realizoJugada = false;
	}

	// Falso si no se puede asignar un valor actualiza el estado de jugada realizada a falso
	else { realizoJugada = false; }
	return realizoJugada;
}

// Metodo que retorna un vector en el cuál se le agregarón las posciones de los posibles 
// resultados donde los jugadores ganan el juego, se validan los movimientos gane posibles
// de fila, columna y diagonal izquierda y derecha.
vector<pair<unsigned int, unsigned int>> nivelDificil::llenarVectorPosiblesJugadas()
{
	// Validacion de jugada de gane de fila 0
	jugadasGanadores.push_back(make_pair(0, 0));
	jugadasGanadores.push_back(make_pair(0, 1));
	jugadasGanadores.push_back(make_pair(0, 2));
	// Validacion de jugada de gane de fila 1
	jugadasGanadores.push_back(make_pair(1, 0));
	jugadasGanadores.push_back(make_pair(1, 1));
	jugadasGanadores.push_back(make_pair(1, 2));
	// Validacion de jugada de gane de fila 2
	jugadasGanadores.push_back(make_pair(2, 0));
	jugadasGanadores.push_back(make_pair(2, 1));
	jugadasGanadores.push_back(make_pair(2, 2));
	// Validacion de jugada de gane de columana 0
	jugadasGanadores.push_back(make_pair(0, 0));
	jugadasGanadores.push_back(make_pair(1, 0));
	jugadasGanadores.push_back(make_pair(2, 0));
	// Validacion de jugada de gane de columana 1
	jugadasGanadores.push_back(make_pair(0, 1));
	jugadasGanadores.push_back(make_pair(1, 1));
	jugadasGanadores.push_back(make_pair(2, 1));
	// Validacion de jugada de gane de columana 2
	jugadasGanadores.push_back(make_pair(0, 2));
	jugadasGanadores.push_back(make_pair(1, 2));
	jugadasGanadores.push_back(make_pair(2, 2));
	// Validacion de jugada de gane de diagonal izquierda
	jugadasGanadores.push_back(make_pair(0, 0));
	jugadasGanadores.push_back(make_pair(1, 1));
	jugadasGanadores.push_back(make_pair(2, 2));
	// Validacion de jugada de gane de diagonal derecha
	jugadasGanadores.push_back(make_pair(2, 0));
	jugadasGanadores.push_back(make_pair(1, 1));
	jugadasGanadores.push_back(make_pair(0, 2));

	return jugadasGanadores;
}

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
bool nivelDificil::asignarValorEnBotonMatriz(unsigned int nBoton, char letraAAgregar) {

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

// Metodo de tipo booleano que retorna un verdadero o falso si en la verificación de la
// matriz y la posiscion a consultar encuentra un valor, si esto ocurre el valor sera
// verdadero pero sino hay nada devolvera un falso.
bool nivelDificil::verificarPosicionMarcada(pair<unsigned int, unsigned int> posicion, char matrizJuego[TAM_FILA][TAM_COLUMNA])
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

// Metodo que retorna un vector con la informacion de todos los campos ocupados por cada 
// jugador obteniendo así el valor de la totalidad de ocupados existentes en la matriz 
// de juego ocupados por cada letra del jugador X y jugador O.
vector<pair<unsigned int, unsigned int>> nivelDificil::obtenerLugaresOcupados(char letraAAgregar, char matrizJuego[TAM_FILA][TAM_COLUMNA])
{
	// Se declara un vector auxiliar para llenarlo con los espacios ocupados por el jugador
	// se utiliza para retornar los valores que el juegador ha ocupado
	vector<std::pair<unsigned int, unsigned int>> auxVectorCamposOcupados;
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

// Metodo que actualiza el estado de la variable jugador 1 gano a verdadero o falso si el juegador 2 (máquina)
// ha realizado movimientos para declararlo ganador del juego o no.
void nivelDificil::verificaGanadorJugador1(char letraAAgregar, char matrizJuego[TAM_FILA][TAM_COLUMNA]) {
	// Siempre y cuando los movimientos correctos por el jugador 1 podra ganar
	if (verificarJugadorGanador(obtenerLugaresOcupados(letraAAgregar, matrizJuego))) {
		jugador1Gano = true;
	}
	else { jugador1Gano = false; }
}

// Metodo que actualiza el estado de la variable jugador 2 gano a verdadero o falso si el juegador 2 (máquina)
// ha realizado movimientos para declararlo ganador del juego o no.
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

	for (unsigned int i = 0; i < llenarVectorPosiblesJugadas().size(); i++)
	{
		auxliarJugadorGano = true;
		vector<pair<unsigned int, unsigned int>> auxliarPosicionGane = llenarVectorPosiblesJugadas();
		for (int j = 0; j < 3; j++)
		{
			if (!(find(begin(llenarVectorPosiblesJugadas()), end(llenarVectorPosiblesJugadas()),
				auxliarPosicionGane[j]) != end(llenarVectorPosiblesJugadas()))) {
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




// <<<<<<<<<<<<<<<<<<	N I V E L  E N  C O N S T R U C C I O N	  >>>>>>>>>>>>>>>>>>>>>>>>>
// <<<<<<<<<<<<<<<<<<			P L E A S E  W A I T...			  >>>>>>>>>>>>>>>>>>>>>>>>>







