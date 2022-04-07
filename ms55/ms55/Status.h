/*
Name: Jay Pravinkumar Chaudhari
Student ID: 147268205
E-mail: jpchaudhari@myseneca.ca
Section Code: NAA

Citation and Sources...
Final Project Milestone 2
Module: Status
Filename: Status.h
Version 1.0
Author	Jay Pravinkumar Chaudhari
Revision History
-----------------------------------------------------------
Date      Reason
2022/04/06  completed milestone 2
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_STATUS_H
#define SDDS_STATUS_H
#include <iostream>
namespace sdds
{
	class Status
	{
		char* m_description{};
		int m_code;
	public:
		// constructors
		Status(const char* str = nullptr);
		Status(const Status& s);
		Status& operator=(const Status& s);
		Status& operator=(int num);
		Status& operator=(const char* str);
		// destructor
		virtual ~Status();
		//modifier
		Status& clear();
		// query
		operator int()const;
		operator const char*()const;
		operator bool()const;
	};
	std::ostream& operator<<(std::ostream& ostr,const Status& s);
}
#endif // !SDDS_STATUS_H
