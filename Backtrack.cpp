#include<bits/stdc++.h>
using namespace std;
int		n=4, X[100], countt=1;
void print(){
	cout << "\n" << countt++ << ": ";
	for(int j=1; j<=n; j++) cout << X[j] << " ";
}
void BackTrack(int i){	//Sinh cau hinh bat dau tu X[i]
	for(int j=0; j<=1; j++){
		X[i]=j;			//chap nhan kha nang j (khong co han che hay rang buoc)
		if(i==n)		//Du 1 cau hinh: in
			print();
		else			//Chua du cau hinh: liet ke cac cau hinh bat dau tu X[i+1]
			BackTrack(i+1);
	}
	return;
}
int main() {
	n=3;
	BackTrack(1);		//Liet ke tat ca cac cau hinh bat dau tu X[1]
}