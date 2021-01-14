#include<iostream>
#include<list>
#include"contact.h"
#include"address.h"
   void Address::addContact(std::string name1,std::string name2,std::string prnum,std::string alnum)
   {
       contacts.push_back(contact(name1,name2,prnum,alnum));
   }
   void  Address::displayAll()
   {
       std::list<contact>::iterator iter;
   for(iter=contacts.begin();iter!=contacts.end();++iter)
       iter->display();
   }
   void  Address::removeContactBypnum(std::string pnum) //by id
   {
       std::list<contact>::iterator iter;
       for(iter=contacts.begin();iter!=contacts.end();++iter)
        {
            if(iter->getprimaryno()==pnum)
                break;
        }
      if(iter!=contacts.end())
        contacts.erase(iter);
   }
   contact*  Address::findContactBypnum(std::string pnum)
   {
       std::list<contact>::iterator iter;
  for(iter=contacts.begin();iter!=contacts.end();++iter)
   {
    if(iter->getprimaryno()==pnum)
        return &(*iter);
   }
  return NULL;  //nullptr
   }
   contact*  Address::findContactWithMatchname(std::string name1,std::string name2)//by firstname & lastname
   {

std::list<contact>::iterator iter;
   for(iter=contacts.begin();iter!=contacts.end();++iter)
       {
       if(((iter->getfirstname()).compare(name1)) || ((iter->getlastname()).compare(name2) ) )
         return &(*iter);
       }
return NULL;
   }
   void  Address::updateContactdetails(std::string name1,std::string name2,std::string prno)
   {
       std::list<contact>::iterator iter;
       for(iter=contacts.begin();iter!=contacts.end();++iter)
        {
            if(iter->getprimaryno()==prno)
            {
               iter->setfirstname(name1);
                iter->setlastname(name2) ;
            }
        }
   }
   //int   Address::countAll(){return contacts.size();}
