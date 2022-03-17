/*
Name: Jay Pravinkumar Chaudhari
Student ID: 147268205
E-mail: jpchaudhari@myseneca.ca
Section Code: NAA

Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.h
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
#ifndef SDDS_MENU_H
#define SDDS_MENU_H
namespace sdds
{
	class Menu
	{
		char* m_content{};
		unsigned int m_options = 0u;
	public:
		Menu(unsigned int num = 16, const char* str = nullptr);
		Menu(const Menu& m) = delete;
		Menu& operator=(const Menu& m) = delete;
		virtual ~Menu();
		unsigned int run()const;
	};
}
#endif // !SDDS_MENU_H
