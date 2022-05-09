#include <iostream>
#include "Poczatek.h"

Poczatek::Poczatek()
{
	//zainicjowanie statków
	for(int i = 0; i < 5; i++)
	{
		Statek* s = new Statek();
		statki.push_back(s);
	}
}
Poczatek::~Poczatek()
{
	delete okno;
	delete zarzadzanie;
	//usuniêcie statków
	while (statki.size() != 0)
	{
		statki.erase(statki.begin());
	}
}
void Poczatek::inicjalizuj(Zarzadzanie_gra*& z, sf::RenderWindow*& o)
{
	int tab[5] = { 0,1,1,2,3 };
	for (int i=0; i < 5; i++)
	{
		statki[i]->inicjalizuj(z->tekstury[tab[i]]);
		statki[i]->sprajt.setOrigin(statki[i]->sprajt.getLocalBounds().width/2.f, statki[i]->sprajt.getLocalBounds().height / 2.f);
		statki[i]->sprajt.setPosition(1300.f, 350.f + i * 100.f);
	}
	siatka.setTexture(*z->tekstury[9]);
	siatka.setPosition(300.f, 150.f);
	siatka.setScale(2.3f, 2.3f);
	zainicjowany = true;
	tytul.setString("STATKI");
	tytul.setFillColor(sf::Color::Black);
	tytul.setFont(*z->czcionka1);
	tytul.setCharacterSize(120);
	tytul.setOrigin(tytul.getLocalBounds().width / 2.f, tytul.getLocalBounds().height / 2.f);
	tytul.setPosition(o->getSize().x / 2.f, 60.f);
	dalej = std::make_unique<Przycisk>(sf::Vector2f(1700.f, 850.f), sf::Color::White, sf::Color(192, 192, 192), z->czcionka2, "Dalej", 65.f, 30);
	zarzadzanie = z;
}
void Poczatek::rysuj(sf::RenderWindow*& o)
{
	o->draw(tytul);
	o->draw(siatka);
	for (int i=0; i < 5; i++)
	{
		statki[i]->rysuj(o);
	}
	dalej->rysuj(o);
	if (komunikat)
	{
		o->draw(*okienko);
		o->draw(*tekstKomunikatu);
		ok->rysuj(o);
	}
}
int Poczatek::uaktualnij(sf::RenderWindow*& o, sf::Event& e)
{
	if (!komunikat)
	{
		for (int i = 0; i < 5; i++)
		{
			if (statki[i]->sprawdzeniePozycji(o))
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (przenoszony == 10 || przenoszony == i)
					{
						statki[i]->sprajt.setPosition((float)sf::Mouse::getPosition(*o).x, (float)sf::Mouse::getPosition(*o).y);
						przenoszony = i;
					}
				}
				else
					przenoszony = 10;
				o->pollEvent(e);
				while (sf::Mouse::isButtonPressed(sf::Mouse::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
				{
					statki[i]->zmienOrientacje();
				}
			}
		}
		//sprawdiæ czy naciœniêty przycisk i je¿eli tak to czy poprawnie u³one statki
		dalej->uaktywnij(o);
		if (dalej->nacisniety == true)
		{
			dalej->nacisniety = false;
			if (sprawdzenieUlozenia())//sprawdzenie poprawnoœci ustwienia statków zwraca bool
				return 1;
			else
			{
				komunikat = true;
				okienko = std::make_unique<sf::RectangleShape>();
				okienko->setFillColor(sf::Color(160, 160, 160));
				okienko->setOutlineColor(sf::Color::Black);
				okienko->setOutlineThickness(5.f);
				okienko->setSize(sf::Vector2f(800.f, 350.f));
				okienko->setOrigin(okienko->getLocalBounds().width / 2.f, okienko->getLocalBounds().height / 2.f);
				okienko->setPosition(o->getSize().x / 2.f, o->getSize().y / 2.f);
				tekstKomunikatu = std::make_unique<sf::Text>();
				tekstKomunikatu->setString("Niepoprawne rozmieszczenie statków!");
				tekstKomunikatu->setFillColor(sf::Color::Black);
				tekstKomunikatu->setFont(*zarzadzanie->czcionka2);
				tekstKomunikatu->setCharacterSize(50);
				tekstKomunikatu->setOrigin(tekstKomunikatu->getLocalBounds().width / 2.f, tekstKomunikatu->getLocalBounds().height / 2.f);
				tekstKomunikatu->setPosition(o->getSize().x / 2.f, o->getSize().y / 2.f - 60.f);
				ok = std::make_unique<Przycisk>(sf::Vector2f(o->getSize().x / 2.f, o->getSize().y / 2.f + 60.f), sf::Color::White, sf::Color(192, 192, 192), zarzadzanie->czcionka2, "OK", 55.f, 30);
			}
		}
	}
	else
	{
		ok->uaktywnij(o);
		if (ok->nacisniety == true)
		{
			ok->nacisniety = false;
			komunikat = false;
		}
	}
	return 0;
}
bool Poczatek::sprawdzeniePozycji()
{
	int poprawnie = true;
	sf::Vector2f lewygorny(siatka.getPosition());
	sf::Vector2f prawydolny(siatka.getPosition().x+siatka.getGlobalBounds().width, siatka.getPosition().y + siatka.getGlobalBounds().height);
	for (int i = 0; i < 5; i++)
	{
		sf::Vector2f pozycja(statki[i]->sprajt.getPosition());
		if (pozycja.x < lewygorny.x || pozycja.y < lewygorny.y || pozycja.x > prawydolny.x || pozycja.y > prawydolny.y)
		{
			poprawnie = false;
			break;
		}
	}

	return poprawnie;
}
bool Poczatek::sprawdzenieUlozenia()
{
	bool poprawnie = false; 
	if (sprawdzeniePozycji())
	{
		inicjalizujGraczy();
		int i = 0;
		for (auto st : statki)
		{
			//odczytaj polozenie
			sf::Vector2f lewygorny(siatka.getPosition());
			sf::Vector2f prawydolny(siatka.getPosition().x + siatka.getGlobalBounds().width, siatka.getPosition().y + siatka.getGlobalBounds().height);
			int pozycja = odczytajPolozenie(i, st, lewygorny, prawydolny);
			if (!zarzadzanie->czlowiek->RozstawStatki(i, static_cast<int>(st->orientacja), pozycja))
			{
				zarzadzanie->czlowiek->plansza->wyczyscPlansze();
				return false;
			}
			auto it = zarzadzanie->czlowiek->listaStatkow->begin();
			for (int j = 0; j < i; j++)
				it++;
			it->pozycja = pozycja;
			i++;
		}
		zarzadzanie->komputer->RozstawStatki();
		poprawnie = true;
	}
	return poprawnie;
}
void Poczatek::inicjalizujGraczy()
{
	zarzadzanie->czlowiek = std::make_unique<Czlowiek>();
	zarzadzanie->komputer = std::make_unique<Komputer>();
}
int Poczatek::odczytajPolozenie(int nr, Statek* statek, sf::Vector2f lewygorny, sf::Vector2f prawydolny)
{
	float rozmiarJednegoPola = (prawydolny.x - lewygorny.x) / 10;
	int x=10, y=10;
	if (nr == 0)
	{
		if (static_cast<int>(statek->orientacja) == 0)
		{
			x = (statek->sprajt.getPosition().x - lewygorny.x - 0.5 * rozmiarJednegoPola) / rozmiarJednegoPola;
			y = (statek->sprajt.getPosition().y - lewygorny.y) / rozmiarJednegoPola;
		}
		else
		{
			x = (statek->sprajt.getPosition().x - lewygorny.x) / rozmiarJednegoPola;
			y = (statek->sprajt.getPosition().y - lewygorny.y - 0.5 * rozmiarJednegoPola) / rozmiarJednegoPola;
		}
	}
	else if (nr == 1 || nr == 2)
	{
		if (static_cast<int>(statek->orientacja) == 0)
		{
			x = (statek->sprajt.getPosition().x - lewygorny.x - 1 * rozmiarJednegoPola)/ rozmiarJednegoPola;
			y = (statek->sprajt.getPosition().y - lewygorny.y) / rozmiarJednegoPola;
		}
		else
		{
			x = (statek->sprajt.getPosition().x - lewygorny.x) / rozmiarJednegoPola;
			y = (statek->sprajt.getPosition().y - lewygorny.y - 1 * rozmiarJednegoPola) / rozmiarJednegoPola;
		}
	}
	else if (nr == 3)
	{
		if (static_cast<int>(statek->orientacja) == 0)
		{
			x = (statek->sprajt.getPosition().x - lewygorny.x - 1.5 * rozmiarJednegoPola) / rozmiarJednegoPola;
			y = (statek->sprajt.getPosition().y - lewygorny.y) / rozmiarJednegoPola;
		}
		else
		{
			x = (statek->sprajt.getPosition().x - lewygorny.x) / rozmiarJednegoPola;
			y = (statek->sprajt.getPosition().y - lewygorny.y - 1.5 * rozmiarJednegoPola) / rozmiarJednegoPola;
		}
	}
	else if (nr == 4)
	{
		if (static_cast<int>(statek->orientacja) == 0)
		{
			x = (statek->sprajt.getPosition().x - lewygorny.x - 2 * rozmiarJednegoPola) / rozmiarJednegoPola;
			y = (statek->sprajt.getPosition().y - lewygorny.y) / rozmiarJednegoPola;
		}
		else
		{
			x = (statek->sprajt.getPosition().x - lewygorny.x) / rozmiarJednegoPola;
			y = (statek->sprajt.getPosition().y - lewygorny.y - 2 * rozmiarJednegoPola) / rozmiarJednegoPola;
		}
	}
	int pozycja = y * 10 + x;
	if ((pozycja >= 0 && pozycja < 100))
		return pozycja;
	else return -1;
}