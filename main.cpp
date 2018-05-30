// main.cpp : driver and test file for the lms application
/*
  Testing of instances of classes : Book , Borrow , Library, and Subscriber
  Usage of the STL containers and algorithms: array, vector , map , etc.

  *\ Author(s) : Pierre Abraham Mulamba, Ph.D.
  *\ Date of creation (modification) : 20171027 (20171028)
*/
/********************************************************************************
 Copyright (c) 2017, IOSS, inc.
 All rights reserved

********************************************************************************/

#include "Library.h"

using namespace std;


int main(int argc, char *argv[])
{
	try
	{
		// freopen("lms_out.txt" , "w" , stdout); 
		// freopen("logError.txt" , "w" , stderr);

		std::cout << "\nCREATION AND PRINTING OF SUBSCRIBERS\n";
		Subscriber sub1 = Subscriber("1839456", "Doe", "John", 23) ; 
		Subscriber sub2 = Subscriber("1630236", "Gagnon", "Nicolas", 8);
		Subscriber sub3 = Subscriber("1269348", "Tremblay", "Martin", 18);


		// Sbuscribers for testing the library

		sub1.print();	
		sub2.print();
		sub3.print();

		std::cout <<"\nCREATION OF THE LIBRARY\n";
				
		Library library;

		std::cout <<"\nTESTING THE LIBRARY PRINTING\n";

		library.print();
		

		std::cout << "\nADDING SUBSCRIBERS TO THE LIBRARY\n";
		library.addSubscriber(sub1);
		library.addSubscriber(sub2);
		library.addSubscriber(sub3);


		std::cout <<"\nTESTING THE LIBRARY INFOOOOOOOOOOOOOOOOOOOOOOOOOO\n";
		library.infoSubscriber(sub1.getId());
		library.infoSubscriber("1269348");
		library.infoSubscriber(sub2.getId());
		std::cout << "\nTESTING A NON EXISTANT ID\n";
		library.infoSubscriber("1122334"); // No existent ID

		library.print();
		
		
		
		std::cout << "\nCREATION AND PRINTING OF BOOK\n";

		Book* bookptr1 = new Book("GA403", "Big C++", "Bjarne Stroustup", "GBBS2017", 2009, 8, 3 , 1);
		Book* bookptr2 = new Book("QA203", "Calculus 1", "Kamputo", "QMK2003", 2011, 3, 2, 1); 
		Book* bookptr3 = new Book("QA204", "Calculus 2", "Mubenga", "QCM2000", 2011, 3, 2 ,1);
		Book* bookptr4 = new Book("AC409", "TIC in Cpp", "Eckel", "ATE1998", 1764, 16, 1, 2);
		Book* bookptr5 = new Book("BD302", "Harry Potter", "Unkown", "BHU1969", 1999, 3, 1 , 0);
  
		
		std::cout << "\nPRINTING INDIVIDUAL BOOK\n";
		
		bookptr1->print();
		bookptr2->print();
		bookptr3->print();
		bookptr4->print();
		bookptr5->print();

	
		
		std::cout << "\nADDING BOOKS TO THE LIBRARY\n";
			
		library.addBook(bookptr1);
		library.addBook(bookptr2);
		library.addBook(bookptr3);
		library.addBook(bookptr4);
		library.addBook(bookptr5);

		library.print();

		std::cout << "\nTESTING STARTING POINT ...\n";

		

		std::cout << "\nSEARCHING BY TITLE ...: Calcul\n";
		library.searchTitle("Calcul");
		library.searchTitle("Mossaka");

		std::cout << "\nSEARCHING BY QUOTE...: AC409\n";
		library.searchQuote("QA204");
		library.searchQuote("AA510");


		std::cout << "\nBORROWING TEST...\n";
		std::cout<< "\nFailing test because of Martin is too young!!!!!!!!!!!!\n";

		if (library.borrowBook("1630236", "AC409", 160204)) {
			std::cout << "\nAC409 borrowed by 1630236\n";
		}
		else{
			std::cout << "\nAC409 book cannot be borrowed\n";
		}

		std::cout << "\nEnd of failed test\n";

		std::cout << "\n!!!!!!!!!!Successfull test\n";
		
		if (library.borrowBook("1630236", "BD302", 160204)) {
			std::cout << "\nBD302 borrowed by 1630236\n";
		}
		else{
			std::cout << "\nBD302 book cannot be borrowed\n";
		}


		std::cout << "\nTESTING THE RETURN method\n";
		std::cout << "\nINFO SUBSCRIBER BEFORE RETURNING THE BOOK\n";

		
		
		delete bookptr1;
		delete bookptr2;
		delete bookptr3;
		delete bookptr4;
		delete bookptr5;


		std::cout << "\nCREATION OF BAD SUBSCRIBER TO TEST THE EXCEPTION\n";
		

		Subscriber badSub = Subscriber("","","",0); // willl throw an exception
		badSub.print();
		
		
		std::cout << "\nProgram Ended Successfully!\n";
		
				
	}
	catch(Subscriber::BadSubsriber e){std::cerr << e.exceptionMessage << '\n';}
	catch(Book::BadBook e){std::cerr << e.exceptionMessage << '\n';}
	catch (...)
	{
		std::cerr << "\nUnknown exception thrown\n";
		
	}

}
