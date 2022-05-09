#include "Gra.h"

Gra::Gra()
{
	okno->create(sf::VideoMode(1920, 1080), "GRA STATKI");
	zarzadzanie = new Zarzadzanie_gra();
	stany.push_back(new Start());
}
Gra::~Gra()
{
	delete okno;
	delete zarzadzanie;
	while (stany.size() != 0)
	{
		stany.erase(stany.begin());
	}
}
void Gra::gra()
{
	//pentla wyœwielania gry
	sf::Event zdarzenie;
	while (okno->isOpen())
	{
		while (okno->pollEvent(zdarzenie))
		{
			if ((zdarzenie.type == zdarzenie.KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape) ||
				zdarzenie.type == sf::Event::Closed)
				okno->close();
		}
		Menu* wskMenu;
		Start* wskStart;
		Poczatek* wskPoczatek;
		Rozgrywka* wskRozgrywka;
		Koniec* wskKoniec;
		//UAKTUALNIENIE
		switch (zmiana)
		{
		case 0:
			break;
		case 1:
			//kolejny stan
			if (wskStart = dynamic_cast<Start*>(stany[0]))
			{
				stany.push_back(new Menu());
			}
			else if (wskMenu = dynamic_cast<Menu*>(stany[0]))
			{
				stany.push_back(new Poczatek());
			}
			else if (wskPoczatek = dynamic_cast<Poczatek*>(stany[0]))
			{
				stany.push_back(new Rozgrywka());
			}
			else if (wskRozgrywka = dynamic_cast<Rozgrywka*>(stany[0]))
			{
				stany.push_back(new Koniec(wskRozgrywka->wygrana));
			}
			else if (wskKoniec = dynamic_cast<Koniec*>(stany[0]))
			{
				stany.push_back(new Menu());
			}
			if (!stany.empty())
			{
				stany.erase(stany.begin());
			}
			zmiana = 0;
			break;
		case 2:
			//wypisanie zasad gry
			if (wskMenu = dynamic_cast<Menu*>(stany[0]))
			{
				wskMenu->zasady = true;
				wskMenu->inicjalizujZadadyGry(zarzadzanie);
			}
			break;
		case 3:
			okno->close();
		}
		okno->clear(sf::Color(0, 180, 247)); //65,105,225
		if (stany.size() == 0)
			okno->close();
		if (!stany[0]->zainicjowany)
		{
			stany[0]->inicjalizuj(zarzadzanie, okno);
		}
		zmiana = stany[0]->uaktualnij(okno, zdarzenie);
		//RYSOWANIE
		stany[0]->rysuj(okno);
		//WYSWIETLENIE
		okno->display();
	}
}