#include <iostream>
using namespace std;
class Out {
public:
	virtual int get() const = 0;
	virtual char ch() const = 0;
};
ostream& operator<<(ostream& os, const Out& out) {
	return os << ">"
		<< out.get() << out.ch() << "<";
}
	// Turns the messages inside the classes on and off
	bool prn_on = true;

	class Base : public Out {
		int m_val;
	public:
		virtual char ch() const {
			return 'F';
		}
		int get() const {
			return m_val;
		}
		void id() {
			if (prn_on) cout << ch() << get() << "+";
		}
		Base(const int a[], int size) :m_val{ 1 } {
			for (int i = 0; i < size; m_val += a[i++]);
		}
		Base(int val = 0) :m_val(val) {
			if (prn_on) cout << "c"; id(); //lowercas
		}
		Base(const Base& B) :m_val(B.m_val + 2) {
			if (prn_on) cout << "d"; id(); // lowerca
		}
		Base& operator=(const Base& B) {
			m_val = B.m_val + 1;
			if (prn_on) cout << "5"; id(); // lowercase s
			return *this;
		}
		operator int() const {
			return get();
		}
		operator char() const {
			return 'F';
		}
		virtual ~Base() {
			if (prn_on) id(); cout << "x";
		}
		friend Base operator+(const Base& left, const Base& right);
	};

	class Derived : public Base {
	public:
		char ch() const {
			return 'C';
		}
		Derived(const int a[], int size)
		{
			int sum = 0;
			for (int i = 0; i < size; sum += a[i++]);
			*this = Derived(sum);
		}
		Derived(int val = 1) :Base(val + 10) {
			id();
		}
		Derived(const Derived& D) :Base(D) {
		}
		Derived& operator=(const Derived& D) {
			Base::operator=(D);
		}
		operator char()const {
			return 'C';
		}
	};

	Base operator+(const Base& left, const Base& right)
	{
		Base sum(left.m_val + right.m_val);
		return sum;
	}

	int main() {
		prn_on = true;
		Base A(3), B;
		return 0;
	}