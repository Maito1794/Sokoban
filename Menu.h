#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Menu {
private:
	Event e;
	Font fuente;
	Text boton[4];
	bool cerrar;
	int botonSeleccionado;

public:
	Menu();
	Menu(float width, float height);
	void dibujarBoton(RenderWindow& window);
	void teclaArriba();
	void teclaAbajo();
	int getbotonPresionado() { return botonSeleccionado; }
	void cargarMenu(RenderWindow& window);

};