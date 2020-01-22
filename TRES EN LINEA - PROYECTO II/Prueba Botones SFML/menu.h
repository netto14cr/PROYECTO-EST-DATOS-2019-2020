// menu.h
// Autores: Kislev Aleman, Josua Esquivel y Néstor Leiva
// Descripción: Definicion de la clase menu


#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp> // Inclusion para uso de la libreria graphica SFML 


#define DIR_FUENTES "../fuentes/arial.ttf"

#define MAXIMO_OPCIONES 3
#define MAXIMO_OPCIONES_JUGADOR1 2
#define MAXIMO_OPCIONES_JUGADOR2 1




class Menu
{
public:

	Menu(float width, float height);
	~Menu();



	// Definicion de metodos de movimientos entre las opciones del menu
	void dibujarMenuInicial(sf::RenderWindow& window);
	void dibujarMenuSeleccionJugador1(sf::RenderWindow& window);
	void dibujarMenuSeleccionJugador2(sf::RenderWindow& window);

	void moveDownMenu();
	void moveUpMenu();

	void moveUpSeleccionJugador(int tipoJugador);
	void moveDownSeleccionJugador(int tipoJugador);

	int GetPressedItem() { return selectedItemIndex; }


	// Declaracion de metodo para preguntar al usaurio la eleccion de una letra en el juego
	void mostrarMenuSeleccionImgJugador1(float width, float height);
	void mostrarMenuSeleccionImgJugador2(float width, float height, int seleccionJugador1);

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAXIMO_OPCIONES];
	sf::Text menuSeleccionJugador1[MAXIMO_OPCIONES_JUGADOR1];
	sf::Text menuSeleccionJugador2[MAXIMO_OPCIONES_JUGADOR2];
	sf::Texture tituloJuego;
	sf::Sprite obj;

	void cargarFuentes();
	void mostrarMenuInicial(float width, float height);
};


#endif // !MENU_H



