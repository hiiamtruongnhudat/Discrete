#include<bits/stdc++.h>
using namespace std;

int n, arr[10001];
int counter = 0;
void input()
{
    for ( int i = 0 ; i < n; i++)
        cin >> arr[i];
    cout << endl;
    for ( int i = 0 ; i < n; i++)
        cout <<  arr[i] << " ";
    cout << endl;
}
int count(int index)
{   
    int left = 0, right = index;
    cout << "left: " << left << " || " << "right: " << right << endl;
    int mid = (left+right)/2;
    cout << mid <<  ": " << arr[mid] << endl; 
    if (arr[mid]==0)
    if (mid == left)
        return 0;
    else
        return count(mid);
}
int main()
{
    cin >> n;
    input();
    count(n);
    return 0;
}
