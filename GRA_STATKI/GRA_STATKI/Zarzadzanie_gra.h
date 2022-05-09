#ifndef ZARZADZANIE_H
#define ZARZADZANIE_H
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include "Gracz.h"
#include "Czlowiek.h"
#include "Komputer.h"

#define DWU 0;
#define TROJ 1;
#define CZT 2;
#define PIE 3;
#define JAS 4;
#define CIEM 5;
#define OGIEN 6;
#define PUDLO 7;
#define ILOSC 5;

class Zarzadzanie_gra
{
public:
	std::vector<sf::Texture*> tekstury;
	sf::Font* czcionka1, *czcionka2;
	std::unique_ptr<Czlowiek> czlowiek;
	std::unique_ptr<Komputer> komputer;

	Zarzadzanie_gra();
	~Zarzadzanie_gra();
	//void Inicjalizuj();
	bool ZaladujCzcionki();
	bool ZaladujTekstury();
};

#endif

