// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack
//
template <typename T>
Stack <T>::Stack (void): 
	tops (-1),
	items(10)
{

}

//
// Stack (const Stack & stack)
//
template <typename T>
Stack <T>::Stack (const Stack & stack):
	tops (-1),
	items (0)
{
	tops = stack.tops;
	
	items = stack.items;
}

//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{
  // COMMENT There is no need to manually call a destructor on a member variable.
  // All destructors of an object are called automatically as part of the destruction
  // process.
	
  // I address this comment by deleting the line of code and letting the deconstructor
  // be called automatically
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{
	tops += 1;

	items[tops] = element;

}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
	//The stack is empty
	if(tops == -1)
	{
		throw empty_exception();
	}

	tops -= 1;
}

//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	//The two stacks are equal to each other
	if(this == &rhs)
	{
		return *this;
	}

	//set the variables of stack to rhs
	tops = rhs.tops;

	items = rhs.items;

	return *this;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
	while(!is_empty())
	{
		this->pop();
	}
}
