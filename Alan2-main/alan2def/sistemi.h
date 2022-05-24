#include <iostream>
#include <cmath>
#include<iomanip>
#include <cstdlib>

using namespace std;

/* Funzione fattoriale */
float fatt(double i) {
	if (i == 0) 
        return 1;
  	else   
        return i*fatt(i-1);}

/* Funzione calcolo norma infinita */
float norma_inf(float *matrix[], int n) {
	float norma = 0;
	float tmp = 0;
	for (unsigned int i=0; i<n; i++){
		for (unsigned int j=0; j<n; j++){
			tmp += fabs(matrix[i][j]);
		}
		if (tmp > norma){ norma = tmp;}
		tmp=0; //reset
	}
	return norma;
}

float norma_inf_vect(float *x, int dim){
	float norma = 0;
	float tmp = 0;
	for (unsigned int i=0; i<dim; i++){
		tmp = fabs(x[i]);
		if (tmp>norma){
			norma = tmp;
		}
	}
	return norma;
}


/* Print matrix */
void stampa_matrice(float *matrix[], int n, int m){
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		cout<<setw(8)<<setprecision(4)<<matrix[i][j];
		cout<<endl;
	}
}

/* Stampa del vettore x */
void stampa_vettore(float x[], int dim)
{ 
 for (int i=0; i<dim; i++)
  {
	cout << x[i] << "\n"; 
  }
}

/* Funzione che moltiplica la matrix per il vettore composto da tutti '1' */
// attenzione: funziona solo con matrici quadrate
// ritorna il vettore calcolato
float* trova_b(float *matrix[], int dim){
	float *b = new float[dim];
	float elem = 0;
	for (unsigned int i=0; i<dim; i++){
		for (unsigned int j=0; j<dim; j++){
			elem += matrix[i][j];
		}
		b[i] = elem;
		elem = 0;
	}
	return b;
}

/* Perturba il vettore */
float* perturba_b(float *x, int dim){
	float *b_perturbato = x;
	float n_inf = norma_inf_vect(x, dim);

	for (unsigned int i=0; i<dim; i++){
		b_perturbato[i] += (n_inf * (i%2==0 ? -0.01 : 0.01));
	}
	return b_perturbato;
}

/* Eliminazione gaussiana */
float* gauss_plus(float** matrix, float* x, int dim){
	float* sol = new float[dim]; // vettore delle soluzioni

	float mat[dim][dim+1]; // matrix composta dalla matrix originale e vettore dei termini noti
	for (int i=0; i<dim; i++){
		for (int j=0; j<dim+1; j++){
			j<dim ? mat[i][j] = matrix[i][j] : mat[i][j] = x[i];
		}
	}

	for (int i=0; i<dim-1; i++){
		for (int j=i+1; j<dim; j++){
			float f=mat[j][i]/mat[i][i];
			for (int k=0; k<dim+1; k++){
				mat[j][k] = mat[j][k]-f*mat[i][k];
			}
		}
	}
	// scorrimento indietro per trovare la soluzione
	for (int i=dim-1; i>=0; i--){
		sol[i]=mat[i][dim];
		for (int j=i+1; j<dim ;j++){
			if (i!=j){
				sol[i]=sol[i]-mat[i][j]*sol[j];
			}
		}
		sol[i]=sol[i]/mat[i][i];
	}

	
	return sol;
}