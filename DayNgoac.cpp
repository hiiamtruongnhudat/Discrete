#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while ( t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        int res = 0;
        stack<int> st;
        st.push(-1);
        /*
3

((()
i = 0; -> s[0] = (;
st = {-1,0};
i = 1; -> s[1] = (;
st = {-1,0,1}
i = 2; -> s[2] = (;
st = {-1,0,1,2}
i = 3; -> s[3] = );
st = {0,1,2}.
res = max(0,3-0) = 3
)()())

()(()))))
*/
        for (int i = 0 ; i < n; i++)
        {   
            // cout << i << " ";
            if (s[i] == '(')
                {
                    st.push(i);
                }
            else
            {      
                cout << st.top() << "\n";
                st.pop();
                cout << st.top();
                if (st.size() > 0 ) 
                    {   
                        res = max(res,i-st.top());
                    }
                if (st.size() == 0 )
                    st.push(i);
            }
        }
        // cout << res << "\n";
    }
    return 0;
}