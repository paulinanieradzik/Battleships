#ifndef POCZATEK_H
#define POCZATEK_H
#include <vector>
#include "Stan_gry.h"
#include "Statek.h"

class Poczatek : public Stan_gry
{
    std::vector<Statek*> statki;
    sf::Sprite siatka;
    int przenoszony = 10 ;
    sf::Text tytul;
    std::unique_ptr<Przycisk> dalej;
    Zarzadzanie_gra* zarzadzanie;
    bool komunikat = false;
    std::unique_ptr <sf::RectangleShape> okienko;
    std::unique_ptr <sf::Text> tekstKomunikatu;
    std::unique_ptr <Przycisk> ok;
public:
    Poczatek();
    ~Poczatek();
    void inicjalizuj(Zarzadzanie_gra*& z, sf::RenderWindow*& o);
    int uaktualnij(sf::RenderWindow*& o, sf::Event& e);
    void rysuj(sf::RenderWindow*& o);
    bool sprawdzeniePozycji();
    bool sprawdzenieUlozenia();
    void inicjalizujGraczy();
    int odczytajPolozenie(int nr, Statek* statek, sf::Vector2f lewygorny, sf::Vector2f prawydolny);
};

#endif