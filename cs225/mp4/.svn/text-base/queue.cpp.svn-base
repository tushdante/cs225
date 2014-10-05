// enqueue
//   - parameters: T newItem - an object to be added to the queue
//   - adds the parameter object to the back of the queue
template<class T>
void Queue<T>::enqueue(T const & newItem){
	//load all values from outStack into inStack
	//this reverses the order making bottom(outStack)=>top(inStack)
	//and vice versa
	while(!outStack.isEmpty()){
		inStack.push(outStack.pop());
	}
	//pushes newItem to end of list
	inStack.push(newItem); 
}

// dequeue
//   - removes the object at the front of the queue, and returns it to
//     the caller
template<class T>
T Queue<T>::dequeue(){
	//load all values from inStack into outStack
	//this reverses the order making bottom(inStack)=>top(outStack)
	//and vice versa
	while(!inStack.isEmpty()){
		outStack.push(inStack.pop());
	}
	return outStack.pop();
}

// peek
//   - finds the object at the front of the queue, and returns it to
//     the caller; unlike pop(), this operation does not alter the queue
template<class T>
T Queue<T>::peek(){
	//load all values from inStack into outStack
	//this reverses the order making bottom(inStack)=>top(outStack)
	//and vice versa
	while(!inStack.isEmpty()){
		outStack.push(inStack.pop());
	}
	return outStack.peek();
}

// isEmpty
//   - returns a boolean which is true if the queue is empty, and false
//     otherwise
template<class T>
bool Queue<T>::isEmpty() const{
	//when both stacks are empty then True
	bool ret=inStack.isEmpty() && outStack.isEmpty();
	return ret;
}
