#include"library.h"
#include"book.h"
#include<iostream>
#include<list>

void Library::addBook(int id, std::string title, std::string author,std::string publisher, double price, int pages) {
    books.push_back(Book(id, title, author, publisher, price, pages));
   
}

void Library::removeBook(int id)
{
std::list<Book>::iterator iter;
  for(iter=books.begin();iter!=books.end();++iter) 
	{
    	if(iter->getId()==id)
        	break;
	}
  if(iter!=books.end())
    books.erase(iter);
}

void Library:: displayAll() {
    std::list<Book>::iterator iter;
   for(iter=books.begin();iter!=books.end();++iter)
       iter->display();
}


Book* Library:: findBookById(int keyId) {

     std::list<Book>::iterator iter;
  for(iter=books.begin();iter!=books.end();++iter) {
    if(iter->getId()==keyId)
        return &(*iter);
	}
  return NULL;
}  
  
int  Library::findAllBooksByAuthor(std::string author, std::list<Book>& results) {
    for (auto iter = books.begin(); iter != books.end(); ++iter)
      if (iter->getAuthor() == author)
        results.push_back(*iter);
    return results.size();
}

double Library:: findAveragePriceOfBook() {
    std::list<Book>::iterator iter;
    double totalPrice = 0;
    for (iter = books.begin(); iter != books.end(); ++iter)
       totalPrice += iter->getPrice();
    return totalPrice / books.size();
}

Book& Library:: findBookWithMaxPages() {
    std::list<Book>::iterator iter;
  iter=books.begin();
  double maxBal = iter->getPages();
  std::list<Book>::iterator maxIter=iter;//accounts.begin();
  std::advance(iter,1);
  for(;iter!=books.end();++iter) {
    if(iter->getPages() >maxBal) {
        maxBal = iter->getPages();
        maxIter = iter;
    }
  }
  return *maxIter;
}
  
Book*  Library::findBookWithMinPriceByPublisher(std::string publisher) {

}

double Library:: findAveragePriceOfBook(std::string publisher) {
    std::list<Book>::iterator iter;
    double totalPrice = 0;
    int c=0;
    for (iter = books.begin(); iter != books.end(); ++iter)
     if(iter->getPublisher()==publisher){
       totalPrice += iter->getPrice();c++;}
    return totalPrice / c;
}

/*int  Library::countBooksByPriceRange(double pmin, double pmax) {
    std::count_if(books.begin(),books.end(), [pmin,pmax](Book& ref) {
        return ref.getPrice() > pmin && ref.getPrice() < pmax;
    });
}
 
int  Library::countBooksWithinPriceLimitByAuthor(double pmax,std::string author ) {
     int count=0;
     std::for_each(books.begin(),books.end(),[pmax,author,&count](const Book& ref) {
        if(ref.getAuthor()==author && ref.getPrice() < pmax) 
            count++;
     });
     return count;
}
 
*/




  
  


  


  







