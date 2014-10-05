/*
Cpp file that implements the funcitonality for:
1) appendList
2) splitList
3)	mixList
4) removeNth
5) tripleRotate
*/

#include "doubly-linked-list.h"



/*
This function take a list as a parameter and appends it to the end of the 
current list. Error handling is done by checking for an empty/malfunctioning
parameter list or if the current list is empty.
If everything is cleared, the parameter is added to the end via the "else"
segment.
*/
template <typename Etype>
void List<Etype>::appendList(List<Etype> & endList)
	{

	//Param list is empty, nothing to append
	if (endList.size == 0 || endList.head==NULL)
		{
		return;
		}

	//If current list is empty but parameter isn't--reassign memory.		
	//Param. variables cleared.
	else if ((this->size==0 || this->head==NULL) && endList.size!=0)
		{
		this->head=endList.head;
		this->tail=endList.tail;
		this->size=endList.size;
		
		endList.head = NULL;
		endList.tail = NULL;
		endList.size=0;

		return;
		}
	
	//Regulas conditions. Parameter gets appended to end of current list.
	//Param. variables cleared.
	else
		{	
		(this->tail)->next = endList.head;
		(endList.head)->prev = (this->tail);
		(this->tail) = endList.tail;
	
		this->size = (this->size) + (endList.size);
		endList.head = NULL;
		endList.tail = NULL;
		endList.size=0;		
		return;
		}
	
}


/*
This function split's the current list at the specified rank location and 
returns the remainder. The rank-th node of the list is the first node of the 
split-off list. The current list is reduced to the portion occurring before 
the rank-th node.

Error handling is done in the case of rank being higher than the list's size
and a special case is made to handle splitting at the 1st node.
*/
template <typename Etype>
List<Etype> List<Etype>::splitList(int rank)
{
	List<Etype> TempList;
	
	if (rank>(this->size))
		{
		return TempList;
		}
		
	typename List<Etype>::ListNode* TempPtr=(this->head);
	
	//Special case, re-assign whole list.
	if (rank==1)
		{
		TempList.head = this->head;
		TempList.tail = this->tail;
		TempList.size = (this->size);
		this->head    = NULL;
		this->tail    = NULL;
		this->size	  = 0;
		return TempList;
		}


	//Traverse linked list to node before the one at which to split.		
	for (int i=1 ; i<(rank-1) ; i++)
		{
		TempPtr = TempPtr->next;
		}
		
	//Split & reassign pointers/prev/next.
	TempList.head = TempPtr->next;	
	TempList.tail = this->tail;
	(TempList.head)->prev=NULL;
	
	TempPtr->next = NULL;
	this->tail = TempPtr;	
	
	
	TempList.size = (this->size) - (rank-1);
	this->size = rank-1;
	
	return TempList;	
	
}



/*
This function mixes elements from the current list and the parameter list--
beginning with the 1st node of the current list, then the second of the param
& so forth. If one list contains more than the other, it is appeneded at the
end.

The algorithm for performing the necessary pointer manipulation works in 
groups of threes before re itirating the for loop until it has worked through
the shorter list of the two. A temporary pointer holds the value of the next 
that would be lost otherwise.
*/
template <typename Etype>
void List<Etype>::mixList(List<Etype> & secList)
{


//Error handling if param list is empty.
if(head!=NULL && secList.head==NULL)
	{
	return;
	}

//Error handling if main list is empty, param. isn't.
else if(head==NULL && secList.head!=NULL)
	{
	this->head=secList.head;
	this->tail=secList.tail;
	this->size=secList.size;
	
	secList.head=NULL;
	secList.tail=NULL;
	secList.size=0;
	return;
	}
	
//Error handling if both are empty lists.
else if(head==NULL && secList.head==NULL)
	{
	this->head=NULL;
	this->tail=NULL;
	this->size=0;
	return;
	}	
	

//Main algorithm.
else if (head!=NULL && secList.head!=NULL)
	{
	int min;
	typename List<Etype>::ListNode* PtrMain=(this->head);
	typename List<Etype>::ListNode* PtrNextMain=PtrMain->next;
	typename List<Etype>::ListNode* PtrParam=(secList.head);
	typename List<Etype>::ListNode* PtrNextParam=PtrParam->next;

	//Finds the minimum size of either lists.
	if ((this->size)>secList.size)
		{
		min=secList.size;
		}
	else if((this->size)<secList.size)
		{
		min=(this->size);
		}
	else 
		{
		min=secList.size;
		}
	
	//Loop performs the mixing in groups of three nodes. 
	for(int i=0 ; i<min-1 ; i++)
		{
		PtrMain->next=PtrParam;
		PtrParam->prev=PtrMain;
		PtrParam->next=PtrNextMain;
		PtrNextMain->prev=PtrParam;
		
		
		PtrMain=PtrNextMain;
		PtrParam=PtrNextParam;
		PtrNextMain=PtrNextMain->next;
		PtrNextParam=PtrNextParam->next;	
		}	
		
	//Once the shorter loop has run out, 3 possible cases are handled below:

	//1) If both lists were of the same lengths.
	if (PtrNextParam==NULL && PtrNextMain==NULL)
		{
		PtrMain->next=PtrParam;
		PtrParam->prev=PtrMain;
		this->tail=secList.tail;
		}
	
	else
		{
	//2)If current list is shorter than parameter list, append on the remainder.		
		if (PtrNextMain==NULL)
			{
			PtrMain->next=PtrParam;
			PtrParam->prev=PtrMain;
			this->tail=secList.tail;
			}

	//3)If the parameter list is shorter than the current list.
		if (PtrNextParam==NULL)
			{
			PtrMain->next=PtrParam;
			PtrParam->prev=PtrMain;
			PtrParam->next=PtrNextMain;
			PtrNextMain->prev=PtrParam;
			}
		}
	//update calling & param. List's members.
	this->size=(this->size) + secList.size;
	secList.head=NULL;
	secList.tail=NULL;
	secList.size=0;
	return;
	}

else
	{
	return;
	}
}

/*
Parameters : N - an integer; each Nth block of nodes will be removed
		       blockSize - an integer giving the number of nodes 
		       grouped into each block of nodes.
		       
Considering the list as a sequence of blocks, with each block containing 
blockSize nodes, this function removes every Nth block from the list.
*/
template <class Etype>
void List<Etype>::removeNth(int N, int blockSize)
{

	if(head==NULL || size==0) return;
	
	
	//# of blocks in our list based on block size--rounds up
	int NumBlocks =((size+(blockSize-1))/blockSize);

	//If the parameter N is larger than the # of contiguous blocks that cover 
	//the list, remove nothing.	
	if(N>NumBlocks) return;

	//initialize variables	
	bool breakflag=false;
	typename List<Etype>::ListNode* deleteNode,*NodeBefore, *tempTail;
	current=head;
	int deleteBlock;

	
	//check for N=1 case--remove/delete whole list
	if(N==1)
		{
		while(current!=NULL)
			{
			deleteNode=current->next;
			delete current;
			current=deleteNode;
			}
		head=NULL;
		tail=NULL;
		size=0;
		return;
		}
		
	//Main Algorithm
	for (int i=1; i<=NumBlocks ; i++)//block counter;used to check when to delete
		{
		tempTail=current->prev;		//temporary pointer to prev. block's end
											//in case we're deleting our tail
		
		for (int j=1; j<=blockSize; j++)//traverses individual nodes & based on
			{									  //the block counter it can delete or not
			

			//checks if at end  or if end block has hanging w/ next==NULL
			//Breaks out of both loops if so.
			if (current==NULL)			
				{								
				breakflag=true;
				break;
				}
				
			// 1) DELETE
			//checks if current node belongs to a block
			//that is meant to be deleted via MOD
			deleteBlock=i%N;
			if (deleteBlock==0)			
				{								
				deleteNode=current->next;
				NodeBefore = current->prev;
				
				(NodeBefore)->next=deleteNode;
				delete current;
				size=size-1;
				
				//if at end of list, no need to set "NULL"s previous
				if(deleteNode!=NULL)
					{
					deleteNode->prev=current->prev;
					}
				//if at end of list, set tail pointer	
				if (deleteNode==NULL || deleteNode->next==NULL)
					{
					tail=tempTail;
					}
				//traverse
				current=deleteNode;
				}
				
			// 2) DON'T DELETE	
			//if not meant to be deleted,only traverse	
			if(deleteBlock!=0)					
				{
				if (current->next==NULL) tail=current;
				current=current->next;

					
				}
			}
		//if nested loop detects that it needs to prematurely break in order to
		//avoid derefrencing NULL, send this signal to break out of the outer loop	
		if (breakflag==true) break;
		}
		
}


template <class Etype>
void List<Etype>::tripleRotate(int blockSize)
{

	int triplets= (size/(3*blockSize)); //number of "ABC" triplets

	
	if (triplets==0 || blockSize>size) return;
	
	typename List<Etype>::ListNode* Ahead, *Atail, *Bhead, *Btail,
	*Ctail, *tripletHead;
	
	current=head;
	
	//Main Algorithm
	//Step 1: find _head & _tail pointers to the first & last node respecively of 
	//each block A, B, C.
	//Step 2: switch positioning of ABC to BCA using pointers from step 1
	//step 3: loop through each "triplet" set of ABC.
	
	for (int i=1; i<=triplets ; i++)//loop through each set of "ABC"s 
	{
	
	//Step 1	
		//traverse A, get head and tail pointers
		for (int j=1; j<=blockSize ; j++)
			{
			if(j==1) Ahead=current;
			if(j==blockSize) Atail=current;

			current=current->next;
			}		
			
		
		//traverse B, get head and tail pointers		
		for (int k=1; k<=blockSize ; k++)
			{
			if(k==1) Bhead=current;
			if(k==blockSize) Btail=current;

			current=current->next;
			}		
			
		//moves "head" to "block B"s first Node for 1st triplet of List	
		if(i==1) 
			{
			head=Bhead;
			Bhead->prev=NULL;
			}

		
		//traverse C, get head and tail pointers (use tail's next for current
		for (int l=1; l<=blockSize ; l++)
			{
			if (l==blockSize) 
				{
				Ctail=current;
				tripletHead=current->next;
				}
			current=current->next;
			}
			
	//Step 2: redirect pointers--ABC => BCA
	Atail->next=tripletHead;
	if (tripletHead !=NULL) tripletHead->prev=Atail;
	if (Ahead->prev !=NULL) 
		{
		Bhead->prev=Ahead->prev;
		(Bhead->prev)->next=Bhead;
		}
	if (Ahead->prev == NULL) Bhead->prev=NULL;
	
	Ahead->prev=Ctail;
	Ctail->next=Ahead;
	
	//moves "tail" to "block A"s last node for last triplet
	if(i==triplets && (Atail->next==NULL)) tail=Atail;
		
	}


}







