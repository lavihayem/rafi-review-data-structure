/*
  Name: capitalizeAndDoubleSpace1
  Copyright: 
  Author: Professor Langsam
  Date: 17/03/06 13:10
  Description: Capitalize lowercase letters and double space
*/
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int c;
  
    while (!cin.eof()){
        c = cin.get();
        if ('a' <= c && c <= 'z')
           cout.put(c + 'A' -'a');
        else if (c == '\n'){
           cout.put('\n');
           cout.put('\n');
        }
        else
           cout.put(c);
    }  // end while    
 
    system("PAUSE");
    return EXIT_SUCCESS;
}
