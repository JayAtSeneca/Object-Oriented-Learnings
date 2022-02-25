#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
const double max_value = 100.0;
class Double {
	// the attribute: 
	double m_value;
public:
	// the one agument constructor: 
	Double(double val = 0)
	{
		if (val > 0 && val < max_value)
		{
			m_value = val;
		}
		else
		{
			m_value = -1;
		}
	}

	// the assignment operator
	Double& operator==(double value)
	{
		if (value > 0 && value < max_value)
		{
			m_value = value;
		}
		else
		{
			m_value = -1;
		}
	}

	// the int cast overload (type converstion overload)
	operator double()const
	{
		return m_value;
	}
	operator int()const
	{
		return m_value;
	}

};
// operator<< overaload (cout << ...)
ostream& operator<<(ostream& ostr, const Double& value)
{
	cout << (double)value;
}

// foolproof operator>> overlaod ( cin >> ...)
istream& operator>>(istream& istr, Double& value)
{
	bool done = true;
	do
	{
		double val = 0;
		cin >> val;
		if (isalpha(val))
		{
			cout << "Bad Double, re-enter: ";
			cin.ignore(1000, '\n');
			done = false;
		}
		else
		{
			if (val > 0 && val < max_value)
			{
				value = val;
				done = true;
			}
			else
			{
				cout << "Invalid Value, re-enter: ";
				done = false;
			}
		}
	} while (done != true);
}

class DoubleArray {
	// the attributes
	Double* arr{};
	int m_size;
public:
	// one argument constructor
	DoubleArray(int size = 1)
	{
		if (size < 1)
		{
			arr = new Double[1];
			m_size = 1;
		}
		else
		{
			arr = new Double[size];
			m_size = size;
		}
	}

	// modifier index operator
	Double& operator[](int& index)
	{
		if (index > m_size)
		{
			Double* temp = new Double[m_size + 1];
			for (int i = 0; i < m_size; i++)
			{
				temp[i] = arr[i];
			}
			delete[] arr;
			m_size++;
			arr = temp;
		}
		return;
	}

	// qurey index operator
	Double& operator[](int index)
	{
		int i = 0;
		bool done = true;
		for (i = 0; i < m_size && done != true; i++)
		{
			if (index == i)
			{
				done = false;
			}
		}
		return arr[i];
	}

	// integer cast overlaod
	operator int()const
	{
		return m_size;
	}

	// memory cleanup
	~DoubleArray()
	{
		delete[] arr;
	}
};
void prnDoubleArray(const DoubleArray& D) {
	int i = 0;
	// looping 3 times (size of D) 
	cout << "D has " << int(D) << " elements: ";
	while (i < D) {  // D will be casted to an integer by compiler
		cout << "D[" << i << "]= " << D[i++] << ", ";
	}
	// goin out of bound but since D is const the operator[] should loop back instead of resizing
	cout << "D[" << i << "]: " << D[i++] << endl;
}
int main() {
	Double A = 300.1, B = 55.2;
	cout << "Invalid A has the value " << A << endl;
	cout << "Valid B has the value " << B << endl;
	DoubleArray D(2);
	prnDoubleArray(D);
	D[0] = 10.0;
	D[1] = 20.0;
	D[2] = 300.0;  // going out of bound to resize and also set to invalid
	prnDoubleArray(D);
	cout << "Enter a Double: ";
	cin >> D[2];
	prnDoubleArray(D);
	return 0;
}

/*
* Execution Sample
*
Invalid A has the value -1
Valid B has the value 55.2
D has 2 elements: D[0]= 0, D[1]= 0, D[2]: 0
D has 3 elements: D[0]= 10, D[1]= 20, D[2]= -1, D[3]: 10
Enter a Double: abc
Bad Double, re-enter: -10.0
Invalid Value, re-enter: 300.1
Invalid Value, re-enter: 12.345
D has 3 elements: D[0]= 10, D[1]= 20, D[2]= 12.345, D[3]: 10

*/