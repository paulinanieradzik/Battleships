#ifndef PRZYCISK_H
#define PRZYCISK_H
#include "Zarzadzanie_gra.h"

class Przycisk
{
	sf::CircleShape ksztalt;
	sf::Color kolor;
	sf::Color kolor2;
	sf::Text napis;
	sf::Font* czcionka;
	friend class Menu;
public:
	bool nacisniety = false;
	Przycisk(sf::Vector2f vec, sf::Color col, sf::Color col2, sf::Font* fon, std::string napis, float promien = 120.f, int rozmCzcionki=50);
	~Przycisk() {};
	void rysuj(sf::RenderWindow*& o);
	void uaktywnij(sf::RenderWindow*& o);
	bool czyNad(sf::RenderWindow*& o);
};

#endif

