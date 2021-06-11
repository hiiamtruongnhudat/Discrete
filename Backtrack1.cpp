//Quay lui - BackTrack co dieu kien liet ke cac hoan vi cua 1..n
#include <iostream>
using namespace std;
int	n, X[100], count=1, unused[100];
void print(){
	cout << "\n" << count++ << ": ";
	for(int j=1; j<=n; j++) cout << X[j] << " ";
}
void BackTrack(int i){	//Sinh cau hinh bat dau tu X[i]
	for(int j=1; j<=n; j++){
		if(unused[j]==1){	//j chua duoc su dung
			X[i]=j;			//chap nhan kha nang j
			unused[j]=0;	//danh dau da dung
			if(i==n)		//Du 1 cau hinh: in
				print();
			else			//Chua du cau hinh: liet ke cac cau hinh bat dau tu X[i+1]
				BackTrack(i+1);
			unused[j]=1;
		}
	}
	return;
}
int main() {
    int t; cin >> t;
    while ( t--)
    {
        cin >> n;
        for(int j=1; j<=n; j++)	unused[j]=1;	//Khoi tao cac kha nang deu chua su dung
	    BackTrack(1);	
    }
	return 0;
	//Liet ke tat ca cac cau hinh bat dau tu X[1]
}