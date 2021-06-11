#include<bits/stdc++.h>
using namespace std;

int n, X[101];
bool cauhinhcuoi = false;
void sinh()
{
    int i = n;
    while ( i > 0 && X[i] == 1)
        i--;
    if ( i == 0 )
    {
        cauhinhcuoi = true;
        return;
    }
    else
    {
        X[i] = 1;
        for (int j = i+1; j<=n;j++)
            X[j] = 0;
    }
    return;
}
void printt()
{   
    int dem = 0;
    // for (int i = 0; i<n;i++)
    // {
    //     if (X[i]!=X[n-i-1])
    //         dem++;
    // }
    int k = 0;
    while (k < n/2)
        if (X[k] != X[n-k-1])
            dem++;
    if ( dem == 0)
        {
            for (int i = 0; i <n; i++)
                cout << X[i] << " ";
            cout << endl;
        }
}
int main()
{
    n = 4;
    // cin >> n;
    for (int i = 0; i<n;i++)
        X[i] = 0;
    while(!cauhinhcuoi)
    {
        printt();
        sinh();
        cauhinhcuoi = false;
    }
    return 0;
}