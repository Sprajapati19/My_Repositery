#include <iostream>
#include <cmath>
using namespace std;

#define n 4 // Order of Matrix

int RowSize = n;
int ColumnSize = n;

void** GetUpperTriangularMatrix(double**& U, int RowSize, int ColumnSize);
void** GetLowerTriangularMatrix(double** A, double** U, double**& L, int RowSize, int ColumnSize);
void** GetYMatrix(double** I, double** L, double** &Y, int RowSize, int ColumnSize);
void** GetInvMatrix(double** Y, double** U, double** &Ainv, int RowSize, int ColumnSize);

int main()
{
	// Create A Matrix
	double** A = new double* [RowSize];
	for (int i = 1; i <= RowSize; i++)
	{
		A[i - 1] = new double[ColumnSize];
	}

	A[0][0] = 3; A[0][1] = 2; A[0][2] = 1; A[0][3] = 5;
	A[1][0] = 2; A[1][1] = 3; A[1][2] = 2; A[1][3] = 7;
	A[2][0] = 1; A[2][1] = 2; A[2][2] = 2; A[2][3] = 6;
	A[3][0] = 4; A[3][1] = 5; A[3][2] = 6; A[3][3] = 5;

	// Create U Matrix
	double** U = new double* [RowSize];
	for (int i = 1; i <= RowSize; i++)
	{
		U[i - 1] = new double[ColumnSize];
		for (int j = 1; j <= ColumnSize; j++)
		{
			U[i - 1][j - 1] = A[i - 1][j - 1];
		}
	}

	// Create L Matrix
	double** L = new double* [RowSize];
	for (int i = 1; i <= RowSize; i++)
	{
		L[i - 1] = new double[ColumnSize];
		for (int j = 1; j <= ColumnSize; j++)
		{
			L[i - 1][j - 1] = 0;
			if (i == j)
			{
				L[i-1][j-1] = 1;
			}
		}
	}

	// Create I Matrix
	double** I = new double* [RowSize];
	for (int i = 1; i <= RowSize; i++)
	{
		I[i - 1] = new double[ColumnSize];
		for (int j = 1; j <= ColumnSize; j++)
		{
			I[i - 1][j - 1] = 0;
			if (i == j)
			{
				I[i-1][j-1] = 1;
			}
		}
	}

	// Create Ainv Matrix
	double** Ainv = new double* [RowSize];
	for (int i = 1; i <= RowSize; i++)
	{
		Ainv[i - 1] = new double[ColumnSize];
		for (int j = 1; j <= ColumnSize; j++)
		{
			Ainv[i - 1][j - 1] = 0;
		}
	}

	// Create Y Matrix = [U]*[Ainv]
	double** Y = new double* [RowSize];
	for (int i = 1; i <= RowSize; i++)
	{
		Y[i - 1] = new double[ColumnSize];
		for (int j = 1; j <= ColumnSize; j++)
		{
			Y[i - 1][j - 1] = 0;
		}
	}

	// Get Upper Triangular Matrix ([U])
	GetUpperTriangularMatrix(U, RowSize, ColumnSize);

	// Get Lower Triangular Matrix ([L])
	GetLowerTriangularMatrix(A, U, L, RowSize, ColumnSize);

	// Get Y Matrix ([L][Y] = [I])
	GetYMatrix(I, L, Y, RowSize, ColumnSize);

	// Get Inverse of given A Matrix ([U][Ainv] = [Y])
	GetInvMatrix(Y, U, Ainv, RowSize, ColumnSize);

	 //Print A in Output Window
	/*cout << "Matrix A is :"<<endl;
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			cout << " " << A[i-1][j-1] << " ";
		}
		cout << "\n";
	}*/

	// Print U in Output Window
	/*cout << "Upper triangular Matrix is :"<< endl;
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			cout << " " << U[i-1][j-1] << " ";
		}
		cout << "\n";
	}*/

	// Print L in Output Window
	/*cout << "Lower triangular Matrix is :"<< endl;
    for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			cout << " " << L[i - 1][j - 1] << " ";
		}
		cout << "\n";
	}*/

	// Print I in Output Window
	/*for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			cout << " " << I[i - 1][j - 1] << " ";
		}
		cout << "\n";
	}*/

	// Print Y in Output Window
	/*for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			cout << " " << Y[i-1][j-1] << " ";
		}
		cout << "\n";
	}*/

	// Print Ainv in Output Window
	cout << "Inverse Matrix of A is :"<< endl;
	for (int i = 1; i <= RowSize; i++)
	{
		for (int j = 1; j <= ColumnSize; j++)
		{
			cout << " " << Ainv[i-1][j-1] << " ";
		}
		cout << "\n";
	}


	// Cleaning A Matrix
	for (int i = 1; i <= RowSize; i++)
	{
		delete[] A[i - 1];
	}
	delete[] A;
	A = NULL;

	// Cleaning U Matrix
	for (int i = 1; i <= RowSize; i++)
	{
		delete[] U[i - 1];
	}
	delete[] U;
	U = NULL;

	// Cleaning L Matrix
	for (int i = 1; i <= RowSize; i++)
	{
		delete[] L[i - 1];
	}
	delete[] L;
	L = NULL;

	// Cleaning I Matrix
	for (int i = 1; i <= RowSize; i++)
	{
		delete[] I[i - 1];
	}
	delete[] I;
	I = NULL;

	// Cleaning Y Matrix
	for (int i = 1; i <= RowSize; i++)
	{
		delete[] Y[i - 1];
	}
	delete[] Y;
	Y = NULL;

	// Cleaning Ainv Matrix
	for (int i = 1; i <= RowSize; i++)
	{
		delete[] Ainv[i - 1];
	}
	delete[] Ainv;
	Ainv = NULL;
}

//--------------------------------------------------
// Forward-elimination
// Row Operations performed on A Matrix
//--------------------------------------------------
void** GetUpperTriangularMatrix(double** &U, int RowSize, int ColumnSize)
{
	for (int k = 1; k < ColumnSize; k++)
	{
		// Get all zero elements under akk
		for (int i = RowSize; i > k; i--)
		{
			for (int j = ColumnSize; j >= k; j--)
			{
				U[i-1][j-1] = U[i-1][j-1] - ((U[i-1][k-1] / U[k-1][k-1]) * U[k-1][j-1]);
			}
		}
	}

	return 0;
}

//--------------------------------------------------
// Lower Triangular Matrix found using A and U
//--------------------------------------------------
void** GetLowerTriangularMatrix(double** A, double** U, double**& L, int RowSize, int ColumnSize)
{
	for (int i = 1; i < RowSize; i++)
	{
		L[i][0] = A[i][0] / U[0][0];
	}

	for (int i = 2; i < RowSize; i++)
	{
		L[i][1] = (A[i][1] - (L[i][0] * U[0][1])) / U[1][1];
	}

	for (int i = 3; i < RowSize; i++)
	{
		L[i][2] = (A[i][2] - (L[i][1] * U[1][2]) - (L[i][0] * U[0][2])) / U[2][2];
	}

	return 0;
}

//--------------------------------------------------
// Get Y Matrix ([L][Y] = [I])
//--------------------------------------------------
void** GetYMatrix(double** I, double** L, double**& Y, int RowSize, int ColumnSize)
{
	for (int j = 1; j <= ColumnSize; j++)
	{
		Y[0][j-1] = I[0][j-1];
	}

	for (int j = 1; j <= ColumnSize; j++)
	{
		Y[1][j-1] = I[1][j-1] - (L[1][0] * Y[0][j-1]);
	}

	for (int j = 1; j <= ColumnSize; j++)
	{
		Y[2][j-1] = I[2][j-1] - (L[2][0] * Y[0][j-1]) - (L[2][1] * Y[1][j-1]);
	}
	
	for (int j = 1; j <= ColumnSize; j++)
	{
		Y[3][j-1] = I[3][j-1] - (L[3][0] * Y[0][j-1]) - (L[3][1] * Y[1][j-1]) - (L[3][2] * Y[2][j-1]);
	}

	return 0;
}

//--------------------------------------------------
// Get Inverse of given A Matrix ([U][Ainv] = [Y])
//--------------------------------------------------
void** GetInvMatrix(double** Y, double** U, double**& Ainv, int RowSize, int ColumnSize)
{
	for (int j = 1; j <= ColumnSize; j++)
	{
		Ainv[3][j-1] = Y[3][j-1] / U[3][3];
	}

	for (int j = 1; j <= ColumnSize; j++)
	{
		Ainv[2][j-1] = (Y[2][j-1] - (U[2][3] * Ainv[3][j-1]) )/ U[2][2];
	}

	for (int j = 1; j <= ColumnSize; j++)
	{
		Ainv[1][j-1] = (Y[1][j-1] - (U[1][3] * Ainv[3][j-1]) - (U[1][2] * Ainv[2][j-1]) )/ U[1][1];
	}

	for (int j = 1; j <= ColumnSize; j++)
	{
		Ainv[0][j-1] = (Y[0][j-1] - (U[0][3] * Ainv[3][j-1]) - (U[0][2] * Ainv[2][j-1]) - (U[0][1] * Ainv[1][j-1]) )/ U[0][0];
	}

	return 0;
}
