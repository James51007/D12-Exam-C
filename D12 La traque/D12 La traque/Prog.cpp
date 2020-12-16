#include "Header.h"

//#include "Affichages.cpp"
//j'ai laisser les fichier affichages et réflexion, afin de montrer que j'ai essayer de plus séparer mon code.
//le programme se lancais mais ne faisai pas ce que je veux... alors que le meme code copier coller directement 
//au meme endroit que le main fonctionne !?

//Pour le sdl j'ai reflechi pour le faire mais n'aillent presque rien compris. 
//J'ai abandoné cette partie pour favoriser un code plus propre et fonctionnel.

static int MAP[31][16] = { 0 }; //map contenent les codes ascii des object a afficher
static int TIX = 31; //taille de la map en x
static int TJY = 16; //taille de la map en y
static int coordPist[10][2] = { 0 }; //coordonees des pisteurs
static int NBPIST = 0; //nombre de pisteurs
static int monstreX = 0;
static int monstreY = 0;

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


//réflexions:----------------------------------------------------------------------------------------------------

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
		printf("Combien	voulez-vous de pisteurs ?\n");
		printf("Entrez un chiffre entre 1 et 10\n");
		scanf("%d", &nbPist);
		AffichMap();
	} while ((nbPist < 1) || (nbPist > 10));
	int x = 0;
	int y = 0;
	int num = 0;
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
			coordPist[num][0] = x;
			coordPist[num][1] = y;
			nbPist--;
		}
		num++;
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
	monstreX = mx;
	monstreY = my;
	system("cls");
	printf("creation du monstre");
	Sleep(1000);
	AffichMap();
}

void Game() //boucle de jeu
{
	bool end = false;
	bool victoire = false;
	do
	{
		DeplaPisteur();
		DeplaMonstre();
	} while (end == false);
	system("cls");
	if (victoire == true)
	{
		printf("Vous avez gagner le monstre a ete tuer");
	}
	else
	{
		printf("Vous avez perdu le monstre vous a eu");
	}
	Sleep(1000);
}

void DeplaPisteur() //deplacement des pisteurs
{
	int px = 0;
	int py = 0;
	int dir = 0;
	bool depla = false;
	for (int i = 0; i < NBPIST; i++)
	{
		px = coordPist[i][0];
		py = coordPist[i][1];
		printf("Choisisiez une direction deplacement pour votre pisteur numero %d\n",i+1);
		printf("1. Haut\n");
		printf("2. Bas\n");
		printf("3. Gauche\n");
		printf("4. Droite\n");
		scanf("%d", &dir);
		do
		{
			do
			{
				MAP[px][py] = 32;
				switch (dir)
				{
					case 1:
					{	
						if (MAP[px][py - 1] != 32)
						{
							printf("Impossible de se déplacer dans cette direction\n");
						}
						else
						{
							MAP[px][py - 1] = 80;
							depla = true;
						}
						break;
					}
					case 2:
					{
						if (MAP[px][py + 1] != 32)
						{
							printf("Impossible de se déplacer dans cette direction\n");
						}
						else
						{
							MAP[px][py - 1] = 80;
							depla = true;
						}
						break;
					}
					case 3:
					{
						if (MAP[px - 1][py] != 32)
						{
							printf("Impossible de se déplacer dans cette direction\n");
						}
						else
						{
							MAP[px][py - 1] = 80;
							depla = true;
						}
						break;
					}
					case 4:
					{
						if (MAP[px + 1][py] != 32)
						{
							printf("Impossible de se déplacer dans cette direction\n");
						}
						else
						{
							MAP[px][py - 1] = 80;
							depla = true;
						}
						break;
					}
				}
			} while ((dir < 1) || (dir > 4));
		} while (depla == true);
		depla = false;
		AffichMap();
		VerifTrace(i+1);
	}
}

void DeplaMonstre() //deplacement de monstre au tour par tour
{
	int x = 0;
	int y = 0;
	int dir = 0;
	x = monstreX;
	y = monstreY;
	dir = (rand() % 4) + 1;
	MAP[x][y] = 15;
	switch (dir)
	{
	case 1:
	{
		MAP[x][y - 1] = 80;
		break;
	}
	case 2:
	{
		MAP[x][y + 1] = 80;
		break;
	}
	case 3:
	{
		MAP[x - 1][y] = 80;
		break;
	}
	case 4:
	{
		MAP[x + 1][y] = 80;
		break;
	}
	}
	for (int j = 0; j < TJY; j++)
	{
		for (int i = 0; i < TIX; i++)
		{
			if ((MAP[i][j] < 16) && (MAP[i][j] > 0))
			{
				MAP[i][j]--;
				if (MAP[i][j] < 1)
				{
					MAP[i][j] = 32;
				}
			}
		}
	}
}

void VerifTrace(int numPist) //verifie si des trace ou le monstre qont a proximité d'un pisteur
{
	int x = coordPist[numPist][0];
	int y = coordPist[numPist][1];
	int cooX = 0;
	int cooY = 0;
	if (((MAP[x][y - 1] < 16) && (MAP[x][y - 1] > 0)) || (MAP[x][y - 1] == 77))
	{
		cooX = x;
		cooY = y - 1;
		if ((MAP[cooX][cooY] < 16) && (MAP[cooX][cooY] > 0))
		{
			printf("Le pisteur numero %d a trouver des traces ",numPist);
		}
		if (MAP[cooX][cooY] == 77)
		{
			printf("Le pisteur numero %d a trouver le monstre ",numPist);
		}
		printf("au coordonee: %d / ",cooX);
		printf("%d \n",cooY);
	}
	if (((MAP[x][y + 1] < 16) && (MAP[x][y + 1] > 0)) || (MAP[x][y + 1] == 77))
	{
		cooX = x;
		cooY = y + 1;
		if ((MAP[cooX][cooY] < 16) && (MAP[cooX][cooY] > 0))
		{
			printf("Le pisteur numero %d a trouver des traces ", numPist);
		}
		if (MAP[cooX][cooY] == 77)
		{
			printf("Le pisteur numero %d a trouver le monstre ", numPist);
		}
		printf("au coordonee: %d / ", cooX);
		printf("%d \n", cooY);
	}
	if (((MAP[x - 1][y] < 16) && (MAP[x - 1][y] > 0)) || (MAP[x - 1][y] == 77))
	{
		cooX = x - 1;
		cooY = y;
		if ((MAP[cooX][cooY] < 16) && (MAP[cooX][cooY] > 0))
		{
			printf("Le pisteur numero %d a trouver des traces ", numPist);
		}
		if (MAP[cooX][cooY] == 77)
		{
			printf("Le pisteur numero %d a trouver le monstre ", numPist);
		}
		printf("au coordonee: %d / ", cooX);
		printf("%d \n", cooY);
	}
	if (((MAP[x + 1][y] < 16) && (MAP[x + 1][y] > 0)) || (MAP[x + 1][y] == 77))
	{
		cooX = x + 1;
		cooY = y;
		if ((MAP[cooX][cooY] < 16) && (MAP[cooX][cooY] > 0))
		{
			printf("Le pisteur numero %d a trouver des traces ", numPist);
		}
		if (MAP[cooX][cooY] == 77)
		{
			printf("Le pisteur numero %d a trouver le monstre ", numPist);
		}
		printf("au coordonee: %d / ", cooX);
		printf("%d \n", cooY);
	}
	if (((MAP[x + 1][y - 1] < 16) && (MAP[x + 1][y - 1] > 0)) || (MAP[x + 1][y - 1] == 77))
	{
		cooX = x + 1;
		cooY = y - 1;
		if ((MAP[cooX][cooY] < 16) && (MAP[cooX][cooY] > 0))
		{
			printf("Le pisteur numero %d a trouver des traces ", numPist);
		}
		if (MAP[cooX][cooY] == 77)
		{
			printf("Le pisteur numero %d a trouver le monstre ", numPist);
		}
		printf("au coordonee: %d / ", cooX);
		printf("%d \n", cooY);
	}
	if (((MAP[x - 1][y + 1] < 16) && (MAP[x - 1][y + 1] > 0)) || (MAP[x - 1][y + 1] == 77))
	{
		cooX = x - 1;
		cooY = y + 1;
		if ((MAP[cooX][cooY] < 16) && (MAP[cooX][cooY] > 0))
		{
			printf("Le pisteur numero %d a trouver des traces ", numPist);
		}
		if (MAP[cooX][cooY] == 77)
		{
			printf("Le pisteur numero %d a trouver le monstre ", numPist);
		}
		printf("au coordonee: %d / ", cooX);
		printf("%d \n", cooY);
	}
	if (((MAP[x - 1][y - 1] < 16) && (MAP[x - 1][y - 1] > 0)) || (MAP[x - 1][y - 1] == 77))
	{
		cooX = x - 1;
		cooY = y - 1;
		if ((MAP[cooX][cooY] < 16) && (MAP[cooX][cooY] > 0))
		{
			printf("Le pisteur numero %d a trouver des traces ", numPist);
		}
		if (MAP[cooX][cooY] == 77)
		{
			printf("Le pisteur numero %d a trouver le monstre ", numPist);
		}
		printf("au coordonee: %d / ", cooX);
		printf("%d \n", cooY);
	}
	if (((MAP[x + 1][y + 1] < 16) && (MAP[x + 1][y + 1] > 0)) || (MAP[x + 1][y + 1] == 77))
	{
		cooX = x + 1;
		cooY = y + 1;
		if ((MAP[cooX][cooY] < 16) && (MAP[cooX][cooY] > 0))
		{
			printf("Le pisteur numero %d a trouver des traces ", numPist);
		}
		if (MAP[cooX][cooY] == 77)
		{
			printf("Le pisteur numero %d a trouver le monstre ", numPist);
		}
		printf("au coordonee: %d / ", cooX);
		printf("%d \n", cooY);
	}
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