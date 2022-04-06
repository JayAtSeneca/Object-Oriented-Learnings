/*
Name: Jay Pravinkumar Chaudhari
Student ID: 147268205
E-mail: jpchaudhari@myseneca.ca
Section Code: NAA

Citation and Sources...
Final Project Milestone 2
Module: iProduct
Filename: iProduct.cpp
Version 1.0
Author	Jay Pravinkumar Chaudhari
Revision History
-----------------------------------------------------------
Date      Reason
2022/04/06  completed milestone 3
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include "iProduct.h"
using namespace std;
namespace sdds
{
	std::ostream& operator<<(std::ostream& ostr, const iProduct& i)
	{
		return i.display(ostr);
	}

	std::istream& operator>>(std::istream& istr, iProduct& i)
	{
		return i.read(istr);
	}

}

