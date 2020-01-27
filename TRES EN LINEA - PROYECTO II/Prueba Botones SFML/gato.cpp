// gato.cpp
// Autores: Kislev Aleman, Josua Esquivel y Néstor Leiva
// Descripcion: Implementacion de la clase gato

#include "gato.h" // Declaración inclusion de clase gato.h
#include "ventana.h"// Declaración inclusion de clase ventana.h
#include "modoJuego1.h"// Declaración inclusion de clase modoJuego1 
#include "nivelDificil.h" // Declaración de clase nivelDificil

// Declara la implementacion de la clase modo de juego jugador vs jugador
modoJuego1 mod1;

// Declara la implementacion en la de nivelFacil

// Declara la implementacion en la de nivelNormal

// Declara la implementacion de la clase nivelDificil
nivelDificil nD;

// Metodo que valida los eventos graficos del modo de juego jugador vs jugador y determina 
// si con la jugada realizada por los jugadores, de exitit ganador mediante la jugada realiza
// actualizara el estado de jugador ganador o de lo contrario determinara un empate en la partida.
bool gato::verificarPosibleJugadaModo1(unsigned int numeroBoton, unsigned int numeroJugador,
	char letraJugador, sf::RenderWindow& window)
{
	// Si se cumple que se puede seleccionar la casilla elegida && todavia no hay un ganador oun empate se interpreta
	// como verdadero que la jugada realizada es correcta y actualiza cambios en la matriz de botnones del juego
	if (mod1.verificarPosibleJugada(numeroBoton, numeroJugador, letraJugador) && !ganadorJugador1
		&& !ganadorJugador2 && !noGanadorFinal) {

		// Cambio el estado de jugada realizada a verdadero
		jugadaRealizada = true;

		// cuenta los movimientos correctos para saber si ya se realizaron los movimientos totales del juego
		// y asi determinar si hay un ganador o el juego termina empatado.
		contarMoviRealizados++;

		// Llama al metodo que realiza la colocacion de imagnes segun el tipo de jugador que este jugando
		cambioLetrasJugadores(letraJugador, numeroJugador);

		// Dibuja los cambios de los botones mediante un vector que contiene los valores de matriz de movimientos 
		// efectuados por los juegador de la clase modoJuego1
		dibujarBotonesMatriz(mod1.vectorGuardaMatriz(), window);

		// Se hace el llamado del metodo que comprueba si sigue mostrando los cambios en la matriz del juego
		// o notifica a la vista para que muestre el resultado final del juego.
		verificarEstatusGanador(mod1.verificaGanadorJugador1(), mod1.verificaGanadorJugador2(),
			numeroJugador, contarMoviRealizados);

	}
	// Falso si no se cumple que se pueda realizar la jugada el estado cambia a falso y no modifica el turno, 
	// ni realiza un cambio en pantalla y jugador con turno puede intentar elegir otro posicion mientras en el juego
	// no haya terminado por haber un ganador o empate.
	else { jugadaRealizada = false; } // por defecto se resetea la vaciable de jugada realizada
	return jugadaRealizada;
}

// Metodo que valida los eventos graficos del modo de juego jugador vs CPU - dificualtad:::Facil y
// determina si con la jugada realizada por el juegador 1 o la maquina, tambien determina el ganador
// mediante la jugada realizada yactualizara el estado de jugador ganador o maquina y de lo contrario
// determinara un empate en la partida.
bool gato::verificarPosibleJugadaModoFacil(unsigned int numeroBoton, unsigned int numeroJugador, char letraJugador, sf::RenderWindow& window)
{
	// <<<<<<<<<<<<<<   llama a los metodos de la clase nivel facil  >>>>>>>>>>>>>>>>>

	// Si se cumple que se puede seleccionar la casilla elegida && todavia no hay un ganador oun empate se interpreta
	// como verdadero que la jugada realizada es correcta y actualiza cambios en la matriz de botnones del juego

	/// el metodo comentado es de nivel facil
	if (/*mod1.verificarPosibleJugada(numeroBoton, numeroJugador, letraJugador) &&*/ !ganadorJugador1
		&& !ganadorJugador2 && !noGanadorFinal) {

		// Cambio el estado de jugada realizada a verdadero
		jugadaRealizada = true;

		// cuenta los movimientos correctos para saber si ya se realizaron los movimientos totales del juego
		// y asi determinar si hay un ganador o el juego termina empatado.
		contarMoviRealizados++;

		// Llama al metodo que realiza la colocacion de imagenes segun el tipo de jugador que este jugando
		cambioLetrasJugadores(letraJugador, numeroJugador);

		// Dibuja los cambios de los botones mediante un vector que contiene los valores de matriz de movimientos 
		// efectuados por los juegador de la clase nivel facil
		//----------------------------------------------------------------------------------------------------

		// AQUI PASA EL VECTOR CON LA INFOMACION DE SLECCION MATRIZ DE JUEGO NIVEL MEDIO

		//  dibujarBotonesMatriz(mod1.vectorGuardaMatriz(), window);

		//----------------------------------------------------------------------------------------------------

		// Tiene que pasar un bool con el estado de juegador 1 y jugador 2 (maquina) de ganador de la
		// clase nivel facil

		verificarEstatusGanador(false, false, /*mod1.verificaGanadorJugador1(), mod1.verificaGanadorJugador2(),*/
			numeroJugador, contarMoviRealizados);

	}
	// Falso si no se cumple que se pueda realizar la jugada el estado cambia a falso y no modifica el turno, 
	// ni realiza un cambio en pantalla y jugador con turno puede intentar elegir otro posicion mientras en el juego
	// no haya terminado por haber un ganador o empate.
	else { jugadaRealizada = false; } // por defecto se resetea la vaciable de jugada realizada
	return jugadaRealizada;
}

// Metodo que valida los eventos graficos del modo de juego jugador vs CPU - dificualtad:::Normal y
// determina si con la jugada realizada por el juegador 1 o la maquina, tambien determina el ganador
// mediante la jugada realizada yactualizara el estado de jugador ganador o maquina y de lo contrario
// determinara un empate en la partida.
bool gato::verificarPosibleJugadaModoMedio(unsigned int numeroBoton, unsigned int numeroJugador, char letraJugador, sf::RenderWindow& window)
{
	// <<<<<<<<<<<<<<   Llama a los metodos de la clase nivel normal (medio)  >>>>>>>>>>>>>>>>>

	// Si se cumple que se puede seleccionar la casilla elegida && todavia no hay un ganador oun empate se interpreta
	// como verdadero que la jugada realizada es correcta y actualiza cambios en la matriz de botnones del juego

	/// el metodo comentado es de nivel normal
	if (/*mod1.verificarPosibleJugada(numeroBoton, numeroJugador, letraJugador) &&*/ !ganadorJugador1
		&& !ganadorJugador2 && !noGanadorFinal) {

		// Cambio el estado de jugada realizada a verdadero
		jugadaRealizada = true;

		// cuenta los movimientos correctos para saber si ya se realizaron los movimientos totales del juego
		// y asi determinar si hay un ganador o el juego termina empatado.
		contarMoviRealizados++;

		// Llama al metodo que realiza la colocacion de imagenes segun el tipo de jugador que este jugando
		cambioLetrasJugadores(letraJugador, numeroJugador);

		// Dibuja los cambios de los botones mediante un vector que contiene los valores de matriz de movimientos 
		// efectuados por los juegador de la clase medio

		//----------------------------------------------------------------------------------------------------

		// AQUI PASA EL VECTOR CON LA INFOMACION DE SLECCION MATRIZ DE JUEGO NIVEL MEDIO

		//  dibujarBotonesMatriz(mod1.vectorGuardaMatriz(), window);

		//----------------------------------------------------------------------------------------------------



		// Tiene que pasar un bool con el estado de juegador 1 y jugador 2 (maquina) de ganador de la
		// clase nivel normal

		verificarEstatusGanador(false, false, /*mod1.verificaGanadorJugador1(), mod1.verificaGanadorJugador2(),*/
			numeroJugador, contarMoviRealizados);

	}
	// Falso si no se cumple que se pueda realizar la jugada el estado cambia a falso y no modifica el turno, 
	// ni realiza un cambio en pantalla y jugador con turno puede intentar elegir otro posicion mientras en el juego
	// no haya terminado por haber un ganador o empate.
	else { jugadaRealizada = false; } // por defecto se resetea la vaciable de jugada realizada
	return jugadaRealizada;
}

// Metodo que valida los eventos graficos del modo de juego jugador vs CPU - dificualtad:::Dificil y 
// determina si con la jugada realizada por el juegador 1 o la maquina, tambien determina el ganador
// mediante la jugada realizada yactualizara el estado de jugador ganador o maquina y de lo contrario 
// determinara un empate en la partida.
bool gato::verificarPosibleJugadaModoDificil(unsigned int numeroBoton, unsigned int numeroJugador, char letraJugador, sf::RenderWindow& window)
{

	// Si se cumple que se puede seleccionar la casilla elegida && todavia no hay un ganador oun empate se interpreta
	// como verdadero que la jugada realizada es correcta y actualiza cambios en la matriz de botnones del juego
	if (nD.verificarPosibleJugada(numeroBoton, numeroJugador, letraJugador) && !ganadorJugador1
		&& !ganadorJugador2 && !noGanadorFinal) {

		// Cambio el estado de jugada realizada a verdadero
		jugadaRealizada = true;

		// cuenta los movimientos correctos para saber si ya se realizaron los movimientos totales del juego
		// y asi determinar si hay un ganador o el juego termina empatado.
		contarMoviRealizados++;
		// Llama al metodo que realiza la colocacion de imagnes segun el tipo de jugador que este jugando
		cambioLetrasJugadores(letraJugador, numeroJugador);

		// Dibuja los cambios de los botones mediante un vector que contiene los valores de matriz de movimientos 
		// efectuados por los juegador de la clase modoJuego1
		dibujarBotonesMatriz(nD.vectorGuardaMatrizDificil(), window);

		// Se hace el llamado del metodo que comprueba si sigue mostrando los cambios en la matriz del juego
		// o notifica a la vista para que muestre el resultado final del juego.
		verificarEstatusGanador(nD.GetGanadorJ1(), nD.GetGanadorJ2(),
			numeroJugador, contarMoviRealizados);

	}
	// Falso si no se cumple que se pueda realizar la jugada el estado cambia a falso y no modifica el turno, 
	// ni realiza un cambio en pantalla y jugador con turno puede intentar elegir otro posicion mientras en el juego
	// no haya terminado por haber un ganador o empate.
	else { jugadaRealizada = false; } // por defecto se resetea la vaciable de jugada realizada
	return jugadaRealizada;
}

// Metodo que realiza la comprobacion que por movimientos de los jugadores que son 9 posibles y
// comprueba mediante el estado de ganador jugador 1 o jugador 2 de la clase del nivel correspondiente
// si debe notificar a la vista que detenga la actualizacion de la matriz de juego y muestre la parte
// visual de que ya el juego acabo y muestre el resultado final , gandor jugador 1 , juegador 2
// o que durante el juego no existio ningun ganador y por lo tanto es un empate.
void gato::verificarEstatusGanador(bool verificacionGanadorJugador1, bool verificacionGanadorJugador2,
	unsigned int numeroJugador, unsigned int movimientosRealizados) {
	// Si de determina que verdadero que jugador 1 gano && los movimientos correctos es menor o igual
	// a 9 y le numero de jugador en el turno es el jugador 1, se interpreta que gano la partida del juego.
	if (verificacionGanadorJugador1 && contarMoviRealizados <= 9 && numeroJugador == 1) {
		cout << "\n :::::::::::		J U G A D O R  1  G A N O !!	:::::::::::::::::::::::\n";
		// Actualiza el estado que jugador 1 gano es verdadero
		ganadorJugador1 = true;
	}
	// Falso Si de determina que verdadero que jugador 2 gano && los movimientos correctos es menor o igual
	// a 9 y le numero de jugador en el turno es el jugador 2, se interpreta que gano la partida del juego.
	else if (verificacionGanadorJugador2 && contarMoviRealizados <= 9 && numeroJugador == 2) {
		cout << "\n :::::::::::		J U G A D O R  2  G A N O !!	:::::::::::::::::::::::\n";
		// Actualiza el estado que jugador 2 gano es verdadero
		ganadorJugador2 = true;
	}
	// Falso Si de determina que el jugador 1 && jugador 2 no ganaron &&  que los movimientos correctos 
	// realizados es igual a 9 se interpreta que nadie gano el juego y que termina la partida.
	else if (!verificacionGanadorJugador1 && !verificacionGanadorJugador2 && contarMoviRealizados == 9) {
		cout << "\n :::::::::::::::			E M P A T E !!		:::::::::::::::::::::::\n";
		// Actualiza el estado que ningun jugador gano y es un empate a verdadero
		noGanadorFinal = true;
	}
}

// Metodo que actualiza la matriz mostrada en pantalla de modo jugador vs jugador
void gato::actualizaMatrizMod1(sf::RenderWindow& window)
{
	dibujarBotonesMatriz(mod1.vectorGuardaMatriz(), window);
}

// Metodo que actualiza la matriz mostrada en pantalla del nivel facil:: jugador VS CPU
void gato::actualizaMatrizNivelFacil(sf::RenderWindow& window)
{
	//dibujarBotonesMatriz(mod1.vectorGuardaMatriz(), window);

}

// Metodo que actualiza la matriz mostrada en pantalla del nivel normal:: jugador VS CPU
void gato::actualizaMatrizNivelMedio(sf::RenderWindow& window)
{
	//dibujarBotonesMatriz(mod1.vectorGuardaMatriz(), window);

}

// Metodo que actualiza la matriz mostrada en pantalla del nivel dificil:: jugador VS CPU
void gato::actualizaMatrizNivelDificil(sf::RenderWindow& window)
{
	dibujarBotonesMatriz(nD.vectorGuardaMatrizDificil(), window);
}

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

// Metodo que obtiene los valores del vector de matriz de juego y lee uno por uno su contenido y
// asi determina la textura de cada boton del juego mostrado en pantalla
void gato::dibujarBotonesMatriz(vector<char> vectorAux, sf::RenderWindow& window)
{
	// Cliclo for que recorre el tamaño del vector y actualiza las las texturas de las imagnes que simulan 
	// la matriz de botones en pantalla.
	for (unsigned int i = 0; i < vectorAux.size(); i++) {
		// se llama al metodo de actualizar texturas de imgenes y se le pasa el numero de boton
		// la ventana (para que dibuje) y se encapsula el metodo de determinar imagen textura 
		// este devuelve una objeto tipo textura de acuerdo con el caracter encontrado en la posicion
		// del vector y devuelve la imagen correcta si es una iamgen de X, O u una en blaco
		// la cual se pasa como tercer paramentro a actualiza imagen boton y finalmente lo actualiza. 
		actualizaImgBoton(i, window, determinarImagenTextura(vectorAux.at(i)));
	}
	window.display(); // actualiza cambios en pantalla
}

// Metodo que actualiza la img de cada boton segun la eleccion o no de cada jugador que se mostraran
// en la matriz de botones que se dibujara en pantalla. 
void gato::actualizaImgBoton(unsigned int nBoton, sf::RenderWindow& window, sf::Texture aux) {
	// Switch determina el numero de boton a actualizar con la nueva imagen
	switch (nBoton)
	{
	case 0: // Dibuja y setea la textura del boton 1
		boton1Image.setTexture(aux); boton1Image.setPosition(317.0f, 200.0f);
		window.draw(boton1Image); break;

	case 1: // Dibuja y setea la textura del boton 2
		boton2Image.setTexture(aux); boton2Image.setPosition(450.0f, 200.0f);
		window.draw(boton2Image); break;

	case 2:// Dibuja y setea la textura del boton 3
		boton3Image.setTexture(aux); boton3Image.setPosition(583.0f, 200.0f);
		window.draw(boton3Image); break;

	case 3:// Dibuja y setea la textura del boton 4
		boton4Image.setTexture(aux); boton4Image.setPosition(317.0f, 333.0f);
		window.draw(boton4Image); break;

	case 4:// Dibuja y setea la textura del boton 5
		boton5Image.setTexture(aux); boton5Image.setPosition(450.0f, 333.0f);
		window.draw(boton5Image); break;

	case 5:// Dibuja y setea la textura del boton 6
		boton6Image.setTexture(aux); boton6Image.setPosition(583.0f, 333.0f);
		window.draw(boton6Image); break;

	case 6:// Dibuja y setea la textura del boton 7
		boton7Image.setTexture(aux); boton7Image.setPosition(317.0f, 466.0f);
		window.draw(boton7Image); break;

	case 7:// Dibuja y setea la textura del boton 8
		boton8Image.setTexture(aux); boton8Image.setPosition(450.0f, 466.0f);
		window.draw(boton8Image); break;

	case 8:// Dibuja y setea la textura del boton 9
		boton9Image.setTexture(aux);  boton9Image.setPosition(583.0f, 466.0f);
		window.draw(boton9Image); break;
	}
}

// Metodo se encarga de obtener el tamaño de los botones
void gato::obtenerTamanioImgBotones() {
	// Gaurda la medida del ancho y largo del boton 1
	boton1Width = boton1Image.getLocalBounds().width;
	boton1Height = boton1Image.getLocalBounds().height;
	// Gaurda la medida del ancho y largo del boton 2
	boton2Width = boton2Image.getLocalBounds().width;
	boton2Height = boton2Image.getLocalBounds().height;
	// Gaurda la medida del ancho y largo del boton 3
	boton3Width = boton3Image.getLocalBounds().width;
	boton3Height = boton3Image.getLocalBounds().height;
	// Gaurda la medida del ancho y largo del boton 4
	boton4Width = boton4Image.getLocalBounds().width;
	boton4Height = boton4Image.getLocalBounds().height;
	// Gaurda la medida del ancho y largo del boton 5
	boton5Width = boton5Image.getLocalBounds().width;
	boton5Height = boton5Image.getLocalBounds().height;
	// Gaurda la medida del ancho y largo del boton 6
	boton6Width = boton6Image.getLocalBounds().width;
	boton6Height = boton6Image.getLocalBounds().height;
	// Gaurda la medida del ancho y largo del boton 7
	boton7Width = boton7Image.getLocalBounds().width;
	boton7Height = boton7Image.getLocalBounds().height;
	// Gaurda la medida del ancho y largo del boton 8
	boton8Width = boton8Image.getLocalBounds().width;
	boton8Height = boton8Image.getLocalBounds().height;
	// Gaurda la medida del ancho y largo del boton 9
	boton9Width = boton9Image.getLocalBounds().width;
	boton9Height = boton9Image.getLocalBounds().height;
}

// Este metodo indica con el evento del mause la flecha esta hubicada encima de algun boton dle juego.
void gato::pintarColorBotonEncima(sf::RenderWindow& window) {
	mousePos = sf::Mouse::getPosition(window);
	sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
	// Si el mause esta hubicado encima del boton 1
	if (boton1Image.getGlobalBounds().contains(mousePosF)) {
		// Pinta de color verde la imagen que el curso esta encima y desmarca las otras imagnes
		boton1Image.setColor(sf::Color(0, 100, 100)); desSeleccionaBotonesMatriz(0);
	}
	// Falso si el boton esta hubicado encima del boton 2
	else if (boton2Image.getGlobalBounds().contains(mousePosF)) {
		// Pinta de color verde la imagen que el curso esta encima y desmarca las otras imagnes
		boton2Image.setColor(sf::Color(0, 100, 100)); desSeleccionaBotonesMatriz(1);
	}
	// Falso si el boton esta hubicado encima del boton 3
	else if (boton3Image.getGlobalBounds().contains(mousePosF)) {
		// Pinta de color verde la imagen que el curso esta encima y desmarca las otras imagnes
		boton3Image.setColor(sf::Color(0, 100, 100)); desSeleccionaBotonesMatriz(2);
	}
	// Falso si el boton esta hubicado encima del boton 4
	else if (boton4Image.getGlobalBounds().contains(mousePosF)) {
		// Pinta de color verde la imagen que el curso esta encima y desmarca las otras imagnes
		boton4Image.setColor(sf::Color(0, 100, 100)); desSeleccionaBotonesMatriz(3);
	}
	// Falso si el boton esta hubicado encima del boton 5
	else if (boton5Image.getGlobalBounds().contains(mousePosF)) {
		// Pinta de color verde la imagen que el curso esta encima y desmarca las otras imagnes
		boton5Image.setColor(sf::Color(0, 100, 100)); desSeleccionaBotonesMatriz(4);
	}
	// Falso si el boton esta hubicado encima del boton 6
	else if (boton6Image.getGlobalBounds().contains(mousePosF)) {
		// Pinta de color verde la imagen que el curso esta encima y desmarca las otras imagnes
		boton6Image.setColor(sf::Color(0, 100, 100)); desSeleccionaBotonesMatriz(5);
	}
	// Falso si el boton esta hubicado encima del boton 7
	else if (boton7Image.getGlobalBounds().contains(mousePosF)) {
		// Pinta de color verde la imagen que el curso esta encima y desmarca las otras imagnes
		boton7Image.setColor(sf::Color(0, 100, 100)); desSeleccionaBotonesMatriz(6);
	}
	// Falso si el boton esta hubicado encima del boton 8
	else if (boton8Image.getGlobalBounds().contains(mousePosF)) {
		// Pinta de color verde la imagen que el curso esta encima y desmarca las otras imagnes
		boton8Image.setColor(sf::Color(0, 100, 100)); desSeleccionaBotonesMatriz(7);
	}
	// Falso si el boton esta hubicado encima del boton 9
	else if (boton9Image.getGlobalBounds().contains(mousePosF)) {
		// Pinta de color verde la imagen que el curso esta encima y desmarca las otras imagnes
		boton9Image.setColor(sf::Color(0, 100, 100)); desSeleccionaBotonesMatriz(8);
	}
}

//	Metodo que des-selecciona el color de los botones diferentes al actual marcado
// por el cursor del mause
void gato::desSeleccionaBotonesMatriz(unsigned int nBoton) {
	// Ciclo for que recorre nueve posiciones misma cantidad de botones empleados en la matriz de botones.
	for (unsigned int n = 0; n < CANT_BOTONES; n++) {
		// Si el boton la letra n del ciclo es diferente al boton indicado que esta seleccionado
		// proceda a buscar ese numero de boton y cambiarle el color a trasparente.
		if (n != nBoton) {
			// Switch determina el numero de boton a desSeleccionar el color
			switch (n)
			{
			case 0: // Des-selecciona el boton 1
				boton1Image.setColor(sf::Color(255, 255, 255)); break;
			case 1: // Des-selecciona el boton 2
				boton2Image.setColor(sf::Color(255, 255, 255)); break;
			case 2:// Des-selecciona el boton 3
				boton3Image.setColor(sf::Color(255, 255, 255)); break;
			case 3:// Des-selecciona el boton 4
				boton4Image.setColor(sf::Color(255, 255, 255)); break;
			case 4:// Des-selecciona el boton 5
				boton5Image.setColor(sf::Color(255, 255, 255)); break;
			case 5:// Des-selecciona el boton 6
				boton6Image.setColor(sf::Color(255, 255, 255)); break;
			case 6:// Des-selecciona el boton 7
				boton7Image.setColor(sf::Color(255, 255, 255)); break;
			case 7:// Des-selecciona el boton 8
				boton8Image.setColor(sf::Color(255, 255, 255)); break;
			case 8:// Des-selecciona el boton 9
				boton9Image.setColor(sf::Color(255, 255, 255)); break;
			}
		}
	}
}

// Metodo que actualiza el estado de la variable boton seleccionado, cuando detecta que el jugador 
// realizo un click encima de la imagen que simula una matriz de botones en pantalla.
void gato::accionSeleccionarBoton(sf::RenderWindow& window, unsigned int numeroJugador) {
	mousePos = sf::Mouse::getPosition(window);
	sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

	// Si el usuario le dio click al boton 1
	if (boton1Image.getGlobalBounds().contains(mousePosF)) { botonSeleccionado = 1; }
	// Falso Si el usuario le dio click al boton 2
	else if (boton2Image.getGlobalBounds().contains(mousePosF)) { botonSeleccionado = 2; }
	// Falso Si el usuario le dio click al boton 3
	else if (boton3Image.getGlobalBounds().contains(mousePosF)) { botonSeleccionado = 3; }
	// Falso Si el usuario le dio click al boton 4
	else if (boton4Image.getGlobalBounds().contains(mousePosF)) { botonSeleccionado = 4; }
	// Falso Si el usuario le dio click al boton 5
	else if (boton5Image.getGlobalBounds().contains(mousePosF)) { botonSeleccionado = 5; }
	// Falso Si el usuario le dio click al boton 6
	else if (boton6Image.getGlobalBounds().contains(mousePosF)) { botonSeleccionado = 6; }
	// Falso Si el usuario le dio click al boton 7
	else if (boton7Image.getGlobalBounds().contains(mousePosF)) { botonSeleccionado = 7; }
	// Falso Si el usuario le dio click al boton 8
	else if (boton8Image.getGlobalBounds().contains(mousePosF)) { botonSeleccionado = 8; }
	// Falso Si el usuario le dio click al boton 9
	else if (boton9Image.getGlobalBounds().contains(mousePosF)) { botonSeleccionado = 9; }
	// Falso si no se le dio un click a ningun boton se determina por defecto el valor de boton seleccionado a 0
	else { botonSeleccionado = 0; }
}

// Metodo que realiza el cambio de letras segun la eleccion de tipo y numero de jugador.
void gato::cambioLetrasJugadores(char letraJugador, unsigned int numeroJugador) {
	// Actualiza con que letra esta realizando la jugada el jugador 
	// Si es jugador 1 actualiza la letra con la que juega
	if (numeroJugador == 1) { letraJugador1 = letraJugador; }
	// Falso Si es jugador 2 actualiza la letra con la que juega
	else if (numeroJugador == 2) { letraJugador2 = letraJugador; }
}

// Metodo que evalua a  que nuero de boton a a asignar la letra correspondiente de jugador sea 
// jugador uno o dos la letra con la que juega al incio del juego.
sf::Texture gato::determinarImagenTextura(char letraJuegador) {
	sf::Texture auxImagenAPoner;
	// Si la letra del jugador es X pone la textura de la imagen X
	if (letraJuegador == 'X') { auxImagenAPoner = jugadorX; }
	// Falso Si la letra del jugador es X pone la textura de la imagen O
	else if (letraJuegador == 'O') { auxImagenAPoner = jugadorO; }
	// Falso Si la letra es un guion pone la textura de la imagen en blanco
	else if (letraJuegador == '-') { auxImagenAPoner = espacioVacio; }

	// De acuerdo a la variable aux de la textura segun la letra del juegador o valor que se pidio asignar
	// se pasa a la variable global actualizarImagenAux, quien la usara para actualizar la imagenes de botones
	// en otro metodo especifico.
	actualizaImagenAux = auxImagenAPoner;
	return actualizaImagenAux;
}

// Metodo que dibuja una imagen espeficica en la pantalla
void gato::dibujarImagenEspecifica(sf::RenderWindow& window, int tipoImg) {
	// Si el tipo de imagen es 1 dibujara el titulo en pantalla
	if (tipoImg == 1) { obj.setTexture(tituloJuego); obj.setPosition(75.0f, 50.0f); }
	// Falso si se pide el 2 dibujara la img de la X
	else if (tipoImg == 2) { obj.setTexture(jugadorX); obj.setPosition(650.0f, 290.0f); }
	// Falso si se pide el 3 dibujara la img de la O
	else if (tipoImg == 3) { obj.setTexture(jugadorO); obj.setPosition(650.0f, 430.0f); }
	// Falso si se pide el 4 dibujara el turno de seleccion jugador 1
	else if (tipoImg == 4) { obj.setTexture(turnoSeleccion1); obj.setPosition(200.0f, 200.0f); }
	// Falso si se pide el 5 dibujara el turno de seleccion jugador 2
	else if (tipoImg == 5) { obj.setTexture(turnoSeleccion2); obj.setPosition(200.0f, 200.0f); }
	// Falso si se pide img 6 es la imagen del circulo en otra posicion (para jugador 2)
	else if (tipoImg == 6) { obj.setTexture(jugadorO); obj.setPosition(650.0f, 290.0f); }
	// Falso si es img 7 dibuja el nombre del jugador 1
	else if (tipoImg == 7) { obj.setTexture(jugadorE1); obj.setPosition(385.0f, 125.0f); }
	// Falso si es img 7 dibuja el nombre del jugador 1
	else if (tipoImg == 8) { obj.setTexture(jugadorE2); obj.setPosition(385.0f, 125.0f); }
	// Falso Si el tipo de imagen es 9 dibujara el titulo en pantalla en una posicion mas alta
	else if (tipoImg == 9) { obj.setTexture(tituloJuego); obj.setPosition(75.0f, 5.0f); }
	// Falso Si el tipo de imagen es 10 siginifica que dibujara la imagen de ganador jugador 1
	else if (tipoImg == 10) { obj.setTexture(jugadorGano1); obj.setPosition(150.0f, 230.0f); }
	// Falso Si el tipo de imagen es 11 siginifica que dibujara la imagen de ganador jugador 2
	else if (tipoImg == 11) { obj.setTexture(jugadorGano2); obj.setPosition(150.0f, 230.0f); }
	// Falso Si el tipo de imagen es 12 siginifica que dibujara la imagen de empate
	else if (tipoImg == 12) { obj.setTexture(empate); obj.setPosition(170.0f, 230.0f); }
	window.draw(obj); // Dibuja el objeto en pantalla dependiento del numero de imgen escogida
}

// Metodo que se encarga de cargar los sonidos dle juego
void gato::cargarSonidos() {

	if (!musica.openFromFile(DIR_PAUSA)) {
		//Error al cargar la musica del menu de pausa
		cout << "\nHa ocurrido un error al cargar el archivo de musica de pausa\n\n";
	}
	if (!musicaTeclas.loadFromFile(DIR_MUSICA_TECLAS)) {
		//Error al cargar la musica del menu de teclas
		cout << "\nHa ocurrido un error al cargar el archivo de musica de teclas\n\n";
	}
	if (!musicaFondo.loadFromFile(DIR_MUSICA_FONDO)) {
		//Error al cargar la musica del menu de fondo
		cout << "\nHa ocurrido un error al cargar el archivo de musica de fondo\n\n";
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
	sonido.play(); // reproduce el numero de sonido seleccionado para el juego.
}

// Metodo que se encarga de pausar o detener los sonidos del juego
void gato::detenerSonido() {
	sonido.setLoop(false);
	sonido.stop();
	musica.stop();
}


