/* ------------------------------------------------------
Workshop 5 part 2
Module: Portfolio
Filename: Portfolio.h
Version 1.0
Date: 24/11/2021
Author: Asam Gulaid
Revised by: Fardad Soleimanloo
Revision History
-----------------------------------------------------------
Initials    Date           Reason
F.S.        07/02/2022     Peer Review
-----------------------------------------------------------*/
#ifndef SDDS_Portfolio_H_
#define SDDS_Portfolio_H_
#include <iostream>
#include <string>

namespace sdds {

    class Portfolio {
        double m_value = 0;
        char m_stock[16];
        char m_type;
        
    public:
        Portfolio();
        Portfolio(double value, const char* stock, char type);
        void dispPortfolio() const;
        void emptyPortfolio();
        std::ostream& display() const;
        operator double()const;
        operator const char* ()const;
        operator char()const;
        operator bool()const;
        bool operator~()const;
        bool operator!=(const Portfolio& rightOperand);
        Portfolio& operator+=(double value);
        Portfolio& operator-=(double value);
        Portfolio& operator<<(Portfolio& rightOperand);
        Portfolio& operator>>(Portfolio& rightOperand);
    };
    double operator+(const Portfolio& left, const Portfolio& right);
    double operator+=(double& value, const Portfolio& right);
}
#endif // SDDS_Portfolio_H_