#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

struct nodo {
	char dato;
	nodo* sig;
	nodo* ant;
	nodo* arriba;
	nodo* abajo;
};



class Tablero {

private:
	nodo* head = NULL;
	char cadena[100];
	FILE* archivo;
	Text titulo;
	Font fuente;
	Texture fondoTablero;
	Sprite cargarFondoTablero;
	Image imagen;

public:
	void leerArchivo(string archivo);
	void crearMatriz();
	void mostrarMatriz();
	Tablero(float width, float height);
	void mostrarTablero(RenderWindow& window, int nivel);
	void validaciones(nodo *n);
	void jugar();
	void cargarNiveles(int nivel);

};
