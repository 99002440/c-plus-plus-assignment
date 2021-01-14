#include "book.h"
#include <list>
#include <algorithm>

/*bool compareAuthor(const Book& r1, const Book& r2) {
  return r1.getAuthor() < r2.getAuthor();
}
bool comparePages(const Book& r1, const Book& r2) {
  return r1.getPages() < r2.getPages();
}*/
class Library {
  std::list<Book> books;

public:
void addBook(int id, std::string title, std::string author,std::string publisher, double price, int pages);
void displayAll() ;
Book* findBookById(int keyId);
void removeBook(int id);
int findAllBooksByAuthor(std::string author, std::list<Book>& results);
double findAveragePriceOfBook() ;
Book& findBookWithMaxPages() ;
Book* findBookWithMinPriceByPublisher(std::string publisher) ;
double findAveragePriceOfBook(std::string publisher);
//int countBooksByPriceRange(double pmin, double pmax);
//int countBooksWithinPriceLimitByAuthor(double pmax,std::string author ) ;
int countAll(){return books.size();}
};
  

