// using FRIEND FUNCTION three classes
#include<iostream>
using namespace std; 
class B; 
class C;
class A 
{
	 private :
	  int a;
	 public : 
	 friend void sum(A,B,C); 
	
};
class B 
{
	 private :
	  int b;
	  
	  public : 
	  friend void sum(A,B,C);              //establishing friendship
};
class C 
{
	private :
		 int c; 
	public : 
	 friend void sum(A,B,C);       //establishing friendship
};

void sum(A aobj3,B bobj4,C cobj6 )           //accessing private member of all the three class A,B,C
{
	cout<<" Enter the value of a :"<<endl;
	cin>>aobj3.a; 
	cout<<" Enter the value of b :"<<endl;
	cin>>bobj4.b;
	cout<<" Enter the value of c :- "<<endl;
	cin>>cobj6.c; 
	
	cout<<" Sum : "<<(aobj3.a + bobj4.b); 
	cout<<endl;
	cout<<" Difference of b and c "<<endl;
	cout<<(cobj6.c - bobj4.b);
	
}
int main()
{
	 A aobj1;
	 B bobj2; 
	 C cobj5;
	 sum(aobj1,bobj2,cobj5);
}
