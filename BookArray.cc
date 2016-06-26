#include <iostream>
#include <string>
using namespace std;

#include "BookArray.h"

BookArray::BookArray() 
{ 
  size = 0;
  //books = new Book[MAX_BOOKS];
  cout<<" BookArray Constructor being called\n";
}

BookArray::~BookArray()
{

   for (int i = 0; i<size; i++ ){
     if (books !=NULL){
       delete books[i];
       books[i]=0;
   }
     cout<<"BookArray Destructor being called\n";
 }
}

int   BookArray::getSize()         { return size; }
Book*  BookArray::getBook(int i)   { return books[i]; }

void BookArray::add(Book* book)
{
  if (size == MAX_BOOKS)
    return;

  books[size] = book; //book
  size++;
}


