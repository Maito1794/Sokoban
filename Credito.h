#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Credito {
private:
	Text responsable1;
	Text responsable2;
	Text responsable3;

public: 
	Credito(float width, float height);
	void mostrarCreditos(RenderWindow& window);

};