#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include "LblShape.h"
namespace sdds {
	class Line :public LblShape
	{
		int m_length;
	public:
		Line();
		Line(const char* str, int length);
		void getSpecs(std::istream& istr);
		void draw(std::ostream& ostr)const;
	};
}
#endif // !SDDS_LINE_H
