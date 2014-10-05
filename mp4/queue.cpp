template<class T>
void Queue<T>::enqueue(T const & newItem)
{
inStack.push(newItem);
}
 
template<class T> 
T Queue<T>::dequeue()
{

	if(outStack.isEmpty() )
		{
		while (!inStack.isEmpty() )
			{
			outStack.push(inStack.peek());
			inStack.pop();
			}
			
		T temp=outStack.peek();
		outStack.pop();
		return temp;
		}
		
	else 
		{
		T temp=outStack.peek();
		outStack.pop();
		return temp;
		}
}


template<class T>
T Queue<T>::peek()
{
	if(outStack.isEmpty() )
		{
		while (!inStack.isEmpty() )
			{
			outStack.push(inStack.peek());
			inStack.pop();
			}
			
		return outStack.peek();

		}
	
	else return outStack.peek();
}

template<class T>
bool Queue<T>::isEmpty() const
{
	if(outStack.isEmpty() && inStack.isEmpty() ) return true;
	else return false;
		
		
}
