#include <iostream>
using namespace std;

void u(int n)
{
	double u[n];
	// initial conditions are
	u[0] = 2.9689;
	u[1] = 2.9689;
	
	for (int i=0; i<=n; i++){
		u[i+2] = 3*u[i+1] - 2*u[i];
	}
	cout << u[n];
}

void a(int n)
{
	double a[n];
	// initial conditions are
	a[0] = 2.96875;
	a[1] = 2.96875;
	
	for (int i=0; i<=n; i++){
		a[i+2] = 3*a[i+1] - 2*a[i];
	}
	cout << a[n];
}

int main ()
{
    
    int k;
    cout << "[given relation is : u(n+2) = 3u(n+1) - 2u(n)]\nall iterated values from u(2)) to u(64)\n\n";
    cout << "    u[n]      (b) when u(0) = u(1) = 2.9689      (c) when u(0) = u(1) = 2.96875\n\n";
    
    for (k=2; k<=64; k++){
cout << "    u[" << k << "]  =              ";
u(k);
cout << ",                       ";
a(k); 
cout << endl;
}
    return 0;
}
