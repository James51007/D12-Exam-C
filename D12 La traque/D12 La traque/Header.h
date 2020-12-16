#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#pragma warning (disable:4996)

void FirstFillMap();
void PlacePisteur();
void InitGame();
void Game();
void DeplaPisteur();
void DeplaMonstre();
void VerifTrace(int numPist);
void AffichMap();


//ASCII:
//space=32
//P=80
//M=77
//*=42
//0=48
//1=49
//2=50
//3=51
//4=52
//5=53
//6=54
//7=55
//8=56
//9=57