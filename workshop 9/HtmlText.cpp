//Name: Jay Pravinkumar Chaudhari
//Student ID: 147268205
//E-mail: jpchaudhari@myseneca.ca
//Section Code: NAA
//Date: Mar 16, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include "HtmlText.h"
#include "Utils.h"
using namespace std;
namespace sdds
{
	HtmlText::HtmlText(const HtmlText& h):Text(h)
	{
		operator=(h);
	}
	HtmlText::HtmlText()
	{
		m_title = nullptr;
	}
	HtmlText& HtmlText::operator=(const HtmlText& h)
	{
		if (this != &h)
		{
			Text::operator=(h);
			ut.alocpy(m_title, h.m_title);
		}
		return *this;
	}
	HtmlText::HtmlText(const char* str)
	{
		if (str != nullptr)
		{
			ut.alocpy(m_title, str);
		}
	}
	HtmlText::~HtmlText()
	{
		delete[] m_title;
	}
	std::ostream& HtmlText::write(std::ostream& ostr) const
	{
		bool MS = false;
		ostr << "<html><head><title>";
		if (m_title != nullptr)
		{
			ostr << m_title;
		}
		else
		{
			ostr << "No Title";
		}
		ostr << "</title></head>\n<body>\n";
		if (m_title != nullptr)
		{
			ostr << "<h1>" << m_title << "</h1>\n";
		}
		int loopSize = Text::retContentLength();
		for (int i = 0; i < loopSize; i++)
		{
			char value = Text::operator[](i);
			if (value == ' ')
			{
				if (MS == true)
				{
					ostr << "&nbsp;";
				}
				else
				{
					MS = true;
					ostr << " ";
				}
			}
			else if (value == '<')
			{
				ostr << "&lt;";
				MS = false;
			}
			else if (value == '>')
			{
				ostr << "&gt;";
				MS = false;
			}
			else if (value == '\n')
			{
				ostr << "<br />\n";
				MS = false;
			}
			else
			{
				MS = false;
				ostr << value;
			}
		}
		ostr << "</body>\n</html>";
		return ostr;
	}
}