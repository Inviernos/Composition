// -*- C++ -*-
// $Id: Queue.h 

//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS507_QUEUE_H_
#define _CS507_QUEUE_H_

#include <exception>
#include "Array.h"


/**
 * @class Queue
 *
 * Basic Queue for abitrary elements.
 */
template <typename T>
class Queue
{
public:
  /// Type definition of the type.
  typedef T type;

  /**
   * @class empty_exception
   *
   * Exception thrown to indicate the queue is empty.
   */
 
  class empty_exception : public std::exception
  {
	  public:
		/// Default constructor.
		empty_exception (void)
		: std::exception () { }

  };

  /// Default constructor.
  Queue (void);

  /// Copy constructor.
  Queue (const Queue & Q);

  /// Destructor.
  ~Queue (void);
  
  //operation overloading
  const Queue & operator = (const Queue & rhs);

  //adds the element to the end of the list
  void enqueue (T element);
 
 //removes the element at the front of the list
  T dequeue();

  //Test if the queue is empty
  bool is_empty (void) const;

  //number of elements in queue
  size_t size (void) const;

  /// Remove all elements from the queue.
  void clear (void);

private:
  // add member variable here
	int front;

	int back;

	size_t cur_size;
	
	Array<T> list;
};

// include the inline files
#include "Queue.inl"

// include the source file since template class
#include "Queue.cpp"

#endif  // !defined _CS507_QUEUE_H_
