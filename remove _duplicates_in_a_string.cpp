//Removing duplicates from a string
#include <iostream>
using namespace std;

void removeX(char s[], char x)
{
    if (s[0] == '\0')
    {
        return;
    }
    if (s[0] == x)
    {
        int i = 1;
        for (; s[i] != '\0'; i++)
        {
            s[i - 1] = s[i];
        }
        s[i - 1] = s[i];
        removeX(s, x);
    }
    else
    {
        x = s[0];
        removeX(s + 1, x);
    }
};
int main()
{
    char s[100];
    cin >> s;
    removeX(s, s[0]);
    cout << s << endl;
    return 0;
}