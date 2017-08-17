/*
  Name: Sales
  Copyright: 
  Author: Professor Langsam
  Date: 02/04/06 15:00
  Description: Calculates the percent of wholesale and retail sales in the file
*/
#include <cstdlib>
#include <iostream>
#include <fstream>                    //include library for file processing
#include <string>
#include <cctype>

using namespace std;

int main(int argc, char *argv[])
{
    float sale, wholesale = 0, total = 0, percent;
	string type;
	string strUpr(string);
	
    ifstream infile;                 //create the file infile for input
    infile.open("sales.txt");        //open the file
    
    if ( !infile.is_open() ) {       //checks to see if file was opened
       // The file could not be opened
       cout << endl << "ERROR: Unable to open file" << endl;
       system ("PAUSE");
       exit(1);
    }

    while (!infile.eof() && infile >> type >> sale){ 
        if (strUpr(type) == "WHOLESALE")
			wholesale += sale;
		total += sale;
    } /* end while */

	percent = (wholesale/total) * 100;
	cout << "\n The % of wholesale sales was " <<  percent << "%" << endl;
	cout << "\n The % of retail sales was " << 100-percent << "%" << endl;

	cout << endl;
    infile.close();
    system("PAUSE");
    return EXIT_SUCCESS;
}



//strUpr returns an uppercase string
string strUpr(string s)
{
       string uppercase = s;         //allocate storage for the uppercase string
       
       for (int i = 0; i < uppercase.length(); i++)
           uppercase[i] = toupper(s[i]);
           
       return uppercase;
} //end strUpr
