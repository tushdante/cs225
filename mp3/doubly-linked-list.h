// **************************************************************
// *                                                            *
// *  doubly-linked-list.h                                      *
// *                                                            *
// *  Interface for a simple generalized (template) list        *
// *   class, implemented via a doubly-linked list              *
// *                                                            *
// *  Written October 2005 by Jason Zych                        *
// *                                                            *
// **************************************************************

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H


template <typename Etype>
class List
{
public:


   // *** Special update functions for students to implement


   // tripleRotate
   //    - parameters : blockSize - an integer giving the number of nodes
   //                                 grouped into each block of nodes
   //    - considering the list as a sequence of blocks, with each
   //         block containing blockSize nodes, this function takes
   //         the first three blocks (A,B,C), rearranges them in the
   //         form (B,C,A), and continues the procedure on the remainder
   //         of the list
   void tripleRotate(int blockSize);



   // removeNth
   //    - parameters : N - an integer; each Nth block of nodes will be removed
   //                   blockSize - an integer giving the number of nodes
   //                                 grouped into each block of nodes
   //    - considering the list as a sequence of blocks, with each
   //         block containing blockSize nodes, this function removes every
   //         Nth block from the list
   void removeNth(int N, int blockSize);




   // appendList
   //    - parameters : endList - a reference to a previously allocated
   //                     List object; this function changes endList
   //                     to an empty list
   //    - appends endList after the end of the current list, and
   //      empties endList
   void appendList(List<Etype> & endList);




   // mixList
   //    - parameters : secList - a reference to a previously allocated 
   //                     List object; this function changes secList
   //                     to an empty list
   //    - creates a list whose first element is the first elt of the current
   //         list, whose second elt is the first elt of the second list,
   //         whose third elt is the second elt of the first list, and so
   //         on alternating through both lists.  If either list becomes
   //         empty, the remaining list portion goes at the end of the
   //         current list, leaving secList empty.
   //         
   void mixList(List<Etype> & secList);




   // splitList
   //    - parameters : rank - an integer; the rank-th node of the list
   //                     is the first node of the split-off list
   //    - returns the portion of the current list from
   //         the rank-th node onward; the current list is reduced
   //         to the portion occurring before the rank-th node
   List<Etype> splitList(int rank);



   // *** Creation/Destruction/Mass Update


   // List
   //    - default constructor
   //    - initializes list to be empty
   List();


   // List
   //    - copy constructor
   //    - parameters : origVal - a reference to a previously allocated
   //                     List object; this object cannot be changed
   //                     through the parameter reference
   //    - initializes the list to be a copy of origVal
   List(List<Etype> const & origVal);


   // ~List
   //    - destructor
   //    - deallocates all dynamically allocated memory associated
   //        with the list
   ~List();


   // operator=
   //    - parameters : origVal - a reference to a previously allocated
   //                     List object; this object cannot be changed
   //                     through the parameter reference
   //    - return value: reference to this List object, after it's
   //         been assigned to be a copy of the parameter
   //    - sets this list to be a copy of origVal
   List<Etype> const & operator=(List<Etype> const & origVal);


   // clear
   //    - removes all values from list, resulting in an empty list
   void clear();


   // *** Singular Update


   // insertAfter
   //    - parameters : insElem - a reference to an object of the
   //                    generic type; the object cannot be changed
   //                    through the parameter reference. This item
   //                    will be inserted into list.
   //    - inserts insElem after current position in list (or as
   //        the only element in the list, if the list is currently
   //        empty), and sets that new element as the current
   //        position. Code does *not* check to prevent duplicates.
   void insertAfter(Etype const & insElem);


   // insertBefore
   //    - parameters : insElem - a reference to an object of the
   //                    generic type; the object cannot be changed
   //                    through the parameter reference. This item
   //                    will be inserted into list.
   //    - inserts insElem before current position in list (or as
   //        the only element in the list, if the list is currently
   //        empty), and sets that new element as the current
   //        position. Code does not check to prevent duplicates.
   void insertBefore(Etype const & insElem);


   // remove
   //    - removes the element at the current position of the list.
   //       Upon completion of the removal, the current position
   //       will be the next element in the list, or if there is no
   //       next element, then the first position (or no position at
   //       all, if the list is empty). Attempting to remove using a
   //       meaningless current position (which for this class can
   //       only happen when the list is empty) will result in a warning.
   void remove();


   // update
   //    - parameters : updateElem - a reference to an object of the
   //                    generic type; the object cannot be changed
   //                    through the parameter reference. This item
   //                    will replace another item in the list.
   //    - replaces the value at the current position with updateElem
   //      Attempting to update using a meaningless current position
   //      (which for this class can only happen when the list is empty)
   //      will result in a warning.

   // Not available for MP3!
   //void update(Etype const & updateElem);


   // *** Control of Current Position


   // front
   //    - makes the first position in the list the current position
   //      Attempting to do this when there is no first position in the
   //      list (which for this class can only happen when the list is
   //      empty) will result in a warning.
   void front();


   // back
   //    - makes the last position in the list the current position
   //      Attempting to do this when there is no last position in the
   //      list (which for this class can only happen when the list is
   //      empty) will result in a warning.
   void back();


   // forwardOne
   //    - moves the current position one position forward in the list.
   //      Attempting to move forward from a meaningless current position
   //      (which for this class can only happen when the list is empty)
   //      will result in a warning. Attempting to move forward from the
   //      last position in the list will result in a warning and the
   //      current position remaining unchanged.
   void forwardOne();


   // backwardOne
   //    - moves the current position one position backward in the list.
   //      Attempting to move backward from a meaningless current position
   //      (which for this class can only happen when the list is empty)
   //      will result in a warning. Attempting to move backward from the
   //      first position in the list will result in a warning and the
   //      current position remaining unchanged.
   void backwardOne();


   // *** Information Access


   // retrieve
   //    - return type : a reference to the object at the current position
   //         in the list; this object cannot be changed through the
   //         returned reference
   //    - returns the object at the current position in the list;
   //      attempting to retrieve from a meaningless current position
   //      (which for this class can only happen when the list is empty)
   //      will result in an error message and termination of the program.
   Etype const & retrieve() const;


   // find
   //    - parameters : queryElem - a reference to an object of the
   //                    generic type; the object cannot be changed
   //                    through the parameter reference. This item
   //                    will be searched for in the list
   //    - return value : boolean with true indicating value was found
   //    - searches list for queryElem; if found, make that position
   //         the current position and return true; otherwise, return
   //         false and do not change what position is marked as the
   //         current position. Assumes existence of operator== for
   //         generic type.
   bool find(Etype const & queryElem);


   // length
   //    - return value : a non-negative integer holding the
   //        length of the list
   //    - returns the length of the list
   int length() const;


   // print
   //    - prints out the values in the list, in order by position
   //        from first to last position. Assumes existence of
   //        operator<< for generic type.
   void print() const;

   
   // atBack
   //    - returns a boolean which is true if the current node is the
   //        tail, and false otherwise
   bool atBack() const;


private:


   // copy
   //    - parameters : origVal - a previously allocated List object
   //    - sets the list to be a copy of origVal; assumes there is no
   //         dynamic memory that needs to be cleaned out of the list
   void copy(List<Etype> const & origVal);


   class ListNode
   {
   public:

      // ListNode
      //    - constructor
      //    - initializes element to default Etype, and pointers to NULL
      ListNode();


      // ListNode
      //    - constructor
      //    - parameters : value - the value to store in the element field
      //    - initializes node to hold value and NULL pointers
      ListNode(Etype const & value);

      // getElement
      //    - returns the element in this ListNode
      // Added for MP3
      Etype const & getElement() const;

      ListNode* next; // pointer to next node in list
      ListNode* prev; // pointer to prior node in list

   private:
      Etype element;   // holds element of node
                       // made private just for MP3; normally wouldn't be
   };


   // you actually could just use ListNode* here; you don't need to
   // fully scope the type since you are in the List class declaration

   typename List<Etype>::ListNode* head;    // points to first node of list

   typename List<Etype>::ListNode* current; // points to node at
                                            //   current position

   typename List<Etype>::ListNode* tail;    // points to last node of list

   int size;
};

#include "doubly-linked-list.cpp"
#include "mp3extras.cpp"

#endif


