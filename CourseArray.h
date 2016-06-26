/*
Author: Placido Macosso
Last Revised Date: 2016/02/10

This is the course array class, 
here is where the taks dealing with the array of courses will be implemented
*/

#ifndef COURSE_ARRAY_H
#define COURSE_ARRAY_H

#include "Course.h"

class CourseArray
{
  public:
    CourseArray();
    void   add(Course*);
    Course* getCourse(int);
    Course* getCourseID(string); 
    int    getSize();
    bool codeExist(string);
    ~CourseArray();

  private:
    int size;
    Course* courses[MAX_COURSES];

};

#endif


