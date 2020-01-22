// menu.h
// Autores: Kislev Aleman, Josua Esquivel y Néstor Leiva
// Definicion de la clase menu


#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp> // Inclusion para uso de la libreria graphica SFML 

#define MAXIMO_OPCIONES 7
#define DIR_FUENTES "../fuentes/arial.ttf"



class Menu
{
public:

	Menu(float width, float height);
	~Menu();


	// Definicion de metodos de movimientos entre las opciones del menu
	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }

private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAXIMO_OPCIONES];
	void cargarOpcionesMenu(float x, float y);
	void cargarFuentes();

};


#endif // !MENU_H


