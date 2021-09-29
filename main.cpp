#include <iostream>
#include "Menu.h"
#include <SFML/Graphics.hpp>

using namespace sf;

int main(){
	bool contador[4] = { false,false,false,false };
	RenderWindow window(VideoMode(750, 500), "Sokoban",Style::Close);
	
	Menu menu(window.getSize().x, window.getSize().y);

	while (window.isOpen()) {
		sf::Event event;

		while (window.pollEvent(event)) {
			switch (event.type){
				 
			case sf::Event::KeyReleased:
				switch (event.key.code) {
				case sf::Keyboard::Up:
					menu.teclaArriba();
					break;

				case sf::Keyboard::Down:
					menu.teclaAbajo();
					break;

				case sf::Event::Closed:
					window.close();
					break;
				}
			}

			window.clear();
			menu.dibujarBoton(window);
			window.display();

		}
	}
    return 0;
}