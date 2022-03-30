//Name: Jay Pravinkumar Chaudhari
//Student ID: 147268205
//E-mail: jpchaudhari@myseneca.ca
//Section Code: NAA
//Date: Mar 16, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "Text.h"
#include "Utils.h"
using namespace std;
namespace sdds
{
	const char& Text::operator[](int index) const
	{
		return m_content[index];
	}
	Text::Text()
	{
		m_content = nullptr;
		m_contentLength = 0;
	}
	Text::Text(const Text& t)
	{
		operator=(t);
	}
	Text& Text::operator=(const Text& t)
	{
		if (this != &t)
		{
			ut.alocpy(m_content, t.m_content);
			m_contentLength = t.m_contentLength;
		}
		return *this;
	}
	Text::~Text()
	{
		delete[] m_content;
	}
	std::istream& Text::read(std::istream& istr)
	{
		delete[] m_content;
		m_contentLength = 0;
		int contentLength = getFileLength(istr);
		m_contentLength = contentLength;
		
		int i = 0;
		//&& i < contentLength
		/*while (!istr.eof())
		{
			m_content[i] = istr.get();
			i++;
		}
		m_content[i - 1] = '\0';
		if (m_content[0] != '\0')
		{
			istr.clear();
			istr.ignore(1000, '\n');
		}*/
		if (contentLength > 0)
		{
			m_content = new char[contentLength + 1];
			for (i = 0; i < contentLength; i++)
			{
				m_content[i] = istr.get();
			}
			m_content[i] = '\0';
			istr.clear();
		}
		return istr;
	}
	std::ostream& Text::write(std::ostream& ostr) const
	{
		if (m_content != nullptr)
		{
			ostr << m_content;
		}
		return ostr;
	}
	int Text::getFileLength(std::istream& is) {
		int len{};
		if (is) {
			// save the current read position
			std::streampos cur = is.tellg();
			// go to the end
			is.seekg(0, ios::end);
			// let what is the positions (end position = size)
			len = is.tellg();
			// now go back to where you were.
			is.seekg(cur);
		}
		return len;
	}
	int Text::retContentLength() const
	{
		return m_contentLength;
	}
	std::ostream& operator<<(std::ostream& ostr, const Text& t)
	{
		return t.write(ostr);
	}
	std::istream& operator>>(std::istream& istr, Text& t)
	{
		return t.read(istr);
	}
}