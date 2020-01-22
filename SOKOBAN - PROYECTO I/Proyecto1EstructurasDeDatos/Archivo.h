
// Archivo.h
// Autores: Kislev Aleman, Josua Esquivel y Néstor Leiva
// Definicion de la clase Archivo.h


#include"ListaEnlazada.h"
#include<string>
#include<iostream>

//	Definimos la ubicacion delos archivos con los niveles y para guarda la partida anterior
#define DIR_NIVEL1 "../archivos/nivel1.txt"
#define DIR_NIVEL2 "../archivos/nivel2.txt"
#define DIR_NIVEL3 "../archivos/nivel3.txt"
#define DIR_NIVEL4 "../archivos/nivel4.txt"
#define DIR_NIVEL5 "../archivos/nivel5.txt"
#define PART_ANTERIOR "../archivos/partidaAnterior.txt"


struct Archivo {

	Archivo(); //contructor archivo vacio

	std::string seleccionNivel(int);
	void  leerArchivosDeNiveles(std::string nombreArchivo, ListaEnlazada lista, NodoLista*& actual);
	void escribirArchivo(std::string dato);

};