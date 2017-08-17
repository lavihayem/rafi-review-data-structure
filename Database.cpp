/*
  Name: DataBase
  Copyright: 
  Author: Harrow & Jones; 
  Modified: Langsam
  Date: 02/04/06 21:43
  Description: Creates a database about quiz game contestants,
               then answers questions about the database
*/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int NUMCONS = 50;

class CContestantName {
     public:
            string last;
            string first;
};

class CJobInfo {
     public:
            string  title;
            double salary;
};

class CPersonInfo {
     public:
            string   sex;
            string   haircolor;
            int    age;
            CJobInfo job;
};

class CIndividual {
     public:
            CContestantName name;
            CPersonInfo personal;
};

void readData(CIndividual [], int &);
void prettyPrint(CIndividual [], int);
void printMenu(void);
int selectTrait(CIndividual [], int);
void findAge(CIndividual [], int);
void findSex(CIndividual [], int);
void findHair(CIndividual [], int);
void findTitle(CIndividual [], int);
void findSalary(CIndividual [], int);
void pause(void);
string strUpr(string);



int main(int argc, char *argv[])
{
     int num;
     CIndividual contestant[NUMCONS];

    /*
     * Part I: calls readData to read the original database
     * then calls prettyPrint to print it
     */

     readData(contestant,num);
     prettyPrint(contestant,num);
     /* Part II: calls functions to read and process the requests */
     do {
        printMenu();
     } while (selectTrait(contestant,num) != 0);

     system("PAUSE");
     return EXIT_SUCCESS;
}




/*
 * Function readData:
 * Called by: main       
 * Calls: none
 */
void readData(CIndividual contestant[], int &num)
{
     int count;

     ifstream infile;                   //create the file infile for input
     infile.open("database.txt");       //open the file
    
     if ( !infile.is_open() ) {         //checks to see if file was opened
        // The file could not be opened
        cout << endl << "ERROR: Unable to open file" << endl;
        system ("PAUSE");
        exit(1);
     }

     count = 0;
     while (!infile.eof() && infile >> contestant[count].name.last) {
           infile >> contestant[count].name.first
    	       >> contestant[count].personal.sex
    	       >> contestant[count].personal.haircolor
    	       >> contestant[count].personal.age
	           >> contestant[count].personal.job.title
    	       >> contestant[count].personal.job.salary;
	       count++;
     }
     num = count;
     infile.close();
     return;
} // end readData




/*
 * Function prettyPrint:
 * Called by: main       
 * Calls: none
 */
void prettyPrint(CIndividual contestant[], int num)
{
     int  count;
     ofstream outfile("database.out");

     if ( !outfile.is_open() ) {       //Method: checks to see if file was opened
        // The file could not be opened
        cout << endl << "ERROR: Unable to open output file" << endl;
        system ("PAUSE");
        exit(1);
     }
     
     outfile.setf(ios::fixed,ios::floatfield);
	 outfile.precision(2);
     
     outfile << "\t\tContestants in the Database" << endl << endl;
     outfile << "Name \t\tSex \tHair \tAge \tTitle \tSalary" << endl << endl;;
     for (count = 0; count < num; count++) {
	     outfile << contestant[count].name.first             << "\t";
	     outfile << contestant[count].name.last              << "\t";
	     outfile << contestant[count].personal.sex           << "\t";
	     outfile << contestant[count].personal.haircolor     << "\t";
	     outfile << contestant[count].personal.age           << "\t";
	     outfile << contestant[count].personal.job.title     << "\t";
	     outfile << contestant[count].personal.job.salary    << endl;
     }
     outfile.close();
     return;
}




/*
 * Function printMenu:
 * Called by: main   
 * Calls: none
 */
void printMenu()
{
     cout << "\n\n\n\n\n\n\n";
     cout << "To obtain a list of contestants with a given trait," << endl;
     cout << "select a trait from the list and type in the number" << endl;
     cout << "corresponding to that trait." << endl << endl;
     cout << "To quit, select 0." << endl << endl;
     cout << "\t******************************" << endl;
     cout << "\t        List of Choices       " << endl;
     cout << "\t******************************" << endl;
     cout << "\t   0 -- quit" << endl;
     cout << "\t   1 -- age" << endl;
     cout << "\t   2 -- sex" << endl;
     cout << "\t   3 -- haircolor" << endl;
     cout << "\t   4 -- title" << endl;
     cout << "\t   5 -- salary" << endl;
     cout << "\n\n\tEnter your selection, 0 through 5 > ";
     return;
}




/*
 * Function selectTrait:
 * Called by: main    
 * Calls: findAge,findSex,findHair,findTitle,findSalary
 */
int selectTrait(CIndividual contestant[], int num)
{
    int choice;

    do {
	  cin >> choice;
	  switch(choice) {
            case 0: break;
	        case 1: findAge(contestant,num);
		            break;
            case 2: findSex(contestant,num);
		            break;
            case 3: findHair(contestant,num);
		            break;
            case 4: findTitle(contestant,num);
		            break;
            case 5: findSalary(contestant,num);
		            break;
            default: cout << "Incorrect value; try again" << endl;
		             cout << "\n\tEnter your selection, 0 through 5 > ";	       
       } // end switch
     } while (choice < 0 || choice > 5);
     return choice;
} // end selectTrait




/*
 * Function findAge:
 * Called by: selectTrait    
 * Calls: pause
 */
void findAge(CIndividual contestant[], int num)
{
     int agewanted, i, found=0;

     cout << "\n\nEnter the age that you want > ";
     cin >> agewanted;
     cout << "\n\nContestants whose age is " << agewanted << endl << endl;
     for (i = 0; i < num; i++)
         if (contestant[i].personal.age == agewanted) {
	        cout << contestant[i].name.first << " "
                 << contestant[i].name.last << endl;
	        found++;
         }
     if (!found)
	     cout << "No contestants of this age" << endl << endl;
     else
	     cout << found << " contestants found" << endl;
     pause();
     return;
} // end findAge



/*
 * Function findSex:
 * Called by: selectTrait    
 * Calls: pause
 */
void findSex(CIndividual contestant[],int num) 
{
     int i;
     string sexvalue;
     int found = 0;

     cout << "\n\nEnter the sex desired (M/F) > ";
     cin >> sexvalue;
     cout << "\n\nAll contestants whose sex is " << sexvalue << endl << endl;
     for (i = 0; i < num; i++)
         if (strUpr(contestant[i].personal.sex) == strUpr(sexvalue)) {
		    cout << contestant[i].name.first << " "
                 << contestant[i].name.last << endl;
		    found++;
	  }
	  if (!found)
		 cout << "none" << endl;
	  else
		  cout << found << " contestants were found" << endl;
	  pause();
	  return;
} //end findSex




/*
 * Function findHair:
 * Called by: selectTrait    
 * Calls: pause
 */
void findHair(CIndividual contestant[], int num) 
{
     int i;
     string hairvalue;
     int found = 0;

     cout << "\n\nEnter the haircolor desired." << endl;
     cout << "Choices: red,brown,blonde,bald,black,gray > ";
     cin >> hairvalue;
     cout << "\n\nAll contestants whose hair is " << hairvalue << endl << endl;

     for (i = 0; i < num; i++)
         if (strUpr(contestant[i].personal.haircolor) == strUpr(hairvalue)) {
            cout << contestant[i].name.first << " "
                 << contestant[i].name.last << endl;
		    found++;
         }
	  if (!found)
		 cout << "none" << endl;
	  else
		  cout << found << " contestants were found" << endl;
	  pause();
	  return;
} // end findHair




/*
 * Function findTitle:
 * Called by: selectTrait    
 * Calls: pause
 */
void findTitle(CIndividual contestant[], int num) {
     int i;
     string titlevalue;
     int found = 0;

     cout << "\n\nEnter the occupation desired > ";
     cin >> titlevalue;
     cout << "\n\nAll contestants whose title is " << titlevalue << endl << endl;

     for (i = 0; i < num; i++)
	     if (strUpr(contestant[i].personal.job.title) == strUpr(titlevalue)) {
		    cout << contestant[i].name.first << " "
                 << contestant[i].name.last << endl;
		    found++;
	  }
	  if (!found)
		 cout << "none" << endl;
	  else
		  cout << found << " contestants were found" << endl;
	  pause();
	  return;
} //end findTitle




/*
 * Function findSalary:
 * Called by: selectTrait    
 * Calls: pause
 */
void findSalary(CIndividual contestant[], int num) {
     int i;
     double salaryvalue;
     int found = 0;

     cout << "\n\nEnter the minimum salary desired > ";
     cin >> salaryvalue;
     cout << "\n\nAll contestants whose salary is above $" << salaryvalue 
          << endl << endl;

     cout.setf(ios::fixed,ios::floatfield);
	 cout.precision(2);
     
     for (i = 0; i < num; i++)
	     if (contestant[i].personal.job.salary >= salaryvalue) {
	        cout << contestant[i].name.first << " "
                 << contestant[i].name.last << endl;
		    found++;
	  }
	  if (!found)
		 cout << "none" << endl;
	  else
		  cout << found << " contestants were found" << endl;
	  pause();
	  return;
} //end findSalary




/*
 * Function pause:
 * Called by: findAge,findHair,findSex,findTitle,findSalary  
 * Calls: none
 */
void pause()
{
     string response;
     getline(cin, response);
     cout << "\n\nPress <Enter> to continue";
     getline(cin, response);
     return;
} //end pause




//strUpr returns an uppercase string
string strUpr(string s)
{
       string uppercase = s;         //allocate storage for the uppercase string
       
       for (int i = 0; i < uppercase.length(); i++)
           uppercase[i] = toupper(s[i]);
           
       return uppercase;
} //end strUpr


