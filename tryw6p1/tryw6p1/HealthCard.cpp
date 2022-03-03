#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "HealthCard.h"
using namespace std;
namespace sdds {
	bool HealthCard::validID(const char* name, long long number, const char vCode[], const char sNumber[]) const
	{
		bool done = false;
		if ((name != nullptr && strlen(name) != 0) && (number > 999999999 && number < 9999999999) && (strlen(vCode) == 2) && (strlen(sNumber) == 9))
		{
			done = true;
		}
		return done;
	}
	void HealthCard::setEmpty()
	{
		m_name = nullptr;
	}
	void HealthCard::allocateAndCopy(const char* name)
	{
		delete[] m_name;
		m_name = new char[strlen(name) + 1];
		strcpy(m_name, name);
		
	}
	void HealthCard::extractChar(istream& istr, char ch) const
	{
		
		if (istr.peek()== ch)
		{
			istr.ignore();
		}
		else
		{
			istr.ignore(1000, ch);
			istr.setstate(ios::failbit);
		}
	}
	ostream& HealthCard::printIDInfo(ostream& ostr) const
	{
		ostr << m_number << "-" << m_vCode << ", " << m_sNumber;
		return ostr;
	}
	void HealthCard::set(const char* name, long long number, const char vCode[], const char sNumber[])
	{
		if (validID(name, number, vCode, sNumber))
		{
			allocateAndCopy(name);
			m_number = number;
			strcpy(m_vCode, vCode);
			strcpy(m_sNumber, sNumber);
		}
		else
		{
			delete[] m_name;
			setEmpty();
		}
	}
	/*bool HealthCard::isValid(const HealthCard& hc) const
	{
		bool done = false;
		if ((hc.m_name != nullptr && strlen(hc.m_name) != 0) && (hc.m_number > 999999999 && hc.m_number < 9999999999) && (strlen(hc.m_vCode) == 2) && (strlen(hc.m_sNumber) == 9))
		{
			done = true;
		}
		return done;
	}*/

	HealthCard::HealthCard(const char* name, long long number, const char vCode[], const char sNumber[])
	{
		/*if (validID(name, number, vCode, sNumber))
		{
			allocateAndCopy(name);
			m_number = number;
			strcpy(m_vCode, vCode);
			strcpy(m_sNumber, sNumber);
		}*/
		set(name, number, vCode, sNumber);
	}

	HealthCard::HealthCard(const HealthCard& hc)
	{
		if (hc)
		{
			set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
		}
	}
	HealthCard& HealthCard::operator==(const HealthCard& hc)
	{
		if (this != &hc)
		{
			set(hc.m_name, hc.m_number, hc.m_vCode, hc.m_sNumber);
		}
		return *this;
	}
	HealthCard::~HealthCard()
	{
		delete[] m_name;
	}
	HealthCard::operator bool() const
	{
		return m_name != nullptr;
	}
	ostream& HealthCard::print(ostream& ostr, bool toFile) const
	{
		if (*this)
		{
			if (toFile == true)
			{
				ostr << m_name;
				printIDInfo(ostr);
			}
			else
			{
				ostr.fill('.');
				ostr.width(50);
				ostr << left << m_name;
				printIDInfo(ostr);
			}
		}
		return ostr;
	}
	istream& HealthCard::read(istream& istr)
	{
		char localName[MaxNameLength + 1];
		long long localNumber;
		char localvCode[3];
		char localsNumber[10];
		istr.get(localName, MaxNameLength, ',');
		extractChar(istr, ',');
		istr >> localNumber;
		extractChar(istr, '-');
		istr.get(localvCode, 3, ',');
		extractChar(istr, ',');
		istr.get(localsNumber, 10, '\n');
		if (!istr.fail())
		{
			set(localName, localNumber, localvCode, localsNumber);
		}
		istr.clear();
		istr.ignore(1000, '\n');
		return istr;
	}
	ostream& operator<<(std::ostream& ostr, const HealthCard& hc)
	{
		if (hc)
		{
			hc.print(ostr, false);
		}
		else
		{
			ostr << "Invalid Health Card Record";
		}
		return ostr;
	}
	istream& operator>>(std::istream& istr, HealthCard& hc)
	{
		
		return hc.read(istr);
	}
}
