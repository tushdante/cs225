/*****************************************************
 *                                                   *
 *   stack.h                                         *   
 *                                                   *
 *   Declaration of the Stack class.                 * 
 *                                                   *
 *   Written Spring 2007 by the CS225 course staff   *
 *   Updated Spring 2008 by Daniel Hoodin            * 
 *                                                   * 
 ****************************************************/

#ifndef STACK_H
#define STACK_H

#include <list>
using std::list;

// Class Stack
//
// Represents a standard Stack.  Templated to hold elements of any type.
template<class T>
class Stack {

public:

   // push
   //   - parameters: T newItem - an object to be added to the stack
   //   - adds the parameter object to the top of the stack
   void push(T const & newItem);


   // pop
   //   - removes the object on top of the stack, and returns it to the caller
   T pop();


   // peek
   //   - finds the object on top of the stack, and returns it to the caller;
   //     unlike pop(), this operation does not alter the stack itself
   T peek() const;


   // isEmpty
   //   - returns a boolean which is true if the stack is empty, and false
   //     otherwise
   bool isEmpty() const;


private:
   list<T> myStack;  // the list representing our stack; the front of the list
                     // corresponds to the head of the stack
};

#include "stack.cpp"  // needed for template instantiation
#endif
