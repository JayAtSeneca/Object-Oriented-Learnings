#include <cstring>
#include "Item.h"
#include "Utils.h"
using namespace std;
namespace sdds
{
	bool Item::linear() const
	{
		return m_flag;
	}
	Item::Item()
	{
		m_description = nullptr;
		m_flag = false;
		m_price = 0.0;
		m_quantityInHand = 0;
		m_quantityReq = 0;
		SKU = 0;
	}
	Item::Item(const Item& i)
	{
		operator=(i);
	}
	Item& Item::operator=(const Item& i)
	{
		if (this != &i)
		{
			ut.alocpy(m_description, i.m_description);
			m_flag = i.m_flag;
			m_price = i.m_price;
			m_quantityInHand = i.m_quantityInHand;
			m_quantityReq = i.m_quantityReq;
		}
		return *this;
	}
	Item::~Item()
	{
		delete[] m_description;
	}
	int Item::qtyNeeded() const
	{
		return m_quantityReq;
	}
	int Item::qty() const
	{
		return m_quantityInHand;
	}
	Item::operator double() const
	{
		return m_price;
	}
	Item::operator bool() const
	{
		return state;
	}
	int Item::operator-=(int quantityInHand)
	{
		m_quantityInHand -= quantityInHand;
		return 0;
	}
	int Item::operator+=(int quantityInHand)
	{
		m_quantityInHand += quantityInHand;
		return 0;
	}
	void Item::linear(bool flag)
	{
		m_flag = flag;
	}
	Item& Item::clear()
	{
		state.clear();
		return *this;
	}
	bool Item::operator==(int sku) const
	{
		bool done = false;
		if (sku == SKU)
		{
			done = true;
		}
		return done;
	}
	bool Item::operator==(const char* description) const
	{
		bool done = false;
		if (description != NULL)
		{
			if (strncmp(description, m_description, strlen(description) >= 0))
			{
				done = true;
			}
		}
		return done;
	}
	std::ofstream& Item::save(std::ofstream& ofstr) const
	{
		if (state)
		{
			ofstr << SKU << "\t";
			ofstr << m_description << "\t";
			ofstr << m_quantityInHand << "\t";
			ofstr.setf(ios::fixed);
			ofstr.precision(2);
			ofstr << m_price << "\t";
		}
		return ofstr;
	}
	std::ifstream& Item::load(std::ifstream& ifstr)
	{
		delete[] m_description;
		int tempSKU;
		char tempDescription[100];
		int tempQuantityInHand;
		int tempQuantityReq;
		double tempPrice;
		ifstr >> tempSKU;
		ifstr.ignore();
		ifstr >> tempDescription;
		ifstr.ignore();
		ifstr >> tempQuantityInHand;
		ifstr.ignore();
		ifstr >> tempQuantityReq;
		ifstr.ignore();
		ifstr >> tempPrice;
		ifstr.ignore();
		SKU = tempSKU;
		ut.alocpy(m_description, tempDescription);
		m_quantityInHand = tempQuantityInHand;
		m_quantityReq = tempQuantityReq;
		m_price = tempPrice;
		if (ifstr.bad())
		{
			state = "Input file stream read failed!";
		}
		return ifstr;
	}
	std::ostream& Item::display(std::ostream& ostr) const
	{
		if (!state)
		{
			ostr << state;
		}
		else
		{
			if (linear())
			{
				ostr.setf(ios::fixed);
				ostr.width(4);
				ostr << SKU;
				ostr << " | ";
				ostr.unsetf(ios::fixed);
				bool done = false;
				for (int i = 0; i < 35 && done != true; i++)
				{
					if (m_description[i] != '\0')
					{
						ostr << m_description[i];
					}
					else
					{
						done = true;
					}
				}
				ostr << " | ";
				ostr.setf(ios::fixed);
				ostr.width(4);
				ostr << right << m_quantityInHand;
				ostr << " | ";
				ostr << right << m_quantityReq;
				ostr << " | ";
				ostr.unsetf(ios::fixed);
				ostr.setf(ios::fixed);
				ostr.precision(2);
				ostr << right << m_price;
				ostr.unsetf(ios::fixed);
			}
			else
			{
				int tempQty = m_quantityReq - m_quantityInHand;
				ostr << "AMA Item:" << endl;
				ostr << SKU << ": " << m_description << endl;
				ostr << "Quantity Needed: " << m_quantityReq << endl;
				ostr << "Quantity Available: " << m_quantityInHand << endl;
				ostr.setf(ios::fixed);
				ostr.precision(2);
				ostr << "Unit Price: $" << m_price << endl;
				ostr << "Needed Purchase Fund: $" << (m_price * tempQty) << endl;
				ostr.unsetf(ios::fixed);
			}
		}
		return ostr;
	}
	std::istream& Item::read(std::istream& istr)
	{
		//DEV: TO DO 
		delete[] m_description;
		state.clear();
		char tempDescription[100];
		int tempQuantityReq;
		int tempQuantityInHand;
		double tempPrice;
		cout << "AMA Item:" << endl;
		SKU = ut.getint(40000, 99999, "SKU: ");
		cout << "Description: ";
		istr.ignore(1000, '\n');
		istr.getline(tempDescription,100);
		cout << "Quantity Needed: ";
	}
	int Item::readSku(std::istream& istr)
	{
		SKU = ut.getint(40000, 99999, "SKU: ");
		return 0;
	}
}