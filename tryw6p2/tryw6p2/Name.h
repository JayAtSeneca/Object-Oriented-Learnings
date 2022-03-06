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
		Name& setFirstName(const char* str);
		Name& setMiddleName(const char* str);
		Name& setLastName(const char* str);
	public:
		Name();
		Name(const char* firstName);
		Name(const char* firstName,const char* lastName);
		Name(const char* firstName, const char* middleName, const char* lastName);
		Name(const Name& n);
		Name& operator=(const Name& n);
		~Name();
		Name& setShort(bool arg);
		std::istream& read(std::istream& istr);
		std::ostream& print(std::ostream& ostr)const;
		Name& operator+=(const char* str);
		operator bool()const;
		void extractChar(std::istream& istr, char ch) const;
	};
	std::istream& operator>>(std::istream& istr, Name& n);
	std::ostream& operator<<(std::ostream& ostr, const Name& n);
}
#endif // !SDDS_NAME_H
