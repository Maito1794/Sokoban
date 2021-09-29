#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

using namespace sf;

Menu::Menu(float width, float height) {

	fuente.loadFromFile("Letra_Pixel.ttf");

	boton[0].setFont(fuente);
	boton[0].setFillColor(Color::Green);
	boton[0].setString("Nueva partida");
	boton[0].setPosition(Vector2f((width/2) - 150, height / 5 * 1));
	boton[0].setCharacterSize(40);

	boton[1].setFont(fuente);
	boton[1].setFillColor(Color::White);
	boton[1].setString("Cargar Partida");
	boton[1].setPosition(Vector2f((width/2) - 160, height / (5) * 2));
	boton[1].setCharacterSize(40);

	boton[2].setFont(fuente);
	boton[2].setFillColor(Color::White);
	boton[2].setString("Créditos");
	boton[2].setPosition(Vector2f((width/2) - 95, height / (5) * 3));
	boton[2].setCharacterSize(40);

	boton[3].setFont(fuente);
	boton[3].setFillColor(Color::White);
	boton[3].setString("Salir");
	boton[3].setPosition(Vector2f((width/2) - 70, height / (5) * 4));
	boton[3].setCharacterSize(40);

	botonSeleccionado = 0;
}

void Menu::dibujarBoton(RenderWindow& window)
{
	for (int i = 0; i < 4; i++) {
		window.draw(boton[i]);
	}
}

void Menu::teclaArriba()
{
	if (botonSeleccionado - 1 >= 0) {
		boton[botonSeleccionado].setFillColor(Color::White);
		botonSeleccionado--;
		boton[botonSeleccionado].setFillColor(Color::Green);
	}
}

void Menu::teclaAbajo()
{
	if (botonSeleccionado + 1 < 4) {
		boton[botonSeleccionado].setFillColor(sf::Color::White);
		botonSeleccionado++;
		boton[botonSeleccionado].setFillColor(sf::Color::Green);
	}
}