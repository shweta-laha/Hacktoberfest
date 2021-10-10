// using FRIEND FUNCTION with two classes
#include<iostream>
using namespace std; 
class B; 
class A 
{
	 private :
	  int a;
	 public : 
	 friend void sum(A,B);  // establishing frienship between class A and function sum
	
};
class B 
{
	 private :
	  int b;
	  
	  public : 
	  friend void sum(A,B);  // establishing frienship between class B and function sum
};

void sum(A aobj3,B bobj4)   //function Sum is friend of both the class A and B so it can access their private member
{
	cout<<" Enter the value of a :"<<endl;
	cin>>aobj3.a; 
	cout<<" Enter the value of b :"<<endl;
	cin>>bobj4.b;
	
	cout<<" Sum : "<<(aobj3.a + bobj4.b); 
	
}
int main()
{
	 A aobj1;
	 B bobj2; 
	 
	 sum(aobj1,bobj2);
}
