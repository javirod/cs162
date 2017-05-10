#include <iostream>

using namespace std;

void main()
{
	char x[200] = {0, 1, 2, 3};
	char y[200] = {6, 7, 8, 9};
	char n[200];
	cout << "x: " << x << "\ny: " << y << endl;

	n  = x;
	
	cout << "x: " << x << "\ny: " << y << endl;


}
