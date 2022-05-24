/*
 FAZIO AURORA 4353010
 POLIZZI LUCREZIA 4935449
 RAFFAGHELLO TOMMASO 4978613
 */ 

/*
 Esercizio 1: Si consideri il numero di matricola del primo componente, in
 ordine alfabetico, del gruppo; 
 si indichi con d0 e d1, rispettivamente,
 l’ultima e la penultima cifra di tale numero di matricola.
 Sapendo che:
 a = (d0 + 1) · 10^i con i = 0, 1,...,6;
 b = (d1 + 1) · 10^20;
 c = −b;
 Eseguire i seguenti calcoli in aritmetica di macchina a doppia
 precisione, cioè utilizzando variabili di tipo double:
 (a+b)+c;
 a+(b+c);
 */ 


#include <iostream> 
#include <cmath>
#include <math.h>
using namespace std;


int main()
{
	double		d0 = 0,	d1 = 1;
	double		a, b, c, op1, op2;
	double		esp = 10;
	double		exp = 10;
	
		
		esp = pow(10, 20);
	//calcolo 10 ^ 20 utilizzando la funzione pow 
		b = (d1 + 1) * (esp);
	//calcolo b 
		c = -b;
	//calcolo c 
		
		cout << " b e' uguale: " << b << "\n" << " c e' uguale: " << c << endl;
	
		for (int i = 0; i <= 6; i++) {
		
			exp = pow(10, i);
		//calcolo di exp per 10 con i da 0 a 6 con pow 
			a = (d0 + 1) * exp;
		//calcolo a 
			cout << "a = " << a << endl << "exp =" << exp << "\n";
		
			
			 /* CALCOLO OPERAZIONI */ 
			op1 = (a + b) + c;
		
			op2 = a + (b + c);
		
			
			cout << "Con i = " << i << "\n" << "Operazione uno: " << op1 << "\n";
		//stampa risultati 
			cout << "Operazione due: " << op2 << "\n";
		
	} 
} 
