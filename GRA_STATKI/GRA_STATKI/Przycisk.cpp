#include "Przycisk.h"

Przycisk::Przycisk(sf::Vector2f vec, sf::Color col, sf::Color col2, sf::Font* fon, std::string str, float promien, int rozmCzcionki)
{
	kolor = col;
	kolor2 = col2;
	ksztalt.setRadius(promien);
	ksztalt.setOrigin(ksztalt.getLocalBounds().width / 2.f, ksztalt.getLocalBounds().height / 2.f);
	ksztalt.setPosition(vec);
	ksztalt.setFillColor(kolor);
	ksztalt.setOutlineColor(sf::Color::Black);
	ksztalt.setOutlineThickness(2.f);
	czcionka = fon;
	napis.setFont(*czcionka);
	napis.setString(str);
	napis.setCharacterSize(rozmCzcionki);
	napis.setFillColor(sf::Color::Black);
	napis.setOrigin(napis.getLocalBounds().width / 2.f, napis.getLocalBounds().height / 2.f);
	napis.setPosition(vec);
}
void Przycisk::rysuj(sf::RenderWindow*& o)
{
	o->draw(ksztalt);
	o->draw(napis);
}
void Przycisk::uaktywnij(sf::RenderWindow*& o)
{
	if (czyNad(o))
	{
		ksztalt.setFillColor(kolor2);
		if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
			nacisniety = true;
	}
	else
		ksztalt.setFillColor(kolor);
}
bool Przycisk::czyNad(sf::RenderWindow*& o)
{
	sf::Vector2f pozycja = sf::Vector2f(sf::Mouse::getPosition(*o));
	float polowaSzer = ksztalt.getLocalBounds().width / 2.f;
	float polowaWys = ksztalt.getLocalBounds().height / 2.f;
	if (pozycja.x < (ksztalt.getPosition().x + polowaSzer) && pozycja.x > (ksztalt.getPosition().x - polowaSzer)
		&& pozycja.y < (ksztalt.getPosition().y + polowaWys) && pozycja.y > (ksztalt.getPosition().y - polowaWys))
	{
		return true;
	}
	else
		return false;
}