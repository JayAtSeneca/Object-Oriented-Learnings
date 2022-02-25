#include <iostream>
using namespace std;
int main() {
	cout << 'X';
	cout.fill('$');
	cout.width(3);
	cout.setf(ios::fixed);
	cout.setf(ios::left);
	cout.precision(0);
	cout << 1.6 << 'X';
	return 0;
}