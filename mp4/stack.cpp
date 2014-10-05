template <class T>
void Stack<T>::push(T const & newItem)
{
myStack.push_front(newItem);
}
   
   
   
template <class T>
T Stack<T>::pop()
{
T temp = myStack.front();
myStack.pop_front();

return temp;
//either make T not a pointer and return address& of temp
//or leave as is
//or use iterator front

//myStack<T>.front()?????
}



template <class T>
T Stack<T>::peek() const
{
return myStack.front();
}




template <class T>
bool Stack<T>::isEmpty() const
{
if (myStack.size()==0) return true;
else return false;
}
