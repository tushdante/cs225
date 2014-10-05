/*
   Binary Search Tree (Lab 08)
   Created by Chase Geigle for CS225, Spring 2011
*/

// include the given functions
#include "bst_given.cpp"

/*
   Dictionary ADT functions and helpers
*/

// insert() - public interface
template <class K, class V>
void BST<K,V>::insert( K const & key, V const & value ) {
    insert(root, key, value);
}

// insert() - private helper
template <class K, class V>
void BST<K,V>::insert( Node * & croot, K const & key, V const & value ) {
    // your code here
	if(croot ==NULL)
		croot = new Node(key, value);
	else if(key < croot->key)
		insert(croot->left, key, value);
	else insert(croot->right, key, value);
}

// find() - public interface
template <class K, class V>
V BST<K,V>::find( K const & key ) const {
	return find(root,key);
}

// find() - private helper
template <class K, class V>
V BST<K,V>::find( Node const * croot, K const & key ) const {
	if(croot == NULL)
		return V();
	else if (croot->key == key)
		return croot->value;
	else if(key < croot->key)
		return find(croot->left,key);
	else return find(croot->right, key);
}

// remove() - public interface
template <class K, class V>
void BST<K,V>::remove( K const & key ) {
    remove( root, key );
}

// remove() - private helper
template <class K, class V>
void BST<K,V>::remove( Node * & croot, K const & key ) {
    // your code here
	if(croot == NULL)
		return;
	else if(croot->key == key)
		doRemoval(croot);
	else if(key < croot->key)
		remove(croot->left, key);
	else remove(croot->right,key);
}

//make helper function doRemoval
template<class K, class V>
void BST<K,V>::doRemoval(Node * & croot){
	if((croot->left) == NULL && (croot->right) == NULL)
		noChildRemove(croot);
	else if ((croot->left !=NULL) && croot->right !=NULL)
		twoChildRemove(croot);
	else oneChildRemove(croot);
}

template<class K, class V> 
void BST<K,V>::noChildRemove(Node * & croot){
	delete croot;
	croot = NULL;
}

template<class K,class V>
void BST<K,V>::twoChildRemove(Node * & croot){
	Node * iop = IOP(croot);
	croot->key = iop->key;
	doRemoval(IOP(croot));
}

template<class K,class V>
void BST<K,V>::oneChildRemove(Node * & croot){
	Node * temp = croot;
	if(croot->left==NULL) 
		croot = croot->right;
	else croot = croot->left;
	delete temp;
}

template<class K,class V>
typename BST<K,V>::Node * & BST<K,V>::IOP(Node * & croot){
	return rightMostChild(croot->left);
}

template<class K,class V> 
typename BST<K,V>::Node * & BST<K,V>::rightMostChild(Node * & croot){
	if(croot->right == NULL) return croot;
	else return rightMostChild(croot->right);
}

/*
   Additional functions and helpers
*/

// keySort()
template <class K, class V>
vector<V> BST<K,V>::keySort() const {
	Node* croot=root;
	return keySort(croot);
}

template <class K, class V>
vector<V> BST<K,V>::keySort(Node* & croot) const{
	vector<V> myVector;
	return inorderTraversal(croot, myVector);
}

template <class K, class V>
vector<V> BST<K,V>::inorderTraversal( Node * & croot, vector<V> & myVector)const{
    if( croot == NULL )
	 return vector<V>();
    inorderTraversal( croot->left, myVector);
    myVector.push_back(croot->value);
    inorderTraversal( croot->right, myVector );
    return myVector;

}
// levelOrder()
template <class K, class V>
vector<V> BST<K,V>::levelOrder() const {
    if(root==NULL)
    	return vector<V>(); // your code here, helpers are allowed
    else
    {
    vector<V> myVector;
    levelOrder(root,myVector);
    return myVector;
    }
    
}
template <class K, class V>
void BST<K,V>::levelOrder(Node*croot, vector<V> & myVector) const 
{
   queue<Node*> Q;
   Q.push(croot);
   while(!Q.empty())
   {
   	Node* curr=Q.front();
   	Q.pop();
   	if(curr!=NULL){
   		Q.push(curr->left);
   		Q.push(curr->right);
   		myVector.push_back(curr->value);
   	}
   }
}
