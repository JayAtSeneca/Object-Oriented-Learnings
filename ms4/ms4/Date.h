/*
Name: Jay Pravinkumar Chaudhari
Student ID: 147268205
E-mail: jpchaudhari@myseneca.ca
Section Code: NAA

Citation and Sources...
Final Project Milestone 2
Module: Date
Filename: Date.h
Version 1.0
Author	Jay Pravinkumar Chaudhari
Revision History
-----------------------------------------------------------
Date      Reason
2022/03/16  completed milestone 2
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_DATE_H
#define SDDS_DATE_H
#include <fstream>
#include "Status.h"
namespace sdds
{
	const int CURR_YEAR = 2022;
	const  int MAX_YEAR = 2030;
	class Date
	{
		int m_year = 0;
		int m_month = 0;
		int m_day = 0;
		Status m_state;
		bool m_formatted = true;
		//private member functions
		bool validate();
		int uniqDateVal(int year, int month, int day);
	public:
		Date(int year = 0, int month = 0, int day = 0);
		Date& operator=(const Date& d);
		std::ostream& displayUnformatted(std::ostream& ofstr)const;
		std::ostream& displayFormatted(std::ostream& ofstr)const;
		bool operator==(const Date& d);
		bool operator!=(const Date& d);
		bool operator<(const Date& d);
		bool operator>(const Date& d);
		bool operator<=(const Date& d);
		bool operator>=(const Date& d);
		const Status& state();
		Date& formatted(bool val);
		operator bool()const;
		std::ostream& write(std::ostream& ostr)const;
		std::istream& read(std::istream& istr);
		Date& set(int year, int month, int day);
	};
	std::ostream& operator<<(std::ostream& ostr, const Date& d);
	std::istream& operator>>(std::istream& istr, Date& d);
}
#endif // !SDDS_DATE_H
