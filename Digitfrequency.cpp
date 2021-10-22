#include <iostream>
using namespace std;
int main()
{
    int n, i, j, ctr, r;
    cout << "\n\n Find frequency of each digit in a given integer:\n";
    cout << "-----------------------------------------------------\n";
    cout << " Input any number: ";
    cin >> n;
    for (i = 0; i < 10; i++) 
    {
        cout << "The frequency of " << i << " = ";
        ctr = 0;
        for (j = n; j > 0; j = j / 10) 
        {
            r = j % 10;
            if (r == i) 
            {
                ctr++;
            }
        }
        cout << ctr << endl;
    }
}
