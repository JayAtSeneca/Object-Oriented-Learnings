// Interface.h
#ifndef SDDS_INTERFACE_H
#define SDDS_INTERFACE_H
#include <iostream>
namespace sdds
{
	class Interface
	{
	public:
		virtual std::ostream& output(std::ostream& ostr = std::cout)const = 0;
		virtual std::istream& input(std::istream& istr = std::cin) = 0;
	};
	std::ostream& operator>>(std::ostream& ostr, const Interface& I);
	std::istream& operator<<(std::istream& istr, Interface& I);
}

#endif // !SDDS_INTERFACE_H
