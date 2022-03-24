#include <iostream>
#include "Shape.h"

using namespace std;
namespace sdds {
	std::ostream& operator<<(std::ostream& ostr, const Shape& s)
	{
		s.draw(ostr);
		return ostr;
	}

	std::istream& operator>>(std::istream& istr, Shape& s)
	{
		s.getSpecs(istr);
		return istr;
	}
};

