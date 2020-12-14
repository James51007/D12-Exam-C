#include "Header.h"

//#include "Affichages.cpp"
//j'ai laisser les fichier affichages et r�flexion, afin de montrer que j'ai essayer de plus s�parer mon code.
//le programme se lancais mais ne faisai pas ce que je veux... alors que le meme code copier coller directement 
//au meme endroit que le main fonctionne !?

//Pour le sdl j'ai reflechi pour le faire mais n'aillent presque rien compris. 
//J'ai abandon� cette partie pour favoriser un code plus propre et fonctionnel.

static int MAP[31][16] = { 0 }; //map contenent les codes ascii des object a afficher
static int TIX = 31; //taille de la map en x
static int TJY = 16; //taille de la map en y

void main()
{
	srand(time(NULL)); //initialisation de la fonction random 
    FirstFillMap(); //preremplisage des bords de la map
    AffichMap(); //affichage et mise en page 
	PlacePisteur(); //placement des pisteurs dans la map
	InitGame(); //Placement du monstre 
	Game(); //boucle de jeu
    system("pause");
}


//r�flexions:----------------------------------------------------------------------------------------------------

void FirstFillMap() //preremplisage des bords de la map
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

void PlacePisteur() //placement des pisteurs dans la map
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
		system("cls");
		printf("creation du pisteur");
		Sleep(1000);
		AffichMap();
	} while (nbPist > 0);
}

void InitGame() //Placement du monstre 
{
	int mx = 0;
	int my = 0;
	do
	{
		mx = (rand() % 29) + 1;
		my = (rand() % 14) + 1;
	} while ((MAP[mx][my] == 42) || (MAP[mx][my] == 80));
	MAP[mx][my] = 77;
	system("cls");
	printf("creation du monstre");
	Sleep(1000);
	AffichMap();
}

void Game() //boucle de jeu
{
	do
	{

	} while ((0 == 0));
}

//affichages:----------------------------------------------------------------------------------------------------

void AffichMap() //affichage et mise en page 
{
	int cl = 0;
	system("cls");
	printf("                                          La Traque\n");
	printf("                                         -----------\n");
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
			//printf("");
			//Sleep(1);
			//system("cls");
			printf("  %c", MAP[i][j]);
			if (i == TIX - 1)
				printf("\n");
		}
	}
	printf("\n");
}