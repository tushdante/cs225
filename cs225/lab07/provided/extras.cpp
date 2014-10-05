
// height()
template <typename T>
int BinaryTree<T>::height() const
{
	if (root==NULL)
		return -1;
	else
		return height(root);
}

// height() recursive helper function
template <typename T>
int BinaryTree<T>::height(Node * subRoot) const
{	int left_max=0,right_max=0;
	
	if (subRoot==NULL)
		return 0;
	if (subRoot->left != NULL){			//left
		left_max+=1+height(subRoot->left);
	}
	if (subRoot->right != NULL){		//right
		right_max+=1+height(subRoot->left);
	}
	//if none of the above then height=0

	if (left_max>=right_max)
		return left_max;
	else
		return right_max;
}



// mirror()
template <typename T>
void BinaryTree<T>::mirror()
{
	// Your code here
}



// isOrdered()
template <typename T>
bool BinaryTree<T>::isOrdered() const
{
	return false; // Stub: Your code here
}



// printPathSums()
template <typename T>
void BinaryTree<T>::printPaths() const
{
	// Your code here
}

