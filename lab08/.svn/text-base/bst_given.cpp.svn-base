/*
   Below are given functions for Lab 08
   You should *NOT* modify this file.
*/

/*
   Big Three
*/

// constructor
template <class K, class V>
BST<K,V>::BST() : root(NULL) { }

// copy constructor
template <class K, class V>
BST<K,V>::BST( BST<K,V> const & orig ) {
    root = copy(orig.root);
}

// destructor
template <class K, class V>
BST<K,V>::~BST() {
    clear(root);
}

// operator=
template <class K, class V>
BST<K,V> const & BST<K,V>::operator=( BST<K,V> const & rhs ) {
    if( this != &rhs ) {
        clear(root);
        root = copy(rhs.root);
    }
    return *this;
}

// copy()
template <class K, class V>
typename BST<K,V>::Node * BST<K,V>::copy( Node const * croot ) {
    if( croot == NULL ) return NULL;

    Node * node = new Node(croot->key, croot->value);
    node->left  = copy(croot->left);
    node->right = copy(croot->right);
    return node;
}

// clear()
template <class K, class V>
void BST<K,V>::clear( Node * croot ) {
    if( croot == NULL )
        return;
    clear( croot->left );
    clear( croot->right );
    delete croot;
}

// height() - public interface
template <class K, class V>
int BST<K,V>::height() const { 
    return height( root );
}

// height() - private helper
template <class K, class V>
int BST<K,V>::height( Node const * croot ) const {
    if( croot == NULL )
        return -1;

    return 1 + max( height( croot->left ), height( croot->right ) );
}

// print()
template <class K, class V>
void BST<K,V>::print() const
{
	// Base case
	if (root == NULL)
	{
		cout << "(empty)" << endl;
		return;
	}

	// Make a character matrix for outputting the tree onto
	int rootData  = getPrintData(root);
	int width     = (4 << rootData) - 3;
	int height    = 2 * rootData + 1;

	// Initialize this matrix to be filled with spaces
	vector<string> output(height);
	for (size_t i = 0; i < output.size(); i++)
		output[i] = string(width+4, ' '); // extra room for long things

	// Recursively print each node
	print(root, output, 0, 0, width);

	// Output the matrix
	for (int row = 0; row < height; row++)
		cout << output[row] << endl;
}

// Gathers data about each node to determine the size of the output matrix
template <class K, class V>
int BST<K,V>::getPrintData(const Node * node) const
{
    if (node == NULL) return -1;
    return 1 + max( getPrintData(node->left),
	                getPrintData(node->right) );
}

// Recursively prints tree to output matrix
template <class K, class V>
void BST<K,V>::print(const Node * node, vector<string> & output,
                          int left, int top, int width) const
{
	// Convert data to string
	stringstream nodeOut;
	nodeOut << node->key;
	string nodeStr = nodeOut.str();
	
	// Output data
	for (size_t i = 0; i < nodeStr.length() && left + width/2 + i < output[top].length(); i++)
		output[top][left + width/2 + i] = nodeStr[i];
	
	// Calculate / \ offset = 2 ^ height
	int branchOffset = (width+3) >> 3; //(1 << (node->printData - 1));
	
	// Print left child
	if (node->left  != NULL)
	{
		output[top+1][left + width/2 - branchOffset] = '/';
		print(node->left, output, left, top+2, width/2 - 1);
	}
	// Print right child
	if (node->right != NULL)
	{
		output[top+1][left + width/2 + branchOffset] = '\\';
		print(node->right, output, left + width/2 + 2, top+2, width/2 - 1);
	}
}


