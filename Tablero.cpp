#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "Tablero.h"

using namespace std;

Tablero::Tablero() {

}

void Tablero::leerArchivo(string archivo) {
	colocado = 0;
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
	int x = 20, y = 20; 
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
				else if (q->dato == 36 || q->dato == 33) {// $ punto dede estara la caja al iniciar el juego.
					cajas.loadFromFile("resources/sprite/caja_roja.png");
					cargarCajas.setTexture(cajas);
					cargarCajas.setPosition(x, y);
					window1.draw(cargarCajas);
					x += 64;

				}
				else if (q->dato == 46 ) {// ! punto donde se tendra colocar la caja.
					puntoCaja.loadFromFile("resources/sprite/punto_rojo.png");
					cargarPuntoCaja.setTexture(puntoCaja);
					cargarPuntoCaja.setPosition(x+16, y+16);
					window1.draw(cargarPuntoCaja);
					x += 64;

				}
				else if (q->dato == 64 || q->dato == 38) {// @ vichito
					personaje.loadFromFile("resources/sprite/personaje.png");
					cargarPersonaje.setTexture(personaje);
					cargarPersonaje.setPosition(x+13, y+2);
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
			x = 20;
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
	titulo.setPosition(300, 0);
	titulo.setCharacterSize(20);
}

void Tablero::cargarNiveles(int nivel) {

	switch (nivel) {
	case 1:
		leerArchivo("resources/niveles/nivel1.txt");
		fondoTablero.loadFromFile("resources/fondo_tablero/fondo_tablero1.png");
		numNivel = "1";
		break;

	case 2:
		leerArchivo("resources/niveles/nivel2.txt");
		fondoTablero.loadFromFile("resources/fondo_tablero/fondo_tablero2.png");
		numNivel = "";
		numNivel = "2";
		break;

	case 3:
		leerArchivo("resources/niveles/nivel3.txt");
		fondoTablero.loadFromFile("resources/fondo_tablero/fondo_tablero3.png");
		numNivel = "";
		numNivel = "3";
		break;

	case 4:
		leerArchivo("resources/niveles/nivel4.txt");
		fondoTablero.loadFromFile("resources/fondo_tablero/fondo_tablero4.png");
		numNivel = "";
		numNivel = "4";
		break;

	case 5:
		leerArchivo("resources/niveles/nivel5.txt");
		fondoTablero.loadFromFile("resources/fondo_tablero/fondo_tablero5.png");
		numNivel = "";
		numNivel = "5";
		break;

	default:
		break;
	}
	
	crearMatriz();
	//mostrarMatriz();
	cargarFondoTablero.setTexture(fondoTablero);
	cargarFondoTablero.setPosition(20, 20);
}

void Tablero::pedirNombre() {
	cout << "BIENVENIDO (A) a Sokoban. Digite su nombre:" << endl;
	cin >> nombreJ;
}

void Tablero::pantallaDatos(RenderWindow& window) {
	fuente.loadFromFile("Letra_Pixel.ttf");

	niv.setFont(fuente);
	niv.setString("Nivel " + numNivel);
	niv.setPosition(770, 20);
	niv.setFillColor(Color::White);
	niv.setCharacterSize(40);


	nombreJugador.setFont(fuente);
	nombreJugador.setString("Jugador:");

	window.draw(niv);

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
				
				case Keyboard::Up:
					validaciones(window, "arri");
					break;

				case Keyboard::Down:
					validaciones(window, "abajo");
					break;
				case Keyboard::Left:
					validaciones(window, "izq");
					break;
				case Keyboard::Right:
					validaciones(window, "dere");
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
			if (colocado == 2) {
				fuente.loadFromFile("Letra_Pixel.ttf");
				Text gano;
				gano.setString("GANASTE!!!!!!!!!!");
				gano.setPosition(660, 330);
				gano.setFont(fuente);
				window.draw(gano);
			}
			pantallaDatos(window);
			window.display();
			
		}
		

	}
	
}

void Tablero::validaciones(RenderWindow& window, string mov) {
	

	cout << "dentro a validaciones";
	nodo* p = NULL, * q = NULL, *aux = NULL, *relevo = NULL; 
	if (head != NULL) {
		p = head;
		// se recorre las filas
		while (p != NULL) {
			q = p;
			// se recorren columnas
			while (q != NULL) {

				if (q->dato == 64 || q->dato == 38) {//@ &
					aux = q;
					break;
				}
				else {
					q = q->sig;
				}

			}
			cout << "\n";

			p = p->abajo;

		}
	}

	if (mov =="izq") {
		if (aux->ant->dato == 32) { // valida si esta en blanco
			aux->ant->dato = 64;
			if (aux->dato == 64) {
				aux->dato = 32;
			}
			else {
				aux->dato = 46;
			}
		}
		else if (aux->ant->dato == 46) {
			aux->ant->dato = 38;
			if (aux->dato == 64) {
				aux->dato = 32;
			}
			else {
				aux->dato = 46;
			}

		}

		else if (aux->ant->dato == 36) { // valida si hay una caja
			relevo = aux->ant;
			if (relevo->ant->dato == 32 ) { // si al frende la caja esta en blanco
				

				relevo->ant->dato = relevo->dato;
				relevo->dato = 64;
				if (aux->dato == 64) {
					aux->dato = 32;
				}
				else {
					aux->dato = 46;
				}
				
			}
			else if (relevo->ant->dato == 46) { // // si al frende la caja es un punto
				colocado++;
				relevo->ant->dato = 33;
				relevo->dato = 64;
				if (aux->dato == 64) {
					aux->dato = 32;
				}
				else {
					aux->dato = 46;
				}
			}

		}
		else if ( aux->ant->dato == 33) { // si es un signo de !
			relevo = aux->ant;
			if (relevo->ant->dato != 35) {
				colocado--;
				relevo->ant->dato = 36;
				relevo->dato = 38;
				aux->dato = 32;
			}
			

		}
		
	}

	if (mov == "dere") {
		if (aux->sig->dato == 32) {
			aux->sig->dato = 64;
			if (aux->dato == 64) {
				aux->dato = 32;
			}
			else {
				aux->dato = 46;
			}
		}
		else if (aux->sig->dato == 46) {
			aux->sig->dato = 38;
			if (aux->dato == 64) {
				aux->dato = 32;
			}
			else {
				aux->dato = 46;
			}

		}
		else if (aux->sig->dato == 36) {
			relevo = aux->sig;
			if (relevo->sig->dato == 32) {
				relevo->sig->dato = relevo->dato;
				relevo->dato = 64;
				if (aux->dato == 64) {
					aux->dato = 32;
				}
				else {
					aux->dato = 46;
				}
			}
			else if (relevo->sig->dato == 46) {
				colocado++;
				relevo->sig->dato = 33;
				relevo->dato = 64;
				if (aux->dato == 64) {
					aux->dato = 32;
				}
				else {
					aux->dato = 46;
				}
			}

		}
		else if (aux->sig->dato == 33) {
			relevo = aux->sig;
			if (relevo->sig->dato != 35) {
				colocado--;
				relevo->sig->dato = 36;
				relevo->dato = 38;
				aux->dato = 32;
			}
		}


	}

	if (mov == "arri") {
		if (aux->arriba->dato == 32) {
			aux->arriba->dato = 64;
			if (aux->dato == 64) {
				aux->dato = 32;
			}
			else {
				aux->dato = 46;
			}
		}
		else if (aux->arriba->dato == 46) {
			aux->arriba->dato = 38;
			if (aux->dato == 64) {
				aux->dato = 32;
			}
			else {
				aux->dato = 46;
			}

		}
		else if (aux->arriba->dato == 36) {
			relevo = aux->arriba;
			if (relevo->arriba->dato == 32) {
				
				relevo->arriba->dato = relevo->dato;
				relevo->dato = 64;
				if (aux->dato == 64) {
					aux->dato = 32;
				}
				else {
					aux->dato = 46;
				}
			}
			else if (relevo->arriba->dato == 46) {
				colocado++;
				relevo->arriba->dato = 33;
				relevo->dato = 64;
				if (aux->dato == 64) {
					aux->dato = 32;
				}
				else {
					aux->dato = 46;
				}
			}

		}
		else if (aux->arriba->dato == 33) {
			relevo = aux->arriba;
			if (relevo->arriba->dato != 35) {
				colocado--;
				relevo->arriba->dato = 36;
				relevo->dato = 38;
				aux->dato = 32;
			}
		}


	}
	if (mov == "abajo") {
		if (aux->abajo->dato == 32) {
			aux->abajo->dato = 64;
			if (aux->dato == 64) {
				aux->dato = 32;
			}
			else {
				aux->dato = 46;
			}
		}
		else if (aux->abajo->dato == 46) {
			aux->abajo->dato = 38;
			if (aux->dato == 64) {
				aux->dato = 32;
			}
			else {
				aux->dato = 46;
			}

		}
		else if (aux->abajo->dato == 36) {
			relevo = aux->abajo;
			if (relevo->abajo->dato == 32) {
				relevo->abajo->dato = relevo->dato;
				relevo->dato = 64;
				if (aux->dato == 64) {
					aux->dato = 32;
				}
				else {
					aux->dato = 46;
				}
			}
			else if (relevo->abajo->dato == 46) {
				colocado++;
				relevo->abajo->dato = 33;
				relevo->dato = 64;
				if (aux->dato == 64) {
					aux->dato = 32;
				}
				else {
					aux->dato = 46;
				}
			}

		}
		else if (aux->abajo->dato == 33) {
			relevo = aux->abajo;
			if (relevo->abajo->dato != 35) {
				colocado--;
				relevo->abajo->dato = 36;
				relevo->dato = 38;
				aux->dato = 32;
			}
		}


	}


}


