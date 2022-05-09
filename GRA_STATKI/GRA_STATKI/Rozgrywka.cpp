#include "Rozgrywka.h"
#include <iostream>

Rozgrywka::Rozgrywka()
{
	for (int i = 0; i < 5; i++)
	{
		Statek* s = new Statek();
		statki.push_back(s);
	}
}
Rozgrywka::~Rozgrywka()
{

}
void Rozgrywka::inicjalizuj(Zarzadzanie_gra*& z, sf::RenderWindow*& o)
{
	tytul.setString("STATKI");
	tytul.setFillColor(sf::Color::Black);
	tytul.setFont(*z->czcionka1);
	tytul.setCharacterSize(120);
	tytul.setOrigin(tytul.getLocalBounds().width / 2.f, tytul.getLocalBounds().height / 2.f);
	tytul.setPosition(o->getSize().x / 2.f, 60.f);
	zdanie.setString("Twoj ruch.");
	zdanie.setFillColor(sf::Color::Black);
	zdanie.setFont(*z->czcionka2);
	zdanie.setCharacterSize(80);
	zdanie.setOrigin(tytul.getLocalBounds().width / 2.f, tytul.getLocalBounds().height / 2.f);
	tytul.setPosition(o->getSize().x / 2.f, o->getSize().y - 60.f);
	siatka.setTexture(*z->tekstury[9]);
	siatka.setScale(2.3f, 2.3f);
	siatka.setPosition(o->getSize().x / 2.f - 100.f - siatka.getGlobalBounds().width, 200.f);
	siatka2.setTexture(*z->tekstury[9]);
	siatka2.setPosition(o->getSize().x / 2.f + 100.f, 200.f);
	siatka2.setScale(2.3f, 2.3f);
	zarzdzanie = z;
	ogien = *z->tekstury[6];
	pudlo = *z->tekstury[7];
	sf::Vector2f lewygorny(siatka2.getPosition());
	sf::Vector2f prawydolny(siatka2.getPosition().x + siatka2.getGlobalBounds().width, siatka2.getPosition().y + siatka2.getGlobalBounds().height);
	float rozmiarJednegoPola = (prawydolny.x - lewygorny.x) / 10;
	int tab[5] = { 0,1,1,2,3 };
	for (int i = 0; i < 5; i++)
	{
		auto it = z->czlowiek->listaStatkow->begin();
		for(int j=0; j<i; j++)
			it++;
		int x = it->pozycja % 10;
		int y = it->pozycja / 10;
		float pol;
		if ((tab[i] + 2) % 2 == 1)
			pol = 0.5;
		else
			pol = 0;
		statki[i]->inicjalizuj(z->tekstury[tab[i]]);
		statki[i]->sprajt.setOrigin(statki[i]->sprajt.getLocalBounds().width / 2.f, statki[i]->sprajt.getLocalBounds().height / 2.f);
		if (static_cast<int>(it->orientacja) == 0)
		{
			statki[i]->sprajt.setPosition(lewygorny.x + x * rozmiarJednegoPola + ((tab[i]+2)/2 + pol) * rozmiarJednegoPola, lewygorny.y + y * rozmiarJednegoPola + (0.5) * rozmiarJednegoPola);
		}
		else
		{
			statki[i]->zmienOrientacje();
			statki[i]->sprajt.setPosition(lewygorny.x + x * rozmiarJednegoPola + (0.5) * rozmiarJednegoPola, lewygorny.y + y * rozmiarJednegoPola + ((tab[i] + 2) / 2 + pol) * rozmiarJednegoPola);
		}
	}
	zainicjowany = true;
}
int Rozgrywka::uaktualnij(sf::RenderWindow*& o, sf::Event& e)
{
	bool trafiony= false;

	if (ruchCzlowieka)
	{
		trafiony = false;
		sf::Vector2f lewygorny(siatka.getPosition());
		sf::Vector2f prawydolny(siatka.getPosition().x + siatka.getGlobalBounds().width, siatka.getPosition().y + siatka.getGlobalBounds().height);
		sf::Vector2f pozycja = sf::Vector2f(sf::Mouse::getPosition(*o));
		float rozmiarJednegoPola = (prawydolny.x - lewygorny.x) / 10;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			int ruch = zarzdzanie->czlowiek->WykonajRuch(lewygorny, prawydolny, pozycja);
			char z = zarzdzanie->komputer->plansza->CzyTrafiony(ruch);
			if(z!='.')
			{
				trafiony = true;
				zarzdzanie->komputer->Trafiony(z);
			}
			int w = ruch / 10;
			int k = ruch % 10;
			if (trafiony)
			{
				//dodoanie do vectora
				trafienia.push_back(new sf::Sprite());
				auto tr = trafienia.back();
				tr->setTexture(ogien);
				tr->setPosition(lewygorny.x + k * rozmiarJednegoPola, lewygorny.y + w * rozmiarJednegoPola);
				zdanie.setString("Trafiony.");
				//sprawdzenie czy zatopiony
				if (false) zdanie.setString("Zatopiony.");
			}
			else
			{
				//dodoanie do vectora
				pudla.push_back(new sf::Sprite());
				auto pu = pudla.back();
				pu->setTexture(pudlo);
				pu->setPosition(lewygorny.x + k * rozmiarJednegoPola, lewygorny.y + w * rozmiarJednegoPola);
				ruchCzlowieka = false;
				zdanie.setString("Ruch przeciwnika.");
				//dokonczyc
				if (false) zdanie.setString("Zatopiony.");
			}
		}
		if (zarzdzanie->komputer->KoniecGry())
		{
			koniec = true;
			wygrana = true;
		}
	}
	else
	{
		trafiony = false;
		sf::Vector2f lewygorny(siatka2.getPosition());
		sf::Vector2f prawydolny(siatka2.getPosition().x + siatka2.getGlobalBounds().width, siatka2.getPosition().y + siatka2.getGlobalBounds().height);
		sf::Vector2f pozycja = sf::Vector2f(sf::Mouse::getPosition(*o));
		float rozmiarJednegoPola = (prawydolny.x - lewygorny.x) / 10;
		int ruch = zarzdzanie->komputer->WykonajRuch();
		char z = zarzdzanie->czlowiek->plansza->CzyTrafiony(ruch);
		if(z!='.')
		{
			trafiony = true;
			zarzdzanie->komputer->Trafiony(z);
		}
		int w = ruch / 10;
		int k = ruch % 10;
		if (trafiony)
		{
			trafienia.push_back(new sf::Sprite());
			auto tr = trafienia.back();
			tr->setTexture(*zarzdzanie->tekstury[6]);
			tr->setPosition(lewygorny.x + k * rozmiarJednegoPola, lewygorny.y + w * rozmiarJednegoPola);
			//dodoanie do vectora
			zdanie.setString("Trafiony.");
		}
		else
		{
			pudla.push_back(new sf::Sprite());
			auto pu = pudla.back();
			pu->setTexture(pudlo);
			pu->setPosition(lewygorny.x + k * rozmiarJednegoPola, lewygorny.y + w * rozmiarJednegoPola);
			//sprawdzenie czy zatopiony
			ruchCzlowieka = true;
			zdanie.setString("Twoja kolej.");
		}
		if (zarzdzanie->czlowiek->KoniecGry())
		{
			koniec = true;
			wygrana = false;
		}

	}
	if (koniec)
		return 1;
	return 0;
}
void Rozgrywka::rysuj(sf::RenderWindow*& o)
{
	o->draw(tytul);
	o->draw(siatka);
	o->draw(siatka2);
	for (int i = 0; i < 5; i++)
	{
		statki[i]->rysuj(o);
	}
	if (trafienia.size() != 0)
	{
		for (auto i = trafienia.begin(); i != trafienia.end(); i++)
		{
			o->draw(**i);
		}
	}
	if (pudla.size() != 0)
	{
		for (auto i = pudla.begin(); i != pudla.end(); i++)
		{
			o->draw(**i);
		}
	}
}
void Rozgrywka::noweTrafienie(int w, int k)
{

}
void Rozgrywka::nowePudlo(int w, int k)
{

}
