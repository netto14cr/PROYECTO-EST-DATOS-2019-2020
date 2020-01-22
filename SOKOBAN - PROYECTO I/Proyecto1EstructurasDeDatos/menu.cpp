
// menu.cpp
// Autores: Kislev Aleman, Josua Esquivel y Néstor Leiva
// Implementacion de la clase menu

#include "Menu.h"
#include "ventana.h"




Menu::Menu(float width, float height)
{
	cargarFuentes();
	cargarOpcionesMenu(width ,height);
}


Menu::~Menu(){}


void Menu::cargarFuentes(){
	if (!font.loadFromFile(DIR_FUENTES))
	{
		// Mostrar un error si existiera a la hora de carga las fuestes.
		std::cout << "Existe un error al cargar el tipo de letra." << std::endl;
	}
}


void Menu::cargarOpcionesMenu(float width, float height) {
	


	// Creacion de las opciones del menu mostradas al inicio y en la pausa del juego.
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Iniciar nuevo juego");
	menu[0].setPosition(sf::Vector2f(width / 3, height / (MAXIMO_OPCIONES + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Cargar una partida anterior");
	menu[1].setPosition(sf::Vector2f(width / 3, height / (MAXIMO_OPCIONES + 1) * 2));

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Reiniciar juego");
	menu[2].setPosition(sf::Vector2f(width / 3, height / (MAXIMO_OPCIONES + 1) * 3));

	menu[3].setFont(font);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("Nivel 2");
	menu[3].setPosition(sf::Vector2f(width / 3, height / (MAXIMO_OPCIONES + 1) * 4));

	menu[4].setFont(font);
	menu[4].setFillColor(sf::Color::White);
	menu[4].setString("Nivel 3");
	menu[4].setPosition(sf::Vector2f(width / 3, height / (MAXIMO_OPCIONES + 1) * 5));

	menu[5].setFont(font);
	menu[5].setFillColor(sf::Color::White);
	menu[5].setString("Nivel 4");
	menu[5].setPosition(sf::Vector2f(width / 3, height / (MAXIMO_OPCIONES + 1) * 6));


	menu[6].setFont(font);
	menu[6].setFillColor(sf::Color::White);
	menu[6].setString("Salir del juego");
	menu[6].setPosition(sf::Vector2f(width / 3, height / (MAXIMO_OPCIONES + 1) * 7));


	selectedItemIndex = 0;
}



//	Metodo que se encarga de mostrar las opciones dibujadas del menu.
void Menu::draw(sf::RenderWindow& window)
{

	window.clear();
	for (int i = 0; i < MAXIMO_OPCIONES; i++)
	{
		window.draw(menu[i]);
	}
	window.display();
}


// Metodo que se encarga de navegar hacia arriba entre las opciones del menu y cambia el 
// color de item seleccionado
void Menu::MoveUp()
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

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAXIMO_OPCIONES)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Green);
	}
}