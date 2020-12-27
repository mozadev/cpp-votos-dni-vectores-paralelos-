//Ejercicio 9 de la hoja 1 de la semana 12
#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace System;
using namespace std;

void IngresarDatos(int *N, long long *DNI, int *Votos)
{
	for (int i = 0; i < *N; i++)
	{
		cout << "Ingrese el DNI nota de la persona " << i + 1 << ": ";
		cin >> DNI[i];
		while (DNI[i] <= 9999999 || DNI[i] >= 100000000)
		{
			cout << "Ingrese el DNI nota de la persona " << i + 1 << ": ";
			cin >> DNI[i];
		}
		cout << "Ingrese el voto de la persona " << i + 1 << ": ";
		cin >> Votos[i];
		while (Votos[i] != 1 && Votos[i] != 2 && Votos[i] != 3)
		{
			cout << "Ingrese el voto de la persona " << i + 1 << ": ";
			cin >> Votos[i];
		}
	}
}

void SalidaDatos(int *N, long long *DNI, int *Votos)
{
	for (int i = 0; i < *N; i++)
	{
		cout << "El voto de la persona " << i + 1 << " con DNI " << DNI[i] << " es: " << Votos[i] << endl;;
	}
}

void Datos(int *N, long long *DNI, int *Votos)
{
	int C1 = 0;
	int C2 = 0;
	int C3 = 0;
	long long Menor = DNI[0];

	for (int i = 0; i < *N; i++)
	{
		if (Votos[i] == 1)
		{
			C1++;
		}
		if (Votos[i] == 2)
		{
			C2++;
		}
		if (Votos[i] == 3)
		{
			C3++;
		}
	}

	for (int i = 1; i < *N; i++)
	{
		if (Menor>DNI[i])
			Menor = DNI[i];
	}

	cout << "El numero de personas que votaron por el candidato A es: " << C1 << endl;
	cout << "El numero de personas que votaron por el candidato B es: " << C2 << endl;
	cout << "El numero de personas que votaron viciado o en blanco es: " << C3 << endl;
	if (C1>C2)
	{
		cout << "El candidato ganador entre A y B es: A" << endl;
	}
	else
	{
		cout << "El candidato ganador entre A y B es: B" << endl;
	}
	cout << "El DNI del votante mas longevo es: " << Menor << endl;
}

int main()
{
	while (1)
	{
		int N;
		cout << "Ingrese el numero de personas: ";
		cin >> N;
		while (N<0 || N >= 101)
		{
			cout << "Vuelva a ingresar el numero de personas: ";
			cin >> N;
		}
		long long *DNI;
		DNI = new long long[N];
		int *Votos;
		Votos = new int[N];
		IngresarDatos(&N, DNI, Votos);
		SalidaDatos(&N, DNI, Votos);
		Datos(&N, DNI, Votos);
		cout << "--__--__--__--__-- Presione tecla para continuar --__--__--__--__--" << endl;
		_getch();
	}
}
