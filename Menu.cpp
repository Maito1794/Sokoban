#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

using namespace sf;
using namespace std;

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
	caja_gris.loadFromFile("resources/sprite/caja_gris.png");
	caja.setTexture(caja_gris);
	Color color1(61, 110, 255);
	Color color2(58, 207, 97);
	Color color3(204, 91, 57);
	for (int i = 0; i < 6; i++) {
		switch (i) {
		case 0:
			caja.setColor(color1);
			caja.setPosition(20, window.getSize().y - 80);
			break;
		case 1:
			caja.setColor(color2);
			caja.setPosition(84, window.getSize().y - 80);
			break;
		case 2:
			caja.setPosition(20, window.getSize().y - 144);
			caja.setColor(color3);
			break;
		case 3:
			caja.setColor(color1);
			caja.setPosition(window.getSize().x-80,20);
			break;
		case 4:
			caja.setColor(color3);
			caja.setPosition(window.getSize().x - 80, 84);
			break;
		case 5:
			caja.setPosition(window.getSize().x - 144, 20);
			caja.setColor(color2);
			break;
		}
		window.draw(caja);
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

void Menu::cargarMenu(RenderWindow& window)
{
	cerrar = false;
	while (!cerrar) {
		sf::Event event;

		while (window.pollEvent(event)) {
			switch (event.type) {

			case sf::Event::KeyReleased:
				switch (event.key.code) {
				case sf::Keyboard::Up:
					teclaArriba();
					break;

				case sf::Keyboard::Down:
					teclaAbajo();
					break;

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
			dibujarBoton(window);
			window.display();

		}
	}
}