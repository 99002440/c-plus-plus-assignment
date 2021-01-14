
#include"banking.h"
#include"account.h"
#include"SavingsAccount.h"
#include"CreditAccount.h"
#include<list>
#include<iostream>

void Banking::addAccount(std::string id,std::string name,double bal) {
   accounts.push_back(SavingsAccount(id,name,bal));
}

void Banking::displayAll() {
   std::list<SavingsAccount>::iterator iter;
   for(iter=accounts.begin();iter!=accounts.end();++iter)
       iter->display();
}

double Banking:: findAverageBalance(){
	std::list<SavingsAccount>::iterator it;
	double sum=0;
	int c=0;
	for(it=accounts.begin();it!=accounts.end();++it){
       		sum+=it->getBalance();
		c++;
	}
	return (double)sum/c;
}

int Banking::countAccountsByBalanceRange(double min,double max){
	std::list<SavingsAccount>::iterator it;
	int c=0;
	for(it=accounts.begin();it!=accounts.end();++it){
		if(it->getBalance() > min && it->getBalance() < max)
         		c++;
	}
	return c;
}


SavingsAccount* Banking::findAccountById(std::string keyId) {
  std::list<SavingsAccount>::iterator iter;
  for(iter=accounts.begin();iter!=accounts.end();++iter) {
    if(iter->getNumber()==keyId)
        return &(*iter);
	}
  return NULL;  //nullptr
}

SavingsAccount* Banking::findAccountByName(std::string name) {
  std::list<SavingsAccount>::iterator iter;
  for(iter=accounts.begin();iter!=accounts.end();++iter) {
    if(iter->getName()==name)
        return &(*iter);
	}
  return NULL;  //nullptr
}

void Banking::removeAccountById(std::string keyId) {
  std::list<SavingsAccount>::iterator iter;
  for(iter=accounts.begin();iter!=accounts.end();++iter)
	{
    	if(iter->getNumber()==keyId)
        	break;
	}
  if(iter!=accounts.end())
    accounts.erase(iter);
}
 SavingsAccount& Banking::findAccountWithMaxBalance() {
  std::list<SavingsAccount>::iterator iter;
  iter=accounts.begin();
  double maxBal = iter->getBalance();
  std::list<SavingsAccount>::iterator maxIter=iter;
  std::advance(iter,1);
  for(;iter!=accounts.end();++iter) {
    if(iter->getBalance() > maxBal) {
        maxBal = iter->getBalance();
        maxIter = iter;
    }
  }
  return *maxIter;
}
int Banking::countAccountsByBalanceLess(double bal){
    int c=0;
  std::list<SavingsAccount>::iterator iter;
  for(iter=accounts.begin();iter!=accounts.end();++iter) {
    if(iter->getBalance() < bal) {
        c++;

    }
  }
  return c;

}



