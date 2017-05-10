// Lab 3: Bookstore Sale
// Javier Rodriguez
// 28 April 2017
// Source: None

#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
#include <iomanip>

using namespace std;

const int ARRAY_SIZE = 100;
const int MAX_STR = 250;

//defines struct Books 	
struct Book
{
	char title[MAX_STR];
	char author[MAX_STR];
	double price;
};

//reads in file, library.txt, from current directory
void readInFile(int& count, struct Book CatalogStruct[])
{
	ifstream infile;
	char c = infile.peek();

	infile.open("books.txt");

	if (!infile)
	{
		// file was not opened
		cout << "Cannot open file books.txt" << endl;
		exit(-1);
	}
	
	//stores each line in corresponding member
	while (!infile.eof() && c != '\n')
	{
		//get first field, title
		infile.getline(CatalogStruct[count].title, MAX_STR);
		//get next field, author
		infile.getline(CatalogStruct[count].author, MAX_STR);
		//get next field, price
		infile >> CatalogStruct[count].price;
		infile.ignore(MAX_STR, '\n');

		//start next record
		count++;

		c = infile.peek();
	}
	
	//need to close the file so that it can be re-opened again
	infile.close();
}

//writes to file after program finishes running
void writeToFile(int& count, struct Book CatalogStruct[])
{
	ofstream outfile;
	outfile.open("sale.txt");
	
	outfile << fixed <<  setprecision(2);

	if(!outfile)
	{
		cout << "Couldn't open sale.txt for writing" << endl;
		exit(-1);
	}

	for(int i = 0; i < count; i++)
	{
		outfile << CatalogStruct[i].title << endl;
		outfile << CatalogStruct[i].author << endl;
		outfile << CatalogStruct[i].price << endl;
	}

	outfile.close();
}

//prints book information by taking in the index of the array of books
void printBook(int index, struct Book CatalogStruct[])
{
	int i = index;

	cout <<  CatalogStruct[i].title << endl;
	cout << "Author: " <<  CatalogStruct[i].author << endl;
	cout << "Price: " <<  CatalogStruct[i].price << endl;
	cout << "------------------------------" << endl;
}

//prints the entire catalog by passing indexes to the printBook function
void printCatalog(int count, struct Book CatalogStruct[])
{
	cout << "\n";
	for(int i = 0; i < count; i++)
	{
		printBook(i, CatalogStruct);
	}
	cout << "\nTotal number of books: " << count << "\n\n";
}

//searches for the title of a book, if it's not found then the user is notified
void priceReduction(int count, struct Book CatalogStruct[])
{
	double discount = 0.8;

	cout << "Reducing prices...\n" << endl;
	cout << fixed << setprecision(2);
	
	for (int i = 0; i < count; i++)
	{
		CatalogStruct[i].price = CatalogStruct[i].price * discount;
		cout << CatalogStruct[i].title << " is now " << CatalogStruct[i].price << endl;
	}

}

//main function drives the initial menu
//the user is asked to perform searches of books or actions on books.
int main()
{
	int count = 0;
	int decision = 0;
	
	cout << fixed << setprecision(2);
	Book Catalog[ARRAY_SIZE];

	readInFile(count, Catalog);
	printCatalog(count, Catalog);

	priceReduction(count, Catalog);
	writeToFile(count, Catalog);

	cout << "*** Prices have been written to sale.txt ***\n\n";
	return 0;
}
