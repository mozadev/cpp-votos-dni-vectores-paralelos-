//Ejercicio 9 de la hoja 1 de la semana 12
#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include <stdlib.h>
#include<time.h>

using namespace std;
using namespace System;

void ingresadatos(int *n, int *dni, int *voto)
{
	for (int i = 0; i < *n; i++)
	{
		cout << "ingresa dni " << i + 1 << ": "; cin >> dni[i];
		while (dni[i] < 10000000 || dni[i]> 99999999)
		{
			cout << "ingresa dni " << i + 1 << ": "; cin >> dni[i];
		}
		cout << "ingresa voto " << i + 1 << ": "; cin >> voto[i];
		while (voto[i] != 1 && voto[i] != 2 && voto[i] != 3)
		{
			cout << "ingresa voto " << i + 1 << ": "; cin >> voto[i];
		}
	}
}

void salidadatos(int *n, int *dni, int *voto)
{
	for (int i = 0; i < *n; i++)
	{
		cout << " voto  " << i + 1 << " con dni:  " << dni[i] << " es " << voto[i] << endl;
	}

}

void reporte(int *n, int *dni, int *voto)
{
	int a = 0; int b = 0; int c = 0; int menor = dni[0]; int temp;
	for (int i = 1; i < *n; i++)
	{
		if (menor > dni[i])
			menor = dni[i];
	}

	for (int i = 0; i < *n; i++)
	{
		if (voto[i] == 1)
			a++;
		if (voto[i] == 2)
			b++;
		if (voto[i] == 3)
			c++;
	}


	cout << "cant de votos x A" << a << endl;
	cout << "cant de votos x B" << b << endl;
	cout << "cant de votos en BLANCO" << c << endl;

	if (a > b)

	cout << "el ganador es A" << endl;
	 if (a < b)

		cout << "el ganador es B " << endl;
	if(a=b)
		cout << "es un empate " << endl;

	cout << "el dni del votante mas longevo es" << menor << endl;
}










int main()
{
	int n;
	cout << "ingrese n"; cin >> n;
	while (n <= 0 || n > 100)
	{
		cout << "ingrese n"; cin >> n;
	}
	int*dni = new int[n];
	int*voto = new int[n];
	ingresadatos(&n, dni, voto);
	salidadatos(&n, dni, voto);
	reporte(&n, dni, voto);
	delete[]dni;
	delete[]voto;
	_getch();

}

