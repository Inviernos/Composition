// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void):
	Array_Base<T>(N)
{

}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr):
	Array_Base<T>(N)
{
	for(int i = 0;i < N;i++)
	{
    // COMMENT There is no need to used scope resolution to call a base class
    // method unless there is a method in this class that has the same name.
	
	//I address this comment by getting rid of the scope resolution

	   set(i,arr.get(i));
	}
}



//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill):
	Array_Base<T>(N)
// COMMENT You should use call the appropriate base class contructor here.
// I address this comment by adding the appropriate base class contructor
{
	for(int i = 0; i < N;i++)
	{
    // COMMENT There is no need to used scope resolution to call a base class
    // method unless there is a method in this class that has the same name.

	// I address this comment by getting rid of the scope resolution

    // COMMENT You should try to find a way to access data_ directly since you
    // the sublcass could access it if necessary.

	// I address this comment by making data_ accessible so that the subclass 
	// can access it
		
		set(i,fill);
	}
}

//
// ~Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{
  // COMMENT There is no need to manually call the base class destructor. It
  // is called as part of the descruction call chain.

  // I address this comment by getting rid of that line of code since
 //  it will be called automatically
}

//
// operator =
//
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{
	if(this == &rhs)
	{
		return *this;
	}

	this->cur_size_ = rhs.size();

	for(int i = 0; i < N;i++)
	{
    // COMMENT There is no need to used scope resolution to call a base class
    // method unless there is a method in this class that has the same name.
    
	// I address this comment by getting rid of the scope resolution

    // COMMENT You should try to find a way to access data_ directly since you
    // the sublcass could access it if necessary.
	
	// I address this comment by making data_ accessible so that the subclass 
	// can access it

		this->data_[i] = rhs.get(i);
	}

	return *this;
}
