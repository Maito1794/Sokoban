#pragma once
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.hpp>

using namespace sf;

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
	int cont = 0;
	nodo* p, * q, * r;
	FILE* archivo;


public:
	void leerArchivo();
	void crearMatriz();
	void mostrarMatriz();


};
