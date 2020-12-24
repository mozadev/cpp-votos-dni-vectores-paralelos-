
void IngresarDatos(int *N, long long *DNI, int *Votos)
{
	for (int i = 0; i < *N; i++)
	{
		cout << "Ingrese el DNI de la persona " << i + 1 << ": ";
		cin >> DNI[i];
		while (DNI[i] <= 10000000 || DNI[i] >99999999)
		{
			cout << "Vuelva a ingresar el DNI de la persona " << i + 1 << ": ";
			cin >> DNI[i];
		}
		cout << "Ingrese el voto de la persona " << i + 1 << ": ";
		cin >> Votos[i];
		while (Votos[i] != 1 && Votos[i] != 2 && Votos[i] != 3)
		{
			cout << " Vuelva a ingresar el voto de la persona " << i + 1 << ": ";
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
	int Contador1 = 0;
	int Contador2 = 0;
	int Contador3 = 0;
	long long Menor = DNI[0];
	for (int i = 0; i < *N; i++)
	{
		if (Votos[i] == 1)
		{
			Contador1++;
		}
		if (Votos[i] == 2)
		{
			Contador2++;
		}
		if (Votos[i] == 3)
		{
			Contador3++;
		}
	}
	for (int i = 1; i < *N; i++)
	{
		if (Menor>DNI[i])
			Menor = DNI[i];
	}
	cout << "El numero de personas que votaron por el candidato A es: " << Contador1 << endl;
	cout << "El numero de personas que votaron por el candidato B es: " << Contador2 << endl;
	cout << "El numero de personas que votaron viciado o en blanco es: " << Contador3 << endl;
	if (Contador1>Contador2)
	{
		cout << "El candidato ganador entre A y B es: A" << endl;
	}
	if (Contador2>Contador1)
	{
		cout << "El candidato ganador entre A y B es: B" << endl;
	}
	else
	{
		cout << "El candidato ganador entre A y B es: empate" << endl;
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
		delete[] Votos;
		_getch();
	}
}