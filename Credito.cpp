#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Credito.h"


Credito::Credito(float width, float height) {
	//Font font;
	//font.loadFromFile("Letra_Pixel.ttf");
	//responsable1.setFont(font);
	responsable1.setFillColor(Color::Green);
	responsable1.setString("Mauricio Mora Brenes");
	responsable1.setPosition(width/2, height/2);
	responsable1.setCharacterSize(40);
	//responsable2.setString("")
}

void Credito::mostrarCreditos(RenderWindow& window) {
	bool cerrar = false;

	while (!cerrar) {

		sf::Event event;

		while (window.pollEvent(event)) {
			switch (event.type) {

			case sf::Event::KeyReleased:
				switch (event.key.code) {
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
			window.draw(responsable1);
			window.display();
		}
		
	}
	
}