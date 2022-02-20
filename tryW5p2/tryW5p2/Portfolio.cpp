/* ------------------------------------------------------
Workshop 5 part 2
Module: Portfolio
Filename: Portfolio.cpp
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

#include "Portfolio.h"

using namespace std;
namespace sdds {


    Portfolio::Portfolio() {
        emptyPortfolio();
    }

    void Portfolio::emptyPortfolio()
    {
        m_value = 0;
        m_stock[0] = 0;
        m_type = 'E';
    }
    Portfolio::Portfolio(double value, const char* stock, char type) {
        emptyPortfolio();
        if (value >= 0 && (type == 'V' || type == 'G' || type == 'I')) {
            m_value = value;
            m_type = type;
            strcpy(m_stock, stock);
        }
    }

    void Portfolio::dispPortfolio() const {
        cout << " ";
        cout.width(10);
        cout << (const char*)(*this);
        cout << " | ";
        cout << "Value: ";
        cout.width(10);
        cout << double(*this);
        cout << " | ";
        cout << " Type: ";
        cout << char(*this);
    }
    std::ostream& Portfolio::display() const {

        if (~*this) {
            cout << " Portfolio  |  Bad-NG |";
            dispPortfolio();
        }
        else if (*this) {
            cout << " Portfolio  |  Active |";
            dispPortfolio();

        }
        else {
            cout << " Portfolio  |  EMPTY  |";
            dispPortfolio();
        }
        return cout;
    }

    Portfolio::operator double() const
    {
        return m_value;
    }

    Portfolio::operator const char* () const
    {
        return m_stock;
    }

    Portfolio::operator char() const
    {
        return m_type;
    }

    Portfolio::operator bool() const
    {
        bool done = false;
        if (m_type == 'G' || m_type == 'V' || m_type == 'I')
        {
            done = true;
        }
        return done;
    }

    Portfolio& Portfolio::operator+=(double value)
    {
        if (value >= 0 && this->m_value != 0)
        {
            m_value += value;
        }
        return *this;
    }
    bool Portfolio::operator!=(const Portfolio& rightOperand)
    {
        bool done = false;
        if ((m_value != rightOperand.m_value) && (m_stock != rightOperand.m_stock))
        {
            done = true;
        }
        return done;
    }
    Portfolio& Portfolio::operator-=(double value)
    {
        if (value >= 0 && this->m_value != 0)
        {
            m_value -= value;
        }
        return *this;
    }

    Portfolio& Portfolio::operator<<(Portfolio& rightOperand)
    {
        
        if (*this != rightOperand)
        {
            m_value += rightOperand.m_value;
            rightOperand.emptyPortfolio();
        }
        return *this;
    }
    Portfolio& Portfolio::operator>>(Portfolio& rightOperand)
    {
        if (*this != rightOperand)
        {
            rightOperand.m_value += m_value;
            emptyPortfolio();
        }
        return *this;
    }

    bool Portfolio::operator~() const
    {
        return m_value < 0 ? true : false;
    }




    double operator+(const Portfolio& left, const Portfolio& right)
    {
        double value = 0;
        value = (double)left + (double)right;
        return value;
    }

    double operator+=(double& value, const Portfolio& right)
    {
        value += (double)right;
        return value;
    }

}