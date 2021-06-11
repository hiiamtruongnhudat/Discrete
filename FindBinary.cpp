#include<bits/stdc++.h>
using namespace std;


/* 
2

5 3

1 2 3 4 5 ->3

6 5

0 1 2 3 9 10    -> NO
*/ 
int binarySearch(int arr[], int l, int r, int x) {
  if (r >= l) {
    int mid = l + (r - l) / 2; // Tương đương (l+r)/2 nhưng ưu điểm tránh tràn số khi l,r lớn
 
    // Nếu arr[mid] = x, trả về chỉ số và kết thúc.
    if (arr[mid] == x)
      return mid+1;
 
    // Nếu arr[mid] > x, thực hiện tìm kiếm nửa trái của mảng
    if (arr[mid] > x)
      return binarySearch(arr, l, mid - 1, x);
 
    // Nếu arr[mid] < x, thực hiện tìm kiếm nửa phải của mảng
    return binarySearch(arr, mid + 1, r, x);
  }
 
  // Nếu không tìm thấy
  return -1;
}

int main()
{
    int t; cin >> t;
    while ( t-- )
    {
        int n,x; 
        cin >> n >> x;
        int a[n];
        for (int i = 0 ; i < n; i ++)
            cin >> a[i];
        int res = binarySearch(a,0,n-1,x);
        if( res == -1)
            cout << "NO\n";
        else 
            cout << res << endl;
    }
}

