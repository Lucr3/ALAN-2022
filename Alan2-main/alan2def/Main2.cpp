/*ALAN Laboratorio 2, Gruppo:
Fazio Aurora 4353010
Polizzi Lucrezia 4935449
Raffaghello Tommaso 4978613*/

#include <iostream>
#include "sistemi.h"
using namespace std;

int main(){

	/* Creazione matrici */
	// Matrice a:
	float tmp1[4][4] = {{3, 1, -1, 0}, {0, 7, -3, 0}, {0, -3, 9, -2}, {0, 0, 4, -10}};
	const int na = 4;
	float** matrice_a = new float*[na];
	for (int i=0; i<na; i++){
		matrice_a[i] = new float[na];
		for (int j=0; j<na; j++){
			matrice_a[i][j] = tmp1[i][j];
		}
	}

	// Matrice b:
	float tmp2[4][4] = {{2, 4, -2, 0}, {1, 3, 0, 1}, {3, -1, 1, 2}, {0, -1, 2, 1}};
	const int nb = 4;
	float** matrice_b = new float*[nb];
	for (int i=0; i<nb; i++){
		matrice_b[i] = new float[nb];
		for (int j=0; j<nb; j++){
			matrice_b[i][j] = tmp2[i][j];
		}
	}

	// Matrice p:
	const int np = 10;
	float** matrice_p = new float*[np];
	for (int i=0; i<np; i++){
		matrice_p[i] = new float[np];
		for (int j=0; j<np; j++){
			(i==0 || j==0) ? matrice_p[i][j]=1 : matrice_p[i][j] = (matrice_p[i][j-1] + matrice_p[i-1][j]);
		}
	}

	// matricola su cui si svolge il laboratorio: 4978613
	// Matrice t:
	const int d0 = 3; // ultima cifra matricola
	const int d1 = 1; // penultima cifra matricola
	const int nt = 10 * (d1 + 1) + d0;
	float** matrice_t = new float*[nt];
	for (int i=0; i<nt; i++){
		matrice_t[i] = new float[nt];
		for (int j=0;j<nt;j++){
			if (i==j) matrice_t[i][j]=2;
			else if (fabs(i-j)==1) matrice_t[i][j]=-1;
			else matrice_t[i][j]=0;
		}
	}

	//es1
	/* Calcolo norma infinito */
cout<<"\n----------------------------ESERCIZIO 1----------------------------\n";	
	cout << "La norma infinito della matrice a è: " << norma_inf(matrice_a, na) << endl;
	cout << "La norma infinito della matrice b è:" << norma_inf(matrice_b, nb) << endl;
	cout << "La norma infinito della matrice p è:	" << norma_inf(matrice_p, np) << endl;
	cout << "La norma infinito della matrice tridiagonale è: " << norma_inf(matrice_t, nt) << endl;


	//es 2 

 cout<<"\n----------------------------ESERCIZIO 2----------------------------\n";
	/* Matrice a */
	float *ba = trova_b(matrice_a, na);
	cout << "Il vettore dei termini noti per a: \n";
	stampa_vettore(ba, na);

	float *xa = gauss_plus(matrice_a, ba, na);
	cout << "Il vettore soluzioni per a: \n";
	stampa_vettore(xa, na);
	
	
	/* Matrice b */
	float *bb = trova_b(matrice_b, nb);
	cout << "\n Il vettore dei termini noti per b: \n"; 
	stampa_vettore(bb, nb);

	float *xb = gauss_plus(matrice_b, bb, nb);
	cout << "Vettore soluzioni per b:  \n";
	stampa_vettore(xb, nb);

	/* Matrice P */
	float *bp = trova_b(matrice_p, np);
	cout << "\nIl vettore dei termini noti per la matrice di Pascal: \n"; 
	stampa_vettore(bp, np);

	float *xp = gauss_plus(matrice_p, bp, np);
	cout << "Il vettore soluzioni per P:  \n";
	stampa_vettore(xp, np);

	/* Matrice T */
	float *bt = trova_b(matrice_t, nt);
	cout << "\n Il vettore dei termini noti per la matrice tridiagonale: \n"; 
	stampa_vettore(bt, nt);

	float *xt = gauss_plus(matrice_t, bt, nt);
	cout << "Il vettore soluzioni per T:  \n";
	stampa_vettore(xt, nt);


	//es 3 
cout<<"\n----------------------------ESERCIZIO 3----------------------------\n";
	/* Matrice a */
	float *b_pert_a = perturba_b(ba, na);
	cout << "Vettore dei termini noti per a: \n";
	stampa_vettore(b_pert_a, na);

	xa = gauss_plus(matrice_a, b_pert_a, na);
	cout << "Vettore soluzioni per a:  \n";
	stampa_vettore(xa, na);
	
	
	/* Matrice b */
	float *b_pert_b = perturba_b(bb, nb);
	cout << "\nVettore dei termini noti per b: \n"; 
	stampa_vettore(b_pert_b, nb);

	xb = gauss_plus(matrice_b, b_pert_b, nb);
	cout << "Vettore soluzioni per b:  \n";
	stampa_vettore(xb, nb);

	/* Matrice P */
	float *b_pert_p = perturba_b(bp, np);
	cout << "\nVettore dei termini noti per matr. di Pascal:\n"; 
	stampa_vettore(b_pert_p, np);

	xp = gauss_plus(matrice_p, b_pert_p, np);
	cout << "Vettore soluzioni per P:\n";
	stampa_vettore(xp, np);

	/* Matrice T */
	float *b_pert_t = perturba_b(bt, nt);
	cout << "\nVettore dei termini noti per matr. tridiagonale:\n"; 
	stampa_vettore(b_pert_t, nt);

	xt = gauss_plus(matrice_t, b_pert_t, nt);
	cout << "Vettore soluzioni per T: \n";
	stampa_vettore(xt, nt);

	return 0;
}
