/*
Author: Placido Macosso
Last Date: 2016/02/10

This is the control class, here is where all the operations will be made

*/

#include <iostream>
#include "BMScontrol.h"

using namespace std;

//In this constructor the view, books and course will be dynamically allocated 
BMScontrol::BMScontrol()
{
	view =    new UImanager();
	courses = new CourseArray();
        books =   new  BookArray();

   cout<<" BMS Constructor being called\n";
}

//In this destructor the view, books and course will be deallocated 
BMScontrol::~BMScontrol()
{

  delete view;
  delete courses;
  delete books;
}

void BMScontrol::launch()
{
  int    choice;

  string code;

  while (1) {
    choice = -1;
    view->mainMenu(&choice);
    if (choice == 0) {
      break;
    }
    else if (choice == 1) {
      
     // initializing the course object 
      Course* newCourse = 0;

      view->getCourseData(&newCourse);
      courses->add(newCourse);

    }
    else if (choice == 2) {
      view->printCourses(courses); //remove the & operator because is already a pointer
    }
    else if (choice == 3) {
    
    //inittializing the book object
    Book* newBook= 0; 
    string n;

    view->getCourseCode(code);
    
    if (courses->codeExist(code)){
        view->addTextbook(&newBook);
        Course* c = courses->getCourseID(code);
        c->addBook(newBook);
    }
    else 
       cout<<"Course not found\n";

    }
    else if (choice == 4) {
    string n;

    view->getCourseCode(code);
    
    if (courses->codeExist(code)){
        Course* c = courses->getCourseID(code);
        view->printCourseBook(c);
    }
    else 
       cout<<"Course not found\n";
    }   

    view->pause();
  }
}
