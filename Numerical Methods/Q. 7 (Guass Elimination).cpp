#include<iostream>
#include<cmath>

using namespace std;
void** ForwardElimination(double** A, double** B, double** A_u_t, double** B_new){
	int i, j, k;
	double c, d;
	
	for (k=1; k<=4; k++){
		for (i=k; i<5; i++){
			c = A[i][k-1];
			d = A[k-1][k-1];
			B[i][0] = B[i][0] - (c/d)*B[k-1][0];
			for (j=(k-1); j<5; j++){
				A[i][j] = A[i][j] - (c/d)*A[k-1][j];
			}
			
		}
	}
	/*The upper triangular matrix obtained after Forward Elimination and new b vector stored to A_u_t and B_new respectively so that they will 
	be available outside of this function for inputing it in to BackwardSubstitution function*/ 
	
	for(i = 0; i<5; i++){
		B_new[i][0] = B[i][0];
		for (j = 0; j<5; j++){
			A_u_t[i][j] = A[i][j];
		}
	}
	cout << "The upper triangular matrix obtained after Forward Elimination is shown below:" << "\n";
	for(i = 0; i<5; i++){
		for (j = 0; j<5; j++){
		cout << A_u_t[i][j] << "\t";
	}
	cout << "\n";
}
cout << "\n";
cout <<"After performing Forward Elimination b vector changed as:" << "\n";
	for(i = 0; i<5; i++){
		cout << B_new[i][0] << "\n";
	}


}
void** BackwardSubstitution(double** A_ut, double** B_n){

	int i, j;
	double c;
	double** X = new double* [5];
	for(i=0; i<5; i++){
		X[i] = new double [1];
	}
	X[4][0] = B_n[4][0]/A_ut[4][4];      // calculating the last term of X vector
	for(i=3; i>=0; i--){
		c = B_n[i][0];
		for(j=4; j>i; j--){
			c = c - A_ut[i][j]*X[j][0];
			
		}
	X[i][0] = c/A_ut[i][i];
	}
	cout << "After performing Forward Elimination and Backward Substitution the x vector we obtained as:"<< "\n";
	for(i = 0; i<5; i++){
		cout << X[i][0] << "\n";
	}
	
}

int main(){
	int i, j, k;
	double** A = new double* [5];
	double** B = new double* [5];
	double** A_upper_triangular = new double* [5];
	double** B_new = new double* [5];
	for (i=0; i<5; i++){
		A[i] = new double [5];
		B[i] = new double [1];
		A_upper_triangular[i] = new double [5];
		B_new[i] = new double [1];
		
	}
	
	// The matrix on which Guass Elimination method is to be performed and the b vector is defined as:
	
	cout << "The matrix on which Guass Elimination method is to be performed:" << "\n";
	
	for (i=0; i<5; i++){
		B[i][0] = 1;
		for (j=0; j<5; j++){
			A[i][j] = pow((i+1), (j+1));
		}
	}
	
	for(i = 0; i<5; i++){
		for (j = 0; j<5; j++){
		cout <<  A[i][j] << "\t";
	}
	
	cout << "\n";
   }
	cout << "\n";
	cout << "The b vector is given as:" << "\n";
	
	for(i = 0; i<5; i++){
		cout << B[i][0] << "\n";
	}
	
	cout << "\n";

ForwardElimination(A, B, A_upper_triangular, B_new);

BackwardSubstitution(A_upper_triangular, B_new);

return 0;
}
