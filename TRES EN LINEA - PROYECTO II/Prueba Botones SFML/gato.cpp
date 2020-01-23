// gato.cpp
// Autores: Kislev Aleman, Josua Esquivel y Néstor Leiva
// Descripcion: Implementacion de la clase gato

#include "gato.h"
#include "ventana.h"

#include "modoJuego1.h"


modoJuego1 mod1;

// Metodo que se en carga de cargar y verificar la s imagenes usadas en el juego.

void gato::cargaDeTexturasJuego() {

	if (!jugadorX.loadFromFile(DIR_JUGADORX)) {
		//Error en caso de cargar la img del jugador X

		cout << "\nError al cargar img X \n";
	}
	if (!jugadorO.loadFromFile(DIR_JUGADORO)) {
		//Error en caso de cargar la img del jugador O
		cout << "\nError al cargar img O \n";
	}
	if (!espacioVacio.loadFromFile(DIR_ESPACIOVACIO)) {
		//Error en caso de cargar la img del camino del juego
		cout << "\nError al cargar img en blanco \n";
	}

	if (!salir.loadFromFile(DIR_SALIR)) {
		//Error en caso de cargar la img de boton de salir.
		cout << "\nError al cargar img boton salir \n";
	}

	if (!tituloJuego.loadFromFile(DIR_TITULO)) {
		//Error en caso de cargar la img de titulo del juego.
		cout << "\nError al cargar img de titulo de juego \n";
	}

	if (!turnoSeleccion1.loadFromFile(DIR_TURNOSELECCION1)) {
		//Error en caso de cargar la img de turno selecion jugador 1.
		cout << "\nError al cargar img de turno selecion jugador 1 \n";
	}

	if (!turnoSeleccion2.loadFromFile(DIR_TURNOSELECCION2)) {
		//Error en caso de cargar la img de turno selecion jugador 2.
		cout << "\nError al cargar img de turno selecion jugador 2 \n";
	}


	if (!jugadorE1.loadFromFile(DIR_TURNOJ1)) {
		//Error en caso de cargar la img de nombre jugador 1.
		cout << "\nError al cargar img de nombre jugador 1 \n";
	}

	if (!jugadorE2.loadFromFile(DIR_TURNOJ2)) {
		//Error en caso de cargar la img de nombre jugador 2.
		cout << "\nError al cargar img de nombre jugador 2 \n";
	}

	if (!jugadorGano1.loadFromFile(DIR_GANO1)) {
		//Error en caso de cargar la img de ganador jugador 1.
		cout << "\nError al cargar img de ganador jugador 1 \n";
	}

	if (!jugadorGano2.loadFromFile(DIR_GANO2)) {
		//Error en caso de cargar la img de ganador jugador 2.
		cout << "\nError al cargar img de ganador jugador 2 \n";
	}


	if (!empate.loadFromFile(DIR_EMPATE)) {
		//Error en caso de cargar la img de empate.
		cout << "\nError al cargar img de empate \n";
	}

}



// Metodo que dibuja 9 botones en pantalla que representan una matriz en pantalla para que los 
// jugadores presiones y jueguen.
void gato::dibujarBotonesGato(sf::RenderWindow& window) {


	dibujarImagenEspecifica(window, 9);
	// --------------	MATRIZ BOTONES   -----------------
	// -------------------- FILA 1  ----------------------
	boton1Image.setTexture(espacioVacio);
	boton1Image.setPosition(317.0f, 200.0f);
	window.draw(boton1Image);
	boton2Image.setTexture(espacioVacio);
	boton2Image.setPosition(450.0f, 200.0f);
	window.draw(boton2Image);
	boton3Image.setTexture(espacioVacio);
	boton3Image.setPosition(583.0f, 200.0f);

	// -------------------- FILA 2  ----------------------
	window.draw(boton3Image);
	boton4Image.setTexture(espacioVacio);
	boton4Image.setPosition(317.0f, 333.0f);
	window.draw(boton4Image);
	boton5Image.setTexture(espacioVacio);
	boton5Image.setPosition(450.0f, 333.0f);
	window.draw(boton5Image);
	boton6Image.setTexture(espacioVacio);
	boton6Image.setPosition(583.0f, 333.0f);
	window.draw(boton6Image);

	// -------------------- FILA 3  ----------------------

	boton7Image.setTexture(espacioVacio);
	boton7Image.setPosition(317.0f, 466.0f);
	window.draw(boton7Image);
	boton8Image.setTexture(espacioVacio);
	boton8Image.setPosition(450.0f, 466.0f);
	window.draw(boton8Image);
	boton9Image.setTexture(espacioVacio);
	boton9Image.setPosition(583.0f, 466.0f);
	window.draw(boton9Image);
	window.display();
}



// Metodo que obtiene los valores del vector de matriz de juego y lee uno por uno su contenido y
// asi determina la textura de cada boton del juego mostrado en pantalla
void gato::dibujarBotonesMatriz(vector<string> vectorAux, sf::RenderWindow& window)
{
	
	for (unsigned int i = 0; i < vectorAux.size(); i++) {
				actualizaImgBoton(i, window, determinarImagenTextura(vectorAux.at(i)));
	}
	window.display();
}


// Metodo que actualiza la img de cada boton segun la eleccion o no de cada jugador que se mostraran
// en la matriz de botones que se dibujara en pantalla. 
void gato::actualizaImgBoton(unsigned int nBoton, sf::RenderWindow& window, sf::Texture aux) {
	// Switch determina el numero de boton a actualizar con la nueva imagen
	switch (nBoton)
	{
	case 0:
		boton1Image.setTexture(aux);
		boton1Image.setPosition(317.0f, 200.0f);
		window.draw(boton1Image);

		break;

	case 1:
		boton2Image.setTexture(aux);
		boton2Image.setPosition(450.0f, 200.0f);
		window.draw(boton2Image);

		break;

	case 2:
		boton3Image.setTexture(aux);
		boton3Image.setPosition(583.0f, 200.0f);
		window.draw(boton3Image);

		break;

	case 3:
		boton4Image.setTexture(aux);
		boton4Image.setPosition(317.0f, 333.0f);
		window.draw(boton4Image);

		break;

	case 4:
		boton5Image.setTexture(aux);
		boton5Image.setPosition(450.0f, 333.0f);
		window.draw(boton5Image);

		break;

	case 5:
		boton6Image.setTexture(aux);
		boton6Image.setPosition(583.0f, 333.0f);
		window.draw(boton6Image);

		break;

	case 6:
		boton7Image.setTexture(aux);
		boton7Image.setPosition(317.0f, 466.0f);
		window.draw(boton7Image);

		break;

	case 7:
		boton8Image.setTexture(aux);
		boton8Image.setPosition(450.0f, 466.0f);
		window.draw(boton8Image);

		break;

	case 8:
		boton9Image.setTexture(aux);
		boton9Image.setPosition(583.0f, 466.0f);
		window.draw(boton9Image);

		break;
	}


}


// Metodo se encarga de obtener el tamaño de los botones

void gato::obtenerTamanioImgBotones() {

	boton1Width = boton1Image.getLocalBounds().width;
	boton1Height = boton1Image.getLocalBounds().height;

	boton2Width = boton2Image.getLocalBounds().width;
	boton2Height = boton2Image.getLocalBounds().height;

	boton3Width = boton3Image.getLocalBounds().width;
	boton3Height = boton3Image.getLocalBounds().height;

	boton4Width = boton4Image.getLocalBounds().width;
	boton4Height = boton4Image.getLocalBounds().height;

	boton5Width = boton5Image.getLocalBounds().width;
	boton5Height = boton5Image.getLocalBounds().height;

	boton6Width = boton6Image.getLocalBounds().width;
	boton6Height = boton6Image.getLocalBounds().height;

	boton7Width = boton7Image.getLocalBounds().width;
	boton7Height = boton7Image.getLocalBounds().height;

	boton8Width = boton8Image.getLocalBounds().width;
	boton8Height = boton8Image.getLocalBounds().height;

	boton9Width = boton9Image.getLocalBounds().width;
	boton9Height = boton9Image.getLocalBounds().height;
}



// Este metodo indica con el evento del mause la flecha esta hubicada encima de algun boton dle juego.
void gato::pintarColorBotonEncima(sf::RenderWindow& window) {
	mousePos = sf::Mouse::getPosition(window);
	sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));


	// Si el mause esta hubicado encima del boton 1
	if (boton1Image.getGlobalBounds().contains(mousePosF))
	{
		boton1Image.setColor(sf::Color(0, 100, 100));

	}

	// falso si el boton esta hubicado encima del boton 2
	else if (boton2Image.getGlobalBounds().contains(mousePosF)) {
		boton2Image.setColor(sf::Color(0, 100, 100));


	}
	// falso si el boton esta hubicado encima del boton 3
	else if (boton3Image.getGlobalBounds().contains(mousePosF)) {
		boton3Image.setColor(sf::Color(0, 100, 100));

	}
	// falso si el boton esta hubicado encima del boton 4
	else if (boton4Image.getGlobalBounds().contains(mousePosF)) {
		boton4Image.setColor(sf::Color(0, 100, 100));


	}

	// falso si el boton esta hubicado encima del boton 5
	else if (boton5Image.getGlobalBounds().contains(mousePosF)) {
		boton5Image.setColor(sf::Color(0, 100, 100));

	}
	// falso si el boton esta hubicado encima del boton 6
	else if (boton6Image.getGlobalBounds().contains(mousePosF)) {
		boton6Image.setColor(sf::Color(0, 100, 100));

	}

	// falso si el boton esta hubicado encima del boton 7
	else if (boton7Image.getGlobalBounds().contains(mousePosF)) {
		boton7Image.setColor(sf::Color(0, 100, 100));

	}

	// falso si el boton esta hubicado encima del boton 8
	else if (boton8Image.getGlobalBounds().contains(mousePosF)) {
		boton8Image.setColor(sf::Color(0, 100, 100));

	}

	// falso si el boton esta hubicado encima del boton 9
	else if (boton9Image.getGlobalBounds().contains(mousePosF)) {
		boton9Image.setColor(sf::Color(0, 100, 100));

	}
	// Falso si no esta encima de ningun boton no mantiene pinta de color ningun boton 
	else
	{
		boton1Image.setColor(sf::Color(255, 255, 255));
		boton2Image.setColor(sf::Color(255, 255, 255));
		boton3Image.setColor(sf::Color(255, 255, 255));
		boton4Image.setColor(sf::Color(255, 255, 255));
		boton5Image.setColor(sf::Color(255, 255, 255));
		boton6Image.setColor(sf::Color(255, 255, 255));
		boton7Image.setColor(sf::Color(255, 255, 255));
		boton8Image.setColor(sf::Color(255, 255, 255));
		boton9Image.setColor(sf::Color(255, 255, 255));
	}


}












void gato::accionSeleccionarBoton(sf::RenderWindow& window, unsigned int numeroJugador) {
	mousePos = sf::Mouse::getPosition(window);
	sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

	// Si el usuario le dio click al boton 1
	if (boton1Image.getGlobalBounds().contains(mousePosF))
	{
		botonSeleccionado = 1;
	}

	// falso Si el usuario le dio click al boton 2
	else if (boton2Image.getGlobalBounds().contains(mousePosF))
	{
		botonSeleccionado = 2;
	}
	// falso Si el usuario le dio click al boton 3
	else if (boton3Image.getGlobalBounds().contains(mousePosF))
	{
		botonSeleccionado = 3;

	}
	// falso Si el usuario le dio click al boton 4
	else if (boton4Image.getGlobalBounds().contains(mousePosF))
	{
		botonSeleccionado = 4;
	}

	// falso Si el usuario le dio click al boton 5
	else if (boton5Image.getGlobalBounds().contains(mousePosF))
	{
		botonSeleccionado = 5;
	}

	// falso Si el usuario le dio click al boton 6
	else if (boton6Image.getGlobalBounds().contains(mousePosF))
	{
		botonSeleccionado = 6;
	}

	// falso Si el usuario le dio click al boton 7
	else if (boton7Image.getGlobalBounds().contains(mousePosF))
	{
		botonSeleccionado = 7;
	}

	// falso Si el usuario le dio click al boton 8
	else if (boton8Image.getGlobalBounds().contains(mousePosF))
	{
		botonSeleccionado = 8;
	}

	// falso Si el usuario le dio click al boton 9
	else if (boton9Image.getGlobalBounds().contains(mousePosF))
	{
		botonSeleccionado = 9;
	}

	// Falso si no se le dio un click a ningun boton se determina por defecto el valor de boton seleccionado a 0
	else {
		botonSeleccionado = 0;
	}
}




// Metodo que verifica si se puede realizar una jugada por parte de cualquiera de los dos jugadores y se 
// verdad cambiara el estado de las imagenes de los botones y cambiaria el turno asignado a falso del jugador que realizo 
// la jugada.


// Este metodo tambine valida que cambie los eventos graficos y de validacion si no hay todavia un ganador o empate
// de lo contrario avisara que ya la jugada no puede ser realizada.
bool gato::verificarPosibleJugadaModo1(unsigned int numeroBoton, unsigned int numeroJugador, string letraJugador, sf::RenderWindow& window)
{
	if (mod1.verificarPosibleJugada(numeroBoton, numeroJugador, letraJugador) && !ganadorJugador1
		&& !ganadorJugador2 && !noGanadorFinal) {

		jugadaRealizada = true;
		contarMoviRealizados++;
		cambioLetrasJugadores(letraJugador, numeroJugador);


		// Dibuja los cambios de los botones mediante un vector que contiene los valores de matriz de movimientos 
		// efectuados por los juegador de la clase modoJuego1
		dibujarBotonesMatriz(mod1.vectorGuardaMatriz(), window);

		if (mod1.verificaGanadorJugador1() && contarMoviRealizados <= 9 && numeroJugador == 1) {
			cout << "\n JUGADOR 1 GANO EL GATO!!\n";

			ganadorJugador1 = true;
		}
		else if (mod1.verificaGanadorJugador2() && contarMoviRealizados <= 9 && numeroJugador == 2) {
			cout << "\n JUGADOR 2 GANO EL GATO!!\n";
			ganadorJugador2 = true;
		}
		else if (!mod1.verificaGanadorJugador1() && !mod1.verificaGanadorJugador2() && contarMoviRealizados >= 9) {
			cout << "\n JUEGO TERMINO EN EMPATE!!\n";
			noGanadorFinal = true;
		}

	}
	else {
		jugadaRealizada = false; // por defecto se resetea la vaciable de jugada realizada
	}
	return jugadaRealizada;

}



void gato::cambioLetrasJugadores(string letraJugador, unsigned int numeroJugador) {
	// Actualiza con que letra esta realizando la jugada el jugador 
	if (numeroJugador == 1) {
		letraJugador1 = letraJugador;
	}
	else if (numeroJugador == 2) {
		letraJugador2 = letraJugador;
	}

}





// Metodo que evalua a  que nuero de boton a a asignar la letra correspondiente de jugador sea jugador uno o dos
// la letra con la que juega al incio del juego.
sf::Texture gato::determinarImagenTextura(string letraJuegador) {

	sf::Texture auxImagenAPoner;

	if (letraJuegador == "jugadorX") {
		auxImagenAPoner = jugadorX;
	}
	else if (letraJuegador == "jugadorO") {
		auxImagenAPoner = jugadorO;
	}
	else if (letraJuegador == "espacioVacio") {
		auxImagenAPoner = espacioVacio;
	}

	actualizaImagenAux = auxImagenAPoner;
	return actualizaImagenAux;
	//pintarBotonEspecifico(window, nBoton);
}











// Metodo que dibuja una imagen espeficica en la pantalla

void gato::dibujarImagenEspecifica(sf::RenderWindow& window, int tipoImg) {
	// Si el tipo de imagen es 1 dibujara el titulo en pantalla
	if (tipoImg == 1) {

		obj.setTexture(tituloJuego);
		obj.setPosition(75.0f, 50.0f);
	}
	// Falso si se pide el 2 dibujara la img de la X
	else if (tipoImg == 2) {
		obj.setTexture(jugadorX);
		obj.setPosition(650.0f, 290.0f);
	}

	// Falso si se pide el 3 dibujara la img de la O
	else if (tipoImg == 3) {
		obj.setTexture(jugadorO);
		obj.setPosition(650.0f, 430.0f);
	}

	// Falso si se pide el 4 dibujara el turno de seleccion jugador 1
	else if (tipoImg == 4) {
		obj.setTexture(turnoSeleccion1);
		obj.setPosition(200.0f, 200.0f);
	}
	// Falso si se pide el 5 dibujara el turno de seleccion jugador 2
	else if (tipoImg == 5) {
		obj.setTexture(turnoSeleccion2);
		obj.setPosition(200.0f, 200.0f);
	}

	// Falso si se pide img 6 es la imagen del circulo en otra posicion (para jugador 2)
	else if (tipoImg == 6) {
		obj.setTexture(jugadorO);
		obj.setPosition(650.0f, 290.0f);
	}
	// Falso si es img 7 dibuja el nombre del jugador 1
	else if (tipoImg == 7) {
		obj.setTexture(jugadorE1);
		obj.setPosition(385.0f, 125.0f);
	}

	// Falso si es img 7 dibuja el nombre del jugador 1
	else if (tipoImg == 8) {
		obj.setTexture(jugadorE2);
		obj.setPosition(385.0f, 125.0f);
	}


	// Si el tipo de imagen es 9 dibujara el titulo en pantalla en una posicion mas alta
	else if (tipoImg == 9) {

		obj.setTexture(tituloJuego);
		obj.setPosition(75.0f, 5.0f);
	}
	// Si el tipo de imagen es 10 siginifica que dibujara la imagen de ganador jugador 1
	else if (tipoImg == 10) {
		obj.setTexture(jugadorGano1);
		obj.setPosition(150.0f, 230.0f);
	}

	// Si el tipo de imagen es 11 siginifica que dibujara la imagen de ganador jugador 2
	else if (tipoImg == 11) {

		obj.setTexture(jugadorGano2);
		obj.setPosition(150.0f, 230.0f);
	}

	// Si el tipo de imagen es 12 siginifica que dibujara la imagen de empate
	else if (tipoImg == 12) {

		obj.setTexture(empate);
		obj.setPosition(170.0f, 230.0f);
	}
	window.draw(obj);
}







// Metodo que se encarga de cargar los sonidos dle juego
void gato::cargarSonidos() {

	if (!musica.openFromFile(DIR_PAUSA)) {
		//Error al cargar la musica del menu de pausa
	}
	if (!musicaTeclas.loadFromFile(DIR_MUSICA_TECLAS)) {
		//Error al cargar la musica del menu de pausa
	}
	if (!musicaFondo.loadFromFile(DIR_MUSICA_FONDO)) {
		//Error al cargar la musica del menu de pausa
	}

}



// Metodo que realiza la reproduccion del sonido indicado especificamente
void gato::reproducirSonido(int numeroSonido) {
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


// Metodo que se encarga de pausar o detener los sonidos del juego
void gato::detenerSonido() {
	sonido.setLoop(false);
	sonido.stop();
	musica.stop();
}


