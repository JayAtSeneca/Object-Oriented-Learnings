//Name: Jay Pravinkumar Chaudhari
//Student ID: 147268205
//E-mail: jpchaudhari@myseneca.ca
//Section Code: NAA
//Date: Mar 16, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Container.h"

using namespace std;
namespace sdds
{
	bool Container::isValid() const
	{
		bool done = false;
		if (m_content != NULL && m_capacity != 0)
		{
			done = true;
		}
		return done;
	}
	Container& Container::setEmpty()
	{
		m_content[0] = '\0';
		m_capacity = 0;
		m_contentVolume = 0;
		return *this;
	}
	int Container::capacity() const
	{
		return m_capacity;
	}
	int Container::volume() const
	{
		return m_contentVolume;
	}
	Container::Container(const char* str, int num, int val) : m_content{}, m_capacity{ 0 }, m_contentVolume{ 0 }
	{
		if (str != NULL && val < num)
		{
			strcpy(m_content, str);
			m_capacity = num;
			m_contentVolume = val;
		}
	}
	int Container::operator+=(int val)
	{
		int num = val + m_contentVolume;
		int retVal = 0;
		if (num < m_capacity)
		{
			m_contentVolume = num;
			retVal = val;
		}
		else
		{
			retVal = m_capacity - val;
			m_contentVolume = m_capacity;
		}
		return retVal;
	}
	int Container::operator-=(int val)
	{
		int num = m_contentVolume - val;
		int retVal = 0;
		if (num > 0)
		{
			m_contentVolume = num;
			retVal = val;
		}
		else
		{
			retVal = m_contentVolume;
			m_contentVolume = 0;
		}
		return retVal;
	}
	Container::operator bool() const
	{
		bool done = false;
		if (isValid())
		{
			done = true;
		}
		return done;
	}
	Container& Container::clear(int capacity, const char* str)
	{
		if (capacity > 0 && str != NULL)
		{
			m_capacity = capacity;
			strcpy(m_content, str);
		}
		return *this;
	}
	std::ostream& Container::print(std::ostream& ostr) const
	{
		if (isValid())
		{
			ostr << m_content << ": (" << m_contentVolume << "cc/" << m_capacity << ")";
		}
		else
		{
			ostr << "****: (**cc/***)";
		}
		return ostr;
	}
	std::istream& Container::read(std::istream& istr)
	{
		if (isValid())
		{
			cout << "Add to ";
			print() << endl << "> ";
			int num = getint(1, 220000);
			int retVal = operator+=(num);
			cout << "Added " << retVal << " CCs" << endl;
		}
		else
		{
			cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
			istr.ignore(1000, '\n');
			istr.get();
		}
		return istr;
	}
	std::ostream& operator<<(std::ostream& ostr, const Container& c)
	{
		return c.print(ostr);
	}
	std::istream& operator>>(std::istream& istr, Container& c)
	{
		return c.read(istr);
	}

	int getint(const char* prompt)
	{
		int num;
		if (prompt) cout << prompt;
		bool done = false;
		do
		{
			cin >> num;

			if (!cin.fail())
			{
				done = true;
			}
			else
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid Integer, retry: ";
				num = 0;
			}
		} while (done != true);

		return num;
	}

	int getint(int min, int max, const char* prompt, const char* errMes)
	{
		if (prompt) cout << prompt;
		bool done = false;
		int num = 0;
		do
		{
			num = getint();
			if (num < min || num > max)
			{
				if (errMes)
				{
					cout << errMes;
				}
				else
				{
					cout << "Value out of range [" << min << "<=val<=" << max << "]: ";
				}
			}
			else
			{
				done = true;
			}
		} while (done != true);

		return num;
	}

}


