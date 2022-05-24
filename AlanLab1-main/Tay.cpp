/*
 Algoritmo 1: determinare un’approssimazione di f(x) per il punto x = 0.5 ed il punto x = 30,
 valutando fN (x) per N = 3, 10, 50, 100, 150.
 * Ripetere l’esercizio considerando il punto x = −0.5 ed il punto x = −30. 
 
 Algoritmo 2: Osservando che per l’esponenziale vale f(−x) = 1/f(x) e quindi f(−x) ≈ 1/fN (x), 
 determinare una diversa approssimazione di f(−0.5) e f(−30) nel modo seguente: valutare fN (+0.5)
 e fN (+30) per N = 3, 10, 50, 100, 150 e, successivamente, calcolarne il reciproco.
 */ 

#include <iostream> 
#include <cmath>
#include <math.h>
using namespace std;


double fattoriale(int c)
{
	//fattoriale per la funzione taylor 
	int		fatt = 1;
	
		for (int i = 1; i <= c; i++) {
		
			fatt *= i;
		
	} 
		return fatt;
	
} 

double taylor(double x, int n)
{
	//calcolo funzione di taylor per e ^ x 
	double app, somma, val = 0;
	
		for (int i = 1; i <= n; i++) {
		
			somma = ((pow(x, i)) / fattoriale(i));
		
			val = val + somma;
		
	} 
		app = 1 + val;
	
		return app;
	
} 

double 
reciproco(double f)
{
	
	double rec = 1 / f;
	
		return rec;
	
} 

int main()
{
	
	int		N = 0;
	//dato in input 
		double x;
	//dato in input 
		double	risTy, rec;
	
		char	aux;
	//serve per SI oppure NO 
		
		do {
		
			cout << "Inserisci il valore di x:\t ";
		
			cin >> x;
		
			
			for (int i = 0; i <= 4; i++) {
			//algortimo 1 dove calcoliamo fN(x) inserendo x solo una volta ed N ad ogni ciclo 
					cout <<	"Inserisci il valore di N:\t ";
			
				cin >> N;
			
				risTy = taylor(x, N);
			
				cout << "Il risultato e': " << risTy << endl;
			
				
				rec = reciproco(risTy);
			//algoritmo 2 che mi calcola 1 / fN(x) ogni volta che ottiene il risultato da risTy 
					cout <<	"il reciproco della funzione e': " << rec << endl;
			
		} 
			cout << "Vuoi eseguire un altro calcolo per un x diverso? (S/N)\t";
		//se vogliamo cambiare x possiamo continuare e ripartire da capo 
			cin >> aux;
		
			
	} while (aux == 'S' || aux == 's');
	
} 
