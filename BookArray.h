/*
Author: Placido Macosso
Last Revised Date: 2016/02/10

This is the book array class, 
here is where the taks dealing with the array of books will be implemented
*/

#ifndef BOOK_ARRAY_H
#define BOOK_ARRAY_H

#include "Book.h"

class BookArray
{
  public:
    BookArray();
    void add(Book*);
    Book* getBook(int);
    int  getSize();
    //void CheckCode(Book*);
    ~BookArray();
  private:
    int  size;
    //Book* books;
    Book* books[MAX_BOOKS];
};

#endif
