#include <iostream>
#include <string>
#include "Utils.h"
#include "Date.h"

using namespace std;

namespace sdds
{
	bool Date::validate()
	{
		bool done = true;
		int num = 0;
		if (m_year < CURR_YEAR || m_year > MAX_YEAR)
		{
			m_state = "Invalid year in date";
			m_state = 1;
			done = false;
		}
		if (done == true)
		{
			if (m_month < 1 || m_month > 12)
			{
				m_state = "Invalid month in date";
				m_state = 2;
				done = false;
			}
		}

		if (done == true)
		{
			num = ut.daysOfMon(m_month, m_year);
			if (m_day < 1 || m_day > num)
			{
				m_state = "Invalid day in date";
				m_state = 3;
				done = false;
			}
		}

		if (done == true)
		{
			m_state.clear();
		}
		return done;
	}
	int Date::uniqDateVal(int year, int month, int day)
	{
		int num = (year * 372) + (month * 31) + day;
		return num;
	}
	Date::Date(int year, int month, int day)
	{
		if (year != 0 && month != 0 && day != 0)
		{
			m_year = year;
			m_month = month;
			m_day = day;
			validate();
		}
		else if (year == 0 && month == 0 && day == 0)
		{
			ut.getSystemDate(&m_year,&m_month,&m_day);
		}
	}
	bool Date::operator==(const Date& d)
	{
		bool done = false;
		int m_num = uniqDateVal(m_year, m_month, m_day);
		int num = uniqDateVal(d.m_year, d.m_month, d.m_day);
		if (m_num == num)
		{
			done = true;
		}
		return done;
	}
	bool Date::operator!=(const Date& d)
	{
		bool done = false;
		int m_num = uniqDateVal(m_year, m_month, m_day);
		int num = uniqDateVal(d.m_year, d.m_month, d.m_day);
		if (m_num != num)
		{
			done = true;
		}
		return done;
	}
	bool Date::operator<(const Date& d)
	{
		bool done = false;
		int m_num = uniqDateVal(m_year, m_month, m_day);
		int num = uniqDateVal(d.m_year, d.m_month, d.m_day);
		if (m_num < num)
		{
			done = true;
		}
		return done;
	}
	bool Date::operator>(const Date& d)
	{
		bool done = false;
		int m_num = uniqDateVal(m_year, m_month, m_day);
		int num = uniqDateVal(d.m_year, d.m_month, d.m_day);
		if (m_num > num)
		{
			done = true;
		}
		return done;
	}
	bool Date::operator<=(const Date& d)
	{
		bool done = false;
		int m_num = uniqDateVal(m_year, m_month, m_day);
		int num = uniqDateVal(d.m_year, d.m_month, d.m_day);
		if (m_num <= num)
		{
			done = true;
		}
		return done;
	}
	bool Date::operator>=(const Date& d)
	{
		bool done = false;
		int m_num = uniqDateVal(m_year, m_month, m_day);
		int num = uniqDateVal(d.m_year, d.m_month, d.m_day);
		if (m_num >= num)
		{
			done = true;
		}
		return done;
	}
	const Status& Date::state()
	{
		return m_state;
	}
	Date& Date::formatted(bool val)
	{
		if (val == true || val == false)
		{
			m_formatted = val;
		}
		return *this;
	}
	Date::operator bool() const
	{
		return m_state;
	}
	ostream& Date::write(ostream& ostr) const
	{
		if (m_formatted == true)
		{
			ostr << m_year;
			ostr.setf(ios::fixed);
			ostr << "/";
			ostr.width(2);
			ostr.fill('0');
			ostr << right << m_month;
			ostr << "/";
			ostr.width(2);
			ostr.fill('0');
			ostr << right << m_day;
			ostr.unsetf(ios::fixed);
		}
		else
		{
			string year = to_string(m_year);
			year = year.substr(2, 4);
			ostr << year;
			ostr.setf(ios::fixed);
			ostr.width(2);
			ostr.fill('0');
			ostr << right << m_month;
			ostr.width(2);
			ostr.fill('0');
			ostr << right << m_day;
			ostr.unsetf(ios::fixed);
		}
		return ostr;
	}
	istream& Date::read(istream& istr)
	{
		int num;
		bool done = false;
		istr >> num;
		if (!istr.fail())
		{
			if (num > 999 && num < 10000)
			{
				int validateYear = CURR_YEAR;
				int validateMonth = int(num / 100);
				int validateDay = num - (validateMonth * 100);
				set(validateYear, validateMonth, validateDay);
				done = true;
			}
			else if (num > 99999 && num < 1000000)
			{
				int validateYear = num / 10000;
				int validateMonth = (num - (validateYear * 10000)) / 100;
				int validateDay = num - ((validateYear * 10000) + (validateMonth * 100));
				set(validateYear, validateMonth, validateDay);
				done = true;
			}
			else
			{
				set(CURR_YEAR, 0, 0);
				done = true;
			}
		}
		else
		{
			cout<< "Invalid date value";
		}

		if (done == true)
		{
			if (validate() == false)
			{
				istr.setstate(ios::badbit);
			}
		}
		
		return istr;
	}
	Date& Date::set(int year, int month, int day)
	{
		string tempYear = to_string(year);
		if (tempYear.length() < 4)
		{
			string y1 = "20";
			tempYear = y1 + tempYear;
		}
		m_year = stoi(tempYear);
		m_month = month;
		m_day = day;
		return *this;
	}
	ostream& operator<<(ostream& ostr, const Date& d)
	{
		return d.write(ostr);
	}
	istream& operator>>(istream& istr, Date& d)
	{
		return d.read(istr);
	}
}