#ifndef CZLOWIEK_H
#define CZLOWIEK_H
#include "Gracz.h"

class Czlowiek : public Gracz
{
	friend class Poczatek;
	friend class Rozgrywka;
public:
	Czlowiek();
	bool RozstawStatki(int nr, int orientacja, int pozycja);
	int WykonajRuch(sf::Vector2f lewygorny, sf::Vector2f prawydolny, sf::Vector2f pozycja);
};

#endif