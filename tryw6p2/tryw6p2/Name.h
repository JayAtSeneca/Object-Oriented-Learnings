#ifndef SDDS_NAME_H
#define SDDS_NAME_H
#include <iostream>
namespace sdds
{
	class Name
	{
		char* m_firstName{};
		char* m_middleName{};
		char* m_lastName{};
		void safeEmpty();
	public:
		Name();
		Name(const char* firstName);
		Name(const char* firstName,const char* lastName);
		Name(const char* firstName, const char* middleName, const char* lastName);
		Name(const Name& n);
		Name& operator=(const Name& n);
		~Name();
		Name& setShort(bool arg);
		Name& operator+=(const Name& n);
		operator bool()const;
	};
	std::istream& operator>>(std::istream& istr, const Name& n);
	std::ostream& operator<<(std::ostream& ostr, const Name& n);
}
#endif // !SDDS_NAME_H
