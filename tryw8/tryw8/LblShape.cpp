#include "LblShape.h"
#include "Utils.h"
using namespace std;
namespace sdds
{
	const char* LblShape::label() const
	{
		return m_label;
	}
	LblShape::LblShape(const char* str)
	{
		if(str!=nullptr)
			ut.alocpy(m_label, str);
	}
	LblShape::~LblShape()
	{
		delete[] m_label;
	}
	void LblShape::getSpecs(std::istream& istr)
	{
		char str[1000] = "\0";
		istr.get(str, 100, ',');
		ut.alocpy(m_label, str);
	}
}