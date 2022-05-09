#ifndef MENU_H
#define MENU_H
#include "Stan_gry.h"

class Menu: public Stan_gry
{
	sf::Sprite statekTlo;
	std::vector<Przycisk*> przyciski;
	sf::Text tytul;
	std::vector<sf::Text*> tekstZasad;
	sf::Sprite siatka;
	sf::Sprite statek;
	sf::Sprite statek2;
	std::unique_ptr<Przycisk> powrot = nullptr;

public:
	bool zasady = false;
	~Menu();
	void inicjalizuj(Zarzadzanie_gra*& z, sf::RenderWindow*& o);
	int uaktualnij(sf::RenderWindow*& o, sf::Event& e);
	void rysuj(sf::RenderWindow*& o);
	void inicjalizujZadadyGry(Zarzadzanie_gra*& z);
	int uaktualnijZasady(sf::RenderWindow*& o);
	void rysujZadadyGry(sf::RenderWindow*& o);
};

#endif