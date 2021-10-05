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
	while (!colocado.empty()) {
		colocado.pop();
	}
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
					if (numNivel == "1") {
						cajas.loadFromFile("resources/sprite/caja_gris.png");
					}
					else if (numNivel == "2") {
						cajas.loadFromFile("resources/sprite/caja_morada.png");
					}
					else if (numNivel == "3") {
						cajas.loadFromFile("resources/sprite/caja_azul.png");
					}
					else if (numNivel == "4") {
						cajas.loadFromFile("resources/sprite/caja_roja.png");
					}
					else if (numNivel == "5") {
						cajas.loadFromFile("resources/sprite/caja_amarilla.png");
					}
					
					cargarCajas.setTexture(cajas);
					cargarCajas.setPosition(x, y);
					window1.draw(cargarCajas);
					x += 64;

				}
				else if (q->dato == 46 ) {// ! punto donde se tendra colocar la caja.
					if (numNivel == "1") {
						puntoCaja.loadFromFile("resources/sprite/punto_gris.png");
					}
					else if (numNivel == "2") {
						puntoCaja.loadFromFile("resources/sprite/punto_morado.png");
					}
					else if (numNivel == "3") {
						puntoCaja.loadFromFile("resources/sprite/punto_azul.png");
					}
					else if (numNivel == "4") {
						puntoCaja.loadFromFile("resources/sprite/punto_rojo.png");
					}
					else if (numNivel == "5") {
						puntoCaja.loadFromFile("resources/sprite/punto_amarillo.png");
					}
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
	ifstream dirNivel;
	string linea,nNivel;
	int cont = 0;
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

	case 6:
		dirNivel.open("resources/niveles/partidaGuardada" + nombreJ + ".txt");
		while (getline(dirNivel, linea)) {
			if (cont == 10) {
				nNivel = linea;
			}
			cont++;
		}
		leerArchivo("resources/niveles/partidaGuardada"+nombreJ+".txt");
		fondoTablero.loadFromFile("resources/fondo_tablero/fondo_tablero"+nNivel+".png");
		numNivel = nNivel;
		break;
	default:
		break;
	}
	
	crearMatriz();
	cargarFondoTablero.setTexture(fondoTablero);
	cargarFondoTablero.setPosition(20, 20);
}

void Tablero::setNombre(string nombre) {
	nombreJ = nombre;
}

void Tablero::noGuardado(RenderWindow& window) {
	fuente.loadFromFile("Letra_Pixel.ttf");
	Text cargada;
	cargada.setFont(fuente);
	cargada.setString("No existe ninguna partida guardada");
	cargada.setPosition(130,340);
	cargada.setFillColor(Color::White);
	cargada.setCharacterSize(40);
	window.draw(cargada);
	window.display();
	sleep(Time(seconds(3)));
}

void Tablero::pantallaDatos(RenderWindow& window) {
	
	fuente.loadFromFile("Letra_Pixel.ttf");

	niv.setFont(fuente);
	niv.setString("Nivel " + numNivel);
	niv.setPosition(770, 20);
	niv.setFillColor(Color::White);
	niv.setCharacterSize(40);


	nombreJugador.setFont(fuente);
	nombreJugador.setFillColor(Color::White);
	nombreJugador.setString("Jugador: "+ nombreJ);
	nombreJugador.setPosition(695, 120);
	nombreJugador.setCharacterSize(30);

	movimientos.setFont(fuente);
	movimientos.setFillColor(Color::White);
	movimientos.setString("Movimientos: "+ to_string(totalMovimientos));
	movimientos.setPosition(695, 220);
	movimientos.setCharacterSize(30);


	reinicioYsalir.setFont(fuente);
	reinicioYsalir.setFillColor(Color::White);
	reinicioYsalir.setString("Presiona R para reiniciar\n\n\nPresione ESC para salir");
	reinicioYsalir.setPosition(695, 520);
	reinicioYsalir.setCharacterSize(20);

	window.draw(niv);
	window.draw(nombreJugador);
	window.draw(movimientos);
	window.draw(reinicioYsalir);
}
void Tablero::repeticion(RenderWindow& window, int nivel) {
	cargarNiveles(nivel);
	sf::Event event;
	for (int i = 0; i < movJugador.size(); i++) {
		validaciones(window,movJugador[i]);
		sleep(Time(milliseconds(300)));
		while (window.pollEvent(event)) {
			switch (event.type) {

			case sf::Event::KeyReleased:
				switch (event.key.code) {
				case Keyboard::Enter:
					i = movJugador.size();
					break;
				}
			}
		}
		window.clear();
		window.draw(cargarFondoTablero);
		window.draw(titulo);
		mostrarMatriz(window);
		pantallaDatos(window);
		window.display();
	}
	totalMovimientos = 0;
	movJugador.clear();
}



void Tablero::mostrarTablero(RenderWindow& window, int nivel) {
	bool cerrar = false;
	bool sig = false;
	Font fuente;
	fuente.loadFromFile("Letra_Pixel.ttf");
	Text gano;
	gano.setString("GANASTE!!!!!!!!!!");
	gano.setPosition(695, 420);
	gano.setFont(fuente);

	cargarNiveles(nivel);

	crearMatriz();

	
	while (!cerrar) {
		
		sf::Event event;

		while (window.pollEvent(event)) {
			switch (event.type) {

			case sf::Event::KeyReleased:
				switch (event.key.code) {
				
				case Keyboard::Up:					
					validaciones(window, "arri");
					movJugador.push_back("arri");
					totalMovimientos++;
					break;

				case Keyboard::Down:
					validaciones(window, "abajo");
					movJugador.push_back("abajo");
					totalMovimientos++;
					break;
				case Keyboard::Left:
					validaciones(window, "izq");
					movJugador.push_back("izq");
					totalMovimientos++;
					break;
				case Keyboard::Right:
					validaciones(window, "dere");
					movJugador.push_back("dere");
					totalMovimientos++;
					
					break;
				case Keyboard::R:
					cargarNiveles(stoi(numNivel));
					movJugador.clear();
					break;
				case Keyboard::Escape:
					cerrar = true;;
					break;
				default:
					break;
				}
				break;
			case sf::Event::Closed:
				cerrar = true;
				window.close();
				break;
			default:
				break;
			}
			window.clear();
			window.draw(cargarFondoTablero);
			window.draw(titulo);
			mostrarMatriz(window);
			if (nivel == 1 && colocado.size() == 2) {
				window.draw(gano);
				cerrar = true;
				sig = true;
				
			}
			else if ((nivel == 2 || nivel == 4) && colocado.size() == 3) {
				window.draw(gano);
				cerrar = true;
				sig = true;
			}
			else if (nivel == 3 && colocado.size() == 4) {
				window.draw(gano);
				cerrar = true;
				sig = true;
			}
			
			pantallaDatos(window);
			window.display();
		}
		if (cerrar) {
			nodo* p = NULL, * q = NULL;
			ofstream partida;
			partida.open("resources/niveles/partidaGuardada"+nombreJ+".txt");
			if (head != NULL) {
				p = head;
				// se recorre las filas
				while (p != NULL) {
					q = p;
					// se recorren columnas
					while (q != NULL) {
						partida << q->dato;
						q = q->sig;
					}
					partida<< "\n";

					p = p->abajo;

				}
				partida << numNivel;
			}
		}
	}
	if (sig) {
		repeticion(window, nivel);
		if (nivel + 1 <= 5) {
			mostrarTablero(window, nivel + 1);
		}
		else {
			cout << "Gano el juego";
		}
		
	}
	
}

void Tablero::validaciones(RenderWindow& window, string mov) {
	
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
				colocado.push(1);
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
				colocado.pop();
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
				colocado.push(1);
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
				colocado.pop();
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
				colocado.push(1);
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
				colocado.pop();
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
				colocado.push(1);
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
				colocado.pop();
				relevo->abajo->dato = 36;
				relevo->dato = 38;
				aux->dato = 32;
			}
		}


	}


}


