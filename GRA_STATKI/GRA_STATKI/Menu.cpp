#include "Menu.h"

Menu::~Menu()
{
	while (tekstZasad.size() != 0)
	{
		tekstZasad.erase(tekstZasad.begin());
	}
	while (przyciski.size() != 0)
	{
		przyciski.erase(przyciski.begin());
	}
}
void Menu::inicjalizuj(Zarzadzanie_gra*& z, sf::RenderWindow*& o)
{
	statekTlo.setTexture(*z->tekstury[8]);
	statekTlo.setPosition(350.f, 230.f);
	przyciski.push_back(new Przycisk(sf::Vector2f(550.f, 600.f), sf::Color::White, sf::Color(192,192,192), z->czcionka2, "Zagraj"));
	przyciski.push_back(new Przycisk(sf::Vector2f(950.f, 600.f), sf::Color::White, sf::Color(192, 192, 192), z->czcionka2, "Jak grac"));
	przyciski.push_back(new Przycisk(sf::Vector2f(1350.f, 600.f), sf::Color::White, sf::Color(192, 192, 192), z->czcionka2, "Wyjscie"));
	zainicjowany = true;
	tytul.setString("STATKI");
	tytul.setFillColor(sf::Color::Black);
	tytul.setFont(*z->czcionka1);
	tytul.setCharacterSize(120);
	tytul.setOrigin(tytul.getLocalBounds().width / 2.f, tytul.getLocalBounds().height / 2.f);
	tytul.setPosition(o->getSize().x / 2.f, 60.f);
}
int Menu::uaktualnij(sf::RenderWindow*& o, sf::Event& e)
{
	if (zasady == false)
	{
		int i = 1;
		for (auto p = przyciski.begin(); p != przyciski.end(); p++)
		{
			(*p)->uaktywnij(o);
			if ((*p)->nacisniety == true)
			{
				(*p)->nacisniety = false;
				return i;
			}
			i++;
		}
		return 0;
	}
	else
		return uaktualnijZasady(o);
}
void Menu::rysuj(sf::RenderWindow*& o)
{
	o->draw(tytul);
	if (zasady == false)
	{
		o->draw(statekTlo);
		for (int i = 0; i < 3; i++)
		{
			przyciski[i]->rysuj(o);
		}
	}
	else
		rysujZadadyGry(o);
}
void Menu::inicjalizujZadadyGry(Zarzadzanie_gra*& z)
{
	//TEKST
	for (int i = 0; i < 8; i++)
	{
		tekstZasad.push_back(new sf::Text);
	}
	std::string punkty = "Zasady gry w satatki sa bardzo proste:";
	std::string punkty2 = "\t1. Ustaw wszystkie swoje statki na planszy.";
	std::string punkty3 = "\t2. Sprobuj zatopic wszystkie statki przeciwnika zanim on zatopi twoje!";
	std::string ustawienie = "*Chwyc statek naciskajac lewy przycisk myszy, a nastepnie ustaw go w wybranym miejscu.";
	std::string orientaja = "*Zmiana orientacji statku pion/poziom nastepuje po nacisnieciu spacji.";
	std::string strzal = "*Aby strzelic w statek przeciwnika najedz myszka na wybrane pole i nacinij lewy przycisk myszy.";
	std::string koniec = "*Strzelaj celnie i WYGAJ!";
	std::string powodzenia = "POWODZENIA!";
	tekstZasad[0]->setString(punkty);
	tekstZasad[1]->setString(punkty2);
	tekstZasad[2]->setString(punkty3);
	tekstZasad[3]->setString(ustawienie);
	tekstZasad[4]->setString(orientaja);
	tekstZasad[5]->setString(strzal);
	tekstZasad[6]->setString(koniec);
	tekstZasad[7]->setString(powodzenia);
	for (int i = 0; i < 8; i++)
	{
		tekstZasad[i]->setFillColor(sf::Color::Black);
		tekstZasad[i]->setFont(*z->czcionka2);
		tekstZasad[i]->setCharacterSize(30);
	}
	tekstZasad[0]->setPosition(130.f, 250.f);
	tekstZasad[1]->setPosition(130.f, 300.f);
	tekstZasad[2]->setPosition(130.f, 350.f);
	tekstZasad[3]->setPosition(130.f, 500.f);
	tekstZasad[4]->setPosition(130.f, 550.f);
	tekstZasad[5]->setPosition(130.f, 600.f);
	tekstZasad[6]->setPosition(130.f, 650.f);
	tekstZasad[7]->setPosition(500.f, 750.f);
	//ANIMACJA
	siatka.setTexture(*z->tekstury[9]);
	siatka.setPosition(1305.f, 200.f);
	siatka.setScale(1.2f, 1.2f);

	statek.setTexture(*z->tekstury[1]);
	statek.setOrigin(statek.getLocalBounds().width / 2.f, statek.getLocalBounds().height / 2.f);
	statek.setPosition(1800.f, 300.f);
	statek.setScale(0.5f, 0.5f);
	statek2.setTexture(*z->tekstury[1]);
	statek2.setOrigin(statek.getLocalBounds().width / 2.f, statek.getLocalBounds().height / 2.f);
	statek2.setPosition(1800.f, 400.f);
	statek2.setScale(0.5f, 0.5f);
	//POWROT DO MENU
	powrot = std::make_unique<Przycisk>(sf::Vector2f(1700.f, 850.f), sf::Color::White, sf::Color(192, 192, 192), z->czcionka2, "Powrot", 65.f, 30);
}
int Menu::uaktualnijZasady(sf::RenderWindow*& o)
{
	if (statek.getPosition().x > 1510.f and statek.getPosition().y < 600.f)
		statek.move(-0.2f, 0.1f);
	else if (statek2.getRotation() == 0)
		statek2.setRotation(-90);
	else if(statek2.getPosition().x > 1350.f and statek2.getPosition().y >300.f)
		statek2.move(-0.2f, -0.05f);
	else
	{
		statek.setPosition(1800.f, 300.f);
		statek2.setPosition(1800.f, 400.f);
		statek2.setRotation(0);
	}
	powrot->uaktywnij(o);
	if (powrot->nacisniety == true)
	{
		powrot->nacisniety = false;
		zasady = false;
	}
	return 0;
}
void Menu::rysujZadadyGry(sf::RenderWindow*& o)
{
	for (int i = 0; i < 8; i++)
	{
		o->draw(*tekstZasad[i]);
	}
	o->draw(siatka);
	o->draw(statek);
	o->draw(statek2);
	powrot->rysuj(o);
}

