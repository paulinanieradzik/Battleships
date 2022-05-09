#ifndef KONIEC_H
#define KONIEC_H
#include "Stan_gry.h"
#include "Przycisk.h"

class Koniec : public Stan_gry
{
	std::unique_ptr<Przycisk> menu;
	std::unique_ptr<Przycisk> wyjscie;
	std::unique_ptr<sf::Text> ktoWygral;
	std::unique_ptr<sf::Text> komunikat;
	std::string tekst;
public:
	Koniec(bool wygrana);
	void inicjalizuj(Zarzadzanie_gra*& z, sf::RenderWindow*& o);
	int uaktualnij(sf::RenderWindow*& o, sf::Event& e);
	void rysuj(sf::RenderWindow*& o);
};

#endif