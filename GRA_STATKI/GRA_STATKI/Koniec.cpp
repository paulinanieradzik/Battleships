#include "Koniec.h"

Koniec::Koniec(bool wygrana)
{
	if (wygrana)
		tekst = "Gratulacje! Wygrales!";
	else
		tekst = "Niestety nie udalo Ci sie wygrac.";
}
void Koniec::inicjalizuj(Zarzadzanie_gra*& z, sf::RenderWindow*& o)
{
	menu = std::make_unique<Przycisk>(sf::Vector2f(750.f, 650.f), sf::Color::White, sf::Color(192, 192, 192), z->czcionka2, "Zagraj");
	wyjscie = std::make_unique<Przycisk>(sf::Vector2f(1150.f, 650.f), sf::Color::White, sf::Color(192, 192, 192), z->czcionka2, "Wyjscie");
	ktoWygral = std::make_unique<sf::Text>();
	ktoWygral->setString(tekst);
	ktoWygral->setFillColor(sf::Color::Black);
	ktoWygral->setFont(*z->czcionka1);
	ktoWygral->setCharacterSize(100);
	ktoWygral->setOrigin(ktoWygral->getLocalBounds().width / 2.f, ktoWygral->getLocalBounds().height / 2.f);
	ktoWygral->setPosition(o->getSize().x / 2.f, o->getSize().y / 2.f - 400.f);
	komunikat = std::make_unique<sf::Text>();
	komunikat->setString("Chcesz zagrac jescze raz?");
	komunikat->setFillColor(sf::Color::Black);
	komunikat->setFont(*z->czcionka2);
	komunikat->setCharacterSize(60);
	komunikat->setOrigin(komunikat->getLocalBounds().width / 2.f, komunikat->getLocalBounds().height / 2.f);
	komunikat->setPosition(o->getSize().x / 2.f, o->getSize().y / 2.f - 100.f);
	zainicjowany = true;
}
int Koniec::uaktualnij(sf::RenderWindow*& o, sf::Event& e)
{
	menu->uaktywnij(o);
	if (menu->nacisniety == true)
	{
		menu->nacisniety = false;
		return 1;
	}
	wyjscie->uaktywnij(o);
	if (wyjscie->nacisniety == true)
	{
		wyjscie->nacisniety = false;
		return 3;
	}
	return 0;
}
void Koniec::rysuj(sf::RenderWindow*& o)
{
	o->draw(*ktoWygral);
	o->draw(*komunikat);
	menu->rysuj(o);
	wyjscie->rysuj(o);
}