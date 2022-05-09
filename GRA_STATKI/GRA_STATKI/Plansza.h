#ifndef PLANSZA_H
#define PLANSZA_H
#include <array>
#include <list>
#include <algorithm>

class Plansza
{
	friend class Rozgrywka;
	friend class Komputer;
	friend class Czlowiek;
	std::array<std::array<char,10>,10> mojaPlansza;
	std::array<std::array<char,10>,10> planszaPrzeciwnika;
public:
	Plansza();
	bool sprawdzCzyMoznaUstawic(int pozycja, int wielkosc, char znak, int orientacja);
	void zaznaczNaPlanszy(int x, int y, char znak, int wielkosc, int orintacja);
	void wyczyscPlansze();
	char CzyTrafiony(int ruch);
};

#endif