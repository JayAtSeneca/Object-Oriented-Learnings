#include "Text.h"
using namespace std;
namespace sdds
{
	const char& Text::operator[](int index) const
	{
		char temp = NULL;
		if (m_content != NULL && index < strlen(m_content))
		{
			temp = m_content[index];
		}
		return temp;
	}
	Text::Text()
	{
		m_content = nullptr;
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
		int contentLength = ut.getFileLength(istr);
		m_content = new char[contentLength + 1];
		int i = 0;
		while (!istr.eof())
		{
			m_content[i] = istr.get();
			i++;
		}
		m_content[i - 1] = '\0';
		if (!istr.fail())
		{
			istr.clear();
		}
		return istr;
	}
	std::ostream& Text::write(std::ostream& ostr) const
	{
		if (m_content != NULL)
		{
			ostr << m_content;
		}
		return ostr;
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