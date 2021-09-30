#include <iostream>
#include "Menu.h"
#include "Tablero.h"
#include "Credito.h"
#include <SFML/Graphics.hpp>
#include "main.h"

using namespace std;
using namespace sf;

int main(){

	RenderWindow window(VideoMode(750, 500), "Sokoban",Style::Close);
	
	Menu menu(window.getSize().x, window.getSize().y);
	Credito credito(window.getSize().x, window.getSize().y);
	Tablero tablero;
	tablero.leerArchivo();
	tablero.crearMatriz();
	tablero.mostrarMatriz();

	while (window.isOpen()) {

		menu.cargarMenu(window);

		switch (menu.getbotonPresionado()) {
		case 0:

			break;
		case 1:
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