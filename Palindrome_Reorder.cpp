#include<bits/stdc++.h>
using namespace std ;
#define lln long long int 

lln ar[26]={0};
void solve(){
    string s;
    cin>>s;
    lln n=s.length();
    for(lln i=0;i<s.length();i++){
        ar[s[i]-65]++;
    }
    int count=0;
    for(int i=0;i<26;i++){
        if(ar[i]%2!=0){
            count++;
        }
    }
    
    if(count>1){
        cout<<"NO SOLUTION"<<endl;
        return;
    }
    vector<char>s1,s2;
    for(lln i=0;i<26;i++){
        if(ar[i]%2!=0){
            while(ar[i]--){
                s2.push_back(i+65);
            }
        }
        else if(ar[i]>0 && ar[i]%2==0){
            int x=ar[i]/2;
            while (x--){
                s1.push_back(i+65);
            }
            
        }
    }
     for(lln i=0;i<s1.size();i++){
         cout<<s1[i];
     }
     for(lln i=0;i<s2.size();i++){
         cout<<s2[i];
     }
     for(lln i=s1.size()-1;i>=0;i--){
         cout<<s1[i];
     }
    return;
}
int main() {
    solve();
    return 0;
}
