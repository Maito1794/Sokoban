#include <iostream>
#include "Menu.h"
#include "Tablero.h"
#include "Credito.h"
#include <SFML/Graphics.hpp>
#include "main.h"

using namespace std;
using namespace sf;

int main(){
	Tablero tableroNombre;
	tableroNombre.pedirNombre();
	 
	RenderWindow window(VideoMode(1020, 680), "Sokoban",Style::Close);
	
	Menu menu(window.getSize().x, window.getSize().y);
	Credito credito(window.getSize().x, window.getSize().y);
	Tablero tablero(window.getSize().x, window.getSize().y);
	
	
	
	while (window.isOpen()) {

		menu.cargarMenu(window);

		switch (menu.getbotonPresionado()) {
		case 0:
			tablero.mostrarTablero(window,1);
			cout << "a"<<endl;
			
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