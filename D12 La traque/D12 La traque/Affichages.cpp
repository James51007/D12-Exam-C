#include "Header.h"
#include "R�flexions.cpp"
#include "Main.cpp"

void AffichMap()
{
	for (int j = 0; j < TJY; j++)
	{
		for (int i = 0; i < TIX; i++)
		{
			printf("%c", MAP[j][i]);
			if (i == TIX - 1)
				printf("\n");
		
		}
	}
}