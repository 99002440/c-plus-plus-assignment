#include "book.h"

Book::Book(int id, std::string title, std::string author, std::string publisher,
       double price, int pages)
      : m_id(id), m_title(title), m_author(author), m_publisher(publisher),
        m_price(price), m_pages(pages) {}

void Book::display() const {
      std::cout<<m_id<<","<<m_title<<","<<m_author<<","<<m_publisher<<","<<m_price<<","<<m_pages<<"\n";
  }

int Book::getId() const { return m_id; }
  
std::string Book::getTitle() const { return m_title; }
  
std::string Book::getAuthor() const { return m_author; }
  
std::string Book::getPublisher() const { return m_publisher; }
  
double Book::getPrice() const { return m_price; }
  
int Book::getPages() const { return m_pages; }
  
bool Book::operator==(const Book& ref) {
    return m_id == ref.m_id; } 

std::ostream& operator<< (std::ostream& rout, const Book& rb) {
  rout<<rb.m_id<<","<<rb.m_title<<","<<rb.m_author<<","<<rb.m_publisher<<","<<rb.m_price<<","<<rb.m_pages<<"\n";
  return rout;
}

