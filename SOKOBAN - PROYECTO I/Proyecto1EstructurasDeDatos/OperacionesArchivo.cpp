

// OperacionesArchivo.cpp
// Autores: Kislev Aleman, Josua Esquivel y Néstor Leiva
// Implementacion de los metodos para lectura y escritura de archivos



#include"Archivo.h"
#include"ListaEnlazada.h"
#include<iostream>
#include<string>
#include<fstream>




Archivo::Archivo() { } // contructor vacio 

// selccion de nivel
std::string Archivo::seleccionNivel(int numero) {

	std::string nombreArchivo = "";
	int numeroNivel = numero;

	if (numeroNivel == 1) {

		nombreArchivo = DIR_NIVEL1;
	}
	else if (numeroNivel == 2) {

		nombreArchivo = DIR_NIVEL2;
	}
	else if (numeroNivel == 3) {

		nombreArchivo = DIR_NIVEL3;
	}
	else if (numeroNivel == 4) {

		nombreArchivo = DIR_NIVEL4;
	}

	else if (numeroNivel == 5) {

		nombreArchivo = DIR_NIVEL5;
	}

	return nombreArchivo;
}

// lee los archivos por niveles 
void  Archivo::leerArchivosDeNiveles(std::string nombreArchivo, ListaEnlazada lista, NodoLista*& actual) {
	std::ifstream archivo;
	std::string linea;
	int numeroCaracteres;
	int contador = 0;

	archivo.open(nombreArchivo);

	if (archivo.is_open()) {

		while (std::getline(archivo, linea)) {

			numeroCaracteres = linea.length();
			//std::cout << numeroCaracteres <<"  ";
			for (int i = 0; i <= numeroCaracteres; i++) {
				//std::cout << i<<" ";
				if (linea[i] == ' ' || linea[i] == '#' || linea[i] == '$' || linea[i] == '.' || linea[i] == '@' || linea[i] == '!') {
					//std::cout << linea[i]<<std::endl;
					lista.insertar(actual, linea[i], contador);
				}
			}
			contador++;
		}
		archivo.close();
	}


}


//	Metodo que guarda en un archivo de texto los datos del juego.

void  Archivo::escribirArchivo(std::string dato) {

	std::ofstream archivo;

	archivo.open(PART_ANTERIOR, std::ios::app);

	if (archivo.is_open()) {

		archivo << dato;
		std::cout << "EXITO, SE GUARDO";
		archivo.close();
	}


}





