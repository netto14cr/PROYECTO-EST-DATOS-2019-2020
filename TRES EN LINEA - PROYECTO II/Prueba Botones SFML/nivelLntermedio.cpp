// NivelIntermedio.ccp
// Autores: Kislev Aleman, Josua Esquivel y Néstor Leiva
// Descripcion: Implementacion de la clase NivelFacil.ccp y sus metodos necesarios para la 
// realizacion de la validacion del nivel jugador vs maquina, realizacion de jugadas y
// la validacion de jugadas correctas y el deterninar asi en el transcurso del juego
// si hay una ganador o el juego termina en empate.


#include "NivelIntermedio.h"


bool nivelIntermedio::verificarPosibleJugadaNI(unsigned int nBoton, unsigned int nJugador, char letraAAgregar) {
	cout << "\nletra a agrgar:: " << letraAAgregar << endl;
	//Valida si es el turno del jugador o el de la maquina 
	if (nJugador == 1) {
		// Asigna un valor de ser posible en la matrizJuego de juego y actualiza el estado de realizo jugada
		// ademas se verifica la posibilidad de que el jugador haya ganado con ese movimiento
		if (asignarValorEnBotonMatriz(nBoton, letraAAgregar)) {
			// Se realiza el cambio del estado de realizo movimiento en la jugada a verdadero
			realizoJugada = true;
			// llamado al metodo que muestra los valores de la matrizJuego por consola
			mostrarValoresEnMatriz(matrizJuego);
		}
		// Falso si no se puede asignar un valor a la matrizJuego se actualiza su estado a falso
		else if (!asignarValorEnBotonMatriz(nBoton, letraAAgregar)) {
			// Se realiza el cambio del estado de realizo movimiento en la jugada a falso
			realizoJugada = false;
		}
	}
	else if (nJugador == 2) {
		// Asigna un valor de ser posible en la matrizJuego de juego y actualiza el estado de realizo jugada
	 // ademas se verifica la posibilidad de que el jugador haya ganado con ese movimiento
		if (asignarValorEnBotonMatriz(validarJugadaMaquina(nJugador, letraAAgregar), letraAAgregar)) {
			// Se realiza el cambio del estado de realizo movimiento en la jugada a verdadero
			realizoJugada = true;
			// llamado al metodo que muestra los valores de la matrizJuego por consola
			mostrarValoresEnMatriz(matrizJuego);
		}
		// Falso si no se puede asignar un valor a la matrizJuego se actualiza su estado a falso
		else if (!asignarValorEnBotonMatriz(validarJugadaMaquina(nJugador, letraAAgregar), letraAAgregar)) {
			// Se realiza el cambio del estado de realizo movimiento en la jugada a falso
			realizoJugada = false;
		}
	}

	return realizoJugada;
}

//Metodo que ejecuta el movimiento de la maquina y devuelve el numero de botton a seleccionar la maquina
int nivelIntermedio::validarJugadaMaquina(unsigned int jugador, char letraAAgregar) {
	cout << "Jugada Maquina" << endl;
	//coordenadas donde la maquina va a jugar
	int  y; y = 0;
	int x; x = 0;
	//valida si la maquina logro hacer la jugada
	bool validar; validar = false;
	//boton que la maquina va a seleccionar 

	//semilla para el numero aleatrio 
	srand(time(NULL));


	//gerena un ciclo hasta que se genere una posicion que la maquina pueda jugar 

		//Genera las coordenadas de donde va a jugar la maquina con un rand()
	while (validar == false) {
		cout << "While" << validar << endl;
		cout << "bloque" << bloquear << endl;
		y = 1 + rand() % (9 - 1) - 1;

		//Valida si la matrizJuego en la coordenadas generadas esta vacia, si se encuentra vacia guarda la letra
		//de la maquina

			//Validacion horizontal: vaalida dos posiciones con la letra de la maquina y
		   // vaida la tercera que sea espacio vacio
		if ((matrizJuego[0][0] == letraAAgregar) && (matrizJuego[0][1] == letraAAgregar) 
			&&  (matrizJuego[0][2]==CAP_BLAN)) {
			cout << "Validar Horizontal" << endl;
			validar = true;
			y = 2;
		}
		else if ((matrizJuego[0][3] == letraAAgregar) && (matrizJuego[0][4] == letraAAgregar) 
			&& (matrizJuego[0][5] == CAP_BLAN)) {
			validar = true;
			y = 5;
		}
		else if ((matrizJuego[0][6] == letraAAgregar) && (matrizJuego[0][7] == letraAAgregar) 
			&& (matrizJuego[0][8] == CAP_BLAN)) {
			validar = true;
			y = 8;
		}
		else if ((matrizJuego[0][1] == letraAAgregar) && (matrizJuego[0][2] == letraAAgregar) 
			&& (matrizJuego[0][0] == CAP_BLAN)) {
			validar = true;
			y = 0;
		}
		else if ((matrizJuego[0][4] == letraAAgregar) && (matrizJuego[0][5] == letraAAgregar) 
			&& (matrizJuego[0][3] == CAP_BLAN)) {
			validar = true;
			y = 3;
		}
		else if ((matrizJuego[0][7] == letraAAgregar) && (matrizJuego[0][8] == letraAAgregar) 
			&& (matrizJuego[0][6] == CAP_BLAN)) {
			validar = true;
			y = 6;
		}
		else if ((matrizJuego[0][0] == letraAAgregar) && (matrizJuego[0][2] == letraAAgregar) 
			&& (matrizJuego[0][1] == CAP_BLAN)) {
			validar = true;
			y = 1;
		}
		else if ((matrizJuego[0][3] == letraAAgregar) && (matrizJuego[0][5] == letraAAgregar) 
			&& (matrizJuego[0][4] == CAP_BLAN)) {
			validar = true;
			y = 4;
		}
		else if ((matrizJuego[0][6] == letraAAgregar) && (matrizJuego[0][8] == letraAAgregar) 
			&& (matrizJuego[0][7] == CAP_BLAN)) {
			validar = true;
			y = 7;
		}
		//Valida todas las posibles combinacionas a ganar en Vertical
		// Valida dos posiciones que sean de la misma letra con la que juega la maquina 
		// y la tercera sea espacio vacio
		else if ((matrizJuego[0][0] == letraAAgregar) && (matrizJuego[0][3] == letraAAgregar) 
			&& (matrizJuego[0][6] == CAP_BLAN)) {
			validar = true;
			y = 6;
		}
		else if ((matrizJuego[0][1] == letraAAgregar) && (matrizJuego[0][4] == letraAAgregar) 
			&& (matrizJuego[0][7] == CAP_BLAN)) {
			validar = true;
			y = 7;
		}
		else if ((matrizJuego[0][2] == letraAAgregar) && (matrizJuego[0][5] == letraAAgregar) 
			&& (matrizJuego[0][8] == CAP_BLAN)) {
			validar = true;
			y = 8;
		}
		else if ((matrizJuego[0][6] == letraAAgregar) && (matrizJuego[0][3] == letraAAgregar) 
			&& (matrizJuego[0][0] == CAP_BLAN)) {
			validar = true;
			y = 0;
		}
		else if ((matrizJuego[0][7] == letraAAgregar) && (matrizJuego[0][4] == letraAAgregar) 
			&& (matrizJuego[0][1] == CAP_BLAN)) {
			validar = true;
			y = 1;
		}
		else if ((matrizJuego[0][8] == letraAAgregar) && (matrizJuego[0][5] == letraAAgregar) 
			&& (matrizJuego[0][2] == CAP_BLAN)) {
			validar = true;
			y = 2;
		}
		else if ((matrizJuego[0][6] == letraAAgregar) && (matrizJuego[0][0] == letraAAgregar) 
			&& (matrizJuego[0][3] == CAP_BLAN)) {
			validar = true;
			y = 3;
		}
		else if ((matrizJuego[0][1] == letraAAgregar) && (matrizJuego[0][7] == letraAAgregar) 
			&& (matrizJuego[0][4] == CAP_BLAN)) {
			validar = true;
			y = 4;
		}
		else if ((matrizJuego[0][8] == letraAAgregar) && (matrizJuego[0][2] == letraAAgregar) 
			&& (matrizJuego[0][5] == CAP_BLAN)) {
			validar = true;
			y = 5;
		}
		//Vaidar todas las posibles combinaciones en Diagonales izquieda y derecha 
		// Valida dos posiciones que sean de la misma letra con la que juega la maquina 
		// y la tercera sea espacio vacio
		else if ((matrizJuego[0][0] == letraAAgregar) && (matrizJuego[0][4] == letraAAgregar) 
			&& (matrizJuego[0][8] == CAP_BLAN)) {
			validar = true;
			y = 8;
		}
		else if ((matrizJuego[0][8] == letraAAgregar) && (matrizJuego[0][4] == letraAAgregar) 
		&& (matrizJuego[0][0] == CAP_BLAN)) {
			validar = true;
			y = 0;
		}
		else if ((matrizJuego[0][0] == letraAAgregar) && (matrizJuego[0][8] == letraAAgregar) 
		&& (matrizJuego[0][4] == CAP_BLAN)) {
			validar = true;
			y = 4;
		}
		else if ((matrizJuego[0][2] == letraAAgregar) && (matrizJuego[0][4] == letraAAgregar) 
		&& (matrizJuego[0][6] == CAP_BLAN)) {
			validar = true;
			y = 6;
		}
		else if ((matrizJuego[0][6] == letraAAgregar) && (matrizJuego[0][4] == letraAAgregar) 
		&& (matrizJuego[0][2] == CAP_BLAN)) {
			validar = true;
			y = 2;
		}
		else if ((matrizJuego[0][6] == letraAAgregar) && (matrizJuego[0][2] == letraAAgregar) 
		&& (matrizJuego[0][4] == CAP_BLAN)) {
			validar = true;
			y = 4;
		}
		//Bloquea la jugada del oponente, para que no gane en 3 movimientos
		else if (bloquear <1) {
		cout << "bloqueo" << endl;
			 //Validacion horizontal
		     // Valida dos posiciones que sean diferente de la  letra con la que juega la maquina 
		     //  y que sean diferente de espacio vacio
		     // para bloquear en la tercera posicion 
			if ((matrizJuego[0][0] != letraAAgregar) && (matrizJuego[0][1] != letraAAgregar) 
				&& (matrizJuego[0][0] != CAP_BLAN) && (matrizJuego[0][1] != CAP_BLAN) &&
				( matrizJuego[0][2]== CAP_BLAN)) {
				validar = true;
				y = 2;
				bloquear++;
			}
			else if ((matrizJuego[0][3] != letraAAgregar) && (matrizJuego[0][4] != letraAAgregar) 
				&& (matrizJuego[0][3] != CAP_BLAN) && (matrizJuego[0][4] != CAP_BLAN)  
				&& (matrizJuego[0][5] == CAP_BLAN)) {
				validar = true;
				y = 5;
				bloquear++;
			}
			else if ((matrizJuego[0][6] != letraAAgregar) && (matrizJuego[0][7] != letraAAgregar) 
				&& (matrizJuego[0][6] != CAP_BLAN) && (matrizJuego[0][7] != CAP_BLAN) &&
				(matrizJuego[0][8] == CAP_BLAN)) {
				validar = true;
				y = 8;
				bloquear++;
			}
			else if ((matrizJuego[0][2] != letraAAgregar) && (matrizJuego[0][1] != letraAAgregar) 
				&& (matrizJuego[0][2] != CAP_BLAN) && (matrizJuego[0][1] != CAP_BLAN) && 
				(matrizJuego[0][0] == CAP_BLAN)) {
				validar = true;
				y = 0;
				bloquear == true;
			}
			else if ((matrizJuego[0][5] != letraAAgregar) && (matrizJuego[0][4] != letraAAgregar)
				&& (matrizJuego[0][5] != CAP_BLAN) && (matrizJuego[0][4] != CAP_BLAN) && 
				(matrizJuego[0][3] == CAP_BLAN)) {
				validar = true;
				y = 3;
				bloquear++;
			}
			else if ((matrizJuego[0][7] != letraAAgregar) && (matrizJuego[0][8] != letraAAgregar) 
				&& (matrizJuego[0][7] != CAP_BLAN) && (matrizJuego[0][8] != CAP_BLAN) && 
				(matrizJuego[0][6] == CAP_BLAN)) {
				validar = true;
				y = 6;
				bloquear++;
			}
			else if ((matrizJuego[0][0] != letraAAgregar) && (matrizJuego[0][2] != letraAAgregar) 
				&& (matrizJuego[0][0] != CAP_BLAN) && (matrizJuego[0][2] != CAP_BLAN) && 
				(matrizJuego[0][1] == CAP_BLAN)) {
				validar = true;
				y = 1;
				bloquear++;
			}
			else if ((matrizJuego[0][3] != letraAAgregar) && (matrizJuego[0][5] != letraAAgregar)
				&& (matrizJuego[0][3] != CAP_BLAN) && (matrizJuego[0][5] != CAP_BLAN) && 
				(matrizJuego[0][4] == CAP_BLAN)) {
				validar = true;
				y = 4;
				bloquear++;
			}
			else if ((matrizJuego[0][6] != letraAAgregar) && (matrizJuego[0][8] != letraAAgregar)
				&& (matrizJuego[0][6] != CAP_BLAN) && (matrizJuego[0][8] != CAP_BLAN) && 
				(matrizJuego[0][7] == CAP_BLAN)) {
				validar = true;
				y = 7;
				bloquear++;
			}
			//Valida todas las posibles convinaciona a ganar en Vertical
			 // Valida dos posiciones que sean diferente de la  letra con la que juega la maquina 
			 //  y que sean diferente de espacio vacio
			 // para bloquear en la tercera posicion 
			else if ((matrizJuego[0][0] != letraAAgregar) && (matrizJuego[0][3] != letraAAgregar) 
				&& (matrizJuego[0][0] != CAP_BLAN) && (matrizJuego[0][3] != CAP_BLAN) 
				&& (matrizJuego[0][6] == CAP_BLAN)) {
				validar = true;
				y = 6;
				bloquear++;
			}
			else if ((matrizJuego[0][1] != letraAAgregar) && (matrizJuego[0][4] != letraAAgregar) 
				&& (matrizJuego[0][4] != CAP_BLAN) && (matrizJuego[0][1] != CAP_BLAN) &&
				(matrizJuego[0][7] == CAP_BLAN)) {
				validar = true;
				y = 7;
				bloquear++;
			}
			else if ((matrizJuego[0][2] != letraAAgregar) && (matrizJuego[0][5] != letraAAgregar) 
				&& (matrizJuego[0][2] != CAP_BLAN) && (matrizJuego[0][5] != CAP_BLAN) &&
				(matrizJuego[0][8] == CAP_BLAN)) {
				validar = true;
				y = 8;
				bloquear++;
			}
			else if ((matrizJuego[0][6] != letraAAgregar) && (matrizJuego[0][3] != letraAAgregar) 
				&& (matrizJuego[0][6] != CAP_BLAN) && (matrizJuego[0][3] != CAP_BLAN) && 
				(matrizJuego[0][0] == CAP_BLAN)) {
				validar = true;
				y = 0;
				bloquear++;
			}
			else if ((matrizJuego[0][7] != letraAAgregar) && (matrizJuego[0][4] != letraAAgregar) 
				&& (matrizJuego[0][7] != CAP_BLAN) && (matrizJuego[0][4] != CAP_BLAN) && 
				(matrizJuego[0][1] == CAP_BLAN)) {
				validar = true;
				y = 1;
				bloquear++;
			}
			else if ((matrizJuego[0][8] != letraAAgregar) && (matrizJuego[0][5] != letraAAgregar)
				&& (matrizJuego[0][8] != CAP_BLAN) && (matrizJuego[0][5] != CAP_BLAN) && 
				(matrizJuego[0][2] == CAP_BLAN)) {
				validar = true;
				y = 2;
				bloquear++;
			}
			else if ((matrizJuego[0][0] != letraAAgregar) && (matrizJuego[0][6] != letraAAgregar) 
			&& (matrizJuego[0][0] != CAP_BLAN) && (matrizJuego[0][6] != CAP_BLAN) && 
			(matrizJuego[0][3] == CAP_BLAN)) {
				validar = true;
				y = 3;
				bloquear++;
			}
			else if ((matrizJuego[0][1] != letraAAgregar) && (matrizJuego[0][7] != letraAAgregar) 
			&& (matrizJuego[0][1] != CAP_BLAN) && (matrizJuego[0][7] != CAP_BLAN) && 
			(matrizJuego[0][4] == CAP_BLAN)) {
				validar = true;
				y = 4;
				bloquear++;
			}
			else if ((matrizJuego[0][8] != letraAAgregar) && (matrizJuego[0][2] != letraAAgregar) 
			&& (matrizJuego[0][8] != CAP_BLAN) && (matrizJuego[0][2] != CAP_BLAN) && 
			(matrizJuego[0][5] == CAP_BLAN)) {
				validar = true;
				y = 5;
				bloquear++;
			}
			//Vaidar todas las posibles combinaciones en Diagonales izquieda y derecha 
			 // Valida dos posiciones que sean diferente de la  letra con la que juega la maquina 
			 //  y que sean diferente de espacio vacio
			 // para bloquear en la tercera posicion 
			else if ((matrizJuego[0][0] != letraAAgregar) && (matrizJuego[0][4] != letraAAgregar) 
			&& (matrizJuego[0][0] != CAP_BLAN) && (matrizJuego[0][4] != CAP_BLAN) && 
			(matrizJuego[0][8] == CAP_BLAN)) {
				validar = true;
				y = 8;
				bloquear++;
			}
			else if ((matrizJuego[0][8] != letraAAgregar) && (matrizJuego[0][4] != letraAAgregar) 
			&& (matrizJuego[0][8] != CAP_BLAN) && (matrizJuego[0][4] != CAP_BLAN) && 
			(matrizJuego[0][0] == CAP_BLAN)) {
				validar = true;
				y = 0;
				bloquear++;
			}
			else if ((matrizJuego[0][0] != letraAAgregar) && (matrizJuego[0][8] != letraAAgregar) &&
			(matrizJuego[0][0] != CAP_BLAN) && (matrizJuego[0][8] != CAP_BLAN) && 
			(matrizJuego[0][4] == CAP_BLAN)) {
				validar = true;
				y = 4;
				bloquear++;
			}
			else if ((matrizJuego[0][2] != letraAAgregar) && (matrizJuego[0][4] != letraAAgregar) 
			&& (matrizJuego[0][2] != CAP_BLAN) && (matrizJuego[0][4] != CAP_BLAN) && 
			(matrizJuego[0][6] == CAP_BLAN)) {
				validar = true;
				y = 6;
				bloquear++;
			}
			else if ((matrizJuego[0][6] != letraAAgregar) && (matrizJuego[0][4] != letraAAgregar) 
			&& (matrizJuego[0][6] != CAP_BLAN) && (matrizJuego[0][4] != CAP_BLAN) && 
			(matrizJuego[0][2] == CAP_BLAN)) {
				validar = true;
				y = 2;
				bloquear++;
			}
			else if ((matrizJuego[0][2] != letraAAgregar) && (matrizJuego[0][6] != letraAAgregar) 
			&& (matrizJuego[0][2] != CAP_BLAN) && (matrizJuego[0][6] != CAP_BLAN) && 
			(matrizJuego[0][4] == CAP_BLAN)) {
				validar = true;
				y = 4;
				bloquear++;
			}
			// Valida la posicion aletoria sea vacia para que pueda jugar la maquina
			else if (matrizJuego[x][y] == CAP_BLAN) {
				cout << "Rand" << endl;
				validar = true;
			}
			
		}
		 // Valida la posicion aletoria sea vacia para que pueda jugar la maquina 
		else if (matrizJuego[x][y] == CAP_BLAN) {
		 cout << "Rand" << endl;
			validar = true;
		}
		cout << "N" << endl;
		cout << "Final" << endl;
	}

	return y;
}

// Metodo para imprimir la matrizJuego mostrada por consola
void nivelIntermedio::mostrarValoresEnMatriz(char matrizJuegoJuego[TAM_FILA][TAM_COLUMNA]) {
	system("cls");
	cout << " \n :::::::::		Matriz MODO JUGADOR VS MAQUINA -DIficultad:::NORMAL		::::::::::::::::\n\n";
	for (unsigned int i = 0; i < TAM_FILA; i++) {
		for (unsigned int k = 0; k < TAM_COLUMNA; k++) {
			cout << "[	" << matrizJuego[i][k] << "	]	";

		}
		cout << "\n";
	}
}

// Metodo booleano que devuele la verificasion de verdadero o falso si el juegador 1
// ha realizado movimientos para declararlo ganador del juego o no.
void nivelIntermedio::verificaGanadorJugador1() {
	// Siempre y cuando los movimientos correctos por el jugador 1 podra ganar
	if (verificarJugadorGanador()) {
		jugador1Gano = true;
	}
	else {
		jugador1Gano = false;
	}

}

// Metodo booleano que devuele la verificasion de verdadero o falso si el juegador 2
// ha realizado movimientos para declararlo ganador del juego o no.
void nivelIntermedio::verificaGanadorJugador2() {
	// Siempre y cuando los movimientos correctos por el jugador  2 podra ganar
	if (verificarJugadorGanador()) {
		jugador2Gano = true;
	}
	else {
		jugador2Gano = false;
	}
}

// Metodo que verifica si la seleccion de boton del jugador se puede escoger y 
// cambia el estado de la variable realizoJugada a verdadero. 
bool nivelIntermedio::verificarJugadorGanador() {
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
bool nivelIntermedio::verificacionMovimientoDiagonalIzquierda() {
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
bool nivelIntermedio::verificacionMovimientoDiagonalDerecha() {
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
bool nivelIntermedio::verificacionMovimientoVertical() {
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
bool nivelIntermedio::verificacionMovimientoHorizontal() {
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

// Vector guarda matrizJuegoJuego para pasar a la clase gato para usarla 
// para imprimir contenido de botones del juego
vector<char> nivelIntermedio::vectorGuardaMatriz()
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
void nivelIntermedio::resetGame()
{
	jugador1Gano = false;
	jugador2Gano = false;
	realizoJugada = false;
	inicializarMatrizJuegoVacia();
}

// Verifica que se pueda agrgar un nuevo valor a la matrizJuego de juego
bool nivelIntermedio::asignarValorEnBotonMatriz(unsigned int nBoton, char letraAAgregar) {
	cout << "BOTON # " << nBoton << endl;
	bool auxAsignaValor = false;
	for (unsigned int i = 0; i < TAM_FILA; i++) {
		for (unsigned int k = 0; k < TAM_COLUMNA; k++) {

			if (matrizJuego[0][nBoton] == CAP_BLAN) {
				matrizJuego[0][nBoton] = letraAAgregar;
				auxAsignaValor = true;
			}
		}
	}

	return auxAsignaValor;
}

// Metodo que se encarga de asignar un valor de vacia a toda la matrizJuego de juego
void nivelIntermedio::inicializarMatrizJuegoVacia() {
	for (unsigned int i = 0; i < TAM_FILA; i++) {
		for (unsigned int k = 0; k < TAM_COLUMNA; k++) {
			matrizJuego[i][k] = CAP_BLAN;
		}
	}
}

// Metodo que se encargar de reseter los valores por defecto de la matrizJuego de juego
void nivelIntermedio::limpiarMatrizJuego() {
	for (unsigned int i = 0; i < TAM_FILA; i++) {
		for (unsigned int k = 0; k < TAM_COLUMNA; k++) {

			matrizJuego[i][k] = ' ';
		}
	}
}
