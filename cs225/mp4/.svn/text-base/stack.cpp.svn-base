// push
//   - parameters: T newItem - an object to be added to the stack
//   - adds the parameter object to the top of the stack
template<class T>
void Stack<T>::push(T const & newItem){
	myStack.push_front(newItem);
}

// pop
//   - removes the object on top of the stack, and returns it to the caller
template<class T>
T Stack<T>::pop(){
	T ret=myStack.front();
	myStack.pop_front();
	return ret;
}

// peek
//   - finds the object on top of the stack, and returns it to the caller;
//     unlike pop(), this operation does not alter the stack itself
template<class T>
T Stack<T>::peek() const{
	T ret=myStack.front();
	return ret;
}

// isEmpty
//   - returns a boolean which is true if the stack is empty, and false
//     otherwise
template<class T>
bool Stack<T>::isEmpty() const{
	bool ret=myStack.empty();
	return ret;
}
