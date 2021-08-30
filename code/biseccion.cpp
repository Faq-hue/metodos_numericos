#include <stdio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
using namespace std;
// cambio la funcion que me interesa valuar
double f(double x){
	return (-3* (x*x*x) + 5* (x*x) - x + 7);
	
}

int main()
{
	double a;
	double b;
	double error;
	double c; //Es la raiz
	double errorMinimo;
	int iteracion = 0;
	
	cout << "Ingrese el valor inferior de intervalo (a): " << endl;
	cin >> a;
	cout << "Ingrese el valor superior de intervalo (b): " << endl;
	cin >> b;
	cout << "Ingrese el valor del error esperado (e): " << endl;
	cin >> errorMinimo;
	
	double anterior = a;
	
	if (f(a) * f(b) > 0)
	{
		cout << "No hay raices o hay un numero par de ellas" << endl;
		exit(0);
	}
	
	do
	{
		iteracion++;
		c = (b + a) / 2;
		
		if (f(a) * f(c) > 0)
			a = c;
		else if (f(c) * f(b) > 0)
			b = c;
		else
			break;
		
		error = fabs(c - anterior);
		//error = fabs(b - a);
		anterior = c;
		printf("Iteracion: %d, Error: %.10lf\n", iteracion, error);
		printf("La raiz es: %.10lf\n", c);
		
	} while (error > errorMinimo);
	
	printf("Iteracion: %d, Error: %.10lf\n", iteracion, error);
	printf("La raiz es: %.10lf\n", c);
	
	return 0;
}
