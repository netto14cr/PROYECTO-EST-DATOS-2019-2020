// menu.h
// Autores: Kislev Aleman, Josua Esquivel y Néstor Leiva
// Descripción: Definicion de la clase menu y sus metodos para mostrar las diferentes tipos 
// de opciones que puede seleccionar los usuarios antes , durante y despues de comenzar a jugar

#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp> // Inclusion para uso de la libreria graphica SFML 
#include <iostream>
using std::cout;
using std::endl;

// Declaracion de la direccion de fuente empleada para las diferentes opciones
// los menus mostrados por pantalla al usuario
#define DIR_FUENTES "../fuentes/arial.ttf"

//Definimos el maximo de opciones a navegar entre los diferentes menus.
#define MAXIMO_OPCIONES 3
#define MAXIMO_OPCIONES_JUGADOR1 2
#define MAXIMO_OPCIONES_JUGADOR2 1


class Menu
{
public:
	// Declara el constructo y destructor de la clase menu
	Menu(float width, float height);
	~Menu();
	// Declaracion de los metodos que actualizan por pantalla las opciones de los menus
	void dibujarMenuInicial(sf::RenderWindow& window);
	void dibujarMenuSeleccionJugador1(sf::RenderWindow& window);
	void dibujarMenuSeleccionJugador2(sf::RenderWindow& window);
	void dibujarSubMenuSeleccionNiveles(sf::RenderWindow& window);
	void dibujarMenuJuego2(sf::RenderWindow& window);


	// Declaracion de metodos para navegar entre las opciones de los menus
	void moveDownMenu(unsigned int navegaMenu);
	void moveUpMenu(unsigned int navegaMenu);
	void moveUpSeleccionJugador(int tipoJugador);
	void moveDownSeleccionJugador(int tipoJugador);

	int GetPressedItem() { return selectedItemIndex; }


	// Declaracion de metodo para preguntar al usaurio la eleccion de una letra en el juego
	void mostrarMenuSeleccionImgJugador1(float width, float height);
	void mostrarMenuSeleccionImgJugador2(float width, float height, int seleccionJugador1);
	void mostrarSubMenuNiveles(float width, float height);
	void mostrarMenuJuego2(float width, float height);


private:

	// Declaracion de atributos privados de la clase menu
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAXIMO_OPCIONES];
	sf::Text menuSeleccionJugador1[MAXIMO_OPCIONES_JUGADOR1];
	sf::Text menuSeleccionJugador2[MAXIMO_OPCIONES_JUGADOR2];
	sf::Text menuJuego2[MAXIMO_OPCIONES];
	sf::Text menuSubNiveles[MAXIMO_OPCIONES];

	sf::Texture tituloJuego;
	sf::Sprite obj;

	void cargarFuentes();
	void mostrarMenuInicial(float width, float height);
};


#endif // !MENU_H



