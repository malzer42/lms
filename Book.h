// Book.h : Interface of the class Book
/*
  Defining the class Book using the C++ Programming Language Special Ed. by B. Stroutrup 
  Usage of the STL containers and algorithms: array, map , vector , map , etc.

  *\ Author(s) : Pierre Abraham Mulamba, Ph.D.
  *\ Date of creation (modification) : 20171027 (20171028)
*/
/********************************************************************************
 Copyright (c) 2017, IOSS, inc.
 All rights reserved

********************************************************************************/
#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

class Book
{
public: // interface

	Book(const std::string& quote = "quote", const std::string& title = "title",
		 const std::string& author = "author", const std::string& isbn ="isbn",
		 unsigned int year_ = 2017, unsigned int readerMinimalAge = 0,
		 unsigned int nSample = 0, unsigned int nAvailables = 0 );    	//! Default ctor

	Book(const Book& book);  //! Copy ctor
	Book(Book&& book) noexcept;  //! Move ctor
	virtual ~Book() noexcept;   //! Destructor
	Book& operator=(const Book& book);  //! Copy assignment operator
	Book& operator=(Book &&book) noexcept; 	//! Move assignment operator

	
	class BadBook{
	public:
		const std::string exceptionMessage = "Unable to create the book";
	}; // for handling exception
	
	// function for examining Book
	std::string getQuote()const;
	std::string getTitle()const;
	std::string getAuthor()const;
	std::string getIsbn()const;
	unsigned int getYear()const;
	unsigned int getReaderMinimalAge()const;
	unsigned int getNsamples()const;
	unsigned int getNavalaibles()const;

	// functions for changing the book
	static void setDefault(const std::string& quote, const std::string& title, const std::string& author,
						   const std::string& isbn, unsigned int year,  unsigned int readerMinimalAge,
						   unsigned int nSamples, unsigned int nAvailables);

	void setQuote(const std::string& quote);
	void setTitle(const std::string& title);
	void setAuthor(const std::string& author);
	void setIsbn(const std::string& isbn);
	void setYear(unsigned int year);
	void setReaderMiminalAge(unsigned int readerMinimalAge);
	void setNsamples(unsigned int nSamples);
	void setNavalaibles(unsigned int nAvailables);
	
	
	// function for printing
	void print()const;
	

protected:
private: // representation
	std::string quote_; // "may the force be with you"
	std::string title_; // "The C++ Programming Special Edition"
	std::string author_; // "Bjarne Stroustrup"
	std::string isbn_;  // 0-201-88954-4
	unsigned int year_;
	unsigned int readerMinimalAge_; // 16
	unsigned int nSamples_; // e.g. 100
	unsigned int nAvailables_; // e.g. 4
	static Book default_book_; // default_book_("Live Long and Prosper", "Bible","Louis Second", ...)
};




#endif /* BOOK_H */
