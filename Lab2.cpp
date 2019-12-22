// 1.Implement the algorithm for solving congruences.

#include <iostream>
#include <string>

using namespace std;

// C function for extended Euclidean Algorithm 
int gcdExtended(int a, int b, int* x, int* y)
{
	// Base Case  
	if (a == 0)
	{
		*x = 0;
		*y = 1;
		return b;
	}

	int x1, y1; // To store results of recursive call  
	int gcd = gcdExtended(b % a, a, &x1, &y1);

	// Update x and y using results of  
	// recursive call  
	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}

// Function to find modulo inverse of a 
int modInverse(int a, int m)
{
	int x, y;

	//calculating gcd with the Extended Euclidean algorithm
	int g = gcdExtended(a, m, &x, &y);

	if (g != 1)
		cout << "Inverse doesn't exist";
	else
	{
		// m is added to handle negative x 
		int res = (x % m + m) % m;
		return res;
	}
}

int main()
{
	cout << "Enter the congruence you wish to solve(format:ax = b (mod m)):\n";
	int a = -1, b = -1, m = -1;
	cout << "a=";
	cin >> a;
	cout << "b=";
	cin >> b;
	cout << "m=";
	cin >> m;
	while (a*b*m < 0){
		cout << "Numbers have to be >0\n";
		cout << "a=";
		cin >> a;
		cout << "b=";
		cin >> b;
		cout << "m=";
		cin >> m;
	}
	int x, y;
	int d = gcdExtended(a, m, &x, &y);
	cout << "GCD(" << a << ", " << m
		<< ") = " << d<< endl;

   // if b%d != 0 there are no solutions
	if (b % d != 0) {
		cout << "There are no solutions";
	}
	else {

		//if there are solutions, then a, b and m are divided by d
		a = a / d;
		b = b / d;
		m = m / d;
	
		cout << "The equation has the same solutions as:";
		cout << a << "x" << "=" << b << "(mod " << m << ")\n";

		cout << "The general solution is x = "<<a<<"^(-1)"<<b<<"(mod "<<m<<")\n";

		//calculating the inverse
		int inv = modInverse(a, m);
		cout << "The general solution is x = " << ((inv*b)%m) << "(mod " << m << ")";

	}
	return 0;
}
