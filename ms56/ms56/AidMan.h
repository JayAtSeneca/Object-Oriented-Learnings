/*
Name: Jay Pravinkumar Chaudhari
Student ID: 147268205
E-mail: jpchaudhari@myseneca.ca
Section Code: NAA

Citation and Sources...
Final Project Milestone 2
Module: AidMan
Filename: AidMan.h
Version 4.0
Author	Jay Pravinkumar Chaudhari
Revision History
-----------------------------------------------------------
Date        Reason
2022/04/06  completed milestone 5(1)
			added save,load,deallocate and list function
			added remove()
			added updateQuantity()
			added sort()
			added shipOrderFile() and removeByIndex()
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
#include "Menu.h"
#include "iProduct.h"
#include "Perishable.h"
namespace sdds
{
	const int sdds_max_num_items = 100;
	class AidMan :public Menu
	{
		char* m_file{};
		iProduct* m_ptr[sdds_max_num_items]{};
		int m_numIProdItems{};
		unsigned int menu()const;

	public:
		AidMan(unsigned int num = 7, const char* str = "1- List Items\n2- Add Item\n3- Remove Item\n4- Update Quantity\n5- Sort\n6- Ship Items\n7- New/Open Aid Database\n---------------------------------\n");
		AidMan(const AidMan& a) = delete;
		AidMan& operator=(const AidMan& a) = delete;
		virtual ~AidMan();
		void run();
		int list(const char* sub_desc = nullptr);
		AidMan& save();
		AidMan& deallocate();
		bool load(const char* tempFileName);
		int search(int sku)const;
		AidMan& addItem();
		AidMan& remove();
		AidMan& updateQuantity();
		AidMan& sort();
		AidMan& shipOrderFile();
		int removeByIndex(int index);
	};
}
#endif // !SDDS_AIDMAN_H
