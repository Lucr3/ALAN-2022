/*
 * ESERCIZIO 3: Implementare un programma che determina la precisione di
 * macchina eps, ossia il valore positivo 
 eps =2^(−d), dove d è il più grande intero positivo tale che 1 + 2^(−d) > 1 in aritmetica di macchina;
  calcolarne il valore sia in singola che in doppia precisione.
 */ 

#include <iostream> 
#include <cmath>
#include <math.h>
#include <climits>     //serve per d così da usare INT_MAX ovvero 2147483647
using namespace std;

 /* FUNZIONE PRECISIONE SINGOLA */ 
float singolaP()
{
	int		d = INT_MAX;
	
		float		eps = d / 2.0;
	
		cout << "\nfloat eps vale: \t" << eps << endl;
	
		
		while ((1.0 + eps) > 1.0) {
		
			eps = eps / 2.0;
		
	} 
		return eps * 2.0;
	
} 
 /* FUNZIONE PRECISIONE DOPPIA */ 
double doppiaP()
{
	int		d = INT_MAX;
	
		double		eps = d / 2.0;
	
		cout << "double eps vale: \t" << eps << endl;
	
		
		while ((1.0 + eps) > 1.0) {
		
			eps = eps / 2.0;
		
	} 
		return eps * 2.0;
	
} 

int main()
{
	
	
	float		sp = singolaP();
	//chiamo le funzioni e salvo il risultato 
		float		dp = doppiaP();
	
		
		cout << "\nSingola Precisione: \t" << sp << endl;
	//stampa 
		cout << "Doppia Precisione: \t" << dp << endl;
	
} 
