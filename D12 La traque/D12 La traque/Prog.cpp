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
	PlacePisteur();
    system("pause");
    return(0);
}


//réflexions:----------------------------------------------------------------------------------------------------

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

void PlacePisteur()
{
	int nbPist = 0;
	do
	{
		nbPist = 0;
		printf("Combien	voulez-vous de pisteurs ?\n");
		printf("Entrez un chiffre entre 1 et 10\n");
		scanf("%d", &nbPist);
		AffichMap();
	} while ((nbPist < 1) || (nbPist > 10));
	int x = 0;
	int y = 0;
	do
	{
		printf("Il vous reste %d pisteur a placer\n", nbPist);
		printf("Definisez la position de votre pisteur\n");
		printf("Entrez un numero de colone: de 1 a 29\n");
		scanf("%d", &x);
		printf("Entrez un numero de ligne: de 1 a 14\n");
		scanf("%d", &y);
		if ((MAP[x][y] != 80) && (x > 0) && (y > 0) && (x < 29+1) && (y < 14+1))
		{
			MAP[x][y] = 80;
			nbPist--;
		}
		AffichMap();
	} while (nbPist > 0);
}

//affichages:----------------------------------------------------------------------------------------------------

inline void AffichMap()
{
	int cl = 0;
	system("cls");
	printf("                                          La Traque                                             \n");
	printf("                                         -----------                                            \n");
	printf("\n");
	printf("    0  1  2  3  4  5  6  7  8  9  10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30\n");
	for (int j = 0; j < TJY; j++)
	{
		if (cl<10)
			printf("%d ", cl);
		else 
			printf("%d", cl);
		cl++;
		for (int i = 0; i < TIX; i++)
		{
			Sleep(1);
			printf("  %c", MAP[i][j]);
			if (i == TIX - 1)
				printf("\n");
		}
	}
	printf("\n");
}