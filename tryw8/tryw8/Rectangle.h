#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include "LblShape.h"
namespace sdds {
	class Rectangle :public LblShape
	{
		int m_width;
		int m_height;
		Rectangle& setEmpty();
		bool isEmpty()const;
	public:
		Rectangle();
		Rectangle(const char* str, int width, int height);
		void getSpecs(std::istream& istr);
		void draw(std::ostream& ostr)const;
	};
}
#endif // !SDDS_RECTANGLE_H
