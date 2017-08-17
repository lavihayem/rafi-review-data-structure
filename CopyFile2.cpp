/*
  Name: copyFile 2
  Copyright: 
  Author: Professor Langsam
  Date: 10/07/06 12:33
  Description: copyFile 2 uses character processing to copy a file.
*/
#include <cstdlib>
#include <iostream>
#include <fstream>                   //include library for file processing

using namespace std;

int main(int argc, char *argv[])
{
    int c;
    
    ifstream infile("OriginalFile.txt");
    ofstream outfile("CopiedFile.txt");
    
    if ( !infile.is_open() ) {       //Method: checks to see if file was opened
       // The file could not be opened
       cout << endl << "ERROR: Unable to open input file" << endl;
       system ("PAUSE");
       exit(1);
    }
    
    if ( !outfile.is_open() ) {       //Method: checks to see if file was opened
       // The file could not be opened
       cout << endl << "ERROR: Unable to open output file" << endl;
       system ("PAUSE");
       exit(1);
    }
    
        
    /* Read one character at a time, checking for the End of File. */
    while (!infile.eof()){
        c = infile.get();
        outfile.put(c);
    }
    
        
    infile.close();                  //close the input file
    outfile.close();                 //close the output file
    system("PAUSE");
    return EXIT_SUCCESS;
}
