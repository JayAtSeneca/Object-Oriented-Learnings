#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include <iostream>
#include "Shape.h"
namespace sdds {
	class LblShape :public Shape
	{
		char* m_label{};
	protected:
		const char* label()const;
	public:
		LblShape(const char* str = nullptr);
		virtual ~LblShape();
		LblShape(const LblShape& l) = delete;
		LblShape& operator=(const LblShape& l) = delete;
		void getSpecs(std::istream& istr);
	};
}
#endif // !SDDS_LBLSHAPE_H
