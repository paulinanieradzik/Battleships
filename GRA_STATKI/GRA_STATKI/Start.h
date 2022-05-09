#ifndef START_H
#define START_H
#include "Stan_gry.h"

class Start : public Stan_gry
{
	sf::Sprite statek;
	sf::Text nazwa;
public:
	void inicjalizuj(Zarzadzanie_gra*& z, sf::RenderWindow*& o);
	int uaktualnij(sf::RenderWindow*& o, sf::Event& e);
	void rysuj(sf::RenderWindow*& o);
};

#endif