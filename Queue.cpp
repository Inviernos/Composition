// $Id: Queue.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.



template <typename T>
Queue <T>::Queue (void): 
	front (0),
	back (0),
	cur_size (0),
	list(10)
{

}


template <typename T>
Queue <T>::Queue (const Queue & queue):
	front (0),
	back (0),
	cur_size (0),
	list(0)
{
	front = queue.front;
	back = queue.back;
	cur_size = queue.cur_size;
	list = queue.list;
}

//
// ~Queue
//
template <typename T>
Queue <T>::~Queue (void)
{
  // COMMENT There is no need to manually call a destructor on a
  // member variable. All destructors of an object are called
  // automatically as part of the destruction process.
  
  //I address this comment by letting the deconstructer be called
  //automatically
}


template <typename T>
void Queue <T>::enqueue (T element)
{
  // COMMENT The queue will fail if the array runs out of space. Since this
  // is an unboudned queue, you need to resize the array to make space for
  // new elements. Also, make sure you do not waste any space if you must
  // resize the array to accommodate new elements. This will require updates
  // to your dequeue method.

  //I address this comment by resizing the array when the queue has reached
  //its limit and need to resize.

	//Front and back needs to be reset when queue is empty
	if(is_empty())
	{
		front = 0;
		back = 0;
		cur_size = 0;
	}

	//Queue needs to be resize
	if(cur_size == size())
	{
		
		list.resize(list.size()+10);
	}

	list[back++] = element;
	
	cur_size++;
}


template <typename T>
T Queue <T>::dequeue ()
{	
	//There is nothing to dequeue
	if(is_empty())
	{
		throw empty_exception();
	}
	
	cur_size--;

	return list[front++];	
}


template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
	//this queue is equal to rhs
	if(this == &rhs)
	{
		return *this;
	}
  
  // COMMENT Make sure you copy over the elements from rhs.
  // I address this comment by copying the elements from rhs to this

	//set the variables of this queue equal to rhs
	list = rhs.list;

	front = rhs.front;

	back = rhs.back;

	cur_size = rhs.cur_size;

	return *this;
}

//
// clear
//

template <typename T>
void Queue <T>::clear (void)
{
	front = 0;
	back = 0;
	cur_size = 0;
}
