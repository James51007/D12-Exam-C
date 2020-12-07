#include "Header.h"
#include "Affichages.cpp"
#include "Réflexions.cpp"

int MAP[31][16] = { NULL };
int TIX = 31;
int TJY = 16;

void main()
{
    FirstFillMap();
    AffichMap();
    system("pause");
}