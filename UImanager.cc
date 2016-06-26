/*
Author: Placido Macosso
Last Date: 2016/02/10

This is the User Interaction class, 
here is where all the output and input will be resented and entered
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cstdlib>
#include "UImanager.h"

using namespace std;

//This will display the main menu as soon as a user enters the system
void UImanager::mainMenu(int* choice)
{
  string str;

  *choice = -1;

  cout << endl << endl << "WELCOME TO THE BOOKSTORE MANAGEMENT SYSTEM" << endl<<endl;
  cout << "  Course Management:" << endl;
  cout << "  ( 1 )  Add course" << endl;
  cout << "  ( 2 )  List all courses" << endl << endl;
  cout << "  Textbook Management:" << endl;
  cout << "  ( 3 )  Add textbook" << endl;
  cout << "  ( 4 )  List course textbooks" << endl << endl;

  cout << "  ( 0 )  Exit" << endl << endl;

while (*choice < 0 || *choice > 4) {
    cout << "Enter your selection from 0 to 4:  ";
    *choice = getInt();
  }

}

//Here the system ask the user to input information about a specific class
void UImanager::getCourseData(Course** course)
{
  string    str = "";
  string    subj, num, name, inst;
  int       enrol;

  cout << endl;

  while (str.length() != 8) {
    cout << "Enter course code (e.g. COMP2404):  ";
    getline(cin, str);
  }
  subj = str.substr(0,4);
  num  = str.substr(4);

  cout << endl << "Enter course name (e.g. Introduction to SE):  ";
  getline(cin, name);

  cout << endl << "Enter instructor name:   ";
  getline(cin, inst);

  cout << endl << "Enter enrolment:   ";
  getline(cin, str);
  stringstream ss(str);
  ss >> enrol;

  *course = new Course (subj, num, name, inst, enrol);

}

//Here the system ask the user to input information about a specific book 
void UImanager::addTextbook(Book** book) 
{

  
  string    str = "";
  string    title, authors, isbn, code;
  int       year, edition;

  cout << endl;

	  cout << endl << "Enter book title (e.g. Introduction to SE):  ";
	  getline(cin, title);

	  cout << endl << "Enter author name (e.g. Mr. TA ):   ";
	  getline(cin, authors);
	   

	  cout<< endl <<"Enter ISBN (e.g. MY-613123567): "; 
	  getline(cin, isbn);

	  cout << endl << "Enter published year (e.g. 1989)";
	  getline(cin, str);
	  stringstream ss(str);
	  ss >> year;

	  cout << endl << "Enter book edition (e.g. 10)";
	  getline(cin, str);
	  stringstream ss2(str);
	  ss2>>edition;

           //Dynamically allocating the book object
	  *book = new Book (title, authors, isbn, edition,  year);          
}

//This subroutine will take a pointer and print all the courses added  
void UImanager::printCourses(CourseArray *arr)
{
  cout << endl << endl << "ALL COURSES:" << endl << endl;

  for (int i=0; i<arr->getSize(); ++i) {
    Course* c = arr->getCourse(i);
    cout << "Course:     " << c->getCode()  << "  " << c->getName() << endl;
    cout << "Instructor: " << c->getInstr()  << endl;
    cout << "Enrolment:  " << c->getEnrol() << endl; 
    cout << "Textbooks:  ";
    if (c->getNumBooks() == 0) {
      cout << "None" << endl;
    }
    else {

      for (int j =0; j < c->getNumBooks();j++){
      cout <<c->getBook(j)->getTitle()<<endl;
      }
    }
    cout << endl;
  }
}


//This subroutine will take a pointer and print all the books added  
void UImanager::printCourseBook(Course *course)
{
  cout << endl << endl <<"ALL BOOKS: " << endl <<endl;
 
  for (int i = 0; i<course->getNumBooks();i++)
  {
    Book* b = course->getBook(i);
   
    //ask user to enter book info
    cout << "Title:   " << b->getTitle()   << endl;
    cout << "Authors: " << b->getAuthors() << endl;
    cout << "ISBN:    " << b->getISBN()    << endl;
    cout << "Edtion:  " << b->getEdition() << endl;
    cout << "Year :   " << b->getYear()    << endl; 
  }  

}

//This functions makes the system take a pause, untill user is ready to continue
void UImanager::pause()
{
  string str;

  cout << endl << "\nPress enter to continue...";
  getline(cin, str);
}

//This function will get the users string input then allow the user to enter an intenger
int UImanager::getInt()//not a getter
{
  string str;
  int    num;

  getline(cin, str);
  stringstream ss(str);
  ss >> num;

  return num;
}

//Helper Function to get the course code from the user
void UImanager::getCourseCode(string& str)
{

  while(str.length() !=8)
  {
	  cout <<"Please enter the course Code (e.g. COMP2404): ";
	  getline(cin,str);

  }
}
