/*
Name: Jay Pravinkumar Chaudhari
Student ID: 147268205
E-mail: jpchaudhari@myseneca.ca
Section Code: NAA

Citation and Sources...
Final Project Milestone 2
Module: AidMan
Filename: AidMan.cpp
Version 1.0
Author	Jay Pravinkumar Chaudhari
Revision History
-----------------------------------------------------------
Date      Reason
2022/03/16  completed milestone 2
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include "Utils.h"
#include "AidMan.h"

using namespace std;

namespace sdds
{
	unsigned int AidMan::menu() const
	{
		int year = 0;
		int month = 0;
		int day = 0;
		ut.getSystemDate(&year, &month, &day);
		cout << "Aid Management System Version 0.1" << endl;
		cout << "Date: " << year << "/0" << month << "/" << day << endl;
		cout << "Data file: ";
		if (m_file != nullptr)
		{
			cout << m_file << endl;
		}
		else
		{
			cout << "No file" << endl;
		}
		cout << "---------------------------------" << endl;
		int  num = Menu::run();
		return num;
	}

	AidMan::AidMan(unsigned int num, const char* str) :Menu(num, str)
	{
		m_file = nullptr;
	}

	AidMan::~AidMan()
	{
		delete[] m_file;
	}

	void AidMan::run()
	{
		int num = 0;
		do
		{
			num = menu();
			switch (num)
			{
			case 0:
				cout << "Exiting Program!" << endl;
				break;
			case 1:
				cout << "\n****List Items****\n" << endl;
				break;
			case 2:
				cout << "\n****Add Item****\n" << endl;
				break;
			case 3:
				cout << "\n****Remove Item****\n" << endl;
				break;
			case 4:
				cout << "\n****Update Quantity****\n" << endl;
				break;
			case 5:
				cout << "\n****Sort****\n" << endl;
				break;
			case 6:
				cout << "\n****Ship Items****\n" << endl;
				break;
			case 7:
				cout << "\n****New/Open Aid Database****\n" << endl;
				break;
			default:
				break;
			}
		} while (num != 0);
	}
}