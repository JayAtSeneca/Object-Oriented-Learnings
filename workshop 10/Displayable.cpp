/*------------------------------------------------------
Workshop 10 part 1
Module: Displayable
Version 1.0
Author : Fardad Soleimanloo  22/04/01
Revision History
-----------------------------------------------------------
Date: 12/04/2022       Reason: Completed the workshop-10
----------------------------------------------------------- */
#include "Displayable.h"
namespace sdds{
  std::ostream& operator<<(std::ostream& os, const Displayable& D){
    return D.display(os);
  }
}