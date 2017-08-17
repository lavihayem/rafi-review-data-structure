/*                                             
  Name: CountWords
  Copyright:
  Author: Professor Langsam
  Date: 17/03/06 15:37
  Description: Counts the words in a file by looking for
               white space between words
*/
#include <cstdlib>                      
#include <iostream>
#include <fstream>                      //include library for file processing
#include <cctype>

using namespace std;

ifstream infile;                        //declare the input file

int main(int argc, char *argv[])        
{
    infile.open("OriginalFile.txt");    //open the file
                                        
    if ( !infile.is_open() ) {          //check to see if file was opened
       // The file could not be opened
       cout << endl << "ERROR: Unable to open file" << endl;
       system ("PAUSE");
       exit(1);
    }

    int wordCount = 0;
    bool foundNextWord(void);

    while (foundNextWord())
        ++wordCount;

    cout << "Number of words in the file = " << wordCount << endl << endl;

    infile.close();                      //close the file
    system("PAUSE");
    return EXIT_SUCCESS;
} //end main




//Finds a word by skiping (leading) white space and then skipping 
//non-white space.
bool foundNextWord(void)
{
    int c;

    while (!infile.eof() && isspace(c = infile.get()) ) 
          // skip white space
        ;

    if (!infile.eof()) {                // found a word          
       while (!infile.eof() && !isspace(c = infile.get()))
             ;                          // skip everything except EOF
                                        // and white space
       return true;
    } // end if

    return false;
} // end foundNextWord
