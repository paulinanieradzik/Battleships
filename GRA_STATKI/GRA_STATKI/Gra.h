#ifndef GRA_H
#define GRA_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Statek.h"
#include "Start.h"
#include "Menu.h"
#include "Poczatek.h"
#include "Rozgrywka.h"
#include "Koniec.h"

class Gra
{
	sf::RenderWindow* okno = new sf::RenderWindow;
	std::vector<Stan_gry*> stany;
	sf::Vector2f pozycjaMyszy;
	int zmiana = 0;

public:
	Zarzadzanie_gra* zarzadzanie;
	Gra();
	~Gra();
	void gra();
};

#endif
