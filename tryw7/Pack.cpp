//Name: Jay Pravinkumar Chaudhari
//Student ID: 147268205
//E-mail: jpchaudhari@myseneca.ca
//Section Code: NAA
//Date: Mar 16, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include <cstring>
#include "Pack.h"

using namespace std;

namespace sdds
{
	Pack::Pack(const char* str, int size, int unitSize, int noOfUnits):Container(str,size*unitSize,noOfUnits*unitSize), m_unitSize{0}
	{
		if (unitSize > 0)
		{
			m_unitSize = unitSize;
		}
		else
		{
			setEmpty();
		}
	}
	int Pack::operator+=(int val)
	{
		int num = (Container::operator+=(val * m_unitSize)) / m_unitSize;
		return num;
	}
	int Pack::operator-=(int val)
	{
		int num = (Container::operator-=(val * m_unitSize)) / m_unitSize;
		return num;
	}
	int Pack::unit() const
	{
		return m_unitSize;
	}
	int Pack::noOfUnits() const
	{
		return (Container::volume())/m_unitSize;
	}
	int Pack::size() const
	{
		return Container::capacity() / m_unitSize;
	}

	Pack& Pack::clear(int packSize, int unitSize, const char* str)
	{
		if (unitSize > 0)
		{
			Container::clear(packSize * unitSize, str);
			m_unitSize = unitSize;
		}
		return *this;
	}
	std::ostream& Pack::print(std::ostream& ostr) const
	{
		Container::print(ostr);
		if (m_unitSize != 0)
		{
			cout << ", " << noOfUnits() << " in a pack of " << size();
		}
		return ostr;
	}
	std::istream& Pack::read(std::istream& istr)
	{
		if (Container::operator bool())
		{
			if (noOfUnits() < size())
			{
				int numUnit = noOfUnits();
				int sizeUnit = size();
				int missUnits = sizeUnit - numUnit;
				cout << "Add to ";
				print() << endl;
				cout << "> ";
				int num = getint(1,missUnits);
				int retVal = operator+=(num);
				cout << "Added " << num << endl;
			}
			else
			{
				cout << "Pack is full!, press <ENTER> to continue...";
				istr.ignore(1000, '\n');
				istr.get();
			}
		}
		else
		{
			cout << "Broken Container, adding aborted! Press <ENTER> to continue....";
			istr.get();
		}
		return istr;
	}

	std::ostream& operator<<(std::ostream& ostr, const Pack& p)
	{
		return p.print(ostr);
	}
	std::istream& operator>>(std::istream& istr, Pack& p)
	{
		return p.read(istr);
	}
}