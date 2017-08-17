/*
  Name: Censor
  Copyright: 
  Author: Professor Langsam
  Date: 02/04/06 14:54
  Description: Censors four-letter words
*/
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
    string word;

	cout << "\nEnter words. Enter ^Z to stop." << endl;
	while (!cin.eof() && cin >> word)
		if (word.length() == 4)
			cout << "censored! ";
		else
			cout << word << " ";
            
    system("PAUSE");
    return EXIT_SUCCESS;
}
