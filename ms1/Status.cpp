/*
Name: Jay Pravinkumar Chaudhari
Student ID: 147268205
E-mail: jpchaudhari@myseneca.ca
Section Code: NAA

Citation and Sources...
Final Project Milestone 1
Module: Status
Filename: Status.cpp
Version 1.0
Author	Jay Pravinkumar Chaudhari
Revision History
-----------------------------------------------------------
Date      Reason
2022/03/12  completed milestone 1
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include "Utils.h"
#include "Status.h"

using namespace std;

namespace sdds
{
	Status::Status(const char* str)
	{
		if (str != nullptr)
		{
			ut.alocpy(m_description, str);
		}
		else
		{
			m_description = nullptr;
		}
		m_code = 0;
	}

	Status::Status(const Status& s)
	{
		if (!s)
		{
			*this = s;
		}
	}

	Status& Status::operator=(const Status& s)
	{
		if (this != &s)
		{
			ut.alocpy(m_description, s.m_description);
			m_code = s.m_code;
		}
		return *this;
	}

	Status& Status::operator=(int num)
	{
		m_code = num;
		return *this;
	}

	Status& Status::operator=(const char* str)
	{
		ut.alocpy(m_description, str);
		return *this;
	}

	Status::~Status()
	{
		delete[] m_description;
	}
	Status& Status::clear()
	{
		delete[] m_description;
		m_description = nullptr;
		m_code = 0;
		return *this;
	}
	Status::operator int() const
	{
		return m_code;
	}
	Status::operator const char*() const
	{
		return m_description;
	}
	Status::operator bool() const
	{
		bool done = true;
		if (m_description != nullptr)
		{
			done = false;
		}
		return done;
	}
	ostream& operator<<(ostream& ostr, const Status& s)
	{
		if (!s)
		{
			if ((int)s != 0)
			{
				ostr << "ERR#" << (int)s << ": ";
			}
			ostr<< (const char*)s;
		}
		
		return ostr;
	}
}

