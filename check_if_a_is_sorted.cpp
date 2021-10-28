// Check if Array is sortedd
// 1 2 4 5 6 8 9 10

//0 for not sorted
// 1 for sorted

#include<iostream>
using namespace std;

int sorted(int A[], int size){
    if(size <= 1){
        return 1;
    }
    int smallValue = sorted(A+1, size - 1);
    if(smallValue == 1){
        if(A[0]<=A[1]){
            return 1;
        }
        else{
            return 0;
        }
    }else{
        return 0;
    }
};


int main(){
    int n;
    cin >> n ;
    int *P = new int[n];
    for(int i=0; i<n; i++){
        cin>> P[i];
    }

    int s = sorted(P, n);
    cout<< s << endl;
    return 0;
}