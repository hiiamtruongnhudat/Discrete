// CPP program to demonstrate working of STL stack
#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
    string s; 
    cin >> s;
    int i = s.size() - 1;
    while ( s[i] == '1' && i >= 0)
        i--;
    if (i<0)
    {
        for (int j = 0 ; j < s.size() ; j++)
            cout << 0;
        cout << endl;
    }
    else
    {
        s[i] = '1';
        for (int k = i + 1; k < s.size(); k++)
            s[k] = '0';
        cout << s << endl;
    }
}
int main()
{
    int t; cin >> t;
    while ( t-- )
        solve();
    return 0;
}