
// ventana.cpp
// Autores: Kislev Aleman, Josua Esquivel y Néstor Leiva
// Descripcion: Implementacion de la clase ventana que contiene los metodos que controlan los 
// eventos del juego.

#include "ventana.h"
#include "gato.h"
#include "menu.h"
//#include "modoJuego1.h"




// Se define una nueva ventana que contendra el juego gato con un tamaaño establecido y titulo.
sf::RenderWindow window(sf::VideoMode(1024, 622), "Tres en linea ", sf::Style::Default);


Menu m(1024.0f, 622.0f);
gato ga;


void ventana::iniciarPrograma()
{
	window.setFramerateLimit(30);
	manejoEventosTeclado(window);

}



// Metodo que actualiza el titulo y la iamgen de jugador que esta jugando en el juego
void ventana::actualizaEstadoImgJugador() {
	if (turnoJugador1) {

		// Dibuja en pantalla img de jugador 1 y titulo enposicion mas arriba una 
		ga.dibujarImagenEspecifica(window, 7);
		ga.dibujarImagenEspecifica(window, 9);
	}
	// Dibuja en pantalla img de jugador 2 y titulo enposicion mas arriba una 
	else if (turnoJugador2) {
		ga.dibujarImagenEspecifica(window, 8);
		ga.dibujarImagenEspecifica(window, 9);
	}
}


//  Metodo que escucha todo lo que sucede y se ejecuta mientras la nueva ventana o el juego este en ejecucion
void ventana::manejoEventosTeclado(sf::RenderWindow& window) {

	while (window.isOpen())
	{
		// Llamado al metodo que controlo los eventos del juego
		determinarTipoEvento(window);

		// Si ya comenzo el juego y juego no se encuntra en pausa actualiza en pantalla los objetos del juego
		// en modo JUGADOR VS JUGADOR.
		if (comenzoJuego && juegoEnPausa == false && tipoJuego == "JugadorVsJugador") {

			// Si jugador 1 realiza una jugada valida actualiza la vista en modo juego jugador vs jugador!
			// Actualiza la pantalla de juego siempre y cuando existe un cambio en el juego.
			if (juegoModo1Empezo && !ga.GetGanadorJ1() && !ga.GetGanadorJ2() && !ga.GetNoGanadorFinal()
				) {
				window.clear();
				actualizaEstadoImgJugador();
				// Se resetea el valor para que este este a la espera de un nuevo cambio..
				realizoCambioEnJuego = false;
				
			}

			// Falso si es el turno de jugador 1 y empezo el juego y no hay ningun gane o empate en el juego
			else if (turnoJugador1 && juegoModo1Empezo && !ga.GetGanadorJ1() && !ga.GetGanadorJ2() && !ga.GetNoGanadorFinal()) {
				window.clear();
				actualizaEstadoImgJugador();
				window.display();
			}


			// si jugador 1 no ha realizado ningun movimento ,indica que el juego no ha empezado
			// muestra los botones en blanco por defecto!
			else if (!juegoModo1Empezo && !ga.GetGanadorJ1() && !ga.GetGanadorJ2() &&
				!ga.GetNoGanadorFinal()) {
				window.clear();
				actualizaEstadoImgJugador();
				ga.dibujarBotonesGato(window);
			}

			// Falso si el jugador 1 gano y el juego jugador vs jugador continua activo
			// actualiza el estado en la pantalla: Borra la matriz de botones y indica que 
			// el jugador q ha ganado y pausa el juego.
			else if (ga.GetGanadorJ1() && !juegoEnPausa) {
				window.clear();
				ga.dibujarImagenEspecifica(window, 9);

				// Dibuja en pantalla ganador jugador 1
				ga.dibujarImagenEspecifica(window, 10);
				window.display();
				juegoEnPausa = true;
			}

			// Falso si el jugador 2 gano y el juego jugador vs jugador continua activo
			// actualiza el estado en la pantalla: Borra la matriz de botones y indica que 
			// el jugador q ha ganado y pausa el juego.
			else if (ga.GetGanadorJ2() && !juegoEnPausa) {
				window.clear();
				ga.dibujarImagenEspecifica(window, 9);
				// Dibuja en pantalla ganador jugador 2
				ga.dibujarImagenEspecifica(window, 11);
				window.display();
				juegoEnPausa = true;
			}

			// Falso si se llego a la conclusion que ningun jugador gano en modo de juego jugador vs jugador y este continua 
			// continua activo actualiza el estado en la pantalla: Borra la matriz de botones y indica que 
			// el jugador q ha ganado y pausa el juego.
			else if (ga.GetNoGanadorFinal() && !juegoEnPausa) {
				window.clear();
				ga.dibujarImagenEspecifica(window, 9);

				// Dibuja en pantalla que no hubo ganador , muestra img de empate
				ga.dibujarImagenEspecifica(window, 12);
				window.display();
				juegoEnPausa = true;
			}


		}




		// <<<<<<<<	AQUI VAN LOS CONDISIONALES CON LOS METODOS QUE ACTUALIZAN LA PANTALLA EN MODO JUGADOR VS CPU




		//	>>		FIN MODO JUGADOR VS CPU		>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>


	   // Falso si ya se eligio un tipo de juego pero no ha comenzado el juego se mostrara el menu 
	   // para que el jugador 1 seleccionen el tipo de letra para jugar.
		else if (menuInicioActivo == false && comenzoJuego == false && jugador1Eligio == false && tipoJuego == "JugadorVsJugador") {

			window.clear();
			ga.dibujarImagenEspecifica(window, 1);
			ga.dibujarImagenEspecifica(window, 2);
			ga.dibujarImagenEspecifica(window, 3);
			ga.dibujarImagenEspecifica(window, 4);
			m.dibujarMenuSeleccionJugador1(window);

		}

		// Falso si ya se eligio un tipo de juego pero no ha comenzado el juego se mostrara el menu 
		// para que el jugador 2 seleccione el tipo de letra para jugar.
		else if (menuInicioActivo == false && comenzoJuego == false && jugador2Eligio == false && tipoJuego == "JugadorVsJugador") {

			window.clear();
			ga.dibujarImagenEspecifica(window, 1);
			if (letraSeleccionadaJugador2 == "jugadorO") {
				ga.dibujarImagenEspecifica(window, 6);
			}
			else if (letraSeleccionadaJugador2 == "jugadorX") {
				ga.dibujarImagenEspecifica(window, 2);
			}
			ga.dibujarImagenEspecifica(window, 5);
			m.dibujarMenuSeleccionJugador2(window);

		}

		// Falso si menuInicio esta activo muestra las opciones del menu principal de 
		// juego hasta que el jugador seleccione un tipo de partida
		else if (menuInicioActivo) {

			window.clear();
			ga.dibujarImagenEspecifica(window, 1);
			m.dibujarMenuInicial(window);

		}

	}

}




// Metodo que determina el tipo de evento que esta ocurriendo realizado por el usuario en el juego
void ventana::determinarTipoEvento(sf::RenderWindow& window) {
	sf::Event event;
	while (window.pollEvent(event))
	{

		switch (event.type)
		{

			// Valida el evento del boton de cerrar si el usuario cierra la ventana del juego
		case sf::Event::Closed:
			window.close();
			cout << "\nCerro ventana de juego!\n";
			// Detiene el sonido del juego cuando se cirra el juego
			//ga.detenerSonido();
			break;

			// Valida de caso para evento de mouse encima de un boton si estan jugando
			if (comenzoJuego && juegoEnPausa == false) {
		case sf::Event::MouseMoved:

			// Llama al metodo que comprueba si el mause se encuntra encima de un boton del juego.
			ga.pintarColorBotonEncima(window);
			break;


			// Validacion de boton presionado por el usuario (click)
		case sf::Event::MouseButtonPressed:

			// LLama al metodo que comprueba cual boton fue presionado porel usuario
			ga.accionSeleccionarBoton(window, numeroJugador);
			opcionesBotonesJuegoModo1(window);
			break;


			}
			// Validacion del evento por teclado presionadas por el usuario
		case sf::Event::KeyReleased:
			switch (event.key.code)
			{

				// Presiono tecla de arriba
			case sf::Keyboard::Up:
				system("cls");
				cout << "Arriba\n";

				if (menuInicioActivo) {
					m.moveUpMenu();
					//ga.reproducirSonido(2);
				}


				// Falso si ya se elegio un tipo de juego pero no se ha seleccionado las letras de los jugadores
				// ha utilizar en el juego navegan entre el menu de eleccion de letra para jugar.
				else if (menuInicioActivo == false && comenzoJuego == false) {


					// Si el juegador 1 no ha escogido el tipo de letra para jugar
					// Navega con la fecha de arriba entre menu del jugador 1
					if (jugador1Eligio == false) {

						m.moveUpSeleccionJugador(1);
					}

					// Si el juegador 2 no ha escogido el tipo de letra para jugar y jugador 1 ya elegio
					// Navega con la fecha de arriba entre menu del jugador 1
					else if (jugador2Eligio == false && jugador1Eligio) {
						m.moveUpSeleccionJugador(2);
					}

				}
				break;


				//  Presiono tecla de abajo
			case sf::Keyboard::Down:
				system("cls");
				cout << "Abajo\n";
				if (menuInicioActivo) {
					m.moveDownMenu();
					//ga.reproducirSonido(2);
				}


				// Falso si ya se elegio un tipo de juego pero no se ha seleccionado las letras de los jugadores
				// ha utilizar en el juego navegan entre el menu de eleccion de letra para jugar.
				else if (menuInicioActivo == false && comenzoJuego == false) {


					// Si el juegador 1 no ha escogido el tipo de letra para jugar
					// Navega con la fecha de abajo entre menu del jugador 1
					if (jugador1Eligio == false) {

						m.moveDownSeleccionJugador(1);
					}

					// Si el juegador 2 no ha escogido el tipo de letra para jugar y jugador 1 ya elegio
					// Navega con la fecha de abajo entre menu del jugador 1
					else if (jugador2Eligio == false && jugador1Eligio) {
						m.moveDownSeleccionJugador(2);
					}
				}
				break;


			case sf::Keyboard::Return:
				if (juegoEnPausa == true) {
					opcionesMenuJuego(window);
				}
				// Condisional Si comenzo el juego y el tipo de juego es el primero se llama 
				// al metodo que se encarga de escuchar los eventos que suceden el juego de jugador vs jugador 


				else if (comenzoJuego && juegoEnPausa == false && tipoJuego == "JugadorVsJugador") {
					opcionesBotonesJuegoModo1(window);
				}
				else if (comenzoJuego && juegoEnPausa == false && tipoJuego == "JugadorVsCPU") {

				}


			}
		}

	}
}

// Metodo que realiza la validacion de movimientos y de jugadas en modo de juego jugador vs jugador
// ademas de escuhar lo que pasa con los botones, verifica que el jugador pueda realizar la juga y de
// ser posible cambia el estado de las imagenes de los botones en el juego.

void ventana::opcionesBotonesJuegoModo1(sf::RenderWindow& window) {


	unsigned int numeroBotonSeleccionado;
	numeroBotonSeleccionado = 0;
	numeroBotonSeleccionado = ga.GetBotonPresionado();
	// si el boton seleccionado es diferente de 0 realice una accion sino no haga nada..
	if (numeroBotonSeleccionado != 0) {

		// Si es el turno de eleccion es del jugador 1 () Por defecto el turno uno siempre va hacer verdadero
		if (turnoJugador1) {
			cout << "\n ----->1\n";

			// Verificamos que se pueda realizar la jugada pasando el numero de boton presionado y el tipo de jugador 
			// en este caso jugador 1 y la letra de seleccion con la que juega.
			if (ga.verificarPosibleJugadaModo1((numeroBotonSeleccionado - 1), 1, letraSeleccionadaJugador1, window)) {
				// Cambia el estado de dibujo del juego a positivo, deja de mostrar los botones en blanco
				// ha actualizar los que se modifican
				juegoModo1Empezo = true;

				// Si se cumple y jugador 1 puede realizar el movimiento actualiza la matriz grafica y cambia de turno entre jugadores.
				cout << "\n CAMBIO TURNOS AHORA LE TOCA JUGADOR 2222!!\n";
				turnoJugador1 = false;
				turnoJugador2 = true;

				realizoCambioEnJuego = true;// Si jugador modifica el area de juego realizo un cambio correctamente y actualiza

			}
		}

		// Si el turno de eleccion es del jugador 2
		else if (turnoJugador2) {
			cout << "\n ----->2\n";

			// Verificamos que se pueda realizar la jugada pasando el numero de boton presionado y el tipo de jugador 
			// en este caso jugador 1 y la letra de seleccion con la que juega.
			if (ga.verificarPosibleJugadaModo1((numeroBotonSeleccionado - 1), 2, letraSeleccionadaJugador2, window)) {

				cout << "\n CAMBIO TURNOS AHORA LE TOCA JUGADOR 11!!\n";
				turnoJugador2 = false;
				turnoJugador1 = true;
				juegoModo1Empezo = true; // Si jugador modifica el area de juego realizo un cambio correctamente y actualiza
			}
		}

	}
	else {
		// No ha presinado un boton valido!
	}




}











void ventana::opcionesMenuJuego(sf::RenderWindow& window) {
	switch (m.GetPressedItem())
	{
	case 0:

		// Si el juego no ha comenzado entonces el menu de inicio esta activo
		// Selecciono modo de juego Jugador vs Juegador

		if (menuInicioActivo && comenzoJuego == false)
		{
			cout << "\n Selecciono tipo de juego jugador vs jugador! \n";

			// se cambia el estado del menuInicial a falso
			menuInicioActivo = false;
			// Se asigna el tipo de juego 1
			tipoJuego = "JugadorVsJugador";

		}
		// Falso ya se encuntra relizando una partida diferente de jugador vs jugador cambia a este tipo de juego

		else if (comenzoJuego == true && tipoJuego != "JugadorVsJugador") {
			cout << "\n Ha seleccionado cambiar de tipo de juego... \nCargando nuevo tipo de juego!\n";

			// se cambia el estado del menuInicial a falso
			menuInicioActivo = false;
			// Se asigna el tipo de juego 1
			tipoJuego = "JugadorVsJugador";
		}

		// Falso si el ya se elgio un tipo de partida pero el juego no ha comenzado
		// entonces se escucha el valor de seleccion del menu de letra de jugador 1
		else if (menuInicioActivo == false && comenzoJuego == false && jugador1Eligio == false) {

			// Se guarda el valor de tipo de letra de jugador 1 y su estado de eleccion pasa a verdadero
			letraSeleccionadaJugador1 = "jugadorX";
			jugador1Eligio = true;
			// Por defecto si jugador 1 escoge la letra X, la letra de ljugador 2 va hacer la letra "O"
			m.mostrarMenuSeleccionImgJugador2(1024.0f, 622.0f, 2);
			letraSeleccionadaJugador2 = "jugadorO";
		}

		// falso si ya se elegio el tipo de juego && jugador 1 ya elegio letra 
		// entonces escucha cuando jugador 2 da enter a la opcion disponile de eleccion!
		else if (menuInicioActivo == false && comenzoJuego == false && jugador1Eligio && jugador2Eligio == false) {

			// Se cambia el estado jugador2elgio a verdadero y la de comenzo juego a verdadero 
			// por que ya los dos jugadores elegieron la letra para coemnzar la partida.
			// tambine juegoEnPausa pasa a falso para comenzar a escuchar los enventos deñ mouse
			jugador2Eligio = true;
			comenzoJuego = true;
			juegoEnPausa = false;
		}


		break;
	case 1:
		// Si el juego no ha comenzado entonces el menu de inicio esta activo
		// Selecciono modo de juego Jugador vs CPU (Maquina)

		if (menuInicioActivo && comenzoJuego == false) {
			cout << "\n Selecciono tipo de juego jugador vs CPU! \n";
			// se cambia el estado del menuInicial a falso
			menuInicioActivo = false;
			// Se asigna el tipo de juego 1
			tipoJuego = "JugadorVsCPU";

		}

		// Falso ya se encuntra relizando una partida diferente de jugador vs jugador cambia a este tipo de juego
		else if (comenzoJuego == true && tipoJuego != "JugadorVsJugador") {
			cout << "\n Ha seleccionado cambiar de tipo de juego... \ncargando nuevo tipo de juego!\n";
			// se cambia el estado del menuInicial a falso
			menuInicioActivo = false;
			// Se asigna el tipo de juego 1
			tipoJuego = "JugadorVsCPU";
		}

		// Falso si el ya se elgio un tipo de partida pero el juego no ha comenzado
		// entonces se escucha el valor de seleccion del menu de letra de jugador 1
		else if (menuInicioActivo == false && comenzoJuego == false && jugador1Eligio == false) {

			// Se guarda el valor de tipo de letra de jugador 1 y su estado de eleccion pasa a verdadero
			letraSeleccionadaJugador1 = "jugadorO";
			jugador1Eligio = true;
			// Por defecto si jugador 1 escoge la letra O, la letra de ljugador 2 va hacer la letra "X"
			letraSeleccionadaJugador2 = "jugadorX";
			m.mostrarMenuSeleccionImgJugador2(1024.0f, 622.0f, 1);
		}




		break;
	case 2:

		if (comenzoJuego) {
			cout << "\n Gracias por jugar nuestro juego , esperamos que te hayas divertido!! \n¡Vuelve pronto!\n";
		}
		else {
			cout << "\n Selecciono la opcion de salir del juego.. \nAdios! \n";
		}
		window.close();
		break;
	}



}