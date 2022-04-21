#define _CRT_SECURE_NO_WARNINGS
//#include <iostream> // err 1
#include<cstring>
using namespace std;
class Emp {
	char* m_name{}; // err 4
public:
	Emp(const char* name) { // err 5
		m_name = new char[strlen(name) + 1]; // err 2
		strcpy(m_name, name);
	}
	~Emp() {
		delete[] m_name; // err 3
	}
};
int main()
{
	return 0;
}
/*
Line Number: 

Type of Error: 

Problem: 

Fix: 
*/