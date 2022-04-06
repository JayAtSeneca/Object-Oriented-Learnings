/*
Name: Jay Pravinkumar Chaudhari
Student ID: 147268205
E-mail: jpchaudhari@myseneca.ca
Section Code: NAA

Citation and Sources...
Final Project Milestone 2
Module: AidMan
Filename: AidMan.cpp
Version 2.0
Author	Jay Pravinkumar Chaudhari
Revision History
-----------------------------------------------------------
Date      Reason
2022/04/06  completed milestone 5(1)
			added save,load,deallocate and list function
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include <fstream>
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
		cout << "Aid Management System" << endl;
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
		deallocate();
		/*delete[] m_file;*/
	}

	void AidMan::run()
	{
		int num = 0;
		char tempName[30] = { "\0" };
		do
		{
			num = menu();
			if (m_file == nullptr && num != 0)
			{
				switch (num)
				{
				default:
					cout << "\n****New/Open Aid Database****" << endl;
					cout << "Enter file name: ";
					char tempName[30] = { "\0" };
					cin >> tempName;
					if (load(tempName))
					{
						cout << m_numIProdItems << " records loaded!" << endl << endl;
					}
					break;
				}
			}
			else
			{
				switch (num)
				{
				case 0:
					cout << "Exiting Program!" << endl;
					save();
					break;
				case 1:
					cout << "\n****List Items****" << endl;
					list();
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
					cout << "Enter file name: ";
					
					cin >> tempName;
					if (load(tempName))
					{
						cout << m_numIProdItems + 1 << " records loaded!" << endl;
					}
					break;
				default:
					break;
				}
			}
		} while (num != 0);
	}
	int AidMan::list(const char* sub_desc)
	{
		int rowCounter = 0;
		if (m_numIProdItems > 0) {
			cout << " ROW |  SKU  | Description                         | Have | Need |  Price  | Expiry" << endl;
			cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
			if (sub_desc == nullptr)
			{

				for (int i = 0; i < m_numIProdItems; i++)
				{
					cout << " ";
					cout.setf(ios::right);
					cout.width(3);
					cout.fill(' ');
					cout << i + 1;
					cout.unsetf(ios::right);
					cout << " | ";
					m_ptr[i]->linear(true);
					m_ptr[i]->display(cout);
					cout << endl;
					rowCounter++;
				}
			}
			else
			{
				for (int i = 0; i < m_numIProdItems; i++)
				{
					if (m_ptr[i]->operator==(sub_desc))
					{
						cout << " ";
						cout.setf(ios::right);
						cout.width(3);
						cout.fill(' ');
						cout << i + 1;
						cout.unsetf(ios::right);
						cout << " | ";
						m_ptr[i]->linear(true);
						m_ptr[i]->display(cout);
						cout << endl;
						rowCounter++;
					}
				}
			}
			cout << "-----+-------+-------------------------------------+------+------+---------+-----------" << endl;
			cin.ignore();
			cout << "Enter row number to display details or <ENTER> to continue:\n> ";
						
			if (cin.peek() != '\n') {
				char temp[4] = "";
				cin >> temp;
				int tempNum = atoi(temp);
				m_ptr[tempNum - 1]->linear(false);
				m_ptr[tempNum - 1]->display(cout);
			}
			cout << endl;
		}
		else
		{
			cout << "The list is emtpy!" << endl;
		}
		return rowCounter;
	}
	AidMan& AidMan::save()
	{
		if (m_file)
		{
			ofstream file;
			file.open(m_file);
			for (int i = 0; i < m_numIProdItems; i++)
			{
				m_ptr[i]->save(file)<<endl;
			}
		}
		return *this;
	}
	AidMan& AidMan::deallocate()
	{
		for (int i = 0; i < m_numIProdItems; i++)
		{
			delete m_ptr[i];
		}
		delete[] m_file;
		m_file = nullptr;
		m_numIProdItems = 0;
		return *this;
	}
	bool AidMan::load(const char* tempFileName)
	{
		bool isLoaded = false;
		bool done = false;
		int loadCounter = 0;
		save();
		deallocate();
		ut.alocpy(m_file, tempFileName);
		ofstream newFile;
		ifstream file;
		file.open(m_file);
		if (!file.is_open())
		{
			cout << "Failed to open " << m_file << " for reading!";
			cout << "Would you like to create a new data file?";
			cout << "1- Yes!\n0- Exit\n>";
			int tempNum = ut.getint();
			switch (tempNum)
			{
			case 1:
				newFile.open(m_file);
				done = true;
				break;
			case 0:
				break;
			default:
				break;
			}
		}
		if (file.is_open() && done != true)
		{
			while (file)
			{
				char peek = file.peek();
				if (peek == '1' || peek == '2' || peek == '3')
				{
					m_ptr[m_numIProdItems] = new Perishable;
					
					m_ptr[m_numIProdItems]->load(file);
					if (m_ptr[m_numIProdItems]->operator bool())
					{
						m_numIProdItems++;
						loadCounter++;
					}
					else
					{
						delete m_ptr[m_numIProdItems];
					}
				}
				else if (peek == '4' || peek == '5' || peek == '6' || peek == '7' || peek == '8' || peek == '9')
				{
					m_ptr[m_numIProdItems] = new Item;
					m_ptr[m_numIProdItems]->load(file);
					if (m_ptr[m_numIProdItems]->operator bool())
					{
						m_numIProdItems++;
						loadCounter++;
					}
					else
					{
						delete m_ptr[m_numIProdItems];
					}
				}
				else if (!isdigit(file.peek()))
				{
					file.setstate(ios::failbit);
				}
			}
		}
		if (m_numIProdItems > 0)
		{
			isLoaded = true;
		}
		return isLoaded;
	}
	int AidMan::search(int sku) const
	{
		int retIndex = -1;
		bool done = false;
		for (int i = 0; i < m_numIProdItems && done!= true; i++)
		{
			if (m_ptr[i]->operator==(sku))
			{
				retIndex = i;
				done = true;
			}
		}
		return retIndex;
	}
	AidMan& AidMan::addItem()
	{
		if (m_numIProdItems > sdds_max_num_items)
		{
			cout << "Database full!" << endl;
		}
		else
		{
			cout << "1- Perishable\n2 - Non - Perishable\n---------------- -\n0 - Exit\n> ";
			int num = 0;
			cin >> num;
			switch (num)
			{
			case 1:
				iProduct* tempIProduct;
				tempIProduct = new Perishable;
				int tempSku = 0;
				cout << "SKU: ";
				cin >> tempSku;
				if (tempIProduct->operator==(tempSku))
				{
					cout << "Sku: " << tempSku << " is already in the system, try updating quantity instead.\n";
					delete tempIProduct;
				}
				else
				{
					tempIProduct->read(cin);
					if (tempIProduct->operator bool())
					{
						m_ptr[m_numIProdItems] = tempIProduct;
						m_numIProdItems++;
					}
					else
					{
						tempIProduct->display(cout);
						delete tempIProduct;
					}
				}
				break;
			case 2:
				iProduct* tempIProduct;
				tempIProduct = new Item;
				int tempSku = 0;
				cout << "SKU: ";
				cin >> tempSku;
				if (tempIProduct->operator==(tempSku))
				{
					cout << "Sku: " << tempSku << " is already in the system, try updating quantity instead.\n";
					delete tempIProduct;
				}
				else
				{
					tempIProduct->read(cin);
					if (tempIProduct->operator bool())
					{
						m_ptr[m_numIProdItems] = tempIProduct;
						m_numIProdItems++;
					}
					else
					{
						tempIProduct->display(cout);
						delete tempIProduct;
					}
				}
				break;
			case 0:
				cout << "Aborted\n";
				break;
			default:
				break;
			}
		}
	}
}