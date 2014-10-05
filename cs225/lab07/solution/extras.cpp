
// height()
template <typename T>
int BinaryTree<T>::height() const
{
	return height(root);
}

// height() recursive helper function
template <typename T>
int BinaryTree<T>::height(const Node * subRoot) const
{
	if (subRoot == NULL) return -1;
	
	return 1 + max(height(subRoot->left), height(subRoot->right));
}



// mirror()
template <typename T>
void BinaryTree<T>::mirror()
{
	mirror(root);
}

// mirror() recursive helper
template <typename T>
typename BinaryTree<T>::Node * BinaryTree<T>::mirror(Node * subRoot)
{
	if (subRoot == NULL) return NULL;
	
	// Swap and mirror
	Node * temp    = subRoot->left;
	subRoot->left  = mirror(subRoot->right);
	subRoot->right = mirror(temp);

	return subRoot;
}



// isOrdered()
template <typename T>
bool BinaryTree<T>::isOrdered() const
{
	return isOrdered(root);
}

// isOrdered() recursive helper
template <typename T>
bool BinaryTree<T>::isOrdered(const Node * subRoot) const
{
	if (subRoot == NULL) return true;
	
	return isOrdered(subRoot->left) && isOrdered(subRoot->right)                       &&
	       (subRoot->left  == NULL || rightMost(subRoot->left)->elem <= subRoot->elem) &&
	       (subRoot->right == NULL || leftMost(subRoot->right)->elem >= subRoot->elem) ;
}

// Find the left-most child of a node
template <typename T>
const typename BinaryTree<T>::Node * BinaryTree<T>::leftMost(const Node * subRoot) const
{
	while (subRoot->left != NULL)
		subRoot = subRoot->left;
	return subRoot;
}

// Find the right-most child of a node
template <typename T>
const typename BinaryTree<T>::Node * BinaryTree<T>::rightMost(const Node * subRoot) const
{
	while (subRoot->right != NULL)
		subRoot = subRoot->right;
	return subRoot;
}



// printPathSums()
template <typename T>
void BinaryTree<T>::printPaths() const
{
	if (root == NULL)
	{
		cout << "(no paths)" << endl;
		return;
	}

	vector<T> path;
	printPaths(root, path);
}

// printPathSums recursive helper function
template <typename T>
void BinaryTree<T>::printPaths(const Node * node, vector<T> & path) const
{
	if (node == NULL) return;

	path.push_back(node->elem);
	if (node->left == NULL && node->right == NULL)
	{
		cout << "Path:";
		for (size_t i = 0; i < path.size(); i++)
			cout << ' ' << path[i];
		cout << endl;
	}
	else
	{
		printPaths(node->left,  path);
		printPaths(node->right, path);
	}
	path.pop_back();
}
