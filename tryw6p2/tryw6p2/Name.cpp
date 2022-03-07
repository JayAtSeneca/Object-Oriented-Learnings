#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "Name.h"

using namespace std;
namespace sdds
{
	void sdds::Name::safeEmpty()
	{
		delete[] m_firstName;
		m_firstName = nullptr;
		delete[] m_middleName;
		m_middleName = nullptr;
		delete[] m_lastName;
		m_lastName = nullptr;
	}

	Name& Name::setFirstName(const char* str)
	{
		if (str && str[0])
		{
			delete[] m_firstName;
			m_firstName = nullptr;
			char* temp = new char[strlen(str) + 1];
			strcpy(temp, str);
			m_firstName = temp;
		}
		return *this;
	}

	Name& Name::setMiddleName(const char* str)
	{
		if (str && str[0])
		{
			delete[] m_middleName;
			m_middleName = nullptr;
			char* temp = new char[strlen(str) + 1];
			strcpy(temp, str);
			m_middleName = temp;
		}
		return *this;
	}

	Name& Name::setLastName(const char* str)
	{
		if (str && str[0])
		{
			delete[] m_lastName;
			m_lastName = nullptr;
			char* temp = new char[strlen(str) + 1];
			strcpy(temp, str);
			m_lastName = temp;
		}
		return *this;
	}

	sdds::Name::Name()
	{
		safeEmpty();
	}

	sdds::Name::Name(const char* firstName)
	{
		if (firstName == nullptr)
		{
			safeEmpty();
		}
		else
		{
			setFirstName(firstName);
		}
	}

	sdds::Name::Name(const char* firstName, const char* lastName)
	{
		if (firstName == nullptr || lastName == nullptr)
		{
			safeEmpty();
		}
		else
		{
			setFirstName(firstName);
			setLastName(lastName);
		}
	}

	sdds::Name::Name(const char* firstName, const char* middleName, const char* lastName)
	{
		if (firstName == nullptr || lastName == nullptr || middleName == nullptr)
		{
			safeEmpty();
		}
		else
		{
			setFirstName(firstName);
			setLastName(lastName);
			setMiddleName(middleName);
		}
	}

	sdds::Name::Name(const Name& n)
	{
		if (n)
		{
			*this = n;
		}
	}

	Name& sdds::Name::operator=(const Name& n)
	{
		if (this != &n)
		{
			setFirstName(n.m_firstName);
			setLastName(n.m_lastName);
			setMiddleName(n.m_middleName);
		}
		return *this;
	}

	sdds::Name::~Name()
	{
		safeEmpty();
	}

	Name& sdds::Name::setShort(bool arg)
	{
		if (arg == true && m_middleName != nullptr)
		{
			char* temp = new char[strlen(m_middleName) + 1];
			temp[0] = m_middleName[0];
			temp[1] = '\0';
			strcat(temp, ".");
			delete[] m_middleName;
			m_middleName = nullptr;
			m_middleName = temp;
		}
		return *this;
	}

	istream& Name::read(istream& istr)
	{
		char localFirstName[30] = { "\0" };
		char localMiddlename[30] = { "\0" };
		char localLastName[30] = { "\0" };
		safeEmpty();
		istr >> localFirstName;

		if (isalpha(localFirstName[0])) {
			if (istr.peek() == ' ')
			{
				istr.ignore();
				if (m_middleName != nullptr || m_middleName == NULL || m_middleName[0] != ' ')
				{
					delete[] m_middleName;
					m_middleName = nullptr;
				}
				istr >> localLastName;
				if (istr.peek() != '\n' && istr.peek() == ' ')
				{
					strcpy(localMiddlename, localLastName);
					localLastName[0] = '\0';
					istr.ignore();
					istr >> localLastName;
					if (istr.peek() == ' ')
					{
						istr.putback('\n');
						istr.setstate(ios::failbit);
					}
				}
			}
			if (!istr.fail())
			{
				setFirstName(localFirstName);
				setMiddleName(localMiddlename);
				setLastName(localLastName);
			}
			else
			{
				istr.clear();
				istr.ignore(1000, '\n');
				safeEmpty();
			}
		}

		return istr;
	}

	ostream& Name::print(ostream& ostr)const
	{
		if (m_firstName && m_firstName[0])
		{
			ostr << m_firstName;
		}

		if (m_middleName && m_middleName[0])
		{
			ostr << " " << m_middleName;
		}
		if (m_lastName && m_lastName[0])
		{
			ostr << " " << m_lastName;
		}
		return ostr;
	}

	Name& sdds::Name::operator+=(const char* str)
	{
		if (str != nullptr && str[0] != '\0')
		{
			bool space = false;
			for (int i = 0; str[i] != 0 && !space; i++)
			{
				space = str[i] == ' ';
			}

			if (!space)
			{

				if (m_firstName == nullptr)
				{
					setFirstName(str);
				}
				else if (m_middleName == nullptr)
				{
					setMiddleName(str);
				}
				else if (m_lastName == nullptr)
				{
					setLastName(str);
				}
				else
				{
					safeEmpty();
				}
			}
		}
		return *this;
	}

	sdds::Name::operator bool() const
	{
		bool done = true;
		if (m_firstName == nullptr)
		{
			done = false;
		}
		return done;
	}

	istream& operator>>(istream& istr, Name& n)
	{
		return n.read(istr);
	}

	ostream& operator<<(ostream& ostr, const Name& n)
	{
		if (n)
		{
			n.print(ostr);
		}
		else
		{
			cout << "Bad Name";
		}
		return ostr;
	}
}
