#include<bits/stdc++.h>
using namespace std;
int n,x[11];
bool cauhinhcuoi = false;

void reset()
{
    for (int i = 1 ; i <= n; i ++)
        x[i] = n-i+1;
    cauhinhcuoi = false;
}
void sinh()
{
    int i = n - 1;
    while ( i > 0 && x[i] < x[i+1])
        i--;
    if ( i > 0 )
    {
        int k = n;
        while(x[i] < x[k]) k--;
        swap(x[i],x[k]);
        int a = i + 1, b = n;
        while ( a <= b )
        {
            swap(x[a],x[b]);
            a++;
            b--;
        }
    }
    else
    {
        cauhinhcuoi = true;
        return;
    }
    return;
}
void print()
{
    for (int i = 1; i <= n; i++)
        cout << x[i];
    cout << " ";
}
int main()
{
	int t; cin >> t;
    while ( t-- )
    {   
        cin >> n;
        reset();
        while (!cauhinhcuoi)
        {
            print();
            sinh();
        }
        cout << "\n";
    }
    return 0;
}