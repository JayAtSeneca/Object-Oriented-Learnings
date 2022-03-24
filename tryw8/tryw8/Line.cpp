#include "Line.h"
using namespace std;
namespace sdds {
	Line::Line()
	{
		m_length = 0;
	}
	Line::Line(const char* str, int length) :LblShape(str)
	{
		m_length = length;
	}
	void Line::getSpecs(istream& istr)
	{
		LblShape::getSpecs(istr);
		char length[3] = "\0";
		istr.ignore();
		istr.get(length, '\n');
		m_length = atoi(length);
		istr.ignore(1000, '\n');
	}
	void Line::draw(std::ostream& ostr) const
	{
		if (m_length > 0 && LblShape::label() != NULL)
		{
			ostr << LblShape::label() << endl;
			for (int i = 0; i < m_length; i++)
			{
				ostr << "=";
			}
		}
	}
}