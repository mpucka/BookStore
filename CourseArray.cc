/*
Author: Placido Macosso
Last Revised Date: 2016/02/10

This is the course array class, 
here is where the taks dealing with the array of courses will be implemented
*/
#include <iostream>
#include <string>
using namespace std;

#include "CourseArray.h"

//CourseArray constructor initializing the size data member
CourseArray::CourseArray() 
{ 
  size = 0;
}

//CourseArray destructor
CourseArray::~CourseArray() 
{ 
  for (int i = 0; i <size; i++)
   {
    if (courses !=NULL)
	{
     delete courses[i];
     courses[i]=0;
	}
   }
}

int    CourseArray::getSize()           { return size; }
Course* CourseArray::getCourse(int i)   { return courses[i]; }

//This functions goes trough the book array to find if the given code matches
Course* CourseArray::getCourseID(string code)
{ 
  for (int i = 0; i < size;i++){
    if (courses[i]->getCode()==code)
      return courses[i]; 
 }
return 0;
}


void CourseArray::add(Course* course)
{
  if (size == MAX_COURSES)
    return;
  courses[size] = course;
  cout << "Added course: " << courses[size]->getCode() << endl;
  size++;
}

//Function to verify the given code exists
bool CourseArray::codeExist(string courseCode)
{ 
  //Going trough the courses in the courses list
  for (int i = 0; i<size;i++)
   {
	  //Veryfying if the given code exists in the courses list
	  if (courses[i]->getCode()==courseCode){
	      cout<<"Yea the course Exists:" << courses[i]->getCode()<< endl;
              return true;
		}
	}
   return false;
}
