#ifndef ROZGRYWKA_H
#define ROZGRYWKA_H
#include "Stan_gry.h"
#include <list>

class Rozgrywka : public Stan_gry
{
    sf::Text tytul;
    sf::Text zdanie;
    sf::Sprite siatka;
    sf::Sprite siatka2;
    sf::Texture ogien;
    sf::Texture pudlo;
    bool ruchCzlowieka = true;
    bool koniec = false;
    Zarzadzanie_gra* zarzdzanie;
    std::vector<Statek*> statki;
    std::vector<sf::Sprite*> trafienia;
    std::vector<sf::Sprite*> pudla;
public:
    bool wygrana;
    Rozgrywka();
    ~Rozgrywka();
    void inicjalizuj(Zarzadzanie_gra*& z, sf::RenderWindow*& o);
    int uaktualnij(sf::RenderWindow*& o, sf::Event& e);
    void rysuj(sf::RenderWindow*& o);
    void noweTrafienie(int w, int k);
    void nowePudlo(int w, int k);
};

#endif