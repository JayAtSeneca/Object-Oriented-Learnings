/*
Name: Jay Pravinkumar Chaudhari
Student ID: 147268205
E-mail: jpchaudhari@myseneca.ca
Section Code: NAA

Citation and Sources...
Final Project Milestone 2
Module: Item
Filename: Item.h
Version 1.0
Author	Jay Pravinkumar Chaudhari
Revision History
-----------------------------------------------------------
Date      Reason
2022/03/30  completed milestone 3
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H
#include <iostream>
#include <fstream>
#include "iProduct.h"
#include "Status.h"
namespace sdds
{
	class Item :public iProduct
	{
		double m_price;
		int m_quantityInHand;
		int m_quantityReq;
		char* m_description;
		bool m_flag;
	protected:
		Status m_state;
		int m_sku;
		bool linear()const;
	public:
		Item();
		Item(const Item& i);
		Item& operator=(const Item& i);
		~Item();
		// public queries
		virtual int qtyNeeded()const;
		virtual int qty()const;
		virtual operator double()const;
		virtual operator bool()const;
		//modifiers
		virtual int operator-=(int quantityInHand);
		virtual int operator+=(int quantityInHand);
		virtual void linear(bool flag);
		Item& clear();
		virtual bool operator==(int sku)const;
		virtual bool operator==(const char* description)const;
		virtual std::ofstream& save(std::ofstream& ofstr)const;
		virtual std::ifstream& load(std::ifstream& ifstr);
		virtual std::ostream& display(std::ostream& ostr)const;
		virtual std::istream& read(std::istream& istr);
		virtual int readSku(std::istream& istr);
	};
}
#endif // !SDDS_ITEM_H
