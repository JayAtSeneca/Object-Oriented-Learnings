//Interface.cpp
#include "Interface.h"

std::ostream& sdds::operator>>(std::ostream& ostr, const Interface& I)
{
	return I.output(ostr);
}

std::istream& sdds::operator<<(std::istream& istr, Interface& I)
{
	return I.input(istr);
}
