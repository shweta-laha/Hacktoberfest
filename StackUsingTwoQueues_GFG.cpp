//Stack using two queues 
//GFG ACCEPTED
//Stack And Queue


#include<bits/stdc++.h>
using namespace std;

class QueueStack{
private:
    queue<int> q1;
    queue<int> q2;
public:
    void push(int);
    int pop();
};


int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        QueueStack *qs = new QueueStack();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            qs->push(a);
        }else if(QueryType==2){
            cout<<qs->pop()<<" ";

        }
        }
        cout<<endl;
    }
}


//Function to push an element into stack using two queues.

//this element denotes in which queue we'll be inserting element
//after every pop() operation the curr flips
int curr = 1;

void QueueStack :: push(int x)
{
    if(curr == 1)
        q1.push(x);
    else
        q2.push(x);
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
    int x = -1;
    if(curr == 1)
    {
        while(!q1.empty() && q1.size() > 1)
        {
            int val = q1.front();
            q1.pop();
            q2.push(val);
        }
        curr = 2;
        if(!q1.empty())
        {
            x = q1.front();
            q1.pop();
        }
    }
    else
    {
        while(!q2.empty() && q2.size() > 1)
        {
            int val = q2.front();
            q2.pop();
            q1.push(val);
        }
        curr = 1;
        if(!q2.empty())
        {
            x = q2.front();
            q2.pop();
        }
    }
    return x;
}


/*

this can be done like this too without using the curr variable
we keep q1 as the main queue and after pop() swap q1 and q2

void QueueStack :: push(int x)
{
    q1.push(x);
}

//Function to pop an element from stack using two queues. 
int QueueStack :: pop()
{
    int x = -1;
    while(!q1.empty() && q1.size() > 1)
    {
        q2.push(q1.front());
        q1.pop();
    }
    if(!q1.empty())
    {
        x = q1.front();
        q1.pop();
    }
    swap(q1, q2);
    return x;
}
*/