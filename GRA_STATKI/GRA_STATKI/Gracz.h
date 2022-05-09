#ifndef GRACZ_H
#define GRACZ_H
#include <memory>
#include <list>
#include "Plansza.h"
#include "Statek.h"

class Gracz
{
protected:
	std::unique_ptr<Plansza> plansza;
	std::unique_ptr<std::list<Statek>>listaStatkow;
	bool poprzedniTrafiony = false;
public:
	Gracz();
	~Gracz() {};
	bool KoniecGry();
	void Trafiony(char znak);
};

#endif