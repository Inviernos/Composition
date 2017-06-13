// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept>         // for std::out_of_bounds exception

#define DEFAULT_SIZE 10

//
// Array
//
template <typename T>
Array <T>::Array (void):
	Array_Base<T>(),
	max_size_ (DEFAULT_SIZE)
{
	
}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length):
	Array_Base<T>(length), 
	max_size_ (0)
{
	if(length == 0)
	{
		max_size_ = DEFAULT_SIZE;
	}
	else
	{
		max_size_ = length;
	}
}

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array (size_t length, T fill):
	Array_Base<T>(length,fill),
	max_size_ (0)
{

	if(length == 0)
	{
		this->max_size_ = DEFAULT_SIZE;
	}
	else
	{
		this->max_size_ = length;
	}

}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array):
	Array_Base<T>(array.cur_size),
	max_size_ (0)
{
	if(array.cur_size_ > 0)
	{
		max_size_ = array.cur_size_;
	}
	else
	{
		max_size_ = DEFAULT_SIZE;
	}

	
}

//
// ~Array
//
template <typename T>
Array <T>::~Array (void)
{
	//~Array_Base() will be called
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
	//Return this array if both array's are equal 
	if(this == &rhs)
	{
		return *this;
	}
	
	//set all variables related to array equal to rhs
	this->cur_size_ = rhs.size();

	max_size_ = rhs.max_size_;

	delete[] this->data_;

	this->data_ = new T[max_size_];

	//set all the data from rhs to this array
	for(int i = 0; i < this->cur_size; i++)
	{
		this->data_[i] = rhs.get(i);
	}

	return *this;
}

//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
	//Need to allocate more space for data
	if(new_size > max_size_)
	{
		//allocate a new array
		T *new_data_ = new T[new_size];
		
		//set all the data to the new array
		for(int i = 0;i < this->cur_size_;i++)
		{
			new_data_[i] = this->data_[i];
		}

		delete [] this->data_;

		//set variables to new size and data
		this->data_ = new_data_;
		
		this->cur_size_ = new_size;

		this->max_size_ = new_size;
	}
	else
	{
		this->cur_size_ = new_size;	
	}
		
}
