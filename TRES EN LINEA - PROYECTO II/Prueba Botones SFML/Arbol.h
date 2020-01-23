
// gato.h
// Autores: Kislev Aleman, Josua Esquivel y Néstor Leiva
// Descripción: Definicion de la clase gato.h

#ifndef ARBOL_H
#define ARBOL_H


struct Nodo
{
	// int matriz[3][3];
	int probabilidad;
	Nodo* hermanoIzquierda;
	Nodo* hijoDerecho;

};


class Arbol
{
public:

	Arbol() { raiz = nullptr; };
	~Arbol() { BorrarArbol(); };
	void InteligenciaArtificial();

private:

	Nodo* raiz;

	void insertar();

	void busquedaNivel1();
	void busquedaNivel2();
	void busquedaNivel3();

	void BorrarArbol();
};


#endif

