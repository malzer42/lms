// Book.cpp : Implementation of the class Book
/*
  Defining the class Book using the C++ Programming Special Edition of B. Stroutrup 
  Usage of the STL containers and algorithms: array, map , vector , map , etc.

  *\ Author(s) : Pierre Abraham Mulamba, Ph.D.
  *\ Date of creation (modification) : 20171027 (20171028)
*/
/********************************************************************************
 Copyright (c) 2017, IOSS, inc.
 All rights reserved

********************************************************************************/

#include "Book.h"

Book Book::default_book_("Default Book", "Class Book", "Pierre Mulamba", "2017-10-31",
						 2017, 16, 1000, 1);

Book::Book(const std::string& quote, const std::string& title,
		   const std::string& author, const std::string& isbn,
		   unsigned int year, unsigned int readerMinimalAge,
		   unsigned int nSamples, unsigned int nAvailables)
{
	const unsigned int max_age = 100;
	const unsigned int min_age = 0;

	if(readerMinimalAge < min_age || max_age < readerMinimalAge) throw BadBook();

	quote_ = (quote == "") ? default_book_.quote_ : quote;
	title_ = (title == "") ? default_book_.title_ : title;
	author_ = (author == "") ? default_book_.author_ : author;
	isbn_ = (isbn == "") ? default_book_.isbn_ : isbn;
	
	year_ = (year < 2017) ? default_book_.year_ : year;
	readerMinimalAge_ = (readerMinimalAge == 0) ? default_book_.readerMinimalAge_ : readerMinimalAge;
	nSamples_ = (nSamples == 0) ? default_book_.nSamples_ : nSamples;
	nAvailables_ = (nAvailables == 0) ? default_book_.nAvailables_ : nAvailables;
		
}

Book::~Book(){}

// copy ctor
Book::Book(const Book& book) : quote_(book.quote_), title_(book.title_),
							   author_(book.author_), isbn_(book.isbn_),
							  year_(book.year_), readerMinimalAge_(book.readerMinimalAge_),
							  nSamples_(book.nSamples_), nAvailables_(book.nAvailables_){}

// copy assignment operator
Book& Book::operator=(const Book& book)
{
	if (this != &book) {
		quote_ = book.quote_;
		title_ = book.title_;
		author_ = book.author_;
		isbn_ = book.isbn_;
		year_ = book.year_;
		readerMinimalAge_ = book.readerMinimalAge_;
		nSamples_ = book.nSamples_;
		nAvailables_ = book.nAvailables_;
	}
	return *this;
}

// Move constructor
Book::Book(Book&& book) noexcept : quote_(""), title_(""), author_(""), isbn_(""),
								  year_(0), readerMinimalAge_(0), nSamples_(0),
								  nAvailables_(0)
{
	quote_ = book.quote_;
	title_ = book.title_;
	author_ = book.author_;
	isbn_ = book.isbn_;
	year_ = book.year_;
	readerMinimalAge_ = book.readerMinimalAge_;
	nSamples_ = book.nSamples_;
	nAvailables_ = book.nAvailables_;

	book.quote_ = "";
	book.title_ = "";
	book.author_ = "";
	book.isbn_ = "";
	book.year_ = 0 ; 
	book.readerMinimalAge_ = 0 ;
	book.nSamples_ = 0; 
	book.nAvailables_ = 0 ; 
}

// Move assignment operator
Book& Book::operator=(Book &&book) noexcept
{
	quote_ = "";
	title_ = "";
	author_ = "";
	isbn_ = "";
	year_ = 0;
	readerMinimalAge_ = 0;
	nSamples_ = 0;
	nAvailables_ = 0;
	
	
	
	if(this != &book){
		quote_ = book.quote_;
		title_ = book.title_;
		author_ = book.author_;
		isbn_ = book.isbn_;
		year_ = book.year_;
		readerMinimalAge_ = book.readerMinimalAge_;
		nSamples_ = book.nSamples_;
		nAvailables_ = book.nAvailables_;

		book.quote_ = "";
		book.title_ = "";
		book.author_ = "";
		book.isbn_ = "";
		book.year_ = 0 ; 
		book.readerMinimalAge_ = 0 ;
		book.nSamples_ = 0; 
		book.nAvailables_ = 0 ; 

	}
	return *this;
	
}


std::string Book::getQuote()const{return quote_;}
std::string Book::getTitle()const{return title_;}
std::string Book::getAuthor()const{return author_;}
std::string Book::getIsbn()const{return isbn_;}
unsigned int Book::getYear()const{return year_;}
unsigned int Book::getReaderMinimalAge()const{return readerMinimalAge_;}
unsigned int Book::getNsamples()const{return nSamples_;}
unsigned int Book::getNavalaibles()const{return nAvailables_;}

void Book::setQuote(const std::string& quote){quote_.assign(quote);}
void Book::setTitle(const std::string& title){title_.assign(title);}
void Book::setAuthor(const std::string& author){author_.assign(author);}
void Book::setIsbn(const std::string& isbn){isbn_.assign(isbn);}
void Book::setYear(unsigned int year){year_ = year;}
void Book::setReaderMiminalAge(unsigned int readerMinimalAge){readerMinimalAge_ = readerMinimalAge;}
void Book::setNsamples(unsigned int nSamples){nSamples_ = nSamples;}
void Book::setNavalaibles(unsigned int nAvailables){nAvailables_ = nAvailables;}

void Book::setDefault(const std::string& quote, const std::string& title, const std::string& author,
					  const std::string& isbn, unsigned int year, unsigned int readerMinimalAge,
					  unsigned int nSamples, unsigned int nAvailables)
{
	Book::default_book_ = Book(quote, title, author, isbn, year, readerMinimalAge, nSamples, nAvailables);
	
}

void Book::print()const
{
	std::cout << title_ << ' '
			  << "By " << author_ << ' '
			  << quote_ << ' '
			  << year_ << ' '
			  << isbn_ << '\n';
}
