// Subscriber.cpp : Implementation of the class Subscriber
/*
  Defining the class Subscriber using the C++ Programming Language Special Ed. of B. Stroustrup
  Usage of the STL containers and algorithms: array, map, vector, etc.

  *\ Author(s) : Pierre Abraham Mulamba, Ph.D.
  *\ Date of creation (modification) : 20171116 (20171116)
 */
/********************************************************************************
 Copyright (c) 2017, IOSS, inc.
 All rights reserved
********************************************************************************/

#include "Subscriber.h"

Subscriber Subscriber::default_subscriber_("102030","Pierre", "Abraham", 6);

Subscriber::Subscriber(const std::string& id, const std::string& firstName,
					   const std::string& lastName, unsigned int age)
{
	const unsigned int min_age = 6;
	const unsigned int max_age = 100;

	if( age < min_age || max_age < age ) throw BadSubsriber();

	id_ = (id == "") ? default_subscriber_.id_ : id;
	firstName_ = (firstName == "") ? default_subscriber_.firstName_ : firstName;
	lastName_ = (lastName == "") ? default_subscriber_.lastName_ : lastName;
	age_ = (age == 0) ? default_subscriber_.age_ : age;
}

// Copy ctor
Subscriber::Subscriber(const Subscriber& subscriber) : id_(subscriber.id_),
													   firstName_(subscriber.firstName_),
													   lastName_(subscriber.lastName_),
													   age_(subscriber.age_)
{}

// Move ctor
Subscriber::Subscriber(Subscriber&& subscriber)noexcept : id_(""),
																firstName_(""),
																lastName_(""),
																age_(0)
{
	id_ = subscriber.id_;
	firstName_ = subscriber.firstName_;
	lastName_ = subscriber.lastName_;
	age_ = subscriber.age_;

	subscriber.id_ = "";
	subscriber.firstName_ = "";
	subscriber.lastName_ = "";
	subscriber.age_ = 0;
	
}

// Copy assignment
Subscriber& Subscriber::operator=(const Subscriber& subscriber)
{
	if(this != &subscriber)
	{
		id_ = subscriber.id_;
		firstName_ = subscriber.firstName_;
		lastName_ = subscriber.lastName_;
		age_ = subscriber.age_;
	}
	return *this;
}

// Move assignment
Subscriber& Subscriber::operator=(Subscriber&& subscriber) noexcept
{
	id_ = "";
	firstName_ = "";
	lastName_ = "";
	age_ = 0;

	if (this != &subscriber)
	{
		id_ = subscriber.id_;
		firstName_ = subscriber.firstName_;
		lastName_ = subscriber.lastName_;
		age_ = subscriber.age_;

		subscriber.id_ = "";
		subscriber.firstName_ = "";
		subscriber.lastName_ = "";
		subscriber.age_ = 0;
	}
	return *this;
}

// Dtor
Subscriber::~Subscriber(){}

// Accessors
std::string Subscriber::getId()const{return id_;}
std::string Subscriber::getFirstName()const{return firstName_;}
std::string Subscriber::getLastName()const{return lastName_;}
unsigned int Subscriber::getAge()const{return age_;}

// Mutators
void Subscriber::setId(const std::string& id){ id_ = id;}
void Subscriber::setFirstName(const std::string& firstName){ firstName_ = firstName;}
void Subscriber::setLastName(const std::string& lastName){ lastName_ = lastName;}
void Subscriber::setAge(unsigned int age){ age_ = age;}

void Subscriber::setDefault(const std::string& id, const std::string& firstName,
							const std::string& lastName, unsigned int age)
{
	Subscriber::default_subscriber_ = Subscriber(id, firstName, lastName, age);
}

void Subscriber::print()const
{
	std::cout << lastName_ << ", " << firstName_ << ". " << age_ << " years old. #" << id_ << '\n';
}
