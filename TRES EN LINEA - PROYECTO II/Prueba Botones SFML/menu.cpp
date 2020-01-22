
// menu.cpp
// Autores: Kislev Aleman, Josua Esquivel y Néstor Leiva
// Descripcion: Implementacion de la clase menu

#include "Menu.h"
#include "ventana.h"




Menu::Menu(float width, float height)
{
	cargarFuentes();
	mostrarMenuInicial(width,  height);
	mostrarMenuSeleccionImgJugador1(width, height);
	mostrarMenuSeleccionImgJugador2(width, height, 0);
}


void Menu::mostrarMenuInicial(float width, float height) {
	cout << "Mostrando menu inicial!! \n";
	

	// Creacion de las opciones del menu mostradas al inicio y en la pausa del juego.
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Jugador vs Jugador");
	menu[0].setPosition(sf::Vector2f(width / 3, height / (MAXIMO_OPCIONES + 1) * 2));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Jugador vs CPU");
	menu[1].setPosition(sf::Vector2f(width / 3, height / (MAXIMO_OPCIONES + 1) * 2.5));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Salir del juego");
	menu[2].setPosition(sf::Vector2f(width / 3, height / (MAXIMO_OPCIONES + 1) * 3));
	selectedItemIndex = 0;

}


// Metodo que muestra en forma de menu la seleccion de letra del jugador 1
void Menu::mostrarMenuSeleccionImgJugador1(float width, float height) {
	// Creacion de las opciones del menu mostradas al inicio y en la pausa del juego.
	menuSeleccionJugador1[0].setFont(font);
	menuSeleccionJugador1[0].setFillColor(sf::Color::Green);
	menuSeleccionJugador1[0].setString("Seleccionar letra X");
	menuSeleccionJugador1[0].setPosition(sf::Vector2f(width / 3.5, height / (MAXIMO_OPCIONES + 1) * 2.1));

	menuSeleccionJugador1[1].setFont(font);
	menuSeleccionJugador1[1].setFillColor(sf::Color::Magenta);
	menuSeleccionJugador1[1].setString("Seleccionar letra O");
	menuSeleccionJugador1[1].setPosition(sf::Vector2f(width / 3.5, height / (MAXIMO_OPCIONES + 1) * 3));
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
		menuSeleccionJugador2[0].setPosition(sf::Vector2f(width / 3.5, height / (MAXIMO_OPCIONES + 1) * 2.1));
	}

	// Falso si la seleccion del jugador 1 es la letra "O"
	else if (seleccionJugador1==2) {

		menuSeleccionJugador2[0].setFont(font);
		menuSeleccionJugador2[0].setFillColor(sf::Color::Yellow);
		menuSeleccionJugador2[0].setString("Seleccionar letra O");
		menuSeleccionJugador2[0].setPosition(sf::Vector2f(width / 3.5, height / (MAXIMO_OPCIONES + 1) * 2.1));
	}
	selectedItemIndex = 0;

}


// Metodo que realiza la carga del tipo de fuente utilizado para mostrar la letra del menu
void Menu::cargarFuentes() {
	if (!font.loadFromFile(DIR_FUENTES))
	{
		// Mostrar un error si existiera a la hora de carga las fuestes.
		cout << "Existe un error al cargar el tipo de letra." <<endl;
	}
	else {
		cout << "Carga de fuentes exitozamente!! \n";
	}
}




Menu::~Menu() {}

//	Metodo que se encarga de mostrar las opciones dibujadas del menu.
void Menu::dibujarMenuInicial(sf::RenderWindow& window)
{


	//mostrarmenu(window.getSize().x , window.getSize().y);
	for (int i = 0; i < MAXIMO_OPCIONES; i++)
	{
		window.draw(menu[i]);
	}

	window.display();
}








//	Metodo que se encarga de mostrar las opciones a escoger letra del menu jugador 1.
void Menu::dibujarMenuSeleccionJugador1(sf::RenderWindow& window)
{
	
	for (int i = 0; i < MAXIMO_OPCIONES_JUGADOR1; i++)
	{
		window.draw(menuSeleccionJugador1[i]);
	}
	window.display();
}



//	Metodo que se encarga de mostrar las opciones a escoger letra del menu jugador 2.
void Menu::dibujarMenuSeleccionJugador2(sf::RenderWindow& window)
{

	for (int i = 0; i < MAXIMO_OPCIONES_JUGADOR2; i++)
	{
		window.draw(menuSeleccionJugador2[i]);
	}
	window.display();
}




// Metodo que se encarga de navegar hacia arriba entre las opciones del menu y cambia el 
// color de item seleccionado
void Menu::moveUpMenu()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Green);
	}
}

// Metodo que se encarga de navegar hacia abajo entre las opciones del menu y cambia el 
// color de item seleccionado

void Menu::moveDownMenu()
{
	if (selectedItemIndex + 1 < MAXIMO_OPCIONES)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Green);
	}
}




// Metodo que se encarga de navegar hacia arriba entre las opciones del menu selecion letra jugodor y cambia el 
// color de item seleccionado
void Menu::moveUpSeleccionJugador(int tipoJugador)
{


	// considicional si el jugador 1 mueve hacia arriba entre la opciones de letra a escoger
	// jugador 2 no tiene porque solo se le presenta una opcion de acuerdo a la eleccion de jugador 1
	if (selectedItemIndex - 1 >= 0 && tipoJugador==1)
	{
		menuSeleccionJugador1[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menuSeleccionJugador1[selectedItemIndex].setFillColor(sf::Color::Green);
	}

}




// Metodo que se encarga de navegar hacia abajo entre las opciones del menu selecion letra jugodor y cambia el 
// color de item seleccionado
void Menu::moveDownSeleccionJugador(int tipoJugador)
{


	// considicional si el jugador 1 mueve hacia abajo entre la opciones de letra a escoger
	// jugador 2 no tiene porque solo se le presenta una opcion de acuerdo a la eleccion de jugador 1
	if (selectedItemIndex + 1 < MAXIMO_OPCIONES_JUGADOR1 && tipoJugador==1)
	{
		menuSeleccionJugador1[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menuSeleccionJugador1[selectedItemIndex].setFillColor(sf::Color::Green);
	}
	
}

