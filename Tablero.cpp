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

void Tablero::mostrarMatriz(RenderWindow& window1) {
	
	nodo* p = NULL, * q = NULL;
	int x = 25, y = 25; 
	if (head != NULL) {
		p = head;
		// se recorre las filas
		while (p != NULL) {
			q = p;
			cout << "x:  "<< x <<"y "<< y ;
			// se recorren columnas
			while (q != NULL) {
				cout << q->dato << "  ";
				if (q->dato == 35) {// # paredes

					pared.loadFromFile("resources/sprite/pared_cafe.png");
					cargarPared.setTexture(pared);
					cargarPared.setPosition(x, y);
					window1.draw(cargarPared);
					x += 64;
				}
				else if (q->dato == 36) {// $ punto dede estara la caja al iniciar el juego.
					cajas.loadFromFile("resources/sprite/caja_roja.png");
					cargarCajas.setTexture(cajas);
					cargarCajas.setPosition(x, y);
					window1.draw(cargarCajas);
					x += 64;

				}
				else if (q->dato == 33) {// ! punto donde se tendra colocar la caja.
					puntoCaja.loadFromFile("resources/sprite/punto_rojo.png");
					cargarPuntoCaja.setTexture(puntoCaja);
					cargarPuntoCaja.setPosition(x, y);
					window1.draw(cargarPuntoCaja);
					x += 64;

				}
				else if (q->dato == 64) {// @ vichito
					personaje.loadFromFile("resources/sprite/personaje.png");
					cargarPersonaje.setTexture(personaje);
					cargarPersonaje.setPosition(x, y);
					window1.draw(cargarPersonaje);
					x += 64;

				}
				else if (q->dato == 32) {// espacio en blanco

					x += 64;

				}



				q = q->sig;
			}
			cout << "\n";
			
			p = p->abajo;
			x = 25;
			y += 64;

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
	//mostrarMatriz();
	cargarFondoTablero.setTexture(fondoTablero);
	cargarFondoTablero.setPosition(20, 20);
}


void Tablero::mostrarTablero(RenderWindow& window, int nivel) {
	bool cerrar = false;

	cargarNiveles(nivel);

	crearMatriz();

	
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
			mostrarMatriz(window);
			window.display();
			
		}
		

	}
	
}
