/*
  Name: ElectionYear
  Copyright: 
  Author: 
  Date: 18/03/06 21:52
  Description: Program determines how close an election year is.
*/
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int year;

	cout << "\nWhat year is this? ";
	cin >> year;
	switch (year % 4) {
		case 0:		cout << endl << "This is an election year." << endl;
						break;
		case 1:		cout << endl << "Last year was an election year." << endl;
						break;
		case 2:		cout << endl << "The election was two years ago." << endl;
						break;
		case 3:		cout << endl << "Next year will be an election year." << endl;
	} /* end switch */  
  
    system("PAUSE");
    return EXIT_SUCCESS;
}
