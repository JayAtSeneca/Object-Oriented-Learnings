/*------------------------------------------------------
Workshop 10 part 1
Module: Student
Version 1.0
Author : Fardad Soleimanloo  22/04/01
Revision History
-----------------------------------------------------------
Date: 12/04/2022       Reason: Completed the workshop-10
----------------------------------------------------------- */
#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_
#include "Displayable.h"
namespace sdds{

  class Student :public Displayable{
     int m_stno{};
     char m_name[41]{};
     char m_subject[7]{};
     void set(int stno, const char* name, const char* subject  );
  public:
     Student();
     Student(int stno, const char* name, const char* subject );
     std::ostream& display(std::ostream& os)const;
     bool operator==(const Student& S)const;
  };
}
#endif 