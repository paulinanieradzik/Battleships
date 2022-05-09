#include "Statek.h"

Statek::Statek() {}
Statek::Statek(char znak, int wielkosc)
{
	this->znak = znak;
	this->wielkosc = wielkosc;
}
void Statek::inicjalizuj(sf::Texture*& tekstura)
{
	sprajt.setTexture(*tekstura);
}
void Statek::rysuj(sf::RenderWindow*& okno)
{
	okno->draw(sprajt);
}
bool Statek::czyZatopiony()
{
	if (trafienia == wielkosc)
		zatopiony = true;
	return zatopiony;
}
void Statek::ustawOrientacje(int o)
{
	if (o == 0)
		orientacja = Orientacja::pozioma;
	else
		orientacja = Orientacja::pionowa;
}
void Statek::zmienOrientacje()
{
	if (orientacja == Orientacja::pozioma)
	{
		sprajt.setRotation(-90);
		orientacja = Orientacja::pionowa;
	}
	else
	{
		sprajt.setRotation(0);
		orientacja = Orientacja::pozioma;
	}
}
void Statek::Trafiony(sf::RenderWindow* okno)
{
	/*sf::sprite trafienie;
	trafienie.settexture(tekstury[ogien]);
	okno.draw(trafienie);*/
}
bool Statek::sprawdzeniePozycji(sf::RenderWindow*& o)
{
	sf::Vector2f pozycja = sf::Vector2f(sf::Mouse::getPosition(*o));
	sf::Vector2f pozycjaStatku;
	float polowaWys;
	float polowaSzer;
	if (orientacja == Orientacja::pozioma)
	{
		pozycjaStatku = sprajt.getPosition();
		polowaSzer = sprajt.getLocalBounds().width;
		polowaWys = sprajt.getLocalBounds().height;
		if (pozycja.x < (pozycjaStatku.x + polowaSzer) && pozycja.x >(pozycjaStatku.x - polowaSzer)
			&& pozycja.y < (pozycjaStatku.y + polowaWys) && pozycja.y >(pozycjaStatku.y - polowaWys))
			return true;
	}
	else
	{
		pozycjaStatku = sprajt.getPosition();
		polowaSzer = sprajt.getLocalBounds().width;
		polowaWys = sprajt.getLocalBounds().height;
		if (pozycja.x < (pozycjaStatku.x + polowaSzer) && pozycja.x >(pozycjaStatku.x - polowaSzer)
			&& pozycja.y < (pozycjaStatku.y + polowaWys) && pozycja.y >(pozycjaStatku.y - polowaWys))
			return true;
	}
	return false;
}
