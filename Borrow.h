// Borrow.h : Inter of the class Borrow
/*
  Defining the class Borrow using the C++ Programming Language Special Ed. by B. Stroustrup
  This class serve to borrow a book from the Library
  Usage of the STL containers and algorithms: array, map, vector, ect.

  *\ Author(s) : Pierre Abraham Mulamba, Ph.D.
  *\ Date of creation (modification) : 20171117 (20171117)
*/
/********************************************************************************
 Copyright (c) 2017, IOSS, inc.
 All rights reserved
********************************************************************************/

#ifndef BORROW_H
#define BORROW_H

#include <iostream>
#include "Subscriber.h"
#include "Book.h"

class Borrow
{
public: // Interface
	Borrow(Subscriber* subscriber = nullptr, Book* book = nullptr,
		   unsigned int returnDate= 0);//! Default constructor
	Borrow(const Borrow& borrow);//! Copy constructor
	Borrow(Borrow&& borrow) noexcept;//! Move constructor
	virtual ~Borrow() noexcept;//! Destructor
	Borrow& operator=(const Borrow& borrow);//! Copy assignment operator
	Borrow& operator=(Borrow&& borrow) noexcept;//! Move assignment operator

	class BadBorrow{
	public:
		const std::string exceptionMessage = "Unable to borrow a book";
	};

	// Accessors
	Subscriber* getSubscriber()const;
	Book* getBook()const;
	unsigned int getReturnDate()const;
	
	// Mutators
	void setSubscriber(Subscriber* subscriber);
	void setBook(Book* book);
	void setReturnDate(unsigned int returnDate);


	// function for printing
	void print()const;
		

private: // Representation 
	Subscriber* subscriber_;
	Book* book_;
	unsigned int returnDate_;

};


#endif /* BORROW_H */
