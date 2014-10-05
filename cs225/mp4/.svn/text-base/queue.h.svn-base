/*****************************************************
 *                                                   *
 *   queue.h                                         *   
 *                                                   *
 *   Declaration of the Queue class.                 * 
 *                                                   *
 *   Written Spring 2007 by the CS225 course staff   *
 *   Updated Spring 2008 by Daniel Hoodin            * 
 *                                                   * 
 ****************************************************/

#ifndef QUEUE_H
#define QUEUE_H

#include "stack.h"

// Class Queue
//
// Represents a standard Queue.  Templated to hold elements of any type.
template<class T>
class Queue {

public:

   // enqueue
   //   - parameters: T newItem - an object to be added to the queue
   //   - adds the parameter object to the back of the queue
   void enqueue(T const & newItem);

   // dequeue
   //   - removes the object at the front of the queue, and returns it to
   //     the caller
   T dequeue();

   // peek
   //   - finds the object at the front of the queue, and returns it to
   //     the caller; unlike pop(), this operation does not alter the queue
   T peek();

   // isEmpty
   //   - returns a boolean which is true if the queue is empty, and false
   //     otherwise
   bool isEmpty() const;

private:
   Stack<T> inStack;
   Stack<T> outStack;
};

#include "queue.cpp"
#endif
