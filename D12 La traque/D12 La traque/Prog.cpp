#include "Header.h"

//#include "Affichages.cpp"
//j'ai laisser les fichier affichages et réflexion, afin de montrer que j'ai essayer de plus séparer mon code.
//le programme se lancais mais ne faisai pas ce que je veux... alors que le meme code copier coller directement 
//au meme endroit que le main fonctionne !?

static int MAP[31][16] = { 0 };
static int TIX = 31;
static int TJY = 16;

int main()
{
    FirstFillMap();
    AffichMap();
    system("pause");
    return(0);
}

inline void FirstFillMap()
{
	for (int j = 0; j < TJY; j++)
	{
		for (int i = 0; i < TIX; i++)
		{
			if ((j == 0) || (j == TJY - 1) || (i == 0) || (i == TIX - 1))
			{
				MAP[i][j] = 42;
			}
			else
			{
				MAP[i][j] = 32; 
			}
		}
	}
}

inline void AffichMap()
{
	for (int j = 0; j < TJY; j++)
	{
		for (int i = 0; i < TIX; i++)
		{
			Sleep(1);
			printf(" %c", MAP[i][j]);
			if (i == TIX - 1)
				printf("\n");
		}
	}
}