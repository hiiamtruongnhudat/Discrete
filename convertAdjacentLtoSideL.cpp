#include<bits/stdc++.h>
using namespace std;




int main()
{
    // int t; cin >> t;
    int t=1;
    while ( t --)
    {
        int n;
        string s;
        cin >> n;
        cin.ignore();
        vector<int> adjacent[1001];
        for ( int i = 1 ; i <= n; ++i)
        {
            getline(cin,s);
            s += " ";
            int num = 0, j = 0;
            while (j < s.size())
            {
                if (s[j] >= '0' && s[j] <= '9')
                    num = 10*num + (int)(s[j]-'0');
                else if (num > 0)
                {
                    adjacent[i].push_back(num);
                    num = 0;
                }
                ++j;
            }
        }
        for ( int i = 1; i <= n; i++)
            sort(adjacent[i].begin(),adjacent[i].end());
        for ( int i = 1; i <= n ; ++i)
        {
            for ( int j = 0 ; j < adjacent[i].size(); j++)
                if ( i < adjacent[i][j])
                    cout  << i << " " << adjacent[i][j] << endl;
            // cout << "\n";
        }
    }
    return 0;
}