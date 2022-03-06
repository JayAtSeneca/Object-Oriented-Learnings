#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
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
		if (firstName == nullptr) // || strcmp(firstName, " ") || firstName[0] == '\0'
		{
			safeEmpty();
		}
		else
		{
			setFirstName(firstName);
		}
		//cout << m_firstName<<endl;
	}

	sdds::Name::Name(const char* firstName, const char* lastName)
	{
		if (firstName == nullptr || lastName == nullptr) //|| strcmp(firstName, " ") || firstName[0] == '\0' || strcmp(lastName, " ") || lastName[0] == '\0'
		{
			safeEmpty();
		}
		else
		{
			setFirstName(firstName);
			setLastName(lastName);
		}
		//cout << m_firstName << endl << m_lastName << endl;
	}

	sdds::Name::Name(const char* firstName, const char* middleName, const char* lastName)
	{
		if (firstName == nullptr || lastName == nullptr || middleName == nullptr)
			//|| strcmp(firstName, " ") || firstName[0] == '\0' || strcmp(lastName, " ") || lastName[0] == '\0' || strcmp(middleName, " ") || middleName[0] == '\0'
		{
			safeEmpty();
		}
		else
		{
			setFirstName(firstName);
			setLastName(lastName);
			setMiddleName(middleName);
		}
		//cout << m_firstName << endl << m_lastName << endl << m_middleName << endl;
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
		delete[] m_firstName;
		delete[] m_middleName;
		delete[] m_lastName;
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
			m_middleName = temp;
		}
		/*else
		{
			delete[] m_middleName;
			m_middleName = nullptr;
		}*/
		return *this;
	}

	void Name::extractChar(istream& istr, char ch) const
	{

		if (istr.peek() == ch)
		{
			istr.ignore();
		}
		else
		{
			istr.ignore(1000, ch);
			istr.setstate(ios::failbit);
		}
	}

	istream& Name::read(istream& istr)
	{
		char localFirstName[30] = { "\0" };
		char localMiddlename[30] = { "\0" };
		char localLastName[30] = { "\0" };
		
		istr >> localFirstName;
		//istr.getline(localFirstName, 30, '\n');
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
					/*setShort(false);*/

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
		cout << m_firstName;
		if (m_middleName != nullptr)
		{
			cout << " " << m_middleName;
		}
		if (m_lastName != nullptr)
		{
			cout << " " << m_lastName;
		}
		return ostr;
	}

	Name& sdds::Name::operator+=(const char* str)
	{
		if (str != nullptr && str[0] != ' ')
		{
			if (m_firstName == nullptr || m_middleName == nullptr || m_lastName == nullptr)
			{
				if (m_firstName == nullptr)
				{
					/*if (strcmp(str, " "))
					{
						safeEmpty();
					}*/


					char* temp = new char[strlen(str) + 1];
					strcpy(temp, str);
					m_firstName = temp;

				}
				else if (m_middleName == nullptr)
				{
					/*if (strcmp(str, " "))
					{
						safeEmpty();
					}*/


					char* temp = new char[strlen(str) + 1];
					strcpy(temp, str);
					m_middleName = temp;

				}
				else if (m_lastName == nullptr)
				{
					/*if (strcmp(str, " "))
					{
						safeEmpty();
					}*/


					char* temp = new char[strlen(str) + 1];
					strcpy(temp, str);
					m_lastName = temp;

				}

			}
			else
			{
				safeEmpty();
			}
		}
		return *this;
	}

	sdds::Name::operator bool() const
	{
		bool done = true;
		if (m_firstName == nullptr) //|| strcmp(m_firstName, " ")
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

