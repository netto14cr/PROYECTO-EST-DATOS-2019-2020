#include "ventana.h"




// Declaro el uso de la clase sokoban
sokoban sk;
ListaEnlazada list;
Archivo ar;
NodoLista* inicio;
sf::RenderWindow window(sf::VideoMode(1000, 600), "Sokoban");

Menu m(window.getSize().x, window.getSize().y);

ventana::ventana() {

}


ventana::~ventana() {

}
//	Metodo que se manejan todos los eventos de manejo del juego iniciales.

void ventana::determinarMedidasPantalla(sf::RenderWindow& window) {

	if (nivelSeleccionado == 1) {
		//sf::RenderWindow(sf::VideoMode(800, 300), "Sokoban");
		window.setSize(sf::Vector2u((1300), 768));
		//ar.leerArchivosDeNiveles(ar.seleccionNivel(nivelSeleccionado), list, inicio);
	}

	else if (nivelSeleccionado == 2) {
		//sf::RenderWindow(sf::VideoMode(800, 300), "Sokoban");
		window.setSize(sf::Vector2u((1300), 768));
		//ar.leerArchivosDeNiveles(ar.seleccionNivel(nivelSeleccionado), list, inicio);
	}
	else if (nivelSeleccionado == 3) {
		window.setSize(sf::Vector2u((1300), 768));
		//window.setPosition(sf::Vector2i(50, 50));
	}
	else if (nivelSeleccionado == 4) {

		window.setSize(sf::Vector2u((1300), 768));
		//window.setPosition(sf::Vector2i(100,100));
	}

}


void ventana::playGame() {

	inicio = nullptr;
	ar.leerArchivosDeNiveles(ar.seleccionNivel(nivelSeleccionado), list, inicio);
	sk.cargarSonidos();
	sk.reproducirSonido(1);
	//determinarMedidasPantalla(window);
	window.setFramerateLimit(30);
	manejoEventosTeclado(window);
}




void ventana::teclado(sf::RenderWindow& window, NodoLista* &tx) {
	sf::Event event;
	while (window.pollEvent(event))
	{


		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			sk.detenerSonido();
			break;

		case sf::Event::KeyReleased:
			switch (event.key.code)
			{
			case sf::Keyboard::Up:
				system("cls");
				cout << "Arriba\n";

				if (menuEstaActivo) {
					m.MoveUp();
					sk.reproducirSonido(2);
				}
				 else if (estaJugando) {
					list.movimientoJugadorArriba(tx); //	Mueve hacia arriba
					realizoUnMovimiento = true;
				}
				break;

			case sf::Keyboard::Down:
				system("cls");
				cout << "Abajo\n";
				if (menuEstaActivo) {
					m.MoveDown();
					sk.reproducirSonido(2);
				 }
				 else if (estaJugando) {
					list.movimientoJugadorAbajo(tx);
					realizoUnMovimiento = true;
				}
				break;

			case sf::Keyboard::Right:
				system("cls");
				cout << "Derecha\n";
				if (menuEstaActivo) {
					//	Menu no tiene movimiento a la derecha
				}
				else if (estaJugando) {

					list.movimientoJugadorDerecha(tx); //	Mueve hacia la derecha
					realizoUnMovimiento = true;
				}
				break;

			case sf::Keyboard::Left:
				system("cls");
				cout << "Izquierda\n";
				if (menuEstaActivo) {
					// Menu no tiene movimiento a la izquierda
				}
				else if (estaJugando) {
					list.movimientoJugadorIzquierda(tx); // Mueve hacia la izquierda
					realizoUnMovimiento = true;
				}
				break;



				//	Evento tecla escape: Esta detecta cuando un juegador la presiona y activa
				//	la pausa del juego y cambia los estados del mismo. 
			case sf::Keyboard::Escape:
				if (comenzoJuego!=false) {
					if (estaJugando == true) {

						sk.detenerSonido();
						sk.reproducirSonido(2);
						sk.reproducirSonido(1);
						cout << "\n Juego en pausa! \n";
						estaJugando = false;
						menuEstaActivo = true;
					}
					else if (estaJugando==false){
						cout << "\n Ha seleccionado despausar juego \n";
						estaJugando = true;
						menuEstaActivo = false;
						sk.detenerSonido();
						sk.reproducirSonido(3);
					}
				}
				break;

			case sf::Keyboard::Return:

				switch (m.GetPressedItem())
				{
				case 0:
				
					// realizo una pausa durante el juego y selecciona iniciar juego se 
					// le indica que ya tiene uno iniciado
					if (comenzoJuego==false) {
						cout << "\n Ha comenzado un nuevo juego! \n";
						nivelSeleccionado = 1;
						inicializarJuego(nivelSeleccionado);
						estaJugando = true;
						comenzoJuego = true;
						menuEstaActivo = false;
					}
					else {
						if (comenzoJuego == true && nivelSeleccionado == 1) {
							cout << "\n No se puede cargar el nivel porque ya se encuentra jugando el mismo! \n";
						}
						else if (comenzoJuego == true && nivelSeleccionado != 1) {
							cout << "\n Cambio al nivel 1 \n";
							nivelSeleccionado = 1;
							inicializarJuego(nivelSeleccionado);
						}
						estaJugando = true;
						menuEstaActivo = false;

						sk.detenerSonido();
						sk.reproducirSonido(3);
					}
						break;
				case 1:
					cout << "\n No intente esta opcion porque no se programo!! \n";
					break;


				case 2:
					
					if (comenzoJuego != false) {
						cout << "\n Se ha seleccionado reiniciar el nivel! \n";

						inicializarJuego(nivelSeleccionado);
						estaJugando = true;
						menuEstaActivo = false;
					}
					else {
					cout << "\n Ha fallado la opcion de reiniciar nivel , esto se debe a que no esta ha comenzado ninguna partida! \n";
					}
					break;

				case 3:
					
					
					if (comenzoJuego == false) {
					cout << "\nSe ha seleccionado el nivel 2! \n";
					nivelSeleccionado = 2;
					inicializarJuego(nivelSeleccionado);
					estaJugando = true;
					comenzoJuego = true;
					menuEstaActivo = false;

					}
					else {
						if (comenzoJuego == true && nivelSeleccionado == 2) {

							cout << "\n No se puede cargar el nivel porque ya se encuentra jugando el mismo! \n";
						}
						else if (comenzoJuego == true && nivelSeleccionado != 2) {
							cout << "\n Cambio al nivel 2 \n";
							nivelSeleccionado = 2;
							inicializarJuego(nivelSeleccionado);
						}
						estaJugando = true;
						menuEstaActivo = false;
						sk.detenerSonido();
						sk.reproducirSonido(3);
					}
					break;

				case 4:
					if (comenzoJuego == false) {
						cout << "\n Se ha seleccionado el nivel 3! \n";
						nivelSeleccionado = 3;
						inicializarJuego(nivelSeleccionado);
						estaJugando = true;
						comenzoJuego = true;
						menuEstaActivo = false;
					}
					else {
						if (comenzoJuego == true && nivelSeleccionado == 3) {
							cout << "Ya tiene una partida iniciada!" << endl;
						}
						else if (comenzoJuego == true && nivelSeleccionado != 3) {
							cout << "\n Cambio al nivel 3 \n";
							nivelSeleccionado = 3;
							inicializarJuego(nivelSeleccionado);
						}
						estaJugando = true;
						menuEstaActivo = false;
						sk.detenerSonido();
						sk.reproducirSonido(3);
					}
					break;


				case 5:
					
					if (comenzoJuego == false) {
						cout << "\nSe ha seleccionado el nivel 4! \n";
						nivelSeleccionado = 4;
						inicializarJuego(nivelSeleccionado);
						estaJugando = true;
						comenzoJuego = true;
						menuEstaActivo = false;
					}
					else {
						if (comenzoJuego == true && nivelSeleccionado == 4) {
							cout << "Ya tiene una partida iniciada!" << endl;

						}
						else if (comenzoJuego == true && nivelSeleccionado != 4) {
							cout << "\n Cambio al nivel 4 \n";
							nivelSeleccionado = 4;
							inicializarJuego(nivelSeleccionado);
						}
						estaJugando = true;
						menuEstaActivo = false;
						sk.detenerSonido();
						sk.reproducirSonido(3);
					}
					break;

				case 6:
					std::cout << "Boton de cerrar ventaja de juego!" << std::endl;
					window.close();
					sk.detenerSonido();
					break;
				}
				
			}
		}

	}

}



void ventana::manejoEventosTeclado(sf::RenderWindow& window) {

	NodoLista* tx = nullptr;
	//	Cliclo mientras la ventana esta activa.......
	while (window.isOpen())
	{
		tx = list.posicionJugador(inicio);
		teclado(window, tx); // Control de eventos de las teclas de las teclas

		if (estaJugando && realizoUnMovimiento) {
			
			sk.dibCambioMovSokoban(window, inicio);
			realizoUnMovimiento = false;
		}
		else if (estaJugando) {
			sk.dibujarMapa(window); // llama a la clase del juego.
		}
		else if (menuEstaActivo) {
			m.draw(window);
		}
	}
}



void ventana::inicializarJuego(int nivel) {

	window.clear();
	sk.detenerSonido();
	sk.reproducirSonido(3);
	inicio = nullptr;
	determinarMedidasPantalla(window);
	ar.leerArchivosDeNiveles(ar.seleccionNivel(nivel), list, inicio);
	sk.actualizarDatosMatriz(inicio);
	sk.cargaDeTexturasJuego();


}



