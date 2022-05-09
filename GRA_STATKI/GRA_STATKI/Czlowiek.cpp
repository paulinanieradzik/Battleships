#include "Czlowiek.h"

Czlowiek::Czlowiek() : Gracz::Gracz()
{

}
bool Czlowiek::RozstawStatki(int nr, int orientacja, int pozycja)
{
	if (pozycja >= 0 && pozycja < 100)
	{
		auto it = listaStatkow->begin();
		for (int i = 0; i < nr; i++)
		{
			it++;
		}
		it->ustawOrientacje(orientacja);
		return plansza->sprawdzCzyMoznaUstawic(pozycja, it->wielkosc, it->znak, orientacja);
	}
	return false;
}
int Czlowiek::WykonajRuch(sf::Vector2f lewygorny, sf::Vector2f prawydolny, sf::Vector2f pozycja)
{
	bool poprawnie = false;
	int ruch;
	float rozmiarJednegoPola = (prawydolny.x - lewygorny.x) / 10;
	do
	{
		if (pozycja.x > lewygorny.x && pozycja.y > lewygorny.y && pozycja.x < prawydolny.x && pozycja.y < prawydolny.y)
		{
			poprawnie = true;
			int k = (pozycja.x - lewygorny.x) / rozmiarJednegoPola;
			int w = (pozycja.y - lewygorny.y) / rozmiarJednegoPola;
			ruch = 10 * w + k;
		}
	} while (!poprawnie);
	return ruch;
}