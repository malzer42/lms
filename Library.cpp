// Library.cpp : Implementation of the class Library
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

#include "Library.h"

unsigned int getTotalSubscribers(const unsigned int totalSubs){return totalSubs;}
unsigned int getTotalBooks(const unsigned int totalBooks){return totalBooks;}
unsigned int getTotalBorrows(const unsigned int totalBorrs){return totalBorrs;}

//1. Default ctor
Library::Library() : subscribers_(nullptr), nSubscribers_(0),
					 books_(nullptr), nBooks_(0),
					 borrows_(nullptr), nBorrows_(0)
{
	subscribers_ = new Subscriber*[getTotalSubscribers(totalSubscribers)];
	for(unsigned int i = 0; i < getTotalSubscribers(totalSubscribers); i++)
		subscribers_[i] = nullptr;

	std::vector<Subscriber> vecSubscribers_(getTotalSubscribers(totalSubscribers));
	std::vector<Subscriber*> vecPtrSubscribers_(getTotalSubscribers(totalSubscribers));
	
	books_ = new Book*[getTotalBooks(totalBooks)];
	for (unsigned int i = 0; i < getTotalBooks(totalBooks); i++) {
		books_[i] = nullptr;
	}

	std::vector<Book> vecBooks_(getTotalBooks(totalBooks));
	std::vector<Book*> vecPtrBooks_(getTotalBooks(totalBooks));

	borrows_ = new Borrow*[getTotalBorrows(totalBorrows)];
	for (unsigned int i = 0; i < getTotalBorrows(totalBorrows); i++) {
		borrows_[i] = nullptr;
	}

}

//2. Copy ctor; deep copy
Library::Library(const Library& library) : subscribers_(nullptr), nSubscribers_(0),
										   books_(nullptr), nBooks_(0),
										   borrows_(nullptr), nBorrows_(0)
{
	subscribers_ = new Subscriber*[library.nSubscribers_];
	for (unsigned int i = 0 ; i < library.nSubscribers_; i++)
	{

		//Subscriber tmpSub
		Subscriber* sub = new Subscriber(library.subscribers_[i]->getId(),
										 library.subscribers_[i]->getFirstName(),
										 library.subscribers_[i]->getLastName(),
										 library.subscribers_[i]->getAge());

		subscribers_[nSubscribers_++] = &(*sub);//tmpSub;
		vecSubscribers_[i] = *sub;//tmpSub; 
		vecPtrSubscribers_[i] = sub;//&tmpSub;
	}

	
	books_ = new Book*[library.nBooks_];
	for (unsigned int i = 0 ; i < library.nBooks_; i++)
	{
		Book tmpBook = Book(library.books_[i]->getQuote(),
						library.books_[i]->getTitle(),
						library.books_[i]->getAuthor(),
						library.books_[i]->getIsbn(),
						library.books_[i]->getYear(),
						library.books_[i]->getReaderMinimalAge(),
						library.books_[i]->getNsamples(),
						library.books_[i]->getNavalaibles());

		books_[nBooks_++] = &tmpBook;

		vecBooks_[i] = tmpBook;
		vecPtrBooks_[i] = &tmpBook;
	}

	borrows_ = new Borrow*[library.nBorrows_];
	for (unsigned int i = 0; i < library.nBorrows_; i++) {
		Borrow tmpBor = Borrow(library.borrows_[i]->getSubscriber(),
							   library.borrows_[i]->getBook(),
							   library.borrows_[i]->getReturnDate());
		borrows_[nBorrows_++] = &tmpBor;
	}
}

//3. Move ctor
Library::Library(Library&& library)noexcept : subscribers_(nullptr), nSubscribers_(0),
											  books_(nullptr), nBooks_(0),
											  borrows_(nullptr), nBorrows_(0)
{
	subscribers_ = new Subscriber*[library.nSubscribers_];
	for (unsigned int i = 0; i < library.nSubscribers_; i++)
	{
		Subscriber tmpSub  = Subscriber(library.subscribers_[i]->getId(),
										library.subscribers_[i]->getFirstName(),
										library.subscribers_[i]->getLastName(),
										library.subscribers_[i]->getAge());

		subscribers_[nSubscribers_++] = &tmpSub;

		if (library.subscribers_[i] != nullptr) {
			delete library.subscribers_[i];
			library.subscribers_[i] = nullptr;
		}
		
	}


	if (library.subscribers_ != nullptr) {
		delete [] library.subscribers_;
		library.subscribers_ = nullptr;
	}
	library.nSubscribers_ = 0;
	
	
	books_ = new Book*[library.nBooks_];
	for (unsigned int i = 0; i < library.nBooks_; i++)
	{
		Book tmpBook = Book(library.books_[i]->getQuote(),
							library.books_[i]->getTitle(),
							library.books_[i]->getAuthor(),
							library.books_[i]->getIsbn(),
							library.books_[i]->getYear(),
							library.books_[i]->getReaderMinimalAge(),
							library.books_[i]->getNsamples(),
							library.books_[i]->getNavalaibles());

		books_[nBooks_++] = &tmpBook;

		if (library.books_[i] != nullptr) {
			delete library.books_[i];
			library.books_[i] = nullptr;
		}
	}

	if (library.books_ != nullptr) {
		delete [] library.books_;
		library.books_ = nullptr;
	}
	library.nBooks_ = 0;

	borrows_ = new Borrow*[library.nBorrows_];
	for (unsigned int i = 0; i < library.nBorrows_; i++) {
		Borrow tmpBor = Borrow(library.borrows_[i]->getSubscriber(),
							   library.borrows_[i]->getBook(),
							   library.borrows_[i]->getReturnDate());

		borrows_[nBorrows_++] = &tmpBor;
		if (library.borrows_[i] != nullptr) {
			delete library.borrows_[i];
			library.borrows_[i] = nullptr;
		}
	}

	if (library.borrows_ != nullptr) {
		delete [] library.borrows_;
		library.borrows_ = nullptr;
	}

	library.nBorrows_ = 0;

}

//4. Dtor
Library::~Library()
{
	delete [] subscribers_;
	delete [] books_;
	delete [] borrows_;
}

//5. Copy assignment
Library& Library::operator=(const Library& library)
{

    if (this != &library)     // Check for self-assignment!
	{
		if (subscribers_ != nullptr) {
			delete []  subscribers_;
			subscribers_ = nullptr;
		}

		nSubscribers_ = 0;
		subscribers_ = new Subscriber*[library.nSubscribers_];
		for (unsigned int i = 0; i < library.nSubscribers_; i++)
		{
			
			Subscriber tmpSub  = Subscriber(library.subscribers_[i]->getId(),
											library.subscribers_[i]->getFirstName(),
											library.subscribers_[i]->getLastName(),
											library.subscribers_[i]->getAge());
			
			subscribers_[nSubscribers_++] = &tmpSub;
		}
			
		
		if (books_ != nullptr) {
			delete [] books_;
			books_ = nullptr;
		}
	
		nBooks_ = 0;

		books_ = new Book*[library.nBooks_];
		for(unsigned int i = 0; i < library.nBooks_; i++)
		{
			Book tmpBook = Book(library.books_[i]->getQuote(),
										 library.books_[i]->getTitle(),
										 library.books_[i]->getAuthor(),
										 library.books_[i]->getIsbn(),
										 library.books_[i]->getYear(),
										 library.books_[i]->getReaderMinimalAge(),
										 library.books_[i]->getNsamples(),
										 library.books_[i]->getNavalaibles());
			books_[nBooks_++] = &tmpBook;
		}

		if (borrows_ != nullptr) {
			delete [] borrows_;
			borrows_ = nullptr;
		}


		nBorrows_ = 0;

		borrows_ = new Borrow*[library.nBorrows_];
		for (unsigned int i = 0; i < library.nBorrows_; i++) {
		Borrow tmpBor = Borrow(library.borrows_[i]->getSubscriber(),
							   library.borrows_[i]->getBook(),
							   library.borrows_[i]->getReturnDate());

		borrows_[nBorrows_++] = &tmpBor;
		}
	}

	return *this;
}

//6.  Move assignemet
Library& Library::operator=(Library&& library)noexcept
{
	if (this != &library) {

		if (subscribers_ != nullptr) {
			delete []  subscribers_;
			subscribers_ = nullptr;
		}
		
		nSubscribers_ = 0;

		subscribers_ = new Subscriber*[library.nSubscribers_];
		for (unsigned int i = 0; i < library.nSubscribers_; i++)
		{
			Subscriber tmpSub = Subscriber(library.subscribers_[i]->getId(),
										   library.subscribers_[i]->getFirstName(),
										   library.subscribers_[i]->getLastName(),
										   library.subscribers_[i]->getAge());
			
			subscribers_[nSubscribers_++] = &tmpSub;

			if (library.subscribers_[i] != nullptr) {
				delete library.subscribers_[i];
				library.subscribers_[i] = nullptr;
			}
		}

		if (library.subscribers_ != nullptr) {
			delete [] library.subscribers_;
			library.subscribers_ = nullptr;
		}

		library.nSubscribers_ = 0;

		if (books_ != nullptr) {
			delete [] books_;
			books_ = nullptr;
		}

		nBooks_ = 0;

		books_ = new Book*[library.nBooks_];
		for (unsigned int i = 0; i < library.nBooks_; i++)
		{
			Book tmpBook = Book(library.books_[i]->getQuote(),
								library.books_[i]->getTitle(),
								library.books_[i]->getAuthor(),
								library.books_[i]->getIsbn(),
								library.books_[i]->getYear(),
								library.books_[i]->getReaderMinimalAge(),
								library.books_[i]->getNsamples(),
								library.books_[i]->getNavalaibles());
			
			books_[nBooks_++] = &tmpBook;

			if (library.books_[i] != nullptr) {
				delete library.books_[i]; 
				library.books_[i] = nullptr;
			}
		}
	
		if (library.books_ != nullptr) {
			delete [] library.books_;
			library.books_ = nullptr;
		}

		library.nBooks_ = 0;

		if (borrows_ != nullptr) {
			delete [] borrows_;
			borrows_ = nullptr;
		}

		nBorrows_ = 0;

		borrows_ = new Borrow*[library.nBorrows_];
		for (unsigned int i = 0; i < library.nBorrows_; i++) {
			Borrow tmpBor = Borrow(library.borrows_[i]->getSubscriber(),
								   library.borrows_[i]->getBook(),
								   library.borrows_[i]->getReturnDate());
			
			borrows_[nBorrows_++] = &tmpBor;
			if (library.borrows_[i] != nullptr) {
				delete library.borrows_[i];
				library.borrows_[i] = nullptr;
			}
		}

		if (library.borrows_ != nullptr) {
			delete [] library.borrows_;
			library.borrows_ = nullptr;
		}

		library.nBorrows_ = 0;
	}

	return *this;
}


Book** Library::getBooks()const{return books_;}
unsigned int Library::getNbooks()const{return nBooks_;}
void Library::setNbooks(unsigned int nBooks){ nBooks_ = nBooks;}

void Library::addSubscriber(Subscriber& subscriber)
{
	subscribers_[nSubscribers_++] = &subscriber;
	
}


void Library::withdrawSubscriber(const std::string& id)
{
	for (unsigned int i = 0 ; i < nSubscribers_; i++)
	{
		if (subscribers_[i]->getId() == id)
		{
			subscribers_[i] = &(*subscribers_[nSubscribers_ -1]);

			if (subscribers_[nSubscribers_ -1] != nullptr)
			{
				delete subscribers_[nSubscribers_ -1];
				subscribers_[nSubscribers_ - 1] = nullptr;
			}

			nSubscribers_--;
		}
	}
}


void Library::addBook(Book* bookptr)
{
	books_[nBooks_++] = &(*bookptr);
}


void Library::withdrawBook(const std::string& quote)
{
	bool isFound = false;
	for (unsigned int i = 0 ; i < nBooks_; i++)
	{

		if (books_[i]->getQuote() == quote)
		{
			isFound = true;
			books_[i] = &(*books_[nBooks_ -1 ]);

			if (books_[nBooks_ - 1] != nullptr) {
				delete books_[nBooks_ - 1]; 
				books_[nBooks_ - 1] = nullptr;
			}

			nBooks_--;
		}
	}
	
	if(!isFound) std::cout <<"\nATTENTION! NO BOOK QUOTE MATCH : " << quote << " \n";
}

void Library::searchTitle(const std::string& title)
{
	bool isFound = false;
	for(unsigned int i = 0; i < nBooks_; i++)
	{

		std::size_t found = books_[i]->getTitle().find(title);

		if (found != std::string::npos)
		{
			isFound = true;
			std::cout << books_[i]->getTitle() << '\n';
			
		}
	}
	if (!isFound) std::cout << "\nATTENTION! NO BOOK TITLE MATCH :  " << title << " \n";
}

void Library::searchQuote(const std::string& quote)
{
	bool isFound = false;
	for(unsigned int i = 0; i < nBooks_; i++)
	{
		std::size_t found = books_[i]->getQuote().find(quote);
		
		if (found != std::string::npos)
		{
			isFound = true;
			books_[i]->print();
			break;
		}
	}

	if (!isFound) std::cout << "\nATTENTION! NO BOOK QUOTE MATCH : " << quote << " \n";
}



void Library::print()const
{
	std::cout << "\nThe Library has : " << nSubscribers_ <<" Subscriber(s)"
			  << " and " << nBooks_ << " Book(s)\n";
	std::cout << "\nPRINTING THE SUBSCRIBERS ADDED TO THE LIBRARY...\n";
	for (unsigned int i = 0; i < nSubscribers_; i++)
	{
		std::cout << i+1 << ". ";
		subscribers_[i]->print();
	}

	std::cout << "\nPRINTINT THE BOOKS ADDED TO THE LIBRARY...\n";
	for (unsigned int i = 0; i < nBooks_; i++)
	{
		std::cout << i+1 << ". ";
		books_[i]->print();
	}
}

bool Library::borrowBook(const std::string& id, const std::string& quote, unsigned int returnDate)
{
	std::cout << "\nLog: Entering the borrowBook method of the class Library\n";
	
	bool hasBook = false;
	bool isBorrowed = false;
	const unsigned int maxNumberToBorrow = 2;
	unsigned int counterBorrowed = 0;

	std::cout << "\ntesting if the subscriber has already borrowed a book\n";

	for (unsigned int i = 0; i < nBorrows_; i++) {
		if (borrows_[i]->getSubscriber()->getId() == id)
		{
			borrows_[i]->getSubscriber()->print();

			counterBorrowed++;

			if (borrows_[i]->getBook()->getQuote() == quote)
			{
				borrows_[i]->getBook()->print();

				hasBook = true;

				std::cout << "Subscriber Borrowed book status : " << hasBook << '\n'; 
				
			}
		}
	}
	std::cout << "Subscriber Borrowed book status : " << hasBook << '\n';

	std::cout << "\nTesting the requirements conditions\n";
	for (unsigned int i = 0; i < nSubscribers_; i++)
	{
		std::cout << "id : " << id << " sub_id : " << subscribers_[i]->getId() << '\n';
		if (subscribers_[i]->getId() == id)
		{
			subscribers_[i]->print();

			for (unsigned int j = 0; j < nBooks_; j++)
			{
				std::cout << "\nquote : " << quote << ". "
						  << books_[j]->getQuote() << " "
						  << subscribers_[i]->getAge() << ", " << books_[j]->getReaderMinimalAge()
						  << ". " << counterBorrowed << ", " << maxNumberToBorrow
						  << ". " << !hasBook <<'\n';

				
				if (books_[j]->getQuote() == quote &&
					subscribers_[i]->getAge() >= books_[j]->getReaderMinimalAge() &&
					counterBorrowed <= maxNumberToBorrow &&
					!hasBook)
				{
					books_[j]-> print();
					
					isBorrowed = true;

					Borrow temp = Borrow(subscribers_[i], books_[j], returnDate);
					
					borrows_[nBorrows_++] = &temp;

					books_[j]->setNavalaibles(books_[j]->getNavalaibles() - 1);

					break;
				}
			}

			break;
		}

	}

	return isBorrowed;	
}

bool Library::returnBook(const std::string& id, const std::string& quote)
{
	bool isReturned = false;

	// testing if the subscriber has borrowed the  book
	for (unsigned int i = 0; i < nBorrows_; i++)
	{
		if (borrows_[i]->getSubscriber()->getId() == id &&
			borrows_[i]->getBook()->getQuote() == quote)
		{
			borrows_[i]->getBook()->setNavalaibles(borrows_[i]->getBook()->getNavalaibles() +1 );
			

			if (borrows_[nBorrows_ -1] != nullptr) {
				borrows_[i] = &(*borrows_[nBorrows_ -1]);
				delete borrows_[nBorrows_ -1];
				borrows_[nBorrows_ -1] = nullptr;
			}
			else
			{
				delete borrows_[i];
				borrows_[i] = nullptr;
			}

			isReturned = true;
			nBorrows_--;
			break;
		}
	}

	return isReturned;	
}

void Library::infoSubscriber(const std::string& id)
{
	std::cout << "\nLog: Entering the infoSubscriber method\n";
	
	bool isFound = false;

	for(unsigned int i = 0; i < nBorrows_; i++)
	{
		std::cout << i << '\n';
		if ( borrows_[i]->getSubscriber()->getId() == id)
		{
			isFound = true;
			std::cout << "\nSubscriber Info:\n";
			borrows_[i]->getSubscriber()->print();
			break;
		}
	}

	for(unsigned int i = 0; i < nBorrows_; i++)
	{
		if ( borrows_[i]->getSubscriber()->getId() == id)
		{
			std::cout << "Borrowing of subscriber # "
					  << borrows_[i]->getSubscriber()->getId()
					  << ". Book "
					  << borrows_[i]->getBook()->getQuote()
					  << ". Return date : "
					  << borrows_[i]->getReturnDate()
					  <<".\n";

		}
	}

	if (!isFound) std::cout << "\nATTENTION! NO SUBSCRIBER ID MATCH : "	<< id << " \n";
}
