#ifndef SDDS_TEXT_H
#define SDDS_TEXT_H
#include <iostream>
#include "Utils.h"
namespace sdds {
	class Text
	{
		char* m_content{};
	protected:
		const char& operator[](int index)const;
	public:
		Text();
		Text(const Text& t);
		Text& operator=(const Text& t);
		virtual ~Text();
		std::istream& read(std::istream& istr);
		virtual std::ostream& write(std::ostream& ostr)const;
	};
	std::ostream& operator<<(std::ostream& ostr, const Text& t);
	std::istream& operator>>(std::istream& istr, Text& t);
}
#endif // !SDDS_TEXT_H
