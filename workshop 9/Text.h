//Name: Jay Pravinkumar Chaudhari
//Student ID: 147268205
//E-mail: jpchaudhari@myseneca.ca
//Section Code: NAA
//Date: Mar 16, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_TEXT_H
#define SDDS_TEXT_H
#include <iostream>
namespace sdds
{
	class Text
	{
		char* m_content{};
		int m_contentLength;
	protected:
		const char& operator[](int index)const;
	public:
		Text();
		Text(const Text& t);
		Text& operator=(const Text& t);
		virtual ~Text();
		std::istream& read(std::istream& istr);
		virtual std::ostream& write(std::ostream& ostr)const;
		int getFileLength(std::istream& is);
		int retContentLength()const;
	};
	std::ostream& operator<<(std::ostream& ostr, const Text& t);
	std::istream& operator>>(std::istream& istr, Text& t);
}
#endif // !SDDS_TEXT_H
