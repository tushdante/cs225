/*****************************************************
 *                                                   *
 *   testhashtable.cpp                               *   
 *   cs225 lab #11                                   *
 *                                                   *
 *   Made in Spring 2008 by Daniel Hoodin            * 
 *                                                   * 
 ****************************************************/

#include <cstdlib>
#include <iostream>
#include "validator.h"
#include "authenticator.h"

using std::cout;
using std::endl;

bool testRemoveAllUsers(int mode, int hash)
{
   Validator v;
   Authenticator auth(10, mode, hash, "passwords.dat");
   v.assertTrue(auth.authenticate("jack", "broken.crown"));
   v.assertTrue(auth.authenticate("jill", "tumblin'down"));
   v.assertTrue(auth.authenticate("mary", "contrary"));
   v.assertTrue(auth.authenticate("bopeep", "sheep!lost"));
   v.assertTrue(auth.authenticate("bob", "bob.com"));
   v.assertTrue(auth.authenticate("joe", "joe.com"));
   v.assertTrue(auth.authenticate("alice", "alice-test"));
   v.assertTrue(auth.authenticate("frank", "frank-test"));
   v.assertTrue(auth.authenticate("gus", "gus-test"));
   auth.removeAllUsers();
   v.assertFalse(auth.authenticate("jack", "broken.crown"));
   v.assertFalse(auth.authenticate("jill", "tumblin'down"));
   v.assertFalse(auth.authenticate("mary", "contrary"));
   v.assertFalse(auth.authenticate("bopeep", "sheep!lost"));
   v.assertFalse(auth.authenticate("bob", "bob.com"));
   v.assertFalse(auth.authenticate("joe", "joe.com"));
   v.assertFalse(auth.authenticate("alice", "alice-test"));
   v.assertFalse(auth.authenticate("frank", "frank-test"));
   v.assertFalse(auth.authenticate("gus", "gus-test"));
   return v.satisfied();
}

bool testAuthenticate(int mode, int hash)
{
   Validator v;
   Authenticator auth(10, mode, hash, "passwords.dat");
   v.assertTrue(auth.authenticate("jack", "broken.crown"));
   v.assertTrue(auth.authenticate("jill", "tumblin'down"));
   v.assertTrue(auth.authenticate("mary", "contrary"));
   v.assertTrue(auth.authenticate("bopeep", "sheep!lost"));
   v.assertTrue(auth.authenticate("bob", "bob.com"));
   v.assertTrue(auth.authenticate("joe", "joe.com"));
   v.assertTrue(auth.authenticate("alice", "alice-test"));
   v.assertTrue(auth.authenticate("frank", "frank-test"));
   v.assertTrue(auth.authenticate("gus", "gus-test"));
   v.assertFalse(auth.authenticate("jack", "brokencrown"));
   v.assertFalse(auth.authenticate("jack", "tumblin'down"));
   v.assertFalse(auth.authenticate("bopeep", "contrary"));
   v.assertFalse(auth.authenticate("mary", "sheep!lost"));
   return v.satisfied();
}

bool testAddUser(int mode, int hash)
{
   Validator v;
   Authenticator auth(10, mode, hash, "passwords.dat");
   v.assertTrue(auth.authenticate("jack","broken.crown"));
   v.assertTrue(auth.addUser("jack", "crown.broken"));
   v.assertTrue(auth.authenticate("jack","crown.broken"));
   v.assertFalse(auth.authenticate("jack","broken.crown"));
   v.assertTrue(auth.addUser("jack", "crow.broken"));
   v.assertTrue(auth.authenticate("jack","crow.broken"));
   v.assertFalse(auth.authenticate("jack","crown.broken"));
   v.assertTrue(auth.addUser("vicki", "mathematics"));
   v.assertTrue(auth.authenticate("vicki","mathematics"));
   return v.satisfied();
}

bool testRemoveUser(int mode, int hash)
{
   Validator v;
   Authenticator auth(10, mode, hash, "passwords.dat");
  
   v.assertTrue(auth.authenticate("jack", "broken.crown"));
   v.assertTrue(auth.authenticate("jill", "tumblin'down"));
   v.assertTrue(auth.authenticate("mary", "contrary"));
   v.assertTrue(auth.authenticate("bopeep", "sheep!lost"));
   
   v.assertTrue(auth.removeUser("jack"));

   v.assertFalse(auth.authenticate("jack", "broken.crown"));
   v.assertTrue(auth.authenticate("jill", "tumblin'down"));
   v.assertTrue(auth.authenticate("mary", "contrary"));
   v.assertTrue(auth.authenticate("bopeep", "sheep!lost"));
   
   v.assertTrue(auth.removeUser("jill"));
   
   v.assertFalse(auth.authenticate("jack", "broken.crown"));
   v.assertFalse(auth.authenticate("jill", "tumblin'down"));
   v.assertTrue(auth.authenticate("mary", "contrary"));
   v.assertTrue(auth.authenticate("bopeep", "sheep!lost"));
  
   v.assertFalse(auth.removeUser("chris"));
   
   v.assertFalse(auth.authenticate("jack", "broken.crown"));
   v.assertFalse(auth.authenticate("jill", "tumblin'down"));
   v.assertTrue(auth.authenticate("mary", "contrary"));
   v.assertTrue(auth.authenticate("bopeep", "sheep!lost"));
   
   v.assertTrue(auth.removeUser("mary"));
 
   v.assertFalse(auth.authenticate("jack", "broken.crown"));
   v.assertFalse(auth.authenticate("jill", "tumblin'down"));
   v.assertFalse(auth.authenticate("mary", "contrary"));
   v.assertTrue(auth.authenticate("bopeep", "sheep!lost"));
   
   v.assertTrue(auth.removeUser("bopeep"));
 
   v.assertFalse(auth.authenticate("jack", "broken.crown"));
   v.assertFalse(auth.authenticate("jill", "tumblin'down"));
   v.assertFalse(auth.authenticate("mary", "contrary"));
   v.assertFalse(auth.authenticate("bopeep", "sheep!lost"));

   return v.satisfied();
}

void printResults(bool result, int mode, int hash, string testName)
{
   cout << testName << " " << mode << " " << hash;
   if(result)
      cout << " passes" << endl;
   else
      cout << " fails" << endl; 
}

int main()
{
   int numModes = 2;
   int numHashes = 3;
   for(int i = 0; i < numModes; ++i)
   {
      for(int j = 0; j < numHashes; ++j)
      {
         printResults(testAuthenticate(i,j),i,j,"  testAuthenticate");
         printResults(testAddUser(i,j),i,j,"       testAddUser");
         printResults(testRemoveUser(i,j),i,j,"    testRemoveUser");
         printResults(testRemoveAllUsers(i,j),i,j,"testRemoveAllUsers");
      }
   }
}

