#ifndef STANGRY_H
#define STANGRY_H
#include <memory>
#include "Zarzadzanie_gra.h"
#include "Przycisk.h"

class Stan_gry
{
public:
	sf::RenderWindow* okno = nullptr;
	bool zainicjowany = false;
	virtual void inicjalizuj(Zarzadzanie_gra*& z, sf::RenderWindow*& o)=0;
	virtual int uaktualnij(sf::RenderWindow*& o, sf::Event& e)=0;
	virtual void rysuj(sf::RenderWindow*& o)=0;
};

#endif