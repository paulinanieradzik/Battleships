#include "Zarzadzanie_gra.h"
#include <iostream>

Zarzadzanie_gra::Zarzadzanie_gra()
{
	ZaladujCzcionki();
	ZaladujTekstury();
}
Zarzadzanie_gra::~Zarzadzanie_gra()
{
	delete czcionka1;
	delete czcionka2;
	while (tekstury.size() != 0)
	{
		tekstury.erase(tekstury.begin());
	}
}
bool Zarzadzanie_gra::ZaladujCzcionki()
{
	czcionka1 = new sf::Font;
	czcionka2 = new sf::Font;
	czcionka1->loadFromFile("czcionki/Lato-BoldItalic.ttf");
	czcionka2->loadFromFile("czcionki/Lato-Italic.ttf");
	return true;
}
bool Zarzadzanie_gra::ZaladujTekstury()
{
	sf::Texture* tekstura = new sf::Texture;
	if(tekstura->loadFromFile("grafika/dwumasztowiec.png"))
		tekstury.push_back(tekstura);
	sf::Texture* tekstura2 = new sf::Texture;
	if(tekstura2->loadFromFile("grafika/trojmasztowiec.png"))
		tekstury.push_back(tekstura2);
	sf::Texture* tekstura3 = new sf::Texture;
	if(tekstura3->loadFromFile("grafika/czteromasztowiec.png"))
		tekstury.push_back(tekstura3);
	sf::Texture* tekstura4 = new sf::Texture;
	if(tekstura4->loadFromFile("grafika/pieciomasztowiec.png"))
		tekstury.push_back(tekstura4);
	sf::Texture* tekstura5 = new sf::Texture;
	if(tekstura5->loadFromFile("grafika/jasny.png"))
		tekstury.push_back(tekstura5);
	sf::Texture* tekstura6 = new sf::Texture;
	if(tekstura6->loadFromFile("grafika/ciemny.png"))
		tekstury.push_back(tekstura6);
	sf::Texture* tekstura7 = new sf::Texture;
	if(tekstura7->loadFromFile("grafika/ogien.png"))
		tekstury.push_back(tekstura7);
	sf::Texture* tekstura8 = new sf::Texture;
	if (tekstura8->loadFromFile("grafika/pudlo.png"))
	{
		tekstury.push_back(tekstura8);
		std::cout << "wczytana" << std::endl;
	}
	sf::Texture* tekstura9 = new sf::Texture;
	if (tekstura9->loadFromFile("grafika/ship.png"))
		tekstury.push_back(tekstura9);
	sf::Texture* tekstura10 = new sf::Texture;
	if (tekstura10->loadFromFile("grafika/siatka.png"))
		tekstury.push_back(tekstura10);
	return true;
	delete tekstura, tekstura2, tekstura3, tekstura4, tekstura5,
		tekstura6, tekstura7, tekstura8, tekstura9, tekstura10;
}

