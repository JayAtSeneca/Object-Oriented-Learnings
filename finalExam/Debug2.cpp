#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
class Label {
public:
    Label() :m_title(nullptr) {
    };
    Label(const char* value) :m_title(nullptr) {
        allocateAndCopy(value);
    }
    Label(Label& N) {
        *this = N;
    }
    Label operator=(const Label& N) {
        allocateAndCopy(N.m_title);
        // return this;
        // it should be *this
        return *this;
    }
    ~Label() {
        delete[] m_title;
    }
    // return should be ostream reference
   //  void write(ostream& os)const {
   //     os << m_title;
   //  }
    std::ostream& write(ostream& os)const {
        os << m_title;
        //return statement missing
        return os;
    }
    // return should be istream reference
    std::istream& scan(istream& is) {
        // char str[1000];
        //it should be string str;
        string str;
        getline(is, str);
        allocateAndCopy(str.c_str());
        //return missing
        return is;
    }
private:
    //  const char* m_title;
     // it should be char* m_value
    char* m_title;
    void allocateAndCopy(const char* value) {
        delete[] m_title;
        m_title = new char[strlen(value) + 1];
        strcpy(m_title, value);
    }
};
// Sign is wrong below, it should be >> not <<
// istream& operator<<(istream& is, Label& N) {
//    return N.scan(is);
// }

istream& operator>>(istream& is, Label& N) {
    return N.scan(is);
}

// The Label argument should be const
// ostream& operator<<(ostream& os, Label& N) {
//    N.write(os);
//    return os;
// }
ostream& operator<<(ostream& os, const Label& N) {
    N.write(os);
    return os;
}


/*
Line Number: 

Type of Error: 

Problem: 

Fix: 
*/
