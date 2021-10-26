#include<bits/stdc++.h>
using namespace std;

pair<int, int> findMinMax(vector<int> &v)   //This function will return minimum and maximum of a vector
{                                           //In the form of a pair {minimum, maximum}
    int mn, mx;
    mn=mx=v[0];
    for (int i = 1; i < v.size(); i++)
    {
        mn=min(mn, v[i]);
        mx=max(mx, v[i]);
    }
    return {mn, mx};
}

int main()
{
    vector<int> v={1, 2, 3, 4, 5};
    pair<int, int> minMax=findMinMax(v);
    cout<<"Minimum element of vector v is: "<<minMax.first<<endl;
    cout<<"Maximum element of vector v is: "<<minMax.second<<endl;
    return 0;
}
