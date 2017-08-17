/*
  Name: ProcessCharacters
  Copyright: 
  Author: Professor Langsam
  Date: 18/03/06 21:11
  Description: Process characters as follows:
               1.  Read characters from the input stream until EOF is encountered.
               2.  Change any lowercase letter to an uppercase letter.
               3.  Print three words to a line with a single space between each word.
               4.  Count the number of characters and the number of letters printed.
*/
#include <cstdlib>
#include <fstream>                      //include library for file processing
#include <cctype>
#include <iostream>

using namespace std;

ifstream infile;                        //declare the input file

int main(int argc, char *argv[])
{
    char c;
    int  numberCharacters = 0, numberLetters = 0;
    int process(char &, int &, int &);
    
    infile.open("OriginalFile.txt");    //open the file
    if ( !infile.is_open() ) {          //check to see if file was opened
       // The file could not be opened
       cout << endl << "ERROR: Unable to open file" << endl;
       system ("PAUSE");
       exit(1);
    }
   
    while (!infile.eof()){
          c = infile.get();
          if (process(c, numberCharacters, numberLetters) == true)
             cout << c;
    }      
    
    cout << endl 
         << "Number of characters: " << numberCharacters << endl 
         << "Number of letters:" << numberLetters << endl;
    
      
    infile.close();                      //close the file
    system("PAUSE");
    return EXIT_SUCCESS;
} // end main



bool process(char &c, int &numberCharacters, int &numberLetters)
{
    static int count = 0, lastChar = ' ';
    const int NUMBEROFWORDSPERLINE = 3;
    
    if (isspace(lastChar) && isspace(c))
       return false;
    if (isalpha(c)){
       ++numberLetters;
       if (islower(c))
          c = toupper(c);
    }
    else if (isspace(c))
         if (++count % NUMBEROFWORDSPERLINE == 0)
            c = '\n';
         else
             c = ' ';
    ++numberCharacters;
    lastChar = c;
    return true;
} //end process
                      
