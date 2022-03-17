//Name: Jay Pravinkumar Chaudhari
//Student ID: 147268205
//E-mail: jpchaudhari@myseneca.ca
//Section Code: NAA
//Date: Mar 16, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_CONTAINER_H
#define SDDS_CONTAINER_H
#include <iostream>
namespace sdds
{
	class Container
	{
		char m_content[50];
		int m_capacity;
		int m_contentVolume;
		bool isValid()const;
	protected:
		Container& setEmpty();
		int capacity()const;
		int volume()const;
	public:
		Container(const char* str = NULL, int num = 0, int val = 0);
		int operator+=(int val);
		int operator-=(int val);
		operator bool()const;
		Container& clear(int capacity, const char* str);
		std::ostream& print(std::ostream& ostr = std::cout)const;
		std::istream& read(std::istream& istr);
	};

	std::ostream& operator<<(std::ostream& ostr,const Container& c);
	std::istream& operator>>(std::istream& istr, Container& c);
	int getint(const char* prompt = nullptr);
	int getint(int min, int max, const char* prompt = nullptr, const char* errMes = nullptr);
}
#endif // !SDDS_CONTAINER_H
