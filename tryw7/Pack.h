//Name: Jay Pravinkumar Chaudhari
//Student ID: 147268205
//E-mail: jpchaudhari@myseneca.ca
//Section Code: NAA
//Date: Mar 16, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_PACK_H
#define SDDS_PACK_H
#include "Container.h"
namespace sdds
{
	class Pack : public Container
	{
		int m_unitSize;
	public:
		Pack(const char* str, int size, int unitSize = 330, int noOfUnits = 0);
		int operator+=(int val);
		int operator-=(int val);
		int unit()const;
		int noOfUnits()const;
		int size()const;
		Pack& clear(int packSize, int unitSize, const char* str);
		std::ostream& print(std::ostream& ostr = std::cout)const;
		std::istream& read(std::istream& istr);
	};
	std::ostream& operator<<(std::ostream& ostr, const Pack& p);
	std::istream& operator>>(std::istream& istr, Pack& p);
}
#endif // !SDDS_PACK_H
