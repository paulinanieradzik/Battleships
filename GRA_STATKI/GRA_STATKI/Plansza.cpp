#include "Plansza.h"
#include <iostream>

Plansza::Plansza()
{
	for(int i=0; i<10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			mojaPlansza[i][j] = '.';
			planszaPrzeciwnika[i][j] = '.';
		}
	}
}
bool Plansza::sprawdzCzyMoznaUstawic(int pozycja, int wielkosc, char znak, int orientacja)
{
	int x = pozycja / 10;
	int y = pozycja % 10;
	if (orientacja == 0)
	{
		if (y + wielkosc > 10)
			return false;
		for (int i = y - 1; i < y + wielkosc + 1; i++)
		{
			if (i < 10 && i >= 0)
			{
				if (mojaPlansza[x][i] != '.')
					return false;
				if (x - 1 >= 0)
					if (mojaPlansza[x - 1][i] != '.')
						return false;
				if (x + 1 < 10)
					if (mojaPlansza[x + 1][i] != '.')
						return false;
			}
		}
	}
	else
	{
		if (x + wielkosc > 10)
			return false;
		for (int i = x - 1; i < x + wielkosc + 1; i++)
		{
			if (i < 10 && i >= 0)
			{
				if (mojaPlansza[i][y] != '.')
					return false;
				if (y - 1 >= 0)
					if (mojaPlansza[i][y - 1] != '.')
						return false;
				if (y + 1 < 10)
					if (mojaPlansza[i][y + 1] != '.')
						return false;
			}
		}
	}
	zaznaczNaPlanszy(x, y, znak, wielkosc, orientacja);
	return true;
}
void Plansza::zaznaczNaPlanszy(int x, int y, char znak, int wielkosc, int orientacja)
{
	if (orientacja == 0)
	{
		for (int i = y; i < y + wielkosc; i++)
		{
			mojaPlansza[x][i] = znak;
		}
	}
	else
	{
		for (int i = x; i < x + wielkosc; i++)
		{
			mojaPlansza[i][y] = znak;
		}
	}
}
void Plansza::wyczyscPlansze()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			mojaPlansza[i][j] = '.';
		}
	}
}
char Plansza::CzyTrafiony(int ruch)
{
	std::cout << "ruch: " << ruch << std::endl;
	int w = ruch / 10;
	int k = ruch % 10;
	char znak;
	std::cout << "tak6" << std::endl;
	znak = mojaPlansza[w][k];
	if (znak == 'a' || znak == 'b' || znak == 'c' || znak == 'd' || znak == 'e')
		mojaPlansza[w][k] = mojaPlansza[w][k] - 32;
	else if (znak == '.')
		mojaPlansza[w][k] = 'x';
	std::cout << "tak7" << std::endl;
	return znak;
}
