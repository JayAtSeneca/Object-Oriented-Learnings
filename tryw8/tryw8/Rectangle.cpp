#include <iostream>
#include <string>
#include "Rectangle.h"
using namespace std;
namespace sdds
{
	Rectangle& Rectangle::setEmpty()
	{
		m_height = 0;
		m_width = 0;
		return *this;
	}
	bool Rectangle::isEmpty() const
	{
		bool done = false;
		if (m_height == 0 && m_width == 0)
		{
			done = true;
		}
		return done;
	}
	Rectangle::Rectangle()
	{
		m_width = 0;
		m_height = 0;
	}
	Rectangle::Rectangle(const char* str, int width, int height):LblShape(str)
	{
		m_width = width;
		m_height = height;
		if (m_height < 3 || (m_width < strlen(LblShape::label() + 2)))
		{
			setEmpty();
		}
	}
	void Rectangle::getSpecs(istream& istr)
	{
		LblShape::getSpecs(istr);
		char heigth[10];
		char width[10];
		istr.ignore();
		istr.get(width, 3, ',');
		istr.ignore();
		istr.get(heigth, 3, '\n');
		istr.ignore(1000, '\n');
		m_height = atoi(heigth);
		m_width = atoi(width);
	}
	void Rectangle::draw(ostream& ostr) const
	{
		if (!isEmpty())
		{
			//first line
			ostr << "+";
			for (int i = 0; i < m_width - 2; i++)
			{
				ostr << "-";
			}
			ostr << "+" << endl;
			//second line
			ostr << "|";
			ostr.setf(ios::fixed);
			ostr.width(m_width - 2);
			ostr.fill(' ');
			ostr << left << LblShape::label();
			ostr.unsetf(ios::fixed);
			ostr << "|" << endl;
			
			//next lines
			for (int i = 0; i < m_height - 3; i++)
			{
				ostr << "|";
				for (int i = 0; i < m_width - 2; i++)
				{
					ostr << " ";
				}
				ostr << "|" << endl;
			}

			//last line
			ostr << "+";
			for (int i = 0; i < m_width - 2; i++)
			{
				ostr << "-";
			}
			ostr << "+";
		}
	}
}