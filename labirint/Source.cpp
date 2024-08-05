#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>

using namespace std;



void afisare_matrice(char matrice[20][20], int dim)
{
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			cout << matrice[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl;
}


void labirint(char matrice[20][20],int dim)
{
	int i = 1, j = 1;
	char key=0;
	cout << "WELCOME !";
	cout << endl;
	system("pause");
	system("CLS");
	cout << "Use arrow to move.";
	cout << endl;
	system("pause");
	system("CLS");
	afisare_matrice(matrice, dim);
	while ((i != 0 && i != dim - 1) && (j != 0 && j != dim - 1))
	{
		_getch();
		system("CLS");
		key = _getch();

		if (key == 80 && matrice[i+1][j]!='#')
		{
			matrice[i][j] = '.';
			i++;
			matrice[i][j] = 'O';
		}
		if (key == 77 && matrice[i][j+1]!='#')
		{
			matrice[i][j] = '.';
			j++;
			matrice[i][j] = 'O';
		}
		if (key == 72 && matrice[i - 1][j] != '#')
		{
			matrice[i][j] = '.';
			i--;
			matrice[i][j] = 'O';
		}
		if (key == 75 && matrice[i][j - 1] != '#')
		{
			matrice[i][j] = '.';
			j--;
			matrice[i][j] = 'O';
		}
		if (key == 27)
		{
			i = dim - 1;
		}
		afisare_matrice(matrice, dim);
	}
	system("CLS");
	cout << "Congratulations you finished the maze";
	cout << endl;
	system("pause");
	system("CLS");
	
}
void citire_matrice_fisier(char matrice[20][20], int& dim, string filename)
{
	ifstream fisier;
	fisier.open(filename);
	fisier >> dim;
	for (int i = 0; i < dim; i++)
	{
		for (int j = 0; j < dim; j++)
		{
			fisier >> matrice[i][j];
		}
	}
	fisier.close();
}

int main()
{
	char matrice[20][20];
	int dim;
	citire_matrice_fisier(matrice, dim, "labirint.txt");
	labirint(matrice, dim);
}