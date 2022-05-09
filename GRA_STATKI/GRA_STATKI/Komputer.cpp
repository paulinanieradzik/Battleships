#include "Komputer.h"

Komputer::Komputer() : Gracz()
{
	rozkladMiejsca = 100;
	rozkladOrientacji = 2;
}
void Komputer::RozstawStatki()
{
	bool ustawiony;
	for(auto a=(*listaStatkow).begin(); a!= (*listaStatkow).end(); a++)
	{
		ustawiony = false;
		a->ustawOrientacje(losuj(rozkladOrientacji));
		do
		{
			if (plansza->sprawdzCzyMoznaUstawic(losuj(rozkladMiejsca), a->wielkosc, a->znak, static_cast<int>(a->orientacja)))
			{
				ustawiony = true;
			}
		} while (!ustawiony);
	}
}
int Komputer::losuj(int zakres)
{
	return rand() % zakres;
}
int Komputer::WykonajRuch()
{
	int wylosowana;
	bool koniec = false;
	do {
		wylosowana = losuj(100);
		int w = wylosowana / 10;
		int k = wylosowana % 10;
		if (plansza->planszaPrzeciwnika[w][k] == '.')
			koniec = true;
	}
	while (!koniec);
	return wylosowana;
}