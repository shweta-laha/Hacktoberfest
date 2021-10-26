/* Reverse a Sentence using Stack */

#include "bits/stdc++.h"

using namespace std;

void reverseSentence(string s){
    stack<string> st;
    for(int i=0; i<s.length(); i++){
        string word = "";
        while(s[i] != ' ' and i<s.length()){
            word += s[i];
            i++;
        }
        st.push(word);
    }
    while(!st.empty()){
        cout<<st.top()<<" "; 
        st.pop();
    }
    cout<<"\n";
}


int32_t main(){
    string s = "Hey, how are you doing!";
    reverseSentence(s);
    return 0;
}