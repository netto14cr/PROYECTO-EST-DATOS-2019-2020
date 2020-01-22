// sokoban.cpp
// Autores: Kislev Aleman, Josua Esquivel y Néstor Leiva
// Implemeentacion de los metodos del juego sokoban.


#include "sokoban.h"



sokoban::sokoban() {
	caracter = ' ';
	posicionActX = 0;
	posicionActY = 0;
}

sokoban::~sokoban() {
		eliminarContenidoVector();
}



// Metodo que se encarga de actualizar graficamente y los cambios realizados 
// al recorrer la lista enlazada del juego.

void sokoban::dibCambioMovSokoban(sf::RenderWindow& window, NodoLista*& inicio) {

	//window.clear();
	actualizarDatosMatriz(inicio);
	dibujarMapa(window);
	//window.display();
}


// Metodo que se encarga de cargar los datos de la lista enlazada a un string y de el cargarlo
// en un vector para poder mostrarlo graficamente por pantalla al juegador.

void sokoban::actualizarDatosMatriz(NodoLista* & inicio) {
	NodoLista* tmp = nullptr;
	tmp = inicio;
	if (!areaJuego.empty()) {
		areaJuego.clear();
	}

	matriz = lE.leerMatris(tmp);
	cout << "\n";
	for (unsigned int i = 0; i < matriz.length(); i++) {
		caracter = matriz[i];
		areaJuego.push_back(matriz[i]); // cargamos todos los elementos de la matriz de string al vector
	}
	for (unsigned int i = 0; i < areaJuego.size(); i++) {
		cout << areaJuego[i];
	}
	;
	cout << "\n";
	cout << "\n";

}


//	Metodo que se encarga de dibujar las texturas del juego por pantalla.
void sokoban::dibujarMapa(sf::RenderWindow& window) {

	window.clear();
	float posX = 0;
	float posY = 0;
	sf::Sprite obj;
	int j = 0;

	int cont = 0;
	for (unsigned int i = 0; i < areaJuego.size(); i++) {

		if (i == 0) {
			posX += 32;
		}

		if (areaJuego[i] == '\n') {
			//Condisional que detecta lso brincos para simular una matriz

			posY += 32;
			posX = 0;
			j++;
		}
		if (areaJuego[i] == '#') {
			// Dinuja la pared
			obj.setTexture(pared);
			obj.setPosition(posX, posY);
			window.draw(obj);
		}
		else if (areaJuego[i] == ' ') {
			obj.setTexture(camino);
			obj.setPosition(posX, posY);
			window.draw(obj);

		}
		else if (areaJuego[i] == '$') {
			/// Dibuja la caja
			obj.setTexture(caja);
			obj.setPosition(posX, posY);
			window.draw(obj);
		}
		else if (areaJuego[i] == '@') {
			// dibuja el personaje
			posicionActX = i;
			posicionActY = j;
			obj.setTexture(personaje);
			obj.setPosition(posX, posY);
			window.draw(obj);
		}

		else if (areaJuego[i] == '!') {
			// Dinujar la caja colocada correctamente en su lugar.
			obj.setTexture(target);
			obj.setPosition(posX, posY);
			window.draw(obj);
		}
		else if (areaJuego[i] == '.') {
			// Dinujar el lugar donde se puede colocar la caja.
			obj.setTexture(lugarCaja);
			obj.setPosition(posX, posY);
			window.draw(obj);
		}
		posX += 32;
	}

	window.display();
}

// Este metodo elimina el contenido del vector area de juego.
void sokoban::eliminarContenidoVector() {

	if (!areaJuego.empty()) {
		areaJuego.clear();
	}
	else {
		cout << "No existen datos en el vector del area de juego!";
	}
}


// Metodo que se en carga de cargar y verificar la s imagenes usadas en el juego.

void sokoban::cargaDeTexturasJuego() {
	if (!pared.loadFromFile(DIR_PARED)) {
		//Error en caso de cargar la img de la pared.
	}
	if (!caja.loadFromFile(DIR_CAJA)) {
		//Error en caso de cargar la img caja.
	}
	if (!lugarCaja.loadFromFile(DIR_DOT)) {
		//Error en caso de cargar la img de la posicion a colocar la caja.
	}
	if (!personaje.loadFromFile(DIR_JUGADOR)) {
		//Error en caso de cargar la img del jugador
	}
	if (!target.loadFromFile(DIR_OBJETIVO)) {
		//Error en caso de cargar la img caja colocada correctamente.
	}
	if (!camino.loadFromFile(DIR_CAMINO)) {
		//Error en caso de cargar la img del camino del juego
	}
}



void sokoban::cargarSonidos() {

	if (!musica.openFromFile(DIR_PAUSA)){
		//Error al cargar la musica del menu de pausa
	}
	if (!musicaTeclas.loadFromFile(DIR_MUSICA_TECLAS)) {
		//Error al cargar la musica del menu de pausa
	}
	if (!musicaFondo.loadFromFile(DIR_MUSICA_FONDO)) {
		//Error al cargar la musica del menu de pausa
	}

}


void sokoban::reproducirSonido(int numeroSonido) {
	if (numeroSonido == 1) {
		musica.play();
		cout << "sonando puasa\n";
	}
	else if (numeroSonido == 2) {
		sonido.setBuffer(musicaTeclas);
		cout << "sonando musica de teclas\n";
	}
	else if (numeroSonido == 3) {
		sonido.setBuffer(musicaFondo);
		sonido.setLoop(true);
		cout << "sonando musica del juego\n";
	}
	sonido.play();
}



void sokoban::detenerSonido() {
	sonido.setLoop(false);
	sonido.stop();
	musica.stop();
}