#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Credito.h"


Credito::Credito(float width, float height) {
	fuente.loadFromFile("Letra_Pixel.ttf");

	titulo.setFont(fuente);
	titulo.setFillColor(Color::Blue);
	titulo.setString("SOKOBAN");
	titulo.setPosition(400, 30);
	titulo.setCharacterSize(60);


	descripcion.setFont(fuente);
	descripcion.setFillColor(Color::Blue);
	descripcion.setString("Este juego fue elaborado por:");
	descripcion.setPosition(235, 150);
	descripcion.setCharacterSize(35);

	responsables.setFont(fuente);
	responsables.setFillColor(Color::White);
	responsables.setString("Mauricio Mora Brenes\n\n\nHeizel Arias Alvarado\n\n\nJuli�n Ram�rez Sol�s");
	responsables.setPosition((width/2)-200, (height/2)-80);
	responsables.setCharacterSize(35);
	
	salir.setFont(fuente);
	salir.setFillColor(Color::White);
	salir.setString("Presione ENTER para volver al men� principal.");
	salir.setPosition(10, height-50);
	salir.setCharacterSize(20);

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
			window.draw(titulo);
			window.draw(descripcion);
			window.draw(responsables);
			window.draw(salir);
			window.display();
		}
		
	}
	
}