#include <iostream>
#include "Name.h"

using namespace std;
namespace sdds
{
	void sdds::Name::safeEmpty()
	{
	}

	sdds::Name::Name()
	{
	}

	sdds::Name::Name(const char* firstName)
	{
	}

	sdds::Name::Name(const char* firstName, const char* lastName)
	{
	}

	sdds::Name::Name(const char* firstName, const char* middleName, const char* lastName)
	{
	}

	sdds::Name::Name(const Name& n)
	{
	}

	Name& sdds::Name::operator=(const Name& n)
	{
		// TODO: insert return statement here
	}

	sdds::Name::~Name()
	{
	}

	Name& sdds::Name::setShort(bool arg)
	{
		// TODO: insert return statement here
	}

	Name& sdds::Name::operator+=(const Name& n)
	{
		// TODO: insert return statement here
	}

	sdds::Name::operator bool() const
	{
	}

	std::istream& sdds::operator>>(std::istream& istr, const Name& n)
	{
		// TODO: insert return statement here
	}

	std::ostream& sdds::operator<<(std::ostream& ostr, const Name& n)
	{
		// TODO: insert return statement here
	}
}

