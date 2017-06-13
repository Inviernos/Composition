// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array_Base.h"
#include <stdexcept>         // for std::out_of_bounds exception

#define DEFAULT_SIZE 10

//
// Array_Base
//
template <typename T>
Array_Base <T>::Array_Base (void):
	data_ (0), 
	cur_size_ (0)
{
	data_ = new T[DEFAULT_SIZE];
}

//
// Array_Base (size_t)
//
template <typename T>
Array_Base <T>::Array_Base (size_t length):
	data_ (0), 
	cur_size_ (0)
{
	//allocate space for the array
	if(length == 0)
	{
		data_ = new T[DEFAULT_SIZE];
	}
	else
	{
		data_ = new T[length];
	}

	cur_size_ = length;
}

//
// Array_Base (size_t, char)
//
template <typename T>
Array_Base <T>::Array_Base (size_t length, T fill):
	data_ (0), 
	cur_size_ (0)
{
	//allocate space for the array
	if(length == 0)
	{
		data_ = new T[DEFAULT_SIZE];
	}
	else
	{
		data_ = new T[length];
	}
	
	cur_size_ = length;

	this->fill(fill);
}

//
// Array_Base (const Array &)
//
template <typename T>
Array_Base <T>::Array_Base (const Array_Base & array):
	data_ (0), 
	cur_size_ (0)
{
	//allocate space for the array
	if(array.cur_size_ > 0)
	{
		data_ = new T[cur_size_];
	}
	else
	{
		data_ = new T[DEFAULT_SIZE];
	}

	cur_size_ = array.cur_size_;	

	//set all the data equal to this array
	for(int i = 0;i < array.cur_size_;i++)
	{
		data_[i] = array.data_[i];
	}
}

//
// ~Array_Base
//
template <typename T>
Array_Base<T>::~Array_Base (void)
{
	delete [] data_;

	data_ = 0;
}


//
// operator []
//
template <typename T>
T & Array_Base <T>::operator [] (size_t index)
{
	//Array went out of bounds
	if(index >= cur_size_)
	{
		throw std::out_of_range("Invalid Index");
	}

	return data_[index];	
}

//
// operator [] 
//
template <typename T>
const T & Array_Base <T>::operator [] (size_t index) const
{
	//Array went out of bounds
	if(index >= cur_size_)
	{
		throw std::out_of_range("Invalid Index");
	}

	return data_[index];	
}

//
// get
//
template <typename T>
T Array_Base <T>::get (size_t index) const
{
	//Array went out of bounds
	if(index >= cur_size_)
	{
		throw std::out_of_range("Invalid Index");
	}

	return data_[index];
}

//
// set
//
template <typename T>
void Array_Base <T>::set (size_t index, T value)
{
	//Array went out of bounds
	if(index >= cur_size_)
	{
		throw std::out_of_range("Invalid Index");
	}

	data_[index] = value;
}


//
// find (T)
//
template  <typename T>
int Array_Base <T>::find (T value) const
{
	try
	{
		return find(value,0);
	}
	catch(std::out_of_range)
	{

	}
	
	return -1;
}

//
// find (T, size_t) 
//
template <typename T>
int Array_Base <T>::find (T val, size_t start) const
{
	//Array went out of bounds
	if(start >= cur_size_)
	{
		throw std::out_of_range("Invalid Index");
	}
	
	//search through the array for given value
	for(int i = start; i < cur_size_;i++)
	{
		if(data_[i] == val)
		{
			return i;
		}
	}
	
	return -1;
}

//
// operator ==
//
template <typename T>
bool Array_Base <T>::operator == (const Array_Base & rhs) const
{
	//The data of arrays are equal to each other
	if(this->cur_size_ == rhs.cur_size_)
	{
		for(int i = 0;i<cur_size_;i++)
		{
			if(data_[i] != rhs.data_[i])
			{
				return false;
			}	
		}
	}
	else
	{
		return false;
	}
}

//
// operator !=
//
template <typename T>
bool Array_Base <T>::operator != (const Array_Base & rhs) const
{
	return (!((*this) == rhs));
}

//
// fill
//
template <typename T>
void Array_Base <T>::fill (T value)
{
	//set all values of array to the given value
	for(int i = 0;i < cur_size_;i++)
	{
		data_[i] = value;
	}
}
