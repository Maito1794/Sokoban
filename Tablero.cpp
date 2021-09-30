#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Tablero.h"

using namespace std;

void Tablero::leerArchivo() {

	for (int i = 0; i < 100; i++) {
		cadena[i] = NULL;
	}

	int cont = 0;
	ifstream inFile;
	inFile.open("ejemplo.txt");

	if (!inFile) {
		cout << "ocurrio un error abriendo el men";
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


	for (int i = 0; i < 100; i++) {
		std::cout << cadena[i];
	}

	std::cout << "\n";
}
void Tablero::crearMatriz() {
	
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
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
				std::cout << q->dato << "  ";
				q = q->sig;
			}
			std::cout << "\n";
			p = p->abajo;

		}
	}
	else {
		std::cout << "lista vacia...\n";
	}

}
