//Name: Jay Pravinkumar Chaudhari
//Student ID: 147268205
//E-mail: jpchaudhari@myseneca.ca
//Section Code: NAA
//Date: Apr 12, 2022
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

#ifndef SDDS_TEMPS_H
#define SDDS_TEMPS_H
#include <iostream>
#include "Collection.h"
namespace sdds
{
	/*
		Required functions for successfully running the template:
		operator== is required
		operator= is required
		operator[] is required
		copy constructor
	*/
	template <class type>
	Collection<type> select(const type arr[], int size, const type& obj)
	{
		int matchFound = 0;
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == obj)
			{
				matchFound++;
			}
		}
		Collection<type> arrRet(matchFound);
		int j = 0;
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == obj)
			{
				arrRet[j] = arr[i];
				j++;
			}
		}
		return arrRet;
	}

	/*
		Required functions for successfully running the template:
		Extraction operator: operator<< is required
	*/
	template <class type>
	void printCollection(const Collection<type>& obj, const char* title)
	{
		std::cout << title << std::endl;
		for (unsigned int i = 0; i < obj.size(); i++)
		{
			std::cout << obj[i] << std::endl;
		}
	}
}
#endif // !SDDS_TEMPS_H
