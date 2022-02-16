#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
namespace sdds
{
	class Flight
	{
		string m_title;
		double m_fuel;
		int m_passengers;
	public:
		Flight();
		Flight(int passengers, double fuel, std::string title);
		// display function
		ostream& display() const;
		// type conversion operstors
		operator bool()const;
		operator int() const;
		operator double()const;
		operator string()const;
		// unary member operator
		bool operator~()const;
		//Binary member operator
		Flight& operator=(const Flight& value);
		Flight& operator=(int value);
		Flight& operator=(double value);
		Flight& operator+=(double value);
		Flight& operator+=(int value);
		Flight& operator-=(int value);
		Flight& operator-=(double value);
		Flight& operator<<(const Flight& value);
		Flight& operator>>(const Flight& value);
	};
	// binary helper functions
	Flight operator+(const Flight& left, const Flight& right);
	Flight operator+=(int& left, const Flight& right);
}
#endif // !SDDS_FLIGHT_H
