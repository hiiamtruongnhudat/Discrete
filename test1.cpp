#include<bits/stdc++.h>
using namespace std;

int n, x[1005];
void input()
{
    for (int i = 0 ; i < n ;i++)
        cin >> x[i];
}
void output()
{
    for (int i = 0 ; i < n ;i++)
        cout << x[i] << " ";
}
void sapxep()
{
    for (int i = 0; i < n - 1;i++)
        for (int  j = i; j < n; j++)
            if(x[i] < x[j])  
                swap(x[i],x[j]);
    output();
}
int main()
{
    cin >> n;
    input();
    sapxep();
}
