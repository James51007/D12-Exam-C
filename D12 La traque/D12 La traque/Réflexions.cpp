#include "Header.h"
#include "Affichages.cpp"
#include "Main.cpp"

int FirstFillMap()
{
	for (int j = 0; j < TJY; j++)
	{
		for (int i = 0; i < TIX; i++)
		{
			if ((j == 0)||(j == TJY-1)||(i == 0)||(i == TIX-1)
				MAP[j][i] = 42;
			MAP[j][i] = 0;
		}
	}
}