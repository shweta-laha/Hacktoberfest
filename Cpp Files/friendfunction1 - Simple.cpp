// using FRIEND FUNCTION simply 
#include<iostream>
using namespace std; 

class A 
{
	 private : 
	  int  x , y ;
	 
	 public : 
	  
	  void setdata(int a,int b)
	  {
	  	 x = a ; 
	  	 y = b ; 
	  }
	  friend void show(A); 
};
    void show(A aobj1)
	 {
         cout<<" x : "<<aobj1.x<<" Y: "<<aobj1.y; 

	 } 

int main()
{
	A aobj;
	aobj.setdata(4,6);
	show(aobj); 
 	
}
