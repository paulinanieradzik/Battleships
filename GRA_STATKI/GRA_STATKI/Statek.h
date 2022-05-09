#ifndef STATEK_H
#define STATEK_H
#include <SFML/Graphics.hpp>

enum class Orientacja
{
	pozioma=0, pionowa
};
class Statek
{
	friend class Komputer;
	friend class Czlowiek;
	friend class Gracz;
	friend class Poczatek;
	friend class Rozgrywka;
	char znak;
	int pozycja;
	int wielkosc = 0;
	int trafienia = 0;
	Orientacja orientacja = Orientacja::pozioma;
	bool zatopiony = false;
public:
	Statek();
	Statek(char znak, int wielkosc);
	sf::Sprite sprajt;
	void inicjalizuj(sf::Texture*& tekstura);
	void rysuj(sf::RenderWindow*& okno);
	bool czyZatopiony();
	void ustawOrientacje(int o);
	void zmienOrientacje();
	void Trafiony(sf::RenderWindow* okno);
	bool sprawdzeniePozycji(sf::RenderWindow*& o);
};

#endif