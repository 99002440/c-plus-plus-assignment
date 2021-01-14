#include "account.h"
#include "banking.h"
#include<list>
#include<iostream>
//using namespace std;
void Banking::addAccount(std::string id,std::string name,double bal) {
   //Account temp(id,name,bal);
   //accounts.push_back(temp);     //Method-1
   accounts.push_back(Account(id,name,bal));  //Method-2
   //accounts.emplace_back(id,name,bal);  //Method-3,C++11
}
void Banking::displayAll() {
   std::list<Account>::iterator iter;
   for(iter=accounts.begin();iter!=accounts.end();++iter)
       iter->display();
   /* for(Account& ref:accounts)    //C++11
        ref.display();  
   */
   /* for(auto& ref:accounts) 
        ref.display();
   */   
}
double Banking::findAverageBalance()
{
//std::vector<double> vbal;
   std::list<Account>::iterator iter;
   double sum=0;
   int count=0;
   double avg=0;
   for(iter=accounts.begin();iter!=accounts.end();++iter)
	{
      		sum+=iter->getBalance();
		count++;
	}
   avg=(sum/count);
   return avg;
}
int Banking::countAccountsByBalanceRange(double min,double max) 
{  
int count=0;
std::list<Account>::iterator iter;
   for(iter=accounts.begin();iter!=accounts.end();++iter)
       if((iter->getBalance()>=min) && (iter->getBalance()<=max))
		count+=1;
return count;
}
Account* Banking::findAccountById(std::string keyId) 
{
  std::list<Account>::iterator iter;
  for(iter=accounts.begin();iter!=accounts.end();++iter) 
   {
    if(iter->getId()==keyId)
        return &(*iter);
   }
  return NULL;  //nullptr
}
void Banking::removeAccountById(std::string keyId) 
{
  std::list<Account>::iterator iter;
  for(iter=accounts.begin();iter!=accounts.end();++iter)
  {
    if(iter->getId()==keyId)
        break;
  }
  if(iter!=accounts.end())
    accounts.erase(iter); 
}
Account& Banking::findAccountWithMinBalance() {
  std::list<Account>::iterator iter;
  iter=accounts.begin();
  double minBal = iter->getBalance();
  std::list<Account>::iterator minIter=iter; //accounts.begin();
  ++iter;  //std::advance(iter,1)
  for(;iter!=accounts.end();iter++) 
  {
    if(iter->getBalance() < minBal) 
     {
        minBal = iter->getBalance();
        minIter = iter;
     }
  }
  return *minIter;
}
        

