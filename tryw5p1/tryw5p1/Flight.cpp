/* ------------------------------------------------------
Workshop 5 part 1
Module: Flight
Filename: Flight.cpp
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials    Date           Reason
F.S.        07/02/2022     Peer Review
-----------------------------------------------------------*/
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "Flight.h"

using namespace std;
namespace sdds {

    void Flight::emptyPlane() {
        m_passengers = 0;
        m_fuel = 0;
        strcpy(m_title, "EmptyPlane");
    }

    bool Flight::isIdentical(const Flight& operand)
    {
        bool done = false;
        if (m_fuel == operand.m_fuel && m_passengers == operand.m_passengers && m_title == operand.m_title)
        {
            done = true;
        }
        return done;
    }

    // New Flight
    Flight::Flight() {
        emptyPlane();
    }
    Flight::Flight(int passengers, double fuel, const char* title) {
        emptyPlane();
        if (passengers > 0 && passengers <= Boen747Capacity && fuel >= 0 &&
            fuel <= FuelTankCapacity) {
            m_passengers = passengers;
            m_fuel = fuel;
            strcpy(m_title, title);
        }
    }
    std::ostream& Flight::display() const {

        if (*this) {
            cout << " Flight  |  Ready to Depart";
            cout << " ";
            cout.width(10);
            cout << std::string(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        else if (~*this) {
            cout << " Flight  |  Empty Plane    ";
        }
        else {
            cout << " Flight  |  Low Fuel       ";
            cout << " ";
            cout.width(10);
            cout << (const char*)(*this);
            cout << " | ";
            cout << "Pass: ";
            cout.width(10);
            cout << int(*this);
            cout << " | ";
            cout.width(12);
            cout.precision(2);
            cout.setf(ios::right);
            cout.setf(ios::fixed);
            cout << double(*this);
            cout.unsetf(ios::right);
            cout << " Liters";
        }
        return cout;
    }

    int Flight::getPassengers()
    {
        return m_passengers;
    }

    Flight::operator bool() const
    {
        bool done = false;
        if ((m_passengers > 0) && (m_fuel >= m_passengers * fuelPerPerson ))
        {
            done = true;
        }
        return done;
    }

    Flight::operator int() const
    {
        return m_passengers;
    }

    Flight::operator double() const
    {
        return m_fuel;
    }

    Flight::operator const char* () const
    {
        return m_title;
    }

    bool Flight::operator~() const
    {
        bool done = false;
        if (m_passengers == 0)
        {
            done = true;
        }
        return done;
    }

    Flight& Flight::operator=(Flight& rO)
    {
        m_passengers = rO.m_passengers;
        m_fuel = rO.m_fuel;
        strcpy(m_title, rO.m_title);
        rO.m_fuel = 0;
        rO.m_passengers = 0;
        strcpy(rO.m_title, "EmptyPlane");
        return *this;
    }

    Flight& Flight::operator=(int value)
    {
        if (value <= Boen747Capacity && value > 0)
        {
            m_passengers = value;
        }
        return *this;
    }

    Flight& Flight::operator=(double value)
    {
        if (value > 0 && value <= FuelTankCapacity)
        {
            m_fuel = value;
        }
        return *this;
    }

    Flight& Flight::operator+=(double value)
    {
        double m_val = m_fuel;
        m_val += value;
        if (value > 0 && m_fuel != FuelTankCapacity)
        {
            if (m_val >= FuelTankCapacity)
            {
                m_fuel = FuelTankCapacity;
            }
            else
            {
                m_fuel = m_val;
            }
        }
        
        return *this;
    }

    Flight& Flight::operator+=(int value)
    {
        int m_val = m_passengers;
        m_val += value;
        if (value > 0 && m_passengers != Boen747Capacity)
        {
            if (m_val >= Boen747Capacity)
            {
                m_passengers = Boen747Capacity;
            }
            else
            {
                m_passengers = m_val;
            }
        }
        
        return *this;
    }

    Flight& Flight::operator-=(int value)
    {
        int m_val = m_passengers;
        m_val -= value;
        if (value > 0 && value <= m_passengers)
        {
            if (m_val > 0)
            {
                m_passengers = m_val;
            }
        }
        return *this;
    }

    Flight& Flight::operator-=(double value)
    {
        double m_val = m_fuel;
        m_val -= value;
        if (value > 0)
        {
            if (m_val < 0)
            {
                m_fuel = 0;
            }
            else
            {
                m_fuel = m_val;
            }
        }
        return *this;
    }

    Flight& Flight::operator<<(Flight& rO)
    {
        int tempPassengers = m_passengers + rO.m_passengers;
        if (!isIdentical(rO))
        {
            if (tempPassengers >= Boen747Capacity)
            {
                m_passengers = Boen747Capacity;
                rO.m_passengers = rO.m_passengers - Boen747Capacity;
            }
            else
            {
                m_passengers = tempPassengers;
                rO.m_passengers = rO.m_passengers - tempPassengers;
            }
        }
        
        return *this;
    }

    Flight& Flight::operator>>(Flight& rO)
    {
        int tempPassengers = m_passengers + rO.m_passengers;
        if (!isIdentical(rO))
        {
            if (tempPassengers >= Boen747Capacity)
            {
                rO.m_passengers = Boen747Capacity;
                m_passengers = tempPassengers - Boen747Capacity;
            }
            else
            {
                rO.m_passengers = tempPassengers;
                m_passengers = m_passengers - tempPassengers;
            }
        }
        return *this;
    }

    int operator+(const Flight& left, const Flight& right)
    {
        int leftValue = (int)left;
        int rightValue = (int)right;
        int value = leftValue + rightValue;
        return value;
    }

    int operator+=(int& left, const Flight& right)
    {
        left = left + (int)right;
        return left;
    }

}