#include <iostream>
#include "Menu.h"
#include "Tablero.h"
#include "Credito.h"
#include <SFML/Graphics.hpp>
#include "main.h"
#include <cstdio>
#include <cstdlib>

using namespace std;
using namespace sf;

int main(){
	string nombre;
	cout << "BIENVENIDO (A) a Sokoban. Digite su nombre:" << endl;
	cin >> nombre;

	RenderWindow window(VideoMode(1020, 680), "Sokoban",Style::Close);
	
	Menu menu(window.getSize().x, window.getSize().y);
	Credito credito(window.getSize().x, window.getSize().y);
	Tablero tablero;
	tablero.setNombre(nombre);
	ifstream partida;
	string dir = "resources/niveles/partidaGuardada" + nombre + ".txt";
	char direccion[100];
	strcpy_s(direccion, dir.c_str());
	while (window.isOpen()) {

		menu.cargarMenu(window);

		switch (menu.getbotonPresionado()) {
		case 0:
			remove(direccion);
			tablero.mostrarTablero(window,1);
			break;
		case 1:
			partida.open("resources/niveles/partidaGuardada"+nombre+".txt");
			if (!partida.fail()) {
				tablero.mostrarTablero(window, 6);
			}
			else {
				tablero.noGuardado(window);
			}
			partida.close();
			break;
		case 2:
			credito.mostrarCreditos(window);
			break;
		case 3:
			window.close();
			break;
		}		
	}

    return 0;
}