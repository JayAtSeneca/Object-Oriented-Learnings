
#ifndef SDDS_FLIGHT_H
#define SDDS_FLIGHT_H
#include <iostream>

namespace sdds {

    const int Boen747Capacity = 388;
    const int FuelTankCapacity = 238840;

    class Flight {

        int m_passengers = 0;
        double m_fuel = 0;
        char m_title[16];
        void emptyPlane();

    public:
        Flight();
        Flight(int passengers, double fuel, const char* title);
        std::ostream& display()const;
         //type conversion operators
		operator bool()const;
		operator int() const;
		operator double()const;
		operator const char*()const;
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
	// binary helper operaters
	Flight operator+(const Flight& left, const Flight& right);
	Flight operator+=(int& left, const Flight& right);
}
#endif // SDDS_FLIGHT_H



//#ifndef SDDS_FLIGHT_H
//#define SDDS_FLIGHT_H
//namespace sdds
//{
//	class Flight
//	{
//		std::string m_title;
//		double m_fuel;
//		int m_passengers;
//	public:
//		Flight();
//		Flight(int passengers, double fuel, std::string title);
//		// display function
//		ostream& display() const;
//		// type conversion operstors
//		operator bool()const;
//		operator int() const;
//		operator double()const;
//		operator const char*()const;
//		// unary member operator
//		bool operator~()const;
//		//Binary member operator
//		Flight& operator=(const Flight& value);
//		Flight& operator=(int value);
//		Flight& operator=(double value);
//		Flight& operator+=(double value);
//		Flight& operator+=(int value);
//		Flight& operator-=(int value);
//		Flight& operator-=(double value);
//		Flight& operator<<(const Flight& value);
//		Flight& operator>>(const Flight& value);
//	};
//	// binary helper functions
//	Flight operator+(const Flight& left, const Flight& right);
//	Flight operator+=(int& left, const Flight& right);
//}
//#endif // !SDDS_FLIGHT_H
