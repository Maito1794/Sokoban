#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Credito {
private:
	Text responsables;
	Text titulo;
	Text descripcion;
	Text salir;
	Font fuente;
	Texture gif;
	Sprite sprite;

public: 
	Credito(float width, float height);
	void mostrarCreditos(RenderWindow& window);
};