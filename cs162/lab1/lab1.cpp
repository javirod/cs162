// Lab 1: Your Weight on Another Planet
// Javier Rodriguez
// 13 April 17
// Sources: None

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	double wtPlanet;
	double wtEarth;
	double gPlanet;
	double gEarth = 9.81;
	double gMoon = 1.622;
	double gMars = 3.71;
	double gNeptune = 11.15;
	double gJupiter = 24.79;
	char response = 'y';
	int planSelect;

	cout << "\n\n====================\n";
	cout << fixed << showpoint;
	cout << setprecision(2);
	
	//checks reponse of user, initialized to yes
	while (response == 'y' || response == 'Y')
	{
		//asks user to enter weight
		cout << "Please enter your weight on Earth: " << endl;
		cin >> wtEarth;
		cout << "\n";

		//checks for valid weight if invalid weight is entered
		while (wtEarth <= 0)
		{
			cout << "Invalid weight. Please re-enter." << endl;
			cin >> wtEarth;
			cout << "\n";
		}

		//prompts user to choose planet
		cout << "Choose a Planet:\n" << "1 - Moon\n2 - Mars\n3 - Neptune\n4 - Jupiter\n";
		cin >> planSelect;
		cout << "\n";

		//checks for valid selection
		while (planSelect < 1 || planSelect > 4)
		{
			cout << "Invalid Selection. Please re-enter." << endl;
			cin >> planSelect;
			cout << "\n";
		}
		//assigns g value of selected planet to be calculated in equation below
		if (planSelect == 1)
		{
			gPlanet = gMoon;
		}

		else if (planSelect ==2)
		{
			gPlanet = gMars;
		}

		else if (planSelect == 3)
		{
			gPlanet = gNeptune;
		}

		else if (planSelect == 4)
		{
			gPlanet = gJupiter;
		}
		
		//equation to find weight on selected planet
		wtPlanet = wtEarth * (gPlanet / gEarth);

		cout << "Your weight will be: " << wtPlanet << endl << endl;
		cout << "Would you like to continue (y or n)" << endl;
		cin >> response;
		cout << "\n\n";
	}


}
