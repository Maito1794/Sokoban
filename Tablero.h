#pragma once
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <stack>

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
	Text niv;
	Text nombreJugador;
	Text movimientos;
	Text tiempo;

	Time tiempoJuego;
	string nombreJ;
	string numNivel;
	int cantidadMovimientos;
	Font fuente;
	stack<int> colocado;

	Texture fondoTablero;
	Texture pared;
	Texture cajas;
	Texture personaje;
	Texture puntoCaja;
	Texture ubicacionCaja;

	Sprite cargarFondoTablero;
	Sprite cargarPared;
	Sprite cargarCajas;
	Sprite cargarPersonaje;
	Sprite cargarPuntoCaja;
	Sprite cargarUbicacionCaja;

public:
	string prueba;
	Tablero();
	void leerArchivo(string archivo);
	void crearMatriz();
	void mostrarMatriz(RenderWindow& window1);
	Tablero(float width, float height);
	void mostrarTablero(RenderWindow& window, int nivel);
	void validaciones(RenderWindow& window, string mov);
	void jugar();
	void cargarNiveles(int nivel);
	void pantallaDatos(RenderWindow& window);
	void setNombre(string nombre);
	void noGuardado(RenderWindow& window);
};
