#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll len=s.length(),flag=0;
        stack<char>stk;
        for(ll i=0;i<len;i++){
            if(s[i]=='{'||s[i]=='('||s[i]=='['){
                stk.push(s[i]);
            }else{
                if(stk.empty()){
                    flag=1;
                }else{
                    if(s[i]=='}' && stk.top()=='{'){
                        stk.pop();
                
                    }else if(s[i]==']' && stk.top()=='['){
                        stk.pop();
                    }else if(s[i]==')' && stk.top()=='('){
                        stk.pop();
                    }else{
                        flag=1;
                    }
                }
            }
            if(flag==1){
                break;
            }
            
        }
        if(stk.empty()&&flag==0){
            cout<<"balanced"<<"\n";
        }else{
            cout<<"not balanced"<<"\n";
        }
        
    }
    return 0;
}
	

