/*
Author: Placido Macosso
Last Revised Date: 2016/02/10

This file contains the class definitions for the control class 
this is the class  where all the operations will be made

*/

#ifndef BMS_CONTROL_H
#define BMS_CONTROL_H

#include "defs.h"
#include "UImanager.h"
#include "CourseArray.h"

class BMScontrol {
  public:
    BMScontrol();
    void launch();
    ~BMScontrol();
  private:
    UImanager*   view; 
    CourseArray* courses; 
    BookArray* books;
};

#endif



