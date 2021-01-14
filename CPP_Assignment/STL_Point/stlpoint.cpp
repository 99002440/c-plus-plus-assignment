#include"stlpoint.h"
#include"point.h"
#include<list>
#include<iostream>   

void STLPoint:: addPoint(int x,int y){
points.push_back(Point(x,y));
}


void STLPoint::displayAll(){
	std::list<Point>::iterator iter;
   	for(iter=points.begin();iter!=points.end();++iter)
       		iter->display();
}
   

int STLPoint::countAll(Quadrant e1){
	int c=0,x,y;
	std::list<Point>::iterator iter;
   	for(iter=points.begin();iter!=points.end();++iter)
	{
	if(iter->quadrant()==e1)
		c++;
	}
	return c;		
}
   
int  STLPoint::displayPointOnCircle(int r){
	int c=0,x,y;
	std::list<Point>::iterator iter;
   	for(iter=points.begin();iter!=points.end();++iter)
	{
	x=iter->getx();
	y=iter->gety();
	if(((x*x)+(y*y))==(r*r))
		c++;
	}
	return c;	
}
   

int  STLPoint::displayPointinCircle(int r){
	int c=0,x,y;
	std::list<Point>::iterator iter;
   	for(iter=points.begin();iter!=points.end();++iter)
	{
	x=iter->getx();
	y=iter->gety();
	if(((x*x)+(y*y))<(r*r))
		c++;
	}
	return c;
}
