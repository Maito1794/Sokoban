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

void reproducir(int music);

int main(){
	string nombre;
	cout << "BIENVENIDO (A) a Sokoban. Digite su nombre:" << endl;
	cin >> nombre;
	Music *musica;
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
			
			tablero.mostrarTablero(window,1);
			musica = new Music();
			musica->openFromFile("resources/City-Lights.wav");
			musica->setPosition(0, 1, 10);
			musica->setPitch(1);
			musica->setVolume(10);
			musica->setLoop(true);
			musica->play();
			reproducir(1500);
			remove(direccion);
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

void reproducir(int music) {
	Clock Timer;
	while (Timer.getElapsedTime().asMilliseconds() < music);
}