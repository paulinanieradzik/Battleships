#include "Gracz.h"

Gracz::Gracz()
{
	plansza = std::make_unique<Plansza>();
	//inicjalizcja listy statkow
	listaStatkow = std::make_unique<std::list<Statek>>();
	std::unique_ptr<Statek>statek1 = std::make_unique<Statek>('a',2);
	listaStatkow->push_back(*statek1);
	std::unique_ptr<Statek>statek2 = std::make_unique<Statek>('b', 3);
	listaStatkow->push_back(*statek2);
	std::unique_ptr<Statek>statek3 = std::make_unique<Statek>('c', 3);
	listaStatkow->push_back(*statek3);
	std::unique_ptr<Statek>statek4 = std::make_unique<Statek>('d', 4);
	listaStatkow->push_back(*statek4);
	std::unique_ptr<Statek>statek5 = std::make_unique<Statek>('e', 5);
	listaStatkow->push_back(*statek5);
}
bool Gracz::KoniecGry()
{
	for (auto i = listaStatkow->begin(); i != listaStatkow->end(); i++)
	{
		if (!i->czyZatopiony())
			return false;
	}
	return true;
}
void Gracz::Trafiony(char znak)
{
	for (auto i = listaStatkow->begin(); i != listaStatkow->end(); i++)
	{
		if (i->znak == znak)
			i->trafienia++;
	}
}