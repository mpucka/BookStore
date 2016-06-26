/*
Author: Placido Macosso
Last Date: 2016/02/10

This is the User Interaction class, 
here is where all the output and input will be resented and entered
*/

#ifndef UIMANAGER_H
#define UIMANAGER_H

#include "CourseArray.h"
#include "BookArray.h"

#define TEST_MODE

class UImanager {
  public:
    void mainMenu(int*);
    void getCourseData(Course**);
    void printCourses(CourseArray*);
    void pause();
    void addTextbook(Book**);
    void printCourseBook(Course*);
    void getCourseCode(string&);
  private:
    int getInt();
};

#endif

