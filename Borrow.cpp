// Borrow.cpp : Implementation of the class Borrow
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

#include "Borrow.h"

Borrow::Borrow(Subscriber* subscriber, Book* book, unsigned int returnDate) : subscriber_(nullptr),
																			  book_(nullptr),
																			  returnDate_(0)
{
	subscriber_ = new Subscriber(); //&(*subscriber);
	book_ = new Book();//&(*book);
	returnDate_ = returnDate;	
}

// Copy ctor
Borrow::Borrow(const Borrow& borrow) : subscriber_(nullptr),
									   book_(nullptr),
									   returnDate_(0)
{
	//	Subscriber tmpSub
	subscriber_	= new Subscriber(borrow.subscriber_->getId(),
								 borrow.subscriber_->getFirstName(),
								 borrow.subscriber_->getLastName(),
								 borrow.subscriber_->getAge());
	// subscriber_ = &tmpSub;
	//	Book tmpBook
	book_ = new Book(borrow.book_->getQuote(),
					 borrow.book_->getTitle(),
					 borrow.book_->getAuthor(),
					 borrow.book_->getIsbn(),
					 borrow.book_->getYear(),
					 borrow.book_->getReaderMinimalAge(),
					 borrow.book_->getNsamples(),
					 borrow.book_->getNavalaibles());

	//book_ = &tmpBook;

	returnDate_ = borrow.returnDate_;
}

Borrow::Borrow(Borrow&& borrow)noexcept : subscriber_(nullptr),
										  book_(nullptr),
										  returnDate_(0)
{
	//Subscriber tmpSub
	subscriber_ = new Subscriber(borrow.subscriber_->getId(),
								 borrow.subscriber_->getFirstName(),
								 borrow.subscriber_->getLastName(),
								 borrow.subscriber_->getAge());
	//subscriber_ = &tmpSub;

	if (borrow.subscriber_ != nullptr) {
		delete borrow.subscriber_;
		borrow.subscriber_ = nullptr;
	}
	
	// Book tmpBook
	book_ = new Book(borrow.book_->getQuote(),
					 borrow.book_->getTitle(),
					 borrow.book_->getAuthor(),
					 borrow.book_->getIsbn(),
					 borrow.book_->getYear(),
					 borrow.book_->getReaderMinimalAge(),
					 borrow.book_->getNsamples(),
					 borrow.book_->getNavalaibles());

	// book_ = &tmpBook;

	if (borrow.book_ != nullptr) {
		delete borrow.book_;
		borrow.book_ = nullptr;
	}

	returnDate_ = borrow.returnDate_;

	borrow.returnDate_ = 0;
}

Borrow::~Borrow()
{
	delete subscriber_;
	subscriber_ = nullptr;

	delete book_;
	book_ = nullptr;
}

//! Copy assignment
Borrow& Borrow::operator=(const Borrow& borrow)
{
	if (this != &borrow) {

		if (subscriber_ != nullptr) {
			delete subscriber_;
			subscriber_ = nullptr;
		}

		//Subscriber tmpSub
		subscriber_ = new Subscriber(borrow.subscriber_->getId(),
									 borrow.subscriber_->getFirstName(),
									 borrow.subscriber_->getLastName(),
									 borrow.subscriber_->getAge());
		//subscriber_ = &tmpSub;

		if (book_ != nullptr) {
			delete book_;
			book_ = nullptr;
		}

		//Book tmpBook
		book_ = new Book(borrow.book_->getQuote(),
					 borrow.book_->getTitle(),
					 borrow.book_->getAuthor(),
					 borrow.book_->getIsbn(),
					 borrow.book_->getYear(),
					 borrow.book_->getReaderMinimalAge(),
					 borrow.book_->getNsamples(),
					 borrow.book_->getNavalaibles());
		
		//	book_ = &tmpBook;

		returnDate_ = borrow.returnDate_;
	}
	return *this;
}

//! Move assignment
Borrow& Borrow::operator=(Borrow&& borrow)noexcept
{
	if (this != &borrow) {

		if (subscriber_ != nullptr) {
			delete subscriber_;
			subscriber_ = nullptr;
		}

		//Subscriber tmpSub
		subscriber_ = new Subscriber(borrow.subscriber_->getId(),
									 borrow.subscriber_->getFirstName(),
									 borrow.subscriber_->getLastName(),
									 borrow.subscriber_->getAge());
		//subscriber_ = &tmpSub;

		if (borrow.subscriber_ != nullptr) {
			delete borrow.subscriber_;
			borrow.subscriber_ = nullptr;
		}

		if (book_ != nullptr) {
			delete book_;
			book_ = nullptr;
		}

		//Book tmpBook
		book_ = new Book(borrow.book_->getQuote(),
						 borrow.book_->getTitle(),
						 borrow.book_->getAuthor(),
						 borrow.book_->getIsbn(),
						 borrow.book_->getYear(),
						 borrow.book_->getReaderMinimalAge(),
						 borrow.book_->getNsamples(),
						 borrow.book_->getNavalaibles());
		
		//book_ = &tmpBook;

		if (borrow.book_ != nullptr) {
			delete borrow.book_;
			borrow.book_ = nullptr;
		}

		returnDate_ = borrow.returnDate_;
		borrow.returnDate_ = 0;
	}
	return *this;
}

Subscriber* Borrow::getSubscriber()const{return subscriber_;}
Book* Borrow::getBook()const{return book_;}
unsigned int Borrow::getReturnDate()const{return returnDate_;}

void Borrow::setSubscriber(Subscriber* subscriber)
{
	subscriber_ = &(*subscriber);
}

void Borrow::setBook(Book* book)
{
	book_ = &(*book);
}

void Borrow::setReturnDate(unsigned int returnDate)
{
	returnDate_ = returnDate;
}

void Borrow::print()const
{
	std::cout << returnDate_ << '\n';
	subscriber_->print();
	book_->print();
}
