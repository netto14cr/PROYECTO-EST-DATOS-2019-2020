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

// Se declara el uso de la clase menu
Menu m(1024, 622);
// Se declara el uso de la clase gato
gato ga;


// Metodo que da inicio a la interfaz del juego

void ventana::iniciarPrograma()
{
	// Se define la velocidad de actualizacion del frame en pantalla
	window.setFramerateLimit(30);
	// se realiza el llamado del metodo que maneja todos los eventos del juego mientras
	// la ventana del juego este abierta.
	manejoEventosJuego(window);

}

void ventana::verificaEstatusDelJuego(sf::RenderWindow& window) {
	//si el jugador 1 gano y el juego jugador vs jugador continua activo
   // actualiza el estado en la pantalla: Borra la matriz de botones y indica que 
   // jugador q ha ganado y pausa el juego.

	if (ga.GetGanadorJ1() && !juegoEnPausa) {
		window.clear();// Borra lo mostrado en pantallla
		// Dibuja el titulo del juego en pantalla
		ga.dibujarImagenEspecifica(window, 9);
		// Dibuja en pantalla ganador jugador 1
		ga.dibujarImagenEspecifica(window, 10);
		window.display();
		juegoEnPausa = true;// Si el juego ternimo se actualiza el estado de juego a pausado
	}

	// Falso si el jugador 2 gano y el juego jugador vs jugador continua activo
	// actualiza el estado en la pantalla: Borra la matriz de botones y indica que 
	// el jugador q ha ganado y pausa el juego.
	else if (ga.GetGanadorJ2() && !juegoEnPausa) {
		window.clear();// Borra lo mostrado en pantallla
		// Dibuja el titulo del juego en pantalla
		ga.dibujarImagenEspecifica(window, 9);
		// Dibuja en pantalla ganador jugador 2
		ga.dibujarImagenEspecifica(window, 11);
		window.display();
		// Si el juego ternimo se actualiza el estado de juego a pausado
		juegoEnPausa = true;
	}

	// Falso si se llego a la conclusion que ningun jugador gano en modo de juego jugador vs jugador y este continua 
	// continua activo actualiza el estado en la pantalla: Borra la matriz de botones y indica que 
	// el jugador q ha ganado y pausa el juego.
	else if (ga.GetNoGanadorFinal() && !juegoEnPausa) {
		window.clear();// Borra lo mostrado en pantallla
		// Dibuja el titulo del juego en pantalla
		ga.dibujarImagenEspecifica(window, 9);
		// Dibuja en pantalla que no hubo ganador , muestra img de empate
		ga.dibujarImagenEspecifica(window, 12);
		window.display();// actualiza cambios en pantalla
		// Si el juego ternimo se actualiza el estado de juego a pausado
		juegoEnPausa = true;
	}
}





//  Metodo que escucha todo lo que sucede y se ejecuta mientras la nueva ventana o el juego este en ejecucion
void ventana::manejoEventosJuego(sf::RenderWindow& window) {

	while (window.isOpen())
	{
		// Llamado al metodo que controlo los eventos del juego
		determinarTipoEvento(window);
		// Verifica si existe un ganador en el juego antes de continuar
		// actualizando los eventos por pantalla que pasan en el juego.
		verificaEstatusDelJuego(window);

		// <<<<<<<<		M O D O  J U G A D O R   V S   J U G A D O R		>>>>>>>>>>>>>>>>>

		// Si comenzo el juego y el tipo de juego es jugador vs jugador
		// actualizara los eventos en pantalla de este modo de juego en pantalla
		if (comenzoJuego && !juegoEnPausa && tipoJuego == "JugadorVsJugador") {
			window.clear();// Borra lo mostrado en pantallla
			// actualiza 
			actualizaEstadoImgJugador();
			// actualiza los botones de la matriz de juego modo jugador vs jugador
			ga.actualizaMatrizMod1(window);
			// Se resetea el valor para que este este a la espera de un nuevo cambio..
			realizoCambioEnJuego = false;

		}//	>>>>>>>	  F I N  M O D O  J U G A D O R  V S  J U G A D O R       >>>>>>>>>>>>>>>>>>>>>

		//--------------------------------------------------------------------------------------------

		// <<<<<<<<		M O D O  J U G A D O R   V S  C P U		>>>>>>>>>>>>>>>>>

		// Falso si menuInicial y comenzo es falso && subMenuNivel esta activo
		// se muestran las opciones para elegir de tipo de dificultal de niveles al jugador!
		else if (!menuInicioActivo && !comenzoJuego && subMenuNivelActivo) {
			window.clear();// Borra lo mostrado en pantallla
			// Dibuja la imgen del nombre del juego en pantalla
			ga.dibujarImagenEspecifica(window, 1);
			// Dibuja el sub menu de seleccion de niveles en pantalla
			m.dibujarSubMenuSeleccionNiveles(window);
		}
		// Falso si juego modo jugador vs cpu ya no esta en pausa y comenzo 
		// Se actualizan los eventos en pantalla del juego segun el nivel escogido.
		else if (comenzoJuego && !juegoEnPausa && tipoJuego == "JugadorVsCPU") {
			window.clear(); // Borra lo mostrado en pantallla

			// Actualiza y muestra la imgen del turno de jugador en pantalla
			actualizaEstadoImgJugador();

			// Actualiza si la dificultad elegida es facil
			if (dificultad == "facil") {
				cout << "\nENTRO EN MODO DE JUGO    F A C I L \n";
				// actualiza los botones de la matriz de juego modo facil::jugador vs CPU
				ga.actualizaMatrizNivelFacil(window);
			}

			// Actualiza la dificultad del nivel normal
			else if (dificultad == "medio") {
				cout << "\nENTRO EN MODO DE JUGO    N O R M A L \n";
				// actualiza los botones de la matriz de juego modo normal::jugador vs CPU
				ga.actualizaMatrizNivelMedio(window);
			}
			// Actualiza la dificultad del nivel dificil
			else if (dificultad == "dificil") {
				cout << "\nENTRO EN MODO DE JUGO    D I F I C I L \n";
				// actualiza los botones de la matriz de juego modo dificil::jugador vs CPU
				ga.actualizaMatrizNivelDificil(window);
			}

			window.display(); // actualiza cambios en pantalla
		}//	>>>>>>>		F I N   M O D O  J U G A D O R  V S  C P U 		>>>>>>>>>>>>>>>>>>>>>>>>>>>>
		//------------------------------------------------------------------------------------------


		// <<<<<<<<		M E N U  S E L E C C I O N  L E T R A   J U G A D O R  >>>>>>>>>>>>>>>>>

	   // Falso si ya se eligio un tipo de juego pero no ha comenzado el juego se mostrara el menu 
	   // para que el jugador 1 seleccionen el tipo de letra para jugar.
		else if (!menuInicioActivo && !comenzoJuego) {
			window.clear(); // Limpia el contenido de la ventana mostrado
			// Dibuja la img del nombre del juego en pantalla
			ga.dibujarImagenEspecifica(window, 1);

			// Si jugador 1 no ha elegido letra dibuja en pantalla las imagenes 
			// y menu de seleccion de letra de jugador 1 
			if (!jugador1Eligio) {
				// Dibuja la img de la letra X en pantalla
				ga.dibujarImagenEspecifica(window, 2);
				// Dibuja la img de la letra O en pantalla
				ga.dibujarImagenEspecifica(window, 3);
				// Dibujara el turno de seleccion del jugador 1 en pantalla
				ga.dibujarImagenEspecifica(window, 4);
				// Dibuja el menu de seleccion de jugador 1 en pantalla
				m.dibujarMenuSeleccionJugador1(window);
			}

			// Falso si jugador 2 no ha elegido y es en el modo de juego jugador vs jugador
			// Se le mostraran las imagenes y el menu de seleccion que puede elegir de acuerdo
			// a la eleccion previa realizada por el juego 1

			// Nota: Solo en modo de juego jugador vs jugador se muestra esta opcion por que
			// en modo de juego vs CPU la maquina escoge automaticamente despues de rezliar 
			//la eleccion jugador 1 y no se ocupa mostrar por pantalla su actualizacion de esa
			// accion.
			else if (!jugador2Eligio && tipoJuego == "JugadorVsJugador") {
				if (letraSeleccionadaJugador2 == "jugadorO") {

					// Dibuja la letra O en una posicion diferente
					ga.dibujarImagenEspecifica(window, 6);
				}
				else if (letraSeleccionadaJugador2 == "jugadorX") {
					// Dibuja la letra X en una posicion diferente
					ga.dibujarImagenEspecifica(window, 2);
				}
				// Dibuja la img de turno de seleccion del juegador 2
				ga.dibujarImagenEspecifica(window, 5);
				// Dibuja el menu de seleccion de jugador 2
				m.dibujarMenuSeleccionJugador2(window);
			}
		}// >>>>>>>>	F I N  M E N U  S E L E C C I O N  L E T R A   J U G A D O R  >>>>>>>>>>>>>>>>>
		//------------------------------------------------------------------------------------------

		// <<<<<<<<<<<<<<<<<		M E N U  I N I C I A L		 >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

		// Falso si menuInicio esta activo muestra las opciones del menu principal de 
		// juego hasta que el jugador seleccione un tipo de partida
		else if (menuInicioActivo) {
			window.clear();// Limpia el contenido de la ventana mostrado
			// Dibuja la img de nombre del juego en pantalla
			ga.dibujarImagenEspecifica(window, 1);
			// Dibuja el menu inicial mostrado al principio o en pausa del juego
			m.dibujarMenuInicial(window);
		}// >>>>>>>>>>>>>>>>		F I N  M E N U  I N I C I A L		>>>>>>>>>>>>>>>>>>>>

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
			system("cls");
			cout << "\nRealizo la accion de cerrar la ventana de juego! \n\n";

			// Detiene el sonido del juego cuando se cirra el juego
			//ga.detenerSonido();
			break;


		case sf::Event::MouseMoved:
			// Valida de caso para evento de mouse encima de un boton si estan jugando
			if (comenzoJuego && !juegoEnPausa) {
				// Llama al metodo que comprueba si el mause se encuntra 
				//  encima de un boton del juego.
				ga.pintarColorBotonEncima(window);
			}
			break;
			// Validacion de boton presionado por el usuario (click)
		case sf::Event::MouseButtonPressed:
			// LLama al metodo que comprueba cual boton fue presionado por el usuario
			if (comenzoJuego && !juegoEnPausa) {
				ga.accionSeleccionarBoton(window, numeroJugador);
				opcionesBotonesJuegoModo1(window);
			}
			break;

			// Validacion del evento por teclado presionadas por el usuario
		case sf::Event::KeyReleased:
			switch (event.key.code)
			{
				// Presiono tecla de arriba
			case sf::Keyboard::Up:
				system("cls");
				cout << "\n ::  A R R I B A  ::\n";

				// Mueve arriba Si menu inicial o sub menu de niveles esta activo
				// Si el menu inicial esta activo mueve entre la opciones del menu.
				if (menuInicioActivo && !subMenuNivelActivo) {
					m.moveUpMenu(1);
					//ga.reproducirSonido(2);
				}

				// Falso si el sub menu de niveles esta activo navega entre la opciones del menu. 
				else if (!menuInicioActivo && subMenuNivelActivo) {
					m.moveUpMenu(2);
				}
				// Falso si el menuInicial && sub menu de niveles estan falsos
				// llama al metodo de mover entre dos opciones de menu.
				else if (!menuInicioActivo && !subMenuNivelActivo) {

					// Si el jugador 1 no ha elegido 
					// llama al metodo que mueve hacia arriba en la seleccion del jugador 1
					if (!jugador1Eligio) {
						m.moveUpSeleccionJugador(1);
					}

					// Falso si jugador 1 ya eligio y jugador 2 aun no lo ha hecho 
					// llama al metodo que mueve hacia arriba en la selecion del jugador 2
					else if (jugador1Eligio && !jugador2Eligio) {
						m.moveUpSeleccionJugador(2);
					}

				}

				break;


				//  Presiono tecla de abajo
			case sf::Keyboard::Down:
				system("cls");
				cout << "\n::  A B A J O  ::\n";

				// Mueve hacia abajo Si menu inicial o sub menu de niveles esta activo
				// Si el menu inicial esta activo mueve entre la opciones del menu.
				if (menuInicioActivo && !subMenuNivelActivo) {
					m.moveDownMenu(1);
					//ga.reproducirSonido(2);
				}

				// Falso si el sub menu de niveles esta activo navega entre la opciones del menu. 
				else if (!menuInicioActivo && subMenuNivelActivo) {
					m.moveDownMenu(2);
				}
				// Falso si el menuInicial && sub menu de niveles estan falsos
				// llama al metodo de mover entre dos opciones de menu.
				else if (!menuInicioActivo && !subMenuNivelActivo) {

					// Si el jugador 1 no ha elegido 
					// llama al metodo que mueve hacia abajo en la seleccion del jugador 1
					if (!jugador1Eligio) {

						m.moveDownSeleccionJugador(1);
					}
					// Falso si jugador 1 ya eligio y jugador 2 aun no lo ha hecho 
						// llama al metodo que mueve hacia abajo en la selecion del jugador 2
					else if (jugador1Eligio && !jugador2Eligio) {
						m.moveDownSeleccionJugador(2);
					}
				}
				break;


			case sf::Keyboard::Return:

				// Si el juego se encuntra en pausa se escuhan los eventos que pasan entre 
				// los menus que se muestran en pantalla y las elecciones del usuario en ellos.
				if (juegoEnPausa == true) {
					opcionesMenuJuego(window);
				}

				// Falso si el juego no se encuentra en pausa y se esta realizando una partida
				// Determinara las acciones que pasen en cada tipo de juego del usuario
				else if (!juegoEnPausa && comenzoJuego) {

					// Si el tipo de juego es el primero Jugador vs Jugador
					if (tipoJuego == "JugadorVsJugador") {
						// Llama al metodo que se encarga de manejar lo que ocurre en el juego
						// jugador vs jugador
						opcionesBotonesJuegoModo1(window);
					}
					else if (tipoJuego == "JugadorVsCPU") {

					}
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


// Metodo que escuha las opciones del menu mostradas a los juegores ne pantalla y
// determina el tipo de acccion seleccionada por los  usuarios segun sea el caso.
void ventana::opcionesMenuJuego(sf::RenderWindow& window) {
	switch (m.GetPressedItem())
	{
	case 0:
		// -------------	M E N U  D E  J U E G O   E S T A   A C T I V O		-----------------------
				// Si menu de Inicio esta Activo es verdadero 

		if (menuInicioActivo) {

			// Si comenzo un juego es falso y la opcion escogida es cero
			// se cambia el estado de menuInicio a falso para que el juego seguidamente 
			// ponga a los jugadores a elegir
			if (!comenzoJuego) {
				cout << "\n Selecciono tipo de juego jugador vs jugador! \n";
				// se cambia el estado del menuInicial a falso
				menuInicioActivo = false;
				// Se asigna el tipo de juego 1
				tipoJuego = "JugadorVsJugador";
			}
			// Falso si se encentra jugadondo contra la maquina y selecciona 
			// la opcion 1 de jugador vs jugador reiniciara el juego y cargara
			// el otro tipo de juego.

			else if (comenzoJuego && tipoJuego != "JugadorVsJugador") {
				cout << "\n Ha seleccionado cambiar de tipo de juego... \nCargando nuevo tipo de juego!\n";
				// se cambia el estado del menuInicial a falso
				menuInicioActivo = false;
				// Se asigna el nuevo tipo de juego selecionado
				tipoJuego = "JugadorVsJugador";
				// Se cambia el estado de juega maquina a falso
				juegaMaquina = false;
			}
		}// TERMNINA MENU DE JUEGO INICIAL ACTIVO


		// -------		M E N U  D E  J U E G O   N O   E S T A  A C T I V O		--------------------

		// Falso si menu de inicio && sub menu de nivel estan en estaod falso
		// Entonces quiere decir que se estan seleccionando las letras de los jugadores
		else if (!menuInicioActivo && !subMenuNivelActivo) {


			// Si no ha comenzado el juego y la sleccion es 0
			if (!comenzoJuego) {

				// Si jugador 1 no ha elegido entonces se interpreta a que el usuario
				//esta escogiendo la letra X para jugar
				if (!jugador1Eligio) {
					// Se guarda el valor de tipo de letra de jugador 1
					letraSeleccionadaJugador1 = "jugadorX";

					// El estado de eleccion de jugador1 pasa a verdadero
					jugador1Eligio = true;

					// Por defecto si jugador 1 escoge la letra X, la letra del 
					// jugador 2 va hacer la letra "O"
					m.mostrarMenuSeleccionImgJugador2(1024, 622, 2);
					letraSeleccionadaJugador2 = "jugadorO";

					// Si se esta jugando contra la maquina se da por hecho que la maquina
					// eligio ya que ella escoge siempre el tipo de letra restante despues
					// que el jugador eligio y con esto se salta la confirmacion en el mnu de 
					// letra de ella misma.

					if (juegaMaquina == true) {
						verificacionJugadorLetra();
					}
				}
				// Falso si se selecciono la opcion 1 de nuevo despues de elegir 
				// la letra el jugaodor 1, se interpreta que el jugador 2 elegio 
				// la letra disponible que seria la letra O.
				else if (jugador1Eligio) {
					// Se cambia el estado jugador2elgio a verdadero y la de comenzo juego a verdadero 
			// por que ya los dos jugadores elegieron la letra para coemnzar la partida.
			// tambine juegoEnPausa pasa a falso para comenzar a escuchar los enventos deñ mouse

					verificacionJugadorLetra();
				}
			}
		}// TERMINA MENU DE JUEGO NO ESTA ACTIVO


		// -------		S U B  M E N U  E S T A  A C T I V O		--------------------

		// Falso si menu inicial esta en estado falso y subMenuNivelActivo quiere decir
		// que se esta seleccionando los niveles de juego jugador vs CPU y que
		// el usuario quiso jugar en el modo de juuego facil.
		else if (!menuInicioActivo && subMenuNivelActivo) {
			// Se asigna el tipo de dificulta al elegir la opcion 2 - Facil
			dificultad = "facil";
			// Cambia el estado de subMenuNivel a falsa para que se le muestra al usuario
			// las opciones de seleccion de letra con la que jugara.
			subMenuNivelActivo = false;
		}
		// TERMINA SUB MENU DE NIVEL ACTIVO

		break;
	case 1:

		// -------------	M E N U  D E  J U E G O   E S T A   A C T I V O		-----------------------
		// Si menu de Inicio esta Activo es verdadero 		

		if (menuInicioActivo) {

			// Quiere decir que el usuario ha selecciono modo de juego Jugador vs CPU (Maquina)
			if (!comenzoJuego) {
				cout << "\n Selecciono tipo de juego jugador vs CPU! \n";
				// se cambia el estado del menuInicial a falso
				menuInicioActivo = false;
				// Se asigna el tipo de juego 1 -- Juagador VS CPU
				tipoJuego = "JugadorVsCPU";
				// Activa el menu secundario de modo jugador vs CPU
				subMenuNivelActivo = true;
				// Se cambia el estado de juega maquina a verdadero
				juegaMaquina = true;
			}

			// Falso si se encuentra jugadondo contra otro jugador y selecciona 
			// la opcion 2 de jugador vs CPU reiniciara el juego y cargara
			// el otro tipo de modo de juego.
			else if (comenzoJuego && tipoJuego != "JugadorVsCPU") {
				cout << "\n Ha seleccionado cambiar de tipo de juego... \nCargando nuevo tipo de juego!\n";
				// se cambia el estado del menuInicial a falso
				menuInicioActivo = false;
				// Se asigna el nuevo tipo de juego selecionado jugador vs cpu
				tipoJuego = "JugadorVsCPU";
				// Se cambia el estado de juega maquina a falso
				juegaMaquina = true;
			}

		}// TERMNINA MENU DE JUEGO INICIAL ACTIVO


		// ----	M E N U  D E  J U E G O  && S U B M E N U  N O  E S T A   A C T I V O		----------------

		// Falso si menu de inicio y sub menu de juego es falso
		// Quiere decir que los jugadores estan eligiendo con que letra jugar
		else if (!menuInicioActivo && !subMenuNivelActivo) {

			// Si jugador 1 no ha elegido entonces se interpreta a que el usuario
			// esta escogiendo la letra O para jugar.
			if (!jugador1Eligio) {
				// Se guarda el valor de tipo de letra de jugador 1
				letraSeleccionadaJugador1 = "jugadorO";

				// El estado de eleccion de jugador1 pasa a verdadero
				jugador1Eligio = true;

				// Por defecto si jugador 1 escoge la letra O, la letra del 
				// jugador 2 va hacer la letra "X"
				m.mostrarMenuSeleccionImgJugador2(1024, 622, 1);
				letraSeleccionadaJugador2 = "jugadorX";

				// Si se esta jugando contra la maquina se da por hecho que la maquina
				// eligio ya que ella escoge siempre el tipo de letra restante despues
				// que el jugador eligio y con esto se salta la confirmacion en el mnu de 
				// letra de ella misma.

				if (juegaMaquina == true) {
					verificacionJugadorLetra();
				}
			}

			// Falso si se selecciono la opcion 2 de nuevo despues de elegir 
			// la letra el jugaodor 1, se interpreta que el jugador 2 elegio 
			// la letra disponible que seria la letra O.
			else if (jugador1Eligio) {
				// Se cambia el estado jugador2 eligio a verdadero y la variable de 
				// comenzo juego a verdadero por que ya los dos jugadores elegieron la letra 
				// para comenzar la partida, tambien la de juegoEnPausa pasa a falso 
				// para comenzar a escuchar los enventos del mause

				verificacionJugadorLetra();

			}
		}// TERMINA MENU INCIAL && SUB MENU NO ESTA ACTIVO


			// -------		S U B  M E N U  E S T A  A C T I V O		--------------------

		// Falso si menu inicial esta en estado falso y subMenuNivelActivo quiere decir
		// que se esta seleccionando los niveles de juego jugador vs CPU y que
		// el usuario quiso jugar en el modo de juuego normal.
		else if (!menuInicioActivo && subMenuNivelActivo) {

			// Se asigna el tipo de dificulta al elegir la opcion 2 - Normal
			dificultad = "medio";
			// Cambia el estado de subMenuNivel a falsa para que se le muestra al usuario
			// las opciones de seleccion de letra con la que jugara.
			subMenuNivelActivo = false;

		}
		// TERMINA SUB MENU DE NIVEL ACTIVO

		break;
	case 2:

		// Si el menu de inicio esta activo quiere decir que usuario ha elegido la opcion de salir
		if (menuInicioActivo) {

			// Se verifica si el jugador estaba jugando previamente y se le muestra un
			// mensaje personalizado dependiendo de esto.


			// El jugador tenia un juego empezado pero decidio dar pausa y eligio salir
			if (comenzoJuego) {
				cout << "\n Gracias por jugar nuestro juego , esperamos que te hayas divertido!! \n¡Vuelve pronto!\n";
			}

			// Falso jugador no ha empenzado el juego y decide salir!
			else if (!comenzoJuego) {
				cout << "\n Selecciono la opcion de salir del juego.. \nAdios! \n";
			}
			window.close();
		}

		// -------		S U B  M E N U  E S T A  A C T I V O		--------------------

	// Falso si menu inicial esta en estado falso y subMenuNivelActivo quiere decir
	// que se esta seleccionando los niveles de juego jugador vs CPU y que
	// el usuario quiso jugar en el modo de juuego dificil.
		else if (!menuInicioActivo && subMenuNivelActivo) {
			// Se asigna el tipo de dificulta al elegir la opcion 2 - Normal
			dificultad = "dificil";

			// Cambia el estado de subMenuNivel a falsa para que se le muestra al usuario
			// las opciones de seleccion de letra con la que jugara.
			subMenuNivelActivo = false;
		}
		// TERMINA SUB MENU DE NIVEL ACTIVO

		break;
	}

}


// Metodo que verifica si el jugador 2 selecciono su eleccion y comienza el juego, saliendo asi 
// del menu mostrado en pantallapara seguidamente mostrar la matriz de juego.
void ventana::verificacionJugadorLetra() {
	// Se cambia el estado de jugador 2 elegio a verdadero
	jugador2Eligio = true;

	// El estado de comenzo juego a verdadero para que inicie y se 
	// muestren la matriz y desaparescan los menus en pantalla
	comenzoJuego = true;

	// Juego en pausa a false para que se dejen de escuchar los eventos 
	// de las opciones de menu de juego.
	juegoEnPausa = false;
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







