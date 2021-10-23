/* Array Implementation of Stack */

#include<iostream>
using namespace std;
#define n 100
class stack {
public:
	int* arr;
	int top;

	stack(){
		arr = new int[n];
		top = -1;
	}

	void push(int val){
		if(top == n-1){
			cout<<"Overflow Stack"<<endl;
			return;
		}
		top++;
		arr[top] = val;
	}

	void pop(){
		if(top == -1){
			cout<<"Underflow Stack"<<endl;
			return;
		}
		top--;
	}

	int Top(){
		if(top == -1){
			cout<<"No element in the Stack"<<endl;
			return -1;
		}
		return arr[top];
	}

	bool empty(){
		return top == -1;
	}

	// void show(){
	// 	for(int i=0;i<arr.size(); i++){
	// 		cout<<arr[i]<<" ";
	// 	}
	// 	cout<<endl;
	// }
};

int main(){
	stack st;
	st.push(1);
	st.push(2);
	st.push(3);
	// cout<<st.show()<<endl;
	cout<<st.Top()<<endl;
	st.pop();
	cout<<st.Top()<<endl;
	st.pop();
	st.pop();
	st.pop();
	cout<<st.Top()<<endl;
	cout<<st.empty()<<endl;
}