#ifndef __BOOK_H
#define __BOOK_H

#include <string>
#include <iostream>

class Book {
  int m_id;
  std::string m_title;
  std::string m_author;
  std::string m_publisher;
  double m_price;
  int m_pages;

public:
Book(int id, std::string title, std::string author, std::string publisher, double price, int pages);
void display() const;
int getId() const;
std::string getTitle() const;
std::string getAuthor() const;
std::string getPublisher() const;
double getPrice() const ;
int getPages() const ;
bool operator==(const Book& ref);
friend std::ostream& operator<< (std::ostream& rout, const Book& rb);
};


#endif
