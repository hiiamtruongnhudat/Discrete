#include<bits/stdc++.h>
using namespace std;


int n,value;
priority_queue<int,vector<int>, greater<int>> myPriorityQueue;
void __init__()
{
    for ( int i = 0 ; i <  n ; i ++)
    {
        cin >> value;
        myPriorityQueue.push(value);
    }
}

void print()
{   long long sum = 0;
    while (myPriorityQueue.size()>1)
    {   
        int x = myPriorityQueue.top(); myPriorityQueue.pop();
        // cout << "X= "<<  x << endl;
        int y = myPriorityQueue.top(); myPriorityQueue.pop();
        // cout << "Y= "<<  y << endl;
        myPriorityQueue.push(x+y);
        sum+=x+y;
    }
    cout<< sum << endl;
    // cout << myPriorityQueue.empty();
    myPriorityQueue = priority_queue<int,vector<int>, greater<int>>();
}
int main()
{   
    int t; cin >> t;
    while ( t--){
    cin >> n;
    __init__();
    print();
    }
    return 0;

}