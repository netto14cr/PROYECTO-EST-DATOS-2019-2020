
// menu.cpp
// Autores: Kislev Aleman, Josua Esquivel y Néstor Leiva
// Descripcion: Implementacion de la clase menu

#include "Menu.h"

Menu::Menu(float width, float height)
{

	// Se realiza una carga previa de los metodos de los diferentes para que se escriban y
	// se guarden sus valores respectivos.
	cargarFuentes();
	mostrarMenuInicial(width, height);
	mostrarMenuSeleccionImgJugador1(width, height);
	mostrarMenuSeleccionImgJugador2(width, height, 0);
	mostrarSubMenuNiveles(width, height);
}

// Metodo que muestra en forma de menu inicial las opciones de tipo de juego en el program
void Menu::mostrarMenuInicial(float width, float height) {
	cout << "Mostrando menu inicial!! \n";

	// Creacion de las opciones del menu mostradas al inicio y en la pausa del juego.
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Cyan);
	menu[0].setString("Jugador vs Jugador");
	menu[0].setPosition(sf::Vector2f(width / 3.0f, height / (MAXIMO_OPCIONES + 1) * 2.0f));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Jugador vs CPU");
	menu[1].setPosition(sf::Vector2f(width / 3.0f, height / (MAXIMO_OPCIONES + 1) * 2.5f));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Salir del juego");
	menu[2].setPosition(sf::Vector2f(width / 3.0f, height / (MAXIMO_OPCIONES + 1) * 3.0f));
	selectedItemIndex = 0;
}

// Metodo que muestra en forma de menu la seleccion de letra del jugador 1
void Menu::mostrarMenuSeleccionImgJugador1(float width, float height) {
	// Creacion de las opciones del menu mostradas al inicio y en la pausa del juego.
	menuSeleccionJugador1[0].setFont(font);
	menuSeleccionJugador1[0].setFillColor(sf::Color::Cyan);
	menuSeleccionJugador1[0].setString("Seleccionar letra X");
	menuSeleccionJugador1[0].setPosition(sf::Vector2f(width / 3.5f, height / (MAXIMO_OPCIONES + 1) * 2.1f));

	menuSeleccionJugador1[1].setFont(font);
	menuSeleccionJugador1[1].setFillColor(sf::Color::White);
	menuSeleccionJugador1[1].setString("Seleccionar letra O");
	menuSeleccionJugador1[1].setPosition(sf::Vector2f(width / 3.5f, height / (MAXIMO_OPCIONES + 1) * 3.0f));
	selectedItemIndex = 0;
}

// Metodo que muestra en forma de menu la seleccion de letra del jugador 2
void Menu::mostrarMenuSeleccionImgJugador2(float width, float height, int seleccionJugador1) {
	// Creacion de las opciones del menu mostradas al inicio y en la pausa del juego.

	// Si jugador 1 selecciono la letra "X"
	if (seleccionJugador1 == 1) {
		menuSeleccionJugador2[0].setFont(font);
		menuSeleccionJugador2[0].setFillColor(sf::Color::Cyan);
		menuSeleccionJugador2[0].setString("Seleccionar letra X");
		menuSeleccionJugador2[0].setPosition(sf::Vector2f(width / 3.5f, height / (MAXIMO_OPCIONES + 1) * 2.1f));
	}
	// Falso si la seleccion del jugador 1 es la letra "O"
	else if (seleccionJugador1 == 2) {
		menuSeleccionJugador2[0].setFont(font);
		menuSeleccionJugador2[0].setFillColor(sf::Color::Cyan);
		menuSeleccionJugador2[0].setString("Seleccionar letra O");
		menuSeleccionJugador2[0].setPosition(sf::Vector2f(width / 3.5f, height / (MAXIMO_OPCIONES + 1) * 2.1f));
	}
	selectedItemIndex = 0;
}

// Metodo que se encarga de dibujar y posicionar las tres opciones de nivel a escoger contra la maquina
void Menu::mostrarSubMenuNiveles(float width, float height) {

	// Creacion de las opciones del sub menu mostrados despues que el usuario 
	// eliga la opcion de enfrentarse a la maquina ,dibuja nivel facil, medio y dificl. 
	menuSubNiveles[0].setFont(font);
	menuSubNiveles[0].setFillColor(sf::Color::Cyan);
	menuSubNiveles[0].setString("Nivel facil");
	menuSubNiveles[0].setPosition(sf::Vector2f(width / 2.5f, height / (MAXIMO_OPCIONES + 1) * 2.0f));

	menuSubNiveles[1].setFont(font);
	menuSubNiveles[1].setFillColor(sf::Color::White);
	menuSubNiveles[1].setString("Nivel normal");
	menuSubNiveles[1].setPosition(sf::Vector2f(width / 2.5f, height / (MAXIMO_OPCIONES + 1) * 2.5f));

	menuSubNiveles[2].setFont(font);
	menuSubNiveles[2].setFillColor(sf::Color::White);
	menuSubNiveles[2].setString("Nivel dificil");
	menuSubNiveles[2].setPosition(sf::Vector2f(width / 2.5f, height / (MAXIMO_OPCIONES + 1) * 3.0f));
	selectedItemIndex = 0;
}

// Metodo que se encarga de mostrar y de cargar los atributos del menuJuego2 , menu que se 
// muestra durante una pausa en el juego en media partida. 
void Menu::mostrarMenuJuego2(float width, float height) {
	// Creacion de las opciones del menu que se mostraran si el usuario pausa el juego en 
	// medio de una partida empezada!
	menuJuego2[0].setFont(font);
	menuJuego2[0].setFillColor(sf::Color::Cyan);
	menuJuego2[0].setString("Reiniciar nivel");
	menuJuego2[0].setPosition(sf::Vector2f(width / 3.0f, height / (MAXIMO_OPCIONES + 1) * 2.0f));

	menuJuego2[1].setFont(font);
	menuJuego2[1].setFillColor(sf::Color::White);
	menuJuego2[1].setString("Volver a menu principal");
	menuJuego2[1].setPosition(sf::Vector2f(width / 3.0f, height / (MAXIMO_OPCIONES + 1) * 2.5f));

	menuJuego2[2].setFont(font);
	menuJuego2[2].setFillColor(sf::Color::White);
	menuJuego2[2].setString("Salir sin terminar la partida");
	menuJuego2[2].setPosition(sf::Vector2f(width / 3.0f, height / (MAXIMO_OPCIONES + 1) * 3.0f));
	selectedItemIndex = 0;
}

// Metodo que realiza la carga del tipo de fuente utilizado para mostrar la letra del menu
void Menu::cargarFuentes() {
	if (!font.loadFromFile(DIR_FUENTES))
	{
		// Mostrar un error si existiera a la hora de carga las fuestes.
		cout << "Existe un error al cargar el tipo de letra." << endl;
	}
	else {
		//cout << "Carga de fuentes exitozamente!! \n";
	}
}

Menu::~Menu() {} // Destructor de la clase menu

//	Metodo que se encarga de mostrar las opciones dibujadas del menu.
void Menu::dibujarMenuInicial(sf::RenderWindow& window)
{
	for (int i = 0; i < MAXIMO_OPCIONES; i++)
	{
		window.draw(menu[i]);
	}

	window.display(); // actualiza la ventana del juego
}

//	Metodo que se encarga de mostrar las opciones a escoger letra del menu jugador 1.
void Menu::dibujarMenuSeleccionJugador1(sf::RenderWindow& window)
{

	for (int i = 0; i < MAXIMO_OPCIONES_JUGADOR1; i++)
	{
		window.draw(menuSeleccionJugador1[i]);
	}
	window.display(); // actualiza la ventana del juego
}

//	Metodo que se encarga de mostrar las opciones a escoger letra del menu jugador 2.
void Menu::dibujarMenuSeleccionJugador2(sf::RenderWindow& window)
{
	for (int i = 0; i < MAXIMO_OPCIONES_JUGADOR2; i++)
	{
		window.draw(menuSeleccionJugador2[i]);
	}
	window.display(); // actualiza la ventana del juego
}

//	Metodo que se encarga de dibujar las opciones del menu de juego 2 
// (menu mostrado durante un juego inicialdo)
void Menu::dibujarMenuJuego2(sf::RenderWindow& window)
{

	for (int i = 0; i < MAXIMO_OPCIONES; i++)
	{
		window.draw(menuJuego2[i]);
	}
	window.display();// actualiza la ventana del juego
}

// Metodo que se encarga de dibujar las opciones del sub menu de jugador vs CPU
// que se le  muestran al usuario dspues de escoger la opcion dos del menu principal
// se le muestran opciones para que escoga el tipo de nivel que desea jugadro contra la maquina
void Menu::dibujarSubMenuSeleccionNiveles(sf::RenderWindow& window)
{
	for (int i = 0; i < MAXIMO_OPCIONES; i++)
	{
		window.draw(menuSubNiveles[i]); // Dibuja la opcines del sub menu de niveles de modo jugador vs CPU
	}
	window.display(); // actualiza la ventana del juego
}

// Metodo que se encarga de navegar hacia arriba entre las opciones del menu y cambia el 
// color de item seleccionado
void Menu::moveUpMenu(unsigned int navegaMenu)
{

	// Navega hacia abajo en el menu inicial
	if (navegaMenu == 1) {
		if (selectedItemIndex - 1 >= 0)
		{
			menu[selectedItemIndex].setFillColor(sf::Color::White);
			selectedItemIndex--;
			menu[selectedItemIndex].setFillColor(sf::Color::Cyan);
		}
	}
	// Navega hacia abajo en el sub menu de niveles
	else if (navegaMenu == 2) {
		if (selectedItemIndex - 1 >= 0)
		{
			menuSubNiveles[selectedItemIndex].setFillColor(sf::Color::White);
			selectedItemIndex--;
			menuSubNiveles[selectedItemIndex].setFillColor(sf::Color::Cyan);
		}
	}

}

// Metodo que se encarga de navegar hacia abajo entre las opciones del menu y cambia el 
// color de item seleccionado
void Menu::moveDownMenu(unsigned int navegaMenu)
{
	// Navega hacia abajo en el menu inicial
	if (navegaMenu == 1) {
		if (selectedItemIndex + 1 < MAXIMO_OPCIONES)
		{
			menu[selectedItemIndex].setFillColor(sf::Color::White);
			selectedItemIndex++;
			menu[selectedItemIndex].setFillColor(sf::Color::Cyan);
		}
	}
	// Navega hacia abajo en el sub menu de niveles
	else if (navegaMenu == 2) {
		if (selectedItemIndex + 1 < MAXIMO_OPCIONES)
		{
			menuSubNiveles[selectedItemIndex].setFillColor(sf::Color::White);
			selectedItemIndex++;
			menuSubNiveles[selectedItemIndex].setFillColor(sf::Color::Cyan);
		}
	}

}

// Metodo que se encarga de navegar hacia arriba entre las opciones del menu selecion letra jugodor y cambia el 
// color de item seleccionado
void Menu::moveUpSeleccionJugador(int tipoJugador)
{
	// considicional si el jugador 1 mueve hacia arriba entre la opciones de letra a escoger
	// jugador 2 no tiene porque solo se le presenta una opcion de acuerdo a la eleccion de jugador 1
	if (selectedItemIndex - 1 >= 0 && tipoJugador == 1)
	{
		menuSeleccionJugador1[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menuSeleccionJugador1[selectedItemIndex].setFillColor(sf::Color::Cyan);
	}

}

// Metodo que se encarga de navegar hacia abajo entre las opciones del menu selecion letra jugodor y cambia el 
// color de item seleccionado
void Menu::moveDownSeleccionJugador(int tipoJugador)
{
	// considicional si el jugador 1 mueve hacia abajo entre la opciones de letra a escoger
	// jugador 2 no tiene porque solo se le presenta una opcion de acuerdo a la eleccion de jugador 1
	if (selectedItemIndex + 1 < MAXIMO_OPCIONES_JUGADOR1 && tipoJugador == 1)
	{
		menuSeleccionJugador1[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menuSeleccionJugador1[selectedItemIndex].setFillColor(sf::Color::Cyan);
	}

}