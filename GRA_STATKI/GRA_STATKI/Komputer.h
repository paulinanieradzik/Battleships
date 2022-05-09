#ifndef KOMPUTER_H
#define KOMPUTER_H
#include "Gracz.h"
#include <random>
#include <algorithm>

class Komputer :public Gracz
{
    friend class Rozgrywka;
    int rozkladMiejsca;
    int rozkladOrientacji;
public:
    Komputer();
    void RozstawStatki();
    int losuj(int zakres);
    int WykonajRuch();
};

#endif