/*****************************************************
 *                                                   *
 *   main.cpp                                        *
 *   cs225 lab #11                                   *
 *                                                   *
 *   Made in Spring 2008 by Daniel Hoodin            *
 *                                                   *
 ****************************************************/

#include "wordcount.h"
#include "authenticator.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/*****************************************************************************
void printUsage()

Print a usage message and exit
*****************************************************************************/
void printUsage()
{
   cout << "lab10 [authenticator|wordcount] [mode] [hash]" << endl;
   exit(-1);
}

void runAuthenticator(int mode, int hash)
{
   int size = 10;
   Authenticator auth(size, mode, hash, "passwords.dat");
   auth.showStructure();
   auth.showStatistics(); 
   string name,pass;
   cout << "Login: ";
   while(cin >> name)
   {
      cout << "Password: ";
      cin >> pass;
      if(auth.authenticate(name, pass))
         cout << "Authentication successful" << endl;
      else
         cout << "Authentication failure" << endl;
      cout << "Login: ";
   }
   cout << endl;
}

void runWordCount(int mode, int hash)
{
   int size = 60000;
   WordCount wc(size, mode, hash, "shakespeare.dat");
   wc.showStatistics(); 
}

/*****************************************************************************
int main(int arc, char **argv)

argv[0] = lab10
argv[1] = program name
argv[2] = collision-handling scheme #
argv[3] = hash function #

*****************************************************************************/
int main(int argc, char **argv)
{
   //You need to have exactly 3 arguments
   if (argc != 4)
      printUsage();
   else if(!strcmp(argv[1],"authenticator"))
      runAuthenticator(atoi(argv[2]),atoi(argv[3]));
   else if(!strcmp(argv[1],"wordcount"))
      runWordCount(atoi(argv[2]),atoi(argv[3]));
   else
      printUsage();
}
