/*
  Name: StudentGrades
  Copyright: 
  Author: Professor Langsam
  Date: 02/04/06 15:34
  Description: This program will process student grades. 
*/
#include <cstdlib>
#include <iostream>
#include <fstream>

#include "CStudent.h"

using namespace std;

CStudent section[CLASSSIZE];

    

//*************************************************************************


int main(int argc, char *argv[])
{
    int i, count;
  
    int countFailingGrades(CStudent [], int);
    void bubble(CStudent [], int);
    void printStudents(CStudent [], int);
  
    ifstream infile;                   //create the file infile for input
    infile.open("StudentGrades.txt");  //open the file
    
    if ( !infile.is_open() ) {         //checks to see if file was opened
       // The file could not be opened
       cout << endl << "ERROR: Unable to open file" << endl;
       system ("PAUSE");
       exit(1);
    }

    
  
    //read the datafile into the object and count the number of students
    count = 0;
    while (!infile.eof() && infile >> section[count].studentID
                                   >> section[count].name
                                   >> section[count].grade)
        ++count;
  
  
    // print the student list
    printStudents(section, count);
  

    // count the failing grades
    cout << endl << countFailingGrades(section, count) 
                 << " students failed." << endl << endl;
  
  
    // Sort by grades and print the student list
    bubble(section, count);
    
    
    // print the student list
    printStudents(section, count);
  
    
    infile.close();
    cout << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}


//*************************************************************************


//countFailingGrades returns the number of students who have failed
int countFailingGrades(CStudent section[], int studentsInClass)
{
    int i, count = 0;
    
    for (i = 0; i < studentsInClass; ++i)
        if (section[i].grade == "F") 
           ++count;    
           
    return count;
} // end countFailingGrades



//*************************************************************************


// Bubble Sort modified to sort structures
void bubble(CStudent section[], int n)
{
	int j, pass;
	bool switched = true;
	CStudent temp;

	for (pass = 0; pass < n-1 && switched == true; pass++) {
		//     outer loop controls the number of passes
		switched = false;   	              // initially no interchanges
										      // have been made on this pass
		for (j = 0; j < n-pass-1; j++)
			//    inner loop governs each individual pass 
			if (section[j].grade > section[j+1].grade) {
				//           elements out of order 
				//        an interchange is necessary
				switched = true;
				temp = section[j];            // Note: The entire CStudent class 
				section[j] = section[j+1];    // object is being switched
				section[j+1] = temp;
			}  // end if
	}  // end for
}  // end bubble



//*************************************************************************


//Print the student list
void printStudents(CStudent section[], int n)
{
     for (int i = 0; i < n; ++i){
         cout.width(10);
         cout << section[i].studentID;
         cout.width(10); 
         cout << left << section[i].name;
         cout.width(10);
         cout << section[i].grade  << endl;
     }//end for
} //end printStudents
