#include "book.cpp"
#include"library.cpp"
#include <gtest/gtest.h>
namespace {
int m_id;
  std::string m_title;
  std::string m_author;
  std::string m_publisher;
  double m_price;
  int m_pages;
class LibraryTest : public ::testing::Test {

  protected:
    void SetUp() { //override {
        libr.addBook( 1001,"c++","John","mc hill",500,200 );
        libr.addBook( 1002,"c","Nick","mc hill",600,300 );
        libr.addBook( 1003,"Java","John","sunstar",500,220);
    }
    void TearDown() {
    }
    Library libr;
};
TEST_F(LibraryTest,CountAccounts) {
  EXPECT_EQ(3,libr.countAll());
}
/*TEST_F(LibraryTest,CountBooksByPriceRange) {
  EXPECT_EQ(3,libr.countBooksByPriceRange(400,600));
}*/
/*TEST_F(LibraryTest,FindAllBooksByAuthor) {
  EXPECT_EQ(2, libr.findAllBooksByAuthor("John",std::list<Book>& results));
}*/
TEST_F(LibraryTest,AddBook) {
  libr.addBook( 1004,"Linux","Pooja","k",600,350 );
  EXPECT_EQ(4,libr.countAll());
  Book *ptr=libr.findBookById( 1004 );
  EXPECT_NE(nullptr, ptr);
  EXPECT_EQ(1004, ptr->getId());
  EXPECT_EQ(600, ptr->getPrice());
}
TEST_F(LibraryTest,RemoveBook) {
  libr.removeBook( 1002 );
  EXPECT_EQ(2,libr.countAll());
  Book *ptr=libr.findBookById( 1002);
  EXPECT_EQ(nullptr, ptr);
}
}


