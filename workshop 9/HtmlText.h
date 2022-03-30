//Name: Jay Pravinkumar Chaudhari
//Student ID: 147268205
//E-mail: jpchaudhari@myseneca.ca
//Section Code: NAA
//Date: Mar 16, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#ifndef SDDS_HTMLTEXT_H
#define SDDS_HTMLTEXT_H
#include "Text.h"
namespace sdds
{
	class HtmlText :public Text
	{
		char* m_title{};
	public:
		HtmlText();
		HtmlText(const char* str);
		HtmlText(const HtmlText& h);
		HtmlText& operator=(const HtmlText& h);
		virtual ~HtmlText();
		std::ostream& write(std::ostream& ostr)const;
	};
}
#endif // !SDDS_HTMLTEXT_H
