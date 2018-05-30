// Library.h : Interface of the Library class
/*
  Defining the class Library using the C++ Programming Special Edition of B. Stroutrup 
  Usage of the STL containers and algorithms: array, map , vector , map , etc.

  *\ Author(s) : Pierre Abraham Mulamba, Ph.D.
  *\ Date of creation (modification) : 20171027 (20171028)
*/
/********************************************************************************
 Copyright (c) 2017, IOSS, inc.
 All rights reserved

********************************************************************************/

#ifndef LIBRARY_H
#define LIBRARY_H

#include <cstdio>
#include <algorithm>
#include <vector>
#include "Subscriber.h"
#include "Book.h"
#include "Borrow.h"

const unsigned int totalSubscribers = 100;
const unsigned int totalBooks = 1000;
const unsigned int totalBorrows = 200;

unsigned int getTotalSubscribers(const unsigned int totalSubs);
unsigned int getTotalBooks(const unsigned int totalBooks);
unsigned int getTotalBorrows(const unsigned int totalBorrows);

class Library
{
public: // Interface

	// Big 5
	Library(); //! Default ctor
	Library(const Library& library); 	//! Copy ctor
	Library(Library&& library) noexcept; 	//! Move ctor
	virtual ~Library() noexcept; 	//! Dtor
	Library& operator=(const Library& library); // Copy assigment operator  
	Library& operator=(Library&& library) noexcept; // Move assignment operator

	// Accessors
	Book** getBooks()const;
	unsigned int getNbooks()const;

	
	//void searchAuthor(const std::sring& author);
    //void searchIsbn(const std::string& isbn);
	//void searchYear(unsigned inst year);
	
	// Mutators
	void setNbooks(unsigned int nBooks);


	// Utility functions
	void addSubscriber(Subscriber& subscriber);
	void withdrawSubscriber(const std::string& id);
	void infoSubscriber(const std::string& id);

	void print()const; // Mainly used to check any update on the libary like addidng or withdrawing elt
	
	void addBook(Book* book);
	void withdrawBook(const std::string& quote); // after withdrawing the book will be deleted
	void searchTitle(const std::string& title);
	void searchQuote(const std::string& quote);
	bool borrowBook(const std::string& id, const std::string& quote, unsigned int returnDate);
	bool returnBook(const std::string& id, const std::string& quote);
	
protected:
private: // Representation
	Subscriber** subscribers_;

	std::vector<Subscriber> vecSubscribers_;
	std::vector<Subscriber*> vecPtrSubscribers_;
	unsigned int nSubscribers_;
	
	Book** books_;
	std::vector<Book> vecBooks_;
	std::vector<Book*> vecPtrBooks_;
	unsigned int nBooks_;

	Borrow** borrows_;
	unsigned int nBorrows_;

};

#endif /* LIBRARY_H */
