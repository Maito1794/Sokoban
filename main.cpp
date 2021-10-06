#include <iostream>
#include "Menu.h"
#include "Tablero.h"
#include "Credito.h"
#include <SFML/Graphics.hpp>
#include "main.h"
#include <cstdio>
#include <cstdlib>
#include <Windows.h>

using namespace std;
using namespace sf;
Music* musica;
void reproducir(int music);

void main(){
	string nombre;
	cout <<endl<<"\t\t\t\t\tBIENVENIDO(A) a Sokoban. "
		<<endl<<endl<<"\tDigite su nombre: ";
	cin >> nombre;
	
	RenderWindow window(VideoMode(1020, 680), "Sokoban",Style::Titlebar);
	Menu menu(window.getSize().x, window.getSize().y);
	Credito credito(window.getSize().x, window.getSize().y);
	Tablero tablero;
	tablero.setNombre(nombre);
	ifstream partida;
	string dir = "resources/niveles/partidaGuardada" + nombre + ".txt";
	char direccion[100];
	strcpy_s(direccion, dir.c_str());
	FreeConsole();
	while (window.isOpen()) {
		
		reproducir(1);
		menu.cargarMenu(window);		

		switch (menu.getbotonPresionado()) {
		case 0:
			musica->stop();
			reproducir(2);
			remove(direccion);
			tablero.mostrarTablero(window,1);
			break;
		case 1:
			partida.open("resources/niveles/partidaGuardada"+nombre+".txt");
			if (!partida.fail()) {
				musica->stop();
				reproducir(2);
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
			musica->stop();
			window.close();
			break;
		}	
		musica->stop();
	}
	musica->stop();
}

void reproducir(int music) {
	musica = new Music();
	if (music == 1) {
		musica->openFromFile("resources/menu.wav");
	}
	else {
		musica->openFromFile("resources/partida.wav");
	}

	musica->setPitch(1);
	musica->setVolume(20);
	musica->setLoop(true);
	musica->play();
}