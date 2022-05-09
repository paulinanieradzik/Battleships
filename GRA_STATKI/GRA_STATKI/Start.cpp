#include "Start.h"
#include <iostream>

void Start::inicjalizuj(Zarzadzanie_gra*& z, sf::RenderWindow*& o)
{
	statek.setTexture(*z->tekstury[8]);
	statek.setPosition(350.f, 230.f);
	nazwa.setString("Gra w statki");
	nazwa.setFont(*z->czcionka1);
	nazwa.setCharacterSize(100);
	nazwa.setPosition(450.f, 230.f);
	zainicjowany = true;
}
int Start::uaktualnij(sf::RenderWindow*& o, sf::Event& e)
{
	while (o->pollEvent(e))
	{
		if (e.type == e.KeyPressed || e.type == e.MouseButtonPressed)
		{
			return 1;  //zakoñcz stan przejdŸ do kolejnego
		}
	}
	return 0; //bez zmian
}
void Start::rysuj(sf::RenderWindow*& o)
{
	o->draw(statek);
	o->draw(nazwa);
}