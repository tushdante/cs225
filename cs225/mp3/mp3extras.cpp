/******************************************************************************
*	mp3extras.cpp 
*	MP3.1:
*	These funcitons allow the list to append, split, and mix.
*	MP3.2:
*	These functions allow the list to be grouped in blocks and have every
*	Nth block deleted or have the blocks roated three times.
*	Date: Sept. 29, 2010
******************************************************************************/
#include "doubly-linked-list.h"
using std::cout;
using std::endl;
template <typename Etype>

// appendList
//    - parameters : endList - a reference to a previously allocated
//                     List object; this function changes endList
//                     to an empty list
//    - appends endList after the end of the current list, and
//      empties endList
void List<Etype>::appendList(List<Etype> & endList){
   //check if endList is empty
   if (endList.size==0 || endList.head==NULL || endList.tail==NULL)
      return;
   //if current list is empty
   if (size==0 || head==NULL || tail==NULL){
      head=endList.head;
      tail=endList.tail;
      size=endList.size;
      endList.head=NULL;
      endList.tail=NULL;
      endList.size=0;
         return;
   }
   //link tail of current list with head of endlist
   tail->next=endList.head;
   (endList.head)->prev=tail;
   //assign new tail and size
   tail=endList.tail;
   size+=endList.size;
   //clear endlist
   endList.head=NULL;
   endList.tail=NULL;
   endList.size=0;
}


template <typename Etype>
// splitList
//    - parameters : rank - an integer; the rank-th node of the list
//                     is the first node of the split-off list
//    - returns the portion of the current list from
//         the rank-th node onward; the current list is reduced
//         to the portion occurring before the rank-th node
List<Etype> List<Etype>::splitList(int rank){
	List<Etype> r_list;
	int temp_size=size;
	//cout<<"rank= "<<rank<<endl;
	//cout<<"head= "<<head<<endl;
	//cout<<"tail= "<<tail<<endl;
	//cout<<"size= "<<size<<endl<<endl;
	//cout<<"r_list.head= "<<r_list.head<<endl;
	//cout<<"r_list.tail= "<<r_list.tail<<endl;
	//cout<<"r_list.size= "<<r_list.size<<endl;
	//if rank =1 then:
	//1) make s_list equal to current list
	//2) make current list empty
	if (rank==1){
		r_list.appendList(*this);
		head=NULL;
		tail=NULL;
		size=0;
		return r_list;
	}
	//if rank is greater than size of list then return empty list
	else if (rank>size){
		return r_list;
	}
	//find rank then seperate
	else{
		current=head;
		for(int i=1;i<rank;i++)
			current=current->next;
		//cout<<"current="<<current<<endl;
		//cout<<"current->prev="<<current->prev<<endl<<endl;
		(current->prev)->next=NULL;
		r_list.tail=tail;
		//cout<<"r_list.head= "<<r_list.head<<endl;
		//cout<<"r_list.tail= "<<r_list.tail<<endl;
		//cout<<"r_list.size= "<<r_list.size<<endl;
		tail=current->prev;
		current->prev=NULL;
		//cout<<"changing pointer...\n";
		r_list.head=current;
		//cout<<"r_list.head= "<<r_list.head<<endl;
		//cout<<"r_list.tail= "<<r_list.tail<<endl;
		//cout<<"r_list.size= "<<r_list.size<<endl<<endl;
		size=rank-1;
		r_list.size=temp_size-size;
		//cout<<"head= "<<head<<endl;
		//cout<<"tail= "<<tail<<endl;
		//cout<<"size= "<<size<<endl;
		//cout<<"r_list.head= "<<r_list.head<<endl;
		//cout<<"r_list.tail= "<<r_list.tail<<endl;
		//cout<<"r_list.size= "<<r_list.size<<endl<<endl;
		//cout<<"total size= "<<r_list.size+size<<endl;
		return r_list;		
	}
}


template <typename Etype>
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
void List<Etype>::mixList(List<Etype> & secList){
	ListNode* temp;
	int o_size=size,sec_o_size=secList.size;
	current=head;
	//current list is empty
	if (size==0)
		appendList(secList);
	//test if secList is empty
	if (secList.size==0)
		return;
	while (((current->next) != NULL) && (secList.head)->next != NULL){
		temp=current->next;
		current->next=secList.head;
		temp->prev=secList.head;
		(secList.head)->prev=current;
		secList.head=(secList.head)->next;
		((secList.head)->prev)->next=temp;
		current=temp;
	}
	if (o_size==sec_o_size){
		//been mixed add last node
		appendList(secList);
	}
	else if (o_size<sec_o_size){
		//append remaining
		appendList(secList);
	}
	else if (o_size>sec_o_size){
		//link up end of secList nodes with remaining *this nodes
		temp=current->next;
		current->next=secList.head;
		temp->prev=secList.head;
		(secList.head)->prev=current;
		(secList.head)->next=temp;
		secList.head=NULL;
		secList.tail=NULL;
		secList.size=0;
	}
	size=sec_o_size+o_size;
}

template <typename Etype>
// removeNth
//    - parameters : N - an integer; each Nth block of nodes will be removed
//                   blockSize - an integer giving the number of nodes
//                                 grouped into each block of nodes
//    - considering the list as a sequence of blocks, with each
//         block containing blockSize nodes, this function removes every
//         Nth block from the list
void List<Etype>::removeNth(int N, int blockSize){
	ListNode* temp;
	int N_count=1;
	current=head;
	while (current!=NULL){
		//delete 
		if (N==1){
			while (current->next != NULL){
				current=current->next;
				delete current->prev;
			}
			delete current;
			current=NULL;
			head=NULL;
			tail=NULL;
			size=0;
			return;
		}
		//go through list counting each block
		else if (N_count != N){
			for(int i=0;i<blockSize;i++){
				if (current->next !=NULL)
					current=current->next;
				else
					return; //reached end of list
			}
			N_count++;
		}
		//remove block
		else{
			temp=current->prev;
			for(int j=0;j<blockSize;j++){
				if(current->next != NULL){
					current=current->next;
					delete current->prev;
					size--;
					current->prev=temp;
					temp->next=current;
				}
				else{
					delete current;
					current=NULL;
					size--;
					tail=temp;
					temp->next=NULL;
					break;
				}
			}
			N_count=1;
		}
	}
}
					
			

template <typename Etype>
// tripleRotate
//    - parameters : blockSize - an integer giving the number of nodes
//                                 grouped into each block of nodes
//    - considering the list as a sequence of blocks, with each
//         block containing blockSize nodes, this function takes
//         the first three blocks (A,B,C), rearranges them in the
//         form (B,C,A), and continues the procedure on the remainder
//         of the list
void List<Etype>::tripleRotate(int blockSize){
	ListNode *A,*A_end,*temp,*B;
	current=head;
	while(current!=NULL){
		//point to block A
		A=current;
		for(int i=1; i<(blockSize*3);i++){
			if (current->next == NULL)
				return;
			else 
				current=current->next;
		}
		//point to last node in block c
		temp=current;
		current=A;
		for(int i=1;i<blockSize;i++)
			current=current->next;
		//point to last node in A block
		A_end=current;
		//point to first node in B block
		B=A_end->next;
		B->prev=A->prev;
		if (B->prev ==NULL)
			head=B;
		else
			(B->prev)->next=B;
		A_end->next=temp->next;
		temp->next=A;
		if (A_end->next == NULL)
			tail=A_end;
		else
			(A_end->next)->prev=A_end;
		A->prev=temp;
		//set current for loop back
		current=A_end->next;
	}
}
	
