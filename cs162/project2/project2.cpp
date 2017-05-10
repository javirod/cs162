// Project 2: Library Patron App with Structs
// Javier Rodriguez
// 18 April 2017
// Source: None

#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>

using namespace std;

const int ARRAY_SIZE = 200;
const int MAX_STR = 250;

//defines struct Books 	
struct Books
{
	int id;
	char title[MAX_STR];
	char author[MAX_STR];
	int numCopies;
	int numCheckedOut;
	int numHolds;
};

//reads in file, library.txt, from current directory
void readInFile(int& count, struct Books CatalogStruct[])
{
	ifstream infile;
	char c = infile.peek();

	infile.open("library.txt");

	if (!infile)
	{
		// file was not opened
		cout << "Cannot open file library.txt" << endl;
		exit(-1);
	}
	
	//get # of books in file
	infile >> count;
	infile.ignore(MAX_STR, '\n');
	
	//stores each line in corresponding member
	while (!infile.eof() && count <=ARRAY_SIZE && c != '\n')
	{
		//get first field, id
		infile >> CatalogStruct[count].id;
		infile.ignore(MAX_STR, '\n');
		//get next field, title
		infile.getline(CatalogStruct[count].title, MAX_STR);
		//get next field, author
		infile.getline(CatalogStruct[count].author, MAX_STR);
		//get next field, #copies
		infile >> CatalogStruct[count].numCopies;
		infile.ignore(MAX_STR, '\n');
		//get next field, #checkouts
		infile >> CatalogStruct[count].numCheckedOut;
		infile.ignore(MAX_STR, '\n');
		//get next field, #holds
		infile >> CatalogStruct[count].numHolds;
		infile.ignore(MAX_STR, '\n');
		//start next record
		count++;

		c = infile.peek();
	}
	
	//need to close the file so that it can be re-opened again
	infile.close();
}

//writes to file after program finishes running
void writeToFile(int& count, struct Books CatalogStruct[])
{
	ofstream outfile;

	outfile.open("library.txt");

	if(!outfile)
	{
		cout << "Couldn't open library.txt for writing" << endl;
		exit(-1);
	}

	//writes # of books in file
	outfile << count << endl;
	
	for(int i = 0; i < count; i++)
	{
		outfile << CatalogStruct[i].id << endl;
		outfile << CatalogStruct[i].title << endl;
		outfile << CatalogStruct[i].author << endl;
		outfile << CatalogStruct[i].numCopies << endl;
		outfile << CatalogStruct[i].numCheckedOut << endl;
		outfile << CatalogStruct[i].numHolds << endl;
	}

	outfile.close();
}

//prints book information by taking in the index of the array of books
void printBook(int index, struct Books CatalogStruct[])
{
	int i = index;

	cout << "-----  ID: " <<  CatalogStruct[i].id << " -----" << endl;
	cout << "Title: " <<  CatalogStruct[i].title << endl;
	cout << "Author: " <<  CatalogStruct[i].author << endl;
	cout << "Number of Copies: " <<  CatalogStruct[i].numCopies << endl;
	cout << "Number Checked Out: " <<  CatalogStruct[i].numCheckedOut << endl;
	cout << "Number of Holds: " <<  CatalogStruct[i].numHolds << endl;
	cout << "------------------------------" << endl;
}

//prints the entire catalog by passing indexes to the printBook function
void printCatalog(int count, struct Books CatalogStruct[])
{
	cout << "%%%%%%%%%% Book Catalog %%%%%%%%%%\n" << endl;
	for(int i = 3; i < count; i++)
	{
		printBook(i, CatalogStruct);
	}
}

//searches for the title of a book, if it's not found then the user is notified
void searchByTitle(int count, struct Books CatalogStruct[])
{
	char bookTitle[MAX_STR];
	bool found = 0;

	cout << "Please enter title of book: " << endl;
	cin.getline(bookTitle, MAX_STR);
	
	for (int i = 0; i < count; i++)
	{
		if (!strcmp(bookTitle, CatalogStruct[i].title))
		{
			printBook(i, CatalogStruct);
			found = 1;
		}
	}

	if(found == 0)
	{	
		cout << "No books in the Catalog with that title." << endl;
	}
}
//searches for the author of a book, if noene are found the user is notified
void searchByAuthor(int count, struct Books CatalogStruct[])
{
	char bookAuthor[MAX_STR];
	bool found = 0;

	cout << "Please enter author of book: " << endl;
	cin.getline(bookAuthor, MAX_STR);
	
	for (int i = 0; i < count; i++)
	{
		if (!strcmp(bookAuthor, CatalogStruct[i].author))
		{
			printBook(i, CatalogStruct);
			found = 1;
		}
	}

	if(found == 0)
	{	
		cout << "No books in the Catalog from that author." << endl;
	}
}

//provides the possible selections and takes in as input a response from the user
int menuSelection()
{
	int response;

	cout << "********** MAIN MENU**********\n"
	<< "1 - Print Catalog\n"
	<< "2 - Search by Title\n"
	<< "3 - Search by Author\n"
	<< "4 - Do Action\n"
	<< "5 - QUIT\n"
	<< "Enter choice:\n";

	cin >> response;
	cin.ignore(MAX_STR, '\n');
	
	return response;

}

//a book is searched by its ID and returns where in the array it is located, the index
int searchBookByID(int ID, int count, struct Books CatalogStruct[])
{
	for (int i = 0; i < count; i++)
	{
		if (ID == CatalogStruct[i].id)
		{
			return i;
		}
	}
}

//incrememnts the holds memeber by 1
void putHold(int index, struct Books CatalogStruct[])
{
	CatalogStruct[index].numHolds++;
	cout << "Hold on book was successful." << endl;
}

//if all of the copies of a book aren't checked out then the user is able to check out
//the book, other wise the user is asked if they would like to place a hold
void checkoutBook(int index, struct Books CatalogStruct[])
{
	char resp;

	if(CatalogStruct[index].numCheckedOut == CatalogStruct[index].numCopies)
	{
		cout << "There are no copies to checkout." << endl;
		cout << "Would you like to put a hold on this book?(y or n)";
		cin >> resp;
		cin.ignore(MAX_STR, '\n');

		if(resp == 'y' || resp == 'Y')
		{
			putHold(index, CatalogStruct);
		}

	}
	else
	{
		CatalogStruct[index].numCheckedOut++;
		cout << "Check out successful." << endl;
	}
}

//if a copy is checked out, the user is able to return a book back
void returnBook(int index, struct Books CatalogStruct[])
{
	if (CatalogStruct[index].numCheckedOut == 0)
	{
		cout << "No copies were checked out." << endl;
	}
	else
	{
		CatalogStruct[index].numCheckedOut--;
		cout << "Book return successful." << endl;
	}
}

//if there are holds on a book, then the user is able to remove a hold
void removeHold(int index, struct Books CatalogStruct[])
{
	if(CatalogStruct[index].numHolds == 0)
	{
		cout << "No Holds on this book." << endl;
	}
	else
	{
		CatalogStruct[index].numHolds--;
		cout << "Remove Hold on book successful." << endl;
	}

}
//determines what function will be run to manage the number of copies available as
//well as holds for each book in the catalog
void doAction(int count, struct Books CatalogStruct[])
{
	int idBook, index, responseAction;

	cout << "Enter ID of book: (or enter -1 to see a list of books): " << endl;
	cin >> idBook;
	cin.ignore(MAX_STR, '\n');
	if(idBook == -1){
		printCatalog(count, CatalogStruct);
		cout << "Enter ID of Book: ";
		cin >> idBook;
		cin.ignore(MAX_STR, '\n');
	}
		
	index = searchBookByID(idBook, count, CatalogStruct);

	cout << "What would you like to do?\n"	<< "1 - checkout book\n" << "2 - return book\n" << "3 - hold book\n" << "4 - remove hold\n" << "Enter choice:\n";

	cin >> responseAction;

	if(responseAction == 1)
		checkoutBook(index, CatalogStruct);
	else if(responseAction == 2)
		returnBook(index, CatalogStruct);
	else if(responseAction == 3)
		putHold(index, CatalogStruct);
	else if(responseAction == 4)
		removeHold(index, CatalogStruct);
	
	printBook(index, CatalogStruct);

}

//main function drives the initial menu
//the user is asked to perform searches of books or actions on books.
int main()
{
	int count = 0;
	int decision = 0;

	Books Catalog[ARRAY_SIZE];

	readInFile(count, Catalog);


	while(decision != 5)
	{
		decision = menuSelection();
		
		if (decision == 1)
			printCatalog(count, Catalog);
		else if (decision == 2)
			searchByTitle(count, Catalog);
		else if (decision == 3)
			searchByAuthor(count, Catalog);
		else if (decision == 4)
			doAction(count, Catalog);
	}

	
	writeToFile(count, Catalog);
	cout << "*** \n\nTHANK YOU FOR USING OUR LIBRARY ***\n\n";
	return 0;
}
