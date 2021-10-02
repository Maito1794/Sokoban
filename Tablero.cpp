#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Tablero.h"

using namespace std;

void Tablero::leerArchivo(string archivo) {

	for (int i = 0; i < 100; i++) {
		cadena[i] = NULL;
	}

	int cont = 0;
	ifstream inFile;
	inFile.open(archivo);

	if (!inFile) {
		cout << "Ocurrio un error abriendo el archivo";
	}
	string line;
	string texto;

	while (getline(inFile, line)) {
		texto += line;
		cont++;
	}

	for (int i = 0; i < texto.size(); i++) {
		cadena[i] = texto.at(i);
	}


	//for (int i = 0; i < 100; i++) {
	//	std::cout << cadena[i];
	//}

	cout << "\n";
}
void Tablero::crearMatriz() {
	head = NULL;
	nodo *p = NULL, *q = NULL, *r = NULL;
	int cont = 0;

	for (int i = 1; i < 11; i++) {
		for (int j = 1; j < 11; j++) {
			p = new struct nodo;
			p->dato = cadena[cont];
			p->sig = NULL;
			p->abajo = NULL;

			if (j == 1) {
				p->ant = NULL;
				if (head == NULL) {
					head = p;
				}
				q = p;

			}
			else {
				p->ant = q;
				q->sig = p;
				q = p;
			}
			if (i == 1) {
				p->arriba = NULL;
				q = p;
			}
			else {
				p->arriba = r;
				r->abajo = p;
				r = r->sig;

			}

			cont++;

		}
		r = head;

		while (r->abajo != NULL) {
			r = r->abajo;
		}
	}

}

void Tablero::mostrarMatriz() {
	nodo* p = NULL, * q = NULL;
	if (head != NULL) {
		p = head;
		// se recorre las filas
		while (p != NULL) {
			q = p;
			// se recorren columnas
			while (q != NULL) {
				cout << q->dato << "  ";
				q = q->sig;
			}
			cout << "\n";
			p = p->abajo;

		}
	}
	else {
		cout << "lista vacia...\n";
	}
	
}

Tablero::Tablero(float width, float height) {
	fuente.loadFromFile("Letra_Pixel.ttf");
	titulo.setFont(fuente);
	titulo.setFillColor(Color::Blue);
	titulo.setString("SOKOBAN");
	titulo.setPosition(10, 0);
	titulo.setCharacterSize(60);
}

void Tablero::cargarNiveles(int nivel) {
	switch (nivel) {
	case 1:
		leerArchivo("resources/niveles/nivel1.txt");
		fondoTablero.loadFromFile("resources/fondo_tablero/fondo_tablero1.png");
		break;

	case 2:
		leerArchivo("resources/niveles/nivel2.txt");
		
		fondoTablero.loadFromFile("resources/fondo_tablero/fondo_tablero2.png");
		break;

	case 3:
		leerArchivo("resources/niveles/nivel3.txt");
		fondoTablero.loadFromFile("resources/fondo_tablero/fondo_tablero3.png");
		break;

	case 4:
		leerArchivo("resources/niveles/nivel4.txt");
		fondoTablero.loadFromFile("resources/fondo_tablero/fondo_tablero4.png");
		break;

	case 5:
		leerArchivo("resources/niveles/nivel5.txt");
		fondoTablero.loadFromFile("resources/fondo_tablero/fondo_tablero5.png");
		break;

	default:
		break;
	}
	
	crearMatriz();
	mostrarMatriz();
	cargarFondoTablero.setTexture(fondoTablero);
	cargarFondoTablero.setPosition(20, 20);
}


void Tablero::mostrarTablero(RenderWindow& window, int nivel) {
	bool cerrar = false;

	cargarNiveles(nivel);
	
	while (!cerrar) {

		sf::Event event;

		while (window.pollEvent(event)) {
			switch (event.type) {

			case sf::Event::KeyReleased:
				switch (event.key.code) {
				case Keyboard::Enter:
					cerrar = true;
					break;
				}
				break;
			case sf::Event::Closed:
				cerrar = true;
				window.close();
				break;
			}
			window.clear();
			window.draw(cargarFondoTablero);
			window.draw(titulo);
			window.display();
		}

	}
}
